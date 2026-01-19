#include "historydialog.h"
#include "core/historymanager.h"
#include <QApplication>
#include <QClipboard>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QSplitter>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSettings>

namespace ClipAI {
namespace UI {

HistoryDialog::HistoryDialog(Core::HistoryManager* historyManager, QWidget* parent)
    : QDialog(parent)
    , m_historyManager(historyManager)
{
    setupUi();
    setupModel();
    refreshHistory();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("historyDialog").toByteArray());
    settings.endGroup();
}

HistoryDialog::~HistoryDialog() = default;

void HistoryDialog::setupUi()
{
    setWindowTitle(tr("ClipAI - History"));
    resize(900, 600);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Filter group
    QGroupBox* filterGroup = new QGroupBox(tr("Filters"));
    QHBoxLayout* filterLayout = new QHBoxLayout(filterGroup);

    m_searchEdit = new QLineEdit();
    m_searchEdit->setPlaceholderText(tr("Search..."));
    connect(m_searchEdit, &QLineEdit::textChanged, this, &HistoryDialog::onSearchTextChanged);

    m_modelCombo = new QComboBox();
    m_modelCombo->addItem(tr("All Models"), QString());
    connect(m_modelCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HistoryDialog::onFilterChanged);

    m_promptCombo = new QComboBox();
    m_promptCombo->addItem(tr("All Prompts"), QString());
    connect(m_promptCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HistoryDialog::onFilterChanged);

    m_favoritesOnlyCheck = new QCheckBox(tr("Favorites only"));
    connect(m_favoritesOnlyCheck, &QCheckBox::checkStateChanged,
            this, &HistoryDialog::onFilterChanged);

    m_fromDateEdit = new QDateTimeEdit();
    m_fromDateEdit->setCalendarPopup(true);
    m_fromDateEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    m_fromDateEdit->setDateTime(QDateTime::currentDateTime().addDays(-7));
    connect(m_fromDateEdit, &QDateTimeEdit::dateTimeChanged,
            this, &HistoryDialog::onFilterChanged);

    m_toDateEdit = new QDateTimeEdit();
    m_toDateEdit->setCalendarPopup(true);
    m_toDateEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    m_toDateEdit->setDateTime(QDateTime::currentDateTime().addDays(1));
    connect(m_toDateEdit, &QDateTimeEdit::dateTimeChanged,
            this, &HistoryDialog::onFilterChanged);

    filterLayout->addWidget(new QLabel(tr("Search:")));
    filterLayout->addWidget(m_searchEdit);
    filterLayout->addWidget(new QLabel(tr("Model:")));
    filterLayout->addWidget(m_modelCombo);
    filterLayout->addWidget(new QLabel(tr("Prompt:")));
    filterLayout->addWidget(m_promptCombo);
    filterLayout->addWidget(m_favoritesOnlyCheck);
    filterLayout->addWidget(new QLabel(tr("From:")));
    filterLayout->addWidget(m_fromDateEdit);
    filterLayout->addWidget(new QLabel(tr("To:")));
    filterLayout->addWidget(m_toDateEdit);

    mainLayout->addWidget(filterGroup);

    // Splitter for table and preview
    QSplitter* splitter = new QSplitter(Qt::Vertical);

    // Table view
    m_tableView = new QTableView();
    m_tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_tableView->setSelectionMode(QAbstractItemView::SingleSelection);
    m_tableView->setAlternatingRowColors(true);
    m_tableView->setSortingEnabled(true);
    m_tableView->setWordWrap(false);
    m_tableView->horizontalHeader()->setStretchLastSection(true);
    // Note: selectionModel() connects will be set in setupModel() after model is set
    connect(m_tableView, &QTableView::doubleClicked,
            this, &HistoryDialog::onItemDoubleClicked);

    splitter->addWidget(m_tableView);

    // Preview group
    QGroupBox* previewGroup = new QGroupBox(tr("Preview"));
    QVBoxLayout* previewLayout = new QVBoxLayout(previewGroup);

    m_markdownToggle = new QPushButton(tr("Markdown"));
    m_markdownToggle->setCheckable(true);
    m_markdownToggle->setChecked(m_markdownMode);
    connect(m_markdownToggle, &QPushButton::clicked, this, &HistoryDialog::onMarkdownToggleClicked);
    m_markdownToggle->setText(m_markdownMode ? tr("Markdown") : tr("Raw"));
    previewLayout->addWidget(m_markdownToggle);

    m_previewText = new QTextEdit();
    m_previewText->setReadOnly(true);
    previewLayout->addWidget(m_previewText);

    splitter->addWidget(previewGroup);
    splitter->setStretchFactor(0, 2);
    splitter->setStretchFactor(1, 1);

    mainLayout->addWidget(splitter, 1);

    // Status label
    m_statusLabel = new QLabel();
    mainLayout->addWidget(m_statusLabel);

    // Button row
    QHBoxLayout* buttonLayout = new QHBoxLayout();

    m_viewDetailsButton = new QPushButton(tr("View Details"));
    m_viewDetailsButton->setIcon(style()->standardIcon(QStyle::SP_FileDialogDetailedView));
    m_viewDetailsButton->setEnabled(false);
    connect(m_viewDetailsButton, &QPushButton::clicked, this, &HistoryDialog::onViewDetailsClicked);

    m_copyButton = new QPushButton(tr("Copy Output"));
    m_copyButton->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_copyButton->setEnabled(false);
    connect(m_copyButton, &QPushButton::clicked, this, &HistoryDialog::onCopyClicked);

    m_favoriteButton = new QPushButton(tr("Favorite"));
    m_favoriteButton->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    m_favoriteButton->setEnabled(false);
    connect(m_favoriteButton, &QPushButton::clicked, this, &HistoryDialog::onFavoriteClicked);

    m_deleteButton = new QPushButton(tr("Delete"));
    m_deleteButton->setIcon(style()->standardIcon(QStyle::SP_TrashIcon));
    m_deleteButton->setEnabled(false);
    connect(m_deleteButton, &QPushButton::clicked, this, &HistoryDialog::onDeleteClicked);

    m_exportButton = new QPushButton(tr("Export"));
    m_exportButton->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
    connect(m_exportButton, &QPushButton::clicked, this, &HistoryDialog::onExportClicked);

    m_clearButton = new QPushButton(tr("Clear All"));
    m_clearButton->setIcon(style()->standardIcon(QStyle::SP_DialogResetButton));
    connect(m_clearButton, &QPushButton::clicked, this, &HistoryDialog::onClearClicked);

    m_closeButton = new QPushButton(tr("Close"));
    m_closeButton->setIcon(style()->standardIcon(QStyle::SP_DialogCloseButton));
    connect(m_closeButton, &QPushButton::clicked, this, &QDialog::accept);

    buttonLayout->addWidget(m_viewDetailsButton);
    buttonLayout->addWidget(m_copyButton);
    buttonLayout->addWidget(m_favoriteButton);
    buttonLayout->addWidget(m_deleteButton);
    buttonLayout->addStretch();
    buttonLayout->addWidget(m_exportButton);
    buttonLayout->addWidget(m_clearButton);
    buttonLayout->addWidget(m_closeButton);

    mainLayout->addLayout(buttonLayout);
}

void HistoryDialog::setupModel()
{
    m_model = new QStandardItemModel(this);
    m_model->setHorizontalHeaderLabels({
        tr("Date"),
        tr("Prompt"),
        tr("Model"),
        tr("Input Preview"),
        tr("Output Preview"),
        tr("Duration"),
        tr("ID")
    });

    m_tableView->setModel(m_model);

    // Connect selection model after model is set (selectionModel is created now)
    connect(m_tableView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &HistoryDialog::onItemSelectionChanged);

    // Hide the ID column
    m_tableView->setColumnHidden(6, true);

    // Set column widths
    m_tableView->setColumnWidth(0, 150);
    m_tableView->setColumnWidth(1, 120);
    m_tableView->setColumnWidth(2, 150);
    m_tableView->setColumnWidth(3, 200);
    m_tableView->setColumnWidth(4, 200);
    m_tableView->setColumnWidth(5, 80);
}

void HistoryDialog::refreshHistory()
{
    if (!m_historyManager) {
        return;
    }

    m_model->removeRows(0, m_model->rowCount());

    QVector<Core::HistoryEntry> entries = m_historyManager->getAllEntries();

    // Populate model combos
    QStringList models;
    QStringList prompts;

    for (const auto& entry : entries) {
        if (!models.contains(entry.model)) {
            models.append(entry.model);
        }
        if (!prompts.contains(entry.promptName)) {
            prompts.append(entry.promptName);
        }
    }

    // Save current selections
    QString currentModel = m_modelCombo->currentData().toString();
    QString currentPrompt = m_promptCombo->currentData().toString();

    // Rebuild model combo
    m_modelCombo->clear();
    m_modelCombo->addItem(tr("All Models"), QString());
    for (const QString& model : models) {
        m_modelCombo->addItem(model, model);
    }

    // Rebuild prompt combo
    m_promptCombo->clear();
    m_promptCombo->addItem(tr("All Prompts"), QString());
    for (const QString& prompt : prompts) {
        m_promptCombo->addItem(prompt, prompt);
    }

    // Restore selections
    int modelIndex = m_modelCombo->findData(currentModel);
    if (modelIndex >= 0) {
        m_modelCombo->setCurrentIndex(modelIndex);
    }

    int promptIndex = m_promptCombo->findData(currentPrompt);
    if (promptIndex >= 0) {
        m_promptCombo->setCurrentIndex(promptIndex);
    }

    applyFilter();

    m_statusLabel->setText(tr("Total entries: %1").arg(entries.size()));
}

void HistoryDialog::applyFilter()
{
    if (!m_historyManager) {
        return;
    }

    Core::HistoryFilter filter;
    filter.startDate = m_fromDateEdit->dateTime();
    filter.endDate = m_toDateEdit->dateTime();
    filter.searchText = m_searchEdit->text();
    filter.model = m_modelCombo->currentData().toString();
    filter.promptId = m_promptCombo->currentData().toString();
    filter.favoritesOnly = m_favoritesOnlyCheck->isChecked();

    QVector<Core::HistoryEntry> entries = m_historyManager->getFilteredEntries(filter);

    m_model->removeRows(0, m_model->rowCount());

    for (const auto& entry : entries) {
        QList<QStandardItem*> row;

        // Date
        QStandardItem* dateItem = new QStandardItem(formatDate(entry.timestamp));
        dateItem->setData(entry.id, Qt::UserRole);
        if (entry.favorite) {
            QFont font = dateItem->font();
            font.setBold(true);
            dateItem->setFont(font);
            dateItem->setIcon(style()->standardIcon(QStyle::SP_DialogSaveButton));
        }
        row.append(dateItem);

        // Prompt name
        row.append(new QStandardItem(entry.promptName));

        // Model
        row.append(new QStandardItem(entry.model));

        // Input preview
        row.append(new QStandardItem(entry.getInputPreview(100)));

        // Output preview
        row.append(new QStandardItem(entry.getOutputPreview(100)));

        // Duration
        row.append(new QStandardItem(formatDuration(entry.durationMs)));

        // ID (hidden)
        row.append(new QStandardItem(entry.id));

        m_model->appendRow(row);
    }

    m_statusLabel->setText(tr("Showing %1 entries").arg(entries.size()));
}

void HistoryDialog::onSearchTextChanged(const QString& text)
{
    Q_UNUSED(text)
    applyFilter();
}

void HistoryDialog::onFilterChanged()
{
    applyFilter();
}

void HistoryDialog::onItemSelectionChanged()
{
    QItemSelectionModel* selectionModel = m_tableView->selectionModel();
    QModelIndexList selected = selectionModel->selectedRows();

    if (selected.isEmpty()) {
        m_currentEntryId.clear();
        m_previewText->clear();
        m_copyButton->setEnabled(false);
        m_deleteButton->setEnabled(false);
        m_favoriteButton->setEnabled(false);
        m_viewDetailsButton->setEnabled(false);
        return;
    }

    int row = selected.first().row();
    loadEntry(row);

    m_copyButton->setEnabled(true);
    m_deleteButton->setEnabled(true);
    m_favoriteButton->setEnabled(true);
    m_viewDetailsButton->setEnabled(true);
}

void HistoryDialog::loadEntry(int row)
{
    // Get entry ID
    QModelIndex idIndex = m_model->index(row, 6);
    m_currentEntryId = m_model->data(idIndex).toString();

    if (!m_historyManager) {
        return;
    }

    auto entry = m_historyManager->getEntry(m_currentEntryId);
    if (!entry) {
        return;
    }

    // Store raw text for markdown toggle
    m_currentInputText = entry->inputText;
    m_currentOutputText = entry->outputText;

    updatePreviewDisplay(*entry);

    // Update favorite button
    m_favoriteButton->setText(entry->favorite ? tr("Unfavorite") : tr("Favorite"));
}

void HistoryDialog::onItemDoubleClicked(const QModelIndex& index)
{
    loadEntry(index.row());
}

void HistoryDialog::onCopyClicked()
{
    if (!m_historyManager || m_currentEntryId.isEmpty()) {
        return;
    }

    auto entry = m_historyManager->getEntry(m_currentEntryId);
    if (entry) {
        QApplication::clipboard()->setText(entry->outputText);
        m_statusLabel->setText(tr("Copied to clipboard"));
    }
}

void HistoryDialog::onDeleteClicked()
{
    if (!m_historyManager || m_currentEntryId.isEmpty()) {
        return;
    }

    auto reply = QMessageBox::question(
        this,
        tr("Delete Entry"),
        tr("Are you sure you want to delete this entry?"),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        m_historyManager->removeEntry(m_currentEntryId);
        refreshHistory();
    }
}

void HistoryDialog::onFavoriteClicked()
{
    if (!m_historyManager || m_currentEntryId.isEmpty()) {
        return;
    }

    m_historyManager->toggleFavorite(m_currentEntryId);
    applyFilter();
}

void HistoryDialog::onExportClicked()
{
    if (!m_historyManager) {
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(
        this,
        tr("Export History"),
        QStringLiteral("clipai_history_%1.json").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")),
        tr("JSON Files (*.json)")
    );

    if (fileName.isEmpty()) {
        return;
    }

    Core::HistoryFilter filter;
    filter.startDate = m_fromDateEdit->dateTime();
    filter.endDate = m_toDateEdit->dateTime();
    filter.searchText = m_searchEdit->text();
    filter.model = m_modelCombo->currentData().toString();
    filter.promptId = m_promptCombo->currentData().toString();
    filter.favoritesOnly = m_favoritesOnlyCheck->isChecked();

    QString jsonData = m_historyManager->exportToJson(filter);

    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(jsonData.toUtf8());
        file.close();
        m_statusLabel->setText(tr("Exported to %1").arg(fileName));
    } else {
        QMessageBox::warning(this, tr("Export Failed"),
                           tr("Failed to write to file: %1").arg(fileName));
    }
}

void HistoryDialog::onClearClicked()
{
    auto reply = QMessageBox::question(
        this,
        tr("Clear All History"),
        tr("Are you sure you want to delete all history entries? This cannot be undone."),
        QMessageBox::Yes | QMessageBox::No
    );

    if (reply == QMessageBox::Yes) {
        clearHistory();
    }
}

void HistoryDialog::clearHistory()
{
    if (m_historyManager) {
        m_historyManager->clearAll();
        refreshHistory();
    }
}

void HistoryDialog::onViewDetailsClicked()
{
    // Could open a separate detailed view dialog
    // For now, the preview shows most details
}

QString HistoryDialog::formatDate(const QDateTime& date) const
{
    return date.toString("yyyy-MM-dd HH:mm");
}

QString HistoryDialog::formatDuration(double ms) const
{
    if (ms < 1000) {
        return tr("%1 ms").arg(qRound(ms));
    } else if (ms < 60000) {
        return tr("%1 s").arg(ms / 1000.0, 0, 'f', 1);
    } else {
        int minutes = qRound(ms / 60000.0);
        int seconds = qRound((ms - minutes * 60000) / 1000.0);
        return tr("%1m %2s").arg(minutes).arg(seconds);
    }
}

void HistoryDialog::updatePreviewDisplay(const Core::HistoryEntry& entry)
{
    if (m_markdownMode) {
        // Build full markdown content with headers
        QString fullMarkdown;
        fullMarkdown += "**Prompt:** " + entry.promptName + "\n\n";
        fullMarkdown += "**Model:** " + entry.model + "\n\n";
        fullMarkdown += "**Date:** " + formatDate(entry.timestamp) + "\n\n";
        fullMarkdown += "**Duration:** " + formatDuration(entry.durationMs) + "\n\n";
        fullMarkdown += "**Tokens:** " + QString::number(entry.inputTokens) + " input / " +
                       QString::number(entry.outputTokens) + " output\n\n";
        fullMarkdown += "---\n\n";
        fullMarkdown += "## Input\n\n" + m_currentInputText + "\n\n";
        fullMarkdown += "## Output\n\n" + m_currentOutputText;

        m_previewText->setMarkdown(fullMarkdown);
    } else {
        // Plain text mode
        QString fullText;
        fullText += tr("Prompt: %1\n").arg(entry.promptName);
        fullText += tr("Model: %1\n").arg(entry.model);
        fullText += tr("Date: %1\n").arg(formatDate(entry.timestamp));
        fullText += tr("Duration: %1\n").arg(formatDuration(entry.durationMs));
        fullText += tr("Tokens: %1 input / %2 output\n")
                       .arg(entry.inputTokens)
                       .arg(entry.outputTokens);
        fullText += "\n" + QString("-").repeated(40) + "\n\n";
        fullText += tr("Input:\n");
        fullText += m_currentInputText + "\n\n";
        fullText += tr("Output:\n");
        fullText += m_currentOutputText;

        m_previewText->setPlainText(fullText);
    }
}

void HistoryDialog::onMarkdownToggleClicked()
{
    m_markdownMode = m_markdownToggle->isChecked();
    m_markdownToggle->setText(m_markdownMode ? tr("Markdown") : tr("Raw"));

    // Re-render the current entry if one is selected
    if (!m_currentEntryId.isEmpty() && m_historyManager) {
        auto entry = m_historyManager->getEntry(m_currentEntryId);
        if (entry) {
            updatePreviewDisplay(*entry);
        }
    }
}

void HistoryDialog::closeEvent(QCloseEvent* event)
{
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("historyDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

} // namespace UI
} // namespace ClipAI
