# Flatpak Infrastructure for ClipLLM

## Goal
Create `flatpak/` subdirectory with complete Flatpak build infrastructure and set up a private Flatpak repository on GitHub before attempting Flathub submission.

## Strategy: Hybrid Approach

**Why start with own repository first?**
1. **No approval risk** - full control, no "tray applet" policy concerns
2. **Immediate availability** - users can install right away
3. **Testing ground** - validate Flatpak packaging in production
4. **Plan B** - fallback if Flathub submission fails

**Two-phase approach:**
- **Phase 1:** Own GitHub-hosted Flatpak repository
- **Phase 2:** Flathub submission (optional, after Phase 1 is proven)

---

# Phase 1: Own Flatpak Repository

## 1. Create Flatpak Build Infrastructure

### Critical Files to Create

### 1.1 `flatpak/io.github.burbilog.Clipllm.yaml` - Main Flatpak Manifest

**App ID:** `io.github.burbilog.Clipllm` (follows Flathub conventions for future compatibility)

**CRITICAL FIXES NEEDED:**
- **command**: `ClipLLM` (not `clipllm` - CMake installs to `/app/bin/ClipLLM`)
- **Desktop file**: Must be generated from `.in` template or taken from build output
- **License file**: `LICENSE.md` (not `LICENSE` - this is the actual filename in repo)
- **finish-args**: Remove unnecessary permissions (see below)
- **StatusNotifierWatcher**: Add D-Bus access for tray icon

**Permissions justification:**
- `--socket=x11` - Required for global hotkeys via QHotkey (X11)
- `--socket=wayland` - Wayland support
- `--share=network` - Required for LLM API calls (OpenRouter, OpenAI, DeepSeek, etc.)
- `--device=dri` - Required for Qt rendering acceleration
- `--talk-name=org.kde.StatusNotifierWatcher` - Required for StatusNotifier tray icon (KDE)
- `--talk-name=org.freedesktop.StatusNotifierWatcher` - Required for StatusNotifier tray icon (GNOME/others)
- **REMOVE `--talk-name=org.freedesktop.secrets`** - No libsecret integration (API keys use QSettings/XOR)
- **REMOVE `--talk-name=org.freedesktop.Notifications`** - Not currently used
- **REMOVE `--own-name=io.github.burbilog.Clipllm`** - No D-Bus service registered by app

**Manifest structure (for local dev - uses `path: ..`):**
```yaml
app-id: io.github.burbilog.Clipllm
runtime: org.kde.Platform
runtime-version: '6.6'
sdk: org.kde.Sdk
command: ClipLLM
finish-args:
  - --share=ipc
  - --socket=x11
  - --socket=wayland
  - --share=network
  - --device=dri
  - --talk-name=org.kde.StatusNotifierWatcher
  - --talk-name=org.freedesktop.StatusNotifierWatcher

modules:
  - name: clipllm
    buildsystem: cmake-ninja
    config-opts:
      - -DCMAKE_BUILD_TYPE=Release
    sources:
      - type: dir
        path: ..
    post-install:
      - install -Dm644 build/clipllm.desktop /app/share/applications/io.github.burbilog.Clipllm.desktop
      - sed -i 's/^Exec=clipllm$/Exec=ClipLLM/' /app/share/applications/io.github.burbilog.Clipllm.desktop
      - sed -i 's/^Icon=clipllm$/Icon=io.github.burbilog.Clipllm/' /app/share/applications/io.github.burbilog.Clipllm.desktop
      - install -Dm644 ../resources/icons/app-icon.svg /app/share/icons/hicolor/scalable/apps/io.github.burbilog.Clipllm.svg
      - install -Dm644 flatpak/icons/64x64/io.github.burbilog.Clipllm.png /app/share/icons/hicolor/64x64/apps/io.github.burbilog.Clipllm.png
      - install -Dm644 flatpak/icons/128x128/io.github.burbilog.Clipllm.png /app/share/icons/hicolor/128x128/apps/io.github.burbilog.Clipllm.png
      - install -Dm644 flatpak/io.github.burbilog.Clipllm.metainfo.xml /app/share/metainfo/io.github.burbilog.Clipllm.metainfo.xml
      - install -Dm644 ../LICENSE.md /app/share/licenses/io.github.burbilog.Clipllm/LICENSE.md
```

### 1.2 `flatpak/io.github.burbilog.Clipllm.metainfo.xml` - AppStream Metadata

**Required for Flatpak/flathub.** Must include:

- Application ID matching manifest
- Name, summary
- Full description
- Screenshots (at least one)
- Categories (Utility, Qt, etc.)
- Releases section
- Developer info
- Project URLs
- Content rating (OARS-1.1)
- `metadata_license` (CC0-1.0)
- `project_license` (GPL-3.0-or-later)
- `<icon type="stock">` reference

