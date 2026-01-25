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

#ifndef CLIPLLM_CORE_DEBUGLOGGER_H
#define CLIPLLM_CORE_DEBUGLOGGER_H

#include <QFile>
#include <QTextStream>
#include <QMutex>
#include <QString>
#include <QApplication>

// Forward declarations
namespace ClipLLM {

class App;

namespace Core {

enum class DebugLevel {
    Off = 0,
    Normal = 1,
    Trace = 2
};

class DebugLogger
{
public:
    static DebugLogger* instance();

    void log(const QString& message, DebugLevel level = DebugLevel::Normal);
    void trace(const QString& message);  // For trace-level logging

    DebugLevel currentLevel() const;
    void setLevel(DebugLevel level);
    bool isEnabled() const;

    // Convenience methods
    void debug(const QString& message);
    void info(const QString& message);
    void warning(const QString& message);
    void error(const QString& message);

private:
    DebugLogger();
    ~DebugLogger();
    void writeLog(const QString& message);

    QFile m_logFile;
    QTextStream m_logStream;
    QMutex m_mutex;
    DebugLevel m_level = DebugLevel::Off;
};

} // namespace Core
} // namespace ClipLLM

// Convenience macros that use DebugLogger when enabled, fallback to qDebug/qWarning
// These macros work even if DebugLogger is not yet initialized (early startup)
#define LOG_DEBUG(msg) \
    do { \
        if (auto* _logger = ClipLLM::Core::DebugLogger::instance(); _logger && _logger->isEnabled()) { \
            _logger->debug(msg); \
        } else { \
            qDebug() << msg; \
        } \
    } while (0)

#define LOG_INFO(msg) \
    do { \
        if (auto* _logger = ClipLLM::Core::DebugLogger::instance(); _logger && _logger->isEnabled()) { \
            _logger->info(msg); \
        } else { \
            qDebug() << msg; \
        } \
    } while (0)

#define LOG_WARNING(msg) \
    do { \
        if (auto* _logger = ClipLLM::Core::DebugLogger::instance(); _logger && _logger->isEnabled()) { \
            _logger->warning(msg); \
        } else { \
            qWarning() << msg; \
        } \
    } while (0)

#define LOG_ERROR(msg) \
    do { \
        if (auto* _logger = ClipLLM::Core::DebugLogger::instance(); _logger && _logger->isEnabled()) { \
            _logger->error(msg); \
        } else { \
            qCritical() << msg; \
        } \
    } while (0)

// For trace-level logging (only in Trace mode)
#define LOG_TRACE(msg) \
    do { \
        if (auto* _logger = ClipLLM::Core::DebugLogger::instance(); _logger && _logger->currentLevel() >= ClipLLM::Core::DebugLevel::Trace) { \
            _logger->trace(msg); \
        } \
    } while (0)

#endif // CLIPLLM_CORE_DEBUGLOGGER_H
