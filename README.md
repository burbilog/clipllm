# ClipLLM

Cross-platform LLM clipboard utility - Process your clipboard content with AI prompts using global hotkeys.

## Features

- **System Tray Integration** - Runs in the background with a tray icon
- **Global Hotkey** - Activate processing from any application
- **Text and Images** - Process both text content and images from clipboard
- **Configurable Prompts** - Built-in prompts with support for custom prompts
- **Multiple LLM Providers** - Support for OpenRouter, OpenAI, Anthropic, and custom endpoints
- **Streaming Responses** - Real-time display of AI responses with Markdown rendering
- **History Management** - View, search, and export your request history
- **Priority System** - Set priority for prompts to control menu order
- **Prompt Limits** - Configure maximum number of prompts in menu
- **Prompt Editor** - Full UI for creating and editing custom prompts
- **Multi-language** - Available in English, Russian, German, French, and Spanish
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
git clone https://github.com/rm-isaeff/clipllm.git
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
   - Choose a provider (OpenRouter, OpenAI, Anthropic, or Custom)
   - Enter your API key
   - Select a model
4. Set up your global hotkey
5. Click "OK"

### API Key Setup

ClipLLM supports multiple LLM providers:

- **OpenRouter** (https://openrouter.ai) - Access to multiple models
- **OpenAI** - Direct GPT-4 access
- **Anthropic** - Claude models
- **Custom** - Self-hosted or custom endpoints

## Usage

1. Copy text or an image to your clipboard
2. Press the global hotkey (default: Ctrl+Alt+Shift+X)
3. Select a prompt from the menu
4. View the streaming response in the result window
5. Copy or save the result to history

### Default Prompts

- **Summary** - Generate a structured summary
- **Translate** - Translate to English, Russian, German, French, or Spanish
- **Explain Code** - Get code explanations
- **Code Review** - Review code for issues
- **Refactor** - Suggest code improvements
- **Describe Image** - Get image descriptions
- **Extract Text** - OCR text extraction from images

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
lupdate src/ -ts translations/*.ts

# Edit .ts files with Qt Linguist
linguist translations/*.ts

# Generate .qm files
lrelease translations/*.ts
```

## License

GNU General Public License v3.0 - See LICENSE.md file for details

## Contributing

Contributions are welcome! Please feel free to submit pull requests or open issues.

## Roadmap

- [ ] More built-in prompts
- [ ] Plugin system for custom integrations
- [ ] Voice input support
- [ ] Automatic language detection
- [ ] Batch processing
