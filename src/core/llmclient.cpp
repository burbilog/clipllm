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

#include "llmclient.h"
#include "debuglogger.h"
#include "core/app.h"
#include <QNetworkRequest>
#include <QHttpMultiPart>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QNetworkProxy>
#include <QSslConfiguration>
#include <QRegularExpression>
#include <QDebug>

namespace ClipLLM {
namespace Core {

// LLMMessage implementation
QJsonObject LLMMessage::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("role")] = role;
    obj[QStringLiteral("content")] = content;

    if (!images.isEmpty()) {
        // For vision models, content becomes an array
        QJsonArray contentArray;

        // Text part
        QJsonObject textPart;
        textPart[QStringLiteral("type")] = QStringLiteral("text");
        textPart[QStringLiteral("text")] = content;
        contentArray.append(textPart);

        // Image parts
        for (const QJsonValue& img : images) {
            QJsonObject imagePart;
            imagePart[QStringLiteral("type")] = QStringLiteral("image_url");
            QJsonObject imageUrl;
            imageUrl[QStringLiteral("url")] = QStringLiteral("data:image/png;base64,") + img.toString();
            imagePart[QStringLiteral("image_url")] = imageUrl;
            contentArray.append(imagePart);
        }

        obj[QStringLiteral("content")] = contentArray;
    }

    return obj;
}

// LLMRequest implementation
QJsonObject LLMRequest::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("model")] = model;
    if (temperature >= 0) {
        obj[QStringLiteral("temperature")] = temperature;
    }
    if (maxTokens >= 0) {
        obj[QStringLiteral("max_tokens")] = maxTokens;
    }
    obj[QStringLiteral("stream")] = stream;

    if (responseFormat == QStringLiteral("json")) {
        QJsonObject responseFormatObj;
        responseFormatObj[QStringLiteral("type")] = QStringLiteral("json_object");
        obj[QStringLiteral("response_format")] = responseFormatObj;
    }

    QJsonArray messagesArray;
    for (const auto& msg : messages) {
        messagesArray.append(msg.toJson());
    }
    obj[QStringLiteral("messages")] = messagesArray;

    return obj;
}

// LLMClient implementation
LLMClient::LLMClient(QObject* parent)
    : QObject(parent)
    , m_networkManager(new QNetworkAccessManager(this))
{
    // Set default config
    m_config = Models::LLMConfig::createDefault(Models::LLMProvider::OpenRouter);
}

LLMClient::~LLMClient()
{
    if (m_currentReply) {
        m_currentReply->abort();
        m_currentReply->deleteLater();
    }
}

void LLMClient::setConfig(const Models::LLMConfig& config)
{
    m_config = config;
    m_streamEnabled = config.stream();
}

void LLMClient::setApiKey(const QString& apiKey)
{
    m_apiKey = apiKey;
}

void LLMClient::setModel(const QString& model)
{
    m_config.setModel(model);
}

void LLMClient::setApiUrl(const QUrl& url)
{
    m_config.setApiUrl(url);
}

void LLMClient::setProxy(const QString& proxyUrl)
{
    m_config.setProxyUrl(proxyUrl);

    if (!proxyUrl.isEmpty()) {
        QUrl proxy(proxyUrl);

        // Determine proxy type from scheme
        QString scheme = proxy.scheme().toLower();
        QNetworkProxy::ProxyType proxyType = QNetworkProxy::HttpProxy;

        if (scheme == QStringLiteral("socks5") || scheme == QStringLiteral("socks5h")) {
            proxyType = QNetworkProxy::Socks5Proxy;
        } else if (scheme == QStringLiteral("http") || scheme == QStringLiteral("https")) {
            proxyType = QNetworkProxy::HttpProxy;
        }

        QNetworkProxy networkProxy(
            proxyType,
            proxy.host(),
            proxy.port(8080)
        );

        if (!proxy.userName().isEmpty()) {
            networkProxy.setUser(proxy.userName());
            networkProxy.setPassword(proxy.password());
        }

        m_networkManager->setProxy(networkProxy);
    } else {
        m_networkManager->setProxy(QNetworkProxy::NoProxy);
    }
}

