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

#ifndef CLIPLLM_UI_RUBYSANITIZER_H
#define CLIPLLM_UI_RUBYSANITIZER_H

#include <QString>

namespace ClipLLM {
namespace UI {
namespace RubyUtils {

/**
 * Sanitize ruby tags from LLM output using a state-machine parser.
 * Fixes various malformed markup patterns produced by LLMs:
 * - Missing closing brackets (</rubyが → </ruby>が)
 * - Nested/duplicate <ruby> open tags
 * - Missing <rt> open tags
 * - Missing </rt> close tags with empty annotations
 * - Unclosed tags at end of text
 * - Empty annotations
 *
 * @param text The text to sanitize
 * @return Text with malformed ruby tags fixed or stripped
 */
QString sanitizeRubyTags(const QString& text);

} // namespace RubyUtils
} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_RUBYSANITIZER_H
