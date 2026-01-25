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

#include "settingsdialog.h"
#include "prompteditordialog.h"
#include "groupsdialog.h"
#include "hotkeyedit.h"
#include "core/app.h"
#include "core/configmanager.h"
#include "core/keychainstore.h"
#include "core/providerkeystore.h"
#include "core/promptmanager.h"
#include "core/groupsmanager.h"
#include "core/historymanager.h"
#include "core/app.h"
#include "core/llmclient.h"
#include "models/llmconfig.h"
#include "models/providerprofile.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
#include <QShowEvent>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>
#include <QInputDialog>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QSettings>
#include <QListWidget>

namespace ClipLLM {
namespace UI {

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent)
    , m_updatingProfileEditor(false)
{
    // Get managers from app
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        m_configManager = app->configManager();
        m_keychainStore = app->keychainStore();
        m_providerKeyStore = app->providerKeyStore();
    }

    // Create network manager for fetching models
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &SettingsDialog::onModelsFetchFinished);

    setupUi();
    loadSettings();
}

SettingsDialog::~SettingsDialog()
{
    delete m_testClient;
}

void SettingsDialog::setupUi()
{
    setWindowTitle(tr("ClipLLM - Settings"));
    resize(700, 550);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Tab widget
    m_tabWidget = new QTabWidget();

    setupGeneralTab();
    setupLLMTab();
    setupPromptsTab();
    setupHistoryTab();

    mainLayout->addWidget(m_tabWidget);

    // Dialog buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_okButton = new QPushButton(tr("OK"));
    m_okButton->setDefault(true);
    connect(m_okButton, &QPushButton::clicked, this, &SettingsDialog::onOkClicked);

    m_cancelButton = new QPushButton(tr("Cancel"));
    connect(m_cancelButton, &QPushButton::clicked, this, [this]() {
        // Save window geometry before closing
        QSettings settings;
        settings.beginGroup("WindowGeometry");
        settings.setValue("settingsDialog", saveGeometry());
        settings.endGroup();
        settings.sync();
        reject();
    });

    m_resetButton = new QPushButton(tr("Reset to Defaults"));
    connect(m_resetButton, &QPushButton::clicked, this, &SettingsDialog::onResetClicked);

    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_okButton);
    buttonLayout->addWidget(m_cancelButton);

    mainLayout->addLayout(buttonLayout);

    connect(m_tabWidget, &QTabWidget::currentChanged, this, &SettingsDialog::onTabChanged);
}

void SettingsDialog::setupGeneralTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QGroupBox* languageGroup = new QGroupBox(tr("Language"));
    QFormLayout* languageLayout = new QFormLayout(languageGroup);

    m_languageCombo = new QComboBox();
    connect(m_languageCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsDialog::onLanguageChanged);

    languageLayout->addRow(tr("Interface Language:"), m_languageCombo);

    layout->addWidget(languageGroup);

    // Global hotkey group
    QGroupBox* hotkeyGroup = new QGroupBox(tr("Global Hotkey"));
    QFormLayout* hotkeyLayout = new QFormLayout(hotkeyGroup);

    m_hotkeyEdit = new HotkeyEdit();
    connect(m_hotkeyEdit, &HotkeyEdit::keySequenceChanged,
            this, &SettingsDialog::onHotkeyChanged);
    connect(m_hotkeyEdit, &HotkeyEdit::recordingStarted, this, [this]() {
        // Unregister prompt hotkeys while recording global hotkey to prevent accidental triggering
        m_isRecordingGlobalHotkey = true;
        App* app = qobject_cast<App*>(QApplication::instance());
        if (app) {
            app->unregisterPromptHotkeys();
        }
    });
    connect(m_hotkeyEdit, &HotkeyEdit::recordingFinished,
            this, &SettingsDialog::onGlobalHotkeyRecordingFinished);

    hotkeyLayout->addRow(tr("Activate Clipboard Processing:"), m_hotkeyEdit);

    QLabel* infoLabel = new QLabel(
        tr("<b>Note:</b> Global hotkeys may not work on Wayland. "
           "On X11, the hotkey works globally. On Windows and macOS, "
           "global hotkeys are fully supported.")
    );
    infoLabel->setWordWrap(true);
    infoLabel->setStyleSheet("font-size: 9pt;");
    hotkeyLayout->addRow(infoLabel);

    layout->addWidget(hotkeyGroup);

    // Miscellaneous group
    QGroupBox* miscGroup = new QGroupBox(tr("Miscellaneous"));
    QVBoxLayout* miscLayout = new QVBoxLayout(miscGroup);

    m_showDescriptionInMenuCheck = new QCheckBox(tr("Show prompt descriptions in menu"));
    m_showDescriptionInMenuCheck->setToolTip(tr("Show prompt descriptions in the tray menu (disabled by default for cleaner menu)"));
    miscLayout->addWidget(m_showDescriptionInMenuCheck);

    m_showDescriptionInPopupCheck = new QCheckBox(tr("Show prompt descriptions in popup"));
    m_showDescriptionInPopupCheck->setToolTip(tr("Show prompt descriptions in the popup menu (disabled by default for cleaner popup)"));
    miscLayout->addWidget(m_showDescriptionInPopupCheck);

    layout->addWidget(miscGroup);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("General"));
}