void LLMClient::setStreamEnabled(bool enabled)
{
    m_streamEnabled = enabled;
}

void LLMClient::sendRequest(const LLMRequest& request)
{
    // Proceed without API key - let the API decide if it's required

    // Cancel any existing request
    if (m_currentReply) {
        m_currentReply->abort();
        m_currentReply->deleteLater();
    }

    m_isTestingConnection = false;  // Ensure connection test flag is reset for normal requests
    setState(LLMClientState::Connecting);
    m_accumulatedContent.clear();
    m_lastInputTokens = 0;
    m_lastOutputTokens = 0;
    m_currentModel = request.model;
    m_isThinking = false;
    m_bytesReceived = 0;
    emit thinkingStateChanged(false);
    emit bytesReceivedChanged(0);

    QNetworkRequest netRequest = createRequest(request);
    QByteArray body = createRequestBody(request);

    // Log with DebugLogger if enabled
    if (auto* app = qobject_cast<App*>(QApplication::instance())) {
        if (auto* logger = app->debugLogger(); logger && logger->isEnabled()) {
            logger->debug(QStringLiteral("=== LLM Request ==="));
            logger->debug(QStringLiteral("URL: %1").arg(m_config.apiUrl().toString()));
            logger->debug(QStringLiteral("Model: %1").arg(request.model));
            logger->debug(QStringLiteral("Messages: %1").arg(request.messages.size()));

            if (logger->currentLevel() >= DebugLevel::Trace) {
                logger->trace(QStringLiteral("Request body: %1").arg(QString::fromUtf8(body)));
            }
        }
    }

    m_currentReply = m_networkManager->post(netRequest, body);

    connect(m_currentReply, &QNetworkReply::readyRead,
            this, &LLMClient::onReadyRead);
    connect(m_currentReply, &QNetworkReply::finished,
            this, &LLMClient::onFinished);
    connect(m_currentReply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &LLMClient::onErrorOccurred);
    connect(m_currentReply, &QNetworkReply::sslErrors,
            this, &LLMClient::onSslErrors);
    connect(m_currentReply, &QNetworkReply::downloadProgress,
            this, &LLMClient::progress);

    emit started();
}

void LLMClient::sendPrompt(const QString& systemPrompt, const QString& userPrompt,
                          const QByteArray& imageData, double temperature)
{
    LLMRequest request;
    request.model = m_config.model();
    // Use provided temperature if >= 0, otherwise use config
    if (temperature >= 0) {
        request.temperature = temperature;
    } else {
        request.temperature = m_config.overrideTemperature() ? m_config.temperature() : -1;
    }
    request.maxTokens = m_config.maxTokens();
    request.stream = m_streamEnabled;

    // System message
    if (!systemPrompt.isEmpty()) {
        LLMMessage sysMsg;
        sysMsg.role = QStringLiteral("system");
        sysMsg.content = systemPrompt;
        request.messages.append(sysMsg);
    }

    // User message
    LLMMessage userMsg;
    userMsg.role = QStringLiteral("user");
    userMsg.content = userPrompt;

    if (!imageData.isEmpty()) {
        QString base64Image = QString::fromLatin1(imageData.toBase64());
        userMsg.images.append(QJsonValue(base64Image));
    }

    request.messages.append(userMsg);

    sendRequest(request);
}

void LLMClient::cancel()
{
    if (m_currentReply) {
        // Disconnect all signals from the reply to prevent crashes during abort
        disconnect(m_currentReply, nullptr, this, nullptr);
        m_currentReply->abort();
        m_currentReply->deleteLater();  // Explicitly delete since we disconnected signals
        m_currentReply = nullptr;
    }

    setState(LLMClientState::Idle);
    m_accumulatedContent.clear();
    m_sseBuffer.clear();
}

