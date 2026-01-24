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

#ifndef CLIPAI_UI_UIUTILS_H
#define CLIPAI_UI_UIUTILS_H

#include <QIcon>
#include <QStyle>
#include <QApplication>

namespace ClipAI {
namespace UI {

/**
 * Helper function to get an icon from theme with fallback to standard icons.
 * On Linux/macOS, uses icon theme (e.g., Freedesktop icon theme).
 * On Windows (or if theme icon not found), falls back to QStyle standard icons.
 *
 * @param themeName Icon name from theme (e.g., "configure", "document-open-recent")
 * @param standardPixmap Fallback standard pixmap (e.g., QStyle::SP_FileIcon)
 * @return Icon from theme or standard icon as fallback
 */
inline QIcon iconFromTheme(const QString& themeName, QStyle::StandardPixmap standardPixmap)
{
    QIcon icon = QIcon::fromTheme(themeName);
    if (icon.isNull()) {
        icon = QApplication::style()->standardIcon(standardPixmap);
    }
    return icon;
}

/**
 * Convenience overloads for common icons.
 */
inline QIcon iconSettings() {
    static QIcon icon = iconFromTheme(QStringLiteral("configure"), QStyle::SP_FileDialogDetailedView);
    return icon;
}

inline QIcon iconHistory() {
    static QIcon icon = iconFromTheme(QStringLiteral("document-open-recent"), QStyle::SP_FileIcon);
    return icon;
}

inline QIcon iconAbout() {
    static QIcon icon = iconFromTheme(QStringLiteral("help-about"), QStyle::SP_MessageBoxInformation);
    return icon;
}

inline QIcon iconQuit() {
    static QIcon icon = iconFromTheme(QStringLiteral("application-exit"), QStyle::SP_DialogCancelButton);
    return icon;
}

inline QIcon iconDocumentNew() {
    static QIcon icon = iconFromTheme(QStringLiteral("document-new"), QStyle::SP_FileIcon);
    return icon;
}

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_UIUTILS_H
