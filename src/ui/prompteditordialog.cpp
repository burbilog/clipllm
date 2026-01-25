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

#include "prompteditordialog.h"
#include "promptpreviewdialog.h"
#include "hotkeyedit.h"
#include "core/promptmanager.h"
#include "core/debuglogger.h"
#include "core/groupsmanager.h"
#include "core/configmanager.h"
#include "core/app.h"
#include <QApplication>
#include <QGroupBox>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QRegularExpression>
#include <QSet>
#include <QSettings>
#include <QFileDialog>
#include <QDateTime>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>

namespace ClipLLM {
namespace UI {

PromptEditorDialog::PromptEditorDialog(Core::PromptManager* promptManager,
                                        Core::GroupsManager* groupsManager,
                                        QWidget* parent)
    : QDialog(parent)
    , m_promptManager(promptManager)
    , m_groupsManager(groupsManager)
    , m_editMode(false)
{
    // Get ConfigManager from app
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        m_configManager = app->configManager();
    }

    // Create network manager for fetching models
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &PromptEditorDialog::onModelsFetchFinished);

    setupUi();
    loadProviders();
    setWindowTitle(tr("Add Prompt"));

    // Generate a unique ID for new prompts
    m_idEdit->setText(generateUniqueId());
    m_idEdit->setReadOnly(false);

    // Set default values
    m_temperatureSpin->setValue(0.7);
    m_maxTokensSpin->setValue(131072);
    m_enabledCheck->setChecked(true);
    m_contentTypeCombo->setCurrentIndex(2); // Any
    m_overrideProviderAndModelCheck->setChecked(false);  // Use defaults
    onOverrideProviderAndModelChanged(Qt::Unchecked);
    m_temperatureUseDefaultCheck->setChecked(true);
    updateTemperatureFieldState();

    validateInput();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("promptEditorDialog").toByteArray());
    settings.endGroup();
}

PromptEditorDialog::PromptEditorDialog(Core::PromptManager* promptManager,
                                        Core::GroupsManager* groupsManager,
                                        const Models::Prompt& prompt, QWidget* parent)
    : QDialog(parent)
    , m_promptManager(promptManager)
    , m_groupsManager(groupsManager)
    , m_originalPrompt(prompt)
    , m_editMode(true)
{
    // Get ConfigManager from app
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        m_configManager = app->configManager();
    }

    // Create network manager for fetching models
    m_networkManager = new QNetworkAccessManager(this);
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &PromptEditorDialog::onModelsFetchFinished);

    setupUi();
    loadProviders();
    setWindowTitle(tr("Edit Prompt"));

    loadPrompt(prompt);

    // ID field is read-only when editing
    m_idEdit->setReadOnly(true);

    validateInput();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("promptEditorDialog").toByteArray());
    settings.endGroup();
}

PromptEditorDialog::~PromptEditorDialog() = default;

Models::Prompt PromptEditorDialog::getPrompt() const
{
    return buildPrompt();
}

