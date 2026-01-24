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

#include "promptconfirmdialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>

namespace ClipLLM {
namespace UI {

PromptConflictDialog::PromptConflictDialog(const QString& promptName,
                                          const QString& existingDetails,
                                          const QString& newDetails,
                                          QWidget* parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Prompt Conflict"));
    setMinimumWidth(500);

    auto* layout = new QVBoxLayout(this);

    // Title label
    auto* titleLabel = new QLabel(
        tr("A prompt named \"%1\" already exists.").arg(promptName), this);
    titleLabel->setWordWrap(true);
    layout->addWidget(titleLabel);

    layout->addSpacing(10);

    // Existing prompt details
    auto* existingLabel = new QLabel(
        tr("<b>Existing:</b> %1").arg(existingDetails), this);
    existingLabel->setWordWrap(true);
    layout->addWidget(existingLabel);

    // New prompt details
    auto* newLabel = new QLabel(
        tr("<b>New:</b> %1").arg(newDetails), this);
    newLabel->setWordWrap(true);
    layout->addWidget(newLabel);

    layout->addSpacing(10);

    // Question
    auto* questionLabel = new QLabel(tr("Do you want to replace it?"), this);
    layout->addWidget(questionLabel);

    layout->addSpacing(10);

    // Buttons
    auto* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    auto* yesButton = new QPushButton(tr("Yes"), this);
    auto* yesForAllButton = new QPushButton(tr("Yes for all"), this);
    auto* noButton = new QPushButton(tr("No"), this);
    auto* noForAllButton = new QPushButton(tr("No for all"), this);
    auto* cancelButton = new QPushButton(tr("Cancel"), this);

    buttonLayout->addWidget(yesButton);
    buttonLayout->addWidget(yesForAllButton);
    buttonLayout->addWidget(noButton);
    buttonLayout->addWidget(noForAllButton);
    buttonLayout->addWidget(cancelButton);

    layout->addLayout(buttonLayout);

    connect(yesButton, &QPushButton::clicked, this, [this] {
        m_action = Action::Yes;
        accept();
    });

    connect(yesForAllButton, &QPushButton::clicked, this, [this] {
        m_action = Action::YesForAll;
        accept();
    });

    connect(noButton, &QPushButton::clicked, this, [this] {
        m_action = Action::No;
        accept();
    });

    connect(noForAllButton, &QPushButton::clicked, this, [this] {
        m_action = Action::NoForAll;
        accept();
    });

    connect(cancelButton, &QPushButton::clicked, this, [this] {
        m_action = Action::Cancel;
        reject();
    });

    setLayout(layout);
}

} // namespace UI
} // namespace ClipLLM
