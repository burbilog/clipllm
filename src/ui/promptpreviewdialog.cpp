#include "promptpreviewdialog.h"
#include "imageviewdialog.h"
#include "core/llmclient.h"
#include "core/app.h"
#include "core/configmanager.h"
#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QGroupBox>
#include <QJsonDocument>
#include <QBuffer>
#include <QImage>
#include <QFontDatabase>
#include <QTextDocument>
#include <QSettings>

namespace ClipAI {
namespace UI {

PromptPreviewDialog::PromptPreviewDialog(const Models::Prompt& prompt, QWidget* parent)
    : QDialog(parent)
    , m_prompt(prompt)
{
    setupUi();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("promptPreviewDialog").toByteArray());
    settings.endGroup();

    refreshPreview();
}

PromptPreviewDialog::~PromptPreviewDialog() = default;

void PromptPreviewDialog::setClipboardContent(const QString& content)
{
    m_clipboardContent = content;
    refreshPreview();
}

bool PromptPreviewDialog::validateContentType()
{
    bool hasImage = !m_clipboardImage.isNull();
    bool hasText = !m_clipboardContent.trimmed().isEmpty();

    bool valid = true;
    QString message;

    switch (m_prompt.contentType()) {
        case Models::ContentType::Text:
            if (hasImage) {
                valid = false;
                message = tr("⚠ This prompt is configured for Text content only, but there is an image in the clipboard. "
                            "The image will be ignored.");
            }
            break;

        case Models::ContentType::Image:
            if (!hasImage) {
                valid = false;
                if (hasText) {
                    message = tr("⚠ This prompt is configured for Image content only, but there is text in the clipboard. "
                                "Only the image will be sent to the model.");
                } else {
                    message = tr("⚠ This prompt is configured for Image content only, but the clipboard is empty or doesn't contain an image.");
                }
            }
            break;

        case Models::ContentType::Any:
            // Always valid
            break;
    }

    if (message.isEmpty()) {
        m_warningLabel->hide();
    } else {
        m_warningLabel->setText(message);
        m_warningLabel->show();
    }

    return valid;
}

void PromptPreviewDialog::refreshPreview()
{
    // Get clipboard content if not set
    if (m_clipboardContent.isEmpty()) {
        QClipboard* clipboard = QApplication::clipboard();
        m_clipboardContent = clipboard->text();
    }

    // Get image from clipboard
    m_clipboardImage = QImage();
    QClipboard* clipboard = QApplication::clipboard();
    if (clipboard->mimeData()->hasImage()) {
        m_clipboardImage = clipboard->image();
    }

    // Validate content type
    validateContentType();

    QString preview = buildJsonPreview();

    // Set HTML content
    m_requestView->setHtml(preview);
}

QString PromptPreviewDialog::buildJsonPreview()
{
    // Build the request exactly as LLMClient::sendPrompt does
    Core::LLMRequest request;

    // Model would be set from config, but for preview we show a placeholder
    request.model = QStringLiteral("<from_settings>");

    // Temperature: -1 means use config default
    request.temperature = m_prompt.overrideTemperature() ? m_prompt.temperature() : -1.0;
    request.maxTokens = m_prompt.maxTokens();
    request.stream = true;

    // System message
    if (!m_prompt.systemPrompt().isEmpty()) {
        Core::LLMMessage sysMsg;
        sysMsg.role = QStringLiteral("system");
        sysMsg.content = m_prompt.formatSystemPrompt(m_clipboardContent, getUserLanguage());
        request.messages.append(sysMsg);
    }

    // User message
    Core::LLMMessage userMsg;
    userMsg.role = QStringLiteral("user");
    userMsg.content = m_prompt.formatUserPrompt(m_clipboardContent, getUserLanguage());

    // Check for image in clipboard
    if (!m_clipboardImage.isNull()) {
        QByteArray byteArray;
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        m_clipboardImage.save(&buffer, "PNG");
        QString base64Image = QString::fromLatin1(byteArray.toBase64());
        userMsg.images.append(QJsonValue(base64Image));
    }

    request.messages.append(userMsg);

    // Convert to JSON
    QJsonObject json = request.toJson();
    QJsonDocument doc(json);

    // Convert to formatted string, but replace image data with link
    QString jsonString = QString::fromUtf8(doc.toJson(QJsonDocument::Indented));

    // Replace the base64 image data with a clickable link
    // The pattern is: "url": "data:image/png;base64,<very_long_string>"
    if (!m_clipboardImage.isNull()) {
        // Find and replace the image URL with a link
        QRegularExpression re(R"("url":\s*"data:image/[^;]+;base64,[^"]*")");
        QString imageSize = tr("%1x%2").arg(m_clipboardImage.width()).arg(m_clipboardImage.height());
        QString replacement = QStringLiteral("\"url\": \"<a href=\"clipai://view-image\">[Clipboard image: %1 pixels - click to view]</a>\"").arg(imageSize);
        jsonString.replace(re, replacement);
    }

    // Escape for HTML
    jsonString = jsonString.toHtmlEscaped();

    // Wrap in <pre> for formatting, but convert our link back to HTML
    // The link was escaped, so we need to unescape it
    jsonString.replace(QStringLiteral("&lt;a href=&quot;clipai://view-image&quot;&gt;"),
                       QStringLiteral("<a href=\"clipai://view-image\">"));
    jsonString.replace(QStringLiteral("&lt;/a&gt;"), QStringLiteral("</a>"));

    return QStringLiteral("<pre style=\"font-family: monospace;\">") + jsonString + QStringLiteral("</pre>");
}

void PromptPreviewDialog::onImageLinkClicked()
{
    if (!m_clipboardImage.isNull()) {
        ImageViewDialog* dialog = new ImageViewDialog(m_clipboardImage, this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->exec();
        // Restore the preview content after dialog closes
        m_requestView->setHtml(buildJsonPreview());
    }
}

QString PromptPreviewDialog::getUserLanguage() const
{
    App* app = static_cast<App*>(QApplication::instance());
    if (app && app->configManager()) {
        return app->configManager()->language();
    }
    return QString();
}

void PromptPreviewDialog::setupUi()
{
    resize(800, 700);
    setWindowTitle(tr("Prompt Preview"));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Warning label (hidden by default)
    m_warningLabel = new QLabel();
    m_warningLabel->setWordWrap(true);
    m_warningLabel->setStyleSheet("color: #d4a017; background-color: #2d2d2d; padding: 10px; border-radius: 4px; font-size: 12px;");
    m_warningLabel->hide();
    mainLayout->addWidget(m_warningLabel);

    // Request JSON section
    QGroupBox* requestGroup = new QGroupBox(tr("Request that will be sent to the API"));
    QVBoxLayout* requestLayout = new QVBoxLayout(requestGroup);

    m_requestView = new QTextBrowser();
    m_requestView->setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    m_requestView->setOpenExternalLinks(false);
    connect(m_requestView, &QTextBrowser::anchorClicked, this, &PromptPreviewDialog::onImageLinkClicked);
    requestLayout->addWidget(m_requestView);

    mainLayout->addWidget(requestGroup);

    // Info label
    QLabel* infoLabel = new QLabel(
        tr("This is the exact JSON that will be sent to the LLM API. "
           "Clipboard content is substituted for {clipboard} placeholder. "
           "Click the image link to view the full image.")
    );
    infoLabel->setWordWrap(true);
    infoLabel->setStyleSheet("color: gray; font-size: 11px; padding: 5px;");
    mainLayout->addWidget(infoLabel);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    QPushButton* refreshButton = new QPushButton(tr("Refresh"));
    connect(refreshButton, &QPushButton::clicked, this, &PromptPreviewDialog::refreshPreview);
    buttonLayout->addWidget(refreshButton);

    QPushButton* closeButton = new QPushButton(tr("Close"));
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    buttonLayout->addWidget(closeButton);

    mainLayout->addLayout(buttonLayout);
}

void PromptPreviewDialog::closeEvent(QCloseEvent* event)
{
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("promptPreviewDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

} // namespace UI
} // namespace ClipAI
