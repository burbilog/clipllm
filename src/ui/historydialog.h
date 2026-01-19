#ifndef CLIPAI_UI_HISTORYDIALOG_H
#define CLIPAI_UI_HISTORYDIALOG_H

#include <QDialog>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QTextEdit>
#include <QLabel>
#include "core/historymanager.h"

namespace ClipAI {
namespace Core {
class HistoryManager;
}
}

namespace ClipAI {
namespace UI {

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(Core::HistoryManager* historyManager, QWidget* parent = nullptr);
    ~HistoryDialog();

    void refreshHistory();
    void clearHistory();

private slots:
    void onSearchTextChanged(const QString& text);
    void onFilterChanged();
    void onItemSelectionChanged();
    void onItemDoubleClicked(const QModelIndex& index);
    void onCopyClicked();
    void onDeleteClicked();
    void onFavoriteClicked();
    void onExportClicked();
    void onClearClicked();
    void onViewDetailsClicked();
    void onMarkdownToggleClicked();

private:
    void setupUi();
    void setupModel();
    void applyFilter();
    void loadEntry(int row);
    void updatePreviewDisplay(const Core::HistoryEntry& entry);
    QString formatDate(const QDateTime& date) const;
    QString formatDuration(double ms) const;

    Core::HistoryManager* m_historyManager = nullptr;

    // UI components
    QTableView* m_tableView = nullptr;
    QStandardItemModel* m_model = nullptr;
    QLineEdit* m_searchEdit = nullptr;
    QComboBox* m_modelCombo = nullptr;
    QComboBox* m_promptCombo = nullptr;
    QDateTimeEdit* m_fromDateEdit = nullptr;
    QDateTimeEdit* m_toDateEdit = nullptr;
    QCheckBox* m_favoritesOnlyCheck = nullptr;

    QTextEdit* m_previewText = nullptr;
    QLabel* m_statusLabel = nullptr;
    QPushButton* m_markdownToggle = nullptr;

    // Markdown state
    bool m_markdownMode = true;

    // Current display data
    QString m_currentInputText;
    QString m_currentOutputText;

    QPushButton* m_copyButton = nullptr;
    QPushButton* m_deleteButton = nullptr;
    QPushButton* m_favoriteButton = nullptr;
    QPushButton* m_exportButton = nullptr;
    QPushButton* m_clearButton = nullptr;
    QPushButton* m_viewDetailsButton = nullptr;
    QPushButton* m_closeButton = nullptr;

    // Current selection
    QString m_currentEntryId;
};

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_HISTORYDIALOG_H
