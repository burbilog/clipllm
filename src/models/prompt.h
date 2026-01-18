#ifndef CLIPAI_MODELS_PROMPT_H
#define CLIPAI_MODELS_PROMPT_H

#include <QString>
#include <QStringList>
#include <QJsonObject>
#include <QJsonArray>
#include <QVariantMap>

namespace ClipAI {
namespace Models {

enum class ContentType {
    Text,
    Image,
    Any
};

enum class PromptIcon {
    TextSummary,
    Translate,
    CodeReview,
    Refactor,
    Explain,
    Custom,
    None
};

class Prompt
{
public:
    Prompt() = default;
    explicit Prompt(const QJsonObject& json);

    // Getters
    QString id() const { return m_id; }
    QString name() const { return m_name; }
    QString description() const { return m_description; }
    QString systemPrompt() const { return m_systemPrompt; }
    QString userPromptTemplate() const { return m_userPromptTemplate; }
    ContentType contentType() const { return m_contentType; }
    QString model() const { return m_model; }
    PromptIcon icon() const { return m_icon; }
    double temperature() const { return m_temperature; }
    int maxTokens() const { return m_maxTokens; }
    bool enabled() const { return m_enabled; }
    QVariantMap metadata() const { return m_metadata; }

    // Setters
    void setId(const QString& id) { m_id = id; }
    void setName(const QString& name) { m_name = name; }
    void setDescription(const QString& description) { m_description = description; }
    void setSystemPrompt(const QString& prompt) { m_systemPrompt = prompt; }
    void setUserPromptTemplate(const QString& template_) { m_userPromptTemplate = template_; }
    void setContentType(ContentType type) { m_contentType = type; }
    void setModel(const QString& model) { m_model = model; }
    void setIcon(PromptIcon icon) { m_icon = icon; }
    void setTemperature(double temp) { m_temperature = temp; }
    void setMaxTokens(int tokens) { m_maxTokens = tokens; }
    void setEnabled(bool enabled) { m_enabled = enabled; }
    void setMetadata(const QVariantMap& metadata) { m_metadata = metadata; }

    // Serialization
    QJsonObject toJson() const;
    bool fromJson(const QJsonObject& json);

    // Utility
    QString formatUserPrompt(const QString& clipboardContent) const;
    QString getIconName() const;
    static ContentType contentTypeFromString(const QString& str);
    static QString contentTypeToString(ContentType type);
    static PromptIcon iconFromString(const QString& str);
    static QString iconToString(PromptIcon icon);

    // Validation
    bool isValid() const;

private:
    QString m_id;
    QString m_name;
    QString m_description;
    QString m_systemPrompt;
    QString m_userPromptTemplate;
    ContentType m_contentType = ContentType::Any;
    QString m_model = QStringLiteral("openai/gpt-4");
    PromptIcon m_icon = PromptIcon::None;
    double m_temperature = 0.7;
    int m_maxTokens = 131072;
    bool m_enabled = true;
    QVariantMap m_metadata;
};

} // namespace Models
} // namespace ClipAI

Q_DECLARE_METATYPE(ClipAI::Models::Prompt)
Q_DECLARE_METATYPE(ClipAI::Models::ContentType)
Q_DECLARE_METATYPE(ClipAI::Models::PromptIcon)

#endif // CLIPAI_MODELS_PROMPT_H
