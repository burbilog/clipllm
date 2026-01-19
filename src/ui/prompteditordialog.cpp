#include "prompteditordialog.h"
#include "promptpreviewdialog.h"
#include "core/promptmanager.h"
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

namespace ClipAI {
namespace UI {

PromptEditorDialog::PromptEditorDialog(Core::PromptManager* promptManager, QWidget* parent)
    : QDialog(parent)
    , m_promptManager(promptManager)
    , m_editMode(false)
{
    setupUi();
    setWindowTitle(tr("Add Prompt"));

    // Generate a unique ID for new prompts
    m_idEdit->setText(generateUniqueId());
    m_idEdit->setReadOnly(false);

    // Set default values
    m_temperatureSpin->setValue(0.7);
    m_maxTokensSpin->setValue(131072);
    m_enabledCheck->setChecked(true);
    m_contentTypeCombo->setCurrentIndex(2); // Any
    m_iconCombo->setCurrentIndex(0); // None
    m_modelUseDefaultCheck->setChecked(true);
    updateModelFieldState();
    m_temperatureUseDefaultCheck->setChecked(true);
    updateTemperatureFieldState();

    validateInput();
}

PromptEditorDialog::PromptEditorDialog(Core::PromptManager* promptManager,
                                       const Models::Prompt& prompt, QWidget* parent)
    : QDialog(parent)
    , m_promptManager(promptManager)
    , m_originalPrompt(prompt)
    , m_editMode(true)
{
    setupUi();
    setWindowTitle(tr("Edit Prompt"));

    loadPrompt(prompt);

    // ID field is read-only when editing
    m_idEdit->setReadOnly(true);

    validateInput();
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

    m_iconCombo = new QComboBox();
    m_iconCombo->addItem(tr("None"), QStringLiteral("none"));
    m_iconCombo->addItem(tr("Text Summary"), QStringLiteral("text-summary"));
    m_iconCombo->addItem(tr("Translate"), QStringLiteral("translate"));
    m_iconCombo->addItem(tr("Code Review"), QStringLiteral("code-review"));
    m_iconCombo->addItem(tr("Refactor"), QStringLiteral("refactor"));
    m_iconCombo->addItem(tr("Explain"), QStringLiteral("explain"));
    m_iconCombo->addItem(tr("Custom"), QStringLiteral("custom"));
    settingsLayout->addRow(tr("Icon:"), m_iconCombo);

    // Model field with checkbox
    m_modelUseDefaultCheck = new QCheckBox(tr("Use default model from settings"));
    connect(m_modelUseDefaultCheck, &QCheckBox::checkStateChanged,
            this, &PromptEditorDialog::onModelUseDefaultChanged);
    settingsLayout->addRow(m_modelUseDefaultCheck);

    m_modelEdit = new QLineEdit();
    m_modelEdit->setPlaceholderText(tr("e.g., openai/gpt-4, anthropic/claude-3-opus"));
    settingsLayout->addRow(tr("Model:"), m_modelEdit);

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

    mainLayout->addWidget(settingsGroup);

    // Validation label
    m_validationLabel = new QLabel();
    m_validationLabel->setWordWrap(true);
    m_validationLabel->setStyleSheet("color: red;");
    mainLayout->addWidget(m_validationLabel);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

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
    m_systemPromptEdit->setPlainText(prompt.systemPrompt());
    m_userTemplateEdit->setPlainText(prompt.userPromptTemplate());

    // Content type
    QString contentTypeStr = Models::Prompt::contentTypeToString(prompt.contentType());
    int contentTypeIndex = m_contentTypeCombo->findData(contentTypeStr);
    if (contentTypeIndex >= 0) {
        m_contentTypeCombo->setCurrentIndex(contentTypeIndex);
    }

    // Icon
    QString iconStr = Models::Prompt::iconToString(prompt.icon());
    int iconIndex = m_iconCombo->findData(iconStr.isEmpty() ? QStringLiteral("none") : iconStr);
    if (iconIndex >= 0) {
        m_iconCombo->setCurrentIndex(iconIndex);
    }

    // Model - if empty, use default
    if (prompt.model().isEmpty()) {
        m_modelUseDefaultCheck->setChecked(true);
        m_modelEdit->clear();
    } else {
        m_modelUseDefaultCheck->setChecked(false);
        m_modelEdit->setText(prompt.model());
    }
    updateModelFieldState();

    m_temperatureSpin->setValue(prompt.temperature());
    m_temperatureUseDefaultCheck->setChecked(!prompt.overrideTemperature());
    updateTemperatureFieldState();

    m_maxTokensSpin->setValue(prompt.maxTokens());
    m_enabledCheck->setChecked(prompt.enabled());
    m_prioritySpin->setValue(prompt.priority());
}

Models::Prompt PromptEditorDialog::buildPrompt() const
{
    Models::Prompt prompt;

    prompt.setId(m_idEdit->text().trimmed());
    prompt.setName(m_nameEdit->text().trimmed());
    prompt.setDescription(m_descriptionEdit->text().trimmed());
    prompt.setSystemPrompt(m_systemPromptEdit->toPlainText());
    prompt.setUserPromptTemplate(m_userTemplateEdit->toPlainText());

    // Content type
    QString contentTypeStr = m_contentTypeCombo->currentData().toString();
    prompt.setContentType(Models::Prompt::contentTypeFromString(contentTypeStr));

    // Icon
    QString iconStr = m_iconCombo->currentData().toString();
    if (iconStr == QStringLiteral("none")) {
        iconStr.clear();
    }
    prompt.setIcon(Models::Prompt::iconFromString(iconStr));

    // Model - if checkbox is checked, use empty string (default)
    if (m_modelUseDefaultCheck->isChecked()) {
        prompt.setModel(QString());
    } else {
        prompt.setModel(m_modelEdit->text().trimmed());
    }

    prompt.setTemperature(m_temperatureSpin->value());
    prompt.setOverrideTemperature(!m_temperatureUseDefaultCheck->isChecked());
    prompt.setMaxTokens(m_maxTokensSpin->value());
    prompt.setEnabled(m_enabledCheck->isChecked());
    prompt.setPriority(m_prioritySpin->value());

    return prompt;
}

void PromptEditorDialog::updateModelFieldState()
{
    if (m_modelUseDefaultCheck->isChecked()) {
        m_modelEdit->setEnabled(false);
        m_modelEdit->setPlaceholderText(tr("Uses global default model"));
    } else {
        m_modelEdit->setEnabled(true);
        m_modelEdit->setPlaceholderText(tr("e.g., openai/gpt-4, anthropic/claude-3-opus"));
    }
}

void PromptEditorDialog::updateTemperatureFieldState()
{
    if (m_temperatureUseDefaultCheck->isChecked()) {
        m_temperatureSpin->setEnabled(false);
    } else {
        m_temperatureSpin->setEnabled(true);
    }
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

void PromptEditorDialog::onModelUseDefaultChanged(int state)
{
    Q_UNUSED(state)
    updateModelFieldState();
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

} // namespace UI
} // namespace ClipAI
