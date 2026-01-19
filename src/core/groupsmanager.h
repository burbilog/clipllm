#ifndef CLIPAI_CORE_GROUPSMANAGER_H
#define CLIPAI_CORE_GROUPSMANAGER_H

#include <QObject>
#include <QStringList>

namespace ClipAI {
namespace Core {

class GroupsManager : public QObject
{
    Q_OBJECT

public:
    explicit GroupsManager(QObject* parent = nullptr);
    ~GroupsManager() = default;

    // Load and save groups
    QStringList loadGroups();
    bool saveGroups(const QStringList& groups);
    QString getGroupsFilePath() const;

    // Helper methods for path operations
    bool isDescendant(const QString& parent, const QString& child);
    QString getParentPath(const QString& path);
    QString getLeafName(const QString& path);
    QStringList getChildren(const QString& parentPath, const QStringList& allGroups);
    QStringList getSortedGroups(const QStringList& groups = QStringList());

signals:
    void groupsChanged();
};

} // namespace Core
} // namespace ClipAI

#endif // CLIPAI_CORE_GROUPSMANAGER_H
