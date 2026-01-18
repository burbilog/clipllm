#ifndef CLIPAI_CORE_CLIPBOARDMANAGER_H
#define CLIPAI_CORE_CLIPBOARDMANAGER_H

#include <QObject>
#include <QVariant>
#include <QPixmap>
#include <optional>
#include <memory>

namespace ClipAI {
namespace Core {

enum class ClipboardContentType {
    Text,
    Image,
    Html,
    Empty,
    Unknown
};

struct ClipboardContent
{
    ClipboardContentType type;
    QString text;
    QString html;
    QPixmap image;
    QByteArray imageData; // For base64 encoding
    QString mimeType;
    qint64 timestamp;

    bool isValid() const {
        return type != ClipboardContentType::Empty && type != ClipboardContentType::Unknown;
    }

    bool isText() const { return type == ClipboardContentType::Text; }
    bool isImage() const { return type == ClipboardContentType::Image; }
    bool isHtml() const { return type == ClipboardContentType::Html; }
};

class ClipboardManager : public QObject
{
    Q_OBJECT

public:
    explicit ClipboardManager(QObject* parent = nullptr);
    ~ClipboardManager();

    // Get current clipboard content
    std::optional<ClipboardContent> getContent() const;

    // Check clipboard type
    ClipboardContentType getContentType() const;

    // Text operations
    bool hasText() const;
    QString getText() const;

    // Image operations
    bool hasImage() const;
    QPixmap getImage() const;
    QByteArray getImageData(QByteArray format = QByteArray("PNG")) const;
    QString getImageBase64(QByteArray format = QByteArray("PNG")) const;

    // HTML operations
    bool hasHtml() const;
    QString getHtml() const;

    // Set clipboard content
    void setText(const QString& text);
    void setImage(const QPixmap& pixmap);

    // Monitor clipboard changes
    void startMonitoring();
    void stopMonitoring();
    bool isMonitoring() const { return m_monitoring; }

signals:
    void clipboardChanged(ClipboardContentType type);
    void textChanged(const QString& text);
    void imageChanged(const QPixmap& image);

private slots:
    void onChanged();

private:
    ClipboardContentType detectContentType() const;
    QString formatTimestamp() const;

    class ClipboardManagerPrivate;
    std::unique_ptr<ClipboardManagerPrivate> d;
    bool m_monitoring = false;
};

} // namespace Core
} // namespace ClipAI

Q_DECLARE_METATYPE(ClipAI::Core::ClipboardContentType)
Q_DECLARE_METATYPE(ClipAI::Core::ClipboardContent)

#endif // CLIPAI_CORE_CLIPBOARDMANAGER_H
