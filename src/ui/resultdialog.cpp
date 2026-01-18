#include "resultdialog.h"
#include "core/llmclient.h"
#include "core/historymanager.h"
#include "core/configmanager.h"
#include <QApplication>
#include <QClipboard>
#include <QCloseEvent>
#include <QMessageBox>
#include <QSplitter>
#include <QGroupBox>
#include <QStyle>
#include <QTimer>

namespace ClipAI {
namespace UI {

ResultDialog::ResultDialog(Core::LLMClient* llmClient, Core::HistoryManager* historyManager,
                             Core::ConfigManager* configManager, QWidget* parent)
    : QDialog(parent)
    , m_llmClient(llmClient)
    , m_historyManager(historyManager)
    , m_configManager(configManager)
{
    setupUi();
    setWindowTitle(tr("ClipAI - Result"));
    resize(800, 600);

    // Hide save button if auto-save is enabled
    if (m_configManager && m_configManager->historyAutoSave()) {
        m_saveButton->hide();
    }

    // Connect LLM client signals
    if (m_llmClient) {
        connect(m_llmClient, &Core::LLMClient::streaming,
                this, &ResultDialog::onStreaming);
        connect(m_llmClient, &Core::LLMClient::completed,
                this, &ResultDialog::onCompleted);
        connect(m_llmClient, &Core::LLMClient::error,
                this, &ResultDialog::onError);
        connect(m_llmClient, &Core::LLMClient::thinkingStateChanged,
                this, &ResultDialog::onThinkingStateChanged);
        connect(m_llmClient, &Core::LLMClient::bytesReceivedChanged,
                this, &ResultDialog::onBytesReceivedChanged);
    }
}

ResultDialog::~ResultDialog() = default;

void ResultDialog::setupUi()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Header with model info
    QHBoxLayout* headerLayout = new QHBoxLayout();
    m_modelLabel = new QLabel(tr("Model: -"));
    m_modelLabel->setStyleSheet("font-weight: bold;");
    m_tokensLabel = new QLabel(tr("Tokens: 0 / 0"));
    m_trafficLabel = new QLabel(tr("Traffic: 0 B"));
    m_trafficLabel->setStyleSheet("color: gray; font-size: 10px;");
    headerLayout->addWidget(m_modelLabel);
    headerLayout->addStretch();
    headerLayout->addWidget(m_tokensLabel);
    headerLayout->addWidget(m_trafficLabel);
    mainLayout->addLayout(headerLayout);

    // Progress bar
    m_progressBar = new QProgressBar();
    m_progressBar->setRange(0, 0); // Indeterminate progress
    m_progressBar->setVisible(false);
    m_progressBar->setTextVisible(false);
    m_progressBar->setMaximumHeight(3);
    mainLayout->addWidget(m_progressBar);

    // Status label
    m_statusLabel = new QLabel(tr("Ready"));
    m_statusLabel->setWordWrap(true);
    mainLayout->addWidget(m_statusLabel);

    // Splitter for input/output
    QSplitter* splitter = new QSplitter(Qt::Vertical);

    // Input group
    QGroupBox* inputGroup = new QGroupBox(tr("Input"));
    QVBoxLayout* inputLayout = new QVBoxLayout(inputGroup);
    m_inputText = new QTextEdit();
    m_inputText->setReadOnly(true);
    m_inputText->setMaximumHeight(150);
    inputLayout->addWidget(m_inputText);
    splitter->addWidget(inputGroup);

    // Output group
    QGroupBox* outputGroup = new QGroupBox(tr("Output"));
    QVBoxLayout* outputLayout = new QVBoxLayout(outputGroup);
    m_outputText = new QTextEdit();
    m_outputText->setReadOnly(true);
    outputLayout->addWidget(m_outputText);
    splitter->addWidget(outputGroup);

    splitter->setStretchFactor(0, 1);
    splitter->setStretchFactor(1, 3);
    mainLayout->addWidget(splitter, 1);

    // Button row
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_copyButton = new QPushButton(tr("Copy"));
    m_copyButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_copyButton->setEnabled(false);
    connect(m_copyButton, &QPushButton::clicked, this, &ResultDialog::onCopyClicked);

    m_saveButton = new QPushButton(tr("Save to History"));
    m_saveButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_saveButton->setEnabled(false);
    connect(m_saveButton, &QPushButton::clicked, this, &ResultDialog::onSaveClicked);

