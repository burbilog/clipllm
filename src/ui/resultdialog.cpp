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
#include <QSettings>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QFileDialog>
#include <QFileInfo>
#include <QDir>
#include <QFile>
#include <QTextStream>

namespace ClipLLM {
namespace UI {

ResultDialog::ResultDialog(Core::LLMClient* llmClient, Core::HistoryManager* historyManager,
                             Core::ConfigManager* configManager, QWidget* parent)
    : QDialog(parent)
    , m_llmClient(llmClient)
    , m_historyManager(historyManager)
    , m_configManager(configManager)
{
    setupUi();
    setWindowTitle(tr("ClipLLM - Result"));
    resize(800, 600);

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("resultDialog").toByteArray());
    settings.endGroup();

    // Restore font size
    loadFontSize();
    applyFontSize();

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

    // Chain indicator
    m_chainIndicator = new QLabel();
    m_chainIndicator->setWordWrap(true);
    m_chainIndicator->setStyleSheet("color: #666; font-style: italic; font-size: 10px;");
    m_chainIndicator->hide();
    mainLayout->addWidget(m_chainIndicator);

    // Markdown toggle button
    m_markdownToggle = new QPushButton(tr("Markdown"));
    m_markdownToggle->setCheckable(true);
    m_markdownToggle->setChecked(m_markdownMode);
    connect(m_markdownToggle, &QPushButton::clicked, this, &ResultDialog::onMarkdownToggleClicked);
    m_markdownToggle->setText(m_markdownMode ? tr("Markdown") : tr("Raw"));

    // Input toggle button
    m_inputToggleBtn = new QPushButton(tr("Show Input"));
    m_inputToggleBtn->setCheckable(true);
    m_inputToggleBtn->setChecked(false);
    connect(m_inputToggleBtn, &QPushButton::clicked, this, &ResultDialog::onInputToggleClicked);

    // Toggle buttons layout
    QHBoxLayout* toggleLayout = new QHBoxLayout();
    toggleLayout->addWidget(m_markdownToggle);
    toggleLayout->addWidget(m_inputToggleBtn);
    mainLayout->addLayout(toggleLayout);

    // Splitter for input/output
    m_splitter = new QSplitter(Qt::Vertical);

    // Input group
    m_inputGroup = new QGroupBox(tr("Input"));
    QVBoxLayout* inputLayout = new QVBoxLayout(m_inputGroup);
    m_inputText = new QTextEdit();
    m_inputText->setReadOnly(true);
    m_inputText->setMaximumHeight(150);
    m_inputText->installEventFilter(this);  // Install event filter for zoom
    inputLayout->addWidget(m_inputText);
    m_splitter->addWidget(m_inputGroup);

    // Output group
    QGroupBox* outputGroup = new QGroupBox(tr("Output"));
    QVBoxLayout* outputLayout = new QVBoxLayout(outputGroup);
    m_outputText = new QTextEdit();
    m_outputText->setReadOnly(true);
    m_outputText->installEventFilter(this);  // Install event filter for zoom
    outputLayout->addWidget(m_outputText);
    m_splitter->addWidget(outputGroup);

    // Set initial sizes - input collapsed (0 height), output takes all space
    m_splitter->setStretchFactor(0, 0);
    m_splitter->setStretchFactor(1, 1);
    m_splitter->setSizes({0, 600});
    mainLayout->addWidget(m_splitter, 1);

    // Button row
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_copyButton = new QPushButton(tr("Copy && close"));
    m_copyButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_copyButton->setEnabled(false);
    connect(m_copyButton, &QPushButton::clicked, this, &ResultDialog::onCopyClicked);

    m_saveButton = new QPushButton(tr("Save to History"));
    m_saveButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_saveButton->setEnabled(false);
    connect(m_saveButton, &QPushButton::clicked, this, &ResultDialog::onSaveClicked);

    m_saveAsButton = new QPushButton(tr("Save as..."));
    m_saveAsButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_saveAsButton->setEnabled(false);
    m_saveAsButton->setToolTip(tr("Save output to a file"));
    connect(m_saveAsButton, &QPushButton::clicked, this, &ResultDialog::onSaveAsClicked);

