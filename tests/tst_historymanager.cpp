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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include <QtTest>
#include <QTemporaryDir>
#include "core/historymanager.h"

using namespace ClipLLM::Core;

class TestHistoryManager : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void init();
    void cleanup();

    // cleanupByCount tests
    void cleanupByCount_removesOldestEntries();
    void cleanupByCount_withEmptyHistory();
    void cleanupByCount_withExactLimit();
    void cleanupByCount_withZeroLimit();
    void cleanupByCount_withNegativeLimit();

    // cleanupByDate tests
    void cleanupByDate_removesOldEntries();
    void cleanupByDate_withEmptyHistory();
    void cleanupByDate_withAllRecentEntries();
    void cleanupByDate_withOneDayToKeep();

    // Combined tests
    void cleanupByCountAndDate_combined();

private:
    HistoryManager* m_manager;
    QTemporaryDir* m_tempDir;
};

void TestHistoryManager::initTestCase()
{
    // Set up test environment
}

void TestHistoryManager::init()
{
    m_tempDir = new QTemporaryDir();
    QVERIFY(m_tempDir->isValid());

    // Create a fresh manager for each test with isolated storage
    m_manager = new HistoryManager(nullptr,
                                  m_tempDir->filePath(QStringLiteral("history.json")));
}

void TestHistoryManager::cleanup()
{
    delete m_manager;
    delete m_tempDir;
}

// cleanupByCount tests

