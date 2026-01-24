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

#include "configmanager.h"
#include "models/providerprofile.h"
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonObject>

namespace ClipLLM {
namespace Core {

// Define static keys for provider profiles
static const QString PROVIDER_PROFILES_GROUP = QStringLiteral("ProviderProfiles");
static const QString PROVIDER_PROFILE_PREFIX = QStringLiteral("ProviderProfile_");
static const QString DEFAULT_PROVIDER_ID_KEY = QStringLiteral("ProviderProfiles/default_id");
static const QString DEFAULT_TEMPERATURE_KEY = QStringLiteral("LLM/default_temperature");
static const QString DEFAULT_MAX_TOKENS_KEY = QStringLiteral("LLM/default_max_tokens");

// Define static keys
const QString ConfigManager::LANGUAGE_KEY = QStringLiteral("language");
const QString ConfigManager::HOTKEY_KEY = QStringLiteral("hotkey");
const QString ConfigManager::HOTKEY_MODIFIERS_KEY = QStringLiteral("hotkey_modifiers");
const QString ConfigManager::MODEL_KEY = QStringLiteral("llm/model");
const QString ConfigManager::PROVIDER_KEY = QStringLiteral("llm/provider");
const QString ConfigManager::CUSTOM_API_URL_KEY = QStringLiteral("llm/custom_api_url");
const QString ConfigManager::PROXY_URL_KEY = QStringLiteral("llm/proxy_url");
const QString ConfigManager::STREAM_RESPONSES_KEY = QStringLiteral("llm/stream");
const QString ConfigManager::TEMPERATURE_KEY = QStringLiteral("llm/temperature");
const QString ConfigManager::OVERRIDE_TEMPERATURE_KEY = QStringLiteral("llm/override_temperature");
const QString ConfigManager::MAX_TOKENS_KEY = QStringLiteral("llm/max_tokens");
const QString ConfigManager::WINDOW_SIZE_KEY = QStringLiteral("windows/%1/size");
const QString ConfigManager::WINDOW_POSITION_KEY = QStringLiteral("windows/%1/position");
const QString ConfigManager::FIRST_RUN_KEY = QStringLiteral("first_run");
const QString ConfigManager::HISTORY_LIMIT_KEY = QStringLiteral("history/limit");
const QString ConfigManager::HISTORY_AUTO_CLEANUP_KEY = QStringLiteral("history/auto_cleanup");
const QString ConfigManager::HISTORY_DAYS_TO_KEEP_KEY = QStringLiteral("history/days_to_keep");
const QString ConfigManager::HISTORY_AUTO_SAVE_KEY = QStringLiteral("history/auto_save");
const QString ConfigManager::HISTORY_CLEANUP_BY_COUNT_KEY = QStringLiteral("history/cleanup_by_count");
const QString ConfigManager::HISTORY_CLEANUP_BY_DATE_KEY = QStringLiteral("history/cleanup_by_date");
const QString ConfigManager::PROMPTS_FILE_KEY = QStringLiteral("prompts/file");
const QString ConfigManager::CACHED_MODELS_KEY = QStringLiteral("llm/cached_models/%1");

ConfigManager::ConfigManager()
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir(configPath);

    if (!configDir.exists()) {
        configDir.mkpath(QStringLiteral("."));
    }

    QString settingsFile = configDir.filePath(QStringLiteral("settings.ini"));

