#include "settingsdialog.h"
#include "hotkeyedit.h"
#include "core/configmanager.h"
#include "core/keychainstore.h"
#include "core/promptmanager.h"
#include "core/historymanager.h"
#include "core/app.h"
#include "models/llmconfig.h"
#include <QApplication>
#include <QMessageBox>
#include <QFileDialog>
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

namespace ClipAI {
namespace UI {

SettingsDialog::SettingsDialog(QWidget* parent)
    : QDialog(parent)
{
    // Get managers from app
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        m_configManager = app->configManager();
        m_keychainStore = app->keychainStore();
    }

    // Create network manager for fetching models
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &SettingsDialog::onModelsFetchFinished);

    setupUi();
    loadSettings();
}

SettingsDialog::~SettingsDialog() = default;

void SettingsDialog::setupUi()
{
    setWindowTitle(tr("ClipAI - Settings"));
    resize(700, 550);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Tab widget
    m_tabWidget = new QTabWidget();

    setupGeneralTab();
    setupLLMTab();
    setupHotkeysTab();
    setupPromptsTab();
    setupHistoryTab();

    mainLayout->addWidget(m_tabWidget);

    // Dialog buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_applyButton = new QPushButton(tr("Apply"));
    connect(m_applyButton, &QPushButton::clicked, this, &SettingsDialog::onApplyClicked);

    m_okButton = new QPushButton(tr("OK"));
    m_okButton->setDefault(true);
    connect(m_okButton, &QPushButton::clicked, this, &SettingsDialog::onOkClicked);

    m_cancelButton = new QPushButton(tr("Cancel"));
    connect(m_cancelButton, &QPushButton::clicked, this, &QDialog::reject);

    m_resetButton = new QPushButton(tr("Reset to Defaults"));
    connect(m_resetButton, &QPushButton::clicked, this, &SettingsDialog::onResetClicked);

    buttonLayout->addWidget(m_resetButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_applyButton);
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
    QVBoxLayout* languageLayout = new QVBoxLayout(languageGroup);

    languageLayout->addWidget(new QLabel(tr("Interface Language:")));

    m_languageCombo = new QComboBox();
    connect(m_languageCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsDialog::onLanguageChanged);

    languageLayout->addWidget(m_languageCombo);
    languageLayout->addStretch();

    layout->addWidget(languageGroup);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("General"));
}

