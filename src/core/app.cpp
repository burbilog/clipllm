// ClipAI - Cross-platform LLM clipboard utility
// Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "app.h"
#include "core/version.h"
#include "clipboardmanager.h"
#include "llmclient.h"
#include "promptmanager.h"
#include "configmanager.h"
#include "keychainstore.h"
#include "historymanager.h"
#include "groupsmanager.h"
#include "providerkeystore.h"
#include "models/providerprofile.h"
#include "ui/trayicon.h"
#include "ui/settingsdialog.h"
#include "ui/historydialog.h"
#include "ui/resultdialog.h"
#include "ui/promptmenu.h"
#include "qhotkey.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QMutex>
#include <QSharedMemory>
#include <QLockFile>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QLibraryInfo>
#include <QCursor>

namespace ClipLLM {

// Static namespace for constants
namespace {
    const QString APPLICATION_NAME = QStringLiteral("ClipLLM");
    const QString ORGANIZATION_DOMAIN = QStringLiteral("clipllm.org");

    // Single instance management
    QSharedMemory* g_sharedMemory = nullptr;
    QLockFile* g_lockFile = nullptr;
}

// Using declarations for Core classes
using Core::ClipboardManager;
using Core::ClipboardContent;
using Core::LLMClient;
using Core::PromptManager;
using Core::ConfigManager;
using Core::KeychainStore;
using Core::HistoryManager;
using Core::ProviderKeyStore;

// Getter implementations
Core::ClipboardManager* App::clipboardManager() const { return m_clipboardManager.get(); }
Core::LLMClient* App::llmClient() const { return m_llmClient.get(); }
Core::PromptManager* App::promptManager() const { return m_promptManager.get(); }
Core::ConfigManager* App::configManager() const { return m_configManager.get(); }
Core::KeychainStore* App::keychainStore() const { return m_keychainStore.get(); }
Core::HistoryManager* App::historyManager() const { return m_historyManager.get(); }
Core::GroupsManager* App::groupsManager() const { return m_groupsManager.get(); }
Core::ProviderKeyStore* App::providerKeyStore() const { return m_providerKeyStore.get(); }

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
    , m_instanceId(QByteArray::number(QRandomGenerator::global()->generate()))
{
    setApplicationName(APPLICATION_NAME);
    setOrganizationName(APPLICATION_NAME);
    setOrganizationDomain(ORGANIZATION_DOMAIN);
    setApplicationVersion(ClipLLM::versionString());

    // Don't quit when last window is closed (important for tray apps)
    setQuitOnLastWindowClosed(false);

    // Setup quit handler
    connect(this, &QCoreApplication::aboutToQuit, this, &App::onAboutToQuit);
}

App::~App()
{
    // Cleanup prompt menu
    if (m_promptMenu) {
        delete m_promptMenu;
        m_promptMenu = nullptr;
    }

    // Cleanup global hotkey
    if (m_globalHotkey) {
        delete m_globalHotkey;
        m_globalHotkey = nullptr;
    }

    cleanupTranslations();

    if (g_sharedMemory) {
        g_sharedMemory->detach();
        delete g_sharedMemory;
        g_sharedMemory = nullptr;
    }

    if (g_lockFile) {
        g_lockFile->unlock();
        delete g_lockFile;
        g_lockFile = nullptr;
    }
}

bool App::isSecondary() const
{
    // Check if another instance is running using lock file
    QString lockFilePath = QStandardPaths::writableLocation(QStandardPaths::TempLocation)
                           + QStringLiteral("/clipllm.lock");
    QLockFile lockFile(lockFilePath);

    if (!lockFile.tryLock(10)) {
        return true;
    }

    lockFile.unlock();
    return false;
}

bool App::initialize(bool startMinimized)
{
    // Setup single instance lock
    QString lockFilePath = QStandardPaths::writableLocation(QStandardPaths::TempLocation)
                           + QStringLiteral("/clipllm.lock");
    g_lockFile = new QLockFile(lockFilePath);
    if (!g_lockFile->tryLock(0)) {
        qWarning() << "Another instance is already running";
        return false;
    }

    // Setup translations
    if (!setupTranslations()) {
        qWarning() << "Failed to setup translations";
    }

    // Create core components
    m_configManager = std::make_unique<ConfigManager>();
    m_keychainStore = std::make_unique<KeychainStore>();
    m_providerKeyStore = std::make_unique<ProviderKeyStore>();
    m_historyManager = std::make_unique<HistoryManager>();
    m_promptManager = std::make_unique<PromptManager>();
    m_groupsManager = std::make_unique<Core::GroupsManager>();
    m_clipboardManager = std::make_unique<ClipboardManager>();
    m_llmClient = std::make_unique<LLMClient>();

    // Initialize history manager
    if (!m_historyManager->initialize()) {
        qWarning() << "Failed to initialize history manager";
    }

    // Load configuration
    QString language = m_configManager->value(QStringLiteral("language")).toString();
    if (language.isEmpty()) {
        language = getDefaultLanguage();
    }
    setLanguage(language);

    // Load prompts
    if (!m_promptManager->loadPrompts()) {
        qWarning() << "Failed to load prompts, using defaults";
    }

    // Load LLM configuration from provider profiles
    QString defaultProviderId = m_configManager->defaultProviderId();
    if (defaultProviderId.isEmpty()) {
        qWarning() << "No provider configured - LLM features disabled";
        // Set empty config - features will show error when used
        m_llmClient->setConfig(Models::LLMConfig());
    } else {
        auto profile = m_configManager->providerProfile(defaultProviderId);
        if (!profile.has_value()) {
            qWarning() << "Default provider not found, falling back to first available";
            auto profiles = m_configManager->providerProfiles();
            if (profiles.isEmpty()) {
                qWarning() << "No providers configured at all";
                m_llmClient->setConfig(Models::LLMConfig());
            } else {
                profile = profiles.first();
                m_configManager->setDefaultProviderId(profile->id());
                Models::LLMConfig config = profileToConfig(profile.value());
                m_llmClient->setConfig(config);
                m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
                qDebug() << "LLM initialized: provider=" << profile->name()
                         << "model=" << profile->model();
            }
        } else {
            Models::LLMConfig config = profileToConfig(profile.value());
            m_llmClient->setConfig(config);
            m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
            qDebug() << "LLM initialized: provider=" << profile->name()
                     << "model=" << profile->model();
        }
    }

    // Setup UI components
    m_trayIcon = std::make_unique<UI::TrayIcon>(this);

    // Connect signals
    connect(m_trayIcon.get(), &UI::TrayIcon::activated,
            this, &App::onTrayIconActivated);
    connect(m_trayIcon.get(), &UI::TrayIcon::showSettingsRequested,
            this, &App::showSettings);
    connect(m_trayIcon.get(), &UI::TrayIcon::showPromptMenuRequested,
            this, &App::showPromptMenuAtTray);
    connect(m_trayIcon.get(), &UI::TrayIcon::showHistoryRequested,
            this, &App::showHistory);
    connect(m_trayIcon.get(), &UI::TrayIcon::quitRequested,
            this, &QCoreApplication::quit);
    connect(m_trayIcon.get(), &UI::TrayIcon::hotkeyTriggered,
            this, &App::onHotkeyTriggered);
    connect(m_trayIcon.get(), &UI::TrayIcon::promptSelected,
            this, &App::onPromptSelected);

    // Register global hotkey
    QString hotkeyString = m_configManager->hotkey();
    QKeySequence hotkeySeq = QKeySequence::fromString(hotkeyString);
    registerHotkey(hotkeySeq);

    // Create prompt menu
    m_promptMenu = new UI::PromptMenu(m_promptManager.get(), m_clipboardManager.get(), m_configManager.get());
    connect(m_promptMenu, &UI::PromptMenu::promptSelected, this, &App::onPromptSelected);
    connect(m_promptMenu, &UI::PromptMenu::settingsRequested, this, &App::showSettings);
    connect(m_promptMenu, &UI::PromptMenu::historyRequested, this, &App::showHistory);
    connect(m_promptMenu, &UI::PromptMenu::cancelled, []() {
        qDebug() << "Prompt menu cancelled";
    });

    // Show tray icon
    if (!QSystemTrayIcon::isSystemTrayAvailable()) {
        QMessageBox::critical(nullptr, tr("System Tray"),
                             tr("Couldn't detect any system tray on this system."));
        return false;
    }

    m_trayIcon->show();

    if (!startMinimized) {
        // Optionally show a welcome message on first run
        bool firstRun = m_configManager->value(QStringLiteral("firstRun"), true).toBool();
        if (firstRun) {
            showTrayMessage(tr("Welcome to ClipLLM"),
                           tr("ClipLLM is running in the system tray. Click the tray icon or configure a hotkey in settings."));
            m_configManager->setValue(QStringLiteral("firstRun"), false);
        }
    }

    return true;
}

void App::setLanguage(const QString& languageCode)
{
    if (m_currentLanguage == languageCode) {
        return;
    }

    cleanupTranslations();

    m_currentLanguage = languageCode;

    // Load Qt base translations
    QTranslator* qtTranslator = new QTranslator(this);
    if (qtTranslator->load(QStringLiteral("qtbase_") + languageCode,
                          QLibraryInfo::path(QLibraryInfo::TranslationsPath))) {
        installTranslator(qtTranslator);
        m_translators.push_back(qtTranslator);
    }

    // Load application translations
    QTranslator* appTranslator = new QTranslator(this);
    QString translationsPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation)
                               + QStringLiteral("/../share/clipllm/translations");

