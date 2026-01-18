#include "prompt.h"
#include <QJsonDocument>
#include <QRegularExpression>
#include <QLocale>
#include <QDebug>

namespace ClipAI {
namespace Models {

Prompt::Prompt(const QJsonObject& json)
{
    fromJson(json);
}

QJsonObject Prompt::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("id")] = m_id;
    obj[QStringLiteral("name")] = m_name;
    obj[QStringLiteral("description")] = m_description;
    obj[QStringLiteral("system_prompt")] = m_systemPrompt;
    obj[QStringLiteral("user_prompt_template")] = m_userPromptTemplate;
    obj[QStringLiteral("content_type")] = contentTypeToString(m_contentType);
    obj[QStringLiteral("model")] = m_model;
    obj[QStringLiteral("icon")] = iconToString(m_icon);
    obj[QStringLiteral("temperature")] = m_temperature;
    obj[QStringLiteral("max_tokens")] = m_maxTokens;
    obj[QStringLiteral("enabled")] = m_enabled;
    obj[QStringLiteral("override_temperature")] = m_overrideTemperature;

    // Convert metadata to JSON object
    QJsonObject metadataObj;
    for (auto it = m_metadata.constBegin(); it != m_metadata.constEnd(); ++it) {
        metadataObj[it.key()] = QJsonValue::fromVariant(it.value());
    }
    obj[QStringLiteral("metadata")] = metadataObj;

    return obj;
}

bool Prompt::fromJson(const QJsonObject& json)
{
    m_id = json.value(QStringLiteral("id")).toString();
    m_name = json.value(QStringLiteral("name")).toString();
    m_description = json.value(QStringLiteral("description")).toString();
    m_systemPrompt = json.value(QStringLiteral("system_prompt")).toString();
    m_userPromptTemplate = json.value(QStringLiteral("user_prompt_template"))
                           .toString(QStringLiteral("{clipboard}"));
    m_contentType = contentTypeFromString(
        json.value(QStringLiteral("content_type")).toString(QStringLiteral("any"))
    );
    m_model = json.value(QStringLiteral("model")).toString(QStringLiteral("openai/gpt-4"));
    m_icon = iconFromString(json.value(QStringLiteral("icon")).toString());
    m_temperature = json.value(QStringLiteral("temperature")).toDouble(0.7);
    m_maxTokens = json.value(QStringLiteral("max_tokens")).toInt(131072);
    m_enabled = json.value(QStringLiteral("enabled")).toBool(true);
    m_overrideTemperature = json.value(QStringLiteral("override_temperature")).toBool(false);

    // Load metadata
    QJsonObject metadataObj = json.value(QStringLiteral("metadata")).toObject();
    m_metadata.clear();
    for (auto it = metadataObj.constBegin(); it != metadataObj.constEnd(); ++it) {
        m_metadata[it.key()] = it.value().toVariant();
    }

    return isValid();
}

QString Prompt::formatSystemPrompt(const QString& clipboardContent) const
{
    QString result = m_systemPrompt;

    // Replace {clipboard} placeholder
    result.replace(QStringLiteral("{clipboard}"), clipboardContent);

    // Replace {clipboard:length} placeholder (e.g., {clipboard:1000})
    static QRegularExpression lengthRe(QStringLiteral(R"(\{clipboard:(\d+)\})"));
    QRegularExpressionMatchIterator i = lengthRe.globalMatch(result);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        int maxLength = match.captured(1).toInt();
        QString truncated = clipboardContent.left(maxLength);
        if (clipboardContent.length() > maxLength) {
            truncated += QStringLiteral("...");
        }
        result.replace(match.captured(0), truncated);
    }

    // Replace {language} placeholder with user's language
    QString userLanguage = QLocale::system().nativeLanguageName();
    result.replace(QStringLiteral("{language}"), userLanguage);

    return result;
}

QString Prompt::formatUserPrompt(const QString& clipboardContent) const
{
    QString result = m_userPromptTemplate;

    // Replace {clipboard} placeholder
    result.replace(QStringLiteral("{clipboard}"), clipboardContent);

    // Replace {clipboard:length} placeholder (e.g., {clipboard:1000})
    static QRegularExpression lengthRe(QStringLiteral(R"(\{clipboard:(\d+)\})"));
    QRegularExpressionMatchIterator i = lengthRe.globalMatch(result);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        int maxLength = match.captured(1).toInt();
        QString truncated = clipboardContent.left(maxLength);
        if (clipboardContent.length() > maxLength) {
            truncated += QStringLiteral("...");
        }
        result.replace(match.captured(0), truncated);
    }

    // Replace {language} placeholder with user's language
    QString userLanguage = QLocale::system().nativeLanguageName();
    result.replace(QStringLiteral("{language}"), userLanguage);

    return result;
}

QString Prompt::getIconName() const
{
    return iconToString(m_icon);
}

ContentType Prompt::contentTypeFromString(const QString& str)
{
    QString lower = str.toLower();
    if (lower == QStringLiteral("text")) {
        return ContentType::Text;
    } else if (lower == QStringLiteral("image")) {
        return ContentType::Image;
    }
    return ContentType::Any;
}

QString Prompt::contentTypeToString(ContentType type)
{
    switch (type) {
        case ContentType::Text:
            return QStringLiteral("text");
        case ContentType::Image:
            return QStringLiteral("image");
        case ContentType::Any:
            return QStringLiteral("any");
    }
    return QStringLiteral("any");
}

PromptIcon Prompt::iconFromString(const QString& str)
{
    QString lower = str.toLower().replace(QLatin1Char('-'), QLatin1Char('_'));
    if (lower == QStringLiteral("text_summary")) {
        return PromptIcon::TextSummary;
    } else if (lower == QStringLiteral("translate")) {
        return PromptIcon::Translate;
    } else if (lower == QStringLiteral("code_review")) {
        return PromptIcon::CodeReview;
    } else if (lower == QStringLiteral("refactor")) {
        return PromptIcon::Refactor;
    } else if (lower == QStringLiteral("explain")) {
        return PromptIcon::Explain;
    } else if (lower == QStringLiteral("custom")) {
        return PromptIcon::Custom;
    }
    return PromptIcon::None;
}

QString Prompt::iconToString(PromptIcon icon)
{
    switch (icon) {
        case PromptIcon::TextSummary:
            return QStringLiteral("text-summary");
        case PromptIcon::Translate:
            return QStringLiteral("translate");
        case PromptIcon::CodeReview:
            return QStringLiteral("code-review");
        case PromptIcon::Refactor:
            return QStringLiteral("refactor");
        case PromptIcon::Explain:
            return QStringLiteral("explain");
        case PromptIcon::Custom:
            return QStringLiteral("custom");
        case PromptIcon::None:
            return QString();
    }
    return QString();
}

bool Prompt::isValid() const
{
    return !m_id.isEmpty() && !m_name.isEmpty();
}

} // namespace Models
} // namespace ClipAI
