#ifndef CLIPAI_UI_SETTINGSDIALOG_H
#define CLIPAI_UI_SETTINGSDIALOG_H

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

namespace ClipAI {
namespace Core {
class ConfigManager;
class KeychainStore;
class ProviderKeyStore;
}
}

namespace ClipAI {
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
    void onRefreshModelsClicked();
    void onModelsFetchFinished(QNetworkReply* reply);
    void onProfileEnabledChanged(int state);
    void onGlobalDefaultsChanged();

    // Hotkeys tab
    void onHotkeyChanged(const QKeySequence& sequence);

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
    void onAutoCleanupChanged(int state);
    void onDaysToKeepChanged(int value);

protected:
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;

private:
    void setupUi();
    void setupGeneralTab();
    void setupLLMTab();
    void setupHotkeysTab();
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

    Core::ConfigManager* m_configManager = nullptr;
    Core::KeychainStore* m_keychainStore = nullptr;
    Core::ProviderKeyStore* m_providerKeyStore = nullptr;

    // Tab widget
    QTabWidget* m_tabWidget = nullptr;

    // General tab
    QComboBox* m_languageCombo = nullptr;
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

    // Hotkeys tab
    HotkeyEdit* m_hotkeyEdit = nullptr;

    // Prompts tab
    QSpinBox* m_maxPromptsSpin = nullptr;
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
    QCheckBox* m_autoCleanupCheck = nullptr;
    QSpinBox* m_daysToKeepSpin = nullptr;
    QPushButton* m_clearHistoryButton = nullptr;
    QLabel* m_historyStatusLabel = nullptr;

    // Dialog buttons
    QPushButton* m_okButton = nullptr;
    QPushButton* m_cancelButton = nullptr;
    QPushButton* m_resetButton = nullptr;
};

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_SETTINGSDIALOG_H
