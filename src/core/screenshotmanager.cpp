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

#include "screenshotmanager.h"
#include <QGuiApplication>
#include <QScreen>
#include <QPainter>
#include "qhotkey.h"

namespace ClipLLM {
namespace Core {

ScreenshotManager::ScreenshotManager(QObject* parent)
    : QObject(parent)
{
}

ScreenshotManager::~ScreenshotManager() = default;

QImage ScreenshotManager::captureScreen() const
{
    // Get all screens
    QList<QScreen*> screens = QGuiApplication::screens();
    if (screens.isEmpty()) {
        return QImage();
    }

    // Calculate bounding rect of virtual desktop (all monitors combined)
    QRect virtualGeometry;
    for (QScreen* screen : screens) {
        virtualGeometry = virtualGeometry.united(screen->geometry());
    }

    // Create combined image at virtual desktop size
    QImage combined(virtualGeometry.size(), QImage::Format_RGB32);
    combined.fill(Qt::black);

    QPainter painter(&combined);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    // Capture and draw each screen
    for (QScreen* screen : screens) {
        // Grab the screen content
        QPixmap pixmap = screen->grabWindow(0);
        QRect screenGeometry = screen->geometry();

        // Calculate offset relative to virtual desktop origin
        QPoint offset = screenGeometry.topLeft() - virtualGeometry.topLeft();
        painter.drawPixmap(offset, pixmap);
    }

    painter.end();
    return combined;
}

bool ScreenshotManager::isPlatformSupported()
{
    // Screenshot hotkeys require the same platform support as global hotkeys
    return QHotkey::isPlatformSupported();
}

} // namespace Core
} // namespace ClipLLM
