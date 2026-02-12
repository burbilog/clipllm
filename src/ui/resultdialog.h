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

#ifndef CLIPLLM_UI_RESULTDIALOG_H
#define CLIPLLM_UI_RESULTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QElapsedTimer>
#include <QShortcut>

QT_BEGIN_NAMESPACE
class QGroupBox;
class QSplitter;
QT_END_NAMESPACE

namespace ClipLLM {
namespace Core {
class LLMClient;
class HistoryManager;
class ConfigManager;
struct LLMResponse;
}
}

namespace ClipLLM {
namespace UI {

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(Core::LLMClient* llmClient, Core::HistoryManager* historyManager,
                         Core::ConfigManager* configManager, QWidget* parent = nullptr);
    ~ResultDialog();

    void setPrompt(const QString& promptId, const QString& promptName);
    void setInput(const QString& input);
    void setProvider(const QString& provider);
    void setModel(const QString& model);
    void setRetryContext(const QString& providerId, const QString& model,
                         const QString& systemPrompt, const QString& userPrompt,
                         const QByteArray& imageData, double temperature);
    void setChainInfo(const QStringList& chainNames, const QString& nextPromptId, bool autoContinue);
    void startRequest();
    void appendResponse(const QString& text);

signals:
    void responseReceived(const QString& response);
    void saveToHistoryRequested(const QString& promptId, const QString& promptName,
                                const QString& input, const QString& output);
    void retryRequested(const QString& promptId, const QString& providerId, const QString& model,
                        const QString& systemPrompt, const QString& userPrompt,
                        const QByteArray& imageData, double temperature);
    void chainContinueRequested(const QString& nextPromptId, const QString& output);

public slots:
    void closeDialog();

private slots:
    void onStreaming(const QString& content);
    void onCompleted(const Core::LLMResponse& response);
    void onError(const QString& error);
    void onCopyClicked();
    void onSaveClicked();
    void onRetryClicked();
    void onCloseClicked();
    void onThinkingStateChanged(bool isThinking);
    void onBytesReceivedChanged(qint64 bytesReceived);
    void performClose();
    void onMarkdownToggleClicked();
    void onInputToggleClicked();
    void onZoomOutClicked();
    void onZoomInClicked();
    void onSaveAsClicked();
    void onChainContinueClicked();

protected:
    void closeEvent(QCloseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;

private:
    void setupUi();
    void updateState();
    void updateModelLabel();
    void applyFontSize();
    void saveFontSize();
    void loadFontSize();

    Core::LLMClient* m_llmClient = nullptr;
    Core::HistoryManager* m_historyManager = nullptr;
    Core::ConfigManager* m_configManager = nullptr;

    // UI components
    QTextEdit* m_outputText = nullptr;
    QTextEdit* m_inputText = nullptr;
    QGroupBox* m_inputGroup = nullptr;
    QSplitter* m_splitter = nullptr;
    QLabel* m_statusLabel = nullptr;
    QLabel* m_modelLabel = nullptr;
    QLabel* m_tokensLabel = nullptr;
    QLabel* m_trafficLabel = nullptr;
    QProgressBar* m_progressBar = nullptr;
    QPushButton* m_copyButton = nullptr;
    QPushButton* m_saveButton = nullptr;
    QPushButton* m_retryButton = nullptr;
    QPushButton* m_closeButton = nullptr;
    QPushButton* m_markdownToggle = nullptr;
    QPushButton* m_inputToggleBtn = nullptr;
    QPushButton* m_zoomOutButton = nullptr;
    QPushButton* m_zoomInButton = nullptr;
    QPushButton* m_saveAsButton = nullptr;
    QLabel* m_chainIndicator = nullptr;
    QPushButton* m_continueButton = nullptr;

    // Markdown state
    bool m_markdownMode = true;

    // Input section state
    bool m_inputExpanded = false;

    // Font size state
    int m_fontSize = 10;

    // Request data
    QString m_promptId;
    QString m_promptName;
    QString m_input;
    QString m_output;
    QString m_provider;
    QString m_model;

    // Retry context
    QString m_providerId;
    QString m_modelForRetry;
    QString m_systemPrompt;
    QString m_userPrompt;
    QByteArray m_imageData;
    double m_temperature = -1.0;

    // State
    bool m_isStreaming = false;
    bool m_isThinking = false;
    bool m_wasSaved = false;
    bool m_closing = false;

    // Chain info
    QStringList m_chainNames;
    QString m_nextPromptId;
    bool m_autoContinue = false;

    QElapsedTimer m_timer;
    qint64 m_bytesReceived = 0;

    // Helper for traffic formatting
    static QString formatBytes(qint64 bytes);
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_RESULTDIALOG_H