    m_retryButton = new QPushButton(tr("Retry"));
    m_retryButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_BrowserReload));
    m_retryButton->setEnabled(false);
    connect(m_retryButton, &QPushButton::clicked, this, &ResultDialog::onRetryClicked);

    m_continueButton = new QPushButton(tr("Continue"));
    m_continueButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_MediaSeekForward));
    m_continueButton->setEnabled(false);
    m_continueButton->hide();  // Hidden by default, shown when chain has next step
    connect(m_continueButton, &QPushButton::clicked, this, &ResultDialog::onChainContinueClicked);

    m_closeButton = new QPushButton(tr("Close"));
    m_closeButton->setIcon(QApplication::style()->standardIcon(QStyle::SP_DialogCloseButton));
    connect(m_closeButton, &QPushButton::clicked, this, &ResultDialog::onCloseClicked);

    // Zoom buttons
    m_zoomOutButton = new QPushButton(tr("-"));
    m_zoomOutButton->setToolTip(tr("Zoom out"));
    m_zoomOutButton->setMaximumWidth(40);
    connect(m_zoomOutButton, &QPushButton::clicked, this, &ResultDialog::onZoomOutClicked);

    m_zoomInButton = new QPushButton(tr("+"));
    m_zoomInButton->setToolTip(tr("Zoom in"));
    m_zoomInButton->setMaximumWidth(40);
    connect(m_zoomInButton, &QPushButton::clicked, this, &ResultDialog::onZoomInClicked);

    buttonLayout->addWidget(m_copyButton);
    buttonLayout->addWidget(m_saveButton);
    buttonLayout->addWidget(m_saveAsButton);
    buttonLayout->addStretch();

    // Add zoom buttons
    QHBoxLayout* zoomLayout = new QHBoxLayout();
    zoomLayout->addWidget(m_zoomOutButton);
    zoomLayout->addWidget(m_zoomInButton);
    buttonLayout->addLayout(zoomLayout);

    buttonLayout->addWidget(m_continueButton);
    buttonLayout->addWidget(m_retryButton);
    buttonLayout->addWidget(m_closeButton);

    mainLayout->addLayout(buttonLayout);
}

void ResultDialog::setPrompt(const QString& promptId, const QString& promptName)
{
    m_promptId = promptId;
    m_promptName = promptName;

    if (!m_promptName.isEmpty()) {
        setWindowTitle(tr("ClipLLM - %1").arg(m_promptName));
    }
}

void ResultDialog::setInput(const QString& input)
{
    m_input = input;
    m_inputText->setPlainText(input);
}

void ResultDialog::setProvider(const QString& provider)
{
    m_provider = provider;
    updateModelLabel();
}

void ResultDialog::setModel(const QString& model)
{
    m_model = model;
    updateModelLabel();
}

void ResultDialog::setRetryContext(const QString& providerId, const QString& model,
                                   const QString& systemPrompt, const QString& userPrompt,
                                   const QByteArray& imageData, double temperature)
{
    m_providerId = providerId;
    m_modelForRetry = model;
    m_systemPrompt = systemPrompt;
    m_userPrompt = userPrompt;
    m_imageData = imageData;
    m_temperature = temperature;
}

void ResultDialog::updateModelLabel()
{
    if (m_provider.isEmpty() && m_model.isEmpty()) {
        m_modelLabel->setText(tr("Model: -"));
    } else if (m_provider.isEmpty()) {
        m_modelLabel->setText(tr("Model: %1").arg(m_model));
    } else if (m_model.isEmpty()) {
        m_modelLabel->setText(tr("Model: %1").arg(m_provider));
    } else {
        m_modelLabel->setText(tr("Model: %1 / %2").arg(m_provider, m_model));
    }
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

    // Update markdown toggle button text
    m_markdownToggle->setText(m_markdownMode ? tr("Markdown") : tr("Raw"));

    updateState();

    m_progressBar->setVisible(true);
    m_trafficLabel->setVisible(true);
    m_trafficLabel->setText(tr("Traffic: 0 B"));
    m_statusLabel->setText(tr("Connecting..."));
    m_statusLabel->setStyleSheet("");
    m_copyButton->setEnabled(false);
    m_saveButton->setEnabled(false);
    m_saveAsButton->setEnabled(false);
    m_retryButton->setEnabled(false);
    m_continueButton->setEnabled(false);
    m_continueButton->hide();
}

void ResultDialog::appendResponse(const QString& text)
{
    m_output.append(text);

    if (m_markdownMode) {
        // Set markdown content - QTextDocument will render it
        m_outputText->setMarkdown(m_output);
    } else {
        // Show as plain text
        m_outputText->setPlainText(m_output);
    }

    m_outputText->moveCursor(QTextCursor::End);
}