void SettingsDialog::setupLLMTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    // Provider Profiles section
    QGroupBox* profilesGroup = new QGroupBox(tr("Provider Profiles"));
    QVBoxLayout* profilesLayout = new QVBoxLayout(profilesGroup);

    // Profiles list with buttons
    QHBoxLayout* profilesHeaderLayout = new QHBoxLayout();
    QLabel* profilesLabel = new QLabel(tr("Available Profiles:"));
    profilesHeaderLayout->addWidget(profilesLabel);
    profilesHeaderLayout->addStretch();

    m_addProfileButton = new QPushButton(tr("+ Add"));
    m_addProfileButton->setToolTip(tr("Add a new provider profile"));
    connect(m_addProfileButton, &QPushButton::clicked, this, &SettingsDialog::onAddProfileClicked);
    profilesHeaderLayout->addWidget(m_addProfileButton);

    m_removeProfileButton = new QPushButton(tr("- Remove"));
    m_removeProfileButton->setToolTip(tr("Remove selected profile"));
    connect(m_removeProfileButton, &QPushButton::clicked, this, &SettingsDialog::onRemoveProfileClicked);
    profilesHeaderLayout->addWidget(m_removeProfileButton);

    m_setAsDefaultButton = new QPushButton(tr("Set as Default"));
    m_setAsDefaultButton->setToolTip(tr("Set selected profile as default"));
    connect(m_setAsDefaultButton, &QPushButton::clicked, this, &SettingsDialog::onSetAsDefaultClicked);
    profilesHeaderLayout->addWidget(m_setAsDefaultButton);

    profilesLayout->addLayout(profilesHeaderLayout);

    m_profilesList = new QListWidget();
    m_profilesList->setSelectionMode(QAbstractItemView::SingleSelection);
    connect(m_profilesList, &QListWidget::currentRowChanged,
            this, &SettingsDialog::onProfileSelectionChanged);
    profilesLayout->addWidget(m_profilesList);

    layout->addWidget(profilesGroup);

    // Profile Configuration section
    QGroupBox* configGroup = new QGroupBox(tr("Profile Configuration"));
    QFormLayout* configLayout = new QFormLayout(configGroup);

    m_profileNameEdit = new QLineEdit();
    m_profileNameEdit->setPlaceholderText(tr("e.g., OpenRouter (Main)"));
    connect(m_profileNameEdit, &QLineEdit::textChanged, this, &SettingsDialog::onProfileNameChanged);
    configLayout->addRow(tr("Profile Name:"), m_profileNameEdit);

    // API URL with template dropdown
    QHBoxLayout* urlLayout = new QHBoxLayout();
    m_profileApiUrlEdit = new QLineEdit();
    m_profileApiUrlEdit->setPlaceholderText(tr("Select template or enter custom URL (e.g., http://.../v1/chat/completions)"));
    connect(m_profileApiUrlEdit, &QLineEdit::textChanged, this, [this]() {
        if (m_updatingProfileEditor) {
            return;
        }
        // Update the profile
        Models::ProviderProfile profile = getCurrentProfileFromEditor();
        m_configManager->updateProviderProfile(profile);
    });
    urlLayout->addWidget(m_profileApiUrlEdit, 1);

    m_profileTemplateCombo = new QComboBox();
    m_profileTemplateCombo->addItem(tr("Template..."));
    m_profileTemplateCombo->addItems(Models::ProviderProfile::availableTemplateNames());
    connect(m_profileTemplateCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsDialog::onTemplateChanged);
    urlLayout->addWidget(m_profileTemplateCombo);

    configLayout->addRow(tr("API URL:"), urlLayout);

    // Model combo with refresh
    QHBoxLayout* modelLayout = new QHBoxLayout();
    m_profileModelCombo = new QComboBox();
    m_profileModelCombo->setEditable(true);
    m_profileModelCombo->setPlaceholderText(tr("Select or enter model name..."));
    connect(m_profileModelCombo, &QComboBox::editTextChanged,
            this, &SettingsDialog::onModelChanged);
    modelLayout->addWidget(m_profileModelCombo, 1);

    m_refreshModelsButton = new QPushButton(tr("Refresh"));
    m_refreshModelsButton->setEnabled(false);
    connect(m_refreshModelsButton, &QPushButton::clicked,
            this, &SettingsDialog::onRefreshModelsClicked);
    modelLayout->addWidget(m_refreshModelsButton);

    configLayout->addRow(tr("Model:"), modelLayout);

    m_profileApiKeyEdit = new QLineEdit();
    m_profileApiKeyEdit->setEchoMode(QLineEdit::Password);
    m_profileApiKeyEdit->setPlaceholderText(tr("Leave empty for local providers (e.g., Ollama)"));
    connect(m_profileApiKeyEdit, &QLineEdit::textChanged, this, &SettingsDialog::onApiKeyChanged);
    configLayout->addRow(tr("API Key:"), m_profileApiKeyEdit);

    m_profileProxyEdit = new QLineEdit();
    m_profileProxyEdit->setPlaceholderText(tr("http://host:port or socks5://host:port (optional)"));
    connect(m_profileProxyEdit, &QLineEdit::textChanged, this, [this]() {
        if (m_updatingProfileEditor) {
            return;
        }
        // Update the profile
        Models::ProviderProfile profile = getCurrentProfileFromEditor();
        m_configManager->updateProviderProfile(profile);
    });
    configLayout->addRow(tr("Proxy:"), m_profileProxyEdit);

    // Override Global Defaults section
    QGroupBox* overrideGroup = new QGroupBox(tr("Override Global Defaults (optional, leave empty for default)"));
    QFormLayout* overrideLayout = new QFormLayout(overrideGroup);

    m_profileTemperatureSpin = new QDoubleSpinBox();
    m_profileTemperatureSpin->setRange(0.0, 2.0);
    m_profileTemperatureSpin->setSingleStep(0.1);
    m_profileTemperatureSpin->setSpecialValueText(tr("(use global)"));
    m_profileTemperatureSpin->setValue(0.0);
    overrideLayout->addRow(tr("Temperature:"), m_profileTemperatureSpin);

    m_profileMaxTokensSpin = new QSpinBox();
    m_profileMaxTokensSpin->setRange(0, 1000000);
    m_profileMaxTokensSpin->setSingleStep(1024);
    m_profileMaxTokensSpin->setSpecialValueText(tr("(use global)"));
    m_profileMaxTokensSpin->setValue(0);
    overrideLayout->addRow(tr("Max Tokens:"), m_profileMaxTokensSpin);

    configLayout->addRow(overrideGroup);

    QHBoxLayout* enabledLayout = new QHBoxLayout();
    m_profileEnabledCheck = new QCheckBox(tr("Enabled"));
    connect(m_profileEnabledCheck, &QCheckBox::checkStateChanged,
            this, &SettingsDialog::onProfileEnabledChanged);
    enabledLayout->addWidget(m_profileEnabledCheck);
    enabledLayout->addStretch();
    configLayout->addRow(enabledLayout);

    layout->addWidget(configGroup);

    // Global Defaults section
    QGroupBox* globalGroup = new QGroupBox(tr("Global Defaults (optional, leave empty for provider defaults)"));
    QFormLayout* globalLayout = new QFormLayout(globalGroup);

    m_globalTemperatureSpin = new QDoubleSpinBox();
    m_globalTemperatureSpin->setRange(0.0, 2.0);
    m_globalTemperatureSpin->setSingleStep(0.1);
    m_globalTemperatureSpin->setSpecialValueText(tr("(provider default)"));
    m_globalTemperatureSpin->setValue(0.0);
    m_globalTemperatureSpin->setToolTip(tr("Recommended: Leave empty to let provider use its defaults"));
    connect(m_globalTemperatureSpin, QOverload<double>::of(&QDoubleSpinBox::valueChanged),
            this, &SettingsDialog::onGlobalDefaultsChanged);
    globalLayout->addRow(tr("Temperature:"), m_globalTemperatureSpin);

    m_globalMaxTokensSpin = new QSpinBox();
    m_globalMaxTokensSpin->setRange(0, 1000000);
    m_globalMaxTokensSpin->setSingleStep(1024);
    m_globalMaxTokensSpin->setSpecialValueText(tr("(provider default)"));
    m_globalMaxTokensSpin->setValue(0);
    m_globalMaxTokensSpin->setToolTip(tr("Recommended: Leave empty to let provider use its defaults"));
    connect(m_globalMaxTokensSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &SettingsDialog::onGlobalDefaultsChanged);
    globalLayout->addRow(tr("Max Tokens:"), m_globalMaxTokensSpin);

    layout->addWidget(globalGroup);

    // Test connection button
    QHBoxLayout* testLayout = new QHBoxLayout();
    m_testConnectionButton = new QPushButton(tr("Test Model Connection"));
    connect(m_testConnectionButton, &QPushButton::clicked, this, &SettingsDialog::onTestConnectionClicked);

    m_connectionStatusLabel = new QLabel();
    testLayout->addWidget(m_testConnectionButton);
    testLayout->addWidget(m_connectionStatusLabel);
    testLayout->addStretch();

    layout->addLayout(testLayout);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("LLM"));
}

