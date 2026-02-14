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
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#include "ipcserver.h"
#include "debuglogger.h"
#include <QLocalServer>
#include <QLocalSocket>
#include <QJsonDocument>
#include <QCoreApplication>
#include <QTimer>

namespace ClipLLM {
namespace Core {

const QString IPCServer::SERVER_NAME = QStringLiteral("clipllm-ipc");

IPCServer* IPCServer::instance()
{
    static IPCServer instance;
    return &instance;
}

IPCServer::IPCServer()
    : m_server(std::make_unique<QLocalServer>())
{
    connect(m_server.get(), &QLocalServer::newConnection,
            this, &IPCServer::onNewConnection);
}

IPCServer::~IPCServer()
{
    stop();
}

bool IPCServer::start()
{
    if (m_server->isListening()) {
        return true;
    }

    // Remove any stale socket file from previous crash
    QString serverName = IPCServer::serverName();
    QLocalServer::removeServer(serverName);

    if (!m_server->listen(serverName)) {
        LOG_WARNING(QStringLiteral("Failed to start IPC server: %1").arg(m_server->errorString()));
        return false;
    }

    LOG_DEBUG(QStringLiteral("IPC server started on %1").arg(serverName));
    return true;
}

void IPCServer::stop()
{
    if (m_server) {
        m_server->close();
        LOG_DEBUG(QStringLiteral("IPC server stopped"));
    }
}

bool IPCServer::isRunning() const
{
    return m_server && m_server->isListening();
}

QString IPCServer::serverName()
{
    // Use fixed server name to allow CLI clients to connect
    // User-specific isolation is provided by the OS for local sockets
    return SERVER_NAME;
}

void IPCServer::onNewConnection()
{
    QLocalSocket* client = m_server->nextPendingConnection();
    if (!client) {
        return;
    }

    LOG_DEBUG(QStringLiteral("IPC client connected"));

    connect(client, &QLocalSocket::readyRead, this, [this, client]() {
        onReadyRead();
    });
    connect(client, &QLocalSocket::disconnected, this, [this, client]() {
        onClientDisconnected();
    });
    connect(client, &QLocalSocket::disconnected, client, &QLocalSocket::deleteLater);
}

void IPCServer::onReadyRead()
{
    QLocalSocket* client = qobject_cast<QLocalSocket*>(sender());
    if (!client) {
        return;
    }

    QByteArray data = client->readAll();
    LOG_DEBUG(QStringLiteral("IPC received: %1").arg(QString::fromUtf8(data)));

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(data, &error);

    if (error.error != QJsonParseError::NoError) {
        LOG_WARNING(QStringLiteral("IPC parse error: %1").arg(error.errorString()));
        return;
    }

    if (!doc.isObject()) {
        LOG_WARNING(QStringLiteral("IPC message is not a JSON object"));
        return;
    }

    handleMessage(doc.object(), client);
}

void IPCServer::onClientDisconnected()
{
    LOG_DEBUG(QStringLiteral("IPC client disconnected"));
}

void IPCServer::handleMessage(const QJsonObject& message, QLocalSocket* client)
{
    QString cmd = message.value(QStringLiteral("cmd")).toString();

    if (cmd.isEmpty()) {
        LOG_WARNING(QStringLiteral("IPC message missing 'cmd' field"));
        return;
    }

    LOG_DEBUG(QStringLiteral("IPC command: %1").arg(cmd));

    if (cmd == QStringLiteral("popup")) {
        // Send acknowledgment first
        client->write("{\"status\":\"ok\"}");
        client->flush();
        client->waitForBytesWritten(1000);

        // Emit signal asynchronously to avoid blocking IPC handler
        // (showMenu uses exec() which blocks)
        QTimer::singleShot(0, this, [this]() {
            emit popupRequested();
        });
    }
    else if (cmd == QStringLiteral("run")) {
        QString promptId = message.value(QStringLiteral("prompt_id")).toString();
        if (promptId.isEmpty()) {
            LOG_WARNING(QStringLiteral("IPC run command missing prompt_id"));
            client->write("{\"status\":\"error\",\"message\":\"missing prompt_id\"}");
            client->flush();
            return;
        }

        // Send acknowledgment first
        client->write("{\"status\":\"ok\"}");
        client->flush();
        client->waitForBytesWritten(1000);

        // Emit signal asynchronously
        QTimer::singleShot(0, this, [this, promptId]() {
            emit runRequested(promptId);
        });
    }
    else {
        LOG_WARNING(QStringLiteral("Unknown IPC command: %1").arg(cmd));
        client->write(QStringLiteral("{\"status\":\"error\",\"message\":\"unknown command: %1\"}").arg(cmd).toUtf8());
        client->flush();
    }
}

} // namespace Core
} // namespace ClipLLM
