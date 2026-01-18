#ifndef CLIPAI_CORE_KEYCHAINSTORE_H
#define CLIPAI_CORE_KEYCHAINSTORE_H

#include <QObject>
#include <QString>

namespace ClipAI {
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
} // namespace ClipAI

#endif // CLIPAI_CORE_KEYCHAINSTORE_H
