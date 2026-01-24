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
#include "core/configmanager.h"

using namespace ClipLLM::Core;

class TestConfigManager : public QObject
{
    Q_OBJECT

private slots:
    void initTestCase();
    void init();
    void cleanup();

    // Default values tests
    void cleanupByCountDefault_isFalse();
    void cleanupByDateDefault_isFalse();
    void historyLimitDefault_is1000();
    void historyDaysToKeepDefault_is30();

    // Getter/Setter tests
    void setCleanupByCount_persists();
    void setCleanupByDate_persists();
    void setHistoryLimit_persists();
    void setHistoryDaysToKeep_persists();

    // Edge cases
    void cleanupByCount_withMultipleChanges();
    void cleanupByDate_withMultipleChanges();

private:
    ConfigManager* m_manager;
    QTemporaryDir* m_tempDir;
};

void TestConfigManager::initTestCase()
{
    // Set up test environment
}

void TestConfigManager::init()
{
    m_tempDir = new QTemporaryDir();
    QVERIFY(m_tempDir->isValid());

    // Create a fresh manager for each test
    // Note: ConfigManager uses QSettings which writes to a specific location
    // We can't easily redirect this in tests, so we'll test the getter/setter logic
    m_manager = new ConfigManager();
}

void TestConfigManager::cleanup()
{
    // Clean up settings
    if (m_manager) {
        m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_CLEANUP_BY_COUNT_KEY);
        m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_CLEANUP_BY_DATE_KEY);
        m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_LIMIT_KEY);
        m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_DAYS_TO_KEEP_KEY);
        m_manager->sync();
    }
    delete m_manager;
    delete m_tempDir;
}

// Default values tests

void TestConfigManager::cleanupByCountDefault_isFalse()
{
    // Clear the setting to test default
    m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_CLEANUP_BY_COUNT_KEY);
    m_manager->sync();

    bool defaultValue = m_manager->historyCleanupByCount();
    QCOMPARE(defaultValue, false); // Default should be false (conservative)
}

void TestConfigManager::cleanupByDateDefault_isFalse()
{
    // Clear the setting to test default
    m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_CLEANUP_BY_DATE_KEY);
    m_manager->sync();

    bool defaultValue = m_manager->historyCleanupByDate();
    QCOMPARE(defaultValue, false); // Default should be false (conservative)
}

void TestConfigManager::historyLimitDefault_is1000()
{
    // Clear the setting to test default
    m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_LIMIT_KEY);
    m_manager->sync();

    int defaultValue = m_manager->historyLimit();
    QCOMPARE(defaultValue, 1000);
}

void TestConfigManager::historyDaysToKeepDefault_is30()
{
    // Clear the setting to test default
    m_manager->remove(ClipLLM::Core::ConfigManager::HISTORY_DAYS_TO_KEEP_KEY);
    m_manager->sync();

    int defaultValue = m_manager->historyDaysToKeep();
    QCOMPARE(defaultValue, 30);
}

// Getter/Setter tests

void TestConfigManager::setCleanupByCount_persists()
{
    m_manager->setHistoryCleanupByCount(true);
    m_manager->sync();

    bool value = m_manager->historyCleanupByCount();
    QCOMPARE(value, true);

    // Set to false and verify
    m_manager->setHistoryCleanupByCount(false);
    m_manager->sync();

    value = m_manager->historyCleanupByCount();
    QCOMPARE(value, false);
}

void TestConfigManager::setCleanupByDate_persists()
{
    m_manager->setHistoryCleanupByDate(true);
    m_manager->sync();

    bool value = m_manager->historyCleanupByDate();
    QCOMPARE(value, true);

    // Set to false and verify
    m_manager->setHistoryCleanupByDate(false);
    m_manager->sync();

    value = m_manager->historyCleanupByDate();
    QCOMPARE(value, false);
}

void TestConfigManager::setHistoryLimit_persists()
{
    m_manager->setHistoryLimit(500);
    m_manager->sync();

    int value = m_manager->historyLimit();
    QCOMPARE(value, 500);

    // Set to another value and verify
    m_manager->setHistoryLimit(2000);
    m_manager->sync();

    value = m_manager->historyLimit();
    QCOMPARE(value, 2000);
}

void TestConfigManager::setHistoryDaysToKeep_persists()
{
    m_manager->setHistoryDaysToKeep(60);
    m_manager->sync();

    int value = m_manager->historyDaysToKeep();
    QCOMPARE(value, 60);

    // Set to another value and verify
    m_manager->setHistoryDaysToKeep(90);
    m_manager->sync();

    value = m_manager->historyDaysToKeep();
    QCOMPARE(value, 90);
}

// Edge cases

void TestConfigManager::cleanupByCount_withMultipleChanges()
{
    // Set to true
    m_manager->setHistoryCleanupByCount(true);
    QCOMPARE(m_manager->historyCleanupByCount(), true);

    // Set to false
    m_manager->setHistoryCleanupByCount(false);
    QCOMPARE(m_manager->historyCleanupByCount(), false);

    // Set to true again
    m_manager->setHistoryCleanupByCount(true);
    QCOMPARE(m_manager->historyCleanupByCount(), true);

    m_manager->sync();
}

void TestConfigManager::cleanupByDate_withMultipleChanges()
{
    // Set to true
    m_manager->setHistoryCleanupByDate(true);
    QCOMPARE(m_manager->historyCleanupByDate(), true);

    // Set to false
    m_manager->setHistoryCleanupByDate(false);
    QCOMPARE(m_manager->historyCleanupByDate(), false);

    // Set to true again
    m_manager->setHistoryCleanupByDate(true);
    QCOMPARE(m_manager->historyCleanupByDate(), true);

    m_manager->sync();
}

QTEST_MAIN(TestConfigManager)
#include "tst_configmanager.moc"
