#ifndef CLIPAI_UI_TRAYICON_H
#define CLIPAI_UI_TRAYICON_H

#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include "core/promptmanager.h"
#include "models/prompt.h"

namespace ClipAI {

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
} // namespace ClipAI

#endif // CLIPAI_UI_TRAYICON_H
