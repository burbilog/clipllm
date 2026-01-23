// ClipAI - Cross-platform LLM clipboard utility
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

#include "historymanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QUuid>
#include <QDebug>
#include <QCoreApplication>
#include <algorithm>

namespace ClipAI {
namespace Core {

QJsonObject HistoryEntry::toJson() const
{
    QJsonObject obj;
    obj[QStringLiteral("id")] = id;
    obj[QStringLiteral("timestamp")] = timestamp.toString(Qt::ISODate);
    obj[QStringLiteral("prompt_id")] = promptId;
    obj[QStringLiteral("prompt_name")] = promptName;
    obj[QStringLiteral("provider")] = provider;
    obj[QStringLiteral("model")] = model;
    obj[QStringLiteral("content_type")] = contentType == HistoryEntryType::Text ? QStringLiteral("text") :
                                         contentType == HistoryEntryType::Image ? QStringLiteral("image") :
                                         QStringLiteral("html");
    obj[QStringLiteral("input_text")] = inputText;
    obj[QStringLiteral("input_base64_image")] = inputBase64Image;
    obj[QStringLiteral("output_text")] = outputText;
    obj[QStringLiteral("input_tokens")] = inputTokens;
    obj[QStringLiteral("output_tokens")] = outputTokens;
    obj[QStringLiteral("duration_ms")] = durationMs;
    obj[QStringLiteral("favorite")] = favorite;
    obj[QStringLiteral("tags")] = tags;
    return obj;
}

HistoryEntry HistoryEntry::fromJson(const QJsonObject& json)
{
    HistoryEntry entry;
    entry.id = json.value(QStringLiteral("id")).toString();
    entry.timestamp = QDateTime::fromString(json.value(QStringLiteral("timestamp")).toString(), Qt::ISODate);
    entry.promptId = json.value(QStringLiteral("prompt_id")).toString();
    entry.promptName = json.value(QStringLiteral("prompt_name")).toString();
    entry.provider = json.value(QStringLiteral("provider")).toString();
    entry.model = json.value(QStringLiteral("model")).toString();

    QString typeStr = json.value(QStringLiteral("content_type")).toString();
    if (typeStr == QStringLiteral("text")) {
        entry.contentType = HistoryEntryType::Text;
    } else if (typeStr == QStringLiteral("image")) {
        entry.contentType = HistoryEntryType::Image;
    } else {
        entry.contentType = HistoryEntryType::Html;
    }

    entry.inputText = json.value(QStringLiteral("input_text")).toString();
    entry.inputBase64Image = json.value(QStringLiteral("input_base64_image")).toString();
    entry.outputText = json.value(QStringLiteral("output_text")).toString();
    entry.inputTokens = json.value(QStringLiteral("input_tokens")).toInt();
    entry.outputTokens = json.value(QStringLiteral("output_tokens")).toInt();
    entry.durationMs = json.value(QStringLiteral("duration_ms")).toDouble();
    entry.favorite = json.value(QStringLiteral("favorite")).toBool();
    entry.tags = json.value(QStringLiteral("tags")).toString();

    return entry;
}

QString HistoryEntry::getInputPreview(int maxLength) const
{
    QString preview;
    if (contentType == HistoryEntryType::Image && !inputBase64Image.isEmpty()) {
        preview = QCoreApplication::translate("HistoryEntry", "[Image: %1 bytes]").arg(inputBase64Image.length());
    } else if (!inputText.isEmpty()) {
        preview = inputText;
    } else {
        preview = QCoreApplication::translate("HistoryEntry", "[Empty]");
    }

    if (preview.length() > maxLength) {
        return preview.left(maxLength) + QStringLiteral("...");
    }
    return preview;
}

QString HistoryEntry::getOutputPreview(int maxLength) const
{
    if (outputText.isEmpty()) {
        return QCoreApplication::translate("HistoryEntry", "[Empty]");
    }

    QString preview = outputText;
    if (preview.length() > maxLength) {
        return preview.left(maxLength) + QStringLiteral("...");
    }
    return preview;
}

HistoryManager::HistoryManager(QObject* parent)
    : QObject(parent)
{
}

HistoryManager::~HistoryManager()
{
    flush();
}

bool HistoryManager::initialize()
{
    return loadFromFile();
}

void HistoryManager::flush()
{
    if (m_dirty) {
        saveToFile();
        m_dirty = false;
    }
}

QString HistoryManager::addEntry(const HistoryEntry& entry)
{
    HistoryEntry newEntry = entry;

    // Generate ID if not provided
    if (newEntry.id.isEmpty()) {
        newEntry.id = generateId();
    }

    // Set timestamp if not provided
    if (!newEntry.timestamp.isValid()) {
        newEntry.timestamp = QDateTime::currentDateTime();
    }

    m_entries.append(newEntry);
    m_dirty = true;

    // Enforce max entries limit
    while (m_entries.size() > m_maxEntries) {
        m_entries.removeFirst();
    }

    emit entryAdded(newEntry.id);

    return newEntry.id;
}

bool HistoryManager::updateEntry(const QString& id, const HistoryEntry& entry)
{
    for (int i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].id == id) {
            m_entries[i] = entry;
            m_dirty = true;
            emit entryUpdated(id);
            return true;
        }
    }
    return false;
}

