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

#include "rubysanitizer.h"
#include <QRegularExpression>

namespace ClipLLM {
namespace UI {
namespace RubyUtils {

// Tag type identifiers
enum class TagType {
    RubyOpen,   // <ruby>
    RtOpen,     // <rt>
    RtClose,    // </rt>
    RubyClose,  // </ruby>
};

// State machine states
enum class State {
    Outside,  // Not inside any ruby block
    InRuby,   // After <ruby>, collecting base text
    InRt,     // After <rt>, collecting annotation text
    AfterRt,  // After </rt>, waiting for </ruby>
    StrayRt,  // After <rt> outside <ruby>, collecting to discard
};

QString sanitizeRubyTags(const QString& text)
{
    // === Phase 1: Preprocessing — fix missing closing brackets ===
    // E.g. </rubyが → </ruby>が, <rtが → <rt>が
    QString preprocessed = text;
    const auto ci = QRegularExpression::CaseInsensitiveOption;
    preprocessed.replace(QRegularExpression(QStringLiteral("</ruby(?!>)"), ci), QStringLiteral("</ruby>"));
    preprocessed.replace(QRegularExpression(QStringLiteral("</rt(?!>)"), ci), QStringLiteral("</rt>"));
    preprocessed.replace(QRegularExpression(QStringLiteral("<ruby(?!>)"), ci), QStringLiteral("<ruby>"));
    preprocessed.replace(QRegularExpression(QStringLiteral("<rt(?!>)"), ci), QStringLiteral("<rt>"));

    // === Phase 2: Strip hallucinated non-ruby HTML tags ===
    // LLM sometimes outputs stray tags like </svg>, </zu>, <svg> etc.
    // These break Qt's HTML parser if left in the output.
    static const QRegularExpression strayHtmlTag(
        QStringLiteral("</?(?!ruby\\b)(?!rt\\b)[a-zA-Z][a-zA-Z0-9]*\\b[^>]*>"),
        QRegularExpression::CaseInsensitiveOption
    );
    preprocessed.remove(strayHtmlTag);

    // === Phase 3: State machine — single pass through all tags ===
    static const QRegularExpression tagRe(
        QStringLiteral("(</ruby>|<ruby>|</rt>|<rt>)"),
        QRegularExpression::CaseInsensitiveOption
    );

    QString output;
    output.reserve(preprocessed.size());

    State state = State::Outside;
    QString baseText;
    QString annotationText;

    int lastPos = 0;
    auto it = tagRe.globalMatch(preprocessed);

    while (it.hasNext()) {
        auto match = it.next();
        QString textBetween = preprocessed.mid(lastPos, match.capturedStart() - lastPos);
        lastPos = match.capturedEnd();

        QString tag = match.captured(1).toLower();
        TagType tagType;
        if (tag == QStringLiteral("<ruby>")) {
            tagType = TagType::RubyOpen;
        } else if (tag == QStringLiteral("<rt>")) {
            tagType = TagType::RtOpen;
        } else if (tag == QStringLiteral("</rt>")) {
            tagType = TagType::RtClose;
        } else {
            tagType = TagType::RubyClose;
        }

        switch (state) {
        case State::Outside:
            if (tagType == TagType::RubyOpen) {
                output += textBetween;
                baseText.clear();
                annotationText.clear();
                state = State::InRuby;
            } else if (tagType == TagType::RtOpen) {
                // Stray <rt> outside <ruby> — enter discard mode
                output += textBetween;
                state = State::StrayRt;
            } else {
                // Stray </rt> or </ruby> — strip them
                output += textBetween;
            }
            break;

        case State::StrayRt:
            if (tagType == TagType::RtClose || tagType == TagType::RubyClose) {
                // End of stray annotation — discard it
                state = State::Outside;
            } else if (tagType == TagType::RubyOpen) {
                // New <ruby> while in stray <rt> — start fresh ruby block
                output += textBetween;
                baseText.clear();
                annotationText.clear();
                state = State::InRuby;
            } else {
                // Nested stray <rt> — keep discarding
            }
            break;

        case State::InRuby:
            if (tagType == TagType::RtOpen) {
                baseText += textBetween;
                annotationText.clear();
                state = State::InRt;
            } else if (tagType == TagType::RubyClose) {
                // <ruby>base</ruby> — no annotation, emit base text only
                baseText += textBetween;
                output += baseText;
                state = State::Outside;
            } else if (tagType == TagType::RubyOpen) {
                // Nested <ruby> — ignore duplicate, accumulate text
                baseText += textBetween;
            } else {
                // </rt> without matching <rt> — treat as empty annotation
                baseText += textBetween;
                annotationText.clear();
                state = State::AfterRt;
            }
            break;

        case State::InRt:
            if (tagType == TagType::RtClose) {
                annotationText += textBetween;
                state = State::AfterRt;
            } else if (tagType == TagType::RubyClose) {
                // Missing </rt> — annotation ends at </ruby>
                annotationText += textBetween;
                if (!annotationText.isEmpty()) {
                    output += QStringLiteral("<ruby>") + baseText
                              + QStringLiteral("<rt>") + annotationText
                              + QStringLiteral("</rt></ruby>");
                } else {
                    output += baseText;
                }
                state = State::Outside;
            } else if (tagType == TagType::RubyOpen) {
                // New <ruby> while in <rt> — close current block (empty ann), restart
                annotationText += textBetween;
                output += baseText;
                baseText.clear();
                annotationText.clear();
                state = State::InRuby;
            } else {
                // <rt> inside <rt> — accumulate as annotation text
                annotationText += textBetween + match.captured(1);
            }
            break;

        case State::AfterRt:
            if (tagType == TagType::RubyClose) {
                // Complete block
                if (!annotationText.isEmpty()) {
                    output += QStringLiteral("<ruby>") + baseText
                              + QStringLiteral("<rt>") + annotationText
                              + QStringLiteral("</rt></ruby>");
                } else {
                    output += baseText;
                }
                state = State::Outside;
            } else if (tagType == TagType::RubyOpen) {
                // New <ruby> before </ruby> — emit current block, start new
                if (!annotationText.isEmpty()) {
                    output += QStringLiteral("<ruby>") + baseText
                              + QStringLiteral("<rt>") + annotationText
                              + QStringLiteral("</rt></ruby>");
                } else {
                    output += baseText;
                }
                output += textBetween;
                baseText.clear();
                annotationText.clear();
                state = State::InRuby;
            } else {
                // Stray </rt> or <rt> in AfterRt — emit current block, pass through tag
                if (!annotationText.isEmpty()) {
                    output += QStringLiteral("<ruby>") + baseText
                              + QStringLiteral("<rt>") + annotationText
                              + QStringLiteral("</rt></ruby>");
                } else {
                    output += baseText;
                }
                output += textBetween + match.captured(1);
                state = State::Outside;
            }
            break;
        }
    }

    // Handle remaining text after last tag
    QString trailing = preprocessed.mid(lastPos);

    switch (state) {
    case State::Outside:
        output += trailing;
        break;
    case State::InRuby:
        // Unclosed <ruby> at EOF — emit base text
        baseText += trailing;
        output += baseText;
        break;
    case State::InRt:
        // Unclosed <rt> at EOF — no valid annotation, emit base text only
        output += baseText;
        break;
    case State::AfterRt:
        // Has annotation but missing </ruby> — emit as valid ruby + trailing text
        if (!annotationText.isEmpty()) {
            output += QStringLiteral("<ruby>") + baseText
                      + QStringLiteral("<rt>") + annotationText
                      + QStringLiteral("</rt></ruby>");
        } else {
            output += baseText;
        }
        output += trailing;
        break;
    case State::StrayRt:
        // Unclosed stray <rt> at EOF — discard annotation
        break;
    }

    return output;
}

} // namespace RubyUtils
} // namespace UI
} // namespace ClipLLM
