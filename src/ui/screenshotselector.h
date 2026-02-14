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

#ifndef CLIPLLM_UI_SCREENSHOTSELECTOR_H
#define CLIPLLM_UI_SCREENSHOTSELECTOR_H

#include <QWidget>
#include <QImage>
#include <QRect>
#include <QPoint>

namespace ClipLLM {
namespace UI {

class ScreenshotSelector : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenshotSelector(const QImage& screenshot, QWidget* parent = nullptr);
    ~ScreenshotSelector();

    QRect selectedRect() const { return m_selectedRect; }
    QImage screenshot() const { return m_screenshot; }

signals:
    void areaSelected(const QRect& rect);
    void wholeScreenRequested();
    void cancelled();

protected:
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
#ifdef Q_OS_LINUX
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
#endif

private:
    QImage m_screenshot;
    QRect m_selectedRect;
    QPoint m_dragStart;
    bool m_isDragging = false;
    QString m_hintText;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_SCREENSHOTSELECTOR_H
