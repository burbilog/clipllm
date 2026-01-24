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
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_UI_PROMPTMENU_H
#define CLIPLLM_UI_PROMPTMENU_H

#include <QMenu>
#include <QLineEdit>
#include <QWidgetAction>
#include <QVBoxLayout>
#include "core/promptmanager.h"
#include "models/prompt.h"

namespace ClipLLM {
namespace Core {
class ClipboardManager;
class ConfigManager;
}
}

namespace ClipLLM {
namespace UI {

class PromptMenu : public QMenu
{
    Q_OBJECT

public:
    explicit PromptMenu(Core::PromptManager* promptManager,
                       Core::ClipboardManager* clipboardManager,
                       Core::ConfigManager* configManager,
                       QWidget* parent = nullptr);
    ~PromptMenu();

    void setContentTypeFilter(Models::ContentType type);
    void showMenu(const QPoint& pos = QPoint());

signals:
    void promptSelected(const QString& promptId);
    void cancelled();
    void settingsRequested();
    void historyRequested();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void showEvent(QShowEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;
    void hideEvent(QHideEvent* event) override;

private slots:
    void onPromptTriggered();
    void onSearchTextChanged(const QString& text);
    void onPrevItem();
    void onNextItem();
    void selectCurrentItem();
    void onSettingsClicked();
    void onHistoryClicked();

private:
    void setupUi();
    void rebuildMenu();
    void filterMenu(const QString& filter = QString());
    int getSelectedIndex() const;
    void setSelectedIndex(int index);
    QAction* createPromptAction(const Models::Prompt& prompt);

    Core::PromptManager* m_promptManager = nullptr;
    Core::ClipboardManager* m_clipboardManager = nullptr;
    Core::ConfigManager* m_configManager = nullptr;

    QLineEdit* m_searchEdit = nullptr;
    QWidgetAction* m_searchAction = nullptr;
    QAction* m_separatorAction = nullptr;

    QVector<QAction*> m_promptActions;
    QVector<QString> m_promptIds;
    int m_selectedIndex = -1;

    Models::ContentType m_contentTypeFilter = Models::ContentType::Any;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_PROMPTMENU_H
