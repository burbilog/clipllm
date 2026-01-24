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

#ifndef CLIPLLM_UI_GROUPSDIALOG_H
#define CLIPLLM_UI_GROUPSDIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>

namespace ClipLLM {

namespace Core {
class GroupsManager;
class PromptManager;
}

namespace UI {

class GroupsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GroupsDialog(Core::GroupsManager* groupsManager,
                         Core::PromptManager* promptManager,
                         QWidget* parent = nullptr);
    ~GroupsDialog() = default;

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onNewGroup();
    void onNewSubgroup();
    void onRename();
    void onDelete();
    void onItemChanged(QTreeWidgetItem* item, int column);
    void showContextMenu(const QPoint& pos);

private:
    void setupUi();
    void buildTree();
    void saveTree();
    QTreeWidgetItem* findItemByPath(const QString& path);
    QString getPathFromItem(QTreeWidgetItem* item) const;
    QTreeWidgetItem* getParentItem(const QString& parentPath);
    void expandAll();

    Core::GroupsManager* m_groupsManager = nullptr;
    Core::PromptManager* m_promptManager = nullptr;

    QTreeWidget* m_treeWidget = nullptr;
    QPushButton* m_closeButton = nullptr;

    bool m_updating = false;
    QTreeWidgetItem* m_rootItem = nullptr;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_GROUPSDIALOG_H
