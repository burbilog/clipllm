#include "configmanager.h"
#include <QStandardPaths>
#include <QDir>
#include <QCoreApplication>

namespace ClipAI {
namespace Core {

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
const QString ConfigManager::PROMPTS_FILE_KEY = QStringLiteral("prompts/file");
const QString ConfigManager::MAX_PROMPTS_KEY = QStringLiteral("prompts/max_in_menu");
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
    // Default hotkey: Ctrl+Alt+Shift+X
    return value(HOTKEY_KEY, QStringLiteral("Ctrl+Alt+Shift+X")).toString();
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

QString ConfigManager::promptsFile() const
{
    return value(PROMPTS_FILE_KEY).toString();
}

void ConfigManager::setPromptsFile(const QString& path)
{
    setValue(PROMPTS_FILE_KEY, path);
}

int ConfigManager::maxPrompts() const
{
    return value(MAX_PROMPTS_KEY, 10).toInt();
}

void ConfigManager::setMaxPrompts(int max)
{
    setValue(MAX_PROMPTS_KEY, max);
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

} // namespace Core
} // namespace ClipAI
