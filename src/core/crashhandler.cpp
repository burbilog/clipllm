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

#include "crashhandler.h"

#ifdef __linux__
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <execinfo.h>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#endif

namespace ClipLLM {
namespace Core {

// Static member definition
char CrashHandler::s_logPath[MAX_PATH_LEN] = {0};

#ifdef __linux__

const char* CrashHandler::signalName(int sig)
{
    switch (sig) {
    case SIGSEGV: return "SIGSEGV";
    case SIGABRT: return "SIGABRT";
    case SIGFPE:  return "SIGFPE";
    case SIGBUS:  return "SIGBUS";
    default:      return "UNKNOWN";
    }
}

void CrashHandler::initLogPath()
{
    // Use separate crash.log file (not debug.log which is for DebugLogger)
    // We can't use Qt here, so build the path manually
    const char* home = getenv("HOME");
    if (home) {
        // Check XDG_CONFIG_HOME first
        const char* xdgConfig = getenv("XDG_CONFIG_HOME");
        if (xdgConfig) {
            snprintf(s_logPath, MAX_PATH_LEN, "%s/ClipLLM/crash.log", xdgConfig);
        } else {
            snprintf(s_logPath, MAX_PATH_LEN, "%s/.config/ClipLLM/crash.log", home);
        }
    } else {
        // Fallback to /tmp
        strncpy(s_logPath, "/tmp/clipllm-crash.log", MAX_PATH_LEN - 1);
    }
}

void CrashHandler::writeCrashLog(int sig, void* faultAddress)
{
    // Open log file for append (use open/write for async-signal-safety)
    int fd = open(s_logPath, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0) {
        // Fallback to stderr
        fd = 2;
    }

    // Buffer for building output lines
    char buf[1024];
    int len;

    // Write crash header
    const char* header = "\n========== CRASH DETECTED ==========\n";
    write(fd, header, strlen(header));

    // Write signal info
    len = snprintf(buf, sizeof(buf), "Signal: %s (%d)\n", signalName(sig), sig);
    write(fd, buf, len);

    // Write fault address
    len = snprintf(buf, sizeof(buf), "Fault address: %p\n", faultAddress);
    write(fd, buf, len);

    // Get backtrace
    void* buffer[64];
    int size = backtrace(buffer, 64);

    // Write backtrace header
    const char* btHeader = "Backtrace:\n";
    write(fd, btHeader, strlen(btHeader));

    // Get human-readable symbols
    char** symbols = backtrace_symbols(buffer, size);
    if (symbols) {
        for (int i = 0; i < size; i++) {
            len = snprintf(buf, sizeof(buf), "#%d %s\n", i, symbols[i]);
            write(fd, buf, len);
        }
        // Note: we can't safely free() in signal handler context
        // The symbols array will be cleaned up when process terminates
    } else {
        // Fallback: write raw addresses
        for (int i = 0; i < size; i++) {
            len = snprintf(buf, sizeof(buf), "#%d [%p]\n", i, buffer[i]);
            write(fd, buf, len);
        }
    }

    // Write footer
    const char* footer = "=====================================\n\n";
    write(fd, footer, strlen(footer));

    // Sync to disk
    fsync(fd);

    if (fd != 2) {
        close(fd);
    }
}

void CrashHandler::signalHandler(int sig, void* infoPtr, void* /*context*/)
{
    // Write crash log (async-signal-safe)
    siginfo_t* info = static_cast<siginfo_t*>(infoPtr);
    writeCrashLog(sig, info->si_addr);

    // Restore default handler and re-raise to get proper exit code
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = SIG_DFL;
    sa.sa_flags = 0;
    sigaction(sig, &sa, nullptr);

    raise(sig);
}

void CrashHandler::install()
{
    // Initialize log path before any crash can occur
    initLogPath();

    // Set up signal handlers with SA_SIGINFO for detailed info
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);

    // Block all signals during handler execution
    sigfillset(&sa.sa_mask);

    sa.sa_sigaction = reinterpret_cast<void (*)(int, siginfo_t*, void*)>(signalHandler);
    sa.sa_flags = SA_SIGINFO | SA_RESETHAND;

    // Install handlers for crash signals
    sigaction(SIGSEGV, &sa, nullptr);  // Segmentation fault
    sigaction(SIGABRT, &sa, nullptr);  // Abort
    sigaction(SIGFPE, &sa, nullptr);   // Floating point exception
    sigaction(SIGBUS, &sa, nullptr);   // Bus error
}

#else // Non-Linux platforms

void CrashHandler::install()
{
    // No-op on non-Linux platforms
}

#endif // __linux__

} // namespace Core
} // namespace ClipLLM