void SettingsDialog::setupLLMTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QGroupBox* providerGroup = new QGroupBox(tr("LLM Provider"));
    QFormLayout* providerLayout = new QFormLayout(providerGroup);

    m_providerCombo = new QComboBox();
    connect(m_providerCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &SettingsDialog::onProviderChanged);
    providerLayout->addRow(tr("Provider:"), m_providerCombo);

    // Model combo with refresh button and editable field
    QHBoxLayout* modelLayout = new QHBoxLayout();
    m_modelCombo = new QComboBox();
    m_modelCombo->setEditable(true);  // Allow manual entry
    m_modelCombo->setPlaceholderText(tr("Select or enter model name..."));
    m_refreshModelsButton = new QPushButton(tr("Refresh"));
    m_refreshModelsButton->setEnabled(false);
    connect(m_refreshModelsButton, &QPushButton::clicked,
            this, &SettingsDialog::onRefreshModelsClicked);
    modelLayout->addWidget(m_modelCombo, 1);
    modelLayout->addWidget(m_refreshModelsButton);
    providerLayout->addRow(tr("Model:"), modelLayout);

    m_apiKeyEdit = new QLineEdit();
    m_apiKeyEdit->setEchoMode(QLineEdit::Password);
    connect(m_apiKeyEdit, &QLineEdit::textChanged, this, &SettingsDialog::onApiKeyChanged);
    providerLayout->addRow(tr("API Key:"), m_apiKeyEdit);

    m_customUrlEdit = new QLineEdit();
    providerLayout->addRow(tr("Custom API URL:"), m_customUrlEdit);

    m_proxyEdit = new QLineEdit();
    providerLayout->addRow(tr("Proxy (optional):"), m_proxyEdit);

    layout->addWidget(providerGroup);

    QGroupBox* optionsGroup = new QGroupBox(tr("Options"));
    QFormLayout* optionsLayout = new QFormLayout(optionsGroup);

    m_temperatureSpin = new QDoubleSpinBox();
    m_temperatureSpin->setRange(0.0, 2.0);
    m_temperatureSpin->setSingleStep(0.1);
    m_temperatureSpin->setValue(0.7);
    optionsLayout->addRow(tr("Temperature:"), m_temperatureSpin);

    m_maxTokensSpin = new QSpinBox();
    m_maxTokensSpin->setRange(1, 128000);
    m_maxTokensSpin->setValue(131072);
    m_maxTokensSpin->setSingleStep(512);
    optionsLayout->addRow(tr("Max Tokens:"), m_maxTokensSpin);

    m_streamCheck = new QCheckBox(tr("Enable streaming responses"));
    m_streamCheck->setChecked(true);
    optionsLayout->addRow(m_streamCheck);

    layout->addWidget(optionsGroup);

    // Test connection button
    QHBoxLayout* testLayout = new QHBoxLayout();
    m_testConnectionButton = new QPushButton(tr("Test Connection"));
    connect(m_testConnectionButton, &QPushButton::clicked, this, &SettingsDialog::onTestConnectionClicked);

    m_connectionStatusLabel = new QLabel();
    testLayout->addWidget(m_testConnectionButton);
    testLayout->addWidget(m_connectionStatusLabel);
    testLayout->addStretch();

    layout->addLayout(testLayout);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("LLM"));
}

void SettingsDialog::setupHotkeysTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    QGroupBox* hotkeyGroup = new QGroupBox(tr("Global Hotkey"));
    QFormLayout* hotkeyLayout = new QFormLayout(hotkeyGroup);

    m_hotkeyEdit = new HotkeyEdit();
    connect(m_hotkeyEdit, &HotkeyEdit::keySequenceChanged,
            this, &SettingsDialog::onHotkeyChanged);

    hotkeyLayout->addRow(tr("Activate Clipboard Processing:"), m_hotkeyEdit);

    QLabel* infoLabel = new QLabel(
        tr("<b>Note:</b> Global hotkeys may not work on Wayland. "
           "On X11, the hotkey works globally. On Windows and macOS, "
           "global hotkeys are fully supported.")
    );
    infoLabel->setWordWrap(true);
    hotkeyLayout->addRow(infoLabel);

    layout->addWidget(hotkeyGroup);
    layout->addStretch();

    m_tabWidget->addTab(widget, tr("Hotkeys"));
}

