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

#include "rubytextobject.h"
#include <QTextDocument>
#include <QTextCursor>
#include <QAbstractTextDocumentLayout>
#include <QRegularExpression>
#include <QFontMetrics>

namespace ClipLLM {
namespace UI {

RubyTextObject::RubyTextObject(QObject* parent)
    : QObject(parent)
{
}

void RubyTextObject::registerWithDocument(QTextDocument* doc)
{
    QAbstractTextDocumentLayout* layout = doc->documentLayout();
    if (layout) {
        layout->registerHandler(RubyObjectType, new RubyTextObject(doc));
    }
}

QTextCharFormat RubyTextObject::createFormat(const QString& baseText, const QString& rubyText)
{
    QTextCharFormat format;
    format.setObjectType(RubyObjectType);
    format.setProperty(BaseText, baseText);
    format.setProperty(RubyText, rubyText);
    format.setVerticalAlignment(QTextCharFormat::AlignBaseline);
    return format;
}

QSizeF RubyTextObject::intrinsicSize(QTextDocument* doc, int posInDocument,
                                      const QTextFormat& format)
{
    Q_UNUSED(posInDocument)

    QString baseText = format.property(BaseText).toString();
    QString rubyText = format.property(RubyText).toString();

    QFont baseFont = doc->defaultFont();
    QFont rubyFont = baseFont;
    rubyFont.setPointSizeF(baseFont.pointSizeF() * 0.45);  // 45% size for furigana

    QFontMetricsF baseFm(baseFont);
    QFontMetricsF rubyFm(rubyFont);

    qreal baseWidth = baseFm.horizontalAdvance(baseText);
    qreal rubyWidth = rubyFm.horizontalAdvance(rubyText);

    // Use the wider of the two
    qreal width = qMax(baseWidth, rubyWidth);

    // Height should be just the base text height to keep it on baseline
    // Ruby will be drawn above
    qreal baseHeight = baseFm.height();

    return QSizeF(width, baseHeight);
}

void RubyTextObject::drawObject(QPainter* painter, const QRectF& rect,
                                 QTextDocument* doc, int posInDocument,
                                 const QTextFormat& format)
{
    Q_UNUSED(doc)
    Q_UNUSED(posInDocument)

    QString baseText = format.property(BaseText).toString();
    QString rubyText = format.property(RubyText).toString();

    QFont baseFont = painter->font();
    QFont rubyFont = baseFont;
    rubyFont.setPointSizeF(baseFont.pointSizeF() * 0.45);

    QFontMetricsF baseFm(baseFont);
    QFontMetricsF rubyFm(rubyFont);

    qreal baseWidth = baseFm.horizontalAdvance(baseText);
    qreal rubyWidth = rubyFm.horizontalAdvance(rubyText);
    qreal maxWidth = qMax(baseWidth, rubyWidth);

    // Draw ruby text (furigana) above the base text
    painter->setFont(rubyFont);
    qreal rubyX = rect.x() + (maxWidth - rubyWidth) / 2.0;
    qreal rubyY = rect.y() - rubyFm.descent();  // Just above the rect
    painter->drawText(QPointF(rubyX, rubyY), rubyText);

    // Draw base text (kanji) at normal baseline position
    painter->setFont(baseFont);
    qreal baseX = rect.x() + (maxWidth - baseWidth) / 2.0;
    qreal baseY = rect.y() + baseFm.ascent();
    painter->drawText(QPointF(baseX, baseY), baseText);
}

void RubyTextObject::insertRubyText(QTextCursor& cursor, const QString& text)
{
    QString result = text;

    // Pattern to match <ruby>base<rt>annotation</rt></ruby>
    QRegularExpression rubyPattern(
        QStringLiteral("<ruby>([^<]*)<rt>([^<]*)</rt></ruby>"),
        QRegularExpression::CaseInsensitiveOption
    );

    int offset = 0;
    QRegularExpressionMatchIterator it = rubyPattern.globalMatch(result);

    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();

        // Insert any text before this ruby tag
        int startPos = match.capturedStart();
        QString beforeText = result.mid(offset, startPos - offset);
        if (!beforeText.isEmpty()) {
            cursor.insertText(beforeText);
        }

        // Insert the ruby object
        QString baseText = match.captured(1);
        QString rubyText = match.captured(2);

        QTextCharFormat rubyFormat = createFormat(baseText, rubyText);
        cursor.insertText(QString(QChar::ObjectReplacementCharacter), rubyFormat);

        offset = match.capturedEnd();
    }

    // Insert any remaining text after the last ruby tag
    if (offset < result.length()) {
        QString remainingText = result.mid(offset);
        cursor.insertText(remainingText);
    }
}

} // namespace UI
} // namespace ClipLLM
