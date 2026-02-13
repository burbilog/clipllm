// ClipLLM - Cross-platform LLM clipboard utility
// Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "promptmanager.h"
#include "ui/promptconfirmdialog.h"
#include "configmanager.h"
#include "groupsmanager.h"
#include "models/providerprofile.h"
#include "debuglogger.h"
#include "core/app.h"
#include <QApplication>
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QRegularExpression>
#include <QDebug>
#include <QMap>
#include <QSet>

namespace ClipLLM {
namespace Core {

PromptManager::PromptManager(QObject* parent)
    : QObject(parent)
{
}

PromptManager::~PromptManager() = default;

bool PromptManager::loadPrompts(GroupsManager* groupsManager)
{
    if (groupsManager) {
        m_groupsManager = groupsManager;
    }

    QString customPath = getCustomPromptsFilePath();
    LOG_DEBUG(QStringLiteral("loadPrompts: customPath = %1 exists: %2").arg(customPath).arg(QFile::exists(customPath)));

    if (QFile::exists(customPath)) {
        return loadPromptsFromFile(customPath);
    }

    // No prompts file found, create default from bundled resource
    LOG_DEBUG(QStringLiteral("No prompts file found, creating default prompts from resource"));

    // Load default prompts from resource
    QString resourcePath = QStringLiteral(":/config/prompts-default.json");
    QFile resourceFile(resourcePath);
    if (!resourceFile.open(QIODevice::ReadOnly)) {
        LOG_WARNING(QStringLiteral("Failed to open default prompts resource: %1").arg(resourcePath));
        emit promptsLoadFailed(tr("Failed to load default prompts"));
        return false;
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(resourceFile.readAll(), &error);
    resourceFile.close();

    if (error.error != QJsonParseError::NoError) {
        LOG_WARNING(QStringLiteral("Failed to parse default prompts: %1").arg(error.errorString()));
        // Fall back to hardcoded defaults
        m_prompts = getDefaultPrompts();
    } else {
        // Load prompts from JSON, including groups
        QJsonObject json = doc.object();
        loadPromptsFromJson(json);

        // Import groups from the default prompts file if they exist
        QJsonArray groupsArray = json.value(QStringLiteral("groups")).toArray();
        if (!groupsArray.isEmpty() && m_groupsManager) {
            // Load existing groups first
            QStringList existingGroups = m_groupsManager->loadGroups();
            QSet<QString> existingGroupsSet(existingGroups.begin(), existingGroups.end());

            // Merge with new default groups
            for (const QJsonValue& value : groupsArray) {
                if (value.isObject()) {
                    QJsonObject groupObj = value.toObject();
                    QString groupId = groupObj.value(QStringLiteral("id")).toString();
                    if (!groupId.isEmpty() && !existingGroupsSet.contains(groupId)) {
                        existingGroups.append(groupId);
                    }
                }
            }
            // Save merged groups
            LOG_DEBUG(QStringLiteral("Saving merged groups: %1").arg(existingGroups.join(QStringLiteral(", "))));
            m_groupsManager->saveGroups(existingGroups);
            // Reload to ensure in-memory state is updated
            m_groupsManager->loadGroups();
        }
    }

    savePromptsToFile(customPath);
    emit promptsLoaded();
    LOG_DEBUG(QStringLiteral("Prompts saved to: %1 exists: %2").arg(customPath).arg(QFile::exists(customPath)));
    return true;
}

void PromptManager::setGroupsManager(GroupsManager* groupsManager)
{
    m_groupsManager = groupsManager;
}

bool PromptManager::loadPromptsFromFile(const QString& filePath)
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly)) {
        LOG_WARNING(QStringLiteral("Failed to open prompts file: %1").arg(filePath));
        emit promptsLoadFailed(tr("Failed to open prompts file"));
        return false;
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError) {
        LOG_WARNING(QStringLiteral("Failed to parse prompts file: %1").arg(error.errorString()));
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

    LOG_DEBUG(QStringLiteral("Loaded %1 prompts").arg(m_prompts.size()));
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
        LOG_WARNING(QStringLiteral("Failed to open prompts file for writing: %1").arg(filePath));
        return false;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    return true;
}

void PromptManager::ensureGroupExists(const QString& group)
{
    if (!m_groupsManager || group.isEmpty()) {
        return;
    }

    QStringList existingGroups = m_groupsManager->loadGroups();
    if (existingGroups.contains(group)) {
        return; // Already exists
    }

    // Add the group and all its parent groups
    QStringList newGroups = existingGroups;
    QString currentPath = group;
    while (!currentPath.isEmpty()) {
        if (!newGroups.contains(currentPath)) {
            newGroups.append(currentPath);
        }
        // Move to parent
        int lastSlash = currentPath.lastIndexOf(QLatin1Char('/'));
        if (lastSlash < 0) {
            break;
        }
        currentPath = currentPath.left(lastSlash);
    }

    LOG_DEBUG(QStringLiteral("Adding new groups from prompt: %1").arg(newGroups.join(QStringLiteral(", "))));
    m_groupsManager->saveGroups(newGroups);
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
    savePrompts();
    return true;
}

bool PromptManager::updatePrompt(const QString& id, const Models::Prompt& prompt)
{
    for (int i = 0; i < m_prompts.size(); ++i) {
        if (m_prompts[i].id() == id) {
            QString oldGroup = m_prompts[i].group();
            m_prompts[i] = prompt;

            // Ensure the new group exists in GroupsManager
            if (!prompt.group().isEmpty()) {
                ensureGroupExists(prompt.group());
            }

            emit promptUpdated(id);
            savePrompts();
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
            savePrompts();
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

    // Check for valid placeholder syntax in both prompts
    QString templateStr = prompt.userPromptTemplate();
    QString systemStr = prompt.systemPrompt();
    QRegularExpression placeholderRe(QStringLiteral(R"(\{(?:clipboard|clipboard:\d+|language)\})"));

    // All placeholders should be valid in user prompt template
    QRegularExpression allBracesRe(QStringLiteral(R"(\{[^}]+\})"));
    QRegularExpressionMatchIterator allIt = allBracesRe.globalMatch(templateStr);
    while (allIt.hasNext()) {
        QRegularExpressionMatch match = allIt.next();
        QString captured = match.captured(0);
        if (!placeholderRe.match(captured).hasMatch()) {
            errors.append(tr("Invalid placeholder in user template: %1").arg(captured));
        }
    }

    // All placeholders should be valid in system prompt
    allIt = allBracesRe.globalMatch(systemStr);
    while (allIt.hasNext()) {
        QRegularExpressionMatch match = allIt.next();
        QString captured = match.captured(0);
        if (!placeholderRe.match(captured).hasMatch()) {
            errors.append(tr("Invalid placeholder in system prompt: %1").arg(captured));
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

void PromptManager::updatePromptGroup(const QString& oldGroup, const QString& newGroup)
{
    bool modified = false;
    for (auto& prompt : m_prompts) {
        if (prompt.group() == oldGroup) {
            prompt.setGroup(newGroup);
            modified = true;
        }
    }
    if (modified) {
        savePrompts();
        emit promptsLoaded(); // Notify observers of bulk change
    }
}

void PromptManager::movePromptsToGroup(const QString& fromGroup, const QString& toGroup)
{
    bool modified = false;
    for (auto& prompt : m_prompts) {
        if (prompt.group() == fromGroup) {
            prompt.setGroup(toGroup);
            modified = true;
        }
    }
    if (modified) {
        savePrompts();
        emit promptsLoaded(); // Notify observers of bulk change
    }
}

QVector<Models::Prompt> PromptManager::getDefaultPrompts()
{
    QVector<Models::Prompt> prompts;

    // Summary prompt
    {
        Models::Prompt p;
        p.setId(QStringLiteral("summary"));
        p.setName(tr("Summary"));
        p.setIcon(Models::PromptIcon::TextSummary);
        p.setSystemPrompt(tr("You are a professional analyst. Create a clear, structured summary."));
        p.setUserPromptTemplate(tr("Please provide a comprehensive summary of the following text:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Translate to Russian
    {
        Models::Prompt p;
        p.setId(QStringLiteral("translate-ru"));
        p.setName(tr("Translate to Russian"));
        p.setIcon(Models::PromptIcon::Translate);
        p.setSystemPrompt(tr("Ты — профессиональный переводчик. Переведи текст на русский язык, сохраняя стиль и смысл."));
        p.setUserPromptTemplate(tr("{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Translate to English
    {
        Models::Prompt p;
        p.setId(QStringLiteral("translate-en"));
        p.setName(tr("Translate to English"));
        p.setIcon(Models::PromptIcon::Translate);
        p.setSystemPrompt(tr("You are a professional translator. Translate the text to English, preserving style and meaning."));
        p.setUserPromptTemplate(tr("{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Code explanation
    {
        Models::Prompt p;
        p.setId(QStringLiteral("explain-code"));
        p.setName(tr("Explain Code"));
        p.setIcon(Models::PromptIcon::Explain);
        p.setSystemPrompt(tr("You are an expert programmer. Explain the code clearly and concisely."));
        p.setUserPromptTemplate(tr("Explain the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Code review
    {
        Models::Prompt p;
        p.setId(QStringLiteral("code-review"));
        p.setName(tr("Code Review"));
        p.setIcon(Models::PromptIcon::CodeReview);
        p.setSystemPrompt(tr("You are a code reviewer. Analyze the code for bugs, security issues, and suggest improvements."));
        p.setUserPromptTemplate(tr("Review the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Refactor code
    {
        Models::Prompt p;
        p.setId(QStringLiteral("refactor"));
        p.setName(tr("Refactor Code"));
        p.setIcon(Models::PromptIcon::Refactor);
        p.setSystemPrompt(tr("You are a code optimization expert. Suggest refactoring to improve readability, maintainability, and performance."));
        p.setUserPromptTemplate(tr("Refactor the following code:\n\n{clipboard}"));
        p.setContentType(Models::ContentType::Text);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Image description
    {
        Models::Prompt p;
        p.setId(QStringLiteral("describe-image"));
        p.setName(tr("Describe Image"));
        p.setIcon(Models::PromptIcon::Custom);
        p.setSystemPrompt(tr("You are a visual analyst. Provide a detailed description of the image."));
        p.setUserPromptTemplate(tr("Describe this image in detail."));
        p.setContentType(Models::ContentType::Image);
        p.setModel(QString());  // Use default from settings
        p.setEnabled(true);
        prompts.append(p);
    }

    // Extract text from image
    {
        Models::Prompt p;
        p.setId(QStringLiteral("ocr"));
        p.setName(tr("Extract Text"));
        p.setIcon(Models::PromptIcon::Custom);
        p.setSystemPrompt(tr("Extract all text from the image, preserving formatting where possible."));
        p.setUserPromptTemplate(tr("Extract all text from this image."));
        p.setContentType(Models::ContentType::Image);
        p.setModel(QString());  // Use default from settings
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

bool PromptManager::importPromptsFromJson(const QJsonObject& json,
                                         ConfigManager* configManager,
                                         GroupsManager* groupsManager,
                                         QWidget* parentWidget)
{
    using namespace UI;

    QJsonArray promptsArray = json.value(QStringLiteral("prompts")).toArray();
    if (promptsArray.isEmpty()) {
        return true; // Nothing to import
    }

    // Build map of existing prompts by name for conflict detection
    QMap<QString, Models::Prompt> existingByName;
    for (const auto& prompt : m_prompts) {
        existingByName[prompt.name()] = prompt;
    }

    // Ensure all groups from imported prompts exist in GroupsManager
    if (groupsManager) {
        QSet<QString> groupsToCreate;
        QStringList existingGroups = groupsManager->loadGroups();
        QSet<QString> existingGroupsSet(existingGroups.begin(), existingGroups.end());

        // Collect all groups from imported prompts
        for (const QJsonValue& value : promptsArray) {
            if (!value.isObject()) {
                continue;
            }
            Models::Prompt prompt(value.toObject());
            if (!prompt.group().isEmpty()) {
                QString group = prompt.group();
                // Add the group and all its parent groups
                while (!group.isEmpty() && !existingGroupsSet.contains(group)) {
                    groupsToCreate.insert(group);
                    // Also add parent groups
                    int lastSlash = group.lastIndexOf(QLatin1Char('/'));
                    if (lastSlash < 0) {
                        break;
                    }
                    group = group.left(lastSlash);
                }
            }
        }

        // Create missing groups
        if (!groupsToCreate.isEmpty()) {
            QStringList allGroups = existingGroups;
            for (const QString& group : groupsToCreate) {
                if (!allGroups.contains(group)) {
                    allGroups.append(group);
                }
            }
            groupsManager->saveGroups(allGroups);
        }
    }

    // Track "for all" decisions
    enum class GlobalDecision {
        None,
        OverwriteAll,
        SkipAll
    };
    GlobalDecision globalDecision = GlobalDecision::None;

    int importedCount = 0;

    for (const QJsonValue& value : promptsArray) {
        if (!value.isObject()) {
            continue;
        }

        Models::Prompt importedPrompt(value.toObject());
        if (!importedPrompt.isValid()) {
            continue;
        }

        // Check for name conflict
        if (existingByName.contains(importedPrompt.name())) {
            const Models::Prompt& existing = existingByName[importedPrompt.name()];

            // Always show conflict dialog, even if IDs match
            PromptConflictDialog::Action action = PromptConflictDialog::Action::Cancel;

            if (globalDecision == GlobalDecision::OverwriteAll) {
                action = PromptConflictDialog::Action::Yes;
            } else if (globalDecision == GlobalDecision::SkipAll) {
                action = PromptConflictDialog::Action::No;
            } else {
                // Show conflict dialog
                QString existingDetails = QStringLiteral("ID: %1").arg(existing.id());
                QString newDetails = QStringLiteral("ID: %1").arg(importedPrompt.id());

                PromptConflictDialog dialog(importedPrompt.name(),
                                           existingDetails,
                                           newDetails,
                                           parentWidget);
                if (dialog.exec() == QDialog::Accepted) {
                    action = dialog.action();
                } else {
                    action = PromptConflictDialog::Action::Cancel;
                }
            }

            // Handle the action
            switch (action) {
            case PromptConflictDialog::Action::Yes:
                // Overwrite this prompt
                for (int i = 0; i < m_prompts.size(); ++i) {
                    if (m_prompts[i].name() == importedPrompt.name()) {
                        m_prompts[i] = importedPrompt;
                        break;
                    }
                }
                importedCount++;
                break;

            case PromptConflictDialog::Action::YesForAll:
                // Overwrite all conflicts
                globalDecision = GlobalDecision::OverwriteAll;
                for (int i = 0; i < m_prompts.size(); ++i) {
                    if (m_prompts[i].name() == importedPrompt.name()) {
                        m_prompts[i] = importedPrompt;
                        break;
                    }
                }
                importedCount++;
                break;

            case PromptConflictDialog::Action::No:
                // Skip this prompt
                continue;

            case PromptConflictDialog::Action::NoForAll:
                // Skip all conflicts
                globalDecision = GlobalDecision::SkipAll;
                continue;

            case PromptConflictDialog::Action::Cancel:
                // Cancel entire import
                return false;
            }
        } else {
            // No conflict, add new prompt
            m_prompts.append(importedPrompt);
            existingByName[importedPrompt.name()] = importedPrompt;
            importedCount++;
        }
    }

    // Validate and fix provider settings
    if (configManager) {
        for (auto& prompt : m_prompts) {
            if (prompt.overrideProvider()) {
                QString providerId = prompt.providerId();
                // Check if provider exists
                if (!providerId.isEmpty() && !configManager->providerProfile(providerId).has_value()) {
                    // Provider doesn't exist, reset to defaults
                    prompt.setOverrideProvider(false);
                    prompt.setProviderId(QString());
                    prompt.setModel(QString());
                }
            }
        }
    }

    // Save the merged prompts
    savePrompts();
    emit promptsLoaded();
    return true;
}

} // namespace Core
} // namespace ClipLLM