    // Fallback paths for development
    if (!QDir(translationsPath).exists()) {
        // Try executable directory first (build directory)
        translationsPath = QCoreApplication::applicationDirPath() + QStringLiteral("/translations");
        if (!QDir(translationsPath).exists()) {
            // Try parent directory (source directory when running from build/subdir)
            translationsPath = QCoreApplication::applicationDirPath() + QStringLiteral("/../translations");
        }
    }

    if (appTranslator->load(QStringLiteral("clipllm_") + languageCode, translationsPath)) {
        installTranslator(appTranslator);
        m_translators.push_back(appTranslator);
    } else {
        qWarning() << "Failed to load translation for" << languageCode << "from" << translationsPath;
        delete appTranslator;
    }

    m_configManager->setValue(QStringLiteral("language"), languageCode);
    emit languageChanged(languageCode);
}

bool App::setupTranslations()
{
    // Translations are loaded on-demand in setLanguage
    return true;
}

void App::cleanupTranslations()
{
    for (QTranslator* translator : m_translators) {
        removeTranslator(translator);
        delete translator;
    }
    m_translators.clear();
}

QString App::getDefaultLanguage() const
{
    // Get system locale
    QString locale = QLocale::system().name(); // e.g., "en_US"
    QString language = locale.left(2);        // e.g., "en"

    // Check if we support this language
    QStringList supportedLanguages = {QStringLiteral("en"), QStringLiteral("ru"),
                                       QStringLiteral("de"), QStringLiteral("fr"),
                                       QStringLiteral("es")};

    if (supportedLanguages.contains(language)) {
        return language;
    }

    // Default to English
    return QStringLiteral("en");
}

