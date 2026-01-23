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
