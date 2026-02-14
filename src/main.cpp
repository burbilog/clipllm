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
// along with this program. If not, see <https://www.gnu.org/licenses/>.

#include "core/app.h"
#include "core/ipcserver.h"
#include <QCoreApplication>
#include <QCommandLineParser>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>
#include <QLocalSocket>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QTimer>

/**
 * @brief List available prompts from file (for --list option).
 * Works without requiring a running ClipLLM instance.
 */
static int listPrompts()
{
    // Try user's prompts file first (appends organization name automatically)
    QString configPath = QStandardPaths::writableLocation(QStandardPaths::AppConfigLocation);
    QString promptsPath = configPath + QStringLiteral("/prompts.json");

    QFile file(promptsPath);
    if (!file.exists()) {
        // Fallback: try ConfigLocation + /ClipLLM/prompts.json
        promptsPath = QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)
                      + QStringLiteral("/ClipLLM/prompts.json");
        file.setFileName(promptsPath);
    }
    if (!file.exists()) {
        // Try default prompts from resources
        promptsPath = QStringLiteral(":/config/prompts-default.json");
        file.setFileName(promptsPath);
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qCritical() << qPrintable(QObject::tr("Cannot open prompts file: %1").arg(promptsPath));
        return 1;
    }

    QByteArray data = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);

    if (error.error != QJsonParseError::NoError) {
        qCritical() << qPrintable(QObject::tr("Invalid JSON in prompts file: %1").arg(error.errorString()));
        return 1;
    }

    // File can be either an array or object with "prompts" array
    QJsonArray prompts;
    if (doc.isArray()) {
        prompts = doc.array();
    } else if (doc.isObject()) {
        prompts = doc.object().value(QStringLiteral("prompts")).toArray();
    }

    if (prompts.isEmpty()) {
        qCritical() << qPrintable(QObject::tr("No prompts found"));
        return 1;
    }

    // Output format: "id\tname"
    for (const QJsonValue& val : prompts) {
        QJsonObject obj = val.toObject();
        QString id = obj.value(QStringLiteral("id")).toString();
        QString name = obj.value(QStringLiteral("name")).toString();
        if (!id.isEmpty()) {
            qDebug("%s\t%s", qPrintable(id), qPrintable(name));
        }
    }

    return 0;
}

/**
 * @brief Send IPC command to running instance.
 * @return 0 on success, 1 on failure
 */
static int sendIpcCommand(const QString& cmd, const QString& promptId = QString())
{
    QJsonObject message;
    message[QStringLiteral("cmd")] = cmd;

    if (!promptId.isEmpty()) {
        message[QStringLiteral("prompt_id")] = promptId;
    }

    QLocalSocket socket;
    socket.connectToServer(ClipLLM::Core::IPCServer::serverName());

    if (!socket.waitForConnected(2000)) {
        qCritical() << qPrintable(QObject::tr("Cannot connect to ClipLLM. Is it running?"));
        return 1;
    }

    // Send message
    QByteArray data = QJsonDocument(message).toJson(QJsonDocument::Compact);
    socket.write(data);
    socket.flush();

    // Wait for acknowledgment
    if (!socket.waitForReadyRead(2000)) {
        qCritical() << qPrintable(QObject::tr("No response from ClipLLM"));
        return 1;
    }

    QByteArray response = socket.readAll();
    QJsonDocument responseDoc = QJsonDocument::fromJson(response);
    QJsonObject responseObj = responseDoc.object();

    if (responseObj.value(QStringLiteral("status")).toString() == QStringLiteral("ok")) {
        return 0;
    } else {
        QString errorMsg = responseObj.value(QStringLiteral("message")).toString();
        if (!errorMsg.isEmpty()) {
            qCritical() << qPrintable(QObject::tr("Error: %1").arg(errorMsg));
        }
        return 1;
    }
}

int main(int argc, char *argv[])
{
    // High DPI scaling is enabled by default in Qt6

    ClipLLM::App app(argc, argv);

    // Setup command line parser
    QCommandLineParser parser;
    parser.setApplicationDescription(QObject::tr("ClipLLM - Cross-platform LLM clipboard utility"));
    parser.addHelpOption();
    parser.addVersionOption();

    // Optional: Start minimized option
    QCommandLineOption minimizedOption(QStringList() << "m" << "minimized",
                                       QObject::tr("Start minimized to system tray"));
    parser.addOption(minimizedOption);

    // IPC options for CLI control
    QCommandLineOption popupOption(QStringList() << "popup",
                                   QObject::tr("Show prompt popup menu (requires running instance)"));
    parser.addOption(popupOption);

    QCommandLineOption runOption(QStringList() << "run",
                                 QObject::tr("Execute prompt by ID with clipboard content (requires running instance)"),
                                 QObject::tr("prompt-id"));
    parser.addOption(runOption);

    QCommandLineOption listOption(QStringList() << "list",
                                  QObject::tr("List available prompts with their IDs"));
    parser.addOption(listOption);

    parser.process(app);

    // --list works independently (doesn't require running instance)
    if (parser.isSet(listOption)) {
        return listPrompts();
    }

    // Check if another instance is running
    if (app.isSecondary()) {
        // Try to send IPC commands if requested
        if (parser.isSet(popupOption)) {
            return sendIpcCommand(QStringLiteral("popup"));
        }

        if (parser.isSet(runOption)) {
            QString promptId = parser.value(runOption);
            if (promptId.isEmpty()) {
                qCritical() << qPrintable(QObject::tr("--run requires a prompt ID"));
                return 1;
            }
            return sendIpcCommand(QStringLiteral("run"), promptId);
        }

        // No IPC command specified, just inform and exit
        qDebug() << qPrintable(QObject::tr("Another instance of ClipLLM is already running"));
        return 0;
    }

    // Initialize application components
    if (!app.initialize(parser.isSet(minimizedOption))) {
        qCritical() << qPrintable(QObject::tr("Failed to initialize application"));
        return 1;
    }

    // Start IPC server for CLI commands
    if (!app.startIpcServer()) {
        qWarning() << qPrintable(QObject::tr("Failed to start IPC server - CLI commands will not work"));
        // Continue anyway, the app can still work via tray
    }

    return app.exec();
}
