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

#ifndef CLIPLLM_UI_HOTKEYEDIT_H
#define CLIPLLM_UI_HOTKEYEDIT_H

#include <QWidget>
#include <QKeySequence>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>

namespace ClipLLM {
namespace UI {

class HotkeyEdit : public QWidget
{
    Q_OBJECT

public:
    explicit HotkeyEdit(QWidget* parent = nullptr);
    ~HotkeyEdit();

    QKeySequence keySequence() const;
    void setKeySequence(const QKeySequence& sequence);

    QString hotkeyText() const;
    void setHotkeyText(const QString& text);

    void setPlaceholderText(const QString& text);

    bool isRecording() const { return m_isRecording; }

signals:
    void keySequenceChanged(const QKeySequence& sequence);
    void recordingStarted();
    void recordingFinished();

protected:
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;
    bool event(QEvent* event) override;

private slots:
    void onRecordButtonClicked();
    void onClearButtonClicked();
    void stopRecording();

private:
    QString formatKeySequence(const QKeySequence& sequence) const;
    void updateDisplay();
    bool isValidKey(int key) const;
    bool isModifierKey(int key) const;

    QPushButton* m_recordButton = nullptr;
    QPushButton* m_clearButton = nullptr;
    QLabel* m_displayLabel = nullptr;
    QHBoxLayout* m_layout = nullptr;

    QKeySequence m_keySequence;
    QString m_placeholderText;
    bool m_isRecording = false;
    int m_currentKey = 0;
    Qt::KeyboardModifiers m_currentModifiers = Qt::NoModifier;
};

} // namespace UI
} // namespace ClipLLM

#endif // CLIPLLM_UI_HOTKEYEDIT_H
