#include "providerprofile.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>

namespace ClipAI {
namespace Models {

ProviderProfile::ProviderProfile(const QJsonObject& json)
{
    fromJson(json);
}

QJsonObject ProviderProfile::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("id")] = m_id;
    obj[QStringLiteral("name")] = m_name;
    obj[QStringLiteral("api_url")] = m_apiUrl.toString();
    obj[QStringLiteral("model")] = m_model;

    // Temperature - only save if set
    if (m_temperature.has_value()) {
        obj[QStringLiteral("temperature")] = *m_temperature;
    }

    // MaxTokens - only save if set
    if (m_maxTokens.has_value()) {
        obj[QStringLiteral("max_tokens")] = *m_maxTokens;
    }

    obj[QStringLiteral("is_default")] = m_isDefault;
    obj[QStringLiteral("enabled")] = m_enabled;

    return obj;
}

bool ProviderProfile::fromJson(const QJsonObject& json)
{
    m_id = json.value(QStringLiteral("id")).toString();
    m_name = json.value(QStringLiteral("name")).toString();
    m_apiUrl = QUrl(json.value(QStringLiteral("api_url")).toString());
    m_model = json.value(QStringLiteral("model")).toString();

    // Temperature - optional
    if (json.contains(QStringLiteral("temperature"))) {
        m_temperature = json.value(QStringLiteral("temperature")).toDouble();
    } else {
        m_temperature = std::nullopt;
    }

    // MaxTokens - optional
    if (json.contains(QStringLiteral("max_tokens"))) {
        m_maxTokens = json.value(QStringLiteral("max_tokens")).toInt();
    } else {
        m_maxTokens = std::nullopt;
    }

    m_isDefault = json.value(QStringLiteral("is_default")).toBool(false);
    m_enabled = json.value(QStringLiteral("enabled")).toBool(true);

    return isValid();
}

bool ProviderProfile::isValid() const
{
    return !m_id.isEmpty() && !m_name.isEmpty() && m_apiUrl.isValid();
}

QList<ProviderProfile::ProviderTemplate> ProviderProfile::availableTemplates()
{
    return {
        {
            QStringLiteral("OpenRouter"),
            QStringLiteral("https://openrouter.ai/api/v1/chat/completions"),
            QStringLiteral("openai/gpt-4"),
            {
                QStringLiteral("openai/gpt-4"),
                QStringLiteral("openai/gpt-4-turbo"),
                QStringLiteral("openai/gpt-3.5-turbo"),
                QStringLiteral("anthropic/claude-3-opus"),
                QStringLiteral("anthropic/claude-3-sonnet"),
                QStringLiteral("google/gemini-pro"),
                QStringLiteral("meta-llama/llama-3-70b")
            }
        },
        {
            QStringLiteral("OpenAI"),
            QStringLiteral("https://api.openai.com/v1/chat/completions"),
            QStringLiteral("gpt-4"),
            {
                QStringLiteral("gpt-4"),
                QStringLiteral("gpt-4-turbo-preview"),
                QStringLiteral("gpt-3.5-turbo"),
                QStringLiteral("gpt-4-vision-preview")
            }
        },
        {
            QStringLiteral("Anthropic"),
            QStringLiteral("https://api.anthropic.com/v1/messages"),
            QStringLiteral("claude-3-opus-20240229"),
            {
                QStringLiteral("claude-3-opus-20240229"),
                QStringLiteral("claude-3-sonnet-20240229"),
                QStringLiteral("claude-3-haiku-20240307")
            }
        },
        {
            QStringLiteral("Ollama"),
            QStringLiteral("http://localhost:11434/v1/chat/completions"),
            QStringLiteral("llama3"),
            {
                QStringLiteral("llama3"),
                QStringLiteral("llama3:70b"),
                QStringLiteral("mistral"),
                QStringLiteral("gemma")
            }
        },
        {
            QStringLiteral("NanoGPT"),
            QStringLiteral("https://nano-gpt.com/api/v1/chat/completions"),
            QStringLiteral("nano-gpt"),
            {
                QStringLiteral("nano-gpt"),
                QStringLiteral("nano-gpt-turbo")
            }
        },
        {
            QStringLiteral("Custom"),
            QString(),
            QString(),
            QStringList()
        }
    };
}

ProviderProfile::ProviderTemplate ProviderProfile::templateByName(const QString& name)
{
    QList<ProviderTemplate> templates = availableTemplates();
    for (const auto& tmpl : templates) {
        if (tmpl.name == name) {
            return tmpl;
        }
    }
    return ProviderTemplate();
}

QStringList ProviderProfile::availableTemplateNames()
{
    QList<ProviderTemplate> templates = availableTemplates();
    QStringList names;
    for (const auto& tmpl : templates) {
        names.append(tmpl.name);
    }
    return names;
}

ProviderProfile ProviderProfile::createFromTemplate(const QString& templateName, const QString& suffix)
{
    ProviderProfile profile;
    ProviderTemplate tmpl = templateByName(templateName);

    if (tmpl.name.isEmpty()) {
        // Unknown template, create empty profile
        profile.setId(generateId(suffix.isEmpty() ? QStringLiteral("custom") : suffix));
        profile.setName(suffix.isEmpty() ? QStringLiteral("Custom Provider") : suffix);
        return profile;
    }

    QString profileName = tmpl.name;
    if (!suffix.isEmpty()) {
        profileName += QStringLiteral(" ") + suffix;
    }

    profile.setId(generateId(tmpl.name.toLower(), suffix));
    profile.setName(profileName);
    profile.setApiUrl(QUrl(tmpl.templateUrl));
    profile.setModel(tmpl.defaultModel);
    profile.setEnabled(true);
    profile.setIsDefault(false);

    // Don't set temperature/maxTokens - let them use global defaults

    return profile;
}

QString ProviderProfile::generateId(const QString& name, const QString& suffix)
{
    QString baseName = name.toLower();
    baseName.remove(QRegularExpression(QStringLiteral("[^a-z0-9]")));
    baseName.replace(QLatin1Char(' '), QLatin1Char('-'));

    QString id = baseName;
    if (!suffix.isEmpty()) {
        QString suffixClean = suffix.toLower();
        suffixClean.remove(QRegularExpression(QStringLiteral("[^a-z0-9]")));
        suffixClean.replace(QLatin1Char(' '), QLatin1Char('-'));
        id += QLatin1Char('-') + suffixClean;
    }

    // Add timestamp to ensure uniqueness
    QString timestamp = QString::number(QDateTime::currentMSecsSinceEpoch());
    id += QLatin1Char('-') + timestamp.right(6);

    return id;
}

} // namespace Models
} // namespace ClipAI
