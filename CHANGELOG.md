# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.5] - 2026-07-09

### Fixed

- **Proxy was not actually used** - The per-profile proxy URL was stored on the config but never reached the `QNetworkAccessManager`, so all LLM requests connected directly and bypassed the configured proxy entirely. The same defect affected the connection test and the model-list ("Refresh") fetch in both the Settings and Prompt Editor dialogs, which use their own network manager.
  - `LLMClient::setConfig()` now applies the proxy from the config (the core fix); `setProxy()` shares the logic via a new `applyProxy()` helper
  - Added a shared `LLMClient::proxyFromUrl()` (static) so the dialog model fetches apply the same proxy as real requests
  - The Settings "Test connection" client now honors the profile's proxy

### Added

- **Proxy test suite**
  - `TestProxy` (unit) - verifies the proxy is applied to the network manager after `setProxy()` / `setConfig()` for `http`, `https`, `socks5`, `socks5h`, authenticated, and empty URLs, including the regression where `setConfig()` stored but never applied the proxy
  - `TestProxyIntegration` (Docker) - drives real requests through tinyproxy (HTTP) and microsocks (SOCKS5) against a mock LLM, proving traversal for LLM requests, SOCKS5 (via echoed peer IP), and the model-list fetch path, and asserting a direct request without a proxy fails; automatically skips when Docker is unavailable

### Changed

- `LLMClient` logging no longer reaches up to `App`; it uses the `DebugLogger` singleton directly, which makes the client unit-testable without pulling in the whole application

## [1.0.4] - 2026-03-02

### Added

- **Japanese Language Support** - Full Japanese UI translation

### Fixed

- **Furigana Rendering** - Fixed ruby (furigana) rendering for documents with many ruby tags
- **Furigana Line Height** - Preserve line height when toggling furigana visibility
- **Ruby Word Wrap** - Prevent ruby overlap on previous line during word wrap
- **Screenshot Selector** - Align screenshot size label background with text baseline

### Changed

- Extracted ruby placeholder replacement into shared function for better maintainability
- Removed native AppImage build (keep only Docker build for GLIBC compatibility)

## [1.0.3] - 2026-02-22

### Fixed

- **AppImage GLIBC Compatibility** - AppImage now builds with GLIBC 2.35 (Ubuntu 22.04) for Debian 12+ compatibility
- **Qt 6.2 API Compatibility** - Replaced `checkStateChanged` with `stateChanged` for Qt 6.2 compatibility
- Fixed file ownership in Docker AppImage builds (files no longer owned by root)

### Added

- **Docker AppImage Build** - New `make linux-appimage-docker` target for building compatible AppImages
- Updated documentation with Qt 6.2 compatibility requirements

## [1.0.2] - 2026-02-22

### Added

- **Furigana Support** - Display furigana (ruby annotations) for Japanese text with configurable size
- **CLI Options** - `--popup`, `--run`, `--list` commands for Wayland support and automation
- **Crash Handler** - Automatic backtrace logging on crashes (Linux)
- **/validate Slash Command** - Code review feedback analysis for AI-assisted development
- **Save As in History** - Save history entries directly from the HistoryDialog

### Changed

- Refactored codebase with unique_ptr for exception safety
- Optimized cleanupByCount from O(n²) to O(n)
- Extracted UiUtils for window geometry management
- Replaced magic numbers with named constants

### Fixed

- Fixed furigana toggle scroll position preservation
- Fixed ruby object clipboard copy (copies kanji only)
- Fixed Custom provider profiles without API key requirement
- Fixed llama.cpp compatibility with connection test streaming
- Fixed various memory management issues with proper RAII patterns
- Completed all unfinished translations for all languages

### Documentation

- Added Wayland setup guide with CLI workaround
- Updated website with screenshot capture feature info

## [1.0.1] - 2026-02-14

### Added

- **Screenshot Hotkeys** - Capture screen regions and process with AI via dedicated hotkey per prompt
- **Prompt Chaining** - Chain prompts together with `nextPromptId` and `autoContinue` for automated workflows
- **Multi-selection in Prompt List** - Select multiple prompts for bulk operations (delete, export, enable/disable)
- **Prompt ID Rename** - Rename prompt IDs with automatic reference updates
- **"Save As..." in Result Dialog** - Save AI responses to new files directly from result window
- **Favicon** - Added favicon to the project website

### Changed

- **Prompt Editor Reorganization** - Reorganized PromptEditorDialog with tabs for better UX
- **Version Management** - Separated build version (CMakeLists.txt) from website version (Makefile)
- **Screenshot Selector** - Simplified hint text, mouse-only controls to avoid key event leakage

### Fixed

- Prevented key events from leaking through screenshot selector overlay

### Documentation

- Updated README.md and CLAUDE.md with new features and model fields
- Added System Requirements and Quick Start sections to website
- Added Privacy & Security section to website

## [1.0.0] - 2025-12-XX

### Added

- Initial release
- System tray integration
- Global hotkey activation
- Text and image clipboard processing
- 17 built-in prompts for common tasks
- Multiple LLM provider support (OpenRouter, OpenAI, DeepSeek, Ollama, NanoGPT, llama.cpp, Custom)
- Streaming responses with Markdown rendering
- History management with search and export
- Prompt editor with full UI
- Prompt groups with hierarchical organization
- Provider profiles with per-profile settings
- Multi-language support (English, Russian, German, French, Spanish)
- Debug logging system
- Linux AppImage and Windows installer distributions