void App::registerHotkey(const QKeySequence& sequence)
{
    // Check if platform supports global hotkeys
    if (!QHotkey::isPlatformSupported()) {
        qWarning() << "Global hotkeys are not supported on this platform";
        showTrayMessage(tr("Hotkey Not Supported"),
                       tr("Global hotkeys are not supported on this platform (Wayland?)."));
        return;
    }

    // Remove old hotkey if exists
    if (m_globalHotkey) {
        if (m_globalHotkey->isRegistered()) {
            m_globalHotkey->setRegistered(false);
        }
        delete m_globalHotkey;
        m_globalHotkey = nullptr;
    }

    // Don't register empty hotkey
    if (sequence.isEmpty()) {
        qDebug() << "Hotkey is empty, skipping registration";
        return;
    }

    // Create new hotkey
    m_globalHotkey = new QHotkey(sequence, true, this);

    // Check if registration succeeded
    if (!m_globalHotkey->isRegistered()) {
        qWarning() << "Failed to register global hotkey:" << sequence.toString();
        showTrayMessage(tr("Hotkey Registration Failed"),
                       tr("Could not register global hotkey: %1").arg(sequence.toString()));
        delete m_globalHotkey;
        m_globalHotkey = nullptr;
        return;
    }

    qDebug() << "Global hotkey registered:" << sequence.toString();

    // Connect hotkey signal
    connect(m_globalHotkey, &QHotkey::activated, this, [this]() {
        qDebug() << "Global hotkey activated!";
        onHotkeyTriggered();
    });
}