bool HistoryManager::removeEntry(const QString& id)
{
    for (int i = 0; i < m_entries.size(); ++i) {
        if (m_entries[i].id == id) {
            m_entries.removeAt(i);
            m_dirty = true;
            emit entryRemoved(id);
            return true;
        }
    }
    return false;
}

std::optional<HistoryEntry> HistoryManager::getEntry(const QString& id) const
{
    for (const auto& entry : m_entries) {
        if (entry.id == id) {
            return entry;
        }
    }
    return std::nullopt;
}

QVector<HistoryEntry> HistoryManager::getAllEntries() const
{
    return m_entries;
}

QVector<HistoryEntry> HistoryManager::getFilteredEntries(const HistoryFilter& filter) const
{
    QVector<HistoryEntry> result;

    for (const auto& entry : m_entries) {
        // Date range filter
        if (filter.startDate.isValid() && entry.timestamp < filter.startDate) {
            continue;
        }
        if (filter.endDate.isValid() && entry.timestamp > filter.endDate) {
            continue;
        }

        // Model filter
        if (!filter.model.isEmpty() && entry.model != filter.model) {
            continue;
        }

        // Prompt filter
        if (!filter.promptId.isEmpty() && entry.promptId != filter.promptId) {
            continue;
        }

        // Favorites filter
        if (filter.favoritesOnly && !entry.favorite) {
            continue;
        }

        // Search text filter
        if (!filter.searchText.isEmpty()) {
            QString searchLower = filter.searchText.toLower();
            if (!entry.inputText.toLower().contains(searchLower) &&
                !entry.outputText.toLower().contains(searchLower) &&
                !entry.promptName.toLower().contains(searchLower)) {
                continue;
            }
        }

        // Tags filter
        if (!filter.tags.isEmpty()) {
            bool hasAllTags = true;
            for (const QString& tag : filter.tags) {
                if (!entry.tags.contains(tag, Qt::CaseInsensitive)) {
                    hasAllTags = false;
                    break;
                }
            }
            if (!hasAllTags) {
                continue;
            }
        }

        result.append(entry);
    }

    // Sort by timestamp descending (newest first)
    std::sort(result.begin(), result.end(),
              [](const HistoryEntry& a, const HistoryEntry& b) {
                  return a.timestamp > b.timestamp;
              });

    return result;
}

QVector<HistoryEntry> HistoryManager::search(const QString& query) const
{
    HistoryFilter filter;
    filter.searchText = query;
    return getFilteredEntries(filter);
}

QVector<HistoryEntry> HistoryManager::getFavorites() const
{
    HistoryFilter filter;
    filter.favoritesOnly = true;
    return getFilteredEntries(filter);
}

QVector<HistoryEntry> HistoryManager::getRecent(int count) const
{
    QVector<HistoryEntry> recent = m_entries;
    std::sort(recent.begin(), recent.end(),
              [](const HistoryEntry& a, const HistoryEntry& b) {
                  return a.timestamp > b.timestamp;
              });

    if (recent.size() > count) {
        recent.resize(count);
    }
    return recent;
}

int HistoryManager::getTotalEntries() const
{
    return m_entries.size();
}

int HistoryManager::getEntriesCount(const QDateTime& since) const
{
    int count = 0;
    for (const auto& entry : m_entries) {
        if (entry.timestamp >= since) {
            ++count;
        }
    }
    return count;
}

QVector<QPair<QString, int>> HistoryManager::getModelUsage() const
{
    QMap<QString, int> usage;
    for (const auto& entry : m_entries) {
        usage[entry.model]++;
    }

    QVector<QPair<QString, int>> result;
    for (auto it = usage.constBegin(); it != usage.constEnd(); ++it) {
        result.append(qMakePair(it.key(), it.value()));
    }

    std::sort(result.begin(), result.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;
              });

    return result;
}

QVector<QPair<QString, int>> HistoryManager::getPromptUsage() const
{
    QMap<QString, int> usage;
    for (const auto& entry : m_entries) {
        usage[entry.promptName]++;
    }

    QVector<QPair<QString, int>> result;
    for (auto it = usage.constBegin(); it != usage.constEnd(); ++it) {
        result.append(qMakePair(it.key(), it.value()));
    }

    std::sort(result.begin(), result.end(),
              [](const QPair<QString, int>& a, const QPair<QString, int>& b) {
                  return a.second > b.second;
              });

    return result;
}

bool HistoryManager::clearAll()
{
    m_entries.clear();
    m_dirty = true;
    emit historyCleared();
    return saveToFile();
}

bool HistoryManager::clearBefore(const QDateTime& date)
{
    bool removed = false;
    for (int i = m_entries.size() - 1; i >= 0; --i) {
        if (m_entries[i].timestamp < date) {
            m_entries.removeAt(i);
            removed = true;
        }
    }

    if (removed) {
        m_dirty = true;
    }
    return removed;
}

bool HistoryManager::clearOlderThan(int days)
{
    QDateTime cutoff = QDateTime::currentDateTime().addDays(-days);
    return clearBefore(cutoff);
}

