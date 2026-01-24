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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef CLIPLLM_CORE_KEYCHAINSTORE_H
#define CLIPLLM_CORE_KEYCHAINSTORE_H

#include <QObject>
#include <QString>

namespace ClipLLM {
namespace Core {

class KeychainStore : public QObject
{
    Q_OBJECT

public:
    explicit KeychainStore(QObject* parent = nullptr);
    ~KeychainStore();

    // API Key storage
    bool writeApiKey(const QString& apiKey);
    QString readApiKey() const;
    bool removeApiKey();
    bool hasApiKey() const;

    // Provider-specific keys
    bool writeProviderKey(const QString& provider, const QString& apiKey);
    QString readProviderKey(const QString& provider) const;
    bool removeProviderKey(const QString& provider);

signals:
    void apiKeyWriteFailed(const QString& error);
    void apiKeyReadFailed(const QString& error);

private:
    QString getServiceName() const;
    QString getKeyName(const QString& provider = QString()) const;

    QString m_serviceName;
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_KEYCHAINSTORE_H