void App::showSettings()
{
    if (!m_settingsDialog) {
        m_settingsDialog = new UI::SettingsDialog();
        m_settingsDialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_settingsDialog, &QObject::destroyed, [this]() {
            m_settingsDialog = nullptr;
        });
        // Update LLM config when settings are applied
        connect(m_settingsDialog, &UI::SettingsDialog::settingsChanged, [this]() {
            QString defaultProviderId = m_configManager->defaultProviderId();
            if (defaultProviderId.isEmpty()) {
                qWarning() << "No provider configured in settings";
                return;
            }

            auto profile = m_configManager->providerProfile(defaultProviderId);
            if (!profile.has_value()) {
                qWarning() << "Default provider not found:" << defaultProviderId;
                return;
            }

            Models::LLMConfig config = profileToConfig(profile.value());
            m_llmClient->setConfig(config);
            m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
            qDebug() << "LLM config updated: provider=" << profile->name()
                     << "model=" << profile->model();
        });

        // Apply language change immediately when selected in settings
        connect(m_settingsDialog, &UI::SettingsDialog::languageChanged, [this](const QString& languageCode) {
            setLanguage(languageCode);
        });

        // Re-register hotkey when changed
        connect(m_settingsDialog, &UI::SettingsDialog::hotkeyChanged, [this](const QKeySequence& sequence) {
            qDebug() << "Hotkey changed in settings, re-registering:" << sequence.toString();
            registerHotkey(sequence);
        });
    }

    m_settingsDialog->show();
    m_settingsDialog->raise();
    m_settingsDialog->activateWindow();
}

void App::showHistory()
{
    if (!m_historyDialog) {
        m_historyDialog = new UI::HistoryDialog(m_historyManager.get());
        m_historyDialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_historyDialog, &QObject::destroyed, [this]() {
            m_historyDialog = nullptr;
        });
    }

    m_historyDialog->show();
    m_historyDialog->raise();
    m_historyDialog->activateWindow();
}

void App::showTrayMessage(const QString& title, const QString& message)
{
    if (m_trayIcon) {
        m_trayIcon->showMessage(title, message, QSystemTrayIcon::Information, 3000);
    }
}

void App::showPromptMenuAtTray()
{
    if (!m_promptMenu) {
        qWarning() << "PromptMenu not initialized";
        return;
    }

    // Get tray icon geometry
    QRect trayGeometry = m_trayIcon->geometry();
    QPoint trayCenter = trayGeometry.center();

    qDebug() << "Showing prompt menu at tray position:" << trayCenter;

    m_promptMenu->showMenu(trayCenter);
}

void App::onHotkeyTriggered()
{
    qDebug() << "Hotkey triggered";

    // Get clipboard content
    auto clipboardContent = m_clipboardManager->getContent();

    if (!clipboardContent.has_value()) {
        showTrayMessage(tr("Clipboard Empty"),
                       tr("No content found in clipboard."));
        return;
    }

    // Show prompt menu at cursor position
    if (m_promptMenu) {
        m_promptMenu->showMenu(QCursor::pos());
    } else {
        qWarning() << "PromptMenu not created!";
    }
}