void LLMClient::testConnection()
{
    if (m_apiKey.isEmpty()) {
        emit connectionTestResult(false, tr("API key is not set"));
        return;
    }

    // Cancel any existing request
    if (m_currentReply) {
        m_currentReply->abort();
        m_currentReply->deleteLater();
    }

    m_isTestingConnection = true;
    setState(LLMClientState::Connecting);
    m_accumulatedContent.clear();
    m_sseBuffer.clear();

    // Create minimal test request
    LLMRequest request;
    request.model = m_config.model();
    request.temperature = 0.0;
    request.maxTokens = 10;  // Very short response
    request.stream = false;  // Non-streaming for simpler handling

    // Simple "hi" message
    LLMMessage userMsg;
    userMsg.role = QStringLiteral("user");
    userMsg.content = QStringLiteral("hi");
    request.messages.append(userMsg);

    QNetworkRequest netRequest = createRequest(request);
    QByteArray body = createRequestBody(request);

    m_currentReply = m_networkManager->post(netRequest, body);

    connect(m_currentReply, &QNetworkReply::readyRead,
            this, &LLMClient::onReadyRead);
    connect(m_currentReply, &QNetworkReply::finished,
            this, &LLMClient::onFinished);
    connect(m_currentReply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::errorOccurred),
            this, &LLMClient::onErrorOccurred);
}

void LLMClient::onReadyRead()
{
    if (!m_currentReply) {
        return;
    }

    setState(LLMClientState::Streaming);

    QByteArray data = m_currentReply->readAll();
    m_bytesReceived += data.size();
    emit bytesReceivedChanged(m_bytesReceived);

    // Log raw response chunks at trace level
    if (auto* app = qobject_cast<App*>(QApplication::instance())) {
        if (auto* logger = app->debugLogger(); logger && logger->currentLevel() >= DebugLevel::Trace) {
            logger->trace(QStringLiteral("Response chunk: %1").arg(QString::fromUtf8(data)));
        }
    }

    // For connection test, any data received means success
    if (m_isTestingConnection) {
        int httpStatus = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if (httpStatus >= 200 && httpStatus < 300) {
            // Got successful response - abort and report success
            disconnect(m_currentReply, nullptr, this, nullptr);
            m_currentReply->abort();
            m_currentReply->deleteLater();
            m_currentReply = nullptr;

            m_isTestingConnection = false;
            setState(LLMClientState::Idle);
            emit connectionTestResult(true, tr("Connection successful"));
            return;
        }
    }

    processStreamingChunk(data);
}

