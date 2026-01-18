#include "trayicon.h"
#include "core/app.h"
#include "core/promptmanager.h"
#include <QApplication>
#include <QMessageBox>
#include <QStyle>

namespace ClipAI {
namespace UI {

TrayIcon::TrayIcon(App* app)
    : QSystemTrayIcon(app)
    , m_app(app)
{
    // Load icons
    m_normalIcon = QIcon(QStringLiteral(":/icons/tray-icon.png"));
    m_activeIcon = QIcon(QStringLiteral(":/icons/tray-icon-active.png"));

    // Fallback icon if resource not found
    if (m_normalIcon.isNull()) {
        m_normalIcon = QApplication::style()->standardIcon(QStyle::SP_ComputerIcon);
    }

    setIcon(m_normalIcon);
    setToolTip(tr("ClipAI - LLM Clipboard Utility"));

    // Create menu and actions
    createActions();
    createMenu();

    // Connect signals
    connect(this, &QSystemTrayIcon::activated,
            this, &TrayIcon::onActivated);

    // Update prompts menu
    if (m_app && m_app->promptManager()) {
        connect(m_app->promptManager(), &Core::PromptManager::promptsLoaded,
                this, &TrayIcon::onPromptsUpdated);
        connect(m_app->promptManager(), &Core::PromptManager::promptAdded,
                this, &TrayIcon::onPromptsUpdated);
        connect(m_app->promptManager(), &Core::PromptManager::promptRemoved,
                this, &TrayIcon::onPromptsUpdated);
    }

    show();
}

TrayIcon::~TrayIcon() = default;

void TrayIcon::createActions()
{
    m_settingsAction = new QAction(tr("&Settings"), this);
    m_settingsAction->setIcon(QIcon::fromTheme(QStringLiteral("configure")));
    connect(m_settingsAction, &QAction::triggered, this, &TrayIcon::onSettingsTriggered);

    m_historyAction = new QAction(tr("&History"), this);
    m_historyAction->setIcon(QIcon::fromTheme(QStringLiteral("document-open-recent")));
    connect(m_historyAction, &QAction::triggered, this, &TrayIcon::onHistoryTriggered);

    m_aboutAction = new QAction(tr("&About"), this);
    m_aboutAction->setIcon(QIcon::fromTheme(QStringLiteral("help-about")));
    connect(m_aboutAction, &QAction::triggered, this, &TrayIcon::onAboutTriggered);

    m_separator1 = new QAction(this);
    m_separator1->setSeparator(true);

    m_separator2 = new QAction(this);
    m_separator2->setSeparator(true);

    m_quitAction = new QAction(tr("&Quit"), this);
    m_quitAction->setIcon(QIcon::fromTheme(QStringLiteral("application-exit")));
    connect(m_quitAction, &QAction::triggered, this, &TrayIcon::onQuitTriggered);
}

void TrayIcon::createMenu()
{
    m_menu = new QMenu();
    m_promptsMenu = new QMenu(tr("&Prompts"), m_menu);
    m_promptsMenu->setIcon(QIcon::fromTheme(QStringLiteral("document-new")));

    m_menu->addMenu(m_promptsMenu);
    m_menu->addAction(m_historyAction);
    m_menu->addAction(m_settingsAction);
    m_menu->addAction(m_separator1);
    m_menu->addAction(m_aboutAction);
    m_menu->addAction(m_separator2);
    m_menu->addAction(m_quitAction);

    setContextMenu(m_menu);

    // Initial prompts menu build
    rebuildPromptsMenu();
}

void TrayIcon::rebuildPromptsMenu()
{
    m_promptsMenu->clear();

    if (!m_app || !m_app->promptManager()) {
        QAction* noPromptsAction = m_promptsMenu->addAction(tr("No prompts available"));
        noPromptsAction->setEnabled(false);
        return;
    }

    QVector<Models::Prompt> prompts = m_app->promptManager()->getEnabledPrompts();

    if (prompts.isEmpty()) {
        QAction* noPromptsAction = m_promptsMenu->addAction(tr("No prompts available"));
        noPromptsAction->setEnabled(false);
        return;
    }

    for (const auto& prompt : prompts) {
        QString text = prompt.name();
        if (!prompt.description().isEmpty()) {
            text += QStringLiteral(" - ") + prompt.description();
        }

        QAction* action = m_promptsMenu->addAction(text);
        action->setData(prompt.id());

        // Set icon based on prompt icon type
        QString iconName = prompt.getIconName();
        if (!iconName.isEmpty()) {
            action->setIcon(QIcon::fromTheme(iconName));
        }

        connect(action, &QAction::triggered, this, &TrayIcon::onPromptTriggered);
    }
}

void TrayIcon::updatePromptsMenu(const QVector<Models::Prompt>& prompts)
{
    Q_UNUSED(prompts)
    rebuildPromptsMenu();
}

void TrayIcon::setHotkeyText(const QString& hotkey)
{
    QString tooltip = tr("ClipAI - LLM Clipboard Utility");
    if (!hotkey.isEmpty()) {
        tooltip += QStringLiteral("\n") + tr("Hotkey: ") + hotkey;
    }
    setToolTip(tooltip);
}

void TrayIcon::setProcessing(bool processing)
{
    m_processing = processing;
    updateIcon();
}

void TrayIcon::updateIcon()
{
    if (m_processing) {
        setIcon(m_activeIcon);
    } else {
        setIcon(m_normalIcon);
    }
}

void TrayIcon::showTrayMessage(const QString& title, const QString& message,
                               QSystemTrayIcon::MessageIcon icon, int millisecondsTimeoutHint)
{
    showMessage(title, message, icon, millisecondsTimeoutHint);
}

void TrayIcon::onActivated(QSystemTrayIcon::ActivationReason reason)
{
    emit activated(reason);

    // Double-click to show settings
    if (reason == QSystemTrayIcon::DoubleClick) {
        emit showSettingsRequested();
    }
}

void TrayIcon::onPromptTriggered()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (!action) {
        return;
    }

    QString promptId = action->data().toString();
    if (!promptId.isEmpty()) {
        emit promptSelected(promptId);
        emit hotkeyTriggered();
    }
}

void TrayIcon::onSettingsTriggered()
{
    emit showSettingsRequested();
}

void TrayIcon::onHistoryTriggered()
{
    emit showHistoryRequested();
}

void TrayIcon::onAboutTriggered()
{
    QMessageBox::about(nullptr,
        tr("About ClipAI"),
        tr("<h3>ClipAI</h3>"
           "<p>Version 1.0.0</p>"
           "<p>Cross-platform LLM clipboard utility</p>"
           "<p>Process your clipboard content with AI prompts.</p>"
           "<p>Copyright © 2024</p>"));
}

void TrayIcon::onQuitTriggered()
{
    emit quitRequested();
}

void TrayIcon::onPromptsUpdated()
{
    rebuildPromptsMenu();
}

} // namespace UI
} // namespace ClipAI
