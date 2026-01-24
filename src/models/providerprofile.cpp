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
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include "providerprofile.h"
#include <QCryptographicHash>
#include <QDateTime>
#include <QDebug>

namespace ClipLLM {
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

    // Proxy URL - only save if set
    if (!m_proxyUrl.isEmpty()) {
        obj[QStringLiteral("proxy_url")] = m_proxyUrl;
    }

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

    // Proxy URL - optional
    m_proxyUrl = json.value(QStringLiteral("proxy_url")).toString();

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
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
        },
        {
            QStringLiteral("OpenAI"),
            QStringLiteral("https://api.openai.com/v1/chat/completions"),
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
        },
        {
            QStringLiteral("Ollama"),
            QStringLiteral("http://localhost:11434/v1/chat/completions"),
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
        },
        {
            QStringLiteral("NanoGPT"),
            QStringLiteral("https://nano-gpt.com/api/v1/chat/completions"),
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
        },
        {
            QStringLiteral("llama.cpp"),
            QStringLiteral("http://localhost:8080/v1/chat/completions"),
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
        },
        {
            QStringLiteral("Custom"),
            QString(),
            QString(),
            {QStringLiteral("Click Refresh to fetch models...")}
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
} // namespace ClipLLM
