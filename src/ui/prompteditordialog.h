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

#ifndef CLIPLLM_UI_PROMPTEDITORDIALOG_H
#define CLIPLLM_UI_PROMPTEDITORDIALOG_H

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
#include <QTabWidget>
#include "models/prompt.h"
#include "models/providerprofile.h"

class QNetworkAccessManager;
class QNetworkReply;

namespace ClipLLM {
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
    void onExportClicked();
    void onOverrideProviderAndModelChanged(int state);
    void onProviderChanged(int index);
    void onRefreshModelsClicked();
    void onTemperatureUseDefaultChanged(int state);
    void onHotkeyChanged(const QKeySequence& sequence);
    void onHotkeyRecordingFinished();
    void validateInput();
    void onNextPromptChanged(int index);

private:
    void setupUi();
    void setupPromptsTab();
    void setupSettingsTab();
    void loadPrompt(const Models::Prompt& prompt);
    Models::Prompt buildPrompt() const;
    void updateTemperatureFieldState();
    void loadProviders();
    void loadModelsForProvider(const QString& providerId);
    void fetchModelsFromAPI();
    void onModelsFetchFinished(QNetworkReply* reply);
    QString generateUniqueId() const;
    bool checkHotkeyConflict(const QKeySequence& seq) const;
    void loadNextPromptCombo(const QString& currentId = QString());
    bool detectChainCycle(const QString& startId, const QString& targetId) const;
    void updateChainWarning();

    Core::PromptManager* m_promptManager = nullptr;
    Core::GroupsManager* m_groupsManager = nullptr;
    Core::ConfigManager* m_configManager = nullptr;
    Models::Prompt m_originalPrompt;
    bool m_editMode = false;

    // Tab widget
    QTabWidget* m_tabWidget = nullptr;

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
    QCheckBox* m_overrideProviderAndModelCheck = nullptr;
    QComboBox* m_providerCombo = nullptr;
    QComboBox* m_modelCombo = nullptr;
    QPushButton* m_refreshModelsButton = nullptr;
    QLabel* m_modelsStatusLabel = nullptr;
    QCheckBox* m_temperatureUseDefaultCheck = nullptr;
    QDoubleSpinBox* m_temperatureSpin = nullptr;
    QSpinBox* m_maxTokensSpin = nullptr;
    QCheckBox* m_enabledCheck = nullptr;
    QSpinBox* m_prioritySpin = nullptr;
    class HotkeyEdit* m_hotkeyEdit = nullptr;

    // Chain fields
    QComboBox* m_nextPromptCombo = nullptr;
    QCheckBox* m_autoContinueCheck = nullptr;
    QLabel* m_chainWarningLabel = nullptr;

    // Recording state
    bool m_isRecordingHotkey = false;

    // Network
    QNetworkAccessManager* m_networkManager = nullptr;

    // Validation
    QLabel* m_validationLabel = nullptr;
    QPushButton* m_okButton = nullptr;
};

} // namespace UI
} // namespace ClipLLM

#endif
