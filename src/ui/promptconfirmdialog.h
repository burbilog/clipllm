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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPAI_UI_PROMPTCONFLICTDIALOG_H
#define CLIPAI_UI_PROMPTCONFLICTDIALOG_H

#include <QDialog>
#include <QString>

namespace ClipAI {
namespace UI {

class PromptConflictDialog : public QDialog
{
    Q_OBJECT

public:
    enum class Action {
        Yes,
        YesForAll,
        No,
        NoForAll,
        Cancel
    };

    PromptConflictDialog(const QString& promptName,
                        const QString& existingDetails,
                        const QString& newDetails,
                        QWidget* parent = nullptr);

    Action action() const { return m_action; }

private:
    Action m_action = Action::Cancel;
};

} // namespace UI
} // namespace ClipAI

#endif // CLIPAI_UI_PROMPTCONFLICTDIALOG_H
