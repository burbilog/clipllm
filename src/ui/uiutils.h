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

#ifndef CLIPLLM_UI_UIUTILS_H
#define CLIPLLM_UI_UIUTILS_H

#include <QIcon>
#include <QStyle>
#include <QApplication>
#include <QSettings>
#include <QWidget>
#include <QSplitter>
#include <QFileDialog>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QTextStream>
#include <QDateTime>
#include <QMessageBox>
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
#include <QStringConverter>
#endif

namespace ClipLLM {
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

/**
 * Save widget geometry to QSettings.
 * @param widget Widget to save geometry for
 * @param key Settings key (e.g., "resultDialog")
 */
inline void saveWindowGeometry(QWidget* widget, const QString& key)
{
    if (!widget) return;
    QSettings settings;
    settings.beginGroup(QStringLiteral("WindowGeometry"));
    settings.setValue(key, widget->saveGeometry());
    settings.endGroup();
    settings.sync();
}

/**
 * Restore widget geometry from QSettings.
 * @param widget Widget to restore geometry for
 * @param key Settings key (e.g., "resultDialog")
 */
inline void restoreWindowGeometry(QWidget* widget, const QString& key)
{
    if (!widget) return;
    QSettings settings;
    settings.beginGroup(QStringLiteral("WindowGeometry"));
    widget->restoreGeometry(settings.value(key).toByteArray());
    settings.endGroup();
}

/**
 * Save splitter state to QSettings.
 * @param splitter Splitter to save state for
 * @param key Settings key (e.g., "historyDialogSplitter")
 */
inline void saveSplitterState(QSplitter* splitter, const QString& key)
{
    if (!splitter) return;
    QSettings settings;
    settings.beginGroup(QStringLiteral("WindowGeometry"));
    settings.setValue(key, splitter->saveState());
    settings.endGroup();
    settings.sync();
}

/**
 * Restore splitter state from QSettings.
 * @param splitter Splitter to restore state for
 * @param key Settings key (e.g., "historyDialogSplitter")
 */
inline void restoreSplitterState(QSplitter* splitter, const QString& key)
{
    if (!splitter) return;
    QSettings settings;
    settings.beginGroup(QStringLiteral("WindowGeometry"));
    splitter->restoreState(settings.value(key).toByteArray());
    settings.endGroup();
}

/**
 * Save text content to a file with a file dialog.
 * Uses QSettings to persist the last used directory.
 *
 * @param parent Parent widget for the dialog
 * @param content Text content to save
 * @param defaultFileName Default filename suggestion (optional, will generate timestamp-based name if empty)
 * @return Saved file path, or empty string if cancelled/failed
 */
inline QString saveTextToFile(QWidget* parent, const QString& content, const QString& defaultFileName = QString())
{
    // Get the last used directory from settings
    QSettings settings;
    settings.beginGroup(QStringLiteral("FileDialogs"));
    QString startDir = settings.value(QStringLiteral("lastSaveDirectory")).toString();
    settings.endGroup();

    if (startDir.isEmpty()) {
        startDir = QDir::homePath();
    }

    // Generate default filename if not provided
    QString fileName = defaultFileName;
    if (fileName.isEmpty()) {
        fileName = QStringLiteral("clipllm-result-%1.txt")
            .arg(QDateTime::currentDateTime().toString(QStringLiteral("yyyy-MM-dd-HHmmss")));
    }

    // Show file save dialog
    QString selectedPath = QFileDialog::getSaveFileName(
        parent,
        QObject::tr("Save As"),
        startDir + QLatin1Char('/') + fileName,
        QObject::tr("Text Files (*.txt);;All Files (*)")
    );

    // User cancelled
    if (selectedPath.isEmpty()) {
        return QString();
    }

    // Save the directory for next time
    QFileInfo fileInfo(selectedPath);
    settings.beginGroup(QStringLiteral("FileDialogs"));
    settings.setValue(QStringLiteral("lastSaveDirectory"), fileInfo.absolutePath());
    settings.endGroup();
    settings.sync();

    // Write the file
    QFile file(selectedPath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
#if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
        out.setEncoding(QStringConverter::Utf8);
#else
        out.setCodec("UTF-8");
#endif
        out << content;
        out.flush();
        file.close();
        return selectedPath;
    } else {
        QMessageBox::warning(
            parent,
            QObject::tr("Save Failed"),
            QObject::tr("Could not write to file:\n%1").arg(selectedPath)
        );
        return QString();
    }
}

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_UIUTILS_H
