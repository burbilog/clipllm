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

#ifndef CLIPAI_CORE_APP_H
#define CLIPAI_CORE_APP_H

#include <QApplication>
#include <QSystemTrayIcon>
#include <QTranslator>
#include <memory>
#include <QKeySequence>

// Forward declarations
class QHotkey;

namespace ClipAI {

class App;

namespace Models {
class ProviderProfile;
class LLMConfig;
}

namespace Core {
class ClipboardManager;
class LLMClient;
class PromptManager;
class ConfigManager;
class KeychainStore;
class HistoryManager;
class GroupsManager;
class ProviderKeyStore;
}

namespace UI {
class TrayIcon;
class SettingsDialog;
class HistoryDialog;
class ResultDialog;
class PromptMenu;
}

class App : public QApplication
{
    Q_OBJECT

public:
    explicit App(int &argc, char **argv);
    ~App();

    // Initialize all components
    bool initialize(bool startMinimized = false);

    // Check if this is a secondary instance
    bool isSecondary() const;

    // Get component instances
    Core::ClipboardManager* clipboardManager() const;
    Core::LLMClient* llmClient() const;
    Core::PromptManager* promptManager() const;
    Core::ConfigManager* configManager() const;
    Core::KeychainStore* keychainStore() const;
    Core::HistoryManager* historyManager() const;
    Core::GroupsManager* groupsManager() const;
    Core::ProviderKeyStore* providerKeyStore() const;

    // Language management
    void setLanguage(const QString& languageCode);
    QString currentLanguage() const { return m_currentLanguage; }

    // Hotkey management
    void registerHotkey(const QKeySequence& sequence);

    // UI management
    void showSettings();
    void showHistory();
    void showTrayMessage(const QString& title, const QString& message);

public slots:
    void showPromptMenuAtTray();

signals:
    void languageChanged(const QString& languageCode);
    void hotkeyTriggered();

private slots:
    void onHotkeyTriggered();
    void onPromptSelected(const QString& promptId);
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onAboutToQuit();

private:
    bool setupTranslations();
    void cleanupTranslations();
    QString getDefaultLanguage() const;

    // Profile to LLM config conversion with cascade logic
    Models::LLMConfig profileToConfig(const Models::ProviderProfile& profile) const;

    // Core components
    std::unique_ptr<Core::ClipboardManager> m_clipboardManager;
    std::unique_ptr<Core::LLMClient> m_llmClient;
    std::unique_ptr<Core::PromptManager> m_promptManager;
    std::unique_ptr<Core::ConfigManager> m_configManager;
    std::unique_ptr<Core::KeychainStore> m_keychainStore;
    std::unique_ptr<Core::HistoryManager> m_historyManager;
    std::unique_ptr<Core::GroupsManager> m_groupsManager;
    std::unique_ptr<Core::ProviderKeyStore> m_providerKeyStore;

    // UI components
    std::unique_ptr<UI::TrayIcon> m_trayIcon;

    // Dialogs (created on demand)
    UI::SettingsDialog* m_settingsDialog = nullptr;
    UI::HistoryDialog* m_historyDialog = nullptr;
    UI::ResultDialog* m_resultDialog = nullptr;
    UI::PromptMenu* m_promptMenu = nullptr;

    // Translators
    std::vector<QTranslator*> m_translators;
    QString m_currentLanguage;

    // Global hotkey
    QHotkey* m_globalHotkey = nullptr;

    // Single instance
    QByteArray m_instanceId;
};

} // namespace ClipAI

#endif // CLIPAI_CORE_APP_H
