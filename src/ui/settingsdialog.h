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

#ifndef CLIPLLM_UI_SETTINGSDIALOG_H
#define CLIPLLM_UI_SETTINGSDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QTabWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QTableWidget>
#include <QLabel>
#include <QGroupBox>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QListWidget>
#include <QPushButton>
#include "core/promptmanager.h"
#include "models/providerprofile.h"

namespace ClipLLM {
namespace Core {
class ConfigManager;
class KeychainStore;
class ProviderKeyStore;
class LLMClient;
}
}

namespace ClipLLM {
namespace UI {

class HotkeyEdit;

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget* parent = nullptr);
    ~SettingsDialog();

    void loadSettings();
    void saveSettings();

signals:
    void settingsChanged();
    void languageChanged(const QString& language);
    void hotkeyChanged(const QKeySequence& hotkey);
    void promptsChanged();

private slots:
    void onTabChanged(int index);
    void onOkClicked();
    void onResetClicked();

    // General tab
    void onLanguageChanged(int index);

    // LLM tab
    void onProfileSelectionChanged();
    void onAddProfileClicked();
    void onRemoveProfileClicked();
    void onSetAsDefaultClicked();
    void onProfileNameChanged(const QString& text);
    void onTemplateChanged(int index);
    void onModelChanged(const QString& text);
    void onApiKeyChanged();
    void onTestConnectionClicked();
    void onConnectionTestResult(bool success, const QString& message);
    void onRefreshModelsClicked();
    void onModelsFetchFinished(QNetworkReply* reply);
    void onProfileEnabledChanged(int state);
    void onGlobalDefaultsChanged();

    // Hotkeys tab
    void onHotkeyChanged(const QKeySequence& sequence);
    void onGlobalHotkeyRecordingFinished();

    // Prompts tab
    void onAddPromptClicked();
    void onEditPromptClicked();
    void onDeletePromptClicked();
    void onImportPromptsClicked();
    void onExportPromptsClicked();
    void onResetPromptsClicked();
    void onPromptSelectionChanged();
    void onManageGroupsClicked();

    // History tab
    void onClearHistoryClicked();
    void onHistoryLimitChanged(int value);
    void onCleanupByCountChanged(int state);
    void onCleanupByDateChanged(int state);
    void onDaysToKeepChanged(int value);

protected:
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private:
    void setupUi();
    void setupGeneralTab();
    void setupLLMTab();
    void setupPromptsTab();
    void setupHistoryTab();

    void loadProviders();
    void loadModels();
    void loadLanguages();
    void loadPrompts();
    void loadProviderProfiles();
    void fetchModelsFromAPI();

    void updateProfileEditor(const Models::ProviderProfile& profile);
    void clearProfileEditor();
    Models::ProviderProfile getCurrentProfileFromEditor() const;
    QString getCurrentProviderId() const;

    // Legacy methods (for compatibility with old code)
    QString getCurrentProvider() const;
    QString getCurrentModel() const;
    bool checkGlobalHotkeyConflict(const QKeySequence& seq) const;

    Core::ConfigManager* m_configManager = nullptr;
    Core::KeychainStore* m_keychainStore = nullptr;
    Core::ProviderKeyStore* m_providerKeyStore = nullptr;

    // Tab widget
    QTabWidget* m_tabWidget = nullptr;

    // General tab
    QComboBox* m_languageCombo = nullptr;
    QCheckBox* m_showDescriptionInMenuCheck = nullptr;
    QCheckBox* m_showDescriptionInPopupCheck = nullptr;
    QCheckBox* m_autoSaveHistoryCheck = nullptr;

    // LLM tab - Provider Profiles
    QListWidget* m_profilesList = nullptr;
    QPushButton* m_addProfileButton = nullptr;
    QPushButton* m_removeProfileButton = nullptr;
    QPushButton* m_setAsDefaultButton = nullptr;
    QLineEdit* m_profileNameEdit = nullptr;
    QLineEdit* m_profileApiUrlEdit = nullptr;
    QComboBox* m_profileTemplateCombo = nullptr;
    QComboBox* m_profileModelCombo = nullptr;
    QPushButton* m_refreshModelsButton = nullptr;
    QLineEdit* m_profileApiKeyEdit = nullptr;
    QPushButton* m_testConnectionButton = nullptr;
    QLabel* m_connectionStatusLabel = nullptr;
    QDoubleSpinBox* m_profileTemperatureSpin = nullptr;
    QSpinBox* m_profileMaxTokensSpin = nullptr;
    QLineEdit* m_profileProxyEdit = nullptr;
    QCheckBox* m_profileEnabledCheck = nullptr;

    // LLM tab - Global Defaults
    QDoubleSpinBox* m_globalTemperatureSpin = nullptr;
    QSpinBox* m_globalMaxTokensSpin = nullptr;

    QNetworkAccessManager* m_networkManager = nullptr;
    QStringList m_currentSuggestedModels;
    Models::ProviderProfile m_currentEditingProfile;
    bool m_updatingProfileEditor = false;

    // Temporary LLM client for connection testing (isolated from app's active client)
    Core::LLMClient* m_testClient = nullptr;

    // Hotkeys tab
    HotkeyEdit* m_hotkeyEdit = nullptr;
    bool m_isRecordingGlobalHotkey = false;

    // Prompts tab
    QTableWidget* m_promptsTable = nullptr;
    QPushButton* m_addPromptButton = nullptr;
    QPushButton* m_editPromptButton = nullptr;
    QPushButton* m_deletePromptButton = nullptr;
    QPushButton* m_manageGroupsButton = nullptr;
    QPushButton* m_importPromptsButton = nullptr;
    QPushButton* m_exportPromptsButton = nullptr;
    QPushButton* m_resetPromptsButton = nullptr;

    // History tab
    QSpinBox* m_historyLimitSpin = nullptr;
    QCheckBox* m_cleanupByCountCheck = nullptr;
    QCheckBox* m_cleanupByDateCheck = nullptr;
    QSpinBox* m_daysToKeepSpin = nullptr;
    QPushButton* m_clearHistoryButton = nullptr;
    QLabel* m_historyStatusLabel = nullptr;

    // Dialog buttons
    QPushButton* m_okButton = nullptr;
    QPushButton* m_cancelButton = nullptr;
    QPushButton* m_resetButton = nullptr;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_SETTINGSDIALOG_H
