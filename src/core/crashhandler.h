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

#ifndef CLIPLLM_CORE_CRASHHANDLER_H
#define CLIPLLM_CORE_CRASHHANDLER_H

namespace ClipLLM {
namespace Core {

/**
 * @brief Crash handler for capturing backtraces on segmentation faults.
 *
 * Installs signal handlers for SIGSEGV, SIGABRT, SIGFPE, and SIGBUS.
 * When a crash occurs, writes a backtrace to the debug log file.
 *
 * Currently implemented for Linux only.
 */
class CrashHandler
{
public:
    /**
     * @brief Install crash signal handlers.
     *
     * Should be called as early as possible in main(), before any
     * other initialization that could crash.
     *
     * On non-Linux platforms, this is a no-op.
     */
    static void install();

private:
    // Signal handler function (uses void* to avoid platform-specific types in header)
    static void signalHandler(int sig, void* info, void* context);

    // Write crash information to log file (async-signal-safe)
    static void writeCrashLog(int sig, void* faultAddress);

    // Get signal name as string (async-signal-safe)
    static const char* signalName(int sig);

    // Get path to log file (must be called before any crash)
    static void initLogPath();

    // Buffer for log file path (set at install time)
    static constexpr int MAX_PATH_LEN = 512;
    static char s_logPath[MAX_PATH_LEN];
};

} // namespace Core
} // namespace ClipLLM

#endif // CLIPLLM_CORE_CRASHHANDLER_H