void PromptEditorDialog::setupUi()
{
    resize(600, 700);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Basic Information group
    QGroupBox* basicGroup = new QGroupBox(tr("Basic Information"));
    QFormLayout* basicLayout = new QFormLayout(basicGroup);

    m_idEdit = new QLineEdit();
    m_idEdit->setPlaceholderText(tr("e.g., custom_prompt"));
    connect(m_idEdit, &QLineEdit::textChanged, this, &PromptEditorDialog::validateInput);
    basicLayout->addRow(tr("ID:"), m_idEdit);

    m_nameEdit = new QLineEdit();
    m_nameEdit->setPlaceholderText(tr("e.g., My Custom Prompt"));
    connect(m_nameEdit, &QLineEdit::textChanged, this, &PromptEditorDialog::validateInput);
    basicLayout->addRow(tr("Name:"), m_nameEdit);

    m_descriptionEdit = new QLineEdit();
    m_descriptionEdit->setPlaceholderText(tr("e.g., Does something useful"));
    basicLayout->addRow(tr("Description:"), m_descriptionEdit);

    m_groupCombo = new QComboBox();
    m_groupCombo->addItem(tr("(root)"), QString());

    // Load groups from GroupsManager
    if (m_groupsManager) {
        QStringList groups = m_groupsManager->loadGroups();
        groups.sort(Qt::CaseInsensitive);

        for (const QString& group : groups) {
            // Add indentation for nested groups
            int depth = group.count(QLatin1Char('/'));
            QString indent = QString(depth * 2, QLatin1Char(' '));
            QString display = group;
            display.replace(QLatin1Char('/'), QStringLiteral(" → "));
            m_groupCombo->addItem(indent + display, group);
        }
    }

    // IMPORTANT: Set default selection to root (index 0) for new prompts
    // This prevents the last added group from being auto-selected
    m_groupCombo->setCurrentIndex(0);

    basicLayout->addRow(tr("Group:"), m_groupCombo);

    mainLayout->addWidget(basicGroup);

    // Prompts group
    QGroupBox* promptsGroup = new QGroupBox(tr("Prompts"));
    QVBoxLayout* promptsLayout = new QVBoxLayout(promptsGroup);

    promptsLayout->addWidget(new QLabel(tr("System Prompt:")));
    m_systemPromptEdit = new QTextEdit();
    m_systemPromptEdit->setPlaceholderText(
        tr("You are a helpful assistant...")
    );
    m_systemPromptEdit->setMaximumHeight(100);
    promptsLayout->addWidget(m_systemPromptEdit);

    promptsLayout->addWidget(new QLabel(tr("User Prompt Template:")));
    m_userTemplateEdit = new QTextEdit();
    m_userTemplateEdit->setPlaceholderText(
        tr("Process the following text:\n\n{clipboard}")
    );
    m_userTemplateEdit->setMaximumHeight(100);
    connect(m_userTemplateEdit, &QTextEdit::textChanged, this, &PromptEditorDialog::validateInput);
    promptsLayout->addWidget(m_userTemplateEdit);

    QLabel* placeholderHint = new QLabel(
        tr("Use {clipboard} to insert clipboard content, {clipboard:1000} for truncated content, {language} for user's language.")
    );
    placeholderHint->setStyleSheet("color: gray; font-size: 10px;");
    promptsLayout->addWidget(placeholderHint);

    mainLayout->addWidget(promptsGroup);

    // Settings group
    QGroupBox* settingsGroup = new QGroupBox(tr("Settings"));
    QFormLayout* settingsLayout = new QFormLayout(settingsGroup);

    m_contentTypeCombo = new QComboBox();
    m_contentTypeCombo->addItem(tr("Text"), QStringLiteral("text"));
    m_contentTypeCombo->addItem(tr("Image"), QStringLiteral("image"));
    m_contentTypeCombo->addItem(tr("Any"), QStringLiteral("any"));
    settingsLayout->addRow(tr("Content Type:"), m_contentTypeCombo);

    // Unified provider and model override
    m_overrideProviderAndModelCheck = new QCheckBox(tr("Override provider and model"));
    m_overrideProviderAndModelCheck->setToolTip(tr("When checked, use specific provider and model instead of defaults"));
    connect(m_overrideProviderAndModelCheck, &QCheckBox::checkStateChanged,
            this, &PromptEditorDialog::onOverrideProviderAndModelChanged);
    settingsLayout->addRow(m_overrideProviderAndModelCheck);

    m_providerCombo = new QComboBox();
    m_providerCombo->setToolTip(tr("Select provider for this prompt"));
    connect(m_providerCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &PromptEditorDialog::onProviderChanged);
    settingsLayout->addRow(tr("Provider:"), m_providerCombo);

    // Model combo with refresh button
    QHBoxLayout* modelLayout = new QHBoxLayout();
    m_modelCombo = new QComboBox();
    m_modelCombo->setEditable(true);
    m_modelCombo->setToolTip(tr("Select or enter model name"));
    modelLayout->addWidget(m_modelCombo, 1);

    m_refreshModelsButton = new QPushButton(tr("Refresh"));
    m_refreshModelsButton->setEnabled(false);
    connect(m_refreshModelsButton, &QPushButton::clicked,
            this, &PromptEditorDialog::onRefreshModelsClicked);
    modelLayout->addWidget(m_refreshModelsButton);

    m_modelsStatusLabel = new QLabel();
    m_modelsStatusLabel->setWordWrap(true);
    m_modelsStatusLabel->setStyleSheet("color: gray; font-size: 10px;");
    modelLayout->addWidget(m_modelsStatusLabel);

    settingsLayout->addRow(tr("Model:"), modelLayout);

    // Temperature field with checkbox
    m_temperatureUseDefaultCheck = new QCheckBox(tr("Use default temperature from settings"));
    connect(m_temperatureUseDefaultCheck, &QCheckBox::checkStateChanged,
            this, &PromptEditorDialog::onTemperatureUseDefaultChanged);
    settingsLayout->addRow(m_temperatureUseDefaultCheck);

    m_temperatureSpin = new QDoubleSpinBox();
    m_temperatureSpin->setRange(0.0, 2.0);
    m_temperatureSpin->setSingleStep(0.1);
    settingsLayout->addRow(tr("Temperature:"), m_temperatureSpin);

    m_maxTokensSpin = new QSpinBox();
    m_maxTokensSpin->setRange(1, 128000);
    m_maxTokensSpin->setSingleStep(512);
    settingsLayout->addRow(tr("Max Tokens:"), m_maxTokensSpin);

    m_enabledCheck = new QCheckBox(tr("Enabled"));
    m_enabledCheck->setChecked(true);
    settingsLayout->addRow(m_enabledCheck);

    m_prioritySpin = new QSpinBox();
    m_prioritySpin->setRange(0, 1000);
    m_prioritySpin->setSingleStep(10);
    m_prioritySpin->setValue(0);
    m_prioritySpin->setToolTip(tr("Higher priority prompts appear first in the menu"));
    settingsLayout->addRow(tr("Priority (higher = first):"), m_prioritySpin);

    m_hotkeyEdit = new HotkeyEdit();
    m_hotkeyEdit->setPlaceholderText(tr("None"));
    m_hotkeyEdit->setToolTip(tr("Optional global hotkey to directly execute this prompt"));
    connect(m_hotkeyEdit, &HotkeyEdit::keySequenceChanged, this, &PromptEditorDialog::onHotkeyChanged);
    connect(m_hotkeyEdit, &HotkeyEdit::recordingStarted, this, [this]() {
        // Unregister prompt hotkeys while recording to prevent accidental triggering
        m_isRecordingHotkey = true;
        App* app = qobject_cast<App*>(QApplication::instance());
        if (app) {
            app->unregisterPromptHotkeys();
        }
    });
    connect(m_hotkeyEdit, &HotkeyEdit::recordingFinished,
            this, &PromptEditorDialog::onHotkeyRecordingFinished);
    settingsLayout->addRow(tr("Hotkey:"), m_hotkeyEdit);

    // Initialize flag - prompt hotkeys are currently registered
    m_isRecordingHotkey = false;

    mainLayout->addWidget(settingsGroup);

    // Validation label
    m_validationLabel = new QLabel();
    m_validationLabel->setWordWrap(true);
    m_validationLabel->setStyleSheet("color: red;");
    mainLayout->addWidget(m_validationLabel);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    QPushButton* exportButton = new QPushButton(tr("Export"));
    connect(exportButton, &QPushButton::clicked, this, &PromptEditorDialog::onExportClicked);
    buttonLayout->addWidget(exportButton);

    QPushButton* previewButton = new QPushButton(tr("Prompt Preview"));
    connect(previewButton, &QPushButton::clicked, this, &PromptEditorDialog::onPreviewClicked);
    buttonLayout->addWidget(previewButton);

    m_okButton = new QPushButton(tr("OK"));
    m_okButton->setDefault(true);
    connect(m_okButton, &QPushButton::clicked, this, &PromptEditorDialog::onOkClicked);
    buttonLayout->addWidget(m_okButton);

    QPushButton* cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, &QPushButton::clicked, this, &QDialog::reject);
    buttonLayout->addWidget(cancelButton);

    mainLayout->addLayout(buttonLayout);
}

