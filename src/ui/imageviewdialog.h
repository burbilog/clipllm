#ifndef CLIPAI_UI_IMAGEVIEWDIALOG_H
#define CLIPAI_UI_IMAGEVIEWDIALOG_H

#include <QDialog>
#include <QLabel>

namespace ClipAI {
namespace UI {

class ImageViewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageViewDialog(const QImage& image, QWidget* parent = nullptr);
    ~ImageViewDialog();

private:
    void setupUi();

    QImage m_image;
    QLabel* m_imageLabel = nullptr;
};

} // namespace UI
} // namespace ClipAI

#endif