int HistoryManager::optimize()
{
    // Remove duplicates, compress data, etc.
    // For now, just enforce limit
    int removed = 0;
    while (m_entries.size() > m_maxEntries) {
        m_entries.removeFirst();
        ++removed;
    }

    if (removed > 0) {
        m_dirty = true;
    }

    return removed;
}

int HistoryManager::cleanupByCount(int maxEntries)
{
    if (maxEntries <= 0) {
        return 0; // No limit
    }

    int removed = 0;
    // Sort by timestamp (oldest first) to remove oldest entries
    // Since we want to keep the most recent ones, we need to find entries to remove
    if (m_entries.size() > maxEntries) {
        // Sort entries by timestamp ascending (oldest first)
        std::sort(m_entries.begin(), m_entries.end(),
                  [](const HistoryEntry& a, const HistoryEntry& b) {
                      return a.timestamp < b.timestamp;
                  });

        // Remove oldest entries (at the beginning after sorting)
        int toRemove = m_entries.size() - maxEntries;
        for (int i = 0; i < toRemove; ++i) {
            m_entries.removeFirst();
            ++removed;
        }

        if (removed > 0) {
            m_dirty = true;
        }
    }

    return removed;
}

int HistoryManager::cleanupByDate(int days)
{
    QDateTime cutoff = QDateTime::currentDateTime().addDays(-days);
    int removed = 0;

    // Use std::remove_if pattern for efficient removal
    auto newEnd = std::remove_if(m_entries.begin(), m_entries.end(),
        [&cutoff, &removed](const HistoryEntry& entry) {
            if (entry.timestamp < cutoff) {
                ++removed;
                return true;
            }
            return false;
        });

    if (removed > 0) {
        m_entries.erase(newEnd, m_entries.end());
        m_dirty = true;
    }

    return removed;
}

QString HistoryManager::exportToJson(const HistoryFilter& filter) const
{
    QJsonArray array;

    QVector<HistoryEntry> entries = filter.startDate.isValid() || filter.endDate.isValid() ||
                                    !filter.model.isEmpty() || !filter.promptId.isEmpty() ||
                                    !filter.searchText.isEmpty() || filter.favoritesOnly ?
                                     getFilteredEntries(filter) : m_entries;

    for (const auto& entry : entries) {
        array.append(entry.toJson());
    }

    QJsonDocument doc(array);
    return doc.toJson(QJsonDocument::Indented);
}

bool HistoryManager::importFromJson(const QString& jsonData)
{
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData.toUtf8(), &error);

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse JSON for import:" << error.errorString();
        return false;
    }

    if (!doc.isArray()) {
        qWarning() << "Import JSON is not an array";
        return false;
    }

    QJsonArray array = doc.array();
    int imported = 0;

    for (const QJsonValue& value : array) {
        if (value.isObject()) {
            HistoryEntry entry = HistoryEntry::fromJson(value.toObject());
            addEntry(entry);
            ++imported;
        }
    }

    m_dirty = true;
    qDebug() << "Imported" << imported << "history entries";
    return true;
}

bool HistoryManager::toggleFavorite(const QString& id)
{
    for (auto& entry : m_entries) {
        if (entry.id == id) {
            entry.favorite = !entry.favorite;
            m_dirty = true;
            emit entryUpdated(id);
            return true;
        }
    }
    return false;
}

bool HistoryManager::isFavorite(const QString& id) const
{
    for (const auto& entry : m_entries) {
        if (entry.id == id) {
            return entry.favorite;
        }
    }
    return false;
}

bool HistoryManager::loadFromFile()
{
    QString path = getHistoryFilePath();
    QFile file(path);

    if (!file.exists()) {
        qDebug() << "History file does not exist, starting with empty history";
        return true;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open history file:" << path;
        return false;
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse history file:" << error.errorString();
        return false;
    }

    if (!doc.isArray()) {
        qWarning() << "History file is not an array";
        return false;
    }

    m_entries.clear();
    QJsonArray array = doc.array();

    for (const QJsonValue& value : array) {
        if (value.isObject()) {
            m_entries.append(HistoryEntry::fromJson(value.toObject()));
        }
    }

    qDebug() << "Loaded" << m_entries.size() << "history entries";
    m_dirty = false;
    return true;
}

bool HistoryManager::saveToFile()
{
    QString path = getHistoryFilePath();

    // Ensure directory exists
    QFileInfo fileInfo(path);
    QDir dir = fileInfo.dir();
    if (!dir.exists()) {
        dir.mkpath(QStringLiteral("."));
    }

    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open history file for writing:" << path;
        return false;
    }

    QJsonArray array;
    for (const auto& entry : m_entries) {
        array.append(entry.toJson());
    }

    QJsonDocument doc(array);
    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    m_dirty = false;
    return true;
}

QString HistoryManager::generateId() const
{
    return QUuid::createUuid().toString(QUuid::WithoutBraces);
}

QString HistoryManager::getHistoryFilePath() const
{
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    return dataPath + QStringLiteral("/history.json");
}

} // namespace Core
} // namespace ClipAI
