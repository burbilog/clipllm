# ClipLLM

Cross-platform LLM clipboard utility - Process your clipboard content with AI prompts using global hotkeys.

## Use Cases

- **Language Learning** - Copy Japanese text from a website or manga image, press a hotkey, and get detailed grammar breakdowns with readings, translations, and explanations
- **Translation Workflow** - Quickly translate to 6 built-in languages (English, Russian, German, French, Spanish, Japanese); create custom prompts to translate to/from any language
- **Code Review** - Copy a code snippet and instantly get explanations, reviews, or refactoring suggestions
- **Content Enhancement** - Improve writing clarity, fix grammar, extract keywords, or summarize lengthy documents
- **Image Analysis** - Extract text from screenshots, describe images, or analyze visual content with OCR
- **Information Extraction** - Copy emails, articles, or documents and extract key facts, dates, and structured data

## Features

- **System Tray Integration** - Runs in the background with a tray icon
- **Global Hotkey** - Activate processing from any application
- **Text and Images** - Process both text content and images from clipboard
- **Configurable Prompts** - Built-in prompts with support for custom prompts
- **Multiple LLM Providers** - Support for OpenAI-compatible APIs with 7 pre-configured templates: OpenRouter, OpenAI, DeepSeek, Ollama, NanoGPT, llama.cpp, and custom endpoints
- **Streaming Responses** - Real-time display of AI responses with Markdown rendering
- **History Management** - View, search, and export your request history
- **Priority System** - Set priority for prompts to control menu order
- **Prompt Limits** - Configure maximum number of prompts in menu
- **Prompt Editor** - Full UI for creating and editing custom prompts
- **Multi-language** - Available in English, Russian, German, French, and Spanish
- **Prompt Groups** - Organize prompts into hierarchical groups
- **Provider Profiles** - Pre-configured templates with per-profile settings and cascade fallback
- **Prompt Hotkeys** - Assign individual global hotkeys to specific prompts
- **Screenshot Hotkeys** - Capture screen regions and process with AI via hotkey
- **Searchable Menu** - Quick prompt search with inline keyboard navigation
- **Debug Logging** - Built-in debug logging with file output and multiple levels
- **History Favorites** - Mark important requests as favorites in history
- **Advanced Options** - Proxy support, timeout, top-p, stream toggle
- **Cross-platform** - Works on Linux (X11/Wayland), Windows, and macOS

## Building

### Prerequisites

- Qt6 (Core, Widgets, Network)
- CMake 3.16+
- C++17 compatible compiler

### Linux

```bash
# Install dependencies (Ubuntu/Debian)
sudo apt-get install qt6-base-dev qt6-tools-dev cmake build-essential

# Build
mkdir build && cd build
cmake ..
make -j$(nproc)

# Install (optional)
sudo make install
```

### Windows (Cross-compiled from Linux)

**Prerequisites:** MXE (M Cross Environment) for cross-compilation

```bash
# Install MXE system dependencies (Ubuntu/Debian)
sudo apt-get install \
    git cmake make autoconf libtool pkg-config bison flex gperf \
    unzip p7zip curl wget bash patch perl python3 ruby ruby-json \
    intltool gettext gtk-doc-tools libtool-bin xsltproc ccache \
    g++ g++-multilib libc6-dev-i386

# Clone and build MXE with Qt6 (~1-2 hours)
git clone https://github.com/mxe/mxe.git ~/mxe
cd ~/mxe
make -j$(nproc) MXE_TARGETS='x86_64-w64-mingw32.shared' qt6

# Optional: Install NSIS for creating Windows installers
sudo apt install nsis
```

**Building ClipLLM for Windows:**

```bash
# Clone ClipLLM (if not already done)
git clone https://github.com/burbilog/clipllm.git
cd clipllm

# Build for Windows (shared - default)
make windows

# Deploy with DLLs and Qt plugins
make windows-deploy

# Create ZIP archive (portable, works on all Windows versions)
make windows-zip

# Create NSIS installer (recommended for Windows)
make windows-installer

# Test with Wine
make test-windows-wine
```

**Distribution Options:**

1. **ZIP Archive** (`make windows-zip`):
   - Portable, no installation required
   - Works on all Windows versions
   - Recommended for most users

2. **NSIS Installer** (`make windows-installer`):
   - Native Windows installer
   - Creates shortcuts, registry entries
   - Clean uninstall
   - Requires: `sudo apt install nsis`

**Build Types:**
- `shared` (default) - Dynamic linking, requires DLLs, smaller executable, works with installer
- `static` - Static linking, standalone executable, larger file

```bash
# Build static version
make windows MXE_BUILD_TYPE=static
```

**Output:**
- `build-windows/ClipLLM.exe` - Compiled executable
- `deploy-windows/` - Deployed package with DLLs (shared build)
- `dist/clipllm-*-windows-x86_64.zip` - Portable ZIP archive
- `dist/ClipLLM-*-windows-x86_64-setup.exe` - NSIS installer

### macOS

```bash
# Install Qt6 via Homebrew
brew install qt@6 cmake

# Build
mkdir build && cd build
cmake .. -DCMAKE_PREFIX_PATH=$(brew --prefix qt@6)
make -j$(sysctl -n hw.ncpu)
```

