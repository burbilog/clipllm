#ifndef CLIPAI_CORE_PROVIDERKEYSTORE_H
#define CLIPAI_CORE_PROVIDERKEYSTORE_H

#include <QString>
#include <QSettings>
#include <memory>

namespace ClipAI {
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
} // namespace ClipAI

#endif // CLIPAI_CORE_PROVIDERKEYSTORE_H
