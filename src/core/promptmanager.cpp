#include "promptmanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QRegularExpression>
#include <QDebug>

namespace ClipAI {
namespace Core {

PromptManager::PromptManager(QObject* parent)
    : QObject(parent)
{
}

PromptManager::~PromptManager() = default;

bool PromptManager::loadPrompts()
{
    QString customPath = getCustomPromptsFilePath();

    if (QFile::exists(customPath)) {
        return loadPromptsFromFile(customPath);
    }

    // Try to load from default location
    QString defaultPath = getPromptsFilePath();
    if (QFile::exists(defaultPath)) {
        return loadPromptsFromFile(defaultPath);
    }

    // No prompts file found, create default
    qDebug() << "No prompts file found, creating default prompts";
    m_prompts = getDefaultPrompts();
    savePromptsToFile(customPath);
    emit promptsLoaded();
    return true;
}

bool PromptManager::loadPromptsFromFile(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open prompts file:" << filePath;
        emit promptsLoadFailed(tr("Failed to open prompts file"));
        return false;
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse prompts file:" << error.errorString();
        emit promptsLoadFailed(tr("Failed to parse prompts file"));
        return false;
    }

    return loadPromptsFromJson(doc.object());
}

bool PromptManager::loadPromptsFromJson(const QJsonObject& json)
{
    QString version = json.value(QStringLiteral("version")).toString();

    QJsonArray promptsArray = json.value(QStringLiteral("prompts")).toArray();
    m_prompts.clear();

    for (const QJsonValue& value : promptsArray) {
        if (value.isObject()) {
            Models::Prompt prompt(value.toObject());
            if (prompt.isValid()) {
                m_prompts.append(prompt);
            }
        }
    }

    qDebug() << "Loaded" << m_prompts.size() << "prompts";
    emit promptsLoaded();
    return true;
}

bool PromptManager::savePrompts()
{
    return savePromptsToFile(getCustomPromptsFilePath());
}

bool PromptManager::savePromptsToFile(const QString& filePath)
{
    QJsonObject root;
    root[QStringLiteral("version")] = QStringLiteral("1.0");

    QJsonArray promptsArray;
    for (const auto& prompt : m_prompts) {
        promptsArray.append(prompt.toJson());
    }
    root[QStringLiteral("prompts")] = promptsArray;

    QJsonDocument doc(root);

    // Ensure directory exists
    QFileInfo fileInfo(filePath);
    QDir dir = fileInfo.dir();
    if (!dir.exists()) {
        dir.mkpath(QStringLiteral("."));
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open prompts file for writing:" << filePath;
        return false;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    return true;
}

bool PromptManager::addPrompt(const Models::Prompt& prompt)
{
    if (!prompt.isValid()) {
        return false;
    }

    // Check for duplicate ID
    for (const auto& p : m_prompts) {
        if (p.id() == prompt.id()) {
            return false;
        }
    }

    m_prompts.append(prompt);
    emit promptAdded(prompt.id());
    return true;
}

bool PromptManager::updatePrompt(const QString& id, const Models::Prompt& prompt)
{
    for (int i = 0; i < m_prompts.size(); ++i) {
        if (m_prompts[i].id() == id) {
            m_prompts[i] = prompt;
            emit promptUpdated(id);
            return true;
        }
    }
    return false;
}

bool PromptManager::removePrompt(const QString& id)
{
    for (int i = 0; i < m_prompts.size(); ++i) {
        if (m_prompts[i].id() == id) {
            m_prompts.removeAt(i);
            emit promptRemoved(id);
            return true;
        }
    }
    return false;
}

std::optional<Models::Prompt> PromptManager::getPrompt(const QString& id) const
{
    for (const auto& prompt : m_prompts) {
        if (prompt.id() == id) {
            return prompt;
        }
    }
    return std::nullopt;
}

QVector<Models::Prompt> PromptManager::getAllPrompts() const
{
    return m_prompts;
}

QVector<Models::Prompt> PromptManager::getEnabledPrompts() const
{
    QVector<Models::Prompt> result;
    for (const auto& prompt : m_prompts) {
        if (prompt.enabled()) {
            result.append(prompt);
        }
    }
    return result;
}

QVector<Models::Prompt> PromptManager::getPromptsByContentType(Models::ContentType type) const
{
    QVector<Models::Prompt> result;
    for (const auto& prompt : m_prompts) {
        if (prompt.contentType() == type || prompt.contentType() == Models::ContentType::Any) {
            result.append(prompt);
        }
    }
    return result;
}

QVector<Models::Prompt> PromptManager::searchPrompts(const QString& query) const
{
    QVector<Models::Prompt> result;
    QString queryLower = query.toLower();

    for (const auto& prompt : m_prompts) {
        if (prompt.name().toLower().contains(queryLower) ||
            prompt.description().toLower().contains(queryLower) ||
            prompt.id().toLower().contains(queryLower)) {
            result.append(prompt);
        }
    }

    return result;
}

QString PromptManager::formatPrompt(const QString& promptId, const QString& clipboardContent) const
{
    auto prompt = getPrompt(promptId);
    if (!prompt) {
        return clipboardContent;
    }

    return prompt->formatUserPrompt(clipboardContent);
}

bool PromptManager::validatePrompt(const Models::Prompt& prompt) const
{
    return getValidationErrors(prompt).isEmpty();
}

QStringList PromptManager::getValidationErrors(const Models::Prompt& prompt) const
{
    QStringList errors;

    if (prompt.id().isEmpty()) {
        errors.append(tr("ID is required"));
    }

    if (prompt.name().isEmpty()) {
        errors.append(tr("Name is required"));
    }

    // Check for valid placeholder syntax
    QString templateStr = prompt.userPromptTemplate();
    QRegularExpression placeholderRe(QStringLiteral(R"(\{(?:clipboard|clipboard:\d+)\})"));
    QRegularExpressionMatchIterator i = placeholderRe.globalMatch(templateStr);

    // All placeholders should be valid
    QRegularExpression allBracesRe(QStringLiteral(R"(\{[^}]+\})"));
    QRegularExpressionMatchIterator allIt = allBracesRe.globalMatch(templateStr);
    while (allIt.hasNext()) {
        QRegularExpressionMatch match = allIt.next();
        QString captured = match.captured(0);
        if (!placeholderRe.match(captured).hasMatch()) {
            errors.append(tr("Invalid placeholder: %1").arg(captured));
        }
    }

    return errors;
}

QString PromptManager::getPromptsFilePath() const
{
    // Return path to default prompts file (in resources)
    return QStringLiteral(":/config/prompts-default.json");
}

QString PromptManager::getCustomPromptsFilePath() const
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    return configPath + QStringLiteral("/prompts.json");
}

bool PromptManager::ensurePromptsFileExists()
{
    QString customPath = getCustomPromptsFilePath();
    if (QFile::exists(customPath)) {
        return true;
    }

    // Create default prompts file
    return savePromptsToFile(customPath);
}

QVector<Models::Prompt> PromptManager::getDefaultPrompts()
{
    QVector<Models::Prompt> prompts;

    // Summary prompt
    {
        Models::Prompt p;
        p.setId(QStringLiteral("summary"));
        p.setName(tr("Summary"));
        p.setDescription(tr("Generate a structured summary of the text"));
        p.setIcon(Models::PromptIcon::TextSummary);
        p.setSystemPrompt(tr("You are a professional analyst. Create a clear, structured summary."));
        p.setUserPromptTemplate(tr("Please provide a comprehensive summary of the following text:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Translate to Russian
    {
        Models::Prompt p;
        p.setId(QStringLiteral("translate-ru"));
        p.setName(tr("Translate to Russian"));
        p.setDescription(tr("Translate the text to Russian"));
        p.setIcon(Models::PromptIcon::Translate);
        p.setSystemPrompt(tr("Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл."));
        p.setUserPromptTemplate(tr("{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Translate to English
    {
        Models::Prompt p;
        p.setId(QStringLiteral("translate-en"));
        p.setName(tr("Translate to English"));
        p.setDescription(tr("Translate the text to English"));
        p.setIcon(Models::PromptIcon::Translate);
        p.setSystemPrompt(tr("You are a professional translator. Translate the text to English, preserving style and meaning."));
        p.setUserPromptTemplate(tr("{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Code explanation
    {
        Models::Prompt p;
        p.setId(QStringLiteral("explain-code"));
        p.setName(tr("Explain Code"));
        p.setDescription(tr("Explain what the code does"));
        p.setIcon(Models::PromptIcon::Explain);
        p.setSystemPrompt(tr("You are an expert programmer. Explain the code clearly and concisely."));
        p.setUserPromptTemplate(tr("Explain the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Code review
    {
        Models::Prompt p;
        p.setId(QStringLiteral("code-review"));
        p.setName(tr("Code Review"));
        p.setDescription(tr("Review code and suggest improvements"));
        p.setIcon(Models::PromptIcon::CodeReview);
        p.setSystemPrompt(tr("You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements."));
        p.setUserPromptTemplate(tr("Review the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Refactor code
    {
        Models::Prompt p;
        p.setId(QStringLiteral("refactor"));
        p.setName(tr("Refactor Code"));
        p.setDescription(tr("Suggest refactoring improvements"));
        p.setIcon(Models::PromptIcon::Refactor);
        p.setSystemPrompt(tr("You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance."));
        p.setUserPromptTemplate(tr("Refactor the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QStringLiteral("openai/gpt-4"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Image description
    {
        Models::Prompt p;
        p.setId(QStringLiteral("describe-image"));
        p.setName(tr("Describe Image"));
        p.setDescription(tr("Generate a detailed description of the image"));
        p.setIcon(Models::PromptIcon::Custom);
        p.setSystemPrompt(tr("You are a visual analyst. Provide a detailed description of the image."));
        p.setUserPromptTemplate(tr("Describe this image in detail."));
        p.setContentType(Models::ContentType::Image);
        p.setModel(QStringLiteral("openai/gpt-4-vision-preview"));
        p.setEnabled(true);
        prompts.append(p);
    }

    // Extract text from image
    {
        Models::Prompt p;
        p.setId(QStringLiteral("ocr"));
        p.setName(tr("Extract Text"));
        p.setDescription(tr("Extract all text from the image"));
        p.setIcon(Models::PromptIcon::Custom);
        p.setSystemPrompt(tr("Extract all text from the image, preserving formatting where possible."));
        p.setUserPromptTemplate(tr("Extract all text from this image."));
        p.setContentType(Models::ContentType::Image);
        p.setModel(QStringLiteral("openai/gpt-4-vision-preview"));
        p.setEnabled(true);
        prompts.append(p);
    }

    return prompts;
}

QJsonObject PromptManager::getDefaultPromptsJson()
{
    QJsonObject root;
    root[QStringLiteral("version")] = QStringLiteral("1.0");

    QJsonArray promptsArray;
    for (const auto& prompt : getDefaultPrompts()) {
        promptsArray.append(prompt.toJson());
    }
    root[QStringLiteral("prompts")] = promptsArray;

    return root;
}

} // namespace Core
} // namespace ClipAI