void SettingsDialog::setupPromptsTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    // Prompts table
    m_promptsTable = new QTableWidget();
    m_promptsTable->setColumnCount(7);
    m_promptsTable->setHorizontalHeaderLabels({
        tr("Name"), tr("Description"), tr("Content Type"), tr("Model"), tr("Group"), tr("Priority"), tr("Hotkey")
    });
    m_promptsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_promptsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_promptsTable->horizontalHeader()->setStretchLastSection(true);
    m_promptsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(m_promptsTable, &QTableWidget::itemSelectionChanged,
            this, &SettingsDialog::onPromptSelectionChanged);
    connect(m_promptsTable, &QTableWidget::itemDoubleClicked,
            this, &SettingsDialog::onEditPromptClicked);

    layout->addWidget(m_promptsTable);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_addPromptButton = new QPushButton(tr("Add"));
    m_addPromptButton->setIcon(style()->standardIcon(QStyle::SP_DialogApplyButton));
    connect(m_addPromptButton, &QPushButton::clicked, this, &SettingsDialog::onAddPromptClicked);

    m_editPromptButton = new QPushButton(tr("Edit"));
    m_editPromptButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    m_editPromptButton->setEnabled(false);
    connect(m_editPromptButton, &QPushButton::clicked, this, &SettingsDialog::onEditPromptClicked);

    m_deletePromptButton = new QPushButton(tr("Delete"));
    m_deletePromptButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    m_deletePromptButton->setEnabled(false);
    connect(m_deletePromptButton, &QPushButton::clicked, this, &SettingsDialog::onDeletePromptClicked);

    m_manageGroupsButton = new QPushButton(tr("Manage Groups..."));
    connect(m_manageGroupsButton, &QPushButton::clicked, this, &SettingsDialog::onManageGroupsClicked);

    buttonLayout->addWidget(m_addPromptButton);
    buttonLayout->addWidget(m_editPromptButton);
    buttonLayout->addWidget(m_deletePromptButton);
    buttonLayout->addWidget(m_manageGroupsButton);
    buttonLayout->addStretch();

    layout->addLayout(buttonLayout);

    // Import/Export buttons
    QHBoxLayout* ioLayout = new QHBoxLayout();

    m_importPromptsButton = new QPushButton(tr("Import"));
    m_importPromptsButton->setIcon(style()->standardIcon(QStyle::SP_DialogOpenButton));
    connect(m_importPromptsButton, &QPushButton::clicked, this, &SettingsDialog::onImportPromptsClicked);

    m_exportPromptsButton = new QPushButton(tr("Export"));
    m_exportPromptsButton->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    connect(m_exportPromptsButton, &QPushButton::clicked, this, &SettingsDialog::onExportPromptsClicked);

    m_resetPromptsButton = new QPushButton(tr("Reset to Defaults"));
    connect(m_resetPromptsButton, &QPushButton::clicked, this, &SettingsDialog::onResetPromptsClicked);

    ioLayout->addWidget(m_importPromptsButton);
    ioLayout->addWidget(m_exportPromptsButton);
    ioLayout->addStretch();
    ioLayout->addWidget(m_resetPromptsButton);

    layout->addLayout(ioLayout);

    m_tabWidget->addTab(widget, tr("Prompts"));
}

void SettingsDialog::setupHistoryTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    // Auto-save checkbox at the top
    m_autoSaveHistoryCheck = new QCheckBox(tr("Automatically save to history after generation"));
    layout->addWidget(m_autoSaveHistoryCheck);

    QGroupBox* settingsGroup = new QGroupBox(tr("History Settings"));
    QFormLayout* settingsLayout = new QFormLayout(settingsGroup);

    m_cleanupByCountCheck = new QCheckBox(tr("Auto-cleanup by max entries"));
    m_cleanupByCountCheck->setToolTip(tr("Automatically remove oldest entries when limit is exceeded"));
    connect(m_cleanupByCountCheck, &QCheckBox::checkStateChanged,
            this, &SettingsDialog::onCleanupByCountChanged);
    settingsLayout->addRow(m_cleanupByCountCheck);

    m_historyLimitSpin = new QSpinBox();
    m_historyLimitSpin->setRange(0, 10000);
    m_historyLimitSpin->setValue(1000);
    m_historyLimitSpin->setSpecialValueText(tr("Unlimited"));
    m_historyLimitSpin->setEnabled(false); // Disabled by default
    connect(m_historyLimitSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &SettingsDialog::onHistoryLimitChanged);
    settingsLayout->addRow(tr("Maximum entries:"), m_historyLimitSpin);

    m_cleanupByDateCheck = new QCheckBox(tr("Auto-cleanup by date"));
    m_cleanupByDateCheck->setToolTip(tr("Automatically remove entries older than the specified number of days"));
    connect(m_cleanupByDateCheck, &QCheckBox::checkStateChanged,
            this, &SettingsDialog::onCleanupByDateChanged);
    settingsLayout->addRow(m_cleanupByDateCheck);

    m_daysToKeepSpin = new QSpinBox();
    m_daysToKeepSpin->setRange(1, 365);
    m_daysToKeepSpin->setValue(30);
    m_daysToKeepSpin->setEnabled(false); // Disabled by default
    connect(m_daysToKeepSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &SettingsDialog::onDaysToKeepChanged);
    settingsLayout->addRow(tr("Days to keep:"), m_daysToKeepSpin);

    layout->addWidget(settingsGroup);

    QGroupBox* actionGroup = new QGroupBox(tr("Actions"));
    QVBoxLayout* actionLayout = new QVBoxLayout(actionGroup);

    m_clearHistoryButton = new QPushButton(tr("Clear All History"));
    m_clearHistoryButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    connect(m_clearHistoryButton, &QPushButton::clicked, this, &SettingsDialog::onClearHistoryClicked);

    actionLayout->addWidget(m_clearHistoryButton);

    m_historyStatusLabel = new QLabel();
    actionLayout->addWidget(m_historyStatusLabel);

    layout->addWidget(actionGroup);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("History"));
}

void SettingsDialog::loadSettings()
{
    loadLanguages();
    loadProviders();
    loadPrompts();
    loadProviderProfiles();

    if (!m_configManager) {
        return;
    }

    // General
    QString language = m_configManager->language();
    int langIndex = m_languageCombo->findData(language);
    if (langIndex >= 0) {
        m_languageCombo->blockSignals(true);
        m_languageCombo->setCurrentIndex(langIndex);
        m_languageCombo->blockSignals(false);
    }

    m_autoSaveHistoryCheck->setChecked(m_configManager->historyAutoSave());

    // General - Miscellaneous
    m_showDescriptionInMenuCheck->setChecked(m_configManager->showDescriptionInMenu());
    m_showDescriptionInPopupCheck->setChecked(m_configManager->showDescriptionInPopup());

    // LLM - Global defaults
    if (m_configManager->defaultTemperature().has_value()) {
        m_globalTemperatureSpin->setValue(*m_configManager->defaultTemperature());
    } else {
        m_globalTemperatureSpin->setValue(0.0); // Special value: (provider default)
    }

    if (m_configManager->defaultMaxTokens().has_value()) {
        m_globalMaxTokensSpin->setValue(*m_configManager->defaultMaxTokens());
    } else {
        m_globalMaxTokensSpin->setValue(0); // Special value: (provider default)
    }

    // Hotkeys
    QString hotkey = m_configManager->hotkey();
    qDebug() << "SettingsDialog: loading hotkey from config:" << hotkey;
    m_hotkeyEdit->setHotkeyText(hotkey);
    qDebug() << "SettingsDialog: hotkeyEdit after load:" << m_hotkeyEdit->hotkeyText()
             << "sequence:" << m_hotkeyEdit->keySequence().toString();

    // History
    m_historyLimitSpin->setValue(m_configManager->historyLimit());
    m_cleanupByCountCheck->setChecked(m_configManager->historyCleanupByCount());
    m_cleanupByDateCheck->setChecked(m_configManager->historyCleanupByDate());
    m_daysToKeepSpin->setValue(m_configManager->historyDaysToKeep());
    // Update enabled state of spinboxes based on checkboxes
    m_historyLimitSpin->setEnabled(m_cleanupByCountCheck->isChecked());
    m_daysToKeepSpin->setEnabled(m_cleanupByDateCheck->isChecked());
}

