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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_UI_HISTORYDIALOG_H
#define CLIPLLM_UI_HISTORYDIALOG_H

#include <QDialog>
#include <QCloseEvent>
#include <QTableView>
#include <QStandardItemModel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QTextEdit>
#include <QLabel>
#include <QSplitter>
#include "core/historymanager.h"

namespace ClipLLM {
namespace Core {
class HistoryManager;
}
}

namespace ClipLLM {
namespace UI {

class HistoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit HistoryDialog(Core::HistoryManager* historyManager, QWidget* parent = nullptr);
    ~HistoryDialog();

    void refreshHistory();
    void clearHistory();

protected:
    void showEvent(QShowEvent* event) override;
    void closeEvent(QCloseEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;

private slots:
    void onSearchTextChanged(const QString& text);
    void onFilterChanged();
    void onItemSelectionChanged();
    void onItemDoubleClicked(const QModelIndex& index);
    void onDeleteClicked();
    void onFavoriteClicked();
    void onExportClicked();
    void onClearClicked();
    void onViewDetailsClicked();
    void onMarkdownToggleClicked();
    void onZoomOutClicked();
    void onZoomInClicked();

private:
    void setupUi();
    void setupModel();
    void applyFilter();
    void loadEntry(int row);
    void updatePreviewDisplay(const Core::HistoryEntry& entry);
    QString formatDate(const QDateTime& date) const;
    QString formatDuration(double ms) const;
    void applyFontSize();
    void saveFontSize();
    void loadFontSize();

    Core::HistoryManager* m_historyManager = nullptr;

    // UI components
    QTableView* m_tableView = nullptr;
    QStandardItemModel* m_model = nullptr;
    QSplitter* m_splitter = nullptr;
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

    // Font size state
    int m_fontSize = 10;

    // Current display data
    QString m_currentInputText;
    QString m_currentOutputText;

    QPushButton* m_deleteButton = nullptr;
    QPushButton* m_favoriteButton = nullptr;
    QPushButton* m_exportButton = nullptr;
    QPushButton* m_clearButton = nullptr;
    QPushButton* m_viewDetailsButton = nullptr;
    QPushButton* m_closeButton = nullptr;
    QPushButton* m_zoomOutButton = nullptr;
    QPushButton* m_zoomInButton = nullptr;

    // Current selection
    QString m_currentEntryId;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_HISTORYDIALOG_H
