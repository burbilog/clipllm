#include "imageviewdialog.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QPixmap>
#include <QSettings>

namespace ClipAI {
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
} // namespace ClipAI