void SettingsDialog::setupPromptsTab()
{
    QWidget* widget = new QWidget();
    QVBoxLayout* layout = new QVBoxLayout(widget);

    // Prompts table
    m_promptsTable = new QTableWidget();
    m_promptsTable->setColumnCount(4);
    m_promptsTable->setHorizontalHeaderLabels({
        tr("Name"), tr("Description"), tr("Content Type"), tr("Model")
    });
    m_promptsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_promptsTable->setSelectionMode(QAbstractItemView::SingleSelection);
    m_promptsTable->horizontalHeader()->setStretchLastSection(true);
    m_promptsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(m_promptsTable, &QTableWidget::itemSelectionChanged,
            this, &SettingsDialog::onPromptSelectionChanged);

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

    buttonLayout->addWidget(m_addPromptButton);
    buttonLayout->addWidget(m_editPromptButton);
    buttonLayout->addWidget(m_deletePromptButton);
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

    QGroupBox* settingsGroup = new QGroupBox(tr("History Settings"));
    QFormLayout* settingsLayout = new QFormLayout(settingsGroup);

    m_historyLimitSpin = new QSpinBox();
    m_historyLimitSpin->setRange(0, 10000);
    m_historyLimitSpin->setValue(1000);
    m_historyLimitSpin->setSpecialValueText(tr("Unlimited"));
    connect(m_historyLimitSpin, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &SettingsDialog::onHistoryLimitChanged);
    settingsLayout->addRow(tr("Maximum entries:"), m_historyLimitSpin);

    m_autoCleanupCheck = new QCheckBox(tr("Automatically clean up old entries"));
    connect(m_autoCleanupCheck, &QCheckBox::checkStateChanged,
            this, &SettingsDialog::onAutoCleanupChanged);
    settingsLayout->addRow(m_autoCleanupCheck);

    m_daysToKeepSpin = new QSpinBox();
    m_daysToKeepSpin->setRange(1, 365);
    m_daysToKeepSpin->setValue(30);
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

    if (!m_configManager) {
        return;
    }

    // General
    QString language = m_configManager->language();
    int langIndex = m_languageCombo->findData(language);
    if (langIndex >= 0) {
        m_languageCombo->setCurrentIndex(langIndex);
    }

    // LLM
    QString provider = m_configManager->llmProvider();
    int providerIndex = m_providerCombo->findData(provider);
    if (providerIndex >= 0) {
        m_providerCombo->setCurrentIndex(providerIndex);
    }

    // Load models for the current provider before restoring model selection
    loadModels();

    QString model = m_configManager->llmModel();
    // Use setCurrentText for editable combo box (finds match or sets as manual entry)
    if (!model.isEmpty()) {
        m_modelCombo->setCurrentText(model);
    }

    m_customUrlEdit->setText(m_configManager->proxyUrl());
    m_proxyEdit->setText(m_configManager->proxyUrl());
    m_temperatureSpin->setValue(m_configManager->temperature());
    m_maxTokensSpin->setValue(m_configManager->maxTokens());
    m_streamCheck->setChecked(m_configManager->streamResponses());

    // Load API key from secure storage
    if (m_keychainStore) {
        QString apiKey = m_keychainStore->readApiKey();
        m_apiKeyEdit->setText(apiKey);
    }

    // Hotkeys
    QString hotkey = m_configManager->hotkey();
    m_hotkeyEdit->setHotkeyText(hotkey);

    // History
    m_historyLimitSpin->setValue(m_configManager->historyLimit());
    m_autoCleanupCheck->setChecked(m_configManager->historyAutoCleanup());
    m_daysToKeepSpin->setValue(m_configManager->historyDaysToKeep());
}

void SettingsDialog::saveSettings()
{
    if (!m_configManager) {
        return;
    }

    // General
    m_configManager->setLanguage(m_languageCombo->currentData().toString());

    // LLM
    m_configManager->setLlmProvider(m_providerCombo->currentData().toString());
    QString model = m_modelCombo->currentText().trimmed();
    // Don't save placeholder text
    if (model.isEmpty() || model == tr("Select or enter model name...")) {
        model.clear();  // Clear to use default
    }
    m_configManager->setLlmModel(model);
    m_configManager->setProxyUrl(m_proxyEdit->text());
    m_configManager->setTemperature(m_temperatureSpin->value());
    m_configManager->setMaxTokens(m_maxTokensSpin->value());
    m_configManager->setStreamResponses(m_streamCheck->isChecked());

    // Save API key
    if (m_keychainStore) {
        QString newKey = m_apiKeyEdit->text();
        if (!newKey.isEmpty()) {
            m_keychainStore->writeApiKey(newKey);
        }
    }

    // Hotkeys
    m_configManager->setHotkey(m_hotkeyEdit->hotkeyText());

    // History
    m_configManager->setHistoryLimit(m_historyLimitSpin->value());
    m_configManager->setHistoryAutoCleanup(m_autoCleanupCheck->isChecked());
    m_configManager->setHistoryDaysToKeep(m_daysToKeepSpin->value());

    m_configManager->sync();

    emit settingsChanged();
}

