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

#ifndef CLIPLLM_CORE_IPCSERVER_H
#define CLIPLLM_CORE_IPCSERVER_H

#include <QObject>
#include <QJsonObject>
#include <memory>

class QLocalServer;
class QLocalSocket;

namespace ClipLLM {
namespace Core {

/**
 * @brief IPC server for communication between CLI instances and the main daemon.
 *
 * Allows CLI commands like --popup and --run to communicate with the running
 * ClipLLM instance via QLocalServer/QLocalSocket.
 *
 * Message format: JSON objects with "cmd" field
 * - {"cmd": "popup"} - show prompt popup menu
 * - {"cmd": "run", "prompt_id": "..."} - execute prompt by ID
 */
class IPCServer : public QObject
{
    Q_OBJECT

public:
    static IPCServer* instance();

    /**
     * @brief Start the IPC server.
     * @return true if server started successfully
     */
    bool start();

    /**
     * @brief Stop the IPC server.
     */
    void stop();

    /**
     * @brief Check if server is running.
     */
    bool isRunning() const;

    /**
     * @brief Get the server name used for IPC.
     */
    static QString serverName();

signals:
    /**
     * @brief Emitted when --popup command is received.
     */
    void popupRequested();

    /**
     * @brief Emitted when --run command is received.
     * @param promptId The prompt ID to execute
     */
    void runRequested(const QString& promptId);

private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();

private:
    IPCServer();
    ~IPCServer();
    Q_DISABLE_COPY(IPCServer)

    void handleMessage(const QJsonObject& message, QLocalSocket* client);

    std::unique_ptr<QLocalServer> m_server;
    static const QString SERVER_NAME;
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_IPCSERVER_H
