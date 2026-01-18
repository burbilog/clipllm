#include "llmconfig.h"

namespace ClipAI {
namespace Models {

QJsonObject LLMConfig::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("provider")] = providerToString(m_provider);
    obj[QStringLiteral("api_key")] = m_apiKey; // Note: Typically not saved to file for security
    obj[QStringLiteral("model")] = m_model;
    obj[QStringLiteral("api_url")] = m_apiUrl.toString();
    obj[QStringLiteral("organization_id")] = m_organizationId;
    obj[QStringLiteral("response_format")] = responseFormatToString(m_responseFormat);
    obj[QStringLiteral("temperature")] = m_temperature;
    obj[QStringLiteral("max_tokens")] = m_maxTokens;
    obj[QStringLiteral("top_p")] = m_topP;
    obj[QStringLiteral("stream")] = m_stream;
    obj[QStringLiteral("override_temperature")] = m_overrideTemperature;
    obj[QStringLiteral("proxy_url")] = m_proxyUrl;
    obj[QStringLiteral("timeout_seconds")] = m_timeoutSeconds;
    return obj;
}

bool LLMConfig::fromJson(const QJsonObject& json)
{
    m_provider = providerFromString(json.value(QStringLiteral("provider")).toString());
    m_model = json.value(QStringLiteral("model")).toString(QStringLiteral("openai/gpt-4"));
    m_apiUrl = QUrl(json.value(QStringLiteral("api_url")).toString(
                        QStringLiteral("https://openrouter.ai/api/v1/chat/completions")));
    m_organizationId = json.value(QStringLiteral("organization_id")).toString();
    m_responseFormat = responseFormatFromString(
        json.value(QStringLiteral("response_format")).toString());
    m_temperature = json.value(QStringLiteral("temperature")).toDouble(0.7);
    m_maxTokens = json.value(QStringLiteral("max_tokens")).toInt(131072);
    m_topP = json.value(QStringLiteral("top_p")).toInt(100);
    m_stream = json.value(QStringLiteral("stream")).toBool(true);
    m_overrideTemperature = json.value(QStringLiteral("override_temperature")).toBool(false);
    m_proxyUrl = json.value(QStringLiteral("proxy_url")).toString();
    m_timeoutSeconds = json.value(QStringLiteral("timeout_seconds")).toInt(120);

    // API key is loaded separately from secure storage
    m_apiKey.clear();

    return isValid();
}

QString LLMConfig::providerName() const
{
    return providerToString(m_provider);
}

LLMProvider LLMConfig::providerFromString(const QString& str)
{
    QString lower = str.toLower();
    if (lower == QStringLiteral("openrouter")) {
        return LLMProvider::OpenRouter;
    } else if (lower == QStringLiteral("openai")) {
        return LLMProvider::OpenAI;
    } else if (lower == QStringLiteral("anthropic")) {
        return LLMProvider::Anthropic;
    } else if (lower == QStringLiteral("custom")) {
        return LLMProvider::Custom;
    }
    return LLMProvider::OpenRouter;
}

QString LLMConfig::providerToString(LLMProvider provider)
{
    switch (provider) {
        case LLMProvider::OpenRouter:
            return QStringLiteral("openrouter");
        case LLMProvider::OpenAI:
            return QStringLiteral("openai");
        case LLMProvider::Anthropic:
            return QStringLiteral("anthropic");
        case LLMProvider::Custom:
            return QStringLiteral("custom");
    }
    return QStringLiteral("openrouter");
}

ResponseFormat LLMConfig::responseFormatFromString(const QString& str)
{
    QString lower = str.toLower();
    if (lower == QStringLiteral("json")) {
        return ResponseFormat::JSON;
    }
    return ResponseFormat::Text;
}

QString LLMConfig::responseFormatToString(ResponseFormat format)
{
    switch (format) {
        case ResponseFormat::JSON:
            return QStringLiteral("json");
        case ResponseFormat::Text:
            return QStringLiteral("text");
    }
    return QStringLiteral("text");
}

bool LLMConfig::isValid() const
{
    // Basic validation - API key can be loaded separately
    return !m_model.isEmpty() && m_apiUrl.isValid();
}

LLMConfig LLMConfig::createDefault(LLMProvider provider)
{
    LLMConfig config;
    config.setProvider(provider);

    switch (provider) {
        case LLMProvider::OpenRouter:
            config.setApiUrl(QUrl(QStringLiteral("https://openrouter.ai/api/v1/chat/completions")));
            config.setModel(QStringLiteral("openai/gpt-4"));
            break;
        case LLMProvider::OpenAI:
            config.setApiUrl(QUrl(QStringLiteral("https://api.openai.com/v1/chat/completions")));
            config.setModel(QStringLiteral("gpt-4"));
            break;
        case LLMProvider::Anthropic:
            config.setApiUrl(QUrl(QStringLiteral("https://api.anthropic.com/v1/messages")));
            config.setModel(QStringLiteral("claude-3-opus-20240229"));
            break;
        case LLMProvider::Custom:
            config.setApiUrl(QUrl());
            config.setModel(QString());
            break;
    }

    return config;
}

QStringList LLMConfig::availableModels(LLMProvider provider)
{
    switch (provider) {
        case LLMProvider::OpenRouter:
            return {
                QStringLiteral("openai/gpt-4"),
                QStringLiteral("openai/gpt-4-turbo"),
                QStringLiteral("openai/gpt-3.5-turbo"),
                QStringLiteral("anthropic/claude-3-opus"),
                QStringLiteral("anthropic/claude-3-sonnet"),
                QStringLiteral("google/gemini-pro"),
                QStringLiteral("meta-llama/llama-3-70b")
            };
        case LLMProvider::OpenAI:
            return {
                QStringLiteral("gpt-4"),
                QStringLiteral("gpt-4-turbo-preview"),
                QStringLiteral("gpt-3.5-turbo"),
                QStringLiteral("gpt-4-vision-preview")
            };
        case LLMProvider::Anthropic:
            return {
                QStringLiteral("claude-3-opus-20240229"),
                QStringLiteral("claude-3-sonnet-20240229"),
                QStringLiteral("claude-3-haiku-20240307")
            };
        case LLMProvider::Custom:
            return QStringList();
    }
    return QStringList();
}

} // namespace Models
} // namespace ClipAI