void App::onPromptSelected(const QString& promptId)
{
    qDebug() << "Prompt selected:" << promptId;

    // Get prompt
    auto promptOpt = m_promptManager->getPrompt(promptId);
    if (!promptOpt.has_value()) {
        showTrayMessage(tr("Error"),
                       tr("Prompt not found: %1").arg(promptId));
        return;
    }

    const Models::Prompt& prompt = promptOpt.value();

    // Determine provider profile to use
    Models::ProviderProfile profile;
    QString defaultProviderId = m_configManager->defaultProviderId();
    qDebug() << "onPromptSelected: defaultProviderId from config:" << defaultProviderId;

    if (prompt.overrideProvider() && !prompt.providerId().isEmpty()) {
        auto promptProfile = m_configManager->providerProfile(prompt.providerId());
        if (promptProfile.has_value()) {
            profile = promptProfile.value();
        } else {
            qWarning() << "Prompt references non-existent profile:" << prompt.providerId()
                       << ", using default";
            if (!defaultProviderId.isEmpty()) {
                auto defaultProfile = m_configManager->providerProfile(defaultProviderId);
                if (defaultProfile.has_value()) {
                    profile = defaultProfile.value();
                } else {
                    showTrayMessage(tr("Provider Error"),
                                   tr("No valid LLM provider configured."));
                    return;
                }
            } else {
                showTrayMessage(tr("Provider Error"),
                               tr("No LLM provider configured. Please configure one in Settings."));
                return;
            }
        }
    } else {
        if (!defaultProviderId.isEmpty()) {
            auto defaultProfile = m_configManager->providerProfile(defaultProviderId);
            if (defaultProfile.has_value()) {
                profile = defaultProfile.value();
            } else {
                showTrayMessage(tr("Provider Error"),
                               tr("Default LLM provider not found. Please configure one in Settings."));
                return;
            }
        } else {
            showTrayMessage(tr("Provider Error"),
                           tr("No LLM provider configured. Please configure one in Settings."));
            return;
        }
    }

    // Configure LLM client with selected profile
    Models::LLMConfig config = profileToConfig(profile);

    // Override model if prompt has one set
    QString modelToUse = profile.model();
    if (!prompt.model().isEmpty()) {
        modelToUse = prompt.model();
        qDebug() << "Using model from prompt:" << modelToUse;
    }
    config.setModel(modelToUse);

    qDebug() << "Using provider:" << profile.name()
             << "ID:" << profile.id()
             << "URL:" << profile.apiUrl().toString()
             << "model:" << modelToUse
             << "proxy:" << profile.proxyUrl();
    m_llmClient->setConfig(config);
    // Also set API key explicitly since LLMClient checks m_apiKey separately
    m_llmClient->setApiKey(config.apiKey());

    // Get clipboard content
    auto clipboardContent = m_clipboardManager->getContent();
    if (!clipboardContent.has_value()) {
        showTrayMessage(tr("Clipboard Empty"),
                       tr("No content found in clipboard."));
        return;
    }

    const ClipboardContent& content = clipboardContent.value();

    // Check content type compatibility
    if (prompt.contentType() != Models::ContentType::Any) {
        bool compatible = false;
        // Html content is also compatible with Text prompts (it contains plain text)
        if (prompt.contentType() == Models::ContentType::Text && (content.isText() || content.isHtml())) {
            compatible = true;
        } else if (prompt.contentType() == Models::ContentType::Image && content.isImage()) {
            compatible = true;
        }

        if (!compatible) {
            showTrayMessage(tr("Incompatible Content"),
                           tr("This prompt requires %1 content.")
                           .arg(Models::Prompt::contentTypeToString(prompt.contentType())));
            return;
        }
    }

    // Format the user prompt with clipboard content
    QString clipboardText;
    if (content.isText()) {
        clipboardText = content.text;
    } else if (content.isHtml()) {
        clipboardText = content.text; // Html content also has plain text
    }
    QString userPrompt = prompt.formatUserPrompt(clipboardText, m_configManager->language());

    // Get image data if present
    QByteArray imageData;
    if (content.isImage()) {
        imageData = content.imageData;
    }

    // Create or reuse result dialog
    if (!m_resultDialog) {
        m_resultDialog = new UI::ResultDialog(m_llmClient.get(), m_historyManager.get(),
                                              m_configManager.get());
        m_resultDialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_resultDialog, &QObject::destroyed, [this]() {
            m_resultDialog = nullptr;
        });
    }

    // Configure dialog
    m_resultDialog->setPrompt(promptId, prompt.name());
    m_resultDialog->setInput(clipboardText.isEmpty() ? tr("[Image content]") : clipboardText);

    // Set provider and model (model from prompt takes precedence)
    QString displayModel = modelToUse;
    m_resultDialog->setProvider(profile.name());
    m_resultDialog->setModel(displayModel);

    // Auto-cleanup history if enabled
    if (m_configManager->historyCleanupByCount()) {
        int removed = m_historyManager->cleanupByCount(m_configManager->historyLimit());
        if (removed > 0) {
            qDebug() << "Auto-removed" << removed << "old history entries (by count)";
        }
    }
    if (m_configManager->historyCleanupByDate()) {
        int removed = m_historyManager->cleanupByDate(m_configManager->historyDaysToKeep());
        if (removed > 0) {
            qDebug() << "Auto-removed" << removed << "old history entries (by date)";
        }
    }

    m_resultDialog->startRequest();

    // Show dialog
    m_resultDialog->show();
    m_resultDialog->raise();
    m_resultDialog->activateWindow();

    // Send request to LLM
    QString systemPrompt = prompt.formatSystemPrompt(clipboardText, m_configManager->language());

    // Determine temperature to use
    double temperature = -1.0;  // -1 means use config default
    if (prompt.overrideTemperature()) {
        temperature = prompt.temperature();
    }

    if (!systemPrompt.isEmpty()) {
        m_llmClient->sendPrompt(systemPrompt, userPrompt, imageData, temperature);
    } else {
        // If no system prompt, send user prompt only
        m_llmClient->sendPrompt(QString(), userPrompt, imageData, temperature);
    }
}

