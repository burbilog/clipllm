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
#include "screenshotmanager.h"
#include "models/providerprofile.h"
#include "ui/trayicon.h"
#include "ui/settingsdialog.h"
#include "ui/historydialog.h"
#include "ui/resultdialog.h"
#include "ui/promptmenu.h"
#include "ui/screenshotselector.h"
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
#include <QClipboard>
#include <QPixmap>

#include "debuglogger.h"

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
Core::ScreenshotManager* App::screenshotManager() const { return m_screenshotManager.get(); }
Core::DebugLogger* App::debugLogger() const { return m_debugLogger; }

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

    // Cleanup prompt hotkeys
    unregisterPromptHotkeys();

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
        LOG_WARNING(QStringLiteral("Another instance is already running"));
        return false;
    }

    // Setup translations
    if (!setupTranslations()) {
        LOG_WARNING(QStringLiteral("Failed to setup translations"));
    }

    // Create core components
    m_configManager = std::make_unique<ConfigManager>();
    m_keychainStore = std::make_unique<KeychainStore>();
    m_providerKeyStore = std::make_unique<ProviderKeyStore>();
    // Get the DebugLogger singleton instance
    m_debugLogger = Core::DebugLogger::instance();
    m_debugLogger->setLevel(static_cast<Core::DebugLevel>(m_configManager->debugLevel()));
    m_historyManager = std::make_unique<HistoryManager>();
    m_promptManager = std::make_unique<PromptManager>();
    m_groupsManager = std::make_unique<Core::GroupsManager>();
    m_clipboardManager = std::make_unique<ClipboardManager>();
    m_llmClient = std::make_unique<LLMClient>();
    m_screenshotManager = std::make_unique<Core::ScreenshotManager>();

    // Initialize history manager
    if (!m_historyManager->initialize()) {
        LOG_WARNING(QStringLiteral("Failed to initialize history manager"));
    }

    // Load configuration
    QString language = m_configManager->value(QStringLiteral("language")).toString();
    if (language.isEmpty()) {
        language = getDefaultLanguage();
    }
    setLanguage(language);

    // Set GroupsManager in PromptManager before loading prompts
    m_promptManager->setGroupsManager(m_groupsManager.get());

    // Load prompts
    if (!m_promptManager->loadPrompts(m_groupsManager.get())) {
        LOG_WARNING(QStringLiteral("Failed to load prompts, using defaults"));
    }

    // Load LLM configuration from provider profiles
    QString defaultProviderId = m_configManager->defaultProviderId();
    if (defaultProviderId.isEmpty()) {
        LOG_WARNING(QStringLiteral("No provider configured - LLM features disabled"));
        // Set empty config - features will show error when used
        m_llmClient->setConfig(Models::LLMConfig());
    } else {
        auto profile = m_configManager->providerProfile(defaultProviderId);
        if (!profile.has_value()) {
            LOG_WARNING(QStringLiteral("Default provider not found, falling back to first available"));
            auto profiles = m_configManager->providerProfiles();
            if (profiles.isEmpty()) {
                LOG_WARNING(QStringLiteral("No providers configured at all"));
                m_llmClient->setConfig(Models::LLMConfig());
                QMessageBox::warning(nullptr,
                    tr("No LLM Provider Configured"),
                    tr("No LLM provider profile has been configured.\n\n"
                       "Please add at least one provider profile in Settings to use ClipLLM."));
            } else {
                profile = profiles.first();
                m_configManager->setDefaultProviderId(profile->id());
                Models::LLMConfig config = profileToConfig(profile.value());
                m_llmClient->setConfig(config);
                m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
                LOG_DEBUG(QStringLiteral("LLM initialized: provider=%1 model=%2").arg(profile->name()).arg(profile->model()));
            }
        } else {
            Models::LLMConfig config = profileToConfig(profile.value());
            m_llmClient->setConfig(config);
            m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
            LOG_DEBUG(QStringLiteral("LLM initialized: provider=%1 model=%2").arg(profile->name()).arg(profile->model()));
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
            this, [this](const QString& promptId) {
                onPromptSelected(promptId);
            });

    // Register global hotkey
    QString hotkeyString = m_configManager->hotkey();
    QKeySequence hotkeySeq = QKeySequence::fromString(hotkeyString);
    registerHotkey(hotkeySeq);

    // Register prompt-specific hotkeys
    registerPromptHotkeys();

    // Create prompt menu
    m_promptMenu = new UI::PromptMenu(m_promptManager.get(), m_clipboardManager.get(), m_configManager.get());
    connect(m_promptMenu, &UI::PromptMenu::promptSelected, this, [this](const QString& promptId) {
        onPromptSelected(promptId);
    });
    connect(m_promptMenu, &UI::PromptMenu::settingsRequested, this, &App::showSettings);
    connect(m_promptMenu, &UI::PromptMenu::historyRequested, this, &App::showHistory);
    connect(m_promptMenu, &UI::PromptMenu::cancelled, []() {
        LOG_DEBUG(QStringLiteral("Prompt menu cancelled"));
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
        LOG_WARNING(QStringLiteral("Failed to load translation for %1 from %2").arg(languageCode).arg(translationsPath));
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
        LOG_WARNING(QStringLiteral("Global hotkeys are not supported on this platform"));
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
        LOG_DEBUG(QStringLiteral("Hotkey is empty, skipping registration"));
        return;
    }

    // Create new hotkey
    m_globalHotkey = new QHotkey(sequence, true, this);

    // Check if registration succeeded
    if (!m_globalHotkey->isRegistered()) {
        LOG_WARNING(QStringLiteral("Failed to register global hotkey: %1").arg(sequence.toString()));
        showTrayMessage(tr("Hotkey Registration Failed"),
                       tr("Could not register global hotkey: %1").arg(sequence.toString()));
        delete m_globalHotkey;
        m_globalHotkey = nullptr;
        return;
    }

    LOG_DEBUG(QStringLiteral("Global hotkey registered: %1").arg(sequence.toString()));

    // Connect hotkey signal
    connect(m_globalHotkey, &QHotkey::activated, this, [this]() {
        LOG_DEBUG(QStringLiteral("Global hotkey activated!"));
        onHotkeyTriggered();
    });
}

void App::registerPromptHotkeys()
{
    LOG_DEBUG(QStringLiteral("=== registerPromptHotkeys() called ==="));
    if (!QHotkey::isPlatformSupported()) {
        LOG_WARNING(QStringLiteral("QHotkey not supported on this platform"));
        return;
    }
    unregisterPromptHotkeys();

    QVector<Models::Prompt> prompts = m_promptManager->getEnabledPrompts();
    LOG_DEBUG(QStringLiteral("Total enabled prompts: %1").arg(prompts.size()));

    QKeySequence globalHotkeySeq = QKeySequence::fromString(m_configManager->hotkey());
    LOG_DEBUG(QStringLiteral("Global hotkey: %1").arg(m_configManager->hotkey()));

    // Collect all used hotkeys for conflict detection
    QSet<QKeySequence> usedSequences;

    // First pass: collect all clipboard hotkeys
    for (const auto& prompt : prompts) {
        QString hotkeyStr = prompt.hotkey();
        if (!hotkeyStr.isEmpty()) {
            usedSequences.insert(QKeySequence::fromString(hotkeyStr));
        }
    }

    for (const auto& prompt : prompts) {
        // === Register clipboard hotkey (existing behavior) ===
        QString hotkeyStr = prompt.hotkey();
        LOG_DEBUG(QStringLiteral("Prompt %1 hotkey: %2").arg(prompt.id()).arg(hotkeyStr));

        if (!hotkeyStr.isEmpty()) {
            QKeySequence seq = QKeySequence::fromString(hotkeyStr);
            LOG_DEBUG(QStringLiteral("  KeySequence: %1").arg(seq.toString()));

            // Skip if conflicts with global hotkey
            if (!globalHotkeySeq.isEmpty() && seq == globalHotkeySeq) {
                LOG_WARNING(QStringLiteral("Prompt hotkey %1 conflicts with global hotkey, skipping").arg(hotkeyStr));
            } else {
                // Skip if conflicts with another prompt
                bool conflict = false;
                for (const auto& other : prompts) {
                    if (other.id() != prompt.id() && QKeySequence::fromString(other.hotkey()) == seq) {
                        LOG_WARNING(QStringLiteral("Prompt hotkey %1 conflicts with prompt %2, skipping").arg(hotkeyStr).arg(other.name()));
                        conflict = true;
                        break;
                    }
                }

                if (!conflict) {
                    // Create and register hotkey
                    QHotkey* hotkey = new QHotkey(seq, true, this);
                    LOG_DEBUG(QStringLiteral("  QHotkey created, registered: %1").arg(hotkey->isRegistered()));
                    if (!hotkey->isRegistered()) {
                        LOG_WARNING(QStringLiteral("Failed to register prompt hotkey: %1").arg(hotkeyStr));
                        delete hotkey;
                    } else {
                        m_promptHotkeys[prompt.id()] = hotkey;

                        // Connect with direct lambda for debugging
                        connect(hotkey, &QHotkey::activated, this, [this, id = prompt.id(), name = prompt.name()]() {
                            LOG_DEBUG(QStringLiteral("LAMBDA: Hotkey activated for prompt: %1 id: %2").arg(name).arg(id));
                            onPromptHotkeyTriggered(id);
                        });
                        LOG_DEBUG(QStringLiteral("Registered prompt hotkey: %1 for prompt: %2").arg(hotkeyStr).arg(prompt.name()));
                    }
                }
            }
        }

        // === Register screenshot hotkey (new) ===
        QString screenshotHotkeyStr = prompt.screenshotHotkey();
        if (!screenshotHotkeyStr.isEmpty()) {
            LOG_DEBUG(QStringLiteral("Prompt %1 screenshot hotkey: %2").arg(prompt.id()).arg(screenshotHotkeyStr));
            QKeySequence screenshotSeq = QKeySequence::fromString(screenshotHotkeyStr);

            // Check conflict with clipboard hotkey of same prompt
            if (!hotkeyStr.isEmpty() && screenshotSeq == QKeySequence::fromString(hotkeyStr)) {
                LOG_WARNING(QStringLiteral("Screenshot hotkey conflicts with clipboard hotkey for prompt %1").arg(prompt.name()));
                continue;
            }

            // Check conflict with global hotkey
            if (!globalHotkeySeq.isEmpty() && screenshotSeq == globalHotkeySeq) {
                LOG_WARNING(QStringLiteral("Screenshot hotkey conflicts with global hotkey for prompt %1").arg(prompt.name()));
                continue;
            }

            // Check conflict with other hotkeys (clipboard or screenshot)
            if (usedSequences.contains(screenshotSeq)) {
                LOG_WARNING(QStringLiteral("Screenshot hotkey conflicts with another hotkey for prompt %1").arg(prompt.name()));
                continue;
            }

            // Create and register screenshot hotkey
            QHotkey* screenshotHotkey = new QHotkey(screenshotSeq, true, this);
            if (!screenshotHotkey->isRegistered()) {
                LOG_WARNING(QStringLiteral("Failed to register screenshot hotkey: %1").arg(screenshotHotkeyStr));
                delete screenshotHotkey;
                continue;
            }

            m_screenshotHotkeys[prompt.id()] = screenshotHotkey;
            usedSequences.insert(screenshotSeq);

            connect(screenshotHotkey, &QHotkey::activated, this, [this, id = prompt.id()]() {
                LOG_DEBUG(QStringLiteral("Screenshot hotkey activated for prompt: %1").arg(id));
                onScreenshotHotkeyTriggered(id);
            });
            LOG_DEBUG(QStringLiteral("Registered screenshot hotkey: %1 for prompt: %2").arg(screenshotHotkeyStr).arg(prompt.name()));
        }
    }
    LOG_DEBUG(QStringLiteral("=== registerPromptHotkeys() done, registered %1 clipboard hotkeys, %2 screenshot hotkeys ===")
              .arg(m_promptHotkeys.size()).arg(m_screenshotHotkeys.size()));
}

void App::unregisterPromptHotkeys()
{
    // Delete clipboard hotkeys
    for (auto* hk : m_promptHotkeys) {
        delete hk;
    }
    m_promptHotkeys.clear();

    // Delete screenshot hotkeys
    for (auto* hk : m_screenshotHotkeys) {
        delete hk;
    }
    m_screenshotHotkeys.clear();
}

void App::onPromptHotkeyTriggered(const QString& promptId)
{
    LOG_DEBUG(QStringLiteral("Prompt hotkey triggered for: %1").arg(promptId));
    // Directly execute - clipboard check is in onPromptSelected()
    onPromptSelected(promptId);
}

void App::onScreenshotHotkeyTriggered(const QString& promptId)
{
    LOG_DEBUG(QStringLiteral("Screenshot hotkey triggered for: %1").arg(promptId));

    // Verify prompt exists
    auto promptOpt = m_promptManager->getPrompt(promptId);
    if (!promptOpt.has_value()) {
        LOG_WARNING(QStringLiteral("Invalid prompt ID for screenshot: %1").arg(promptId));
        return;
    }

    // Capture screen
    QImage screenshot = m_screenshotManager->captureScreen();
    if (screenshot.isNull()) {
        showTrayMessage(tr("Screenshot Failed"), tr("Could not capture screen"));
        return;
    }

    // Store prompt ID for later execution
    m_pendingPromptId = promptId;

    // Show screenshot selector
    auto* selector = new UI::ScreenshotSelector(screenshot);
    connect(selector, &UI::ScreenshotSelector::areaSelected,
            this, &App::onScreenshotAreaSelected);
    connect(selector, &UI::ScreenshotSelector::wholeScreenRequested,
            this, &App::onScreenshotWholeScreenRequested);
    connect(selector, &UI::ScreenshotSelector::cancelled,
            this, &App::onScreenshotCancelled);
    selector->show();
}

void App::onScreenshotAreaSelected(const QRect& rect)
{
    auto* selector = qobject_cast<UI::ScreenshotSelector*>(sender());
    if (!selector) return;

    QImage fullScreenshot = selector->screenshot();
    m_pendingScreenshot = fullScreenshot.copy(rect);
    selector->deleteLater();

    // Put cropped image in clipboard and execute prompt
    QApplication::clipboard()->setPixmap(QPixmap::fromImage(m_pendingScreenshot));

    // Execute prompt
    onPromptSelected(m_pendingPromptId);

    // Clear state
    m_pendingPromptId.clear();
    m_pendingScreenshot = QImage();
}

void App::onScreenshotWholeScreenRequested()
{
    auto* selector = qobject_cast<UI::ScreenshotSelector*>(sender());
    if (!selector) return;

    m_pendingScreenshot = selector->screenshot();
    selector->deleteLater();

    // Put image in clipboard and execute prompt
    QApplication::clipboard()->setPixmap(QPixmap::fromImage(m_pendingScreenshot));

    // Execute prompt
    onPromptSelected(m_pendingPromptId);

    // Clear state
    m_pendingPromptId.clear();
    m_pendingScreenshot = QImage();
}

void App::onScreenshotCancelled()
{
    auto* selector = qobject_cast<UI::ScreenshotSelector*>(sender());
    if (selector) selector->deleteLater();

    m_pendingPromptId.clear();
    m_pendingScreenshot = QImage();
    LOG_DEBUG(QStringLiteral("Screenshot cancelled"));
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
                LOG_WARNING(QStringLiteral("No provider configured in settings"));
                return;
            }

            auto profile = m_configManager->providerProfile(defaultProviderId);
            if (!profile.has_value()) {
                LOG_WARNING(QStringLiteral("Default provider not found: %1").arg(defaultProviderId));
                return;
            }

            Models::LLMConfig config = profileToConfig(profile.value());
            m_llmClient->setConfig(config);
            m_llmClient->setApiKey(config.apiKey()); // Also set API key explicitly
            LOG_DEBUG(QStringLiteral("LLM config updated: provider=%1 model=%2").arg(profile->name()).arg(profile->model()));

            // Update debug logger settings in real-time
            int newLevel = m_configManager->debugLevel();
            if (newLevel == 0) {
                // Log before turning off, so this message appears in the log
                LOG_DEBUG(QStringLiteral("Debug logging turned off"));
                m_debugLogger->setLevel(Core::DebugLevel::Off);
            } else {
                m_debugLogger->setLevel(static_cast<Core::DebugLevel>(newLevel));
                const char* levelName = (newLevel == 1) ? "Normal" : "Trace";
                LOG_DEBUG(QStringLiteral("Debug logging enabled: level=%1 (%2)").arg(newLevel).arg(QString::fromUtf8(levelName)));
            }
        });

        // Apply language change immediately when selected in settings
        connect(m_settingsDialog, &UI::SettingsDialog::languageChanged, [this](const QString& languageCode) {
            setLanguage(languageCode);
        });

        // Re-register hotkey when changed
        connect(m_settingsDialog, &UI::SettingsDialog::hotkeyChanged, [this](const QKeySequence& sequence) {
            LOG_DEBUG(QStringLiteral("Hotkey changed in settings, re-registering: %1").arg(sequence.toString()));
            registerHotkey(sequence);
        });

        // Re-register prompt hotkeys when prompts are changed
        connect(m_settingsDialog, &UI::SettingsDialog::promptsChanged, [this]() {
            LOG_DEBUG(QStringLiteral("Prompts changed, re-registering prompt hotkeys"));
            registerPromptHotkeys();
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
        LOG_WARNING(QStringLiteral("PromptMenu not initialized"));
        return;
    }

    // Get tray icon geometry
    QRect trayGeometry = m_trayIcon->geometry();
    QPoint trayCenter = trayGeometry.center();

    LOG_DEBUG(QStringLiteral("Showing prompt menu at tray position: (%1, %2)").arg(trayCenter.x()).arg(trayCenter.y()));

    m_promptMenu->showMenu(trayCenter);
}

