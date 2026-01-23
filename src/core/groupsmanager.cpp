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

#include "groupsmanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QRegularExpression>
#include <QDebug>

namespace ClipAI {
namespace Core {

GroupsManager::GroupsManager(QObject* parent)
    : QObject(parent)
{
}

QStringList GroupsManager::loadGroups()
{
    QString filePath = getGroupsFilePath();
    QFile file(filePath);

    if (!file.exists()) {
        // No groups file yet, return empty list
        return QStringList();
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open groups file:" << filePath;
        return QStringList();
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse groups file:" << error.errorString();
        return QStringList();
    }

    if (!doc.isArray()) {
        qWarning() << "Groups file does not contain an array";
        return QStringList();
    }

    QJsonArray groupsArray = doc.array();
    QStringList groups;
    for (const QJsonValue& value : groupsArray) {
        if (value.isString()) {
            groups.append(value.toString());
        }
    }

    return groups;
}

bool GroupsManager::saveGroups(const QStringList& groups)
{
    QString filePath = getGroupsFilePath();

    // Ensure directory exists
    QFileInfo fileInfo(filePath);
    QDir dir = fileInfo.dir();
    if (!dir.exists()) {
        dir.mkpath(QStringLiteral("."));
    }

    QJsonArray groupsArray;
    for (const QString& group : groups) {
        groupsArray.append(group);
    }

    QJsonDocument doc(groupsArray);

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Failed to open groups file for writing:" << filePath;
        return false;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    emit groupsChanged();
    return true;
}

QString GroupsManager::getGroupsFilePath() const
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    return configPath + QStringLiteral("/groups.json");
}

bool GroupsManager::isDescendant(const QString& parent, const QString& child)
{
    if (parent.isEmpty()) {
        return false;
    }

    // Check if child starts with parent + "/"
    // Also handle the case where parent == child (same group)
    if (child == parent) {
        return false; // Not a descendant of itself
    }

    if (child.startsWith(parent + QLatin1Char('/'))) {
        return true;
    }

    return false;
}

QString GroupsManager::getParentPath(const QString& path)
{
    int lastSlash = path.lastIndexOf(QLatin1Char('/'));
    if (lastSlash < 0) {
        return QString(); // Root level
    }
    return path.left(lastSlash);
}

QString GroupsManager::getLeafName(const QString& path)
{
    int lastSlash = path.lastIndexOf(QLatin1Char('/'));
    if (lastSlash < 0) {
        return path;
    }
    return path.mid(lastSlash + 1);
}

QStringList GroupsManager::getChildren(const QString& parentPath, const QStringList& allGroups)
{
    QStringList children;
    QString prefix = parentPath.isEmpty() ? QString() : parentPath + QLatin1Char('/');

    for (const QString& group : allGroups) {
        if (group.startsWith(prefix)) {
            QString remainder = group.mid(prefix.length());
            // Get the first component
            int slash = remainder.indexOf(QLatin1Char('/'));
            if (slash < 0) {
                // Direct child
                children.append(remainder);
            } else {
                // Indirect child (nested), get the first component
                QString firstComponent = remainder.left(slash);
                if (!children.contains(firstComponent)) {
                    children.append(firstComponent);
                }
            }
        }
    }

    children.sort();
    return children;
}

QStringList GroupsManager::getSortedGroups(const QStringList& groups)
{
    if (groups.isEmpty()) {
        return groups;
    }

    QStringList sorted = groups;
    sorted.sort(Qt::CaseInsensitive);

    // We want to sort by path components, so:
    // "Text Processing" comes before "Text Processing/Summarization"
    // This should already be handled by simple string sort due to '/' character

    return sorted;
}

} // namespace Core
} // namespace ClipAI
