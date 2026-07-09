#!/usr/bin/env python3
"""Minimal OpenAI-compatible mock for proxy integration tests.

Listens on 0.0.0.0:8080. Replies to POST with an SSE chat-completion
stream (the format ClipLLM's LLMClient parses). The streamed content echoes
the connecting peer's IP, so a test can confirm the request arrived *and*
tell which hop connected. GET is a health-check.

The host must NOT be able to reach this directly: in docker-compose its port
is not published, so the only way in is through one of the proxies. That is
the whole point -- if a request succeeds, it traversed a proxy.
"""

import json
import sys
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer


class Handler(BaseHTTPRequestHandler):
    protocol_version = "HTTP/1.1"

    def _send_sse(self):
        peer = self.client_address[0]
        # Pieces of the assistant message. processStreamingChunk accumulates
        # delta.content, so splitting across chunks also exercises buffering.
        pieces = ["proxied", "-", "ok", " peer=" + peer]
        body = bytearray()
        for piece in pieces:
            payload = {"choices": [{"index": 0, "delta": {"content": piece}}]}
            body += b"data: " + json.dumps(payload).encode() + b"\n\n"
        # Final chunk carries usage + finish_reason, then the terminator.
        final = {
            "choices": [{"index": 0, "delta": {}, "finish_reason": "stop"}],
            "usage": {"prompt_tokens": 4, "completion_tokens": 4, "total_tokens": 8},
            "model": "mock",
        }
        body += b"data: " + json.dumps(final).encode() + b"\n\n"
        body += b"data: [DONE]\n\n"

        out = bytes(body)
        self.send_response(200)
        self.send_header("Content-Type", "text/event-stream")
        self.send_header("Cache-Control", "no-cache")
        self.send_header("Connection", "close")
        self.send_header("Content-Length", str(len(out)))
        self.end_headers()
        self.wfile.write(out)

    def do_POST(self):
        length = int(self.headers.get("Content-Length", "0") or "0")
        if length:
            self.rfile.read(length)
        self._send_sse()

    def do_GET(self):
        # /models -> an OpenAI-style model list (the shape the settings and
        # prompt-editor dialogs parse). Anything else -> a health-check blob.
        if self.path.endswith("/models"):
            payload = json.dumps({
                "data": [
                    {"id": "mock-model-1"},
                    {"id": "mock-model-2"},
                ]
            }).encode()
            content_type = "application/json"
        else:
            payload = b"ok"
            content_type = "text/plain"

        self.send_response(200)
        self.send_header("Content-Type", content_type)
        self.send_header("Content-Length", str(len(payload)))
        self.end_headers()
        self.wfile.write(payload)

    def log_message(self, *args):
        # Keep test output clean; uncomment for debugging.
        # sys.stderr.write("[mock] %s\n" % (args[0] % args[1:],))
        pass


if __name__ == "__main__":
    addr = ("0.0.0.0", 8080)
    ThreadingHTTPServer(addr, Handler).serve_forever()