**Example:**
```xml
<?xml version="1.0" encoding="UTF-8"?>
<component type="desktop-application">
  <id>io.github.burbilog.Clipllm</id>
  <name>ClipLLM</name>
  <summary>AI clipboard utility with global hotkeys</summary>
  <metadata_license>CC0-1.0</metadata_license>
  <project_license>GPL-3.0-or-later</project_license>
  <developer_name>Roman V. Isaev</developer_name>
  <url type="homepage">https://github.com/burbilog/clipllm</url>
  <url type="bugtracker">https://github.com/burbilog/clipllm/issues</url>
  <categories>
    <category>Utility</category>
    <category>Qt</category>
  </categories>
  <icon type="stock">io.github.burbilog.Clipllm</icon>
  <description>
    <p>ClipLLM is a cross-platform system tray utility that lets you instantly process
    text and images from your clipboard using AI.</p>
  </description>
  <screenshots>
    <screenshot type="default">
      <image>https://raw.githubusercontent.com/burbilog/clipllm/1.0.0/docs/screenshots/settings.png</image>
    </screenshot>
  </screenshots>
  <releases>
    <release version="1.0.0" date="2025-01-26"/>
  </releases>
  <content_rating type="oars-1.1"/>
  <launchable type="desktop-id">io.github.burbilog.Clipllm.desktop</launchable>
</component>
```

### 1.3 `flatpak/io.github.burbilog.Clipllm.appdata.xml` - Symlink

Symlink to metainfo.xml for compatibility.

### 1.4 `flatpak/icons/` - AppStream Icons

PNG icons in multiple sizes (64x64, 128x128 minimum).

Generate from:
- `art/clipllm_hires.png` (high-res source)
- OR `resources/icons/app-icon.svg`

### 1.5 `flatpak/io.github.burbilog.Clipllm.flatpakrepo` - Repository Definition

**NEW file for own repository:**

```ini
[Flatpak Repo]
Title=ClipLLM Flatpak Repository
Url=https://burbilog.github.io/clipllm/flatpak
Homepage=https://github.com/burbilog/clipllm
Comment=Official Flatpak repository for ClipLLM
Description=ClipLLM is a cross-platform AI clipboard utility
Icon=https://burbilog.github.io/clipllm/flatpak/repo-icon.png
GPGKey=<BASE64_ENCODED_GPG_KEY>
```

**Note:** GPG key is required for signing Flatpak bundles. Users will see a warning if repository is not signed.

### 1.6 `flatpak/Makefile` - Build Helper

Convenience targets:
```makefile
FLATPAK_ID := io.github.burbilog.Clipllm
BUILD_DIR := build-flatpak
REPO_DIR := flatpak/repo

build:
	flatpak-builder --user --force-clean $(BUILD_DIR) $(FLATPAK_ID).yaml

install: build
	flatpak-builder --user --install --force-clean $(BUILD_DIR) $(FLATPAK_ID).yaml

run:
	flatpak run $(FLATPAK_ID)

bundle:
	flatpak build-bundle ~/.local/share/flatpak/app/$(FLATPAK_ID) $(FLATPAK_ID).flatpak $(FLATPAK_ID)

export: build
	flatpak build-export $(REPO_DIR) $(BUILD_DIR)

icons:
	# Generate icons from art/clipllm_hires.png
	convert ../art/clipllm_hires.png -resize 64x64 icons/64x64/$(FLATPAK_ID).png
	convert ../art/clipllm_hires.png -resize 128x128 icons/128x128/$(FLATPAK_ID).png
	cp ../resources/icons/app-icon.svg icons/scalable/$(FLATPAK_ID).svg

lint:
	appstream-util validate-relax $(FLATPAK_ID).metainfo.xml
	flatpak-builder --lint $(FLATPAK_ID).yaml

clean:
	rm -rf $(BUILD_DIR) $(REPO_DIR)
```

### 1.7 `flatpak/README.md` - Documentation

Usage instructions for building and installing.

## 2. Create GitHub Pages Repository Hosting

### 2.1 Enable GitHub Pages

In main repo `burbilog/clipllm`:
1. Go to Settings → Pages
2. Source: Deploy from branch → `gh-pages` branch
3. (Or use `/docs` folder from main branch)

### 2.2 Create `gh-pages` Branch Structure

```
gh-pages/
├── index.html                    # Redirect to main repo
└── flatpak/
    ├── io.github.burbilog.Clipllm.flatpakrepo  # Repository config
    ├── repo/                     # Flatpak repository (generated)
    │   ├── io.github.burbilog.Clipllm.flatpakref
    │   ├── io.github.burbilog.Clipllm.flatpak
    │   ├── icons/
    │   └── metadata
    └── repo-icon.png             # Repository icon
```

