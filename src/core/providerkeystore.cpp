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

#include "providerkeystore.h"
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

namespace ClipLLM {
namespace Core {

const QString ProviderKeyStore::KEYS_GROUP = QStringLiteral("ProviderKeys");

ProviderKeyStore::ProviderKeyStore()
{
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QDir configDir(configPath);

    if (!configDir.exists()) {
        configDir.mkpath(QStringLiteral("."));
    }

    QString settingsFile = configDir.filePath(QStringLiteral("settings.ini"));
    m_settings = std::make_unique<QSettings>(settingsFile, QSettings::IniFormat);
}

ProviderKeyStore::~ProviderKeyStore()
{
    if (m_settings) {
        m_settings->sync();
    }
}

void ProviderKeyStore::setProviderKey(const QString& profileId, const QString& apiKey)
{
    m_settings->beginGroup(KEYS_GROUP);
    m_settings->setValue(profileId, apiKey);
    m_settings->endGroup();
    m_settings->sync();

    qDebug() << "Stored API key for profile:" << profileId;
}

QString ProviderKeyStore::providerKey(const QString& profileId) const
{
    m_settings->beginGroup(KEYS_GROUP);
    QString key = m_settings->value(profileId).toString();
    m_settings->endGroup();

    return key;
}

void ProviderKeyStore::removeProviderKey(const QString& profileId)
{
    m_settings->beginGroup(KEYS_GROUP);
    m_settings->remove(profileId);
    m_settings->endGroup();
    m_settings->sync();

    qDebug() << "Removed API key for profile:" << profileId;
}

bool ProviderKeyStore::hasProviderKey(const QString& profileId) const
{
    m_settings->beginGroup(KEYS_GROUP);
    bool has = m_settings->contains(profileId);
    QString key = m_settings->value(profileId).toString();
    m_settings->endGroup();

    // Has key only if it exists and is not empty
    return has && !key.isEmpty();
}

QStringList ProviderKeyStore::providerIdsWithKeys() const
{
    m_settings->beginGroup(KEYS_GROUP);
    QStringList ids = m_settings->childKeys();
    m_settings->endGroup();

    // Filter out empty keys
    QStringList result;
    for (const QString& id : ids) {
        if (!providerKey(id).isEmpty()) {
            result.append(id);
        }
    }

    return result;
}

void ProviderKeyStore::sync()
{
    m_settings->sync();
}

} // namespace Core
} // namespace ClipLLM
