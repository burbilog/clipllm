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

#ifndef CLIPLLM_MODELS_LLMCONFIG_H
#define CLIPLLM_MODELS_LLMCONFIG_H

#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QUrl>

namespace ClipLLM {
namespace Models {

enum class LLMProvider {
    OpenRouter,
    OpenAI,
    Anthropic,
    Custom
};

enum class ResponseFormat {
    Text,
    JSON
};

class LLMConfig
{
public:
    LLMConfig() = default;

    // Getters
    LLMProvider provider() const { return m_provider; }
    QString apiKey() const { return m_apiKey; }
    QString model() const { return m_model; }
    QUrl apiUrl() const { return m_apiUrl; }
    QString organizationId() const { return m_organizationId; }
    ResponseFormat responseFormat() const { return m_responseFormat; }
    double temperature() const { return m_temperature; }
    int maxTokens() const { return m_maxTokens; }
    int topP() const { return m_topP; }
    bool stream() const { return m_stream; }
    bool overrideTemperature() const { return m_overrideTemperature; }
    QString proxyUrl() const { return m_proxyUrl; }
    int timeoutSeconds() const { return m_timeoutSeconds; }

    // Setters
    void setProvider(LLMProvider provider) { m_provider = provider; }
    void setApiKey(const QString& key) { m_apiKey = key; }
    void setModel(const QString& model) { m_model = model; }
    void setApiUrl(const QUrl& url) { m_apiUrl = url; }
    void setOrganizationId(const QString& id) { m_organizationId = id; }
    void setResponseFormat(ResponseFormat format) { m_responseFormat = format; }
    void setTemperature(double temp) { m_temperature = temp; }
    void setMaxTokens(int tokens) { m_maxTokens = tokens; }
    void setTopP(int topP) { m_topP = topP; }
    void setStream(bool stream) { m_stream = stream; }
    void setOverrideTemperature(bool override) { m_overrideTemperature = override; }
    void setProxyUrl(const QString& proxy) { m_proxyUrl = proxy; }
    void setTimeoutSeconds(int seconds) { m_timeoutSeconds = seconds; }

    // Serialization
    QJsonObject toJson() const;
    bool fromJson(const QJsonObject& json);

    // Utility
    QString providerName() const;
    static LLMProvider providerFromString(const QString& str);
    static QString providerToString(LLMProvider provider);
    static ResponseFormat responseFormatFromString(const QString& str);
    static QString responseFormatToString(ResponseFormat format);

    // Validation
    bool isValid() const;

    // Create default configs for providers
    static LLMConfig createDefault(LLMProvider provider);

    // Get list of available models for a provider
    static QStringList availableModels(LLMProvider provider);

private:
    LLMProvider m_provider = LLMProvider::OpenRouter;
    QString m_apiKey;
    QString m_model = QStringLiteral("openai/gpt-4");
    QUrl m_apiUrl = QUrl(QStringLiteral("https://openrouter.ai/api/v1/chat/completions"));
    QString m_organizationId;
    ResponseFormat m_responseFormat = ResponseFormat::Text;
    double m_temperature = 0.7;
    int m_maxTokens = 131072;
    int m_topP = 100; // Stored as 0-100
    bool m_stream = true;
    bool m_overrideTemperature = false;
    QString m_proxyUrl;
    int m_timeoutSeconds = 120;
};

} // namespace Models
} // namespace ClipLLM

Q_DECLARE_METATYPE(ClipLLM::Models::LLMConfig)
Q_DECLARE_METATYPE(ClipLLM::Models::LLMProvider)
Q_DECLARE_METATYPE(ClipLLM::Models::ResponseFormat)

#endif // CLIPLLM_MODELS_LLMCONFIG_H
