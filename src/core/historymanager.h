#ifndef CLIPAI_CORE_HISTORYMANAGER_H
#define CLIPAI_CORE_HISTORYMANAGER_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QVector>
#include <QJsonObject>
#include <optional>

namespace ClipAI {
namespace Core {

enum class HistoryEntryType {
    Text,
    Image,
    Html
};

struct HistoryEntry
{
    QString id;
    QDateTime timestamp;
    QString promptId;
    QString promptName;
    QString provider;
    QString model;
    HistoryEntryType contentType;
    QString inputText;
    QString inputBase64Image; // For images
    QString outputText;
    int inputTokens;
    int outputTokens;
    double durationMs;
    bool favorite;
    QString tags;

    QJsonObject toJson() const;
    static HistoryEntry fromJson(const QJsonObject& json);
    QString getInputPreview(int maxLength = 100) const;
    QString getOutputPreview(int maxLength = 100) const;
};

struct HistoryFilter
{
    QDateTime startDate;
    QDateTime endDate;
    QString model;
    QString promptId;
    QString searchText;
    bool favoritesOnly = false;
    QVector<QString> tags;
};

class HistoryManager : public QObject
{
    Q_OBJECT

public:
    explicit HistoryManager(QObject* parent = nullptr);
    ~HistoryManager();

    // Initialize history storage
    bool initialize();
    void flush();

    // CRUD operations
    QString addEntry(const HistoryEntry& entry);
    bool updateEntry(const QString& id, const HistoryEntry& entry);
    bool removeEntry(const QString& id);
    std::optional<HistoryEntry> getEntry(const QString& id) const;

    // Query operations
    QVector<HistoryEntry> getAllEntries() const;
    QVector<HistoryEntry> getFilteredEntries(const HistoryFilter& filter) const;
    QVector<HistoryEntry> search(const QString& query) const;
    QVector<HistoryEntry> getFavorites() const;
    QVector<HistoryEntry> getRecent(int count = 20) const;

    // Statistics
    int getTotalEntries() const;
    int getEntriesCount(const QDateTime& since) const;
    QVector<QPair<QString, int>> getModelUsage() const;
    QVector<QPair<QString, int>> getPromptUsage() const;

    // Maintenance
    bool clearAll();
    bool clearBefore(const QDateTime& date);
    bool clearOlderThan(int days);
    int optimize();

    // Export/Import
    QString exportToJson(const HistoryFilter& filter = HistoryFilter()) const;
    bool importFromJson(const QString& jsonData);

    // Favorites
    bool toggleFavorite(const QString& id);
    bool isFavorite(const QString& id) const;

signals:
    void entryAdded(const QString& id);
    void entryUpdated(const QString& id);
    void entryRemoved(const QString& id);
    void historyCleared();

private:
    bool loadFromFile();
    bool saveToFile();
    QString generateId() const;
    QString getHistoryFilePath() const;

    QVector<HistoryEntry> m_entries;
    bool m_dirty = false;
    int m_maxEntries = 1000;
};

} // namespace Core
} // namespace ClipAI

Q_DECLARE_METATYPE(ClipAI::Core::HistoryEntry)
Q_DECLARE_METATYPE(ClipAI::Core::HistoryEntryType)
Q_DECLARE_METATYPE(ClipAI::Core::HistoryFilter)

#endif // CLIPAI_CORE_HISTORYMANAGER_H
