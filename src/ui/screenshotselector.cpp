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

#include "screenshotselector.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QApplication>
#include <QScreen>
#include <QGuiApplication>
#include <QTimer>

#ifdef Q_OS_LINUX
#include <xcb/xcb.h>
#endif

namespace ClipLLM {
namespace UI {

ScreenshotSelector::ScreenshotSelector(const QImage& screenshot, QWidget* parent)
    : QWidget(parent)
    , m_screenshot(screenshot)
    , m_hintText(tr("Select an area to capture\nEnter = whole screen\nEscape = cancel\nRight-click = reset/cancel"))
{
    // Window setup for fullscreen overlay
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::Tool);
    setAttribute(Qt::WA_TranslucentBackground);
    setAttribute(Qt::WA_DeleteOnClose);
    setCursor(Qt::CrossCursor);

    // Set fullscreen geometry covering all screens (virtual desktop)
    QRect virtualGeometry;
    for (QScreen* screen : QGuiApplication::screens()) {
        virtualGeometry = virtualGeometry.united(screen->geometry());
    }
    setGeometry(virtualGeometry);

    // Grab keyboard using Qt
    grabKeyboard();
    setFocus();
}

ScreenshotSelector::~ScreenshotSelector()
{
    releaseKeyboard();
}

#ifdef Q_OS_LINUX
bool ScreenshotSelector::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
{
    Q_UNUSED(result)

    if (eventType == "xcb_generic_event_t") {
        xcb_generic_event_t* event = static_cast<xcb_generic_event_t*>(message);
        uint8_t responseType = event->response_type & ~0x80;

        // Intercept all key events and eat them
        if (responseType == XCB_KEY_PRESS || responseType == XCB_KEY_RELEASE) {
            xcb_key_press_event_t* keyEvent = reinterpret_cast<xcb_key_press_event_t*>(event);

            // Handle Escape and Enter keys
            if (responseType == XCB_KEY_PRESS) {
                // Get keysym - we need to check keycode
                // Escape is typically keycode 9, Enter is typically keycode 36
                // But we'll handle this in keyPressEvent instead
                // Just eat all key events here
            }

            // Return true to eat the event
            return true;
        }
    }

    return QWidget::nativeEvent(eventType, message, result);
}
#endif

void ScreenshotSelector::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event)

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Draw the screenshot as background
    QPixmap screenshotPixmap = QPixmap::fromImage(m_screenshot);

    // Calculate offset for multi-monitor setup
    QRect virtualGeometry;
    for (QScreen* screen : QGuiApplication::screens()) {
        virtualGeometry = virtualGeometry.united(screen->geometry());
    }
    QPoint offset = virtualGeometry.topLeft();

    painter.drawPixmap(-offset, screenshotPixmap);

    // Draw semi-transparent dark overlay
    QColor overlayColor(0, 0, 0, 120);
    painter.fillRect(rect(), overlayColor);

    // If there's a selection, clear the overlay in that area and draw border
    if (m_isDragging && !m_selectedRect.isNull()) {
        // Clear the overlay in the selected area (show original screenshot)
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.fillRect(m_selectedRect, Qt::transparent);
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);

        // Draw the screenshot content in the selected area
        QRect sourceRect = m_selectedRect.translated(offset);
        painter.drawPixmap(m_selectedRect.topLeft(), screenshotPixmap, sourceRect);

        // Draw red selection border
        QPen pen(QColor(255, 0, 0), 2);
        painter.setPen(pen);
        painter.drawRect(m_selectedRect);

        // Draw size label
        QString sizeText = QStringLiteral("%1 x %2").arg(m_selectedRect.width()).arg(m_selectedRect.height());
        QFont font = painter.font();
        font.setBold(true);
        painter.setFont(font);
        QFontMetrics fm(font);

        // Position size text at top-left corner of selection
        QPoint textPos = m_selectedRect.topLeft() + QPoint(5, fm.height());
        if (textPos.y() < fm.height() + 5) {
            textPos.setY(m_selectedRect.top() + fm.height() + 5);
        }

        // Draw text background
        QRect textRect = fm.boundingRect(sizeText);
        textRect.moveTopLeft(textPos);
        textRect.adjust(-4, -2, 4, 2);
        painter.fillRect(textRect, QColor(0, 0, 0, 180));

        // Draw text
        painter.setPen(Qt::white);
        painter.drawText(textPos, sizeText);
    }

    // Draw hint text in center
    if (!m_isDragging) {
        QFont font = painter.font();
        font.setPointSize(14);
        font.setBold(true);
        painter.setFont(font);
        QFontMetrics fm(font);

        QRect screenRect = QGuiApplication::primaryScreen()->geometry();
        QPoint center = screenRect.center();
        center = mapFromGlobal(center);

        QStringList lines = m_hintText.split('\n');
        int lineHeight = fm.height();
        int totalHeight = lines.size() * lineHeight;
        int startY = center.y() - totalHeight / 2;

        for (int i = 0; i < lines.size(); ++i) {
            QString line = lines[i];
            int textWidth = fm.horizontalAdvance(line);
            int x = center.x() - textWidth / 2;
            int y = startY + (i + 1) * lineHeight;

            // Draw background for hint
            QRect bgRect = fm.boundingRect(line);
            bgRect.moveCenter(QPoint(center.x(), y - lineHeight / 4));
            bgRect.adjust(-10, -5, 10, 5);
            painter.fillRect(bgRect, QColor(0, 0, 0, 200));

            // Draw text
            painter.setPen(Qt::white);
            painter.drawText(x, y, line);
        }
    }
}

