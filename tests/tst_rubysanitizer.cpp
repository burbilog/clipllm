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

#include <QtTest>
#include "ui/rubysanitizer.h"

using namespace ClipLLM::UI::RubyUtils;

class TestRubySanitizer : public QObject
{
    Q_OBJECT

private slots:
    // Valid ruby blocks — should be preserved unchanged
    void testValidRubyPreserved();
    void testValidRubySurroundedByText();
    void testMultipleValidBlocks();

    // Mal-formed: nested <ruby>
    void testNestedRubyOpenTag();

    // Mal-formed: missing closing >
    void testMissingCloseBracketOnRubyClose();
    void testMissingCloseBracketOnRtClose();
    void testMissingCloseBracketOnRubyOpen();
    void testMissingCloseBracketOnRtOpen();

    // Mal-formed: missing <rt>
    void testMissingRtOpenTag();

    // Mal-formed: missing </rt> + empty annotation
    void testMissingCloseRtEmptyAnnotation();

    // Mal-formed: empty annotation
    void testEmptyAnnotation();

    // Mal-formed: unclosed ruby at EOF
    void testUnclosedRubyAtEof();

    // Mal-formed: unclosed rt at EOF
    void testUnclosedRtAtEof();

    // Mal-formed: stray close tags outside context
    void testStrayCloseRuby();
    void testStrayCloseRt();

    // Real LLM output integration tests
    void testRealLLMOutput1();
    void testRealLLMOutput2();

    // Invariant: idempotency
    void testIdempotent();
};

// --- Valid ruby blocks (should be preserved) ---

void TestRubySanitizer::testValidRubyPreserved()
{
    QString input = QStringLiteral("<ruby>漢字<rt>かんじ</rt></ruby>");
    QCOMPARE(sanitizeRubyTags(input), input);
}

void TestRubySanitizer::testValidRubySurroundedByText()
{
    QString input = QStringLiteral("Hello <ruby>漢字<rt>かんじ</rt></ruby> world");
    QCOMPARE(sanitizeRubyTags(input), input);
}

void TestRubySanitizer::testMultipleValidBlocks()
{
    QString input = QStringLiteral("<ruby>漢<rt>かん</rt></ruby><ruby>字<rt>じ</rt></ruby>");
    QCOMPARE(sanitizeRubyTags(input), input);
}

// --- Mal-formed: nested <ruby> ---

void TestRubySanitizer::testNestedRubyOpenTag()
{
    QString input = QStringLiteral("<ruby>主<ruby><rt>ぬし</rt></ruby>");
    QString expected = QStringLiteral("<ruby>主<rt>ぬし</rt></ruby>");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: missing closing > ---

void TestRubySanitizer::testMissingCloseBracketOnRubyClose()
{
    QString input = QStringLiteral("</rubyがありません");
    QString expected = QStringLiteral("</ruby>がありません");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

void TestRubySanitizer::testMissingCloseBracketOnRtClose()
{
    QString input = QStringLiteral("</rtが");
    QString expected = QStringLiteral("</rt>が");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

void TestRubySanitizer::testMissingCloseBracketOnRubyOpen()
{
    // After preprocessing: <ruby>が — unclosed ruby at EOF, stripped to base text
    QString input = QStringLiteral("<rubyが");
    QString expected = QStringLiteral("が");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

void TestRubySanitizer::testMissingCloseBracketOnRtOpen()
{
    QString input = QStringLiteral("<rtが");
    QString expected = QStringLiteral("<rt>が");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: missing <rt> ---

void TestRubySanitizer::testMissingRtOpenTag()
{
    QString input = QStringLiteral("<ruby>ばし</rt></ruby>");
    QString expected = QStringLiteral("ばし");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: missing </rt> + empty annotation ---

void TestRubySanitizer::testMissingCloseRtEmptyAnnotation()
{
    QString input = QStringLiteral("<ruby>く<rt></ruby>");
    QString expected = QStringLiteral("く");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: empty annotation ---

void TestRubySanitizer::testEmptyAnnotation()
{
    QString input = QStringLiteral("<ruby>漢字<rt></rt></ruby>");
    QString expected = QStringLiteral("漢字");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: unclosed ruby at EOF ---

void TestRubySanitizer::testUnclosedRubyAtEof()
{
    QString input = QStringLiteral("Some <ruby>未完");
    QString expected = QStringLiteral("Some 未完");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: unclosed rt at EOF ---

void TestRubySanitizer::testUnclosedRtAtEof()
{
    QString input = QStringLiteral("<ruby>字<rt>じ");
    QString expected = QStringLiteral("字");
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Mal-formed: stray close tags outside context ---

void TestRubySanitizer::testStrayCloseRuby()
{
    QString input = QStringLiteral("text</ruby>more");
    QCOMPARE(sanitizeRubyTags(input), input);
}

void TestRubySanitizer::testStrayCloseRt()
{
    QString input = QStringLiteral("text</rt>more");
    QCOMPARE(sanitizeRubyTags(input), input);
}

// --- Real LLM output integration tests ---

void TestRubySanitizer::testRealLLMOutput1()
{
    // Real LLM output with nested ruby tags and missing brackets
    QString input = QStringLiteral(
        "<ruby>駐<rt>ちゅう</rt></ruby><ruby>輪<rt>りん</rt></ruby>"
        "<ruby>場<ruby><rt>じょう</rt></ruby>に"
        "<ruby>自<rt>じ</rt></ruby><ruby>転<rt>てん</rt></ruby>"
        "<ruby>車<rt>しゃ</rt></ruby>を"
    );
    QString expected = QStringLiteral(
        "<ruby>駐<rt>ちゅう</rt></ruby><ruby>輪<rt>りん</rt></ruby>"
        "<ruby>場<rt>じょう</rt></ruby>に"
        "<ruby>自<rt>じ</rt></ruby><ruby>転<rt>てん</rt></ruby>"
        "<ruby>車<rt>しゃ</rt></ruby>を"
    );
    QCOMPARE(sanitizeRubyTags(input), expected);
}

void TestRubySanitizer::testRealLLMOutput2()
{
    // Real LLM output with empty <rt> tag
    QString input = QStringLiteral(
        "<ruby>く<rt></ruby>形式（いわゆる"
    );
    QString expected = QStringLiteral(
        "く形式（いわゆる"
    );
    QCOMPARE(sanitizeRubyTags(input), expected);
}

// --- Invariant: idempotency ---

void TestRubySanitizer::testIdempotent()
{
    QString input = QStringLiteral(
        "<ruby>主<ruby><rt>ぬし</rt></ruby>と"
        "<ruby>漢字<rt>かんじ</rt></ruby> "
        "<ruby>く<rt></ruby> "
        "<ruby>ばし</rt></ruby>"
    );
    QString first = sanitizeRubyTags(input);
    QString second = sanitizeRubyTags(first);
    QCOMPARE(second, first);
}

QTEST_APPLESS_MAIN(TestRubySanitizer)
#include "tst_rubysanitizer.moc"
