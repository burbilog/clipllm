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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_CORE_LLMCLIENT_H
#define CLIPLLM_CORE_LLMCLIENT_H

#include <QObject>
#include <QString>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonArray>
#include "models/llmconfig.h"

namespace ClipLLM {
namespace Core {

enum class LLMClientState {
    Idle,
    Connecting,
    Streaming,
    Completed,
    Error
};

struct LLMMessage
{
    QString role; // "system", "user", "assistant"
    QString content;
    QJsonArray images; // For vision models, base64 encoded images

    QJsonObject toJson() const;
};

struct LLMRequest
{
    QString model;
    QVector<LLMMessage> messages;
    double temperature = 0.7;
    int maxTokens = 4096;
    bool stream = true;
    QString responseFormat; // "text" or "json"

    QJsonObject toJson() const;
};

struct LLMResponse
{
    QString content;
    QString model;
    bool done = false;
    QString error;
    int inputTokens = 0;
    int outputTokens = 0;
    QJsonObject raw;

    bool isSuccess() const { return error.isEmpty() && !content.isEmpty(); }
};

class LLMClient : public QObject
{
    Q_OBJECT

public:
    explicit LLMClient(QObject* parent = nullptr);
    ~LLMClient();

    // Configuration
    void setConfig(const Models::LLMConfig& config);
    Models::LLMConfig config() const { return m_config; }

    void setApiKey(const QString& apiKey);
    QString apiKey() const { return m_apiKey; }

    void setModel(const QString& model);
    QString model() const { return m_config.model(); }

    void setApiUrl(const QUrl& url);
    QUrl apiUrl() const { return m_config.apiUrl(); }

    void setProxy(const QString& proxyUrl);
    QString proxy() const { return m_config.proxyUrl(); }

    void setStreamEnabled(bool enabled);
    bool isStreamEnabled() const { return m_streamEnabled; }

    // Send request
    void sendRequest(const LLMRequest& request);
    void sendPrompt(const QString& systemPrompt, const QString& userPrompt,
                   const QByteArray& imageData = QByteArray(),
                   double temperature = -1.0);  // -1 means use config default

    // Cancel current request
    void cancel();

    // Test connection by sending minimal request
    void testConnection();

    // State
    LLMClientState state() const { return m_state; }
    bool isIdle() const { return m_state == LLMClientState::Idle; }
    bool isBusy() const { return m_state != LLMClientState::Idle &&
                                 m_state != LLMClientState::Completed &&
                                 m_state != LLMClientState::Error; }

    // Statistics
    int lastInputTokens() const { return m_lastInputTokens; }
    int lastOutputTokens() const { return m_lastOutputTokens; }
    bool isThinking() const { return m_isThinking; }
    qint64 bytesReceived() const { return m_bytesReceived; }

signals:
    void started();
    void streaming(const QString& content);
    void completed(const LLMResponse& response);
    void error(const QString& error);
    void progress(int bytesReceived, int bytesTotal);
    void stateChanged(LLMClientState state);
    void thinkingStateChanged(bool isThinking);
    void bytesReceivedChanged(qint64 bytesReceived);
    void connectionTestResult(bool success, const QString& message);

private slots:
    void onReadyRead();
    void onFinished();
    void onErrorOccurred(QNetworkReply::NetworkError code);
    void onSslErrors(const QList<QSslError>& errors);

private:
    void setState(LLMClientState state);
    QNetworkRequest createRequest(const LLMRequest& llmRequest) const;
    QByteArray createRequestBody(const LLMRequest& llmRequest) const;
    void processStreamingChunk(const QByteArray& chunk);
    void processOpenRouterChunk(const QString& data);
    void processAnthropicChunk(const QString& data);
    QString parseSseLine(const QString& line);

    Models::LLMConfig m_config;
    QString m_apiKey;
    bool m_streamEnabled = true;
    LLMClientState m_state = LLMClientState::Idle;

    QNetworkAccessManager* m_networkManager = nullptr;
    QNetworkReply* m_currentReply = nullptr;

    QString m_accumulatedContent;
    int m_lastInputTokens = 0;
    int m_lastOutputTokens = 0;

    // For tracking streaming response
    QString m_currentModel;

    // Buffer for incomplete SSE chunks
    QByteArray m_sseBuffer;

    // Thinking state (for reasoning models)
    bool m_isThinking = false;
    qint64 m_bytesReceived = 0;

    // Connection test mode
    bool m_isTestingConnection = false;
};

} // namespace Core
} // namespace ClipLLM

Q_DECLARE_METATYPE(ClipLLM::Core::LLMClientState)
Q_DECLARE_METATYPE(ClipLLM::Core::LLMMessage)
Q_DECLARE_METATYPE(ClipLLM::Core::LLMRequest)
Q_DECLARE_METATYPE(ClipLLM::Core::LLMResponse)

#endif // CLIPLLM_CORE_LLMCLIENT_H
