#!/usr/bin/env bash
#
# Orchestrates the proxy integration test:
#   1. build + start mock-llm, an HTTP proxy (tinyproxy) and a SOCKS5 proxy
#      (microsocks) in an isolated docker network
#   2. hand the live addresses to the TestProxyIntegration binary
#   3. tear everything down
#
# Designed to be wired into ctest via add_test(). It exits 77 (ctest's
# SKIP_RETURN_CODE) when docker is unavailable, so a CI box without docker
# reports the test as skipped rather than failed.
set -eu

TEST_BIN="${1:-}"
if [ -z "$TEST_BIN" ]; then
  echo "usage: $0 <path-to-TestProxyIntegration>" >&2
  exit 2
fi

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

skip() { echo "SKIP TestProxyIntegration: $1"; exit 77; }

command -v docker >/dev/null 2>&1 || skip "docker not installed"
docker info >/dev/null 2>&1 || skip "docker daemon unavailable"

cd "$SCRIPT_DIR"

cleanup() {
  docker compose down --remove-orphans --volumes >/dev/null 2>&1 || true
}
trap cleanup EXIT

echo "[proxy-integration] building and starting fixtures..."
docker compose up -d --build >/dev/null

# Container IPs on the shared bridge network. The host can route to these,
# which matters for the SOCKS test: Qt's SOCKS5 resolves the destination
# locally, so we point it at the mock's IP rather than its (host-unresolvable)
# service name.
container_ip() {
  docker inspect -f '{{range .NetworkSettings.Networks}}{{.IPAddress}}{{end}}' "$1"
}
MOCK_IP=$(container_ip "$(docker compose ps -q mock-llm)")
SOCKS_IP=$(container_ip "$(docker compose ps -q socks-proxy)")

# Wait until the HTTP proxy can actually forward to the mock (proves all
# three containers are up and wired together). Fall back to a fixed sleep
# when curl is absent.
ready=0
if command -v curl >/dev/null 2>&1; then
  for _ in $(seq 1 60); do
    if curl -sf -m 5 -x http://127.0.0.1:8888 http://mock-llm:8080/ >/dev/null 2>&1; then
      ready=1; break
    fi
    sleep 0.5
  done
else
  sleep 4
  ready=1
fi
[ "$ready" = "1" ] || { echo "FAIL: fixtures did not become ready"; exit 1; }

export CLIPLLM_MOCK_URL_BYNAME="http://mock-llm:8080/v1/chat/completions"
export CLIPLLM_MOCK_IP="$MOCK_IP"
export CLIPLLM_SOCKS_IP="$SOCKS_IP"
export CLIPLLM_HTTP_PROXY="http://127.0.0.1:8888"
export CLIPLLM_SOCKS_PROXY="socks5://127.0.0.1:1080"

echo "[proxy-integration] mock=$MOCK_IP socks-proxy=$SOCKS_IP"
echo "[proxy-integration] running TestProxyIntegration..."
# Run the binary directly (NOT via exec): exec would replace this shell and
# the EXIT trap that tears the fixtures down would never fire.
set +e
"$TEST_BIN"
rc=$?
set -e
exit $rc
