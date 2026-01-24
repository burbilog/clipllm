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

#include "clipboardmanager.h"
#include <QApplication>
#include <QClipboard>
#include <QMimeData>
#include <QBuffer>
#include <QDateTime>
#include <QDebug>

namespace ClipLLM {
namespace Core {

// Private implementation for forward declaration
class ClipboardManager::ClipboardManagerPrivate
{
public:
    QClipboard* clipboard = nullptr;
};

ClipboardManager::ClipboardManager(QObject* parent)
    : QObject(parent)
    , d(std::make_unique<ClipboardManagerPrivate>())
{
    d->clipboard = QApplication::clipboard();
}

ClipboardManager::~ClipboardManager() = default;

std::optional<ClipboardContent> ClipboardManager::getContent() const
{
    ClipboardContent content;
    content.timestamp = QDateTime::currentSecsSinceEpoch();
    content.type = detectContentType();

    switch (content.type) {
        case ClipboardContentType::Text:
            content.text = d->clipboard->text();
            content.mimeType = QStringLiteral("text/plain");
            if (content.text.isEmpty()) {
                return std::nullopt;
            }
            break;

        case ClipboardContentType::Image: {
            QPixmap pixmap = d->clipboard->pixmap();
            if (pixmap.isNull()) {
                return std::nullopt;
            }
            content.image = pixmap;

            // Get image data for base64 encoding
            QBuffer buffer(&content.imageData);
            buffer.open(QIODevice::WriteOnly);
            pixmap.save(&buffer, "PNG");
            buffer.close();

            content.mimeType = QStringLiteral("image/png");
            break;
        }

        case ClipboardContentType::Html:
            content.html = d->clipboard->text();
            content.text = d->clipboard->text(); // Also get plain text as fallback
            content.mimeType = QStringLiteral("text/html");
            break;

        case ClipboardContentType::Empty:
        case ClipboardContentType::Unknown:
            return std::nullopt;
    }

    return content;
}

ClipboardContentType ClipboardManager::getContentType() const
{
    return detectContentType();
}

bool ClipboardManager::hasText() const
{
    return d->clipboard && !d->clipboard->text().isEmpty();
}

QString ClipboardManager::getText() const
{
    return d->clipboard ? d->clipboard->text() : QString();
}

bool ClipboardManager::hasImage() const
{
    return d->clipboard && !d->clipboard->pixmap().isNull();
}

QPixmap ClipboardManager::getImage() const
{
    return d->clipboard ? d->clipboard->pixmap() : QPixmap();
}

QByteArray ClipboardManager::getImageData(QByteArray format) const
{
    QPixmap pixmap = getImage();
    if (pixmap.isNull()) {
        return QByteArray();
    }

    QByteArray data;
    QBuffer buffer(&data);
    buffer.open(QIODevice::WriteOnly);
    pixmap.save(&buffer, format.constData());
    buffer.close();

    return data;
}

QString ClipboardManager::getImageBase64(QByteArray format) const
{
    QByteArray data = getImageData(format);
    if (data.isEmpty()) {
        return QString();
    }

    return QString::fromLatin1(data.toBase64());
}

bool ClipboardManager::hasHtml() const
{
    const QMimeData* mimeData = d->clipboard ? d->clipboard->mimeData() : nullptr;
    return mimeData && mimeData->hasHtml();
}

QString ClipboardManager::getHtml() const
{
    return d->clipboard ? d->clipboard->text() : QString();
}

void ClipboardManager::setText(const QString& text)
{
    if (d->clipboard) {
        d->clipboard->setText(text);
    }
}

void ClipboardManager::setImage(const QPixmap& pixmap)
{
    if (d->clipboard) {
        d->clipboard->setPixmap(pixmap);
    }
}

void ClipboardManager::startMonitoring()
{
    if (!d->clipboard || m_monitoring) {
        return;
    }

    connect(d->clipboard, &QClipboard::changed,
            this, &ClipboardManager::onChanged);
    m_monitoring = true;
}

void ClipboardManager::stopMonitoring()
{
    if (!d->clipboard || !m_monitoring) {
        return;
    }

    disconnect(d->clipboard, &QClipboard::changed,
               this, &ClipboardManager::onChanged);
    m_monitoring = false;
}

void ClipboardManager::onChanged()
{
    ClipboardContentType type = detectContentType();
    emit clipboardChanged(type);

    if (type == ClipboardContentType::Text || type == ClipboardContentType::Html) {
        emit textChanged(getText());
    } else if (type == ClipboardContentType::Image) {
        emit imageChanged(getImage());
    }
}

ClipboardContentType ClipboardManager::detectContentType() const
{
    if (!d->clipboard) {
        return ClipboardContentType::Empty;
    }

    const QMimeData* mimeData = d->clipboard->mimeData();
    if (!mimeData) {
        return ClipboardContentType::Empty;
    }

    // Check for image first
    if (mimeData->hasImage()) {
        QPixmap pixmap = d->clipboard->pixmap();
        if (!pixmap.isNull()) {
            return ClipboardContentType::Image;
        }
    }

    // Check for HTML
    if (mimeData->hasHtml()) {
        return ClipboardContentType::Html;
    }

    // Check for text
    if (mimeData->hasText()) {
        QString text = mimeData->text();
        if (!text.isEmpty()) {
            return ClipboardContentType::Text;
        }
    }

    return ClipboardContentType::Empty;
}

QString ClipboardManager::formatTimestamp() const
{
    return QDateTime::currentDateTime().toString(Qt::ISODate);
}

} // namespace Core
} // namespace ClipLLM