void PromptEditorDialog::loadPrompt(const Models::Prompt& prompt)
{
    m_idEdit->setText(prompt.id());
    m_nameEdit->setText(prompt.name());
    m_descriptionEdit->setText(prompt.description());

    // Set group - explicitly handle empty group (root)
    QString group = prompt.group();
    LOG_DEBUG(QStringLiteral("Loading prompt with group: %1 (isEmpty: %2)").arg(group).arg(group.isEmpty()));

    if (group.isEmpty()) {
        m_groupCombo->setCurrentIndex(0); // root is always at index 0
        LOG_DEBUG(QStringLiteral("Set group combo to index 0 (root)"));
    } else {
        int groupIndex = m_groupCombo->findData(group);
        LOG_DEBUG(QStringLiteral("Looking for group: %1 found at index: %2").arg(group).arg(groupIndex));
        if (groupIndex >= 0) {
            m_groupCombo->setCurrentIndex(groupIndex);
        } else {
            m_groupCombo->setCurrentIndex(0); // fallback to root
            LOG_DEBUG(QStringLiteral("Group not found, setting to root"));
        }
    }

    m_systemPromptEdit->setPlainText(prompt.systemPrompt());
    m_userTemplateEdit->setPlainText(prompt.userPromptTemplate());

    // Content type
    QString contentTypeStr = Models::Prompt::contentTypeToString(prompt.contentType());
    int contentTypeIndex = m_contentTypeCombo->findData(contentTypeStr);
    if (contentTypeIndex >= 0) {
        m_contentTypeCombo->setCurrentIndex(contentTypeIndex);
    }

    // Provider and model - unified override
    m_overrideProviderAndModelCheck->blockSignals(true);
    m_providerCombo->blockSignals(true);
    m_modelCombo->blockSignals(true);

    if (!prompt.overrideProvider()) {
        // Use default - checkbox unchecked, fields disabled
        m_overrideProviderAndModelCheck->setChecked(false);
    } else {
        // Override - checkbox checked, load specific values
        m_overrideProviderAndModelCheck->setChecked(true);

        // Load provider
        if (!prompt.providerId().isEmpty()) {
            int providerIndex = m_providerCombo->findData(prompt.providerId());
            if (providerIndex >= 0) {
                m_providerCombo->setCurrentIndex(providerIndex);
            }
        }

        // Load model
        if (!prompt.model().isEmpty()) {
            m_modelCombo->setCurrentText(prompt.model());
        }
    }

    // Enable/disable based on checkbox state
    onOverrideProviderAndModelChanged(static_cast<int>(m_overrideProviderAndModelCheck->checkState()));

    m_overrideProviderAndModelCheck->blockSignals(false);
    m_providerCombo->blockSignals(false);
    m_modelCombo->blockSignals(false);

    m_temperatureSpin->setValue(prompt.temperature());
    m_temperatureUseDefaultCheck->setChecked(!prompt.overrideTemperature());
    updateTemperatureFieldState();

    m_maxTokensSpin->setValue(prompt.maxTokens());
    m_enabledCheck->setChecked(prompt.enabled());
    m_prioritySpin->setValue(prompt.priority());
    m_hotkeyEdit->setHotkeyText(prompt.hotkey());
}