void TestHistoryManager::cleanupByCount_removesOldestEntries()
{
    // Add 5 entries with different timestamps
    QDateTime now = QDateTime::currentDateTime();
    for (int i = 0; i < 5; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("entry-%1").arg(i);
        entry.timestamp = now.addSecs(i * 60); // Different timestamps
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Input %1").arg(i);
        entry.outputText = QStringLiteral("Output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Limit to 3 entries, should remove 2 oldest
    int removed = m_manager->cleanupByCount(3);
    QCOMPARE(removed, 2);
    QCOMPARE(m_manager->getTotalEntries(), 3);
}

void TestHistoryManager::cleanupByCount_withEmptyHistory()
{
    int removed = m_manager->cleanupByCount(10);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 0);
}

void TestHistoryManager::cleanupByCount_withExactLimit()
{
    QDateTime now = QDateTime::currentDateTime();
    for (int i = 0; i < 5; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("entry-%1").arg(i);
        entry.timestamp = now.addSecs(i * 60);
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Input %1").arg(i);
        entry.outputText = QStringLiteral("Output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Limit equals current count, should remove nothing
    int removed = m_manager->cleanupByCount(5);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 5);
}

void TestHistoryManager::cleanupByCount_withZeroLimit()
{
    QDateTime now = QDateTime::currentDateTime();
    for (int i = 0; i < 5; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("entry-%1").arg(i);
        entry.timestamp = now.addSecs(i * 60);
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Input %1").arg(i);
        entry.outputText = QStringLiteral("Output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Zero limit means no cleanup
    int removed = m_manager->cleanupByCount(0);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 5);
}

void TestHistoryManager::cleanupByCount_withNegativeLimit()
{
    QDateTime now = QDateTime::currentDateTime();
    for (int i = 0; i < 5; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("entry-%1").arg(i);
        entry.timestamp = now.addSecs(i * 60);
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Input %1").arg(i);
        entry.outputText = QStringLiteral("Output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Negative limit means no cleanup
    int removed = m_manager->cleanupByCount(-1);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 5);
}

// cleanupByDate tests

void TestHistoryManager::cleanupByDate_removesOldEntries()
{
    QDateTime now = QDateTime::currentDateTime();

    // Add entries: 3 old (60 days ago), 2 recent
    for (int i = 0; i < 3; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("old-%1").arg(i);
        entry.timestamp = now.addDays(-60); // 60 days old
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Old input %1").arg(i);
        entry.outputText = QStringLiteral("Old output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    for (int i = 0; i < 2; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("new-%1").arg(i);
        entry.timestamp = now; // Recent
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("New input %1").arg(i);
        entry.outputText = QStringLiteral("New output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Keep entries from last 30 days, should remove 3 old entries
    int removed = m_manager->cleanupByDate(30);
    QCOMPARE(removed, 3);
    QCOMPARE(m_manager->getTotalEntries(), 2);
}

void TestHistoryManager::cleanupByDate_withEmptyHistory()
{
    int removed = m_manager->cleanupByDate(30);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 0);
}

void TestHistoryManager::cleanupByDate_withAllRecentEntries()
{
    QDateTime now = QDateTime::currentDateTime();

    // Add 5 recent entries (within 30 days)
    for (int i = 0; i < 5; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("entry-%1").arg(i);
        entry.timestamp = now.addDays(-i); // 0 to 4 days old
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Input %1").arg(i);
        entry.outputText = QStringLiteral("Output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Keep entries from last 30 days, should remove nothing
    int removed = m_manager->cleanupByDate(30);
    QCOMPARE(removed, 0);
    QCOMPARE(m_manager->getTotalEntries(), 5);
}

void TestHistoryManager::cleanupByDate_withOneDayToKeep()
{
    QDateTime now = QDateTime::currentDateTime();

    // Add entries: 3 old (2 days ago), 2 recent (today)
    for (int i = 0; i < 3; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("old-%1").arg(i);
        entry.timestamp = now.addDays(-2); // 2 days old
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Old input %1").arg(i);
        entry.outputText = QStringLiteral("Old output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    for (int i = 0; i < 2; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("new-%1").arg(i);
        entry.timestamp = now; // Today
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("New input %1").arg(i);
        entry.outputText = QStringLiteral("New output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    // Keep only entries from last 1 day, should remove 3 old entries
    int removed = m_manager->cleanupByDate(1);
    QCOMPARE(removed, 3);
    QCOMPARE(m_manager->getTotalEntries(), 2);
}

// Combined tests

void TestHistoryManager::cleanupByCountAndDate_combined()
{
    QDateTime now = QDateTime::currentDateTime();

    // Add mix of entries:
    // - 3 very old (60 days ago)
    // - 3 medium age (20 days ago)
    // - 4 recent (today)
    // Total: 10 entries
    for (int i = 0; i < 3; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("very-old-%1").arg(i);
        entry.timestamp = now.addDays(-60);
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Very old input %1").arg(i);
        entry.outputText = QStringLiteral("Very old output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    for (int i = 0; i < 3; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("medium-%1").arg(i);
        entry.timestamp = now.addDays(-20);
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Medium input %1").arg(i);
        entry.outputText = QStringLiteral("Medium output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    for (int i = 0; i < 4; ++i) {
        HistoryEntry entry;
        entry.id = QStringLiteral("recent-%1").arg(i);
        entry.timestamp = now;
        entry.promptId = QStringLiteral("prompt1");
        entry.promptName = QStringLiteral("Test Prompt");
        entry.provider = QStringLiteral("openrouter");
        entry.model = QStringLiteral("gpt-4");
        entry.contentType = HistoryEntryType::Text;
        entry.inputText = QStringLiteral("Recent input %1").arg(i);
        entry.outputText = QStringLiteral("Recent output %1").arg(i);
        entry.inputTokens = 10;
        entry.outputTokens = 20;
        entry.durationMs = 1000.0;
        entry.favorite = false;

        m_manager->addEntry(entry);
    }

    QCOMPARE(m_manager->getTotalEntries(), 10);

    // First, clean by date (keep last 30 days) - removes 3 very old entries
    int removedByDate = m_manager->cleanupByDate(30);
    QCOMPARE(removedByDate, 3);
    QCOMPARE(m_manager->getTotalEntries(), 7);

    // Then, clean by count (keep 5 entries) - removes 2 oldest of remaining
    int removedByCount = m_manager->cleanupByCount(5);
    QCOMPARE(removedByCount, 2);
    QCOMPARE(m_manager->getTotalEntries(), 5);
}

QTEST_MAIN(TestHistoryManager)
#include "tst_historymanager.moc"
