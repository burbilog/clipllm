#ifndef CLIPAI_UI_PROMPTPREVIEWDIALOG_H
#define CLIPAI_UI_PROMPTPREVIEWDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QTextBrowser>
#include <QImage>
#include <QLabel>
#include "models/prompt.h"

namespace ClipAI {
namespace UI {

class PromptPreviewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PromptPreviewDialog(const Models::Prompt& prompt, QWidget* parent = nullptr);
    ~PromptPreviewDialog();

    void setClipboardContent(const QString& content);
    void refreshPreview();

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onImageLinkClicked();

private:
    void setupUi();
    QString buildJsonPreview();
    bool validateContentType();
    QString getUserLanguage() const;

    Models::Prompt m_prompt;
    QString m_clipboardContent;
    QImage m_clipboardImage;

    QTextBrowser* m_requestView = nullptr;
    QLabel* m_warningLabel = nullptr;
};

} // namespace UI
} // namespace ClipAI

#endif