void LLMClient::onFinished()
{
    if (!m_currentReply) {
        return;
    }

    // If an error already occurred, just clean up and return
    // (onErrorOccurred was called first and set state to Error)
    if (m_state == LLMClientState::Error) {
        m_sseBuffer.clear();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
        return;
    }

    // Check HTTP status for all requests (not just connection test)
    int httpStatus = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

    // Check for authentication/authorization errors (401, 403)
    if (httpStatus == 401 || httpStatus == 403) {
        m_sseBuffer.clear();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
        setState(LLMClientState::Error);

        QString errorMsg = tr("HTTP %1: Authentication required. Please check your API key.")
            .arg(httpStatus);
        emit error(errorMsg);
        return;
    }

    // Check for other HTTP errors (4xx, 5xx)
    if (httpStatus >= 400) {
        QByteArray data = m_currentReply->readAll();
        QString serverError = QString::fromUtf8(data);

        m_sseBuffer.clear();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
        setState(LLMClientState::Error);

        QString errorMsg = tr("HTTP %1: %2").arg(httpStatus).arg(serverError);
        emit error(errorMsg);
        return;
    }

    // Handle non-streaming response
    if (m_state == LLMClientState::Connecting) {
        QByteArray data = m_currentReply->readAll();
        QJsonParseError error;
        QJsonDocument doc = QJsonDocument::fromJson(data, &error);

        if (error.error == QJsonParseError::NoError && doc.isObject()) {
            QJsonObject obj = doc.object();

            // Check for error
            if (obj.contains(QStringLiteral("error"))) {
                QJsonObject errorObj = obj.value(QStringLiteral("error")).toObject();
                QString errorMsg = errorObj.value(QStringLiteral("message")).toString();
                setState(LLMClientState::Error);
                emit this->error(errorMsg);
                m_currentReply->deleteLater();
                m_currentReply = nullptr;
                return;
            }

            // Parse response
            QJsonArray choices = obj.value(QStringLiteral("choices")).toArray();
            if (!choices.isEmpty()) {
                QJsonObject choice = choices.first().toObject();
                QJsonObject message = choice.value(QStringLiteral("message")).toObject();
                m_accumulatedContent = message.value(QStringLiteral("content")).toString();

                // Token usage
                QJsonObject usage = obj.value(QStringLiteral("usage")).toObject();
                m_lastInputTokens = usage.value(QStringLiteral("prompt_tokens")).toInt();
                m_lastOutputTokens = usage.value(QStringLiteral("completion_tokens")).toInt();
            }
        }
    }

    // Handle connection test for non-streaming responses
    if (m_isTestingConnection) {
        m_isTestingConnection = false;
        int httpStatus = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();

        if (httpStatus >= 200 && httpStatus < 300) {
            setState(LLMClientState::Idle);
            emit connectionTestResult(true, tr("Connection successful"));
        } else {
            setState(LLMClientState::Error);
            QString errorMsg = tr("HTTP %1: %2")
                .arg(httpStatus)
                .arg(m_currentReply->errorString());
            emit connectionTestResult(false, errorMsg);
        }

        m_sseBuffer.clear();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;
        return;
    }

    LLMResponse response;
    response.content = m_accumulatedContent;
    response.model = m_currentModel;
    response.done = true;
    response.inputTokens = m_lastInputTokens;
    response.outputTokens = m_lastOutputTokens;

    setState(LLMClientState::Completed);
    emit completed(response);

    m_sseBuffer.clear();
    m_currentReply->deleteLater();
    m_currentReply = nullptr;
}

void LLMClient::onErrorOccurred(QNetworkReply::NetworkError code)
{
    QString errorMsg;
    if (m_currentReply) {
        errorMsg = m_currentReply->errorString();
    }

    // For authentication errors, add a standard marker for dialog detection
    if (code == QNetworkReply::AuthenticationRequiredError) {
        errorMsg = QStringLiteral("401 Unauthorized: ") + errorMsg;
    }

    // Also check HTTP status attribute for other auth errors
    // (some APIs return 401/403 without triggering AuthenticationRequiredError)
    if (m_currentReply) {
        int httpStatus = m_currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        if ((httpStatus == 401 || httpStatus == 403) &&
            !errorMsg.startsWith(QLatin1String("HTTP "))) {
            errorMsg = tr("HTTP %1: ").arg(httpStatus) + errorMsg;
        }
    }

    // Handle connection test error
    if (m_isTestingConnection) {
        m_isTestingConnection = false;
        setState(LLMClientState::Idle);
        emit connectionTestResult(false, errorMsg);
        return;
    }

    m_sseBuffer.clear();
    setState(LLMClientState::Error);
    emit error(errorMsg);
}

void LLMClient::onSslErrors(const QList<QSslError>& errors)
{
    QStringList errorStrings;
    for (const QSslError& error : errors) {
        errorStrings.append(error.errorString());
    }

    qWarning() << "SSL errors:" << errorStrings.join(QStringLiteral(", "));

    // For connection test, SSL errors are considered a failure
    if (m_isTestingConnection && m_currentReply) {
        m_isTestingConnection = false;
        disconnect(m_currentReply, nullptr, this, nullptr);
        m_currentReply->abort();
        m_currentReply->deleteLater();
        m_currentReply = nullptr;

        setState(LLMClientState::Idle);
        emit connectionTestResult(false, tr("SSL error: %1").arg(errorStrings.join(QStringLiteral(", "))));
        return;
    }

    // For production, you may want to be more strict
    // m_currentReply->ignoreSslErrors();
}

void LLMClient::setState(LLMClientState state)
{
    if (m_state != state) {
        m_state = state;
        emit stateChanged(state);
    }
}