void App::onHotkeyTriggered()
{
    LOG_DEBUG(QStringLiteral("Hotkey triggered"));

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
        LOG_WARNING(QStringLiteral("PromptMenu not created!"));
    }
}

void App::onPromptSelected(const QString& promptId,
                           const QString& overrideInput,
                           const ChainContext& chainContext)
{
    LOG_DEBUG(QStringLiteral("Prompt selected: %1 (chain depth: %2, override input: %3)")
              .arg(promptId)
              .arg(chainContext.history.size())
              .arg(overrideInput.isEmpty() ? "no" : "yes"));

    // Check for chain cycle (runtime protection)
    if (chainContext.history.contains(promptId)) {
        QMessageBox::warning(nullptr, tr("Chain Cycle Detected"),
                           tr("The prompt chain would create a cycle. Execution stopped.\n\n"
                              "Prompt '%1' was already executed in this chain.").arg(promptId));
        return;
    }

    // Check chain depth limit
    int maxDepth = m_configManager->chainMaxDepth();
    if (chainContext.history.size() >= maxDepth) {
        QMessageBox::warning(nullptr, tr("Chain Depth Limit"),
                           tr("Maximum chain depth (%1) reached. Execution stopped.\n\n"
                              "You can increase this limit in Settings → General → Prompt Chains.")
                           .arg(maxDepth));
        return;
    }

    // Determine input source
    QString inputText;
    QByteArray imageData;

    if (!overrideInput.isEmpty()) {
        // Use override input from chain execution
        inputText = overrideInput;
    } else {
        // Check clipboard FIRST - applies to both hotkey and menu selection
        auto clipboardContent = m_clipboardManager->getContent();
        if (!clipboardContent.has_value()) {
            QMessageBox::critical(nullptr,
                tr("Clipboard Empty"),
                tr("Cannot execute prompt: clipboard is empty.\n\nCopy some text or an image first."));
            return;
        }

        const ClipboardContent& content = clipboardContent.value();
        if (content.isText() || content.isHtml()) {
            inputText = content.text;
        } else if (content.isImage()) {
            imageData = content.imageData;
        }
    }

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
    LOG_DEBUG(QStringLiteral("onPromptSelected: defaultProviderId from config: %1").arg(defaultProviderId));

    if (prompt.overrideProvider() && !prompt.providerId().isEmpty()) {
        auto promptProfile = m_configManager->providerProfile(prompt.providerId());
        if (promptProfile.has_value()) {
            profile = promptProfile.value();
        } else {
            LOG_WARNING(QStringLiteral("Prompt references non-existent profile: %1, using default").arg(prompt.providerId()));
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
        LOG_DEBUG(QStringLiteral("Using model from prompt: %1").arg(modelToUse));
    }

    // Validate that model is set
    if (modelToUse.isEmpty()) {
        QMessageBox::warning(nullptr, tr("Model Error"),
                           tr("No model selected. Please select a model in Settings → LLM → Provider Profiles."));
        return;
    }

    config.setModel(modelToUse);

    LOG_DEBUG(QStringLiteral("Using provider: %1 ID: %2 URL: %3 model: %4 proxy: %5")
              .arg(profile.name())
              .arg(profile.id())
              .arg(profile.apiUrl().toString())
              .arg(modelToUse)
              .arg(profile.proxyUrl()));
    m_llmClient->setConfig(config);
    // Also set API key explicitly since LLMClient checks m_apiKey separately
    m_llmClient->setApiKey(config.apiKey());

    // Check content type compatibility (only for text input from chain)
    if (!imageData.isEmpty() && prompt.contentType() == Models::ContentType::Text) {
        showTrayMessage(tr("Incompatible Content"),
                       tr("This prompt requires text content."));
        return;
    }

    // Format the user prompt with input text
    QString userPrompt = prompt.formatUserPrompt(inputText, m_configManager->language());

    // Create or reuse result dialog
    if (!m_resultDialog) {
        m_resultDialog = new UI::ResultDialog(m_llmClient.get(), m_historyManager.get(),
                                              m_configManager.get());
        m_resultDialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_resultDialog, &QObject::destroyed, [this]() {
            m_resultDialog = nullptr;
        });
        // Connect retry signal
        connect(m_resultDialog, &UI::ResultDialog::retryRequested,
                this, &App::onResultDialogRetryRequested);
        // Connect chain continue signal
        connect(m_resultDialog, &UI::ResultDialog::chainContinueRequested,
                this, &App::onChainContinueRequested);
    }

    // Configure dialog
    m_resultDialog->setPrompt(promptId, prompt.name());
    m_resultDialog->setInput(inputText.isEmpty() ? tr("[Image content]") : inputText);

    // Set provider and model (model from prompt takes precedence)
    QString displayModel = modelToUse;
    m_resultDialog->setProvider(profile.name());
    m_resultDialog->setModel(displayModel);

    // Auto-cleanup history if enabled
    if (m_configManager->historyCleanupByCount()) {
        int removed = m_historyManager->cleanupByCount(m_configManager->historyLimit());
        if (removed > 0) {
            LOG_DEBUG(QStringLiteral("Auto-removed %1 old history entries (by count)").arg(removed));
        }
    }
    if (m_configManager->historyCleanupByDate()) {
        int removed = m_historyManager->cleanupByDate(m_configManager->historyDaysToKeep());
        if (removed > 0) {
            LOG_DEBUG(QStringLiteral("Auto-removed %1 old history entries (by date)").arg(removed));
        }
    }

    m_resultDialog->startRequest();

    // Set chain info for the dialog
    QStringList chainNames = chainContext.names;
    chainNames.append(prompt.name());
    QString nextPromptId = prompt.nextPromptId();
    bool autoContinue = prompt.autoContinue();
    m_resultDialog->setChainInfo(chainNames, nextPromptId, autoContinue);

    // Store chain context for potential continue
    m_currentChainContext = chainContext;
    m_currentChainContext.history.insert(promptId);
    m_currentChainContext.names.append(prompt.name());
    // Store original input if this is the first prompt in chain
    if (m_currentChainContext.originalInput.isEmpty()) {
        m_currentChainContext.originalInput = inputText;
    }

    // Show dialog
    m_resultDialog->show();
    m_resultDialog->raise();
    m_resultDialog->activateWindow();

    // Send request to LLM
    QString systemPrompt = prompt.formatSystemPrompt(inputText, m_configManager->language());

    // Determine temperature to use
    double temperature = -1.0;  // -1 means use config default
    if (prompt.overrideTemperature()) {
        temperature = prompt.temperature();
    }

    // Store retry context in dialog
    m_resultDialog->setRetryContext(profile.id(), modelToUse, systemPrompt, userPrompt, imageData, temperature);

    if (!systemPrompt.isEmpty()) {
        m_llmClient->sendPrompt(systemPrompt, userPrompt, imageData, temperature);
    } else {
        // If no system prompt, send user prompt only
        m_llmClient->sendPrompt(QString(), userPrompt, imageData, temperature);
    }

    // Auto-continue if enabled and there's a next prompt
    if (autoContinue && !nextPromptId.isEmpty()) {
        // We'll handle auto-continue after the response is complete
        // via the chainContinueRequested signal
    }
}