Models::Prompt PromptEditorDialog::buildPrompt() const
{
    Models::Prompt prompt;

    prompt.setId(m_idEdit->text().trimmed());
    prompt.setName(m_nameEdit->text().trimmed());
    prompt.setDescription(m_descriptionEdit->text().trimmed());

    // Get group from combo - handle empty group case
    int comboIndex = m_groupCombo->currentIndex();
    QString group = m_groupCombo->currentData().toString();
    LOG_DEBUG(QStringLiteral("buildPrompt: comboIndex=%1 currentData=%2").arg(comboIndex).arg(group));

    // If index is 0 (root), ensure group is empty string
    if (comboIndex == 0) {
        group.clear();
    }
    prompt.setGroup(group);
    LOG_DEBUG(QStringLiteral("buildPrompt: setting group to: %1").arg(group));

    prompt.setSystemPrompt(m_systemPromptEdit->toPlainText());
    prompt.setUserPromptTemplate(m_userTemplateEdit->toPlainText());

    // Content type
    QString contentTypeStr = m_contentTypeCombo->currentData().toString();
    prompt.setContentType(Models::Prompt::contentTypeFromString(contentTypeStr));

    // Provider and model - unified override
    if (m_overrideProviderAndModelCheck->isChecked()) {
        // Override - use specific provider and model
        prompt.setProviderId(m_providerCombo->currentData().toString());
        prompt.setOverrideProvider(true);
        prompt.setModel(m_modelCombo->currentText().trimmed());
    } else {
        // Use defaults from settings
        prompt.setProviderId(QString());
        prompt.setOverrideProvider(false);
        prompt.setModel(QString());
    }

    prompt.setTemperature(m_temperatureSpin->value());
    prompt.setOverrideTemperature(!m_temperatureUseDefaultCheck->isChecked());
    prompt.setMaxTokens(m_maxTokensSpin->value());
    prompt.setEnabled(m_enabledCheck->isChecked());
    prompt.setPriority(m_prioritySpin->value());
    prompt.setHotkey(m_hotkeyEdit->hotkeyText());

    return prompt;
}

