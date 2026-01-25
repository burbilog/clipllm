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

#include "debuglogger.h"
#include <QStandardPaths>
#include <QDir>
#include <QDateTime>
#include <QApplication>

namespace ClipLLM {
namespace Core {

DebugLogger* DebugLogger::instance()
{
    static DebugLogger logger;
    return &logger;
}

DebugLogger::DebugLogger()
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir(configPath);

    if (!configDir.exists()) {
        configDir.mkpath(QStringLiteral("."));
    }

    QString logPath = configDir.filePath(QStringLiteral("debug.log"));

    // Open log file, truncate on start (clear previous logs)
    m_logFile.setFileName(logPath);
    if (m_logFile.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text)) {
        m_logStream.setDevice(&m_logFile);
        m_logStream.setEncoding(QStringConverter::Utf8);

        // Write startup header
        QString timestamp = QDateTime::currentDateTime().toString(QStringLiteral("[yyyy-MM-dd HH:mm:ss.zzz]"));
        m_logStream << timestamp << " Debug logging started" << Qt::endl;
        m_logStream.flush();
    } else {
        qWarning() << "Failed to open debug log file:" << logPath;
    }
}

DebugLogger::~DebugLogger()
{
    if (m_logFile.isOpen()) {
        QString timestamp = QDateTime::currentDateTime().toString(QStringLiteral("[yyyy-MM-dd HH:mm:ss.zzz]"));
        m_logStream << timestamp << " Debug logging stopped" << Qt::endl;
        m_logStream.flush();
        m_logFile.close();
    }
}

void DebugLogger::log(const QString& message, DebugLevel level)
{
    if (m_level == DebugLevel::Off) {
        return;
    }

    if (level == DebugLevel::Trace && m_level < DebugLevel::Trace) {
        return;
    }

    writeLog(message);
}

void DebugLogger::trace(const QString& message)
{
    if (m_level >= DebugLevel::Trace) {
        writeLog(message);
    }
}

DebugLevel DebugLogger::currentLevel() const
{
    return m_level;
}

void DebugLogger::setLevel(DebugLevel level)
{
    m_level = level;
}

bool DebugLogger::isEnabled() const
{
    return m_level != DebugLevel::Off;
}

void DebugLogger::debug(const QString& message)
{
    log(message, DebugLevel::Normal);
}

void DebugLogger::info(const QString& message)
{
    log(message, DebugLevel::Normal);
}

void DebugLogger::warning(const QString& message)
{
    log(QStringLiteral("WARNING: %1").arg(message), DebugLevel::Normal);
}

void DebugLogger::error(const QString& message)
{
    log(QStringLiteral("ERROR: %1").arg(message), DebugLevel::Normal);
}

void DebugLogger::writeLog(const QString& message)
{
    if (!m_logFile.isOpen()) {
        return;
    }

    QMutexLocker locker(&m_mutex);

    QString timestamp = QDateTime::currentDateTime().toString(QStringLiteral("[yyyy-MM-dd HH:mm:ss.zzz]"));
    m_logStream << timestamp << " " << message << Qt::endl;
    m_logStream.flush();
}

} // namespace Core
} // namespace ClipLLM