    m_retryButton = new QPushButton(tr("Retry"));
    m_retryButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_BrowserReload));
    m_retryButton->setEnabled(false);
    connect(m_retryButton, &QPushButton::clicked, this, &ResultDialog::onRetryClicked);

    m_closeButton = new QPushButton(tr("Close"));
    m_closeButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCloseButton));
    connect(m_closeButton, &QPushButton::clicked, this, &ResultDialog::onCloseClicked);

    buttonLayout->addWidget(m_copyButton);
    buttonLayout->addWidget(m_saveButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_retryButton);
    buttonLayout->addWidget(m_closeButton);

    mainLayout->addLayout(buttonLayout);
}

void ResultDialog::setPrompt(const QString& promptId, const QString& promptName)
{
    m_promptId = promptId;
    m_promptName = promptName;

    if (!m_promptName.isEmpty()) {
        setWindowTitle(tr("ClipAI - %1").arg(m_promptName));
    }
}

void ResultDialog::setInput(const QString& input)
{
    m_input = input;
    m_inputText->setPlainText(input);
}

void ResultDialog::setModel(const QString& model)
{
    m_modelLabel->setText(tr("Model: %1").arg(model));
}

void ResultDialog::startRequest()
{
    m_output.clear();
    m_outputText->clear();
    m_isStreaming = true;
    m_isThinking = false;
    m_wasSaved = false;
    m_bytesReceived = 0;
    m_timer.start();

    updateState();

    m_progressBar->setVisible(true);
    m_trafficLabel->setVisible(true);
    m_trafficLabel->setText(tr("Traffic: 0 B"));
    m_statusLabel->setText(tr("Connecting..."));
    m_statusLabel->setStyleSheet("");
    m_copyButton->setEnabled(false);
    m_saveButton->setEnabled(false);
    m_retryButton->setEnabled(false);
}

void ResultDialog::appendResponse(const QString& text)
{
    m_outputText->insertPlainText(text);
    m_outputText->moveCursor(QTextCursor::End);
}

void ResultDialog::onStreaming(const QString& content)
{
    m_output.append(content);
    appendResponse(content);

    // Update token estimate (rough approximation: 4 chars per token)
    int estimatedTokens = m_output.length() / 4;
    m_tokensLabel->setText(tr("Tokens: ~%1").arg(estimatedTokens));
}

void ResultDialog::onCompleted(const Core::LLMResponse& response)
{
    m_isStreaming = false;
    m_isThinking = false;
    m_progressBar->setVisible(false);
    m_trafficLabel->setVisible(false);

    double elapsed = m_timer.elapsed() / 1000.0;

    if (response.isSuccess()) {
        m_statusLabel->setText(tr("Completed in %1 seconds").arg(elapsed, 0, 'f', 2));
        // Model is already set via setModel(), but update if response has different one
        if (!response.model.isEmpty()) {
            m_modelLabel->setText(tr("Model: %1").arg(response.model));
        }
        m_tokensLabel->setText(tr("Tokens: %1 input / %2 output")
                              .arg(response.inputTokens)
                              .arg(response.outputTokens));

        m_copyButton->setEnabled(true);
        // Only enable save button if auto-save is disabled
        if (!m_configManager || !m_configManager->historyAutoSave()) {
            m_saveButton->setEnabled(true);
        }
        m_retryButton->setEnabled(true);

        emit responseReceived(response.content);
    } else if (!response.error.isEmpty()) {
        m_statusLabel->setText(tr("Error: %1").arg(response.error));
        m_statusLabel->setStyleSheet("color: red;");
        m_retryButton->setEnabled(true);
    }

    updateState();
}

void ResultDialog::onError(const QString& error)
{
    m_isStreaming = false;
    m_isThinking = false;
    m_progressBar->setVisible(false);
    m_trafficLabel->setVisible(false);

    m_statusLabel->setText(tr("Error: %1").arg(error));
    m_statusLabel->setStyleSheet("color: red;");
    m_retryButton->setEnabled(true);

    updateState();
}

void ResultDialog::onCopyClicked()
{
    QApplication::clipboard()->setText(m_output);

    m_statusLabel->setText(tr("Copied to clipboard"));
    m_statusLabel->setStyleSheet("color: green;");

    // Reset style after a delay
    QTimer::singleShot(2000, this, [this]() {
        m_statusLabel->setStyleSheet("");
        if (!m_isStreaming) {
            m_statusLabel->setText(tr("Completed"));
        }
    });
}

