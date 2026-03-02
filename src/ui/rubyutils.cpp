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

#include "rubyutils.h"
#include "rubytextobject.h"
#include "core/app.h"
#include "core/configmanager.h"
#include <QRegularExpression>
#include <QStringBuilder>
#include <QTextDocument>
#include <QTextBlock>
#include <QTextFragment>
#include <QTextCursor>
#include <QApplication>
#include <algorithm>

namespace ClipLLM {
namespace UI {
namespace RubyUtils {

bool containsRubyTags(const QString& text)
{
    return text.contains(QLatin1String("<ruby>"), Qt::CaseInsensitive) &&
           text.contains(QLatin1String("<rt>"), Qt::CaseInsensitive);
}

QString stripRubyTags(const QString& text)
{
    QString result = text;

    // Pattern to match <ruby>base<rt>annotation</rt></ruby>
    QRegularExpression rubyPattern(
        QStringLiteral("<ruby>([^<]*)<rt>([^<]*)</rt></ruby>"),
        QRegularExpression::CaseInsensitiveOption
    );

    // Manual replacement to extract just the base text
    QRegularExpressionMatch match;
    while ((match = rubyPattern.match(result)).hasMatch()) {
        QString baseText = match.captured(1);  // Get the kanji
        result.replace(match.capturedStart(), match.capturedLength(), baseText);
    }

    return result;
}

QString convertRubyToHtml(const QString& text)
{
    QString result = text;

    // Pattern to match <ruby>base<rt>annotation</rt></ruby>
    QRegularExpression rubyPattern(
        QStringLiteral("<ruby>([^<]*)<rt>([^<]*)</rt></ruby>"),
        QRegularExpression::CaseInsensitiveOption
    );

    QRegularExpressionMatch match;
    while ((match = rubyPattern.match(result)).hasMatch()) {
        QString baseText = match.captured(1);
        QString rubyText = match.captured(2);

        // Use simple superscript styling
        QString replacement = QStringLiteral(
            "<sup style=\"font-size: 0.7em;\">%1</sup>%2"
        ).arg(rubyText, baseText);

        result.replace(match.capturedStart(), match.capturedLength(), replacement);
    }

    return result;
}

QString convertEscapedRubyInHtml(const QString& html)
{
    QString result = html;

    // Pattern to match escaped ruby tags
    QRegularExpression escapedRubyPattern(
        QStringLiteral("&lt;ruby&gt;([^&]*)&lt;rt&gt;([^&]*)&lt;/rt&gt;&lt;/ruby&gt;"),
        QRegularExpression::CaseInsensitiveOption
    );

    QRegularExpressionMatch match;
    while ((match = escapedRubyPattern.match(result)).hasMatch()) {
        QString baseText = match.captured(1);
        QString rubyText = match.captured(2);

        QString replacement = QStringLiteral(
            "<sup style=\"font-size: 0.7em;\">%1</sup>%2"
        ).arg(rubyText, baseText);

        result.replace(match.capturedStart(), match.capturedLength(), replacement);
    }

    return result;
}

// Helper to encode string as hex
static QString toHex(const QString& s)
{
    QByteArray utf8 = s.toUtf8().toHex();
    return QString::fromLatin1(utf8);
}

// Helper to decode hex string
static QString fromHex(const QString& h)
{
    QByteArray bytes = QByteArray::fromHex(h.toLatin1());
    return QString::fromUtf8(bytes);
}

QString protectRubyTags(QString& text)
{
    QString result = text;
    QStringList rubyData;
    int index = 0;

    // Pattern to match <ruby>base<rt>annotation</rt></ruby>
    QRegularExpression rubyPattern(
        QStringLiteral("<ruby>([^<]*)<rt>([^<]*)</rt></ruby>"),
        QRegularExpression::CaseInsensitiveOption
    );

    struct Replacement {
        int start;
        int length;
        QString placeholder;
    };
    QVector<Replacement> replacements;

    QRegularExpressionMatchIterator it = rubyPattern.globalMatch(result);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        QString baseText = match.captured(1);
        QString rubyText = match.captured(2);

        // Store data as hex-encoded strings separated by |
        rubyData.append(toHex(baseText) % QStringLiteral("|") % toHex(rubyText));

        // Use unique placeholder format with zero-padded index
        // Format: RB<zero-padded 5 digits>END
        QString placeholder = QStringLiteral("RB%1END").arg(index, 5, 10, QLatin1Char('0'));

        replacements.append({static_cast<int>(match.capturedStart()),
                            static_cast<int>(match.capturedLength()),
                            placeholder});
        index++;
    }

    // Apply replacements from end to start
    for (int i = replacements.size() - 1; i >= 0; --i) {
        result.replace(replacements[i].start, replacements[i].length, replacements[i].placeholder);
    }