void App::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    Q_UNUSED(reason)
    // Could show settings or history on double click
}

Models::LLMConfig App::profileToConfig(const Models::ProviderProfile& profile) const
{
    Models::LLMConfig llmConfig;
    llmConfig.setApiUrl(profile.apiUrl());
    llmConfig.setModel(profile.model());

    // Temperature cascade: profile -> global -> NOT SET (-1)
    // If not set anywhere, use -1 which means "don't send to API"
    // Provider will use its own defaults
    if (profile.temperature().has_value()) {
        llmConfig.setTemperature(*profile.temperature());
        llmConfig.setOverrideTemperature(true);
    } else if (m_configManager->defaultTemperature().has_value()) {
        llmConfig.setTemperature(*m_configManager->defaultTemperature());
        llmConfig.setOverrideTemperature(true);
    } else {
        llmConfig.setTemperature(-1.0); // Don't send temperature to API
        llmConfig.setOverrideTemperature(false);
    }

    // MaxTokens cascade: profile -> global -> NOT SET (-1)
    // Same logic - let provider decide if not specified
    if (profile.maxTokens().has_value()) {
        llmConfig.setMaxTokens(*profile.maxTokens());
    } else if (m_configManager->defaultMaxTokens().has_value()) {
        llmConfig.setMaxTokens(*m_configManager->defaultMaxTokens());
    } else {
        llmConfig.setMaxTokens(-1); // Don't send max_tokens to API
    }

    // Proxy: from provider profile (per-provider proxy setting)
    llmConfig.setProxyUrl(profile.proxyUrl());

    // Stream: always true for now
    llmConfig.setStream(true);

    // API key from ProviderKeyStore
    QString apiKey = m_providerKeyStore->providerKey(profile.id());
    llmConfig.setApiKey(apiKey);

    return llmConfig;
}

void App::onAboutToQuit()
{
    // Save any pending data
    if (m_historyManager) {
        m_historyManager->flush();
    }

    if (m_configManager) {
        m_configManager->sync();
    }
}

} // namespace ClipLLM
