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

#ifndef CLIPLLM_CORE_CONFIGMANAGER_H
#define CLIPLLM_CORE_CONFIGMANAGER_H

#include <QSettings>
#include <QVariant>
#include <QStringList>
#include <QSize>
#include <QPoint>
#include <memory>
#include <optional>

namespace ClipLLM {

namespace Models {
class ProviderProfile;
}

namespace Core {

class ConfigManager
{
public:
    ConfigManager();
    ~ConfigManager();

    // Generic value access
    QVariant value(const QString& key, const QVariant& defaultValue = QVariant()) const;
    void setValue(const QString& key, const QVariant& value);
    void remove(const QString& key);
    bool contains(const QString& key) const;
    void clear();

    // Sync settings
    void sync();
    void flush();

    // Group management
    void beginGroup(const QString& prefix);
    void endGroup();

    // Application settings keys
    static const QString LANGUAGE_KEY;
    static const QString HOTKEY_KEY;
    static const QString HOTKEY_MODIFIERS_KEY;
    static const QString MODEL_KEY;
    static const QString PROVIDER_KEY;
    static const QString CUSTOM_API_URL_KEY;
    static const QString PROXY_URL_KEY;
    static const QString STREAM_RESPONSES_KEY;
    static const QString TEMPERATURE_KEY;
    static const QString OVERRIDE_TEMPERATURE_KEY;
    static const QString MAX_TOKENS_KEY;
    static const QString WINDOW_SIZE_KEY;
    static const QString WINDOW_POSITION_KEY;
    static const QString FIRST_RUN_KEY;
    static const QString HISTORY_LIMIT_KEY;
    static const QString HISTORY_AUTO_CLEANUP_KEY;
    static const QString HISTORY_DAYS_TO_KEEP_KEY;
    static const QString HISTORY_AUTO_SAVE_KEY;
    static const QString HISTORY_CLEANUP_BY_COUNT_KEY;
    static const QString HISTORY_CLEANUP_BY_DATE_KEY;
    static const QString PROMPTS_FILE_KEY;
    static const QString CACHED_MODELS_KEY;

    // Convenience methods for common settings
    QString language() const;
    void setLanguage(const QString& language);

    QString hotkey() const;
    void setHotkey(const QString& hotkey);

    Qt::Modifiers hotkeyModifiers() const;
    void setHotkeyModifiers(Qt::Modifiers modifiers);

    QString llmModel() const;
    void setLlmModel(const QString& model);

    QString llmProvider() const;
    void setLlmProvider(const QString& provider);

    QString customApiUrl() const;
    void setCustomApiUrl(const QString& url);

    QString proxyUrl() const;
    void setProxyUrl(const QString& url);

    bool streamResponses() const;
    void setStreamResponses(bool stream);

    double temperature() const;
    void setTemperature(double temp);

    bool overrideTemperature() const;
    void setOverrideTemperature(bool override);

    int maxTokens() const;
    void setMaxTokens(int tokens);

    // Window geometry
    QSize windowSize(const QString& windowId, const QSize& defaultSize) const;
    void setWindowSize(const QString& windowId, const QSize& size);

    QPoint windowPosition(const QString& windowId, const QPoint& defaultPos) const;
    void setWindowPosition(const QString& windowId, const QPoint& position);

    // History settings
    int historyLimit() const;
    void setHistoryLimit(int limit);

    bool historyAutoCleanup() const;
    void setHistoryAutoCleanup(bool enabled);

    int historyDaysToKeep() const;
    void setHistoryDaysToKeep(int days);

    bool historyAutoSave() const;
    void setHistoryAutoSave(bool enabled);

    bool historyCleanupByCount() const;
    void setHistoryCleanupByCount(bool enabled);

    bool historyCleanupByDate() const;
    void setHistoryCleanupByDate(bool enabled);

    // Prompts settings
    QString promptsFile() const;
    void setPromptsFile(const QString& path);

    // Cached models for providers
    QStringList cachedModels(const QString& provider) const;
    void setCachedModels(const QString& provider, const QStringList& models);

    // Provider profiles (new multi-provider system)
    QStringList providerProfileIds() const;
    QList<Models::ProviderProfile> providerProfiles() const;
    void setProviderProfiles(const QList<Models::ProviderProfile>& profiles);
    void addProviderProfile(const Models::ProviderProfile& profile);
    void updateProviderProfile(const Models::ProviderProfile& profile);
    void removeProviderProfile(const QString& id);
    std::optional<Models::ProviderProfile> providerProfile(const QString& id) const;

    QString defaultProviderId() const;
    void setDefaultProviderId(const QString& id);

    // Global defaults - optional (if omitted, -1 is used which means "don't send to API, provider uses its own defaults")
    std::optional<double> defaultTemperature() const;
    void setDefaultTemperature(std::optional<double> temp);

    std::optional<int> defaultMaxTokens() const;
    void setDefaultMaxTokens(std::optional<int> tokens);

private:
    std::unique_ptr<QSettings> m_settings;
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_CONFIGMANAGER_H
