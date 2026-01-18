#include "app.h"
#include "clipboardmanager.h"
#include "llmclient.h"
#include "promptmanager.h"
#include "configmanager.h"
#include "keychainstore.h"
#include "historymanager.h"
#include "ui/trayicon.h"
#include "ui/settingsdialog.h"
#include "ui/historydialog.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>
#include <QMutex>
#include <QSharedMemory>
#include <QLockFile>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QLibraryInfo>

namespace ClipAI {

// Static namespace for constants
namespace {
    const QString APPLICATION_NAME = QStringLiteral("ClipAI");
    const QString ORGANIZATION_NAME = QStringLiteral("ClipAI");
    const QString ORGANIZATION_DOMAIN = QStringLiteral("clipai.org");

    // Single instance management
    QSharedMemory* g_sharedMemory = nullptr;
    QLockFile* g_lockFile = nullptr;
}

// Using declarations for Core classes
using Core::ClipboardManager;
using Core::LLMClient;
using Core::PromptManager;
using Core::ConfigManager;
using Core::KeychainStore;
using Core::HistoryManager;

// Getter implementations
Core::ClipboardManager* App::clipboardManager() const { return m_clipboardManager.get(); }
Core::LLMClient* App::llmClient() const { return m_llmClient.get(); }
Core::PromptManager* App::promptManager() const { return m_promptManager.get(); }
Core::ConfigManager* App::configManager() const { return m_configManager.get(); }
Core::KeychainStore* App::keychainStore() const { return m_keychainStore.get(); }
Core::HistoryManager* App::historyManager() const { return m_historyManager.get(); }

App::App(int &argc, char **argv)
    : QApplication(argc, argv)
    , m_instanceId(QByteArray::number(QRandomGenerator::global()->generate()))
{
    setApplicationName(APPLICATION_NAME);
    setOrganizationName(ORGANIZATION_NAME);
    setOrganizationDomain(ORGANIZATION_DOMAIN);
    setApplicationVersion(QStringLiteral("1.0.0"));

    // Don't quit when last window is closed (important for tray apps)
    setQuitOnLastWindowClosed(false);

    // Setup quit handler
    connect(this, &QCoreApplication::aboutToQuit, this, &App::onAboutToQuit);
}

App::~App()
{
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
                           + QStringLiteral("/clipai.lock");
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
                           + QStringLiteral("/clipai.lock");
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
    m_historyManager = std::make_unique<HistoryManager>();
    m_promptManager = std::make_unique<PromptManager>();
    m_clipboardManager = std::make_unique<ClipboardManager>();
    m_llmClient = std::make_unique<LLMClient>();

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

    // Load API key from secure storage
    QString apiKey = m_keychainStore->readApiKey();
    if (!apiKey.isEmpty()) {
        m_llmClient->setApiKey(apiKey);
    }

    // Setup UI components
    m_trayIcon = std::make_unique<UI::TrayIcon>(this);

    // Connect signals
    connect(m_trayIcon.get(), &UI::TrayIcon::activated,
            this, &App::onTrayIconActivated);
    connect(m_trayIcon.get(), &UI::TrayIcon::showSettingsRequested,
            this, &App::showSettings);
    connect(m_trayIcon.get(), &UI::TrayIcon::showHistoryRequested,
            this, &App::showHistory);
    connect(m_trayIcon.get(), &UI::TrayIcon::quitRequested,
            this, &QCoreApplication::quit);
    connect(m_trayIcon.get(), &UI::TrayIcon::hotkeyTriggered,
            this, &App::onHotkeyTriggered);

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
            showTrayMessage(tr("Welcome to ClipAI"),
                           tr("ClipAI is running in the system tray. Press the global hotkey to start."));
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
                               + QStringLiteral("/../share/clipai/translations");

    // Fallback paths for development
    if (!QDir(translationsPath).exists()) {
        translationsPath = QCoreApplication::applicationDirPath() + QStringLiteral("/../translations");
        if (!QDir(translationsPath).exists()) {
            translationsPath = QCoreApplication::applicationDirPath() + QStringLiteral("/translations");
        }
    }

    if (appTranslator->load(QStringLiteral("clipai_") + languageCode, translationsPath)) {
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

void App::showSettings()
{
    if (!m_settingsDialog) {
        m_settingsDialog = new UI::SettingsDialog();
        m_settingsDialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(m_settingsDialog, &QObject::destroyed, [this]() {
            m_settingsDialog = nullptr;
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

    // Show prompt menu
    // This will be implemented when PromptMenu is created
    emit hotkeyTriggered();
}

void App::onTrayIconActivated(QSystemTrayIcon::ActivationReason reason)
{
    Q_UNUSED(reason)
    // Could show settings or history on double click
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

} // namespace ClipAI