void PromptEditorDialog::updateTemperatureFieldState()
{
    if (m_temperatureUseDefaultCheck->isChecked()) {
        m_temperatureSpin->setEnabled(false);
    } else {
        m_temperatureSpin->setEnabled(true);
    }
}

void PromptEditorDialog::onOverrideProviderAndModelChanged(int state)
{
    bool enabled = (state == Qt::Checked);
    m_providerCombo->setEnabled(enabled);
    m_modelCombo->setEnabled(enabled);
    m_refreshModelsButton->setEnabled(enabled);

    // Clear status label when disabled
    if (!enabled) {
        m_modelsStatusLabel->clear();
    }
}

void PromptEditorDialog::onProviderChanged(int index)
{
    if (index < 0) {
        return;
    }
    QString providerId = m_providerCombo->currentData().toString();
    loadModelsForProvider(providerId);
}

void PromptEditorDialog::loadModelsForProvider(const QString& providerId)
{
    if (!m_configManager || providerId.isEmpty()) {
        m_modelCombo->clear();
        m_modelCombo->addItem(tr("(Select provider first)"), QString());
        return;
    }

    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        m_modelCombo->clear();
        m_modelCombo->addItem(tr("(Provider not found)"), QString());
        return;
    }

    const auto& profile = profileOpt.value();

    // Get templates to find suggested models
    auto templates = Models::ProviderProfile::availableTemplates();
    QString suggestedModel;

    // Try to match by name first, then by URL
    for (const auto& tmpl : templates) {
        if (tmpl.name == profile.name() || tmpl.templateUrl == profile.apiUrl().toString()) {
            if (!tmpl.defaultModel.isEmpty()) {
                suggestedModel = tmpl.defaultModel;
            }
            // Load suggested models
            m_modelCombo->clear();
            m_modelCombo->addItem(tr("(Custom model...)"), QString());
            for (const QString& model : tmpl.suggestedModels) {
                m_modelCombo->addItem(model, model);
            }
            break;
        }
    }

    // If no template matched, just add custom option
    if (m_modelCombo->count() == 0) {
        m_modelCombo->clear();
        m_modelCombo->addItem(tr("(Custom model...)"), QString());
    }

    // Set current model from profile if available
    if (!profile.model().isEmpty()) {
        m_modelCombo->setCurrentText(profile.model());
    } else if (!suggestedModel.isEmpty()) {
        m_modelCombo->setCurrentText(suggestedModel);
    }
}

void PromptEditorDialog::loadProviders()
{
    // Block signals during population
    m_providerCombo->blockSignals(true);
    m_providerCombo->clear();

    if (!m_configManager) {
        m_providerCombo->addItem(tr("(No providers available)"), QString());
        m_providerCombo->setEnabled(false);
        m_providerCombo->blockSignals(false);
        return;
    }

    auto profiles = m_configManager->providerProfiles();

    if (profiles.isEmpty()) {
        m_providerCombo->addItem(tr("(No providers configured)"), QString());
        m_providerCombo->setEnabled(false);
        m_providerCombo->blockSignals(false);
        return;
    }

    // Add all enabled profiles
    for (const auto& profile : profiles) {
        if (profile.enabled()) {
            QString display = profile.name();
            if (profile.isDefault()) {
                display += QStringLiteral(" (*)");
            }
            m_providerCombo->addItem(display, profile.id());
        }
    }

    // Select default provider if available
    QString defaultProviderId = m_configManager->defaultProviderId();
    if (!defaultProviderId.isEmpty()) {
        int defaultIndex = m_providerCombo->findData(defaultProviderId);
        if (defaultIndex >= 0) {
            m_providerCombo->setCurrentIndex(defaultIndex);
        }
    }

    // Load models for selected provider
    if (m_providerCombo->count() > 0) {
        loadModelsForProvider(m_providerCombo->currentData().toString());
    }

    m_providerCombo->blockSignals(false);
}

