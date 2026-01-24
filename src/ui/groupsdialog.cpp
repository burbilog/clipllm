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

#include "groupsdialog.h"
#include "core/groupsmanager.h"
#include "core/promptmanager.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QInputDialog>
#include <QCloseEvent>
#include <QSettings>
#include <QMenu>

namespace ClipLLM {
namespace UI {

GroupsDialog::GroupsDialog(Core::GroupsManager* groupsManager,
                          Core::PromptManager* promptManager,
                          QWidget* parent)
    : QDialog(parent)
    , m_groupsManager(groupsManager)
    , m_promptManager(promptManager)
{
    setupUi();
    buildTree();
    expandAll();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("groupsDialog").toByteArray());
    settings.endGroup();
}

void GroupsDialog::setupUi()
{
    resize(500, 400);
    setWindowTitle(tr("Manage Groups"));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Help text
    QLabel* helpLabel = new QLabel(
        tr("Right-click to add, rename, or delete groups. Drag and drop to move groups.")
    );
    helpLabel->setWordWrap(true);
    helpLabel->setStyleSheet("color: gray; padding: 5px;");
    mainLayout->addWidget(helpLabel);

    // Tree widget
    m_treeWidget = new QTreeWidget();
    m_treeWidget->setHeaderLabels(QStringList() << tr("Group Name"));
    m_treeWidget->setRootIsDecorated(true);
    m_treeWidget->setAlternatingRowColors(true);
    m_treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    m_treeWidget->setEditTriggers(QAbstractItemView::EditKeyPressed | QAbstractItemView::SelectedClicked);
    m_treeWidget->setDragEnabled(true);
    m_treeWidget->setAcceptDrops(true);
    m_treeWidget->setDragDropMode(QAbstractItemView::InternalMove);

    // Hide the header
    m_treeWidget->header()->hide();

    connect(m_treeWidget, &QTreeWidget::itemChanged,
            this, &GroupsDialog::onItemChanged);
    connect(m_treeWidget, &QTreeWidget::customContextMenuRequested,
            this, &GroupsDialog::showContextMenu);

    mainLayout->addWidget(m_treeWidget);

    // Close button
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    m_closeButton = new QPushButton(tr("Close"));
    connect(m_closeButton, &QPushButton::clicked, this, &QDialog::accept);
    buttonLayout->addWidget(m_closeButton);

    mainLayout->addLayout(buttonLayout);
}

void GroupsDialog::buildTree()
{
    m_updating = true;
    m_treeWidget->clear();

    // Create virtual root item
    m_rootItem = new QTreeWidgetItem(m_treeWidget);
    m_rootItem->setText(0, tr("Root"));
    m_rootItem->setData(0, Qt::UserRole, QString());
    m_rootItem->setFlags(m_rootItem->flags() & ~Qt::ItemIsEditable & ~Qt::ItemIsDragEnabled);
    QFont rootFont = m_rootItem->font(0);
    rootFont.setBold(true);
    m_rootItem->setFont(0, rootFont);

    // Load groups
    QStringList groups = m_groupsManager->loadGroups();

    // Sort groups
    groups.sort(Qt::CaseInsensitive);

    // Build tree structure
    for (const QString& group : groups) {
        if (group.isEmpty()) {
            continue;
        }

        QStringList parts = group.split(QLatin1Char('/'));
        QTreeWidgetItem* parent = m_rootItem;
        QString currentPath;

        for (int i = 0; i < parts.size(); ++i) {
            QString part = parts[i];
            if (part.isEmpty()) {
                continue;
            }

            currentPath = currentPath.isEmpty() ? part : currentPath + QLatin1Char('/') + part;

            // Look for existing item
            QTreeWidgetItem* foundItem = nullptr;
            for (int j = 0; j < parent->childCount(); ++j) {
                QTreeWidgetItem* child = parent->child(j);
                if (child->text(0) == part) {
                    foundItem = child;
                    break;
                }
            }

            if (!foundItem) {
                foundItem = new QTreeWidgetItem(parent);
                foundItem->setText(0, part);
                foundItem->setData(0, Qt::UserRole, currentPath);
                foundItem->setFlags(foundItem->flags() | Qt::ItemIsEditable);
            }

            parent = foundItem;
        }
    }

    m_rootItem->setExpanded(true);
    m_updating = false;
}

void GroupsDialog::saveTree()
{
    QStringList groups;

    // Recursively collect all group paths
    std::function<void(QTreeWidgetItem*, const QString&)> collectGroups;
    collectGroups = [&](QTreeWidgetItem* item, const QString& parentPath) {
        for (int i = 0; i < item->childCount(); ++i) {
            QTreeWidgetItem* child = item->child(i);
            QString name = child->text(0);
            QString path = parentPath.isEmpty() ? name : parentPath + QLatin1Char('/') + name;
            groups.append(path);

            // Recurse into children
            if (child->childCount() > 0) {
                collectGroups(child, path);
            }
        }
    };

    collectGroups(m_rootItem, QString());

    m_groupsManager->saveGroups(groups);
}

void GroupsDialog::expandAll()
{
    m_treeWidget->expandAll();
}

void GroupsDialog::showContextMenu(const QPoint& pos)
{
    QTreeWidgetItem* item = m_treeWidget->itemAt(pos);

    QMenu menu(this);

    if (item == m_rootItem || !item) {
        // Right-click on root or empty space - "New Group"
        QAction* newGroupAction = menu.addAction(tr("New Group..."));
        connect(newGroupAction, &QAction::triggered, this, &GroupsDialog::onNewGroup);
    } else {
        // Right-click on a group
        QAction* newSubgroupAction = menu.addAction(tr("New Subgroup..."));
        connect(newSubgroupAction, &QAction::triggered, this, &GroupsDialog::onNewSubgroup);

        QAction* renameAction = menu.addAction(tr("Rename..."));
        connect(renameAction, &QAction::triggered, this, &GroupsDialog::onRename);

        menu.addSeparator();

        QAction* deleteAction = menu.addAction(tr("Delete..."));
        connect(deleteAction, &QAction::triggered, this, &GroupsDialog::onDelete);
    }

    menu.exec(m_treeWidget->mapToGlobal(pos));
}

void GroupsDialog::onNewGroup()
{
    bool ok;
    QString name = QInputDialog::getText(
        this, tr("New Group"),
        tr("Enter group name:"),
        QLineEdit::Normal, QString(), &ok
    );

    if (ok && !name.trimmed().isEmpty()) {
        name = name.trimmed();

        // Check for duplicate at root level
        for (int i = 0; i < m_rootItem->childCount(); ++i) {
            if (m_rootItem->child(i)->text(0) == name) {
                QMessageBox::warning(this, tr("Duplicate Group"),
                    tr("A group with this name already exists."));
                return;
            }
        }

        m_updating = true;
        QTreeWidgetItem* newItem = new QTreeWidgetItem(m_rootItem);
        newItem->setText(0, name);
        newItem->setData(0, Qt::UserRole, name);
        newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
        m_updating = false;

        saveTree();
    }
}

void GroupsDialog::onNewSubgroup()
{
    QTreeWidgetItem* item = m_treeWidget->currentItem();
    if (!item || item == m_rootItem) {
        return;
    }

    bool ok;
    QString name = QInputDialog::getText(
        this, tr("New Subgroup"),
        tr("Enter subgroup name:"),
        QLineEdit::Normal, QString(), &ok
    );

    if (ok && !name.trimmed().isEmpty()) {
        name = name.trimmed();

        // Check for duplicate
        for (int i = 0; i < item->childCount(); ++i) {
            if (item->child(i)->text(0) == name) {
                QMessageBox::warning(this, tr("Duplicate Group"),
                    tr("A subgroup with this name already exists."));
                return;
            }
        }

        QString parentPath = getPathFromItem(item);
        QString newPath = parentPath.isEmpty() ? name : parentPath + QLatin1Char('/') + name;

        m_updating = true;
        QTreeWidgetItem* newItem = new QTreeWidgetItem(item);
        newItem->setText(0, name);
        newItem->setData(0, Qt::UserRole, newPath);
        newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
        m_updating = false;

        item->setExpanded(true);

        saveTree();
    }
}

void GroupsDialog::onRename()
{
    QTreeWidgetItem* item = m_treeWidget->currentItem();
    if (!item || item == m_rootItem) {
        return;
    }

    m_treeWidget->editItem(item, 0);
}

void GroupsDialog::onDelete()
{
    QTreeWidgetItem* item = m_treeWidget->currentItem();
    if (!item || item == m_rootItem) {
        return;
    }

    QString path = getPathFromItem(item);
    QString displayName = path.isEmpty() ? tr("(root)") : path;

    // Count prompts in this group
    int promptCount = 0;
    for (const auto& prompt : m_promptManager->getAllPrompts()) {
        if (prompt.group() == path || m_groupsManager->isDescendant(path, prompt.group())) {
            promptCount++;
        }
    }

    QString message;
    if (promptCount > 0) {
        message = tr("Delete group '%1'?\n\n%2 prompt(s) in this group will be moved to root.")
                      .arg(displayName).arg(promptCount);
    } else {
        message = tr("Delete group '%1'?").arg(displayName);
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, tr("Delete Group"), message,
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        // Move prompts to root
        m_promptManager->movePromptsToGroup(path, QString());

        // Collect all descendant paths to remove
        QStringList pathsToRemove;
        std::function<void(QTreeWidgetItem*)> collectDescendants;
        collectDescendants = [&](QTreeWidgetItem* item) {
            pathsToRemove.append(getPathFromItem(item));
            for (int i = 0; i < item->childCount(); ++i) {
                collectDescendants(item->child(i));
            }
        };
        collectDescendants(item);

        // Remove the item
        QTreeWidgetItem* parent = item->parent();
        if (parent) {
            parent->removeChild(item);
        }

        saveTree();
    }
}

void GroupsDialog::onItemChanged(QTreeWidgetItem* item, int column)
{
    if (m_updating || !item || column != 0) {
        return;
    }

    if (item == m_rootItem) {
        return; // Don't allow editing root
    }

    QString newName = item->text(0).trimmed();

    // Check for empty name
    if (newName.isEmpty()) {
        m_updating = true;
        QMessageBox::warning(this, tr("Invalid Name"),
            tr("Group name cannot be empty."));
        // Revert to old name (we need to get it from the stored path)
        QString oldPath = item->data(0, Qt::UserRole).toString();
        QString oldName = m_groupsManager->getLeafName(oldPath);
        item->setText(0, oldName);
        m_updating = false;
        return;
    }

    QString oldPath = item->data(0, Qt::UserRole).toString();
    QString parentPath = m_groupsManager->getParentPath(oldPath);
    QString newPath = parentPath.isEmpty() ? newName : parentPath + QLatin1Char('/') + newName;

    // Check for duplicate
    QTreeWidgetItem* parentItem = item->parent();
    if (parentItem) {
        for (int i = 0; i < parentItem->childCount(); ++i) {
            QTreeWidgetItem* sibling = parentItem->child(i);
            if (sibling != item && sibling->text(0) == newName) {
                m_updating = true;
                QMessageBox::warning(this, tr("Duplicate Name"),
                    tr("A group with this name already exists in this location."));
                QString oldName = m_groupsManager->getLeafName(oldPath);
                item->setText(0, oldName);
                m_updating = false;
                return;
            }
        }
    }

    // Update item data
    item->setData(0, Qt::UserRole, newPath);

    // Update all descendants
    std::function<void(QTreeWidgetItem*, const QString&, const QString&)> updateDescendants;
    updateDescendants = [&](QTreeWidgetItem* item, const QString& oldPrefix, const QString& newPrefix) {
        for (int i = 0; i < item->childCount(); ++i) {
            QTreeWidgetItem* child = item->child(i);
            QString oldChildPath = child->data(0, Qt::UserRole).toString();
            QString newChildPath = oldChildPath;
            newChildPath.replace(0, oldPrefix.length(), newPrefix);
            child->setData(0, Qt::UserRole, newChildPath);

            if (child->childCount() > 0) {
                updateDescendants(child, oldPrefix, newPrefix);
            }
        }
    };

    updateDescendants(item, oldPath, newPath);

    // Update prompts
    m_promptManager->updatePromptGroup(oldPath, newPath);

    saveTree();
}

void GroupsDialog::closeEvent(QCloseEvent* event)
{
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("groupsDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

QTreeWidgetItem* GroupsDialog::findItemByPath(const QString& path)
{
    if (path.isEmpty()) {
        return m_rootItem;
    }

    std::function<QTreeWidgetItem*(QTreeWidgetItem*, const QStringList&, int)> search;
    search = [&](QTreeWidgetItem* parent, const QStringList& parts, int index) -> QTreeWidgetItem* {
        if (index >= parts.size()) {
            return parent;
        }

        QString part = parts[index];
        for (int i = 0; i < parent->childCount(); ++i) {
            QTreeWidgetItem* child = parent->child(i);
            if (child->text(0) == part) {
                return search(child, parts, index + 1);
            }
        }

        return nullptr;
    };

    return search(m_rootItem, path.split(QLatin1Char('/')), 0);
}

QString GroupsDialog::getPathFromItem(QTreeWidgetItem* item) const
{
    if (!item || item == m_rootItem) {
        return QString();
    }

    QStringList parts;
    QTreeWidgetItem* current = item;
    while (current && current != m_rootItem) {
        parts.prepend(current->text(0));
        current = current->parent();
    }

    return parts.join(QLatin1Char('/'));
}

} // namespace UI
} // namespace ClipLLM
