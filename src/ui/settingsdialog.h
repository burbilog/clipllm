#ifndef CLIPAI_UI_SETTINGSDIALOG_H
#define CLIPAI_UI_SETTINGSDIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QCheckBox>
#include <QTextEdit>
#include <QTableWidget>
#include <QLabel>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "core/promptmanager.h"

namespace ClipAI {
namespace Core {
class ConfigManager;
class KeychainStore;
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
    void onProviderChanged(int index);
    void onModelChanged(int index);
    void onApiKeyChanged();
    void onTestConnectionClicked();
    void onRefreshModelsClicked();
    void onModelsFetchFinished(QNetworkReply* reply);

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

    // History tab
    void onClearHistoryClicked();
    void onHistoryLimitChanged(int value);
    void onAutoCleanupChanged(int state);
    void onDaysToKeepChanged(int value);

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
    void fetchModelsFromAPI();

    QString getCurrentProvider() const;
    QString getCurrentModel() const;

    Core::ConfigManager* m_configManager = nullptr;
    Core::KeychainStore* m_keychainStore = nullptr;

    // Tab widget
    QTabWidget* m_tabWidget = nullptr;

    // General tab
    QComboBox* m_languageCombo = nullptr;
    QCheckBox* m_autoSaveHistoryCheck = nullptr;

    // LLM tab
    QComboBox* m_providerCombo = nullptr;
    QComboBox* m_modelCombo = nullptr;
    QLineEdit* m_apiKeyEdit = nullptr;
    QLineEdit* m_customUrlEdit = nullptr;
    QLineEdit* m_proxyEdit = nullptr;
    QDoubleSpinBox* m_temperatureSpin = nullptr;
    QCheckBox* m_overrideTemperatureCheck = nullptr;
    QSpinBox* m_maxTokensSpin = nullptr;
    QCheckBox* m_streamCheck = nullptr;
    QPushButton* m_testConnectionButton = nullptr;
    QPushButton* m_refreshModelsButton = nullptr;
    QLabel* m_connectionStatusLabel = nullptr;
    QNetworkAccessManager* m_networkManager = nullptr;

    // Hotkeys tab
    HotkeyEdit* m_hotkeyEdit = nullptr;

    // Prompts tab
    QTableWidget* m_promptsTable = nullptr;
    QPushButton* m_addPromptButton = nullptr;
    QPushButton* m_editPromptButton = nullptr;
    QPushButton* m_deletePromptButton = nullptr;
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