    m_settings = std::make_unique<QSettings>(settingsFile, QSettings::IniFormat);
    // Note: setIniCodec() was removed in Qt6 - UTF-8 is now the default
}

ConfigManager::~ConfigManager()
{
    if (m_settings) {
        m_settings->sync();
    }
}

QVariant ConfigManager::value(const QString& key, const QVariant& defaultValue) const
{
    return m_settings->value(key, defaultValue);
}

void ConfigManager::setValue(const QString& key, const QVariant& value)
{
    m_settings->setValue(key, value);
}

void ConfigManager::remove(const QString& key)
{
    m_settings->remove(key);
}

bool ConfigManager::contains(const QString& key) const
{
    return m_settings->contains(key);
}

void ConfigManager::clear()
{
    m_settings->clear();
}

void ConfigManager::sync()
{
    m_settings->sync();
}

void ConfigManager::flush()
{
    m_settings->sync();
}

void ConfigManager::beginGroup(const QString& prefix)
{
    m_settings->beginGroup(prefix);
}

void ConfigManager::endGroup()
{
    m_settings->endGroup();
}

QString ConfigManager::language() const
{
    return value(LANGUAGE_KEY, QStringLiteral("en")).toString();
}

void ConfigManager::setLanguage(const QString& language)
{
    setValue(LANGUAGE_KEY, language);
}

QString ConfigManager::hotkey() const
{
    // No default hotkey - let user choose one that works on their system
    return value(HOTKEY_KEY, QStringLiteral("")).toString();
}

void ConfigManager::setHotkey(const QString& hotkey)
{
    setValue(HOTKEY_KEY, hotkey);
}

Qt::Modifiers ConfigManager::hotkeyModifiers() const
{
    // Legacy method - kept for compatibility but not used anymore
    int defaultModifiers = static_cast<int>(Qt::ControlModifier | Qt::ShiftModifier);
    int modifiers = value(HOTKEY_MODIFIERS_KEY, defaultModifiers).toInt();
    return static_cast<Qt::Modifiers>(modifiers);
}

void ConfigManager::setHotkeyModifiers(Qt::Modifiers modifiers)
{
    // Legacy method - kept for compatibility but not used anymore
    setValue(HOTKEY_MODIFIERS_KEY, static_cast<int>(modifiers));
}

QString ConfigManager::llmModel() const
{
    return value(MODEL_KEY, QStringLiteral("openai/gpt-4")).toString();
}

void ConfigManager::setLlmModel(const QString& model)
{
    setValue(MODEL_KEY, model);
}

QString ConfigManager::llmProvider() const
{
    return value(PROVIDER_KEY, QStringLiteral("openrouter")).toString();
}

void ConfigManager::setLlmProvider(const QString& provider)
{
    setValue(PROVIDER_KEY, provider);
}

QString ConfigManager::customApiUrl() const
{
    return value(CUSTOM_API_URL_KEY).toString();
}

void ConfigManager::setCustomApiUrl(const QString& url)
{
    setValue(CUSTOM_API_URL_KEY, url);
}

QString ConfigManager::proxyUrl() const
{
    return value(PROXY_URL_KEY).toString();
}

void ConfigManager::setProxyUrl(const QString& url)
{
    setValue(PROXY_URL_KEY, url);
}

bool ConfigManager::streamResponses() const
{
    return value(STREAM_RESPONSES_KEY, true).toBool();
}

void ConfigManager::setStreamResponses(bool stream)
{
    setValue(STREAM_RESPONSES_KEY, stream);
}

double ConfigManager::temperature() const
{
    return value(TEMPERATURE_KEY, 0.7).toDouble();
}

void ConfigManager::setTemperature(double temp)
{
    setValue(TEMPERATURE_KEY, temp);
}

bool ConfigManager::overrideTemperature() const
{
    return value(OVERRIDE_TEMPERATURE_KEY, false).toBool();
}

void ConfigManager::setOverrideTemperature(bool override)
{
    setValue(OVERRIDE_TEMPERATURE_KEY, override);
}

int ConfigManager::maxTokens() const
{
    return value(MAX_TOKENS_KEY, 131072).toInt();
}

void ConfigManager::setMaxTokens(int tokens)
{
    setValue(MAX_TOKENS_KEY, tokens);
}

QSize ConfigManager::windowSize(const QString& windowId, const QSize& defaultSize) const
{
    QString key = WINDOW_SIZE_KEY.arg(windowId);
    return value(key, defaultSize).toSize();
}

void ConfigManager::setWindowSize(const QString& windowId, const QSize& size)
{
    QString key = WINDOW_SIZE_KEY.arg(windowId);
    setValue(key, size);
}

QPoint ConfigManager::windowPosition(const QString& windowId, const QPoint& defaultPos) const
{
    QString key = WINDOW_POSITION_KEY.arg(windowId);
    return value(key, defaultPos).toPoint();
}

void ConfigManager::setWindowPosition(const QString& windowId, const QPoint& position)
{
    QString key = WINDOW_POSITION_KEY.arg(windowId);
    setValue(key, position);
}

int ConfigManager::historyLimit() const
{
    return value(HISTORY_LIMIT_KEY, 1000).toInt();
}

void ConfigManager::setHistoryLimit(int limit)
{
    setValue(HISTORY_LIMIT_KEY, limit);
}

bool ConfigManager::historyAutoCleanup() const
{
    return value(HISTORY_AUTO_CLEANUP_KEY, true).toBool();
}

void ConfigManager::setHistoryAutoCleanup(bool enabled)
{
    setValue(HISTORY_AUTO_CLEANUP_KEY, enabled);
}

int ConfigManager::historyDaysToKeep() const
{
    return value(HISTORY_DAYS_TO_KEEP_KEY, 30).toInt();
}

void ConfigManager::setHistoryDaysToKeep(int days)
{
    setValue(HISTORY_DAYS_TO_KEEP_KEY, days);
}

bool ConfigManager::historyAutoSave() const
{
    return value(HISTORY_AUTO_SAVE_KEY, false).toBool();
}

void ConfigManager::setHistoryAutoSave(bool enabled)
{
    setValue(HISTORY_AUTO_SAVE_KEY, enabled);
}

bool ConfigManager::historyCleanupByCount() const
{
    return value(HISTORY_CLEANUP_BY_COUNT_KEY, false).toBool();
}

void ConfigManager::setHistoryCleanupByCount(bool enabled)
{
    setValue(HISTORY_CLEANUP_BY_COUNT_KEY, enabled);
}

bool ConfigManager::historyCleanupByDate() const
{
    return value(HISTORY_CLEANUP_BY_DATE_KEY, false).toBool();
}

void ConfigManager::setHistoryCleanupByDate(bool enabled)
{
    setValue(HISTORY_CLEANUP_BY_DATE_KEY, enabled);
}

QString ConfigManager::promptsFile() const
{
    return value(PROMPTS_FILE_KEY).toString();
}

void ConfigManager::setPromptsFile(const QString& path)
{
    setValue(PROMPTS_FILE_KEY, path);
}

QStringList ConfigManager::cachedModels(const QString& provider) const
{
    QString key = CACHED_MODELS_KEY.arg(provider);
    return value(key, QStringList()).toStringList();
}

void ConfigManager::setCachedModels(const QString& provider, const QStringList& models)
{
    QString key = CACHED_MODELS_KEY.arg(provider);
    setValue(key, models);
}

// Provider profiles implementation
QStringList ConfigManager::providerProfileIds() const
{
    m_settings->beginGroup(PROVIDER_PROFILES_GROUP);
    QStringList ids = m_settings->value(QStringLiteral("ids"), QStringList()).toStringList();
    m_settings->endGroup();
    return ids;
}

QList<Models::ProviderProfile> ConfigManager::providerProfiles() const
{
    QList<Models::ProviderProfile> profiles;
    QStringList ids = providerProfileIds();

    for (const QString& id : ids) {
        auto profileOpt = providerProfile(id);
        if (profileOpt.has_value()) {
            profiles.append(profileOpt.value());
        }
    }

    return profiles;
}

void ConfigManager::setProviderProfiles(const QList<Models::ProviderProfile>& profiles)
{
    // Clear existing profiles
    QStringList oldIds = providerProfileIds();
    for (const QString& oldId : oldIds) {
        m_settings->remove(PROVIDER_PROFILE_PREFIX + oldId);
    }

    // Set new profiles
    QStringList newIds;
    for (const auto& profile : profiles) {
        QString key = PROVIDER_PROFILE_PREFIX + profile.id();
        QJsonObject json = profile.toJson();
        m_settings->setValue(key, QJsonDocument(json).toJson(QJsonDocument::Compact));
        newIds.append(profile.id());
    }

    // Save the list of IDs
    m_settings->beginGroup(PROVIDER_PROFILES_GROUP);
    m_settings->setValue(QStringLiteral("ids"), newIds);
    m_settings->setValue(QStringLiteral("size"), newIds.size());
    m_settings->endGroup();
}

void ConfigManager::addProviderProfile(const Models::ProviderProfile& profile)
{
    // Save the profile
    QString key = PROVIDER_PROFILE_PREFIX + profile.id();
    QJsonObject json = profile.toJson();
    m_settings->setValue(key, QJsonDocument(json).toJson(QJsonDocument::Compact));

    // Add to the list of IDs
    QStringList ids = providerProfileIds();
    if (!ids.contains(profile.id())) {
        ids.append(profile.id());
        m_settings->beginGroup(PROVIDER_PROFILES_GROUP);
        m_settings->setValue(QStringLiteral("ids"), ids);
        m_settings->setValue(QStringLiteral("size"), ids.size());
        m_settings->endGroup();
    }
}

void ConfigManager::updateProviderProfile(const Models::ProviderProfile& profile)
{
    // Update the profile
    QString key = PROVIDER_PROFILE_PREFIX + profile.id();
    QJsonObject json = profile.toJson();
    m_settings->setValue(key, QJsonDocument(json).toJson(QJsonDocument::Compact));
}

void ConfigManager::removeProviderProfile(const QString& id)
{
    // Remove the profile
    m_settings->remove(PROVIDER_PROFILE_PREFIX + id);

    // Remove from the list of IDs
    QStringList ids = providerProfileIds();
    ids.removeAll(id);
    m_settings->beginGroup(PROVIDER_PROFILES_GROUP);
    m_settings->setValue(QStringLiteral("ids"), ids);
    m_settings->setValue(QStringLiteral("size"), ids.size());
    m_settings->endGroup();
}

std::optional<Models::ProviderProfile> ConfigManager::providerProfile(const QString& id) const
{
    QString key = PROVIDER_PROFILE_PREFIX + id;
    if (!m_settings->contains(key)) {
        return std::nullopt;
    }

    QByteArray jsonBytes = m_settings->value(key).toByteArray();
    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonBytes, &error);

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "Failed to parse provider profile JSON:" << error.errorString();
        return std::nullopt;
    }

    Models::ProviderProfile profile;
    if (profile.fromJson(doc.object())) {
        return profile;
    }

    return std::nullopt;
}

