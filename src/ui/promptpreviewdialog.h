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
// along with this program. If not, see <https://www.gnu.org/licenses/>.

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