void ResultDialog::onSaveClicked()
{
    if (m_historyManager && !m_wasSaved) {
        Core::HistoryEntry entry;
        entry.promptId = m_promptId;
        entry.promptName = m_promptName;
        entry.model = m_llmClient ? m_llmClient->model() : QString();
        entry.inputText = m_input;
        entry.outputText = m_output;
        entry.inputTokens = m_llmClient ? m_llmClient->lastInputTokens() : 0;
        entry.outputTokens = m_llmClient ? m_llmClient->lastOutputTokens() : 0;
        entry.durationMs = m_timer.elapsed();
        entry.favorite = false;

        m_historyManager->addEntry(entry);
        m_wasSaved = true;

        m_saveButton->setEnabled(false);
        m_saveButton->setText(tr("Saved"));

        emit saveToHistoryRequested(m_promptId, m_promptName, m_input, m_output);
    }
}

void ResultDialog::onRetryClicked()
{
    m_retryButton->setEnabled(false);
    emit responseReceived(m_output); // Signal to retry
}

void ResultDialog::onCloseClicked()
{
    closeDialog();
}

void ResultDialog::closeDialog()
{
    // Auto-save if enabled, output exists and not already saved
    bool autoSaveEnabled = m_configManager && m_configManager->historyAutoSave();
    if (autoSaveEnabled && !m_output.isEmpty() && !m_wasSaved && m_historyManager) {
        onSaveClicked();
    }

    // Use close() instead of accept() to trigger closeEvent
    close();
}

void ResultDialog::updateState()
{
    if (m_isStreaming) {
        m_outputText->setReadOnly(false);
        m_outputText->setFocus();
    } else {
        m_outputText->setReadOnly(true);
    }
}

void ResultDialog::closeEvent(QCloseEvent* event)
{
    // Prevent re-entry
    if (m_closing) {
        event->ignore();
        return;
    }

    // If streaming is in progress, ask for confirmation
    if (m_isStreaming) {
        m_closing = true;
        auto reply = QMessageBox::question(
            this,
            tr("Close During Generation"),
            tr("A response is still being generated. Close and cancel the request?"),
            QMessageBox::Yes | QMessageBox::No,
            QMessageBox::No
        );

        if (reply == QMessageBox::Yes) {
            // User confirmed - show cancel status
            if (m_statusLabel) {
                m_statusLabel->setText(tr("Cancelling..."));
                m_statusLabel->setStyleSheet("color: orange;");
            }

            // Disconnect signals and cancel
            if (m_llmClient) {
                disconnect(m_llmClient, nullptr, this, nullptr);
                m_llmClient->cancel();
            }
            // Don't accept the event yet - close after cancel is done
            event->ignore();
            // Schedule actual close after returning from closeEvent
            QTimer::singleShot(0, this, &ResultDialog::performClose);
        } else {
            // User cancelled - don't close
            m_closing = false;
            event->ignore();
        }
    } else {
        // Not streaming - auto-save if enabled and allow close
        bool autoSaveEnabled = m_configManager && m_configManager->historyAutoSave();
        if (autoSaveEnabled && !m_output.isEmpty() && !m_wasSaved && m_historyManager) {
            onSaveClicked();
        }
        event->accept();
    }
}

void ResultDialog::performClose()
{
    // Direct accept without going through closeEvent again
    // Auto-save was already done in closeEvent if needed
    accept();
}

void ResultDialog::onThinkingStateChanged(bool isThinking)
{
    m_isThinking = isThinking;

    if (m_isStreaming) {
        if (isThinking) {
            m_statusLabel->setText(tr("Model is thinking..."));
            m_statusLabel->setStyleSheet("color: blue;");
        } else {
            m_statusLabel->setText(tr("Generating response..."));
            m_statusLabel->setStyleSheet("color: black;");
        }
    }
}

void ResultDialog::onBytesReceivedChanged(qint64 bytesReceived)
{
    m_bytesReceived = bytesReceived;
    m_trafficLabel->setText(tr("Traffic: %1").arg(formatBytes(bytesReceived)));
}

QString ResultDialog::formatBytes(qint64 bytes)
{
    if (bytes == 0) {
        return QStringLiteral("0 B");
    }

    const QString units[] = {QStringLiteral("B"), QStringLiteral("KB"),
                             QStringLiteral("MB"), QStringLiteral("GB")};
    int unitIndex = 0;
    double size = bytes;

    while (size >= 1024.0 && unitIndex < 3) {
        size /= 1024.0;
        unitIndex++;
    }

    return QStringLiteral("%1 %2").arg(size, 0, 'f', 2).arg(units[unitIndex]);
}

} // namespace UI
} // namespace ClipAI