QNetworkRequest LLMClient::createRequest(const LLMRequest& llmRequest) const
{
    QNetworkRequest request;
    request.setUrl(m_config.apiUrl());
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
    request.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("ClipLLM/1.0"));

    // Set authorization header only if API key is present
    if (!m_apiKey.isEmpty()) {
        QString authHeader = QStringLiteral("Bearer ") + m_apiKey;
        request.setRawHeader("Authorization", authHeader.toUtf8());
    }

    // Additional headers
    request.setRawHeader("HTTP-Referer", QStringLiteral("https://clipllm.org").toUtf8()); // For OpenRouter
    request.setRawHeader("X-Title", QStringLiteral("ClipLLM").toUtf8()); // For OpenRouter

    return request;
}

QByteArray LLMClient::createRequestBody(const LLMRequest& llmRequest) const
{
    QJsonObject obj = llmRequest.toJson();
    QJsonDocument doc(obj);
    return doc.toJson(QJsonDocument::Compact);
}

void LLMClient::processStreamingChunk(const QByteArray& chunk)
{
    // Append new data to buffer
    m_sseBuffer.append(chunk);

    // Process complete SSE messages (format: "data: {...}\n\n")
    int pos = 0;
    while ((pos = m_sseBuffer.indexOf('\n')) >= 0) {
        QByteArray line = m_sseBuffer.left(pos);
        m_sseBuffer = m_sseBuffer.mid(pos + 1);

        // Skip empty lines
        if (line.trimmed().isEmpty()) {
            continue;
        }

        QString lineStr = QString::fromUtf8(line);

        if (lineStr.startsWith(QStringLiteral("data: "))) {
            QString data = lineStr.mid(6); // Remove "data: " prefix

            // Check for done signal
            if (data == QStringLiteral("[DONE]")) {
                continue;
            }

            processOpenRouterChunk(data);
        }
    }
}

void LLMClient::processOpenRouterChunk(const QString& data)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse streaming chunk:" << error.errorString();
        return;
    }

    if (!doc.isObject()) {
        return;
    }

    QJsonObject obj = doc.object();

    // Parse choices
    QJsonArray choices = obj.value(QStringLiteral("choices")).toArray();
    if (choices.isEmpty()) {
        return;
    }

    QJsonObject choice = choices.first().toObject();
    QJsonObject delta = choice.value(QStringLiteral("delta")).toObject();

    // Check for reasoning content (for thinking models)
    QString reasoning = delta.value(QStringLiteral("reasoning")).toString();
    QString reasoningContent = delta.value(QStringLiteral("reasoning_content")).toString();
    QString content = delta.value(QStringLiteral("content")).toString();

    bool wasThinking = m_isThinking;

    if (!reasoning.isEmpty() || !reasoningContent.isEmpty()) {
        m_isThinking = true;
    }

    if (!content.isEmpty()) {
        m_isThinking = false;
        m_accumulatedContent.append(content);
        emit streaming(content);
    }

    // Emit signal if thinking state changed
    if (wasThinking != m_isThinking) {
        emit thinkingStateChanged(m_isThinking);
    }

    // Update usage info if available
    QJsonObject usage = obj.value(QStringLiteral("usage")).toObject();
    if (!usage.isEmpty()) {
        m_lastInputTokens = usage.value(QStringLiteral("prompt_tokens")).toInt();
        m_lastOutputTokens = usage.value(QStringLiteral("completion_tokens")).toInt();
    }

    m_currentModel = obj.value(QStringLiteral("model")).toString(m_currentModel);
}

void LLMClient::processAnthropicChunk(const QString& data)
{
    // Anthropic uses a different streaming format
    // This is a placeholder for Anthropic-specific handling
    processOpenRouterChunk(data);
}

QString LLMClient::parseSseLine(const QString& line)
{
    if (line.startsWith(QStringLiteral("data: "))) {
        return line.mid(6);
    }
    return line;
}

} // namespace Core
} // namespace ClipLLM