QString PromptEditorDialog::generateUniqueId() const
{
    if (!m_promptManager) {
        return QStringLiteral("custom_prompt_1");
    }

    QSet<QString> existingIds;
    for (const auto& prompt : m_promptManager->getAllPrompts()) {
        existingIds.insert(prompt.id());
    }

    int counter = 1;
    QString id;
    do {
        id = QStringLiteral("custom_prompt_%1").arg(counter);
        counter++;
    } while (existingIds.contains(id));

    return id;
}

void PromptEditorDialog::onTemperatureUseDefaultChanged(int state)
{
    Q_UNUSED(state)
    updateTemperatureFieldState();
}

void PromptEditorDialog::validateInput()
{
    QStringList errors;

    // Check required fields
    if (m_nameEdit->text().trimmed().isEmpty()) {
        errors.append(tr("Name is required"));
    }

    if (m_idEdit->text().trimmed().isEmpty()) {
        errors.append(tr("ID is required"));
    }

    // Check for valid placeholder syntax in both prompts
    QString templateStr = m_userTemplateEdit->toPlainText();
    QString systemStr = m_systemPromptEdit->toPlainText();
    QRegularExpression placeholderRe(QStringLiteral(R"(\{(?:clipboard|clipboard:\d+|language)\})"));

    // Check for invalid placeholders in user template
    QRegularExpression allBracesRe(QStringLiteral(R"(\{[^}]+\})"));
    QRegularExpressionMatchIterator allIt = allBracesRe.globalMatch(templateStr);
    while (allIt.hasNext()) {
        QRegularExpressionMatch match = allIt.next();
        QString captured = match.captured(0);
        if (!placeholderRe.match(captured).hasMatch()) {
            errors.append(tr("Invalid placeholder in user template: %1").arg(captured));
        }
    }

    // Check for invalid placeholders in system prompt
    allIt = allBracesRe.globalMatch(systemStr);
    while (allIt.hasNext()) {
        QRegularExpressionMatch match = allIt.next();
        QString captured = match.captured(0);
        if (!placeholderRe.match(captured).hasMatch()) {
            errors.append(tr("Invalid placeholder in system prompt: %1").arg(captured));
        }
    }

    // For new prompts, check ID uniqueness
    if (!m_editMode && m_promptManager) {
        QString newId = m_idEdit->text().trimmed();
        if (!newId.isEmpty()) {
            auto existing = m_promptManager->getPrompt(newId);
            if (existing.has_value()) {
                errors.append(tr("ID already exists: %1").arg(newId));
            }
        }
    }

    // Update validation label
    if (errors.isEmpty()) {
        m_validationLabel->clear();
        m_okButton->setEnabled(true);
    } else {
        m_validationLabel->setText(errors.join('\n'));
        m_okButton->setEnabled(false);
    }
}

void PromptEditorDialog::onOkClicked()
{
    Models::Prompt prompt = buildPrompt();

    // Additional validation via PromptManager
    if (m_promptManager && !m_promptManager->validatePrompt(prompt)) {
        QStringList validationErrors = m_promptManager->getValidationErrors(prompt);
        QMessageBox::warning(this, tr("Validation Error"),
                           tr("The prompt has validation errors:\n\n%1")
                           .arg(validationErrors.join('\n')));
        return;
    }

    accept();
}

void PromptEditorDialog::onPreviewClicked()
{
    Models::Prompt prompt = buildPrompt();

    PromptPreviewDialog* previewDialog = new PromptPreviewDialog(prompt, this);
    previewDialog->setAttribute(Qt::WA_DeleteOnClose);
    previewDialog->exec();
}