void SettingsDialog::saveSettings()
{
    if (!m_configManager) {
        return;
    }

    // General
    m_configManager->setLanguage(m_languageCombo->currentData().toString());
    m_configManager->setHistoryAutoSave(m_autoSaveHistoryCheck->isChecked());
    m_configManager->setShowDescriptionInMenu(m_showDescriptionInMenuCheck->isChecked());
    m_configManager->setShowDescriptionInPopup(m_showDescriptionInPopupCheck->isChecked());

    // LLM - Save all profiles
    QList<Models::ProviderProfile> profiles;
    for (int i = 0; i < m_profilesList->count(); ++i) {
        QListWidgetItem* item = m_profilesList->item(i);
        QString profileId = item->data(Qt::UserRole).toString();
        auto profileOpt = m_configManager->providerProfile(profileId);
        if (profileOpt.has_value()) {
            profiles.append(profileOpt.value());
        }
    }
    m_configManager->setProviderProfiles(profiles);

    // LLM - Global defaults
    if (m_globalTemperatureSpin->value() > 0.0) {
        m_configManager->setDefaultTemperature(m_globalTemperatureSpin->value());
    } else {
        m_configManager->setDefaultTemperature(std::nullopt);
    }

    if (m_globalMaxTokensSpin->value() > 0) {
        m_configManager->setDefaultMaxTokens(m_globalMaxTokensSpin->value());
    } else {
        m_configManager->setDefaultMaxTokens(std::nullopt);
    }

    // Hotkeys
    QString hotkeyText = m_hotkeyEdit->hotkeyText();
    qDebug() << "SettingsDialog: saving hotkey:" << hotkeyText;
    m_configManager->setHotkey(hotkeyText);

    // History
    m_configManager->setHistoryLimit(m_historyLimitSpin->value());
    m_configManager->setHistoryCleanupByCount(m_cleanupByCountCheck->isChecked());
    m_configManager->setHistoryCleanupByDate(m_cleanupByDateCheck->isChecked());
    m_configManager->setHistoryDaysToKeep(m_daysToKeepSpin->value());

    m_configManager->sync();

    emit settingsChanged();
}

void SettingsDialog::loadLanguages()
{
    m_languageCombo->blockSignals(true);
    m_languageCombo->clear();
    m_languageCombo->addItem(tr("English"), QStringLiteral("en"));
    m_languageCombo->addItem(tr("Russian"), QStringLiteral("ru"));
    m_languageCombo->addItem(tr("German"), QStringLiteral("de"));
    m_languageCombo->addItem(tr("French"), QStringLiteral("fr"));
    m_languageCombo->addItem(tr("Spanish"), QStringLiteral("es"));
    m_languageCombo->blockSignals(false);
}

void SettingsDialog::loadProviders()
{
    // This function is kept for compatibility but is no longer used
    // with the new provider profiles system
    // The old m_providerCombo is no longer available
}

void SettingsDialog::loadModels()
{
    // This function is kept for compatibility but is no longer used
    // with the new provider profiles system
    // Models are now loaded per-profile in updateProfileEditor
}

void SettingsDialog::loadPrompts()
{
    m_promptsTable->setRowCount(0);

    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    QVector<Models::Prompt> prompts = app->promptManager()->getAllPrompts();

    m_promptsTable->setRowCount(prompts.size());

    for (int i = 0; i < prompts.size(); ++i) {
        const auto& prompt = prompts[i];

        QTableWidgetItem* nameItem = new QTableWidgetItem(prompt.name());
        nameItem->setData(Qt::UserRole, prompt.id());
        m_promptsTable->setItem(i, 0, nameItem);
        m_promptsTable->setItem(i, 1, new QTableWidgetItem(prompt.description()));
        m_promptsTable->setItem(i, 2, new QTableWidgetItem(
            Models::Prompt::contentTypeToString(prompt.contentType())
        ));
        // Show model only if override is enabled, otherwise show "(default)"
        QString modelText;
        if (prompt.overrideProvider()) {
            modelText = prompt.model().isEmpty() ? tr("(custom)") : prompt.model();
        } else {
            modelText = tr("(default)");
        }
        m_promptsTable->setItem(i, 3, new QTableWidgetItem(modelText));
        m_promptsTable->setItem(i, 4, new QTableWidgetItem(
            prompt.group().isEmpty() ? tr("(root)") : prompt.group()
        ));
        m_promptsTable->setItem(i, 5, new QTableWidgetItem(
            QString::number(prompt.priority())
        ));
        m_promptsTable->setItem(i, 6, new QTableWidgetItem(
            prompt.hotkey().isEmpty() ? tr("(none)") : prompt.hotkey()
        ));
    }

    m_promptsTable->resizeColumnsToContents();
}

void SettingsDialog::onTabChanged(int index)
{
    Q_UNUSED(index)

    if (m_tabWidget->currentWidget() != m_promptsTable->parentWidget()) {
        loadPrompts();
    }
}

void SettingsDialog::onOkClicked()
{
    saveSettings();
    // Save window geometry before closing
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("settingsDialog", saveGeometry());
    settings.endGroup();
    settings.sync();
    accept();
}

void SettingsDialog::onResetClicked()
{
    auto reply = QMessageBox::question(
        this,
        tr("Reset Settings"),
        tr("Are you sure you want to reset all settings to defaults?"),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        if (m_configManager) {
            m_configManager->clear();
        }
        loadSettings();
    }
}

void SettingsDialog::onLanguageChanged(int index)
{
    Q_UNUSED(index)
    QString newLanguage = m_languageCombo->currentData().toString();

    // Save the language setting
    if (m_configManager) {
        m_configManager->setLanguage(newLanguage);
    }

    // Show notification that restart is required
    QMessageBox::information(
        this,
        tr("Language Changed"),
        tr("The language will be changed after you restart the application.")
    );
}

