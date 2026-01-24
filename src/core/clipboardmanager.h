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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_CORE_CLIPBOARDMANAGER_H
#define CLIPLLM_CORE_CLIPBOARDMANAGER_H

#include <QObject>
#include <QVariant>
#include <QPixmap>
#include <optional>
#include <memory>

namespace ClipLLM {
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
} // namespace ClipLLM

Q_DECLARE_METATYPE(ClipLLM::Core::ClipboardContentType)
Q_DECLARE_METATYPE(ClipLLM::Core::ClipboardContent)

#endif // CLIPLLM_CORE_CLIPBOARDMANAGER_H