void PromptEditorDialog::onExportClicked()
{
    Models::Prompt prompt = buildPrompt();

    // Validate prompt before export
    if (!prompt.isValid()) {
        QMessageBox::warning(this, tr("Export Prompt"),
                           tr("Cannot export: prompt is not valid."));
        return;
    }

    // Generate default filename: prompt_{id}_{date}.json
    QString defaultFileName = QStringLiteral("prompt_%1_%2.json")
        .arg(prompt.id())
        .arg(QDateTime::currentDateTime().toString("yyyyMMdd"));

    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Export Prompt"),
        defaultFileName,
        tr("JSON Files (*.json)")
    );

    if (fileName.isEmpty()) {
        return;
    }

    // Create JSON in the same format as full export
    QJsonObject root;
    root[QStringLiteral("version")] = QStringLiteral("1.0");

    QJsonArray promptsArray;
    promptsArray.append(prompt.toJson());
    root[QStringLiteral("prompts")] = promptsArray;

    QJsonDocument doc(root);

    // Write to file
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, tr("Export Prompt"),
                           tr("Failed to open file for writing: %1").arg(fileName));
        return;
    }

    file.write(doc.toJson(QJsonDocument::Indented));
    file.close();

    QMessageBox::information(this, tr("Export Prompt"),
                           tr("Prompt exported to %1").arg(fileName));
}

void PromptEditorDialog::closeEvent(QCloseEvent* event)
{
    // Ensure prompt hotkeys are re-registered when dialog closes
    // (in case they were left unregistered due to conflict or user pressed record then closed)
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        app->registerPromptHotkeys();
    }

    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("promptEditorDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

void PromptEditorDialog::onRefreshModelsClicked()
{
    QString providerId = m_providerCombo->currentData().toString();
    if (providerId.isEmpty()) {
        m_modelsStatusLabel->setText(tr("No provider selected"));
        m_modelsStatusLabel->setStyleSheet("color: red; font-size: 10px;");
        return;
    }

    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        m_modelsStatusLabel->setText(tr("Provider not found"));
        m_modelsStatusLabel->setStyleSheet("color: red; font-size: 10px;");
        return;
    }

    // Check if provider URL supports model fetching (not Anthropic)
    QString apiUrl = profileOpt->apiUrl().toString();
    if (apiUrl.contains(QStringLiteral("anthropic.com"))) {
        m_modelsStatusLabel->setText(tr("Model fetching not supported for this provider"));
        m_modelsStatusLabel->setStyleSheet("color: orange; font-size: 10px;");
        return;
    }

    fetchModelsFromAPI();
}

void PromptEditorDialog::fetchModelsFromAPI()
{
    QString providerId = m_providerCombo->currentData().toString();
    if (providerId.isEmpty()) {
        return;
    }

    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        return;
    }

    const auto& profile = profileOpt.value();
    QString apiUrl = profile.apiUrl().toString();

    LOG_DEBUG(QStringLiteral("=== PromptEditor: Fetching models ==="));
    LOG_DEBUG(QStringLiteral("Provider ID: %1").arg(providerId));
    LOG_DEBUG(QStringLiteral("Provider name: %1").arg(profile.name()));
    LOG_DEBUG(QStringLiteral("Original API URL: %1").arg(apiUrl));

    // Build models endpoint URL - same logic as SettingsDialog
    QUrl url = QUrl(apiUrl);
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

    LOG_DEBUG(QStringLiteral("Models URL: %1").arg(url.toString()));

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, QStringLiteral("application/json"));
    request.setHeader(QNetworkRequest::UserAgentHeader, QStringLiteral("ClipLLM/1.0"));

    // Note: API key not included here as many providers don't require it for model listing
    // For providers that require authentication, the user can manually enter the model

    m_modelsStatusLabel->setText(tr("Fetching models..."));
    m_modelsStatusLabel->setStyleSheet("color: blue; font-size: 10px;");
    m_refreshModelsButton->setEnabled(false);

    m_networkManager->get(request);
}