void SettingsDialog::loadLanguages()
{
    m_languageCombo->clear();
    m_languageCombo->addItem(tr("English"), QStringLiteral("en"));
    m_languageCombo->addItem(tr("Russian"), QStringLiteral("ru"));
    m_languageCombo->addItem(tr("German"), QStringLiteral("de"));
    m_languageCombo->addItem(tr("French"), QStringLiteral("fr"));
    m_languageCombo->addItem(tr("Spanish"), QStringLiteral("es"));
}

void SettingsDialog::loadProviders()
{
    m_providerCombo->clear();
    m_providerCombo->addItem(tr("OpenRouter"), QStringLiteral("openrouter"));
    m_providerCombo->addItem(tr("OpenAI"), QStringLiteral("openai"));
    m_providerCombo->addItem(tr("Anthropic"), QStringLiteral("anthropic"));
    m_providerCombo->addItem(tr("Custom"), QStringLiteral("custom"));
}

void SettingsDialog::loadModels()
{
    QString provider = getCurrentProvider();
    Models::LLMProvider providerEnum = Models::LLMConfig::providerFromString(provider);
    QStringList models = Models::LLMConfig::availableModels(providerEnum);

    // Check if we have cached models from API
    if (m_configManager) {
        QStringList cached = m_configManager->cachedModels(provider);
        if (!cached.isEmpty()) {
            models = cached;
        }
    }

    // Sort models alphabetically
    models.sort(Qt::CaseInsensitive);

    // Save current text before clearing
    QString currentText = m_modelCombo->currentText();

    m_modelCombo->clear();
    for (const QString& model : models) {
        m_modelCombo->addItem(model, model);
    }

    // Restore current text if it existed (handles manual entries)
    if (!currentText.isEmpty()) {
        int index = m_modelCombo->findText(currentText);
        if (index >= 0) {
            m_modelCombo->setCurrentIndex(index);
        } else {
            // Manual entry not in list, set it as text
            m_modelCombo->setCurrentText(currentText);
        }
    }
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

        m_promptsTable->setItem(i, 0, new QTableWidgetItem(prompt.name()));
        m_promptsTable->setItem(i, 1, new QTableWidgetItem(prompt.description()));
        m_promptsTable->setItem(i, 2, new QTableWidgetItem(
            Models::Prompt::contentTypeToString(prompt.contentType())
        ));
        m_promptsTable->setItem(i, 3, new QTableWidgetItem(prompt.model()));
    }

    m_promptsTable->resizeColumnsToContents();
}

QString SettingsDialog::getCurrentProvider() const
{
    return m_providerCombo->currentData().toString();
}

QString SettingsDialog::getCurrentModel() const
{
    // Use currentText() for editable combo box to get manual entries
    return m_modelCombo->currentText().trimmed();
}

void SettingsDialog::onTabChanged(int index)
{
    Q_UNUSED(index)

    if (m_tabWidget->currentWidget() != m_promptsTable->parentWidget()) {
        loadPrompts();
    }
}

void SettingsDialog::onApplyClicked()
{
    saveSettings();
}

void SettingsDialog::onOkClicked()
{
    saveSettings();
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
    emit languageChanged(m_languageCombo->currentData().toString());
}

void SettingsDialog::onProviderChanged(int index)
{
    Q_UNUSED(index)
    loadModels();

    // Enable refresh button only for providers with model API
    QString provider = getCurrentProvider();
    m_refreshModelsButton->setEnabled(
        provider == QStringLiteral("openrouter") ||
        provider == QStringLiteral("openai")
    );
}

void SettingsDialog::onModelChanged(int index)
{
    Q_UNUSED(index)
}

void SettingsDialog::onApiKeyChanged()
{
    // Update status based on key presence
    bool hasKey = !m_apiKeyEdit->text().isEmpty();
    m_connectionStatusLabel->setText(hasKey ? tr("API key set") : tr("No API key"));
}

