#include "trayicon.h"
#include "core/app.h"
#include "core/promptmanager.h"
#include "core/groupsmanager.h"
#include <QApplication>
#include <QFile>
#include <QMessageBox>
#include <QSize>
#include <QStyle>
#include <QDebug>

namespace ClipAI {
namespace UI {

TrayIcon::TrayIcon(App* app)
    : QSystemTrayIcon(app)
    , m_app(app)
{
    // Load icons with multiple resolutions for better DPI scaling
    m_normalIcon = QIcon();
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-16.png"));
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-22.png"));
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-24.png"));
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-32.png"));
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-48.png"));
    m_normalIcon.addFile(QStringLiteral(":/icons/tray-icon-64.png"));
    m_activeIcon = m_normalIcon;

    qDebug() << "TrayIcon: Loaded" << m_normalIcon.availableSizes().size() << "sizes, isNull:" << m_normalIcon.isNull();

    // Fallback icon if resource not found
    if (m_normalIcon.isNull()) {
        qWarning() << "TrayIcon: Icon resources not found, using fallback";
        m_normalIcon = QApplication::style()->standardIcon(QStyle::SP_ComputerIcon);
        m_activeIcon = m_normalIcon;
    }

    setIcon(m_normalIcon);
    setToolTip(tr("ClipAI - LLM Clipboard Utility"));

    // Create menu and actions
    createActions();
    createMenu();

    // Connect signals
    connect(this, &QSystemTrayIcon::activated,
            this, &TrayIcon::onActivated);

    // Connect to language change signal
    connect(m_app, &App::languageChanged,
            this, &TrayIcon::onLanguageChanged);

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

    // Group prompts by their group path
    QMap<QString, QVector<Models::Prompt>> grouped;
    for (const auto& prompt : prompts) {
        QString group = prompt.group();
        if (group.isEmpty()) {
            group = QStringLiteral(""); // Root
        }
        grouped[group].append(prompt);
    }

    // Sort groups alphabetically
    QStringList groups = grouped.keys();
    groups.sort(Qt::CaseInsensitive);

    // Add root prompts first (at top level)
    if (groups.contains(QString())) {
        groups.removeAll(QString());
        QVector<Models::Prompt> rootPrompts = grouped.value(QString());

        // Sort root prompts by priority
        std::sort(rootPrompts.begin(), rootPrompts.end(),
            [](const Models::Prompt& a, const Models::Prompt& b) {
                if (a.priority() != b.priority()) {
                    return a.priority() > b.priority();
                }
                return a.name() < b.name();
            });

        for (const auto& prompt : rootPrompts) {
            QString text = prompt.name();
            if (!prompt.description().isEmpty()) {
                text += QStringLiteral(" - ") + prompt.description();
            }

            QAction* action = m_promptsMenu->addAction(text);
            action->setData(prompt.id());

            connect(action, &QAction::triggered, this, &TrayIcon::onPromptTriggered);
        }
    }

    // Add groups as submenus
    for (const QString& group : groups) {
        // Build submenu path (e.g., "Text Processing" -> "Summarization")
        QStringList parts = group.split(QLatin1Char('/'));

        QMenu* currentMenu = m_promptsMenu;

        // Navigate/create nested menus
        QString currentPath;
        for (int i = 0; i < parts.size(); ++i) {
            currentPath = currentPath.isEmpty() ? parts[i] : currentPath + QLatin1Char('/') + parts[i];

            // Look for existing submenu
            bool found = false;
            for (QAction* action : currentMenu->actions()) {
                if (action->menu() && action->text() == parts[i]) {
                    currentMenu = action->menu();
                    found = true;
                    break;
                }
            }

            if (!found) {
                QMenu* newMenu = currentMenu->addMenu(parts[i]);
                currentMenu = newMenu;
            }
        }

        // Add prompts to the final submenu
        QVector<Models::Prompt> groupPrompts = grouped.value(group);

        // Sort by priority
        std::sort(groupPrompts.begin(), groupPrompts.end(),
            [](const Models::Prompt& a, const Models::Prompt& b) {
                if (a.priority() != b.priority()) {
                    return a.priority() > b.priority();
                }
                return a.name() < b.name();
            });

        for (const auto& prompt : groupPrompts) {
            QString text = prompt.name();
            if (!prompt.description().isEmpty()) {
                text += QStringLiteral(" - ") + prompt.description();
            }

            QAction* action = currentMenu->addAction(text);
            action->setData(prompt.id());

            connect(action, &QAction::triggered, this, &TrayIcon::onPromptTriggered);
        }
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
    QString aboutText = tr(
        "<table border='0' cellpadding='8' cellspacing='0'>"
        "<tr>"
        "<td align='center' width='150'>"
        "<img src=':/icons/tray-icon-128.png' width='128' height='128'/>"
        "</td>"
        "<td>"
        "<h2 style='margin-top:0;'>ClipAI</h2>"
        "<p><b>Version 1.0.0</b></p>"
        "</td>"
        "</tr>"
        "</table>"
        "<p><b>ClipAI</b> is a cross-platform clipboard utility that integrates Large Language Models (LLMs) "
        "directly into your workflow. Running as a system tray service, it allows you to process clipboard "
        "content (both text and images) with customizable AI prompts using global hotkeys.</p>"
        "<p>Whether you need to summarize text, translate content, rewrite code, extract information from images, "
        "or perform any other AI-powered transformation, ClipAI makes it instantly accessible with a single "
        "keypress. Copy content, press your hotkey, and get AI-generated results back in your clipboard.</p>"
        "<p><small>Copyright © 2026 Roman V. Isaev &lt;<a href='mailto:rm@isaeff.net'>rm@isaeff.net</a>&gt;</small></p>"
    );

    QMessageBox::about(nullptr, tr("About ClipAI"), aboutText);
}

void TrayIcon::onQuitTriggered()
{
    emit quitRequested();
}

void TrayIcon::onPromptsUpdated()
{
    rebuildPromptsMenu();
}

void TrayIcon::onLanguageChanged(const QString& languageCode)
{
    Q_UNUSED(languageCode)
    retranslateUi();
}

void TrayIcon::retranslateUi()
{
    setToolTip(tr("ClipAI - LLM Clipboard Utility"));

    // Update action texts
    if (m_settingsAction) {
        m_settingsAction->setText(tr("&Settings"));
    }
    if (m_historyAction) {
        m_historyAction->setText(tr("&History"));
    }
    if (m_aboutAction) {
        m_aboutAction->setText(tr("&About"));
    }
    if (m_quitAction) {
        m_quitAction->setText(tr("&Quit"));
    }

    // Update prompts menu title
    if (m_promptsMenu) {
        m_promptsMenu->setTitle(tr("&Prompts"));
    }

    // Rebuild prompts menu to update prompt descriptions
    rebuildPromptsMenu();
}

} // namespace UI
} // namespace ClipAI