### 2.3 Repository URL

Once published, the repository will be available at:
```
https://burbilog.github.io/clipllm/flatpak/io.github.burbilog.Clipllm.flatpakrepo
```

### 2.4 Alternative: Separate Repository

Create `burbilog/clipllm-flatpak` repository with:
- GitHub Pages enabled
- Host `.flatpakrepo` file and built Flatpak repository
- Auto-publish via GitHub Actions

**Decision needed:** Use gh-pages branch in main repo or separate repo?

**Pros of gh-pages in main repo:**
- Simpler, one repo
- Everything in one place

**Pros of separate repo:**
- Cleaner separation of concerns
- Can set up automated builds via Actions
- Easier to manage releases

**Recommendation:** Start with gh-pages branch in main repo for simplicity.

## 3. GPG Key Setup (Optional but Recommended)

### 3.1 Generate GPG Key

```bash
gpg --full-generate-key
# Select: RSA and RSA
# Size: 4096
# Valid: 1y (or longer)
# Name: ClipLLM Flatpak Repository
# Email: your@email.com
```

### 3.2 Export Public Key

```bash
gpg --export --armor your@email.com > flatpak/repo-key.pub
```

### 3.3 Add to .flatpakrepo

```bash
# Encode GPG key in base64 for flatpakrepo file
base64 -w 0 flatpak/repo-key.pub
```

Add to `flatpakrepo`:
```ini
GPGKey=<BASE64_OUTPUT>
```

### 3.4 Configure flatpak-builder to Sign

When exporting repository:
```bash
flatpak build-export --gpg-sign=YOUR_KEY_ID --gpg-homedir=/path/to/gpg flatpak/repo build-flatpak
```

## 4. Automated Build Workflow (Optional)

### 4.1 GitHub Actions: Build on Release

Create `.github/workflows/flatpak.yml`:

```yaml
name: Flatpak Build

on:
  release:
    types: [published]

jobs:
  flatpak:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v3

      - name: Install dependencies
        run: |
          sudo apt-get update
          sudo apt-get install -y flatpak flatpak-builder

      - name: Install KDE runtime
        run: |
          flatpak remote-add --if-not-exists flathub https://flathub.org/repo/flathub.flatpakrepo
          flatpak install flathub org.kde.Platform//6.6
          flatpak install flathub org.kde.Sdk//6.6

      - name: Build Flatpak
        run: |
          cd flatpak
          make icons
          make build
          make export

      - name: Deploy to gh-pages
        uses: peaceiris/actions-gh-pages@v3
        with:
          github_token: ${{ secrets.GITHUB_TOKEN }}
          publish_dir: ./flatpak/repo
          destination_dir: flatpak
```

### 4.2 Manual Build Workflow

For manual control:
1. Build locally: `make -f flatpak/Makefile bundle`
2. Upload `.flatpak` file to GitHub Release
3. Update `.flatpakrepo` to point to release asset

## 5. User Installation Instructions

### From Own Repository

```bash
# Add repository
flatpak remote-add --if-not-exists clipllm https://burbilog.github.io/clipllm/flatpak/io.github.burbilog.Clipllm.flatpakrepo

# Install
flatpak install clipllm io.github.burbilog.Clipllm

# Run
flatpak run io.github.burbilog.Clipllm
```

### From Bundle File

```bash
# Download .flatpak from GitHub Releases
flatpak install clipllm.flatpak
```

## 6. Required Code Changes

### 6.1 Fix first_run Key Mismatch

**Problem:** ConfigManager defines `FIRST_RUN_KEY = "first_run"` but App::initialize() reads `"firstRun"`.

**Fix:** Standardize to snake_case in `src/core/app.cpp`:
```cpp
// Change:
config->setValue("firstRun", false);
// To:
config->setValue(ConfigManager::FIRST_RUN_KEY, false);
```

### 6.2 Startup Behavior: Show GUI by Default

**Current:** Shows only tray notification on first run.

**Solution:** Show Settings dialog by default (unless `--minimized` flag or setting enabled).

**Implementation:**

1. Add setting in ConfigManager:
```cpp
bool startMinimizedToTray() const;
void setStartMinimizedToTray(bool enabled);
```

2. Add checkbox in Settings dialog (General tab)

3. Modify startup logic in App:
```cpp
bool showGui = !minimized && !configManager->startMinimizedToTray();
if (showGui) {
    settingsDialog->show();
}
```

**Files to modify:**
- `src/core/configmanager.h/.cpp`
- `src/ui/settingsdialog.h/.cpp`
- `src/core/app.cpp`
- `resources/clipllm.desktop.in`

