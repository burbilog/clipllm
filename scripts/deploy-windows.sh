#!/usr/bin/env bash
# ClipAI - Cross-platform LLM clipboard utility
# Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
#
# Windows deployment script for ClipAI
# This script deploys the Windows build with all required Qt DLLs and plugins

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Configuration
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
BUILD_DIR="${PROJECT_ROOT}/build-windows"
DEPLOY_DIR="${PROJECT_ROOT}/deploy-windows"
MXE_PATH="${HOME}/mxe"

# Default to static build (can be overridden with MXE_BUILD_TYPE=shared)
MXE_BUILD_TYPE="${MXE_BUILD_TYPE:-static}"

if [ "$MXE_BUILD_TYPE" = "shared" ]; then
    MXE_TARGET="${MXE_PATH}/usr/x86_64-w64-mingw32.shared"
    BUILD_DESC="Shared (dynamic linking)"
else
    MXE_TARGET="${MXE_PATH}/usr/x86_64-w64-mingw32.static"
    BUILD_DESC="Static (static linking - no DLLs needed)"
fi

# Print configuration
echo "=========================================="
echo "ClipAI Windows Deployment Script"
echo "=========================================="
echo "Build type:      ${BUILD_DESC}"
echo "Build directory: ${BUILD_DIR}"
echo "Deploy directory: ${DEPLOY_DIR}"
echo "MXE target:      ${MXE_TARGET}"
echo ""

# Check if build directory exists
if [ ! -d "${BUILD_DIR}" ]; then
    echo -e "${RED}Error: Build directory ${BUILD_DIR} does not exist${NC}"
    echo "Please run 'make windows' first to build the project"
    exit 1
fi

# Check if executable exists
if [ ! -f "${BUILD_DIR}/ClipAI.exe" ]; then
    echo -e "${RED}Error: ClipAI.exe not found in ${BUILD_DIR}${NC}"
    echo "Please run 'make windows' first to build the project"
    exit 1
fi

# Create deployment directory
echo "Creating deployment directory..."
rm -rf "${DEPLOY_DIR}"
mkdir -p "${DEPLOY_DIR}"
mkdir -p "${DEPLOY_DIR}/translations"

# Copy executable
echo "Copying ClipAI.exe..."
cp "${BUILD_DIR}/ClipAI.exe" "${DEPLOY_DIR}/"

# Copy translations
echo "Copying translations..."
cp "${BUILD_DIR}/translations"/*.qm "${DEPLOY_DIR}/translations/" 2>/dev/null || true

# For static builds, no DLLs or plugins needed
if [ "$MXE_BUILD_TYPE" = "static" ]; then
    echo -e "${GREEN}Static build detected - skipping DLL deployment${NC}"
    echo "All dependencies are linked into the executable."
else
    # Shared build - need DLLs and plugins
    mkdir -p "${DEPLOY_DIR}/platforms"
    mkdir -p "${DEPLOY_DIR}/styles"
    mkdir -p "${DEPLOY_DIR}/iconengines"
    mkdir -p "${DEPLOY_DIR}/imageformats"
    mkdir -p "${DEPLOY_DIR}/tls"

    # Copy required Qt DLLs
    echo "Copying Qt DLLs..."
    DLLS=(
        "libgcc_s_seh-1.dll"
        "libstdc++-6.dll"
        "libwinpthread-1.dll"
        "Qt6Core.dll"
        "Qt6Gui.dll"
        "Qt6Widgets.dll"
        "Qt6Network.dll"
        "libcrypto-*.dll"
        "libssl-*.dll"
        "zlib1.dll"
    )

    for dll in "${DLLS[@]}"; do
        # Handle wildcards
        for file in ${MXE_TARGET}/bin/${dll}; do
            if [ -f "$file" ]; then
                echo "  Copying $(basename "$file")"
                cp "$file" "${DEPLOY_DIR}/"
            fi
        done
    done

    # Copy Qt plugins
    echo "Copying Qt plugins..."

    # Platform plugin (required for Windows)
    cp "${MXE_TARGET}/qt6/plugins/platforms/qwindows.dll" "${DEPLOY_DIR}/platforms/"

    # Image formats (for PNG, ICO support)
    for plugin in qico.dll qpng.dll qjpeg.dll qsvg.dll; do
        if [ -f "${MXE_TARGET}/qt6/plugins/imageformats/${plugin}" ]; then
            cp "${MXE_TARGET}/qt6/plugins/imageformats/${plugin}" "${DEPLOY_DIR}/imageformats/"
        fi
    done

    # TLS/SSL plugins (for HTTPS connections)
    for plugin in qopensslbackend.dll qcertonlybackend.dll qsecuretransportbackend.dll; do
        if [ -f "${MXE_TARGET}/qt6/plugins/tls/${plugin}" ]; then
            cp "${MXE_TARGET}/qt6/plugins/tls/${plugin}" "${DEPLOY_DIR}/tls/"
        fi
    done

    # Create qt.conf to specify plugin paths
    echo "Creating qt.conf..."
    cat > "${DEPLOY_DIR}/qt.conf" << 'EOF'
[Paths]
Translations=translations
Plugins=plugins
EOF
fi

# Copy default prompts configuration
echo "Copying default prompts configuration..."
mkdir -p "${DEPLOY_DIR}/config"
cp "${PROJECT_ROOT}/resources/config/prompts-default.json" "${DEPLOY_DIR}/config/" 2>/dev/null || true

# Print summary
echo ""
echo "=========================================="
echo -e "${GREEN}Deployment complete!${NC}"
echo "=========================================="
echo "Deployment directory: ${DEPLOY_DIR}"
echo ""
echo "Contents:"
ls -lh "${DEPLOY_DIR}"
echo ""

if [ "$MXE_BUILD_TYPE" = "shared" ]; then
    echo "Subdirectories:"
    for dir in translations platforms imageformats tls; do
        if [ -d "${DEPLOY_DIR}/${dir}" ] && [ "$(ls -A ${DEPLOY_DIR}/${dir})" ]; then
            echo "  ${dir}/:"
            ls -lh "${DEPLOY_DIR}/${dir}" | tail -n +2 | awk '{print "    " $9 " (" $5 ")"}'
        fi
    done
    echo ""
fi

echo -e "${YELLOW}To test with Wine, run:${NC}"
echo "  wine ${DEPLOY_DIR}/ClipAI.exe"
echo ""
echo -e "${YELLOW}To create a portable ZIP archive:${NC}"
echo "  cd ${DEPLOY_DIR}"
echo "  zip -r ../clipai-windows-x86_64-$(git describe --tags --always 2>/dev/null || echo 'dev').zip ."
echo ""