void SettingsDialog::onTestConnectionClicked()
{
    m_connectionStatusLabel->setText(tr("Testing..."));
    m_connectionStatusLabel->setStyleSheet("color: blue;");
    m_testConnectionButton->setEnabled(false);

    QString providerId = getCurrentProviderId();
    if (providerId.isEmpty()) {
        m_connectionStatusLabel->setText(tr("No profile selected"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        m_testConnectionButton->setEnabled(true);
        return;
    }

    // Check if profile has required fields
    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        m_connectionStatusLabel->setText(tr("Profile not found"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        m_testConnectionButton->setEnabled(true);
        return;
    }

    const auto& profile = profileOpt.value();
    if (!profile.apiUrl().isValid()) {
        m_connectionStatusLabel->setText(tr("Invalid API URL"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        m_testConnectionButton->setEnabled(true);
        return;
    }

    // Check if local provider (no API key needed)
    QString apiUrl = profile.apiUrl().toString();
    bool isLocalProvider = apiUrl.contains(QStringLiteral("localhost")) ||
                          apiUrl.contains(QStringLiteral("127.0.0.1")) ||
                          apiUrl.contains(QStringLiteral("ollama"));

    if (!isLocalProvider && m_profileApiKeyEdit->text().isEmpty()) {
        m_connectionStatusLabel->setText(tr("Error: No API key"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        m_testConnectionButton->setEnabled(true);
        return;
    }

    if (profile.model().isEmpty()) {
        m_connectionStatusLabel->setText(tr("Error: No model selected"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        m_testConnectionButton->setEnabled(true);
        return;
    }

    // Clean up any existing test client
    delete m_testClient;
    m_testClient = nullptr;

    // Create a temporary LLM client for connection testing (isolated from app's active client)
    m_testClient = new Core::LLMClient(this);

    // Create a temporary config from the profile
    Models::LLMConfig config;
    config.setApiUrl(profile.apiUrl());
    config.setModel(profile.model());

    m_testClient->setConfig(config);

    QString apiKey = m_profileApiKeyEdit->text();
    if (!isLocalProvider && !apiKey.isEmpty()) {
        m_testClient->setApiKey(apiKey);
    }

    // Connect to result signal
    connect(m_testClient, &Core::LLMClient::connectionTestResult,
            this, &SettingsDialog::onConnectionTestResult);

    m_testClient->testConnection();
}

void SettingsDialog::onConnectionTestResult(bool success, const QString& message)
{
    m_testConnectionButton->setEnabled(true);

    if (success) {
        m_connectionStatusLabel->setText(tr("Connection successful"));
        m_connectionStatusLabel->setStyleSheet("color: green;");
    } else {
        m_connectionStatusLabel->setText(tr("Error: %1").arg(message));
        m_connectionStatusLabel->setStyleSheet("color: red;");
    }

    // Clean up the temporary test client
    if (m_testClient) {
        m_testClient->deleteLater();
        m_testClient = nullptr;
    }
}

void SettingsDialog::onHotkeyChanged(const QKeySequence& sequence)
{
    // Ignore changes during recording - we'll handle it in recordingFinished
    if (m_isRecordingGlobalHotkey) {
        return;
    }
    emit hotkeyChanged(sequence);
}

void SettingsDialog::onAddPromptClicked()
{
    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    PromptEditorDialog dialog(app->promptManager(), app->groupsManager(), this);
    if (dialog.exec() == QDialog::Accepted) {
        Models::Prompt prompt = dialog.getPrompt();
        if (app->promptManager()->addPrompt(prompt)) {
            loadPrompts();
            emit settingsChanged();
            emit promptsChanged();
        } else {
            QMessageBox::warning(this, tr("Error"),
                               tr("Failed to add prompt. ID may already exist."));
        }
    }
}

void SettingsDialog::onEditPromptClicked()
{
    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    int row = m_promptsTable->currentRow();
    if (row < 0) {
        return;
    }

    QTableWidgetItem* nameItem = m_promptsTable->item(row, 0);
    if (!nameItem) {
        return;
    }

    QString promptId = nameItem->data(Qt::UserRole).toString();
    auto promptOpt = app->promptManager()->getPrompt(promptId);
    if (!promptOpt) {
        return;
    }

    PromptEditorDialog dialog(app->promptManager(), app->groupsManager(), promptOpt.value(), this);
    if (dialog.exec() == QDialog::Accepted) {
        Models::Prompt updatedPrompt = dialog.getPrompt();
        if (app->promptManager()->updatePrompt(promptId, updatedPrompt)) {
            loadPrompts();
            emit settingsChanged();
            emit promptsChanged();
        } else {
            QMessageBox::warning(this, tr("Error"),
                               tr("Failed to update prompt."));
        }
    }
}

void SettingsDialog::onDeletePromptClicked()
{
    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    int row = m_promptsTable->currentRow();
    if (row < 0) {
        return;
    }

    QString promptId = m_promptsTable->item(row, 0)->data(Qt::UserRole).toString();
    if (promptId.isEmpty()) {
        return;
    }

    auto reply = QMessageBox::question(
        this,
        tr("Delete Prompt"),
        tr("Are you sure you want to delete this prompt?"),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        app->promptManager()->removePrompt(promptId);
        loadPrompts();
        emit promptsChanged();
    }
}

void SettingsDialog::onManageGroupsClicked()
{
    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->groupsManager()) {
        return;
    }

    GroupsDialog dialog(app->groupsManager(), app->promptManager(), this);
    dialog.exec();

    // Reload prompts as groups may have changed
    loadPrompts();
}

void SettingsDialog::onImportPromptsClicked()
{
    QString fileName = QFileDialog::getOpenFileName(
        this,
        tr("Import Prompts"),
        QString(),
        tr("JSON Files (*.json)")
    );

    if (fileName.isEmpty()) {
        return;
    }

    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    // Read and parse the JSON file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, tr("Import Prompts"),
                            tr("Failed to open file: %1").arg(fileName));
        return;
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &error);
    file.close();

    if (error.error != QJsonParseError::NoError) {
        QMessageBox::warning(this, tr("Import Prompts"),
                            tr("Failed to parse JSON file: %1").arg(error.errorString()));
        return;
    }

    // Import the prompts with conflict resolution
    bool success = app->promptManager()->importPromptsFromJson(
        doc.object(),
        m_configManager,
        app->groupsManager(),
        this
    );

    if (success) {
        QMessageBox::information(this, tr("Import Prompts"),
                               tr("Prompts imported successfully."));
        loadPrompts();
    } else {
        // Import was cancelled or failed - no message needed for cancel
        // User already saw the conflict dialog and chose cancel
    }
}

void SettingsDialog::onExportPromptsClicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Export Prompts"),
        QStringLiteral("prompts_%1.json").arg(QDateTime::currentDateTime().toString("yyyyMMdd")),
        tr("JSON Files (*.json)")
    );

    if (fileName.isEmpty()) {
        return;
    }

    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return;
    }

    app->promptManager()->savePromptsToFile(fileName);

    QMessageBox::information(this, tr("Export Prompts"),
                           tr("Prompts exported to %1").arg(fileName));
}

void SettingsDialog::onResetPromptsClicked()
{
    auto reply = QMessageBox::question(
        this,
        tr("Reset Prompts"),
        tr("Are you sure you want to reset prompts to defaults? All custom prompts will be lost."),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        App* app = qobject_cast<App*>(QApplication::instance());
        if (app && app->promptManager()) {
            // Reset to defaults
            app->promptManager()->savePromptsToFile(app->promptManager()->getCustomPromptsFilePath());
            loadPrompts();
        }
    }
}

void SettingsDialog::onPromptSelectionChanged()
{
    bool hasSelection = m_promptsTable->currentRow() >= 0;
    m_editPromptButton->setEnabled(hasSelection);
    m_deletePromptButton->setEnabled(hasSelection);
}

void SettingsDialog::onClearHistoryClicked()
{
    auto reply = QMessageBox::question(
        this,
        tr("Clear History"),
        tr("Are you sure you want to delete all history entries? This cannot be undone."),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        App* app = qobject_cast<App*>(QApplication::instance());
        if (app && app->historyManager()) {
            app->historyManager()->clearAll();
        }
    }
}

void SettingsDialog::onHistoryLimitChanged(int value)
{
    Q_UNUSED(value)
}

void SettingsDialog::onCleanupByCountChanged(int state)
{
    m_historyLimitSpin->setEnabled(state == Qt::Checked);
}

void SettingsDialog::onCleanupByDateChanged(int state)
{
    m_daysToKeepSpin->setEnabled(state == Qt::Checked);
}

void SettingsDialog::onDaysToKeepChanged(int value)
{
    Q_UNUSED(value)
}

void SettingsDialog::onRefreshModelsClicked()
{
    QString providerId = getCurrentProviderId();
    if (providerId.isEmpty()) {
        m_connectionStatusLabel->setText(tr("No profile selected"));
        return;
    }

    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        m_connectionStatusLabel->setText(tr("Profile not found"));
        return;
    }

    const auto& profile = profileOpt.value();
    QString apiUrl = profile.apiUrl().toString();

    if (apiUrl.isEmpty()) {
        m_connectionStatusLabel->setText(tr("No API URL set"));
        return;
    }

    fetchModelsFromAPI();
}

void SettingsDialog::fetchModelsFromAPI()
{
    QString providerId = getCurrentProviderId();
    if (providerId.isEmpty()) {
        return;
    }

    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        return;
    }

    const auto& profile = profileOpt.value();
    QString apiKey = m_profileApiKeyEdit->text();
    QString apiUrl = profile.apiUrl().toString();

    QUrl url;
    QString authHeader;

    if (apiUrl.contains(QStringLiteral("openrouter.ai"))) {
        url = QUrl(QStringLiteral("https://openrouter.ai/api/v1/models"));
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    } else if (apiUrl.contains(QStringLiteral("api.openai.com"))) {
        url = QUrl(QStringLiteral("https://api.openai.com/v1/models"));
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    } else if (apiUrl.contains(QStringLiteral("nano-gpt.com"))) {
        // NanoGPT uses base URL + /api/v1/models
        // Replace /chat/completions with /models
        url = QUrl(apiUrl);
        QString path = url.path();
        path.replace(QLatin1String("/chat/completions"), QLatin1String("/models"));
        url.setPath(path);
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    } else {
        // OpenAI-compatible providers (Ollama, llama.cpp, custom, etc.)
        // Replace /chat/completions or /messages with /models
        url = QUrl(apiUrl);
        QString path = url.path();
        path.replace(QLatin1String("/chat/completions"), QLatin1String("/models"));
        path.replace(QLatin1String("/messages"), QLatin1String("/models"));
        // Ensure we have /v1/models or /models
        if (!path.endsWith(QLatin1String("/models"))) {
            if (path.endsWith(QLatin1String("/v1")) || path.endsWith(QLatin1String("/api"))) {
                path += QLatin1String("/models");
            } else if (path.contains(QLatin1String("/v1/")) || path.contains(QLatin1String("/api/"))) {
                path = path.left(path.lastIndexOf(QLatin1Char('/'))) + QLatin1String("/models");
            } else {
                path = QLatin1String("/v1/models");
            }
        }
        url.setPath(path);
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    }

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
    if (!authHeader.isEmpty()) {
        request.setRawHeader("Authorization", authHeader.toUtf8());
    }

    m_connectionStatusLabel->setText(tr("Fetching models..."));
    m_refreshModelsButton->setEnabled(false);

    m_networkManager->get(request);
}

void SettingsDialog::onModelsFetchFinished(QNetworkReply* reply)
{
    m_refreshModelsButton->setEnabled(true);

    if (reply->error() != QNetworkReply::NoError) {
        m_connectionStatusLabel->setText(tr("Error: %1").arg(reply->errorString()));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        m_connectionStatusLabel->setText(tr("Error: Invalid response"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        reply->deleteLater();
        return;
    }

    QJsonObject root = doc.object();
    QStringList models;

    QString providerId = getCurrentProviderId();
    auto profileOpt = m_configManager->providerProfile(providerId);
    QString apiUrl;
    if (profileOpt.has_value()) {
        apiUrl = profileOpt->apiUrl().toString();
    }

    if (apiUrl.contains(QStringLiteral("api.openai.com"))) {
        // OpenAI format: { "data": [ { "id": "model-name", ... }, ... ] }
        QJsonArray modelArray = root.value(QStringLiteral("data")).toArray();
        for (const QJsonValue& value : modelArray) {
            QJsonObject modelObj = value.toObject();
            QString id = modelObj.value(QStringLiteral("id")).toString();
            // Filter out legacy models (containing dot like gpt-3.5-turbo)
            if (!id.isEmpty() && !id.contains(QLatin1Char('.'))) {
                models.append(id);
            }
        }
    } else {
        // OpenAI-compatible format (OpenRouter, NanoGPT, Ollama, llama.cpp, custom, etc.)
        // { "data": [ { "id": "model/name", ... }, ... ] }
        QJsonArray modelArray = root.value(QStringLiteral("data")).toArray();
        for (const QJsonValue& value : modelArray) {
            QJsonObject modelObj = value.toObject();
            QString id = modelObj.value(QStringLiteral("id")).toString();
            if (!id.isEmpty()) {
                models.append(id);
            }
        }
    }

    if (models.isEmpty()) {
        m_connectionStatusLabel->setText(tr("No models found"));
    } else {
        // Sort models alphabetically
        models.sort(Qt::CaseInsensitive);

        // Save current selection (use text for editable combo box)
        QString currentModel = m_profileModelCombo->currentText().trimmed();

        // Update combo box (no "Auto" entry, user can type manually)
        m_profileModelCombo->clear();
        for (const QString& model : models) {
            m_profileModelCombo->addItem(model, model);
        }

        // Restore selection or auto-select first model if using placeholder
        if (!currentModel.isEmpty()) {
            int index = m_profileModelCombo->findText(currentModel);
            if (index >= 0) {
                m_profileModelCombo->setCurrentIndex(index);
            } else {
                m_profileModelCombo->setCurrentText(currentModel);
            }
        } else {
            // Auto-select first model and save to profile
            m_profileModelCombo->setCurrentIndex(0);
            Models::ProviderProfile profile = getCurrentProfileFromEditor();
            m_configManager->updateProviderProfile(profile);
        }

        // Expand the combo box to show models
        m_profileModelCombo->showPopup();

        m_connectionStatusLabel->setText(tr("Loaded %1 models").arg(models.size()));
        m_connectionStatusLabel->setStyleSheet("color: green;");
    }

    reply->deleteLater();
}

// Provider profiles handlers

void SettingsDialog::loadProviderProfiles()
{
    m_profilesList->clear();

    if (!m_configManager) {
        return;
    }

    QList<Models::ProviderProfile> profiles = m_configManager->providerProfiles();
    QString defaultId = m_configManager->defaultProviderId();

    // Add placeholder item when no profiles exist
    if (profiles.isEmpty()) {
        QListWidgetItem* placeholderItem = new QListWidgetItem();
        placeholderItem->setText(tr("No provider profiles configured.\nClick '+ Add' to create one."));
        placeholderItem->setFlags(placeholderItem->flags() & ~Qt::ItemIsEnabled & ~Qt::ItemIsSelectable);
        QFont font = placeholderItem->font();
        font.setItalic(true);
        placeholderItem->setFont(font);
        placeholderItem->setForeground(Qt::gray);
        m_profilesList->addItem(placeholderItem);
        onProfileSelectionChanged();
        return;
    }

    for (const auto& profile : profiles) {
        QListWidgetItem* item = new QListWidgetItem();
        QString displayText = profile.name();
        if (profile.id() == defaultId) {
            displayText += tr(" [Default]");
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
        }
        if (!profile.enabled()) {
            displayText += tr(" (disabled)");
        }
        item->setText(displayText);
        item->setData(Qt::UserRole, profile.id());
        m_profilesList->addItem(item);
    }

    // Enable/disable buttons based on selection
    onProfileSelectionChanged();
}

void SettingsDialog::onProfileSelectionChanged()
{
    int row = m_profilesList->currentRow();
    bool hasSelection = row >= 0;

    m_removeProfileButton->setEnabled(hasSelection);
    m_setAsDefaultButton->setEnabled(hasSelection);

    if (hasSelection) {
        QListWidgetItem* item = m_profilesList->currentItem();
        QString profileId = item->data(Qt::UserRole).toString();
        auto profileOpt = m_configManager->providerProfile(profileId);
        if (profileOpt.has_value()) {
            updateProfileEditor(profileOpt.value());
        }
    } else {
        clearProfileEditor();
    }
}

void SettingsDialog::onAddProfileClicked()
{
    // Create a new profile from a template or as custom
    bool ok;
    QString templateName = QInputDialog::getItem(
        this,
        tr("Add Provider Profile"),
        tr("Select a template or create custom:"),
        Models::ProviderProfile::availableTemplateNames(),
        0, false, &ok
    );

    if (!ok || templateName.isEmpty()) {
        return;
    }

    // Check for existing profiles with same name and find next number
    QString suffix;
    QList<Models::ProviderProfile> existingProfiles = m_configManager->providerProfiles();
    QSet<QString> existingNames;
    for (const auto& p : existingProfiles) {
        existingNames.insert(p.name());
    }

    QString baseName = templateName;
    if (existingNames.contains(baseName)) {
        // Find next available number
        int num = 2;
        while (existingNames.contains(baseName + " " + QString::number(num))) {
            num++;
        }
        suffix = QString::number(num);
    }

    // Create profile from template (with or without suffix)
    Models::ProviderProfile profile = Models::ProviderProfile::createFromTemplate(
        templateName,
        suffix
    );

    // Add to config
    m_configManager->addProviderProfile(profile);

    // Set as default if it's the first profile
    if (m_configManager->providerProfiles().size() == 1) {
        m_configManager->setDefaultProviderId(profile.id());
    }

    // Reload list and select the new profile
    loadProviderProfiles();
    for (int i = 0; i < m_profilesList->count(); ++i) {
        QListWidgetItem* item = m_profilesList->item(i);
        if (item->data(Qt::UserRole).toString() == profile.id()) {
            m_profilesList->setCurrentRow(i);
            break;
        }
    }
}

void SettingsDialog::onRemoveProfileClicked()
{
    int row = m_profilesList->currentRow();
    if (row < 0) {
        return;
    }

    QListWidgetItem* item = m_profilesList->currentItem();
    QString profileId = item->data(Qt::UserRole).toString();
    QString profileName = item->text().replace(tr(" [Default]"), QString()).replace(tr(" (disabled)"), QString());

    auto reply = QMessageBox::question(
        this,
        tr("Remove Profile"),
        tr("Are you sure you want to remove the profile \"%1\"?").arg(profileName),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        // Remove API key
        if (m_providerKeyStore) {
            m_providerKeyStore->removeProviderKey(profileId);
        }

        // Remove profile
        m_configManager->removeProviderProfile(profileId);

        // If this was the default, clear the default
        if (m_configManager->defaultProviderId() == profileId) {
            m_configManager->setDefaultProviderId(QString());
        }

        loadProviderProfiles();
        clearProfileEditor();
    }
}

void SettingsDialog::onSetAsDefaultClicked()
{
    int row = m_profilesList->currentRow();
    if (row < 0) {
        return;
    }

    QListWidgetItem* item = m_profilesList->currentItem();
    QString profileId = item->data(Qt::UserRole).toString();

    m_configManager->setDefaultProviderId(profileId);
    m_configManager->sync();  // Ensure the setting is written immediately

    qDebug() << "Default provider set to:" << profileId
             << "current default:" << m_configManager->defaultProviderId();

    loadProviderProfiles();

    // Reselect the profile
    for (int i = 0; i < m_profilesList->count(); ++i) {
        QListWidgetItem* listItem = m_profilesList->item(i);
        if (listItem->data(Qt::UserRole).toString() == profileId) {
            m_profilesList->setCurrentRow(i);
            break;
        }
    }
}

void SettingsDialog::onProfileNameChanged(const QString& text)
{
    if (m_updatingProfileEditor) {
        return;
    }

    // Update the profile in config
    Models::ProviderProfile profile = getCurrentProfileFromEditor();
    profile.setName(text);
    m_configManager->updateProviderProfile(profile);

    // Update list item
    int row = m_profilesList->currentRow();
    if (row >= 0) {
        QListWidgetItem* item = m_profilesList->currentItem();
        QString displayText = text;
        if (profile.id() == m_configManager->defaultProviderId()) {
            displayText += tr(" [Default]");
        }
        if (!profile.enabled()) {
            displayText += tr(" (disabled)");
        }
        item->setText(displayText);
    }
}

void SettingsDialog::onTemplateChanged(int index)
{
    if (index <= 0) { // First item is "Template..."
        return;
    }

    QString templateName = m_profileTemplateCombo->currentText();
    auto tmpl = Models::ProviderProfile::templateByName(templateName);

    if (!tmpl.name.isEmpty()) {
        m_updatingProfileEditor = true;
        m_profileApiUrlEdit->setText(tmpl.templateUrl);
        m_profileModelCombo->clear();
        m_profileModelCombo->addItems(tmpl.suggestedModels);
        if (!tmpl.defaultModel.isEmpty()) {
            m_profileModelCombo->setCurrentText(tmpl.defaultModel);
        }
        m_updatingProfileEditor = false;

        // Update the profile
        Models::ProviderProfile profile = getCurrentProfileFromEditor();
        profile.setApiUrl(QUrl(tmpl.templateUrl));
        if (!tmpl.defaultModel.isEmpty()) {
            profile.setModel(tmpl.defaultModel);
        }
        m_configManager->updateProviderProfile(profile);
    }

    // Reset template combo
    m_profileTemplateCombo->blockSignals(true);
    m_profileTemplateCombo->setCurrentIndex(0);
    m_profileTemplateCombo->blockSignals(false);
}

void SettingsDialog::onModelChanged(const QString& text)
{
    Q_UNUSED(text)
    if (m_updatingProfileEditor) {
        return;
    }

    // Update the profile
    Models::ProviderProfile profile = getCurrentProfileFromEditor();
    m_configManager->updateProviderProfile(profile);
}

void SettingsDialog::onApiKeyChanged()
{
    if (m_updatingProfileEditor) {
        return;
    }

    // Get current profile ID
    QString profileId = getCurrentProviderId();
    if (profileId.isEmpty()) {
        return;
    }

    // Store API key directly using profile ID
    if (m_providerKeyStore) {
        m_providerKeyStore->setProviderKey(profileId, m_profileApiKeyEdit->text());
    }

    // Update status label
    bool hasKey = !m_profileApiKeyEdit->text().isEmpty();
    m_connectionStatusLabel->setText(hasKey ? tr("API key set") : tr("No API key"));

    // Also update the profile in config (model, name, etc. may have changed)
    Models::ProviderProfile profile = getCurrentProfileFromEditor();
    m_configManager->updateProviderProfile(profile);
}

void SettingsDialog::onProfileEnabledChanged(int state)
{
    if (m_updatingProfileEditor) {
        return;
    }

    // Update the profile
    Models::ProviderProfile profile = getCurrentProfileFromEditor();
    profile.setEnabled(state == Qt::Checked);
    m_configManager->updateProviderProfile(profile);

    // Reload list to show updated state
    loadProviderProfiles();

    // Reselect the profile
    for (int i = 0; i < m_profilesList->count(); ++i) {
        QListWidgetItem* item = m_profilesList->item(i);
        if (item->data(Qt::UserRole).toString() == profile.id()) {
            m_profilesList->setCurrentRow(i);
            break;
        }
    }
}

void SettingsDialog::onGlobalDefaultsChanged()
{
    // Just mark that global defaults have changed
    // They will be saved when OK is clicked
}

void SettingsDialog::updateProfileEditor(const Models::ProviderProfile& profile)
{
    m_updatingProfileEditor = true;
    m_currentEditingProfile = profile;

    m_profileNameEdit->setText(profile.name());
    m_profileApiUrlEdit->setText(profile.apiUrl().toString());
    m_profileModelCombo->setCurrentText(profile.model());
    m_profileEnabledCheck->setChecked(profile.enabled());

    // Load API key
    if (m_providerKeyStore) {
        QString apiKey = m_providerKeyStore->providerKey(profile.id());
        m_profileApiKeyEdit->setText(apiKey);
    }

    // Proxy URL
    m_profileProxyEdit->setText(profile.proxyUrl());

    // Temperature override
    if (profile.temperature().has_value()) {
        m_profileTemperatureSpin->setValue(*profile.temperature());
    } else {
        m_profileTemperatureSpin->setValue(0.0); // Special value
    }

    // MaxTokens override
    if (profile.maxTokens().has_value()) {
        m_profileMaxTokensSpin->setValue(*profile.maxTokens());
    } else {
        m_profileMaxTokensSpin->setValue(0); // Special value
    }

    // Enable/disable refresh button based on URL
    QString apiUrl = profile.apiUrl().toString();
    // Disable for empty URLs (user needs to enter URL first)
    m_refreshModelsButton->setEnabled(!apiUrl.isEmpty());

    // Update API key status label
    bool hasKey = !m_profileApiKeyEdit->text().isEmpty();
    m_connectionStatusLabel->setText(hasKey ? tr("API key set") : tr("No API key"));
    m_connectionStatusLabel->setStyleSheet(QString());

    m_updatingProfileEditor = false;
}

void SettingsDialog::clearProfileEditor()
{
    m_updatingProfileEditor = true;
    m_currentEditingProfile = Models::ProviderProfile();

    m_profileNameEdit->clear();
    m_profileApiUrlEdit->clear();
    m_profileModelCombo->clear();
    m_profileApiKeyEdit->clear();
    m_profileProxyEdit->clear();
    m_profileTemperatureSpin->setValue(0.0);
    m_profileMaxTokensSpin->setValue(0);
    m_profileEnabledCheck->setChecked(true);

    m_updatingProfileEditor = false;
}

Models::ProviderProfile SettingsDialog::getCurrentProfileFromEditor() const
{
    Models::ProviderProfile profile = m_currentEditingProfile;

    profile.setName(m_profileNameEdit->text());
    profile.setApiUrl(QUrl(m_profileApiUrlEdit->text()));
    profile.setModel(m_profileModelCombo->currentText().trimmed());
    profile.setProxyUrl(m_profileProxyEdit->text().trimmed());
    profile.setEnabled(m_profileEnabledCheck->isChecked());

    // Temperature override - 0 means use global
    if (m_profileTemperatureSpin->value() > 0.0) {
        profile.setTemperature(m_profileTemperatureSpin->value());
    } else {
        profile.setTemperature(std::nullopt);
    }

    // MaxTokens override - 0 means use global
    if (m_profileMaxTokensSpin->value() > 0) {
        profile.setMaxTokens(m_profileMaxTokensSpin->value());
    } else {
        profile.setMaxTokens(std::nullopt);
    }

    return profile;
}

QString SettingsDialog::getCurrentProviderId() const
{
    int row = m_profilesList->currentRow();
    if (row >= 0) {
        QListWidgetItem* item = m_profilesList->item(row);
        return item->data(Qt::UserRole).toString();
    }
    return QString();
}

// Legacy methods (for compatibility with old code)

QString SettingsDialog::getCurrentProvider() const
{
    // Return a dummy provider string for compatibility
    return QStringLiteral("custom");
}

QString SettingsDialog::getCurrentModel() const
{
    // Return the current profile's model
    return m_profileModelCombo->currentText().trimmed();
}

void SettingsDialog::showEvent(QShowEvent* event)
{
    // Restore window geometry when dialog is shown
    // This works more reliably than restoring in constructor
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("settingsDialog").toByteArray());
    settings.endGroup();

    QDialog::showEvent(event);
}

void SettingsDialog::closeEvent(QCloseEvent* event)
{
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("settingsDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

void SettingsDialog::onGlobalHotkeyRecordingFinished()
{
    m_isRecordingGlobalHotkey = false;

    QKeySequence seq = m_hotkeyEdit->keySequence();

    // Re-register prompt hotkeys first
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        app->registerPromptHotkeys();
    }

    if (seq.isEmpty()) {
        // Empty hotkey - always valid
        emit hotkeyChanged(seq);
        return;
    }

    // Check for conflicts
    if (checkGlobalHotkeyConflict(seq)) {
        // Clear the conflicting hotkey
        m_hotkeyEdit->blockSignals(true);
        m_hotkeyEdit->setHotkeyText(QString());
        m_hotkeyEdit->blockSignals(false);

        // Show warning
        QMessageBox::warning(this,
            tr("Hotkey Conflict"),
            tr("This hotkey is already in use by a prompt.\n\nPlease choose a different hotkey."));
        // Do NOT emit hotkeyChanged - the hotkey was cleared
    } else {
        // No conflict - emit the change signal to save the new hotkey
        emit hotkeyChanged(seq);
    }
}

bool SettingsDialog::checkGlobalHotkeyConflict(const QKeySequence& seq) const
{
    App* app = qobject_cast<App*>(QApplication::instance());
    if (!app || !app->promptManager()) {
        return false;
    }

    // Check conflict with prompt hotkeys
    QVector<Models::Prompt> allPrompts = app->promptManager()->getAllPrompts();
    for (const auto& prompt : allPrompts) {
        QString promptHotkey = prompt.hotkey();
        if (!promptHotkey.isEmpty()) {
            QKeySequence promptSeq = QKeySequence::fromString(promptHotkey);
            if (seq == promptSeq) {
                return true;
            }
        }
    }

    return false;
}

} // namespace UI
} // namespace ClipLLM
