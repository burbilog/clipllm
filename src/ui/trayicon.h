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

#ifndef CLIPLLM_UI_TRAYICON_H
#define CLIPLLM_UI_TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include "core/promptmanager.h"
#include "models/prompt.h"

namespace ClipLLM {

class App;

namespace Core {
class ClipboardManager;
class PromptManager;
}

namespace UI {

class TrayIcon : public QSystemTrayIcon
{
    Q_OBJECT

public:
    explicit TrayIcon(App* app);
    ~TrayIcon();

    void updatePromptsMenu(const QVector<Models::Prompt>& prompts);
    void setHotkeyText(const QString& hotkey);
    void setProcessing(bool processing);

signals:
    void activated(QSystemTrayIcon::ActivationReason reason);
    void showSettingsRequested();
    void showPromptMenuRequested();
    void showHistoryRequested();
    void quitRequested();
    void hotkeyTriggered();
    void promptSelected(const QString& promptId);

public slots:
    void showTrayMessage(const QString& title, const QString& message,
                        QSystemTrayIcon::MessageIcon icon = QSystemTrayIcon::Information, int millisecondsTimeoutHint = 3000);
    void onLanguageChanged(const QString& languageCode);

private slots:
    void onActivated(QSystemTrayIcon::ActivationReason reason);
    void onPromptTriggered();
    void onSettingsTriggered();
    void onHistoryTriggered();
    void onAboutTriggered();
    void onQuitTriggered();
    void onPromptsUpdated();

private:
    void createMenu();
    void createActions();
    void retranslateUi();
    void updateIcon();
    void rebuildPromptsMenu();

    App* m_app;
    QMenu* m_menu = nullptr;
    QMenu* m_promptsMenu = nullptr;

    QAction* m_settingsAction = nullptr;
    QAction* m_historyAction = nullptr;
    QAction* m_separator1 = nullptr;
    QAction* m_separator2 = nullptr;
    QAction* m_aboutAction = nullptr;
    QAction* m_quitAction = nullptr;

    QIcon m_normalIcon;
    QIcon m_activeIcon;
    QIcon m_errorIcon;

    bool m_processing = false;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_TRAYICON_H
