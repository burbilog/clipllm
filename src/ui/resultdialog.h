#ifndef CLIPAI_UI_RESULTDIALOG_H
#define CLIPAI_UI_RESULTDIALOG_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QElapsedTimer>

namespace ClipAI {
namespace Core {
class LLMClient;
class HistoryManager;
struct LLMResponse;
}
}

namespace ClipAI {
namespace UI {

class ResultDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResultDialog(Core::LLMClient* llmClient, Core::HistoryManager* historyManager, QWidget* parent = nullptr);
    ~ResultDialog();

    void setPrompt(const QString& promptId, const QString& promptName);
    void setInput(const QString& input);
    void setModel(const QString& model);
    void startRequest();
    void appendResponse(const QString& text);

signals:
    void responseReceived(const QString& response);
    void saveToHistoryRequested(const QString& promptId, const QString& promptName,
                                const QString& input, const QString& output);

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

private:
    void setupUi();
    void updateState();

    Core::LLMClient* m_llmClient = nullptr;
    Core::HistoryManager* m_historyManager = nullptr;

    // UI components
    QTextEdit* m_outputText = nullptr;
    QTextEdit* m_inputText = nullptr;
    QLabel* m_statusLabel = nullptr;
    QLabel* m_modelLabel = nullptr;
    QLabel* m_tokensLabel = nullptr;
    QLabel* m_trafficLabel = nullptr;
    QProgressBar* m_progressBar = nullptr;
    QPushButton* m_copyButton = nullptr;
    QPushButton* m_saveButton = nullptr;
    QPushButton* m_retryButton = nullptr;
    QPushButton* m_closeButton = nullptr;

    // Request data
    QString m_promptId;
    QString m_promptName;
    QString m_input;
    QString m_output;

    // State
    bool m_isStreaming = false;
    bool m_isThinking = false;
    bool m_wasSaved = false;
    QElapsedTimer m_timer;
    qint64 m_bytesReceived = 0;

    // Helper for traffic formatting
    static QString formatBytes(qint64 bytes);
};

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_RESULTDIALOG_H
