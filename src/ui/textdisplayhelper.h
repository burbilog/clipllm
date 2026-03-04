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

#ifndef CLIPLLM_UI_TEXTDISPLAYHELPER_H
#define CLIPLLM_UI_TEXTDISPLAYHELPER_H

#include <QObject>
#include <QVector>

class QTextEdit;
class QWheelEvent;
class QKeyEvent;
class QTextCursor;

namespace ClipLLM {
namespace UI {

/**
 * Helper class for common text display functionality.
 * Provides font size management, zoom, and ruby text expansion.
 */
class TextDisplayHelper : public QObject
{
    Q_OBJECT

public:
    // Font size limits
    static constexpr int MIN_FONT_SIZE = 6;
    static constexpr int MAX_FONT_SIZE = 30;
    static constexpr int DEFAULT_FONT_SIZE = 10;

    /**
     * Construct a helper for the given text edit.
     * @param textEdit The primary text edit to manage
     * @param settingsGroup QSettings group name for persisting settings
     * @param parent Parent object
     */
    explicit TextDisplayHelper(QTextEdit* textEdit, const QString& settingsGroup,
                               QObject* parent = nullptr);
    ~TextDisplayHelper() override = default;

    /**
     * Add an additional text edit to receive font updates.
     * Useful for dialogs with multiple text areas (e.g., input and output).
     */
    void addSecondaryTextEdit(QTextEdit* textEdit);

    // Font size management
    void applyFontSize();
    void setFontSize(int size);
    int fontSize() const { return m_fontSize; }

    // Zoom controls
    void zoomIn();
    void zoomOut();

    /**
     * Handle wheel event for zoom (Ctrl+wheel).
     * @return true if the event was handled (zoom applied)
     */
    bool handleWheelEvent(QWheelEvent* event);

    /**
     * Handle key event for +/- zoom shortcuts.
     * @return true if the event was handled (zoom applied)
     */
    bool handleKeyEvent(QKeyEvent* event);

    /**
     * Get text with ruby objects expanded to base text (for copy operations).
     * @param cursor The cursor with selection
     * @return Text with ruby objects replaced by their base text
     */
    QString getTextWithExpandedRuby(QTextCursor& cursor) const;

signals:
    void fontSizeChanged(int newSize);

private:
    void saveFontSize();
    void loadFontSize();

    QTextEdit* m_primaryTextEdit = nullptr;
    QVector<QTextEdit*> m_secondaryTextEdits;
    QString m_settingsGroup;
    int m_fontSize = DEFAULT_FONT_SIZE;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_TEXTDISPLAYHELPER_H
