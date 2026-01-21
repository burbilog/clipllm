#ifndef CLIPAI_UI_PROMPTEDITORDIALOG_H
#define CLIPAI_UI_PROMPTEDITORDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include "models/prompt.h"
#include "models/providerprofile.h"

namespace ClipAI {
namespace Core {
class PromptManager;
class GroupsManager;
class ConfigManager;
}
namespace UI {

class PromptEditorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PromptEditorDialog(Core::PromptManager* promptManager,
                                Core::GroupsManager* groupsManager,
                                QWidget* parent = nullptr);
    explicit PromptEditorDialog(Core::PromptManager* promptManager,
                                Core::GroupsManager* groupsManager,
                                const Models::Prompt& prompt, QWidget* parent = nullptr);
    ~PromptEditorDialog();

    Models::Prompt getPrompt() const;

protected:
    void closeEvent(QCloseEvent* event) override;

private slots:
    void onOkClicked();
    void onPreviewClicked();
    void onModelUseDefaultChanged(int state);
    void onTemperatureUseDefaultChanged(int state);
    void onProviderUseDefaultChanged(int state);
    void validateInput();

private:
    void setupUi();
    void loadPrompt(const Models::Prompt& prompt);
    Models::Prompt buildPrompt() const;
    void updateModelFieldState();
    void updateTemperatureFieldState();
    void updateProviderFieldState();
    void loadProviders();
    QString generateUniqueId() const;

    Core::PromptManager* m_promptManager = nullptr;
    Core::GroupsManager* m_groupsManager = nullptr;
    Core::ConfigManager* m_configManager = nullptr;
    Models::Prompt m_originalPrompt;
    bool m_editMode = false;

    // Basic info fields
    QLineEdit* m_idEdit = nullptr;
    QLineEdit* m_nameEdit = nullptr;
    QLineEdit* m_descriptionEdit = nullptr;
    QComboBox* m_groupCombo = nullptr;

    // Prompt fields
    QTextEdit* m_systemPromptEdit = nullptr;
    QTextEdit* m_userTemplateEdit = nullptr;

    // Settings fields
    QComboBox* m_contentTypeCombo = nullptr;
    QCheckBox* m_providerUseDefaultCheck = nullptr;
    QComboBox* m_providerCombo = nullptr;
    QCheckBox* m_modelUseDefaultCheck = nullptr;
    QLineEdit* m_modelEdit = nullptr;
    QCheckBox* m_temperatureUseDefaultCheck = nullptr;
    QDoubleSpinBox* m_temperatureSpin = nullptr;
    QSpinBox* m_maxTokensSpin = nullptr;
    QCheckBox* m_enabledCheck = nullptr;
    QSpinBox* m_prioritySpin = nullptr;

    // Validation
    QLabel* m_validationLabel = nullptr;
    QPushButton* m_okButton = nullptr;
};

} // namespace UI
} // namespace ClipAI

#endif