void App::onResultDialogRetryRequested(const QString& promptId, const QString& providerId,
                                        const QString& model, const QString& systemPrompt,
                                        const QString& userPrompt, const QByteArray& imageData,
                                        double temperature)
{
    LOG_DEBUG(QStringLiteral("Retry requested for prompt: %1 provider: %2 model: %3").arg(promptId).arg(providerId).arg(model));

    // Get provider profile
    auto profileOpt = m_configManager->providerProfile(providerId);
    if (!profileOpt.has_value()) {
        LOG_WARNING(QStringLiteral("Provider profile not found for retry: %1").arg(providerId));
        return;
    }

    const Models::ProviderProfile& profile = profileOpt.value();

    // Configure LLM client with the provider profile
    Models::LLMConfig config = profileToConfig(profile);
    config.setModel(model);  // Use the exact model from the original request
    m_llmClient->setConfig(config);
    m_llmClient->setApiKey(config.apiKey());

    // Reset the dialog for new request
    m_resultDialog->startRequest();

    // Re-send the request with the same parameters
    if (!systemPrompt.isEmpty()) {
        m_llmClient->sendPrompt(systemPrompt, userPrompt, imageData, temperature);
    } else {
        m_llmClient->sendPrompt(QString(), userPrompt, imageData, temperature);
    }
}

void App::onChainContinueRequested(const QString& nextPromptId, const QString& output)
{
    LOG_DEBUG(QStringLiteral("Chain continue requested: nextPromptId=%1").arg(nextPromptId));

    // Execute the next prompt with the current output as input
    onPromptSelected(nextPromptId, output, m_currentChainContext);
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
