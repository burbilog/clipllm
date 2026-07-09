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

// Unit tests for proxy handling in LLMClient.
//
// These verify that a configured proxy URL is actually applied to the
// underlying QNetworkAccessManager (i.e. requests will traverse it). No
// network and no Docker are involved: we only inspect the QNetworkProxy
// object that ends up on the manager after setProxy()/setConfig().

#include <QtTest>
#include <QNetworkProxy>
#include "core/llmclient.h"
#include "models/llmconfig.h"

using namespace ClipLLM::Core;
using namespace ClipLLM::Models;

class TestProxy : public QObject
{
    Q_OBJECT

private slots:
    // --- setProxy(): proxy type and address parsing ---

    void testHttpProxy();
    void testHttpsProxy();
    void testSocks5Proxy();
    void testSocks5hProxy();
    void testProxyWithAuth();
    void testDefaultPort();
    void testEmptyProxyClears();
    void testConfigStringPreserved();

    // --- setConfig(): this is the regression that motivated the tests.
    //     Previously setConfig() stored the proxy URL but never applied it
    //     to the network manager, so requests bypassed the proxy. ---
    void testSetConfigAppliesHttpProxy();
    void testSetConfigAppliesSocks5Proxy();
    void testSetConfigEmptyProxyIsNoProxy();
    void testSetProxyOverridesPreviousConfig();
    void testEmptyConfigAfterProxyClearsIt();
};

void TestProxy::testHttpProxy()
{
    LLMClient client;
    client.setProxy(QStringLiteral("http://127.0.0.1:8888"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::HttpProxy);
    QCOMPARE(p.hostName(), QStringLiteral("127.0.0.1"));
    QCOMPARE(p.port(), 8888);
    QVERIFY(p.user().isEmpty());
}

void TestProxy::testHttpsProxy()
{
    LLMClient client;
    client.setProxy(QStringLiteral("https://proxy.example.com:3128"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::HttpProxy);
    QCOMPARE(p.hostName(), QStringLiteral("proxy.example.com"));
    QCOMPARE(p.port(), 3128);
}

void TestProxy::testSocks5Proxy()
{
    LLMClient client;
    client.setProxy(QStringLiteral("socks5://10.0.0.5:1080"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::Socks5Proxy);
    QCOMPARE(p.hostName(), QStringLiteral("10.0.0.5"));
    QCOMPARE(p.port(), 1080);
}

void TestProxy::testSocks5hProxy()
{
    LLMClient client;
    client.setProxy(QStringLiteral("socks5h://10.0.0.5:1080"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::Socks5Proxy);
    QCOMPARE(p.hostName(), QStringLiteral("10.0.0.5"));
    QCOMPARE(p.port(), 1080);
}

void TestProxy::testProxyWithAuth()
{
    LLMClient client;
    client.setProxy(QStringLiteral("http://alice:secret@127.0.0.1:8888"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::HttpProxy);
    QCOMPARE(p.hostName(), QStringLiteral("127.0.0.1"));
    QCOMPARE(p.port(), 8888);
    QCOMPARE(p.user(), QStringLiteral("alice"));
    QCOMPARE(p.password(), QStringLiteral("secret"));
}

void TestProxy::testDefaultPort()
{
    LLMClient client;
    // No explicit port -> code falls back to 8080.
    client.setProxy(QStringLiteral("http://127.0.0.1"));

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::HttpProxy);
    QCOMPARE(p.hostName(), QStringLiteral("127.0.0.1"));
    QCOMPARE(p.port(), 8080);
}

void TestProxy::testEmptyProxyClears()
{
    LLMClient client;
    client.setProxy(QStringLiteral("http://127.0.0.1:8888"));
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::HttpProxy);

    // Empty string must clear the proxy (NoProxy), not leave the old one.
    client.setProxy(QString());
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::NoProxy);
}

void TestProxy::testConfigStringPreserved()
{
    LLMClient client;
    client.setProxy(QStringLiteral("http://127.0.0.1:8888"));
    // The configured URL string is queryable through proxy().
    QCOMPARE(client.proxy(), QStringLiteral("http://127.0.0.1:8888"));
}

void TestProxy::testSetConfigAppliesHttpProxy()
{
    LLMClient client;

    LLMConfig config;
    config.setProxyUrl(QStringLiteral("http://127.0.0.1:8888"));

    client.setConfig(config);

    // Regression: setConfig() must apply the proxy, not just store it.
    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::HttpProxy);
    QCOMPARE(p.hostName(), QStringLiteral("127.0.0.1"));
    QCOMPARE(p.port(), 8888);
    QCOMPARE(client.proxy(), QStringLiteral("http://127.0.0.1:8888"));
}

void TestProxy::testSetConfigAppliesSocks5Proxy()
{
    LLMClient client;

    LLMConfig config;
    config.setProxyUrl(QStringLiteral("socks5://10.0.0.5:1080"));

    client.setConfig(config);

    QNetworkProxy p = client.networkProxy();
    QCOMPARE(p.type(), QNetworkProxy::Socks5Proxy);
    QCOMPARE(p.hostName(), QStringLiteral("10.0.0.5"));
    QCOMPARE(p.port(), 1080);
}

void TestProxy::testSetConfigEmptyProxyIsNoProxy()
{
    LLMClient client;

    LLMConfig config;  // default: empty proxyUrl
    client.setConfig(config);

    QCOMPARE(client.networkProxy().type(), QNetworkProxy::NoProxy);
}

void TestProxy::testSetProxyOverridesPreviousConfig()
{
    LLMClient client;

    LLMConfig config;
    config.setProxyUrl(QStringLiteral("http://127.0.0.1:8888"));
    client.setConfig(config);
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::HttpProxy);

    // Switching to SOCKS5 via setProxy must replace the applied proxy.
    client.setProxy(QStringLiteral("socks5://10.0.0.5:1080"));
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::Socks5Proxy);
    QCOMPARE(client.networkProxy().port(), 1080);
}

void TestProxy::testEmptyConfigAfterProxyClearsIt()
{
    LLMClient client;
    client.setProxy(QStringLiteral("socks5://10.0.0.5:1080"));
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::Socks5Proxy);

    // Loading a config without a proxy must clear the previously applied one.
    LLMConfig empty;
    client.setConfig(empty);
    QCOMPARE(client.networkProxy().type(), QNetworkProxy::NoProxy);
}

QTEST_GUILESS_MAIN(TestProxy)
#include "tst_proxy.moc"
