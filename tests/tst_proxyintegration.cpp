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

// End-to-end proxy integration test.
//
// Requires the docker fixtures in tests/proxy/ (brought up by run.sh). The
// mock LLM is reachable ONLY through the proxies (its port is not published
// to the host), and it echoes the connecting peer's IP back in the streamed
// content. Together this lets us prove a request really traversed a proxy:
//
//   * HTTP proxy -> target uses the host-unresolvable service name. If the
//     proxy were bypassed the host could not resolve it, so a successful
//     response proves traversal.
//   * SOCKS5 proxy -> Qt resolves the destination locally before handing it
//     to the SOCKS server, so we target the mock by IP and instead prove
//     traversal by checking the echoed peer IP equals the socks-proxy.
//   * No proxy + service-name target -> must fail (the host can't resolve
//     the name), which guards against a regression that ignores the proxy
//     setting and connects directly.

#include <QtTest>
#include <QCoreApplication>
#include <QEventLoop>
#include <QTimer>
#include <QString>
#include <QStringList>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QNetworkProxy>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include "core/llmclient.h"
#include "models/llmconfig.h"

using namespace ClipLLM::Core;
using namespace ClipLLM::Models;

namespace {
// Read a required env var; returns empty string if unset.
QString env(const char* key)
{
    return QString::fromLocal8Bit(qgetenv(key));
}
} // namespace

class TestProxyIntegration : public QObject
{
    Q_OBJECT

    QString mockUrlByName;   // http://mock-llm:8080/...  (host-unresolvable)
    QString mockUrlByIp;     // http://<mock-ip>:8080/...
    QString httpProxy;       // http://127.0.0.1:8888
    QString socksProxy;      // socks5://127.0.0.1:1080
    QString socksIp;         // peer IP we expect the socks-proxy to present

private slots:
    void initTestCase();
    void testHttpProxyTraversed();
    void testSocksProxyTraversed();
    void testDirectFailsWithoutProxy();
    // Regression for the model-list ("Refresh") path: it uses its own
    // QNetworkAccessManager, so it must apply the profile proxy itself.
    void testModelsFetchUsesProxy();
};

struct Outcome
{
    bool completed = false;
    bool errored = false;
    QString content;
    QString error;
};

// Drive one sendPrompt() to completion/error/timeout and collect the result.
static Outcome runOnce(LLMClient& client)
{
    Outcome out;
    QEventLoop loop;

    QTimer watchdog;
    watchdog.setSingleShot(true);
    watchdog.setInterval(20000);

    QObject::connect(&client, &LLMClient::completed, &loop,
        [&](const LLMResponse& response) {
            out.completed = true;
            out.content = response.content;
            loop.quit();
        });
    QObject::connect(&client, &LLMClient::error, &loop,
        [&](const QString& message) {
            out.errored = true;
            out.error = message;
            loop.quit();
        });
    QObject::connect(&watchdog, &QTimer::timeout, &loop, &QEventLoop::quit);

    watchdog.start();
    client.sendPrompt(QStringLiteral("You are a test assistant."),
                      QStringLiteral("ping"));
    loop.exec();

    return out;
}

void TestProxyIntegration::initTestCase()
{
    mockUrlByName = env("CLIPLLM_MOCK_URL_BYNAME");
    mockUrlByIp = QStringLiteral("http://%1:8080/v1/chat/completions")
                      .arg(env("CLIPLLM_MOCK_IP"));
    httpProxy = env("CLIPLLM_HTTP_PROXY");
    socksProxy = env("CLIPLLM_SOCKS_PROXY");
    socksIp = env("CLIPLLM_SOCKS_IP");

    // run.sh exports these when docker is available; otherwise skip.
    if (mockUrlByName.isEmpty() || httpProxy.isEmpty()
        || socksProxy.isEmpty() || socksIp.isEmpty()
        || env("CLIPLLM_MOCK_IP").isEmpty()) {
        QSKIP("proxy integration fixtures not available "
              "(docker / run.sh env not set)");
    }
}

