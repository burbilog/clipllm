#!/usr/bin/env bash
# ClipLLM - Cross-platform LLM clipboard utility
# Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
#
# Windows deployment script for ClipLLM
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
echo "ClipLLM Windows Deployment Script"
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
if [ ! -f "${BUILD_DIR}/ClipLLM.exe" ]; then
    echo -e "${RED}Error: ClipLLM.exe not found in ${BUILD_DIR}${NC}"
    echo "Please run 'make windows' first to build the project"
    exit 1
fi

# Create deployment directory
echo "Creating deployment directory..."
rm -rf "${DEPLOY_DIR}"
mkdir -p "${DEPLOY_DIR}"
mkdir -p "${DEPLOY_DIR}/translations"

# Copy executable
echo "Copying ClipLLM.exe..."
cp "${BUILD_DIR}/ClipLLM.exe" "${DEPLOY_DIR}/"

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

    # Use objdump to find exact DLL dependencies, then copy them
    echo "Finding DLL dependencies..."
    MXE_OBJDUMP="${MXE_PATH}/usr/bin/x86_64-w64-mingw32.shared-objdump"

    # Get list of all DLL dependencies from the executable
    DEPS=$($MXE_OBJDUMP -p "${BUILD_DIR}/ClipLLM.exe" 2>/dev/null | \
        grep "DLL Name:" | \
        awk '{print tolower($3)}' | \
        sed 's/\.dll$//' | \
        sort -u)

    echo "  Found dependencies: $(echo $DEPS | tr '\n' ' ')"

    # Function to convert lowercase dependency name to DLL filename
    # qt6core -> Qt6Core.dll, libgcc_s_seh-1 -> libgcc_s_seh-1.dll
    dep_to_dll() {
        local dep="$1"
        local lower="$1"

        # If it starts with "qt6", convert to Qt6*.dll format (qt6core -> Qt6Core.dll)
        if [[ "$lower" == qt6* ]]; then
            local rest="${lower#qt6}"
            rest="$(echo "${rest:0:1}" | tr '[:lower:]' '[:upper:]')${rest:1}"
            echo "Qt6${rest}.dll"
        # If it starts with "lib", keep as lib*.dll
        elif [[ "$lower" == lib* ]]; then
            echo "${lower}.dll"
        else
            echo "${lower}.dll"
        fi
    }

    # Copy each dependency DLL
    echo "Copying dependency DLLs..."
    for dep in $DEPS; do
        # Skip Windows system DLLs
        if [[ "$dep" =~ ^(kernel32|user32|gdi32|shell32|ole32|oleaut32|uuid|comdlg32|advapi32|winmm|ws2_32|shlwapi|version|wininet|crypt32|secur32|iphlpapi|netapi32|userenv|d3d9|ddraw|glu32|opengl32|msvcrt|imm32|wintrust|oleaut32)$ ]]; then
            continue
        fi

        dll_name=$(dep_to_dll "$dep")
        found=false

        # Search in both bin and qt6/bin directories
        for search_path in "${MXE_TARGET}/qt6/bin" "${MXE_TARGET}/bin"; do
            if [ -f "${search_path}/${dll_name}" ]; then
                echo "  Copying ${dll_name}"
                cp "${search_path}/${dll_name}" "${DEPLOY_DIR}/"
                found=true
                break
            fi
        done

        if [ "$found" = false ]; then
            echo "  Warning: ${dll_name} not found"
        fi
    done

    # Copy Qt plugins
    echo "Copying Qt plugins..."

    # Platform plugin (required for Windows)
    if [ -f "${MXE_TARGET}/qt6/plugins/platforms/qwindows.dll" ]; then
        cp "${MXE_TARGET}/qt6/plugins/platforms/qwindows.dll" "${DEPLOY_DIR}/platforms/"
    fi

    # Image formats (for PNG, ICO support)
    for plugin in qico.dll qpng.dll qjpeg.dll qsvg.dll qicns.dll qtiff.dll qwbmp.dll qgif.dll; do
        if [ -f "${MXE_TARGET}/qt6/plugins/imageformats/${plugin}" ]; then
            cp "${MXE_TARGET}/qt6/plugins/imageformats/${plugin}" "${DEPLOY_DIR}/imageformats/"
        fi
    done

    # TLS/SSL plugins (for HTTPS connections)
    for plugin in qopensslbackend.dll qcertonlybackend.dll qsecuretransportbackend.dll qbuiltinbackend.dll; do
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
    for dir in "${DEPLOY_DIR}"/*; do
        if [ -d "$dir" ]; then
            dirname=$(basename "$dir")
            if [ "$(ls -A "$dir")" ]; then
                echo "  ${dirname}/:"
                ls -lh "$dir" | tail -n +2 | awk '{print "    " $9 " (" $5 ")"}'
            fi
        fi
    done
    echo ""
fi

echo -e "${YELLOW}To test with Wine, run:${NC}"
echo "  wine ${DEPLOY_DIR}/ClipLLM.exe"
echo ""
echo -e "${YELLOW}To create a portable ZIP archive:${NC}"
echo "  cd ${DEPLOY_DIR}"
echo "  zip -r ../clipllm-windows-x86_64-$(git describe --tags --always 2>/dev/null || echo 'dev').zip ."
echo ""
