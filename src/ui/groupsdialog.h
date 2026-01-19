#ifndef CLIPAI_UI_GROUPSDIALOG_H
#define CLIPAI_UI_GROUPSDIALOG_H

#include <QDialog>
#include <QTreeWidget>
#include <QTreeWidgetItem>
#include <QPushButton>
#include <QLabel>

namespace ClipAI {

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
} // namespace ClipAI

#endif // CLIPAI_UI_GROUPSDIALOG_H