## Configuration

### First Run

1. Launch ClipLLM
2. Click on the tray icon and select "Settings"
3. Configure your LLM provider:
   - Choose a provider template (OpenRouter, OpenAI, DeepSeek, Ollama, NanoGPT, llama.cpp, or Custom)
   - Enter your API key (required for most providers; local providers like Ollama/llama.cpp may not need one)
   - For **Custom** provider: specify the API URL (must be an OpenAI-compatible endpoint)
   - Select a model
4. Set up your global hotkey
5. Click "OK"

### LLM Provider Configuration

ClipLLM supports OpenAI-compatible APIs with pre-configured templates for:

| Provider | API URL | Notes |
|----------|---------|-------|
| **OpenRouter** | `https://openrouter.ai/api/v1/chat/completions` | Requires API key; access to multiple models |
| **OpenAI** | `https://api.openai.com/v1/chat/completions` | Requires API key; direct GPT-4 access |
| **DeepSeek** | `https://api.deepseek.com/chat/completions` | Requires API key |
| **Ollama** | `http://localhost:11434/v1/chat/completions` | Local only; API key optional |
| **NanoGPT** | `https://nano-gpt.com/api/v1/chat/completions` | Requires API key |
| **llama.cpp** | `http://localhost:8080/v1/chat/completions` | Local only; API key optional |
| **Custom** | *User-specified* | Any OpenAI-compatible endpoint; **API URL required** |

**Custom Provider Setup:**
1. Select "Custom" from the provider template dropdown
2. Enter the full API URL (e.g., `https://your-provider.com/v1/chat/completions`)
3. Enter your API key if required by the provider
4. Select or enter the model name

## Usage

1. Copy text or an image to your clipboard
2. Press the global hotkey (default: Ctrl+Alt+Shift+X)
3. Select a prompt from the menu
4. View the streaming response in the result window
5. Copy or save the result to history

### Default Prompts

Built-in prompts (17 total):
- **Summary** - Generate a structured summary
- **Translate** - Translate to English, Russian, German, French, Spanish, or Japanese (6 prompts)
- **Japanese Grammar** - Explain Japanese grammar from text or image
- **Explain Code** - Get code explanations
- **Code Review** - Review code for issues
- **Refactor Code** - Suggest code improvements
- **Describe Image** - Get image descriptions
- **Extract Text (OCR)** - OCR text extraction from images
- **Fix Grammar** - Correct grammar and spelling
- **Improve Writing** - Enhance clarity and readability
- **Extract Information** - Extract key facts and data
- **Extract Keywords** - Extract keywords and tags

## Platform Notes

### Linux (X11)
Full functionality including global hotkeys.

### Linux (Wayland)
- System tray works in most compositors
- Global hotkeys have limitations - consider using desktop-specific shortcuts
- Use the tray icon menu for prompt selection

### Windows
Full functionality supported.

### macOS
Full functionality supported.

## Project Structure

```
clipllm/
├── src/
│   ├── core/           # Core application logic
│   ├── ui/             # User interface components
│   └── models/         # Data models
├── resources/          # Icons, configuration, Qt resources
├── translations/       # i18n translation files
├── cmake/              # CMake toolchain files (Windows cross-compilation)
├── scripts/            # Build and deployment scripts
├── installer/          # NSIS installer configuration
├── tests/              # Unit tests
└── CMakeLists.txt      # Build configuration
```

## Development

### Adding Custom Prompts

You can create and edit prompts in several ways:

1. **Settings Dialog** - Use the Prompts tab with full prompt editor UI
2. **Direct File Edit** - Edit `~/.config/ClipLLM/prompts.json` directly
3. **Import/Export** - Share prompts via JSON export/import

Prompt format:
```json
{
  "id": "my-prompt",
  "name": "My Prompt",
  "description": "Does something useful",
  "icon": "custom",
  "system_prompt": "You are a helpful assistant.",
  "user_prompt_template": "Process this: {clipboard}",
  "content_type": "text",
  "model": "openai/gpt-4",
  "enabled": true,
  "priority": 0
}
```

### Translation

To add or update translations:

```bash
# Update translation files from source
make translations
# or
lupdate src/ -ts translations/*.ts

# Edit .ts files with Qt Linguist
linguist translations/*.ts

# Generate .qm files
lrelease translations/*.ts
```

### Makefile Targets

Additional build commands:

```bash
make cloc            # Count lines of code (excludes build dirs)
make regen-icons     # Regenerate tray icons from source art
make web             # Generate landing page from template
```

### Debug Logging

ClipLLM includes a debug logging system that writes to `debug.log` in the configuration directory:
- Linux: `~/.config/ClipLLM/debug.log`
- Windows: Configuration directory + `debug.log`
- macOS: `~/Library/Preferences/com.ClipLLM/debug.log`

Enable via Settings → General tab → Debug group. Three levels available:
- **Normal** - Basic debug messages (errors, warnings, lifecycle)
- **Trace** - Full LLM request/response logging

## License

Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <https://www.gnu.org/licenses/>.

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

**Project Repository:** https://github.com/burbilog/clipllm