void ResultDialog::onStreaming(const QString& content)
{
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
            setModel(response.model);
        }
        m_tokensLabel->setText(tr("Tokens: %1 input / %2 output")
                              .arg(response.inputTokens)
                              .arg(response.outputTokens));

        m_copyButton->setEnabled(true);
        // Only enable save button if auto-save is disabled
        if (!m_configManager || !m_configManager->historyAutoSave()) {
            m_saveButton->setEnabled(true);
        }
        m_saveAsButton->setEnabled(true);
        m_retryButton->setEnabled(true);

        // Show continue button if there's a next prompt in the chain (and not auto-continue)
        if (!m_nextPromptId.isEmpty() && !m_autoContinue) {
            m_continueButton->setEnabled(true);
            m_continueButton->show();
        }

        // Auto-continue if enabled and there's a next prompt
        if (m_autoContinue && !m_nextPromptId.isEmpty()) {
            // Use QTimer to allow the UI to update before continuing
            QTimer::singleShot(100, this, [this]() {
                emit chainContinueRequested(m_nextPromptId, m_output);
            });
        }

        emit responseReceived(response.content);
    } else if (!response.error.isEmpty()) {
        QString error = response.error;

        // Check if this is an API-level error
        bool isApiError = error.contains(QLatin1String("HTTP 401")) ||
                          error.contains(QLatin1String("HTTP 403")) ||
                          error.contains(QLatin1String("Unauthorized"), Qt::CaseInsensitive) ||
                          error.contains(QLatin1String("authentication"), Qt::CaseInsensitive) ||
                          error.contains(QLatin1String("API key"), Qt::CaseInsensitive);

        if (isApiError) {
            QMessageBox::critical(this, tr("API Error"),
                                tr("An error occurred while communicating with the API:\n\n%1").arg(error));
        }

        m_statusLabel->setText(tr("Error: %1").arg(error));
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

    // Check if this is an API-level error that should show a dialog
    bool isApiError = error.contains(QLatin1String("HTTP 401")) ||
                      error.contains(QLatin1String("HTTP 403")) ||
                      error.contains(QLatin1String("Unauthorized"), Qt::CaseInsensitive) ||
                      error.contains(QLatin1String("authentication"), Qt::CaseInsensitive) ||
                      error.contains(QLatin1String("API key"), Qt::CaseInsensitive);

    if (isApiError) {
        // Show dialog for API errors
        QMessageBox::critical(this, tr("API Error"),
                            tr("An error occurred while communicating with the API:\n\n%1")
                                .arg(error));

        // Close the result dialog - authentication errors are fatal
        closeDialog();
        return;
    } else {
        // Show in result window for other errors
        m_statusLabel->setText(tr("Error: %1").arg(error));
        m_statusLabel->setStyleSheet("color: red;");
        m_retryButton->setEnabled(true);
    }

    updateState();
}

void ResultDialog::onCopyClicked()
{
    QApplication::clipboard()->setText(m_output);
    closeDialog();
}

