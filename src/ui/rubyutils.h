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

#ifndef CLIPLLM_UI_RUBYUTILS_H
#define CLIPLLM_UI_RUBYUTILS_H

#include <QString>

namespace ClipLLM {
namespace UI {
namespace RubyUtils {

/**
 * Check if text contains HTML5 ruby tags (<ruby> and <rt>).
 * @param text The text to check
 * @return true if ruby tags are present
 */
bool containsRubyTags(const QString& text);

/**
 * Convert HTML5 ruby tags to Qt-supported HTML with inline styles.
 *
 * Input format: <ruby>漢字<rt>かんじ</rt></ruby>
 * Output format: styled spans that render furigana above kanji
 *
 * @param text The text containing ruby tags
 * @return Text with ruby tags converted to styled HTML spans
 */
QString convertRubyToHtml(const QString& text);

/**
 * Convert escaped ruby tags in HTML to styled spans.
 * Used after markdown conversion which escapes HTML tags.
 *
 * Input format: &lt;ruby&gt;漢字&lt;rt&gt;かんじ&lt;/rt&gt;&lt;/ruby&gt;
 * Output format: styled spans that render furigana above kanji
 *
 * @param html The HTML containing escaped ruby tags
 * @return HTML with escaped ruby tags converted to styled spans
 */
QString convertEscapedRubyInHtml(const QString& html);

/**
 * Protect ruby tags by replacing them with placeholders before markdown processing.
 * This prevents markdown parser from escaping HTML tags.
 *
 * @param text The text to process (modified in place)
 * @return Encoded placeholder data for later restoration
 */
QString protectRubyTags(QString& text);

/**
 * Restore ruby tags from placeholders after markdown processing.
 *
 * @param html The HTML with placeholders
 * @param placeholderData The data returned by protectRubyTags()
 * @return HTML with ruby tags converted to styled spans
 */
QString restoreRubyTags(const QString& html, const QString& placeholderData);

} // namespace RubyUtils
} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_RUBYUTILS_H
