// ClipAI - Cross-platform LLM clipboard utility
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
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include "prompt.h"
#include <QJsonDocument>
#include <QRegularExpression>
#include <QLocale>
#include <QMap>
#include <QDebug>

namespace ClipLLM {
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
    obj[QStringLiteral("priority")] = m_priority;
    obj[QStringLiteral("override_temperature")] = m_overrideTemperature;
    obj[QStringLiteral("group")] = m_group;
    obj[QStringLiteral("provider_id")] = m_providerId;
    obj[QStringLiteral("override_provider")] = m_overrideProvider;

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
    m_priority = json.value(QStringLiteral("priority")).toInt(0);
    m_overrideTemperature = json.value(QStringLiteral("override_temperature")).toBool(false);
    m_group = json.value(QStringLiteral("group")).toString(QString());
    m_providerId = json.value(QStringLiteral("provider_id")).toString(QString());
    m_overrideProvider = json.value(QStringLiteral("override_provider")).toBool(false);

    // Load metadata
    QJsonObject metadataObj = json.value(QStringLiteral("metadata")).toObject();
    m_metadata.clear();
    for (auto it = metadataObj.constBegin(); it != metadataObj.constEnd(); ++it) {
        m_metadata[it.key()] = it.value().toVariant();
    }

    return isValid();
}

QString Prompt::formatSystemPrompt(const QString& clipboardContent, const QString& userLanguage) const
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
    QString langName = userLanguage.isEmpty() ? languageCodeToName(QLocale::system().name().left(2)) : languageCodeToName(userLanguage);
    result.replace(QStringLiteral("{language}"), langName);

    return result;
}

QString Prompt::formatUserPrompt(const QString& clipboardContent, const QString& userLanguage) const
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
    QString langName = userLanguage.isEmpty() ? languageCodeToName(QLocale::system().name().left(2)) : languageCodeToName(userLanguage);
    result.replace(QStringLiteral("{language}"), langName);

    return result;
}

QString Prompt::languageCodeToName(const QString& code)
{
    static const QMap<QString, QString> languageNames = {
        {QStringLiteral("en"), QStringLiteral("English")},
        {QStringLiteral("ru"), QStringLiteral("Русский")},
        {QStringLiteral("de"), QStringLiteral("Deutsch")},
        {QStringLiteral("fr"), QStringLiteral("Français")},
        {QStringLiteral("es"), QStringLiteral("Español")},
        {QStringLiteral("it"), QStringLiteral("Italiano")},
        {QStringLiteral("pt"), QStringLiteral("Português")},
        {QStringLiteral("zh"), QStringLiteral("中文")},
        {QStringLiteral("ja"), QStringLiteral("日本語")},
        {QStringLiteral("ko"), QStringLiteral("한국어")},
        {QStringLiteral("ar"), QStringLiteral("العربية")},
        {QStringLiteral("hi"), QStringLiteral("हिन्दी")}
    };

    return languageNames.value(code, QLocale::system().nativeLanguageName());
}

QString Prompt::getIconName() const
{
    return iconToString(m_icon);
}

QString Prompt::getSystemIconName() const
{
    // Map prompt icons to real FreeDesktop icon names that exist in system themes
    switch (m_icon) {
        case PromptIcon::TextSummary:
            return QStringLiteral("document-edit");
        case PromptIcon::Translate:
            return QStringLiteral("preferences-desktop-locale");
        case PromptIcon::CodeReview:
            return QStringLiteral("debugger");
        case PromptIcon::Refactor:
            return QStringLiteral("tools-check-spelling");
        case PromptIcon::Explain:
            return QStringLiteral("help-browser");
        case PromptIcon::Custom:
            return QStringLiteral("user-bookmarks");
        case PromptIcon::None:
            return QString();
    }
    return QString();
}

QStyle::StandardPixmap Prompt::getStandardIcon() const
{
    // Map prompt icons to cross-platform QStyle standard icons
    // These work on Linux, Windows, and macOS
    switch (m_icon) {
        case PromptIcon::TextSummary:
            return QStyle::SP_FileIcon;
        case PromptIcon::Translate:
            return QStyle::SP_DialogHelpButton;  // Use help icon for translation
        case PromptIcon::CodeReview:
            return QStyle::SP_BrowserReload;      // Use reload for review
        case PromptIcon::Refactor:
            return QStyle::SP_FileDialogDetailedView;  // Detailed view for refactor
        case PromptIcon::Explain:
            return QStyle::SP_MessageBoxInformation;    // Info for explain
        case PromptIcon::Custom:
            return QStyle::SP_DialogResetButton;       // Custom/reset
        case PromptIcon::None:
            return QStyle::SP_CustomBase;  // No icon
    }
    return QStyle::SP_CustomBase;
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
} // namespace ClipLLM
