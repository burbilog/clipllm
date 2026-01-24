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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_CORE_PROMPTMANAGER_H
#define CLIPLLM_CORE_PROMPTMANAGER_H

#include <QObject>
#include <QString>
#include <QVector>
#include <QJsonObject>
#include <optional>
#include "models/prompt.h"

namespace ClipLLM {
namespace Core {

class PromptManager : public QObject
{
    Q_OBJECT

public:
    explicit PromptManager(QObject* parent = nullptr);
    ~PromptManager();

    // Load prompts from configuration
    bool loadPrompts(class GroupsManager* groupsManager = nullptr);
    void setGroupsManager(class GroupsManager* groupsManager);
    bool loadPromptsFromFile(const QString& filePath);
    bool loadPromptsFromJson(const QJsonObject& json);

    // Save prompts
    bool savePrompts();
    bool savePromptsToFile(const QString& filePath);

    // Import prompts with conflict resolution
    bool importPromptsFromJson(const QJsonObject& json,
                               class ConfigManager* configManager,
                               class GroupsManager* groupsManager = nullptr,
                               QWidget* parentWidget = nullptr);

    // CRUD operations
    bool addPrompt(const Models::Prompt& prompt);
    bool updatePrompt(const QString& id, const Models::Prompt& prompt);
    bool removePrompt(const QString& id);
    std::optional<Models::Prompt> getPrompt(const QString& id) const;

    // Query operations
    QVector<Models::Prompt> getAllPrompts() const;
    QVector<Models::Prompt> getEnabledPrompts() const;
    QVector<Models::Prompt> getPromptsByContentType(Models::ContentType type) const;
    QVector<Models::Prompt> searchPrompts(const QString& query) const;

    // Prompt execution
    QString formatPrompt(const QString& promptId, const QString& clipboardContent) const;

    // Validation
    bool validatePrompt(const Models::Prompt& prompt) const;
    QStringList getValidationErrors(const Models::Prompt& prompt) const;

    // File paths
    QString getCustomPromptsFilePath() const;

    // Group operations
    void updatePromptGroup(const QString& oldGroup, const QString& newGroup);
    void movePromptsToGroup(const QString& fromGroup, const QString& toGroup);

    // Default prompts
    static QVector<Models::Prompt> getDefaultPrompts();
    static QJsonObject getDefaultPromptsJson();

signals:
    void promptAdded(const QString& id);
    void promptUpdated(const QString& id);
    void promptRemoved(const QString& id);
    void promptsLoaded();
    void promptsLoadFailed(const QString& error);

private:
    QString getPromptsFilePath() const;
    bool ensurePromptsFileExists();
    void ensureGroupExists(const QString& group);

    QVector<Models::Prompt> m_prompts;
    class GroupsManager* m_groupsManager = nullptr;
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_PROMPTMANAGER_H
