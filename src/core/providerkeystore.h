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

#ifndef CLIPLLM_CORE_PROVIDERKEYSTORE_H
#define CLIPLLM_CORE_PROVIDERKEYSTORE_H

#include <QString>
#include <QSettings>
#include <memory>

namespace ClipLLM {
namespace Core {

/**
 * @brief Abstraction layer for storing provider API keys.
 *
 * Current implementation stores keys in settings.ini under [ProviderKeys] section.
 * Future implementation can be replaced with platform-specific keychain storage:
 * - Linux: libsecret/KWallet
 * - Windows: Credential Manager
 * - macOS: Keychain Services
 *
 * The interface remains the same, allowing easy replacement of the underlying storage.
 */
class ProviderKeyStore
{
public:
    ProviderKeyStore();
    ~ProviderKeyStore();

    /**
     * @brief Store API key for a provider profile
     * @param profileId Unique identifier for the provider profile
     * @param apiKey API key to store (empty means "no key required", e.g., local Ollama)
     */
    void setProviderKey(const QString& profileId, const QString& apiKey);

    /**
     * @brief Retrieve API key for a provider profile
     * @param profileId Unique identifier for the provider profile
     * @return API key if found, empty string if not found or if key not required
     */
    QString providerKey(const QString& profileId) const;

    /**
     * @brief Remove API key for a profile
     * @param profileId Unique identifier for the provider profile
     */
    void removeProviderKey(const QString& profileId);

    /**
     * @brief Check if profile has a stored key
     * @param profileId Unique identifier for the provider profile
     * @return true if a non-empty key is stored for this profile
     */
    bool hasProviderKey(const QString& profileId) const;

    /**
     * @brief Get all profile IDs that have stored keys
     * @return List of profile IDs with stored keys
     */
    QStringList providerIdsWithKeys() const;

    /**
     * @brief Sync the key store to persistent storage
     */
    void sync();

private:
    std::unique_ptr<QSettings> m_settings;
    static const QString KEYS_GROUP;
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_PROVIDERKEYSTORE_H
