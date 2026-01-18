# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

ClipAI is a cross-platform LLM clipboard utility written in C++ using Qt6. It runs as a system tray service and allows users to process clipboard content (text and images) with AI prompts using global hotkeys.

**Key Statistics:** ~6,374 lines of C++17 code, 31 source/header files across 3 modules (core, ui, models).

## Build Commands

### Standard Build
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

### Install (Linux)
```bash
sudo make install
```

### Translation Management
```bash
lupdate src/ -ts translations/*.ts    # Extract translatable strings
linguist translations/*.ts            # Edit translations in Qt Linguist
lrelease translations/*.ts            # Compile .qm files for distribution
```

### Clean Build
```bash
rm -rf build
mkdir build && cd build && cmake .. && make -j$(nproc)
```

## Architecture

### Namespace Structure

The codebase is organized into three namespaces under `ClipAI`:

- **`ClipAI::Core`** - Core business logic (clipboard, LLM client, prompts, config, keychain, history)
- **`ClipAI::Models`** - Data structures (Prompt, LLMConfig, HistoryEntry)
- **`ClipAI::UI`** - User interface components (tray icon, dialogs, menus)

### Application Flow (src/core/app.h)

The `App` class (inherits `QApplication`) is the central controller that:

1. Enforces single-instance application
2. Initializes and manages lifecycle of all core components
3. Coordinates signal/slot communication between components
4. Manages translations/i18n
5. Provides access to UI dialogs (settings, history)

**Managed Components:**
- `ClipboardManager` - Monitors system clipboard for text/images
- `LLMClient` - HTTP client with SSE streaming support
- `PromptManager` - CRUD operations for prompts
- `ConfigManager` - QSettings wrapper for configuration
- `KeychainStore` - Platform keychain for API keys
- `HistoryManager` - Request history and statistics
- `TrayIcon` - System tray integration

### Core Module Details

**ClipboardManager** (src/core/clipboardmanager.h)
- Uses Qt's `QApplication::clipboard()`
- Supports text, HTML, and image content
- Base64-encodes images for vision models

**LLMClient** (src/core/llmclient.h)
- State machine: Idle → Connecting → Streaming → Completed/Error
- Server-Sent Events (SSE) streaming with real-time parsing
- Supports OpenRouter, OpenAI, Anthropic, and custom endpoints
- Provider-specific response parsing required for streaming

**PromptManager** (src/core/promptmanager.h)
- Loads prompts from `~/.config/ClipAI/prompts.json` or bundled defaults
- Template format: `{clipboard}` placeholder in user prompt templates

**ConfigManager** (src/core/configmanager.h)
- Platform-agnostic storage via QSettings:
  - Linux: `~/.config/ClipAI/ClipAI.conf`
  - Windows: Registry `HKEY_CURRENT_USER\Software\ClipAI`
  - macOS: `~/Library/Preferences/com.ClipAI.plist`

**KeychainStore** (src/core/keychainstore.h)
- Platform-specific secure credential storage:
  - Linux: libsecret (GNOME Keyring) / KWallet
  - Windows: Windows Credential Manager
  - macOS: Keychain Services

### Data Models (src/models/)

- **Prompt**: `id`, `name`, `systemPrompt`, `userPromptTemplate`, `contentType` (Text/Image/Any), `model`, `icon`, `temperature`, `maxTokens`, `enabled`, `metadata`
- **LLMConfig**: `provider` (enum), `apiKey`, `model`, `apiUrl`, `temperature`, `maxTokens`, `topP`, `stream`, `proxyUrl`, `timeoutSeconds`
- **HistoryEntry**: `id`, `promptId`, `timestamp`, `contentType`, input/output text, base64 images, token counts, duration, favorite, tags

### UI Components (src/ui/)

- **TrayIcon**: System tray with context menu, dynamic prompt generation
- **SettingsDialog**: 5-tab interface (General, LLM, Hotkeys, Prompts, History)
- **ResultDialog**: Real-time streaming display with progress bar
- **HotkeyEdit**: Custom widget for hotkey capture
- **HistoryDialog**: Searchable history viewer with export

## Configuration Files

- **Default Prompts**: `resources/config/prompts-default.json` (13 built-in prompts)
- **Qt Resources**: `resources/resources.qrc` - bundles prompts and icons into executable
- **Desktop Entry**: `resources/clipai.desktop.in` - Linux application launcher

## Platform-Specific Notes

### Linux
- **Dependencies**: `qt6-base-dev`, `qt6-tools-dev`, `cmake`, `build-essential`
- **X11**: Full functionality including global hotkeys
- **Wayland**: System tray works, global hotkeys have limitations

### Windows
- Built with vcpkg for Qt6 dependencies
- Full functionality supported

### macOS
- Qt6 via Homebrew: `brew install qt@6`
- Full functionality supported

## Adding New Features

### Adding a New LLM Provider
1. Add to `LLMProvider` enum in `models/llmconfig.h`
2. Update `LLMConfig::createDefault()` and `availableModels()`
3. Add provider-specific streaming parsing in `llmclient.cpp`
4. Update Settings dialog provider dropdown

### Adding a New Prompt
1. Edit `~/.config/ClipAI/prompts.json` directly, or
2. Use the Settings → Prompts tab
3. Required fields: `id`, `name`, `system_prompt`, `user_prompt_template`, `content_type`, `enabled`

### Adding a New Language
1. Create `translations/clipai_xx.ts`
2. Run `lupdate src/ -ts translations/clipai_xx.ts`
3. Edit with Qt Linguist
4. Add to `TS_FILES` in CMakeLists.txt
5. Update Settings language dropdown


## Reference implementation

Directory ai-reader/ contains old reference implementation of this program. Read it
only if I reference previous, python incarnation of this program.

## Known Limitations

- **QHotkey Integration**: The `3rdparty/qhotkey/` directory is currently empty; global hotkey support needs implementation
- **No Unit Tests**: No test framework configured yet
- **No CI/CD**: No GitHub Actions or other CI configuration

## Dependencies

- **Qt6**: Core, Widgets, Network, LinguistTools
- **Optional**: Qt6::Concurrent (for async operations)
- **Build**: CMake 3.16+, C++17 compiler
