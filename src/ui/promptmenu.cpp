#include "promptmenu.h"
#include "core/clipboardmanager.h"
#include "core/configmanager.h"
#include "core/groupsmanager.h"
#include <QKeyEvent>
#include <QFocusEvent>
#include <QHideEvent>
#include <QTimer>
#include <QApplication>
#include <QScreen>
#include <QStyle>
#include <QToolButton>
#include <QHBoxLayout>
#include <QDebug>
#include <algorithm>

namespace ClipAI {
namespace UI {

PromptMenu::PromptMenu(Core::PromptManager* promptManager,
                      Core::ClipboardManager* clipboardManager,
                      Core::ConfigManager* configManager,
                      QWidget* parent)
    : QMenu(parent)
    , m_promptManager(promptManager)
    , m_clipboardManager(clipboardManager)
    , m_configManager(configManager)
{
    setupUi();
}

PromptMenu::~PromptMenu() = default;

void PromptMenu::setupUi()
{
    // Create search box with settings button at top
    QWidget* searchWidget = new QWidget();
    QHBoxLayout* searchLayout = new QHBoxLayout(searchWidget);
    searchLayout->setContentsMargins(4, 4, 4, 4);

    m_searchEdit = new QLineEdit();
    m_searchEdit->setPlaceholderText(tr("Search prompts..."));
    m_searchEdit->setClearButtonEnabled(true);
    connect(m_searchEdit, &QLineEdit::textChanged,
            this, &PromptMenu::onSearchTextChanged);

    searchLayout->addWidget(m_searchEdit);

    // Add settings button
    QToolButton* settingsButton = new QToolButton();
    settingsButton->setIcon(QIcon::fromTheme(QStringLiteral("preferences-system")));
    settingsButton->setToolTip(tr("Settings"));
    settingsButton->setAutoRaise(true);
    connect(settingsButton, &QToolButton::clicked, this, &PromptMenu::onSettingsClicked);
    searchLayout->addWidget(settingsButton);

    m_searchAction = new QWidgetAction(this);
    m_searchAction->setDefaultWidget(searchWidget);

    addAction(m_searchAction);

    // Separator
    m_separatorAction = addSeparator();
}

void PromptMenu::setContentTypeFilter(Models::ContentType type)
{
    m_contentTypeFilter = type;
}

void PromptMenu::showMenu(const QPoint& pos)
{
    // Determine content type from clipboard (only if filter is Any)
    Models::ContentType originalFilter = m_contentTypeFilter;
    Models::ContentType effectiveFilter = m_contentTypeFilter;

    if (m_clipboardManager && effectiveFilter == Models::ContentType::Any) {
        Core::ClipboardContentType contentType = m_clipboardManager->getContentType();
        if (contentType == Core::ClipboardContentType::Image) {
            effectiveFilter = Models::ContentType::Image;
        } else if (contentType == Core::ClipboardContentType::Text) {
            effectiveFilter = Models::ContentType::Text;
        }
    }

    // Temporarily apply filter for this menu show
    m_contentTypeFilter = effectiveFilter;
    rebuildMenu();
    m_contentTypeFilter = originalFilter; // Restore original filter

    // Clear search and focus
    m_searchEdit->clear();
    m_searchEdit->setFocus();

    // Show menu
    if (pos.isNull()) {
        // Center on screen or at cursor
        exec(QCursor::pos());
    } else {
        exec(pos);
    }
}

void PromptMenu::rebuildMenu()
{
    // Remove all existing actions except search widget and separator
    const QList<QAction*> allActions = actions();
    for (QAction* action : allActions) {
        if (action != m_searchAction && action != m_separatorAction) {
            removeAction(action);
            action->deleteLater();
        }
    }
    m_promptActions.clear();
    m_promptIds.clear();

    if (!m_promptManager) {
        QAction* noPromptsAction = addAction(tr("No prompts available"));
        noPromptsAction->setEnabled(false);
        return;
    }

    QVector<Models::Prompt> prompts = m_promptManager->getEnabledPrompts();

    // Filter by content type
    QVector<Models::Prompt> filteredPrompts;
    for (const auto& prompt : prompts) {
        if (m_contentTypeFilter == Models::ContentType::Any ||
            prompt.contentType() == m_contentTypeFilter ||
            prompt.contentType() == Models::ContentType::Any) {
            filteredPrompts.append(prompt);
        }
    }

    if (filteredPrompts.isEmpty()) {
        QAction* noPromptsAction = addAction(tr("No prompts available for this content type"));
        noPromptsAction->setEnabled(false);
        return;
    }

    // Get search text and filter by it
    QString searchText = m_searchEdit->text().toLower();
    bool searchEmpty = searchText.isEmpty();

    // Apply search filter to prompts
    if (!searchEmpty) {
        QVector<Models::Prompt> searchFiltered;
        for (const auto& prompt : filteredPrompts) {
            QString text = prompt.name() + prompt.description() + prompt.id();
            if (text.toLower().contains(searchText)) {
                searchFiltered.append(prompt);
            }
        }
        filteredPrompts = searchFiltered;
    }

    if (filteredPrompts.isEmpty()) {
        QAction* noPromptsAction = addAction(tr("No prompts found"));
        noPromptsAction->setEnabled(false);
        return;
    }

    // Split into high priority (>0) and normal priority (<=0 or unset)
    QVector<Models::Prompt> highPriority;
    QVector<Models::Prompt> normalPriority;

    for (const auto& prompt : filteredPrompts) {
        if (prompt.priority() > 0) {
            highPriority.append(prompt);
        } else {
            normalPriority.append(prompt);
        }
    }

    // If search is empty, show notification if no priority prompts
    if (searchEmpty && highPriority.isEmpty()) {
        QAction* hintAction = addAction(tr("Add priority to prompts to see them here"));
        hintAction->setEnabled(false);
        m_selectedIndex = -1;
        return;
    }

    // Sort high priority by priority DESC, then name ASC
    std::sort(highPriority.begin(), highPriority.end(),
        [](const Models::Prompt& a, const Models::Prompt& b) {
            if (a.priority() != b.priority()) {
                return a.priority() > b.priority();  // Higher priority first
            }
            return a.name() < b.name();  // Alphabetical tiebreaker
        });

    // Sort normal priority by name ASC
    std::sort(normalPriority.begin(), normalPriority.end(),
        [](const Models::Prompt& a, const Models::Prompt& b) {
            return a.name() < b.name();
        });

    // When search is empty, only show high priority prompts
    // When searching, show all prompts that match the search
    if (searchEmpty) {
        // Only show priority prompts
        for (const auto& prompt : highPriority) {
            QAction* action = createPromptAction(prompt);
            addAction(action);
            m_promptActions.append(action);
            m_promptIds.append(prompt.id());
        }
    } else {
        // Show all prompts when searching (already filtered by search text)
        for (const auto& prompt : highPriority) {
            QAction* action = createPromptAction(prompt);
            addAction(action);
            m_promptActions.append(action);
            m_promptIds.append(prompt.id());
        }

        for (const auto& prompt : normalPriority) {
            QAction* action = createPromptAction(prompt);
            addAction(action);
            m_promptActions.append(action);
            m_promptIds.append(prompt.id());
        }
    }

    m_selectedIndex = m_promptActions.isEmpty() ? -1 : 0;
    setSelectedIndex(m_selectedIndex);
}

QAction* PromptMenu::createPromptAction(const Models::Prompt& prompt)
{
    QString text = prompt.name();
    if (!prompt.description().isEmpty()) {
        text += QStringLiteral(" — ") + prompt.description();
    }

    QAction* action = new QAction(text, this);
    action->setData(prompt.id());

    connect(action, &QAction::triggered, this, &PromptMenu::onPromptTriggered);

    return action;
}

void PromptMenu::filterMenu(const QString& filter)
{
    QString filterLower = filter.toLower();

    // Show/hide actions based on filter
    for (int i = 0; i < m_promptActions.size(); ++i) {
        QAction* action = m_promptActions[i];
        bool matches = filter.isEmpty() ||
                      action->text().toLower().contains(filterLower) ||
                      m_promptIds[i].toLower().contains(filterLower);
        action->setVisible(matches);
    }

    // Update selection to first visible item
    m_selectedIndex = -1;
    for (int i = 0; i < m_promptActions.size(); ++i) {
        if (m_promptActions[i]->isVisible()) {
            m_selectedIndex = i;
            break;
        }
    }

    setSelectedIndex(m_selectedIndex);
}

int PromptMenu::getSelectedIndex() const
{
    return m_selectedIndex;
}

void PromptMenu::setSelectedIndex(int index)
{
    // Clear previous selection
    for (QAction* action : m_promptActions) {
        action->setChecked(false);
    }

    if (index >= 0 && index < m_promptActions.size()) {
        m_selectedIndex = index;
        m_promptActions[index]->setCheckable(true);
        m_promptActions[index]->setChecked(true);
        m_promptActions[index]->setCheckable(false);

        // Ensure the selected action is visible (highlighted)
        setActiveAction(m_promptActions[index]);
    }
}

void PromptMenu::keyPressEvent(QKeyEvent* event)
{
    switch (event->key()) {
        case Qt::Key_Up:
        case Qt::Key_K:
            onPrevItem();
            event->accept();
            break;

        case Qt::Key_Down:
        case Qt::Key_J:
            onNextItem();
            event->accept();
            break;

        case Qt::Key_Enter:
        case Qt::Key_Return:
            selectCurrentItem();
            event->accept();
            break;

        case Qt::Key_Escape:
            close();
            emit cancelled();
            event->accept();
            break;

        case Qt::Key_Tab:
            // Focus moves to search box
            m_searchEdit->setFocus();
            event->accept();
            break;

        default:
            // Ignore modifier keys (Alt, Ctrl, Shift, Meta) to prevent menu from closing
            // when switching keyboard layout or using keyboard shortcuts
            if (event->key() == Qt::Key_Alt ||
                event->key() == Qt::Key_Control ||
                event->key() == Qt::Key_Shift ||
                event->key() == Qt::Key_Meta) {
                event->accept();
            } else {
                QMenu::keyPressEvent(event);
            }
            break;
    }
}

void PromptMenu::showEvent(QShowEvent* event)
{
    QMenu::showEvent(event);

    // Set maximum height to 1/2 of screen height
    QScreen* screen = QApplication::primaryScreen();
    if (screen) {
        QRect screenGeometry = screen->availableGeometry();
        int maxHeight = screenGeometry.height() / 2;
        setMaximumHeight(maxHeight);
    }

    // Focus search box after a short delay
    QTimer::singleShot(50, this, [this]() {
        m_searchEdit->setFocus();
    });
}

void PromptMenu::focusOutEvent(QFocusEvent* event)
{
    // Don't close menu on focus out - this prevents closing when switching keyboard layout
    // The menu will still close on Escape key or when a prompt is selected
    Q_UNUSED(event);
    // Intentionally not calling QMenu::focusOutEvent() to prevent auto-close
}

void PromptMenu::hideEvent(QHideEvent* event)
{
    QMenu::hideEvent(event);
    // Menu is hidden - emit cancelled if not explicitly triggered
    // This allows proper cleanup when menu closes for any reason
}

void PromptMenu::onPromptTriggered()
{
    QAction* action = qobject_cast<QAction*>(sender());
    if (!action) {
        return;
    }

    QString promptId = action->data().toString();
    emit promptSelected(promptId);
    // Close menu immediately when triggered by mouse click
    hide();
}

void PromptMenu::onSearchTextChanged(const QString& text)
{
    Q_UNUSED(text);
    // Rebuild menu - when search is empty, show only priority prompts
    // when searching, show all prompts and filter them
    rebuildMenu();
}

void PromptMenu::onPrevItem()
{
    if (m_promptActions.isEmpty()) {
        return;
    }

    // Find previous visible item
    int newIndex = m_selectedIndex;
    do {
        newIndex--;
        if (newIndex < 0) {
            newIndex = m_promptActions.size() - 1;
        }
    } while (!m_promptActions[newIndex]->isVisible() && newIndex != m_selectedIndex);

    setSelectedIndex(newIndex);
}

void PromptMenu::onNextItem()
{
    if (m_promptActions.isEmpty()) {
        return;
    }

    // Find next visible item
    int newIndex = m_selectedIndex;
    do {
        newIndex++;
        if (newIndex >= m_promptActions.size()) {
            newIndex = 0;
        }
    } while (!m_promptActions[newIndex]->isVisible() && newIndex != m_selectedIndex);

    setSelectedIndex(newIndex);
}

void PromptMenu::selectCurrentItem()
{
    if (m_selectedIndex >= 0 && m_selectedIndex < m_promptActions.size()) {
        QAction* action = m_promptActions[m_selectedIndex];
        if (action->isVisible() && action->isEnabled()) {
            action->trigger();
            // Close menu immediately after triggering the action
            hide();
        }
    }
}

void PromptMenu::onSettingsClicked()
{
    close();
    emit settingsRequested();
}

} // namespace UI
} // namespace ClipAI