void TestProxyIntegration::testHttpProxyTraversed()
{
    LLMClient client;

    LLMConfig config;
    config.setApiUrl(QUrl(mockUrlByName));
    config.setProxyUrl(httpProxy);
    config.setStream(true);
    client.setConfig(config);

    Outcome out = runOnce(client);

    if (!out.completed) {
        QFAIL(qPrintable(QStringLiteral("expected completion via HTTP proxy, "
                                        "got error: %1").arg(out.error)));
    }
    // The mock streams "proxied-ok peer=<ip>"; "proxied" confirms end-to-end
    // SSE parsing. Reaching the host-unresolvable name at all proves the
    // HTTP proxy was used.
    QVERIFY2(out.content.contains(QStringLiteral("proxied")),
             qPrintable(QStringLiteral("unexpected content: %1").arg(out.content)));
}

void TestProxyIntegration::testSocksProxyTraversed()
{
    LLMClient client;

    LLMConfig config;
    config.setApiUrl(QUrl(mockUrlByIp));  // Qt resolves locally -> use IP
    config.setProxyUrl(socksProxy);
    config.setStream(true);
    client.setConfig(config);

    Outcome out = runOnce(client);

    if (!out.completed) {
        QFAIL(qPrintable(QStringLiteral("expected completion via SOCKS5 proxy, "
                                        "got error: %1").arg(out.error)));
    }
    // The mock echoes the connecting peer's IP. Through the socks-proxy that
    // is socksIp; a direct connection would instead show the host's IP, so
    // matching it here proves the request traversed SOCKS5.
    QString expectedPeer = QStringLiteral("peer=") + socksIp;
    QVERIFY2(out.content.contains(expectedPeer),
             qPrintable(QStringLiteral("content %1 does not contain %2 "
                                       "(SOCKS5 bypassed?)")
                            .arg(out.content, expectedPeer)));
}

void TestProxyIntegration::testDirectFailsWithoutProxy()
{
    LLMClient client;

    LLMConfig config;
    config.setApiUrl(QUrl(mockUrlByName));
    config.setProxyUrl(QString());  // no proxy -> must not reach the mock
    config.setStream(true);
    client.setConfig(config);

    Outcome out = runOnce(client);

    // "mock-llm" does not resolve on the host, so without a proxy the
    // request cannot succeed. If it did, the client would be silently
    // bypassing proxy configuration.
    QVERIFY2(out.errored,
             qPrintable(QStringLiteral("expected a connection error without a "
                                       "proxy, but got content: %1")
                            .arg(out.content)));
}

void TestProxyIntegration::testModelsFetchUsesProxy()
{
    // Mirrors what SettingsDialog::fetchModelsFromAPI() and
    // PromptEditorDialog::fetchModelsFromAPI() do: a GET on a separate
    // QNetworkAccessManager with the proxy taken from proxyFromUrl().
    QNetworkAccessManager nam;
    nam.setProxy(LLMClient::proxyFromUrl(httpProxy));

    QUrl modelsUrl(mockUrlByName);
    modelsUrl.setPath(QStringLiteral("/v1/models"));  // mock-llm:8080/v1/models
    QNetworkRequest request(modelsUrl);

    bool ok = false;
    int httpStatus = 0;
    QStringList models;

    QEventLoop loop;
    QTimer watchdog;
    watchdog.setSingleShot(true);
    watchdog.setInterval(15000);

    QObject::connect(&nam, &QNetworkAccessManager::finished, &loop,
        [&](QNetworkReply* reply) {
            httpStatus = reply->attribute(
                QNetworkRequest::HttpStatusCodeAttribute).toInt();
            ok = (reply->error() == QNetworkReply::NoError);
            if (ok) {
                QJsonDocument doc = QJsonDocument::fromJson(reply->readAll());
                const QJsonArray data = doc.object().value(
                    QStringLiteral("data")).toArray();
                for (const QJsonValue& value : data) {
                    models.append(value.toObject().value(
                        QStringLiteral("id")).toString());
                }
            }
            reply->deleteLater();
            loop.quit();
        });
    QObject::connect(&watchdog, &QTimer::timeout, &loop, &QEventLoop::quit);

    watchdog.start();
    nam.get(request);
    loop.exec();

    // Reaching the host-unresolvable mock-llm name at all proves the proxy
    // was applied; parsing the model list proves the whole refresh path.
    QVERIFY2(ok, "models GET via proxy failed");
    QCOMPARE(httpStatus, 200);
    QVERIFY2(models.contains(QStringLiteral("mock-model-1")),
             qPrintable(QStringLiteral("model list not parsed: %1")
                            .arg(models.join(QStringLiteral(", ")))));
}

QTEST_MAIN(TestProxyIntegration)
#include "tst_proxyintegration.moc"