void ResultDialog::onSaveClicked()
{
    if (m_historyManager && !m_wasSaved) {
        Core::HistoryEntry entry;
        entry.promptId = m_promptId;
        entry.promptName = m_promptName;
        entry.provider = m_provider;
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

void ResultDialog::onSaveAsClicked()
{
    // Get the last used directory from config, or use home directory
    QString startDir;
    if (m_configManager) {
        startDir = m_configManager->lastSaveDirectory();
    }
    if (startDir.isEmpty()) {
        startDir = QDir::homePath();
    }

    // Generate default filename with timestamp
    QString defaultFileName = QStringLiteral("clipllm-result-%1.txt")
        .arg(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd-HHmmss")));

    // Show file save dialog
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Save Output As"),
        startDir + QLatin1Char('/') + defaultFileName,
        tr("Text Files (*.txt);;All Files (*)")
    );

    // User cancelled
    if (fileName.isEmpty()) {
        return;
    }

    // Save the directory for next time
    if (m_configManager) {
        QFileInfo fileInfo(fileName);
        m_configManager->setLastSaveDirectory(fileInfo.absolutePath());
    }

    // Write the file
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        out.setEncoding(QStringConverter::Utf8);
#else
        out.setCodec("UTF-8");
#endif
        out << m_output;
        file.close();

        // Show success message in status label
        m_statusLabel->setText(tr("Saved to %1").arg(fileName));
        m_statusLabel->setStyleSheet("color: green;");
    } else {
        // Show error dialog
        QMessageBox::warning(
            this,
            tr("Save Failed"),
            tr("Could not write to file:\n%1").arg(fileName)
        );
    }
}

void ResultDialog::onRetryClicked()
{
    m_retryButton->setEnabled(false);
    // Emit signal with all necessary context for retry
    emit retryRequested(m_promptId, m_providerId, m_modelForRetry,
                        m_systemPrompt, m_userPrompt, m_imageData, m_temperature);
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
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("resultDialog", saveGeometry());
    settings.endGroup();

    // Save font size
    saveFontSize();
    settings.sync();

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

void ResultDialog::onMarkdownToggleClicked()
{
    m_markdownMode = m_markdownToggle->isChecked();
    m_markdownToggle->setText(m_markdownMode ? tr("Markdown") : tr("Raw"));

    // Re-render the output
    if (!m_output.isEmpty()) {
        if (m_markdownMode) {
            m_outputText->setMarkdown(m_output);
        } else {
            m_outputText->setPlainText(m_output);
        }
        m_outputText->moveCursor(QTextCursor::End);
    }
}

void ResultDialog::onInputToggleClicked()
{
    m_inputExpanded = m_inputToggleBtn->isChecked();

    if (m_inputExpanded) {
        // Expand input section
        m_inputToggleBtn->setText(tr("Hide Input"));
        m_splitter->setSizes({200, 400});
    } else {
        // Collapse input section
        m_inputToggleBtn->setText(tr("Show Input"));
        m_splitter->setSizes({0, 600});
    }
}

void ResultDialog::onZoomOutClicked()
{
    m_fontSize = std::max(m_fontSize - 1, 6);
    applyFontSize();
    saveFontSize();
}

void ResultDialog::onZoomInClicked()
{
    m_fontSize = std::min(m_fontSize + 1, 30);
    applyFontSize();
    saveFontSize();
}

void ResultDialog::wheelEvent(QWheelEvent* event)
{
    // Check if Ctrl (or Cmd on macOS) key is pressed
    if (event->modifiers() & (Qt::ControlModifier | Qt::MetaModifier)) {
        // Calculate delta
        int delta = event->angleDelta().y();
        if (delta > 0) {
            m_fontSize = std::min(m_fontSize + 1, 30);
        } else {
            m_fontSize = std::max(m_fontSize - 1, 6);
        }
        applyFontSize();
        saveFontSize();
        event->accept();
    } else {
        QDialog::wheelEvent(event);
    }
}

bool ResultDialog::eventFilter(QObject* watched, QEvent* event)
{
    // Handle key events for + and - shortcuts
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        // Plus/Equal key (for zoom in)
        if (keyEvent->key() == Qt::Key_Plus || keyEvent->key() == Qt::Key_Equal) {
            m_fontSize = std::min(m_fontSize + 1, 30);
            applyFontSize();
            saveFontSize();
            keyEvent->accept();
            return true;
        }
        // Minus key (for zoom out)
        if (keyEvent->key() == Qt::Key_Minus) {
            m_fontSize = std::max(m_fontSize - 1, 6);
            applyFontSize();
            saveFontSize();
            keyEvent->accept();
            return true;
        }
    }

    return QDialog::eventFilter(watched, event);
}

void ResultDialog::applyFontSize()
{
    if (m_inputText) {
        QFont font = m_inputText->font();
        font.setPointSize(m_fontSize);
        m_inputText->setFont(font);
    }
    if (m_outputText) {
        QFont font = m_outputText->font();
        font.setPointSize(m_fontSize);
        m_outputText->setFont(font);
    }
}

void ResultDialog::saveFontSize()
{
    QSettings settings;
    settings.beginGroup("ResultDialog");
    settings.setValue("fontSize", m_fontSize);
    settings.endGroup();
    settings.sync();
}

void ResultDialog::loadFontSize()
{
    QSettings settings;
    settings.beginGroup("ResultDialog");
    m_fontSize = settings.value("fontSize", 10).toInt();
    settings.endGroup();
}

void ResultDialog::setChainInfo(const QStringList& chainNames, const QString& nextPromptId, bool autoContinue)
{
    m_chainNames = chainNames;
    m_nextPromptId = nextPromptId;
    m_autoContinue = autoContinue;

    // Update chain indicator
    if (!chainNames.isEmpty()) {
        QString chainText = tr("Chain: %1").arg(chainNames.join(QStringLiteral(" → ")));
        m_chainIndicator->setText(chainText);
        m_chainIndicator->show();
    } else {
        m_chainIndicator->hide();
    }
}

void ResultDialog::onChainContinueClicked()
{
    if (!m_nextPromptId.isEmpty()) {
        emit chainContinueRequested(m_nextPromptId, m_output);
    }
}

} // namespace UI
} // namespace ClipLLM
