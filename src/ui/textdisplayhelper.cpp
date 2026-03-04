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

#include "textdisplayhelper.h"
#include "rubytextobject.h"
#include <QTextEdit>
#include <QSettings>
#include <QWheelEvent>
#include <QKeyEvent>
#include <QTextDocument>
#include <QTextCursor>
#include <algorithm>

namespace ClipLLM {
namespace UI {

TextDisplayHelper::TextDisplayHelper(QTextEdit* textEdit, const QString& settingsGroup,
                                     QObject* parent)
    : QObject(parent)
    , m_primaryTextEdit(textEdit)
    , m_settingsGroup(settingsGroup)
{
    loadFontSize();
}

void TextDisplayHelper::addSecondaryTextEdit(QTextEdit* textEdit)
{
    if (textEdit && !m_secondaryTextEdits.contains(textEdit)) {
        m_secondaryTextEdits.append(textEdit);
    }
}

void TextDisplayHelper::applyFontSize()
{
    if (m_primaryTextEdit) {
        QFont font = m_primaryTextEdit->font();
        font.setPointSize(m_fontSize);
        m_primaryTextEdit->setFont(font);
    }

    for (auto* textEdit : m_secondaryTextEdits) {
        if (textEdit) {
            QFont font = textEdit->font();
            font.setPointSize(m_fontSize);
            textEdit->setFont(font);
        }
    }
}

void TextDisplayHelper::setFontSize(int size)
{
    m_fontSize = qBound(MIN_FONT_SIZE, size, MAX_FONT_SIZE);
    applyFontSize();
    saveFontSize();
    emit fontSizeChanged(m_fontSize);
}

void TextDisplayHelper::zoomIn()
{
    setFontSize(m_fontSize + 1);
}

void TextDisplayHelper::zoomOut()
{
    setFontSize(m_fontSize - 1);
}

bool TextDisplayHelper::handleWheelEvent(QWheelEvent* event)
{
    // Check if Ctrl (or Cmd on macOS) key is pressed
    if (event->modifiers() & (Qt::ControlModifier | Qt::MetaModifier)) {
        int delta = event->angleDelta().y();
        if (delta > 0) {
            zoomIn();
        } else {
            zoomOut();
        }
        event->accept();
        return true;
    }
    return false;
}

bool TextDisplayHelper::handleKeyEvent(QKeyEvent* event)
{
    // Plus/Equal key (for zoom in)
    if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Equal) {
        zoomIn();
        event->accept();
        return true;
    }

    // Minus key (for zoom out)
    if (event->key() == Qt::Key_Minus) {
        zoomOut();
        event->accept();
        return true;
    }

    return false;
}

QString TextDisplayHelper::getTextWithExpandedRuby(QTextCursor& cursor) const
{
    if (!m_primaryTextEdit) {
        return QString();
    }

    QString result;
    int start = cursor.selectionStart();
    int end = cursor.selectionEnd();

    QTextDocument* doc = m_primaryTextEdit->document();
    QTextCursor tempCursor(doc);

    for (int pos = start; pos < end; ) {
        tempCursor.setPosition(pos);
        tempCursor.movePosition(QTextCursor::NextCharacter, QTextCursor::KeepAnchor);

        QChar ch = tempCursor.selectedText().at(0);

        if (ch == QChar::ObjectReplacementCharacter) {
            // Check if it's a ruby object
            QTextCharFormat format = tempCursor.charFormat();
            if (format.objectType() == RubyTextObject::RubyObjectType) {
                // Get the base text (kanji)
                QString baseText = format.property(RubyTextObject::BaseText).toString();
                result += baseText;
            }
            pos++;
        } else {
            result += ch;
            pos++;
        }
    }

    return result;
}

void TextDisplayHelper::saveFontSize()
{
    QSettings settings;
    settings.beginGroup(m_settingsGroup);
    settings.setValue(QStringLiteral("fontSize"), m_fontSize);
    settings.endGroup();
    settings.sync();
}

void TextDisplayHelper::loadFontSize()
{
    QSettings settings;
    settings.beginGroup(m_settingsGroup);
    m_fontSize = settings.value(QStringLiteral("fontSize"), DEFAULT_FONT_SIZE).toInt();
    // Ensure loaded value is within bounds
    m_fontSize = qBound(MIN_FONT_SIZE, m_fontSize, MAX_FONT_SIZE);
    settings.endGroup();
}

} // namespace UI
} // namespace ClipLLM
