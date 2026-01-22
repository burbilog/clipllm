#ifndef CLIPAI_MODELS_PROVIDERPROFILE_H
#define CLIPAI_MODELS_PROVIDERPROFILE_H

#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QUrl>
#include <optional>

namespace ClipAI {
namespace Models {

class ProviderProfile
{
public:
    struct ProviderTemplate {
        QString name;           // "OpenRouter", "Ollama", etc.
        QString templateUrl;    // "https://openrouter.ai/api/v1/chat/completions"
        QString defaultModel;   // "openai/gpt-4", "llama3"
        QStringList suggestedModels;
    };

    ProviderProfile() = default;
    explicit ProviderProfile(const QJsonObject& json);

    // Getters
    QString id() const { return m_id; }
    QString name() const { return m_name; }
    QUrl apiUrl() const { return m_apiUrl; }
    QString model() const { return m_model; }
    QString proxyUrl() const { return m_proxyUrl; }

    // Temperature: optional per provider.
    // If std::nullopt -> use global default.
    // If global default also std::nullopt -> use -1 (don't send to API, provider uses its own defaults)
    std::optional<double> temperature() const { return m_temperature; }

    // MaxTokens: optional per provider.
    // If std::nullopt -> use global default.
    // If global default also std::nullopt -> use -1 (don't send to API, provider uses its own defaults)
    std::optional<int> maxTokens() const { return m_maxTokens; }

    bool isDefault() const { return m_isDefault; }
    bool enabled() const { return m_enabled; }

    // Setters
    void setId(const QString& id) { m_id = id; }
    void setName(const QString& name) { m_name = name; }
    void setApiUrl(const QUrl& url) { m_apiUrl = url; }
    void setModel(const QString& model) { m_model = model; }
    void setProxyUrl(const QString& proxy) { m_proxyUrl = proxy; }
    void setTemperature(std::optional<double> temp) { m_temperature = temp; }
    void setMaxTokens(std::optional<int> tokens) { m_maxTokens = tokens; }
    void setIsDefault(bool isDefault) { m_isDefault = isDefault; }
    void setEnabled(bool enabled) { m_enabled = enabled; }

    // Serialization
    QJsonObject toJson() const;
    bool fromJson(const QJsonObject& json);

    // Validation
    bool isValid() const;

    // Provider templates (presets for convenience)
    static QList<ProviderTemplate> availableTemplates();
    static ProviderTemplate templateByName(const QString& name);
    static QStringList availableTemplateNames();

    // Create profile from template
    static ProviderProfile createFromTemplate(const QString& templateName, const QString& suffix = QString());

private:
    QString m_id;
    QString m_name;
    QUrl m_apiUrl;
    QString m_model;
    QString m_proxyUrl;
    std::optional<double> m_temperature;
    std::optional<int> m_maxTokens;
    bool m_isDefault = false;
    bool m_enabled = true;

    // Generate unique ID from name
    static QString generateId(const QString& name, const QString& suffix = QString());
};

} // namespace Models
} // namespace ClipAI

Q_DECLARE_METATYPE(ClipAI::Models::ProviderProfile)

#endif // CLIPAI_MODELS_PROVIDERPROFILE_H