void PromptEditorDialog::onModelsFetchFinished(QNetworkReply* reply)
{
    m_refreshModelsButton->setEnabled(true);

    if (reply->error() != QNetworkReply::NoError) {
        LOG_DEBUG(QStringLiteral("PromptEditor: Model fetch error: %1").arg(reply->errorString()));
        LOG_DEBUG(QStringLiteral("HTTP status: %1").arg(reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt()));
        QByteArray response = reply->readAll();
        LOG_DEBUG(QStringLiteral("Response body: %1").arg(QString::fromUtf8(response.left(500))));
        m_modelsStatusLabel->setText(tr("Error: %1").arg(reply->errorString()));
        m_modelsStatusLabel->setStyleSheet("color: red; font-size: 10px;");
        reply->deleteLater();
        return;
    }

    QByteArray data = reply->readAll();
    LOG_DEBUG(QStringLiteral("PromptEditor: Received response, size: %1").arg(data.size()));
    QJsonDocument doc = QJsonDocument::fromJson(data);

    if (doc.isNull() || !doc.isObject()) {
        LOG_DEBUG(QStringLiteral("PromptEditor: Invalid JSON response"));
        LOG_DEBUG(QStringLiteral("Response: %1").arg(QString::fromUtf8(data.left(500))));
        m_modelsStatusLabel->setText(tr("Error: Invalid response"));
        m_modelsStatusLabel->setStyleSheet("color: red; font-size: 10px;");
        reply->deleteLater();
        return;
    }

    QJsonObject root = doc.object();
    QJsonArray modelArray = root.value(QStringLiteral("data")).toArray();

    LOG_DEBUG(QStringLiteral("PromptEditor: Found %1 models").arg(modelArray.size()));

    if (modelArray.isEmpty()) {
        m_modelsStatusLabel->setText(tr("No models found"));
        m_modelsStatusLabel->setStyleSheet("color: orange; font-size: 10px;");
        reply->deleteLater();
        return;
    }

    // Save current selection
    QString currentModel = m_modelCombo->currentText().trimmed();

    // Update combo box
    m_modelCombo->clear();
    m_modelCombo->addItem(tr("(Custom model...)"), QString());

    // Collect model names and sort them
    QStringList models;
    for (const QJsonValue& value : modelArray) {
        QJsonObject modelObj = value.toObject();
        QString id = modelObj.value(QStringLiteral("id")).toString();
        if (!id.isEmpty()) {
            models.append(id);
        }
    }
    models.sort(Qt::CaseInsensitive);

    // Add sorted models
    for (const QString& model : models) {
        m_modelCombo->addItem(model, model);
    }

    // Restore selection
    if (!currentModel.isEmpty()) {
        m_modelCombo->setCurrentText(currentModel);
    }

    // Expand the combo box to show models
    m_modelCombo->showPopup();

    m_modelsStatusLabel->setText(tr("Loaded %1 models").arg(models.size()));
    m_modelsStatusLabel->setStyleSheet("color: green; font-size: 10px;");

    reply->deleteLater();
}

void PromptEditorDialog::onHotkeyChanged(const QKeySequence& sequence)
{
    // Ignore changes during recording - we'll handle it in recordingFinished
    if (m_isRecordingHotkey) {
        return;
    }
    Q_UNUSED(sequence)
}

void PromptEditorDialog::onHotkeyRecordingFinished()
{
    m_isRecordingHotkey = false;

    // Re-register prompt hotkeys first
    App* app = qobject_cast<App*>(QApplication::instance());
    if (app) {
        app->registerPromptHotkeys();
    }

    QKeySequence seq = m_hotkeyEdit->keySequence();

    if (seq.isEmpty()) {
        return;
    }

    // Check for conflicts
    if (checkHotkeyConflict(seq)) {
        m_hotkeyEdit->blockSignals(true);
        m_hotkeyEdit->setHotkeyText(QString());
        m_hotkeyEdit->blockSignals(false);

        QMessageBox::warning(this,
            tr("Hotkey Conflict"),
            tr("This hotkey is already in use by another prompt or the global hotkey.\n\nPlease choose a different hotkey."));
        // Do NOT save - hotkey was cleared
    }
    // If no conflict, hotkey remains set and will be saved when user clicks OK
}

bool PromptEditorDialog::checkHotkeyConflict(const QKeySequence& seq) const
{
    if (!m_configManager || !m_promptManager) {
        return false;
    }

    // Check conflict with global hotkey
    QKeySequence globalHotkeySeq = QKeySequence::fromString(m_configManager->hotkey());
    if (!globalHotkeySeq.isEmpty() && seq == globalHotkeySeq) {
        return true;
    }

    // Check conflict with other prompts
    QVector<Models::Prompt> allPrompts = m_promptManager->getAllPrompts();
    for (const auto& prompt : allPrompts) {
        // Skip current prompt when editing
        if (m_editMode && prompt.id() == m_originalPrompt.id()) {
            continue;
        }

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