QString ConfigManager::defaultProviderId() const
{
    return value(DEFAULT_PROVIDER_ID_KEY).toString();
}

void ConfigManager::setDefaultProviderId(const QString& id)
{
    setValue(DEFAULT_PROVIDER_ID_KEY, id);
}

std::optional<double> ConfigManager::defaultTemperature() const
{
    if (contains(DEFAULT_TEMPERATURE_KEY)) {
        return value(DEFAULT_TEMPERATURE_KEY).toDouble();
    }
    return std::nullopt;
}

void ConfigManager::setDefaultTemperature(std::optional<double> temp)
{
    if (temp.has_value()) {
        setValue(DEFAULT_TEMPERATURE_KEY, *temp);
    } else {
        remove(DEFAULT_TEMPERATURE_KEY);
    }
}

std::optional<int> ConfigManager::defaultMaxTokens() const
{
    if (contains(DEFAULT_MAX_TOKENS_KEY)) {
        return value(DEFAULT_MAX_TOKENS_KEY).toInt();
    }
    return std::nullopt;
}

void ConfigManager::setDefaultMaxTokens(std::optional<int> tokens)
{
    if (tokens.has_value()) {
        setValue(DEFAULT_MAX_TOKENS_KEY, *tokens);
    } else {
        remove(DEFAULT_MAX_TOKENS_KEY);
    }
}

} // namespace Core
} // namespace ClipLLM
