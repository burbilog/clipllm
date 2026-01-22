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
