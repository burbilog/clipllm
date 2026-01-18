#include "keychainstore.h"
#include <QSettings>
#include <QStandardPaths>
#include <QDir>
#include <QDebug>

// Check if QtKeychain is available
// #ifdef HAVE_QTKEYCHAIN
// #include <keychain.h>
// #endif

namespace ClipAI {
namespace Core {

KeychainStore::KeychainStore(QObject* parent)
    : QObject(parent)
    , m_serviceName(QStringLiteral("ClipAI"))
{
}

KeychainStore::~KeychainStore() = default;

QString KeychainStore::getServiceName() const
{
    return m_serviceName;
}

QString KeychainStore::getKeyName(const QString& provider) const
{
    if (provider.isEmpty()) {
        return QStringLiteral("api_key");
    }
    return QStringLiteral("api_key_%1").arg(provider);
}

bool KeychainStore::writeApiKey(const QString& apiKey)
{
    return writeProviderKey(QStringLiteral("default"), apiKey);
}

QString KeychainStore::readApiKey() const
{
    return readProviderKey(QStringLiteral("default"));
}

bool KeychainStore::removeApiKey()
{
    return removeProviderKey(QStringLiteral("default"));
}

bool KeychainStore::hasApiKey() const
{
    return !readApiKey().isEmpty();
}

bool KeychainStore::writeProviderKey(const QString& provider, const QString& apiKey)
{
    // For now, use QSettings with obfuscation as a fallback
    // TODO: Integrate QtKeychain for proper secure storage

    QString keyName = getKeyName(provider);

    // Simple XOR obfuscation (not cryptographically secure, but better than plaintext)
    QByteArray data = apiKey.toUtf8();
    QByteArray obfuscated;
    quint8 xorKey = 0x5A; // Simple XOR key

    for (int i = 0; i < data.size(); ++i) {
        obfuscated.append(static_cast<char>(data[i] ^ xorKey));
    }

    // Store in QSettings
    QSettings settings(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + QStringLiteral("/keys.ini"),
        QSettings::IniFormat
    );

    settings.setValue(keyName, QString::fromLatin1(obfuscated.toBase64()));
    settings.sync();

    return settings.status() == QSettings::NoError;
}

QString KeychainStore::readProviderKey(const QString& provider) const
{
    QString keyName = getKeyName(provider);

    QSettings settings(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + QStringLiteral("/keys.ini"),
        QSettings::IniFormat
    );

    if (!settings.contains(keyName)) {
        return QString();
    }

    QString encoded = settings.value(keyName).toString();
    QByteArray obfuscated = QByteArray::fromBase64(encoded.toLatin1());

    // De-obfuscate
    QByteArray data;
    quint8 xorKey = 0x5A;

    for (int i = 0; i < obfuscated.size(); ++i) {
        data.append(static_cast<char>(obfuscated[i] ^ xorKey));
    }

    return QString::fromUtf8(data);
}

bool KeychainStore::removeProviderKey(const QString& provider)
{
    QString keyName = getKeyName(provider);

    QSettings settings(
        QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation) + QStringLiteral("/keys.ini"),
        QSettings::IniFormat
    );

    settings.remove(keyName);
    settings.sync();

    return true;
}

} // namespace Core
} // namespace ClipAI
