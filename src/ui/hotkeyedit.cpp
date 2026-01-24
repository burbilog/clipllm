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

#include "hotkeyedit.h"
#include <QKeyEvent>
#include <QFocusEvent>
#include <QStyle>
#include <QDebug>

namespace ClipLLM {
namespace UI {

HotkeyEdit::HotkeyEdit(QWidget* parent)
    : QWidget(parent)
{
    m_layout = new QHBoxLayout(this);
    m_layout->setContentsMargins(0, 0, 0, 0);

    m_displayLabel = new QLabel();
    m_displayLabel->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    m_displayLabel->setMinimumHeight(25);
    m_displayLabel->setAlignment(Qt::AlignCenter);
    m_displayLabel->setText(tr("Press hotkey..."));

    m_recordButton = new QPushButton(tr("Record"));
    m_recordButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    m_recordButton->setCheckable(true);
    connect(m_recordButton, &QPushButton::clicked, this, &HotkeyEdit::onRecordButtonClicked);

    m_clearButton = new QPushButton();
    m_clearButton->setIcon(style()->standardIcon(QStyle::SP_DialogResetButton));
    m_clearButton->setToolTip(tr("Clear"));
    m_clearButton->setEnabled(false);
    connect(m_clearButton, &QPushButton::clicked, this, &HotkeyEdit::onClearButtonClicked);

    m_layout->addWidget(m_displayLabel, 1);
    m_layout->addWidget(m_recordButton);
    m_layout->addWidget(m_clearButton);

    setFocusPolicy(Qt::StrongFocus);
    setFocusProxy(m_displayLabel);
}

HotkeyEdit::~HotkeyEdit() = default;

QKeySequence HotkeyEdit::keySequence() const
{
    return m_keySequence;
}

void HotkeyEdit::setKeySequence(const QKeySequence& sequence)
{
    if (m_keySequence == sequence) {
        return;
    }

    m_keySequence = sequence;
    updateDisplay();
    m_clearButton->setEnabled(!sequence.isEmpty());

    emit keySequenceChanged(sequence);
}

QString HotkeyEdit::hotkeyText() const
{
    // Use PortableText for consistent storage/restore across platforms
    return m_keySequence.toString(QKeySequence::PortableText);
}

void HotkeyEdit::setHotkeyText(const QString& text)
{
    // Use PortableText to match what hotkeyText() returns
    setKeySequence(QKeySequence::fromString(text, QKeySequence::PortableText));
}

void HotkeyEdit::setPlaceholderText(const QString& text)
{
    m_placeholderText = text;
    if (m_keySequence.isEmpty()) {
        m_displayLabel->setText(text.isEmpty() ? tr("Press hotkey...") : text);
    }
}

bool HotkeyEdit::event(QEvent* event)
{
    if (m_isRecording && event->type() == QEvent::ShortcutOverride) {
        return true; // Prevent shortcut from triggering
    }
    return QWidget::event(event);
}

void HotkeyEdit::keyPressEvent(QKeyEvent* event)
{
    if (!m_isRecording) {
        QWidget::keyPressEvent(event);
        return;
    }

    event->accept();

    // Handle native keys
    int key = event->key();
    Qt::KeyboardModifiers modifiers = event->modifiers();

    // Filter out modifier-only presses
    if (isModifierKey(key)) {
        m_currentModifiers = modifiers;
        return;
    }

    // Filter out mouse interaction keys
    if (key == Qt::Key_Meta || key == Qt::Key_unknown) {
        return;
    }

    // Build the key sequence properly by combining key with modifiers
    m_currentKey = key;
    m_currentModifiers = modifiers;

    // Combine key and modifiers into a single int value
    // This is the correct way to create a QKeySequence with modifiers
    int keyWithModifiers = key | modifiers;
    QKeySequence newSeq(keyWithModifiers);

    QString seqText = newSeq.toString(QKeySequence::NativeText);
    m_displayLabel->setText(seqText);

    qDebug() << "HotkeyEdit: captured key=" << key << "modifiers=" << modifiers
             << "combined=" << keyWithModifiers << "sequence=" << seqText;

    // Complete the recording
    setKeySequence(newSeq);
    stopRecording();
}

void HotkeyEdit::keyReleaseEvent(QKeyEvent* event)
{
    if (m_isRecording) {
        event->accept();
    }
    QWidget::keyReleaseEvent(event);
}

void HotkeyEdit::focusOutEvent(QFocusEvent* event)
{
    if (m_isRecording) {
        stopRecording();
    }
    QWidget::focusOutEvent(event);
}

void HotkeyEdit::onRecordButtonClicked()
{
    if (m_isRecording) {
        stopRecording();
    } else {
        m_isRecording = true;
        m_recordButton->setChecked(true);
        m_recordButton->setText(tr("Stop"));
        m_displayLabel->setText(tr("Press key combination..."));
        setFocus();

        emit recordingStarted();
    }
}

void HotkeyEdit::onClearButtonClicked()
{
    setKeySequence(QKeySequence());
}

void HotkeyEdit::stopRecording()
{
    if (!m_isRecording) {
        return;
    }

    m_isRecording = false;
    m_recordButton->setChecked(false);
    m_recordButton->setText(tr("Record"));
    m_currentKey = 0;
    m_currentModifiers = Qt::NoModifier;

    updateDisplay();

    emit recordingFinished();
}

QString HotkeyEdit::formatKeySequence(const QKeySequence& sequence) const
{
    if (sequence.isEmpty()) {
        return m_placeholderText.isEmpty() ? tr("None") : m_placeholderText;
    }
    return sequence.toString(QKeySequence::NativeText);
}

void HotkeyEdit::updateDisplay()
{
    m_displayLabel->setText(formatKeySequence(m_keySequence));
}

bool HotkeyEdit::isValidKey(int key) const
{
    // Filter out invalid keys
    if (key == Qt::Key_unknown || key == 0) {
        return false;
    }

    // Allow all non-modifier keys
    return !isModifierKey(key);
}

bool HotkeyEdit::isModifierKey(int key) const
{
    return key == Qt::Key_Control ||
           key == Qt::Key_Shift ||
           key == Qt::Key_Alt ||
           key == Qt::Key_AltGr ||
           key == Qt::Key_Meta;
}

} // namespace UI
} // namespace ClipLLM
