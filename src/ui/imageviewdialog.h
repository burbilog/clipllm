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

#ifndef CLIPLLM_UI_IMAGEVIEWDIALOG_H
#define CLIPLLM_UI_IMAGEVIEWDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QLabel>

namespace ClipLLM {
namespace UI {

class ImageViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageViewDialog(const QImage& image, QWidget* parent = nullptr);
    ~ImageViewDialog();

protected:
    void closeEvent(QCloseEvent* event) override;

private:
    void setupUi();

    QImage m_image;
    QLabel* m_imageLabel = nullptr;
};

} // namespace UI
} // namespace ClipLLM

#endif
