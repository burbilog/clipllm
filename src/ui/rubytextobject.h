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

#ifndef CLIPLLM_UI_RUBYTEXTOBJECT_H
#define CLIPLLM_UI_RUBYTEXTOBJECT_H

#include <QObject>
#include <QTextObjectInterface>
#include <QTextFormat>
#include <QSizeF>
#include <QPointF>
#include <QPainter>

namespace ClipLLM {
namespace UI {

/**
 * Custom text object for rendering ruby (furigana) annotations.
 * Implements QTextObjectInterface to draw furigana above kanji.
 */
class RubyTextObject : public QObject, public QTextObjectInterface
{
    Q_OBJECT
    Q_INTERFACES(QTextObjectInterface)

public:
    // Object type for QTextFormat
    static const int RubyObjectType = QTextFormat::UserObject + 1;

    // Property IDs for QTextCharFormat
    enum {
        BaseText = 1,   // The kanji text
        RubyText = 2    // The furigana annotation
    };

    explicit RubyTextObject(QObject* parent = nullptr);

    // QTextObjectInterface implementation
    QSizeF intrinsicSize(QTextDocument* doc, int posInDocument,
                         const QTextFormat& format) override;
    void drawObject(QPainter* painter, const QRectF& rect,
                    QTextDocument* doc, int posInDocument,
                    const QTextFormat& format) override;

    /**
     * Register this object type with a text document's layout.
     * Must be called before using ruby objects in the document.
     */
    static void registerWithDocument(QTextDocument* doc);

    /**
     * Create a QTextCharFormat for a ruby annotation.
     * @param baseText The kanji/base text
     * @param rubyText The furigana annotation
     * @return A format that can be inserted into a QTextDocument
     */
    static QTextCharFormat createFormat(const QString& baseText, const QString& rubyText);

    /**
     * Process text containing <ruby> tags and convert to formatted text.
     * @param cursor The text cursor to insert into
     * @param text The text containing ruby tags
     */
    static void insertRubyText(QTextCursor& cursor, const QString& text);
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_RUBYTEXTOBJECT_H