    text = result;
    return rubyData.join(QStringLiteral(";"));
}

QString restoreRubyTags(const QString& html, const QString& placeholderData)
{
    if (placeholderData.isEmpty()) {
        return html;
    }

    // Get furigana size from config (default 45%)
    int furiganaSizePercent = 45;
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app && app->configManager()) {
        furiganaSizePercent = app->configManager()->furiganaSize();
    }

    QStringList rubyDataList = placeholderData.split(QStringLiteral(";"));
    QString result = html;

    for (int i = 0; i < rubyDataList.size(); ++i) {
        if (rubyDataList[i].isEmpty()) continue;

        // Reconstruct placeholder
        QString placeholder = QStringLiteral("R%1X").arg(i);

        // Parse stored data
        QStringList parts = rubyDataList[i].split(QStringLiteral("|"));
        if (parts.size() == 2) {
            QString baseText = fromHex(parts[0]);
            QString rubyText = fromHex(parts[1]);

            // Use em for relative font size (percent / 100 = em)
            double fontSizeEm = furiganaSizePercent / 100.0;
            // Use br to create line break between furigana and kanji within inline-block
            QString replacement = QStringLiteral(
                "<span style=\"display: inline-block; text-align: center; vertical-align: bottom; line-height: 1;\">"
                "<span style=\"font-size: %1em;\">%2</span><br>%3</span>"
            ).arg(QString::number(fontSizeEm, 'f', 2), rubyText, baseText);

            result.replace(placeholder, replacement);
        }
    }

    return result;
}

int replaceRubyPlaceholders(QTextDocument* doc, const QString& placeholderData,
                            bool rubyVisible)
{
    if (placeholderData.isEmpty()) {
        return 0;
    }

    // Parse placeholder data
    QStringList rubyDataList = placeholderData.split(QStringLiteral(";"));
    QVector<QPair<QString, QString>> rubyList; // (base, ruby)

    for (int i = 0; i < rubyDataList.size(); ++i) {
        if (rubyDataList[i].isEmpty()) continue;
        QStringList parts = rubyDataList[i].split(QStringLiteral("|"));
        if (parts.size() == 2) {
            QByteArray baseBytes = QByteArray::fromHex(parts[0].toLatin1());
            QByteArray rubyBytes = QByteArray::fromHex(parts[1].toLatin1());
            rubyList.append(qMakePair(QString::fromUtf8(baseBytes),
                                      QString::fromUtf8(rubyBytes)));
        }
    }

    // Collect all placeholder positions first, then replace from end to start
    // Placeholder format: RB<5 digits>END (e.g., RB00000END, RB00001END)
    struct PlaceholderInfo {
        int position;
        int rubyIndex;
    };
    QVector<PlaceholderInfo> placeholders;

    QTextBlock block = doc->begin();
    while (block.isValid()) {
        QTextBlock::iterator it;
        for (it = block.begin(); !(it.atEnd()); ++it) {
            QTextFragment fragment = it.fragment();
            if (!fragment.isValid())
                continue;

            QString text = fragment.text();
            int fragmentStart = fragment.position();

            // Search for placeholder pattern in this fragment
            int searchPos = 0;
            while (searchPos < text.length()) {
                int rbPos = text.indexOf(QStringLiteral("RB"), searchPos);
                if (rbPos == -1) break;

                int endPos = text.indexOf(QStringLiteral("END"), rbPos);
                if (endPos == -1) {
                    searchPos = rbPos + 2;
                    continue;
                }

                // Verify the placeholder has correct length (RB + 5 digits + END = 10 chars)
                if (endPos - rbPos != 7) { // "RB" + 5 digits = 7, then "END"
                    searchPos = rbPos + 2;
                    continue;
                }

                // Extract index from placeholder
                QString indexStr = text.mid(rbPos + 2, 5);
                bool ok;
                int idx = indexStr.toInt(&ok);

                if (ok && idx >= 0 && idx < rubyList.size()) {
                    placeholders.append({fragmentStart + rbPos, idx});
                }

                searchPos = endPos + 3; // Move past "END"
            }
        }
        block = block.next();
    }

    // Sort placeholders by position in descending order (replace from end)
    std::sort(placeholders.begin(), placeholders.end(),
        [](const PlaceholderInfo& a, const PlaceholderInfo& b) {
            return a.position > b.position;
        });

    // Now replace all placeholders
    QTextCursor cursor(doc);
    cursor.beginEditBlock();

    int replacedCount = 0;
    for (const auto& ph : placeholders) {
        cursor.setPosition(ph.position);
        cursor.setPosition(ph.position + 10, QTextCursor::KeepAnchor);

        const auto& rubyData = rubyList[ph.rubyIndex];
        QTextCharFormat rubyFormat = RubyTextObject::createFormat(
            rubyData.first, rubyData.second, rubyVisible);
        cursor.insertText(QString(QChar::ObjectReplacementCharacter), rubyFormat);
        replacedCount++;
    }

    cursor.endEditBlock();

    return replacedCount;
}

} // namespace RubyUtils
} // namespace UI
} // namespace ClipLLM
