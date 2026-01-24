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

#include "imageviewdialog.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QPixmap>
#include <QSettings>

namespace ClipLLM {
namespace UI {

ImageViewDialog::ImageViewDialog(const QImage& image, QWidget* parent)
    : QDialog(parent)
    , m_image(image)
{
    setupUi();

    // Restore window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    restoreGeometry(settings.value("imageViewDialog").toByteArray());
    settings.endGroup();
}

ImageViewDialog::~ImageViewDialog() = default;

void ImageViewDialog::setupUi()
{
    resize(800, 600);
    setWindowTitle(tr("Clipboard Image"));

    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Scroll area for large images
    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setWidgetResizable(true);
    scrollArea->setAlignment(Qt::AlignCenter);

    m_imageLabel = new QLabel();
    m_imageLabel->setPixmap(QPixmap::fromImage(m_image));
    m_imageLabel->setAlignment(Qt::AlignCenter);
    scrollArea->setWidget(m_imageLabel);

    mainLayout->addWidget(scrollArea);

    // Image info
    QString info = tr("Size: %1 x %2 pixels").arg(m_image.width()).arg(m_image.height());
    QLabel* infoLabel = new QLabel(info);
    infoLabel->setAlignment(Qt::AlignCenter);
    infoLabel->setStyleSheet("color: gray; font-size: 11px; padding: 5px;");
    mainLayout->addWidget(infoLabel);

    // Buttons
    QHBoxLayout* buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();

    QPushButton* closeButton = new QPushButton(tr("Close"));
    connect(closeButton, &QPushButton::clicked, this, &QDialog::accept);
    buttonLayout->addWidget(closeButton);

    mainLayout->addLayout(buttonLayout);
}

void ImageViewDialog::closeEvent(QCloseEvent* event)
{
    // Save window geometry
    QSettings settings;
    settings.beginGroup("WindowGeometry");
    settings.setValue("imageViewDialog", saveGeometry());
    settings.endGroup();
    settings.sync();

    QDialog::closeEvent(event);
}

} // namespace UI
} // namespace ClipLLM
