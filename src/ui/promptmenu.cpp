#include "promptmenu.h"
#include "core/clipboardmanager.h"
#include "core/configmanager.h"
#include <QKeyEvent>
#include <QTimer>
#include <QApplication>
#include <QStyle>
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
    // Create search box at top
    QWidget* searchWidget = new QWidget();
    QVBoxLayout* searchLayout = new QVBoxLayout(searchWidget);
    searchLayout->setContentsMargins(4, 4, 4, 4);

    m_searchEdit = new QLineEdit();
    m_searchEdit->setPlaceholderText(tr("Search prompts..."));
    m_searchEdit->setClearButtonEnabled(true);
    connect(m_searchEdit, &QLineEdit::textChanged,
            this, &PromptMenu::onSearchTextChanged);

    searchLayout->addWidget(m_searchEdit);

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
    // Remove existing prompt actions
    for (QAction* action : m_promptActions) {
        removeAction(action);
        action->deleteLater();
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

    // Sort by priority (descending), then by name (ascending)
    std::sort(filteredPrompts.begin(), filteredPrompts.end(),
        [](const Models::Prompt& a, const Models::Prompt& b) {
            if (a.priority() != b.priority()) {
                return a.priority() > b.priority();
            }
            return a.name() < b.name();
        });

    // Add all prompt actions (QMenu handles scrolling automatically)
    for (const auto& prompt : filteredPrompts) {
        QAction* action = createPromptAction(prompt);
        addAction(action);
        m_promptActions.append(action);
        m_promptIds.append(prompt.id());
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

    // Set icon based on prompt icon type
    QString iconName = prompt.getIconName();
    if (!iconName.isEmpty()) {
        action->setIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon));
    }

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
            // Pass other keys to search
            QMenu::keyPressEvent(event);
            break;
    }
}

void PromptMenu::showEvent(QShowEvent* event)
{
    QMenu::showEvent(event);

    // Set maximum height based on maxPrompts setting
    int maxPrompts = m_configManager ? m_configManager->maxPrompts() : 10;
    if (maxPrompts > 0) {
        // Approximate height: search box (50px) + separator + prompts (30px each)
        int maxHeight = 50 + 2 + (maxPrompts * 30);
        setMaximumHeight(maxHeight);
    }

    // Focus search box after a short delay
    QTimer::singleShot(50, this, [this]() {
        m_searchEdit->setFocus();
    });
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
    filterMenu(text);
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

} // namespace UI
} // namespace ClipAI