void SettingsDialog::onTestConnectionClicked()
{
    // TODO: Implement test connection
    m_connectionStatusLabel->setText(tr("Testing..."));

    // For now, just check if we have an API key
    if (m_apiKeyEdit->text().isEmpty()) {
        m_connectionStatusLabel->setText(tr("Error: No API key"));
        m_connectionStatusLabel->setStyleSheet("color: red;");
        return;
    }

    m_connectionStatusLabel->setText(tr("Connected"));
    m_connectionStatusLabel->setStyleSheet("color: green;");
}

void SettingsDialog::onHotkeyChanged(const QKeySequence& sequence)
{
    emit hotkeyChanged(sequence);
}

void SettingsDialog::onAddPromptClicked()
{
    // TODO: Implement prompt editor dialog
    QMessageBox::information(this, tr("Add Prompt"),
                           tr("Prompt editor will be implemented in a future version."));
}

void SettingsDialog::onEditPromptClicked()
{
    // TODO: Implement prompt editor dialog
    QMessageBox::information(this, tr("Edit Prompt"),
                           tr("Prompt editor will be implemented in a future version."));
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
    }
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

    // TODO: Implement import
    QMessageBox::information(this, tr("Import Prompts"),
                           tr("Import will be implemented in a future version."));
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

void SettingsDialog::onAutoCleanupChanged(int state)
{
    m_daysToKeepSpin->setEnabled(state == Qt::Checked);
}

void SettingsDialog::onDaysToKeepChanged(int value)
{
    Q_UNUSED(value)
}

void SettingsDialog::onRefreshModelsClicked()
{
    QString provider = getCurrentProvider();
    if (provider.isEmpty()) {
        return;
    }

    fetchModelsFromAPI();
}

void SettingsDialog::fetchModelsFromAPI()
{
    QString provider = getCurrentProvider();
    QString apiKey = m_apiKeyEdit->text();

    QUrl url;
    QString authHeader;

    if (provider == QStringLiteral("openrouter")) {
        url = QUrl(QStringLiteral("https://openrouter.ai/api/v1/models"));
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    } else if (provider == QStringLiteral("openai")) {
        url = QUrl(QStringLiteral("https://api.openai.com/v1/models"));
        if (!apiKey.isEmpty()) {
            authHeader = QStringLiteral("Bearer ") + apiKey;
        }
    } else {
        m_connectionStatusLabel->setText(tr("Fetch not supported for this provider"));
        return;
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

    QString provider = getCurrentProvider();

    if (provider == QStringLiteral("openrouter")) {
        // OpenRouter format: { "data": [ { "id": "model/name", ... }, ... ] }
        QJsonArray modelArray = root.value(QStringLiteral("data")).toArray();
        for (const QJsonValue& value : modelArray) {
            QJsonObject modelObj = value.toObject();
            QString id = modelObj.value(QStringLiteral("id")).toString();
            if (!id.isEmpty()) {
                models.append(id);
            }
        }
    } else if (provider == QStringLiteral("openai")) {
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
    }

    if (models.isEmpty()) {
        m_connectionStatusLabel->setText(tr("No models found"));
    } else {
        // Sort models alphabetically
        models.sort(Qt::CaseInsensitive);

        // Save current selection (use text for editable combo box)
        QString currentModel = m_modelCombo->currentText().trimmed();

        // Update combo box (no "Auto" entry, user can type manually)
        m_modelCombo->clear();
        for (const QString& model : models) {
            m_modelCombo->addItem(model, model);
        }

        // Restore selection (use setText for editable combo box)
        if (!currentModel.isEmpty()) {
            int index = m_modelCombo->findText(currentModel);
            if (index >= 0) {
                m_modelCombo->setCurrentIndex(index);
            } else {
                m_modelCombo->setCurrentText(currentModel);
            }
        }

        // Cache models for future use
        if (m_configManager) {
            m_configManager->setCachedModels(provider, models);
        }

        m_connectionStatusLabel->setText(tr("Loaded %1 models").arg(models.size()));
        m_connectionStatusLabel->setStyleSheet("color: green;");
    }

    reply->deleteLater();
}

} // namespace UI
} // namespace ClipAI