## 7. File Structure

```
flatpak/
├── io.github.burbilog.Clipllm.yaml          # Main manifest
├── io.github.burbilog.Clipllm.metainfo.xml  # AppStream metadata
├── io.github.burbilog.Clipllm.appdata.xml   # Symlink to metainfo.xml
├── io.github.burbilog.Clipllm.flatpakrepo   # Repository definition
├── Makefile                                  # Build helpers
├── README.md                                 # Documentation
└── icons/                                    # Generated (not in git)
    ├── 64x64/io.github.burbilog.Clipllm.png
    ├── 128x128/io.github.burbilog.Clipllm.png
    └── scalable/io.github.burbilog.Clipllm.svg

docs/screenshots/                             # Hosted in main repo
├── settings.png
├── result.png
└── history.png
```

---

# Phase 2: Flathub Submission (Optional)

After Phase 1 is complete and working, consider submitting to Flathub.

## Flathub Submission Risks

**Potential Rejection Risk:** Flathub states that "tray applets, system utilities" may not be accepted.

**However,** many tray applications exist on Flathub. The distinction:
- **Rejected:** Pure tray applets with minimal/no GUI
- **Accepted:** Applications with tray icon AND substantial desktop UI

**ClipLLM position:** Has full GUI dialogs (Settings, Result, History, PromptEditor).

## Submission Process

1. **Create Flathub PR** via https://github.com/flathub/flathub/pull/new

2. **Flathub-specific manifest changes:**
   - Change `sources: type: dir, path: ..` → `type: archive, url: ..., sha256: ...`
   - Add `x-checker-data` for automatic version updates
   - Ensure all finish-args have explanatory comments

3. **Requirements:**
   - Complete AppStream metadata with screenshots
   - Stable source URL (GitHub release tarball)
   - Pre-computed SHA256 hash
   - All permissions justified

## If Flathub Submission Fails

You already have:
- Working Flatpak package
- Hosted repository with full control
- Users can install immediately
- No dependency on Flathub approval

---

# Verification Steps

## Phase 1 Verification

1. **Code fixes:**
   - [ ] Fix first_run key mismatch
   - [ ] Add "Start minimized to tray" setting
   - [ ] Modify startup logic to show GUI by default

2. **Flatpak files:**
   - [ ] Create `flatpak/*.yaml` manifest
   - [ ] Create `flatpak/*.metainfo.xml`
   - [ ] Create `flatpak/*.flatpakrepo`
   - [ ] Generate icons

3. **Local build:**
   ```bash
   make -f flatpak/Makefile icons
   make -f flatpak/Makefile build
   make -f flatpak/Makefile install
   flatpak run io.github.burbilog.Clipllm
   ```

4. **Validation:**
   ```bash
   make -f flatpak/Makefile lint
   ```

5. **Bundle creation:**
   ```bash
   make -f flatpak/Makefile bundle
   ```

6. **Repository setup:**
   - [ ] Enable GitHub Pages
   - [ ] Create gh-pages branch structure
   - [ ] Upload `.flatpakrepo` file
   - [ ] Test repository installation

7. **Test user workflow:**
   ```bash
   flatpak remote-add --if-not-exists clipllm https://burbilog.github.io/clipllm/flatpak/io.github.burbilog.Clipllm.flatpakrepo
   flatpak install clipllm io.github.burbilog.Clipllm
   flatpak run io.github.burbilog.Clipllm
   ```

## Phase 2 Verification (Flathub)

- [ ] Screenshots hosted on GitHub
- [ ] Manifest uses stable source (not `path: ..`)
- [ ] Description emphasizes desktop GUI
- [ ] AppStream metadata validates
- [ ] Desktop file validates
- [ ] All Flathub checklist items completed

---

# Summary of Changes from Original Plan

| Aspect | Old Plan | New Plan |
|--------|----------|----------|
| **Primary target** | Flathub | Own repository first |
| **Secondary target** | None | Flathub (optional) |
| **Approval risk** | High (blocks release) | None |
| **Time to publish** | Weeks (review process) | Days (immediate) |
| **Control** | Limited | Full |
| **Complexity** | Lower (single target) | Higher (two phases) |
| **Fallback** | None | Built-in |

---

# Open Questions

1. **Separate repo or gh-pages branch?**
   - Recommendation: Start with gh-pages branch for simplicity
   - Can migrate to separate repo later if needed

2. **GPG signing?**
   - Optional for testing
   - Recommended for production (users see warning without it)

3. **Automated builds?**
   - Manual for MVP
   - GitHub Actions for automation (optional)

4. **Flathub submission?**
   - Only after Phase 1 is proven
   - Not required for distribution
