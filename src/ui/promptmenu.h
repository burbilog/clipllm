#ifndef CLIPAI_UI_PROMPTMENU_H
#define CLIPAI_UI_PROMPTMENU_H

#include <QMenu>
#include <QLineEdit>
#include <QWidgetAction>
#include <QVBoxLayout>
#include "core/promptmanager.h"
#include "models/prompt.h"

namespace ClipAI {
namespace Core {
class ClipboardManager;
}
}

namespace ClipAI {
namespace UI {

class PromptMenu : public QMenu
{
    Q_OBJECT

public:
    explicit PromptMenu(Core::PromptManager* promptManager,
                       Core::ClipboardManager* clipboardManager,
                       QWidget* parent = nullptr);
    ~PromptMenu();

    void setContentTypeFilter(Models::ContentType type);
    void showMenu(const QPoint& pos = QPoint());

signals:
    void promptSelected(const QString& promptId);
    void cancelled();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void showEvent(QShowEvent* event) override;

private slots:
    void onPromptTriggered();
    void onSearchTextChanged(const QString& text);
    void onPrevItem();
    void onNextItem();
    void selectCurrentItem();

private:
    void setupUi();
    void rebuildMenu();
    void filterMenu(const QString& filter = QString());
    int getSelectedIndex() const;
    void setSelectedIndex(int index);
    QAction* createPromptAction(const Models::Prompt& prompt);

    Core::PromptManager* m_promptManager = nullptr;
    Core::ClipboardManager* m_clipboardManager = nullptr;

    QLineEdit* m_searchEdit = nullptr;
    QWidgetAction* m_searchAction = nullptr;
    QAction* m_separatorAction = nullptr;

    QVector<QAction*> m_promptActions;
    QVector<QString> m_promptIds;
    int m_selectedIndex = -1;

    Models::ContentType m_contentTypeFilter = Models::ContentType::Any;
};

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_PROMPTMENU_H