void ScreenshotSelector::keyPressEvent(QKeyEvent* event)
{
    // Eat ALL key events to prevent them from reaching other apps
    event->accept();

    switch (event->key()) {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        // Accept whole screen
        emit wholeScreenRequested();
        // Hide immediately, then delay close
        hide();
        QTimer::singleShot(100, this, &QWidget::close);
        break;
    case Qt::Key_Escape:
        // Cancel
        emit cancelled();
        // Hide immediately, then delay close
        hide();
        QTimer::singleShot(100, this, &QWidget::close);
        break;
    default:
        break;
    }
}

void ScreenshotSelector::keyReleaseEvent(QKeyEvent* event)
{
    // Also eat all key release events
    event->accept();
}

void ScreenshotSelector::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::RightButton) {
        if (m_isDragging) {
            // User started dragging but changed mind - reset selection
            m_selectedRect = QRect();
            m_isDragging = false;
            m_dragStart = QPoint();
            update();
        } else {
            // No active selection - close window
            emit cancelled();
            close();
        }
        return;
    }

    if (event->button() == Qt::LeftButton) {
        m_dragStart = event->pos();
        m_isDragging = true;
        m_selectedRect = QRect();
        update();
    }
}

void ScreenshotSelector::mouseMoveEvent(QMouseEvent* event)
{
    if (!m_isDragging) {
        return;
    }

    // Calculate selection rectangle
    QPoint currentPos = event->pos();
    int x = qMin(m_dragStart.x(), currentPos.x());
    int y = qMin(m_dragStart.y(), currentPos.y());
    int width = qAbs(currentPos.x() - m_dragStart.x());
    int height = qAbs(currentPos.y() - m_dragStart.y());

    m_selectedRect = QRect(x, y, width, height);
    update();
}

void ScreenshotSelector::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() != Qt::LeftButton || !m_isDragging) {
        return;
    }

    m_isDragging = false;

    // If selection is too small (just a click), treat as cancel
    if (m_selectedRect.width() < 5 || m_selectedRect.height() < 5) {
        m_selectedRect = QRect();
        update();
        return;
    }

    // Emit the selected area
    emit areaSelected(m_selectedRect);
    close();
}

} // namespace UI
} // namespace ClipLLM
