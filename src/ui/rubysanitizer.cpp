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
    // === Step 1: Protect known tags with placeholders ===
    // Replace <ruby>, <rt>, </rt>, </ruby> (including broken variants
    // missing the closing >) with unique placeholder tokens using \x01/\x02
    // delimiters. Control characters never appear in LLM output.
    //
    // Each regex matches both:
    //   - Complete tags: </ruby>  (the > alternative)
    //   - Broken tags:   </rubyが  (negative lookahead — next char is not a letter)
    //   - Tags at EOF:   </ruby   (negative lookahead succeeds at end of string)
    //
    // Negative lookahead (?![a-zA-Z]) prevents false matches on unrelated
    // tags like <rubyx>.

    const auto ci = QRegularExpression::CaseInsensitiveOption;
    QString preprocessed = text;

    preprocessed.replace(QRegularExpression(QStringLiteral("</ruby(?:>|(?![a-zA-Z]))"), ci),
                         QStringLiteral("\x01/R\x02"));
    preprocessed.replace(QRegularExpression(QStringLiteral("<ruby(?:>|(?![a-zA-Z]))"), ci),
                         QStringLiteral("\x01R\x02"));
    preprocessed.replace(QRegularExpression(QStringLiteral("</rt(?:>|(?![a-zA-Z]))"), ci),
                         QStringLiteral("\x01/RT\x02"));
    preprocessed.replace(QRegularExpression(QStringLiteral("<rt(?:>|(?![a-zA-Z]))"), ci),
                         QStringLiteral("\x01RT\x02"));

    // === Step 2: Remove all remaining HTML tags ===
    // After step 1, every <...> is unwanted HTML hallucinated by the LLM.
    static const QRegularExpression anyHtmlTag(QStringLiteral("<[^>]*>"));
    preprocessed.remove(anyHtmlTag);

    // === Step 3: Remove stray angle brackets ===
    // Broken fragments like </しかった or <何か remain after step 2 because
    // they lack a closing >. Remove </ first, then <, to avoid leaving
    // a stray / behind.
    preprocessed.remove(QStringLiteral("</"));
    preprocessed.remove(QStringLiteral("<"));

    // === Step 4: Restore placeholders to proper tags ===
    preprocessed.replace(QStringLiteral("\x01/R\x02"), QStringLiteral("</ruby>"));
    preprocessed.replace(QStringLiteral("\x01R\x02"), QStringLiteral("<ruby>"));
    preprocessed.replace(QStringLiteral("\x01/RT\x02"), QStringLiteral("</rt>"));
    preprocessed.replace(QStringLiteral("\x01RT\x02"), QStringLiteral("<rt>"));

    // === Step 5: State machine — validate and fix ruby structure ===
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
