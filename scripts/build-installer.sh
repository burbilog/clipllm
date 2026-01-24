#!/usr/bin/env bash
# ClipAI - Cross-platform LLM clipboard utility
# Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
#
# Windows installer build script for ClipAI
# This script creates a Windows installer using Qt Installer Framework

set -e

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Configuration
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$(dirname "$SCRIPT_DIR")"
DEPLOY_DIR="${PROJECT_ROOT}/deploy-windows"
INSTALLER_DIR="${PROJECT_ROOT}/installer"
PACKAGES_DIR="${PROJECT_ROOT}/packages"
OUTPUT_DIR="${PROJECT_ROOT}/dist"
MXE_PATH="${HOME}/mxe"
BINARYCREATOR="${MXE_PATH}/usr/bin/binarycreator"
ARCHIVEGEN="${MXE_PATH}/usr/bin/archivegen"

# Get version from CMakeLists.txt
VERSION=$(grep "^project(ClipAI VERSION" "${PROJECT_ROOT}/CMakeLists.txt" | sed 's/project(ClipAI VERSION \([0-9.]*\).*/\1/')

# Print configuration
echo "=========================================="
echo "ClipAI Windows Installer Builder"
echo "=========================================="
echo "Version:         ${VERSION}"
echo "Deploy dir:      ${DEPLOY_DIR}"
echo "Output dir:      ${OUTPUT_DIR}"
echo "MXE path:        ${MXE_PATH}"
echo ""

# Check if deployment directory exists
if [ ! -d "${DEPLOY_DIR}" ]; then
    echo -e "${RED}Error: Deployment directory ${DEPLOY_DIR} does not exist${NC}"
    echo "Please run 'make windows-deploy' first"
    exit 1
fi

# Check if binarycreator exists
if [ ! -f "${BINARYCREATOR}" ]; then
    echo -e "${RED}Error: binarycreator not found at ${BINARYCREATOR}${NC}"
    echo "Qt Installer Framework not installed in MXE."
    echo ""
    echo "To install Qt Installer Framework in MXE:"
    echo "  cd ~/mxe"
    echo "  make ifw"
    exit 1
fi

# Create output directory
echo "Creating output directory..."
mkdir -p "${OUTPUT_DIR}"

# Prepare package data directory
echo "Preparing package data..."
rm -rf "${PACKAGES_DIR}/clipai/data"
mkdir -p "${PACKAGES_DIR}/clipai/data"

# Copy deployment files to package data directory
echo "Copying files to package..."
cp -r "${DEPLOY_DIR}"/* "${PACKAGES_DIR}/clipai/data/"

# Copy LICENSE file
if [ -f "${PROJECT_ROOT}/LICENSE.md" ]; then
    cp "${PROJECT_ROOT}/LICENSE.md" "${PACKAGES_DIR}/clipai/meta/LICENSE"
fi

# Prepare installer icons directory
echo "Preparing installer icons..."
mkdir -p "${INSTALLER_DIR}/icons"

# Create or copy icons for the installer
# For now, create a placeholder script comment
# TODO: Add proper installer icons

# Update package.xml with current version
echo "Updating package.xml with version ${VERSION}..."
cat > "${PACKAGES_DIR}/clipai/meta/package.xml" << EOF
<?xml version="1.0"?>
<Package>
    <DisplayName>ClipAI</DisplayName>
    <Description>ClipAI - Cross-platform LLM clipboard utility. Process clipboard content with AI prompts using global hotkeys.</Description>
    <Version>${VERSION}</Version>
    <ReleaseDate>$(date +%Y-%m-%d)</ReleaseDate>
    <Name>clipai</Name>
    <Licenses>
        <License name="GNU General Public License v3" file="LICENSE" />
    </Licenses>
    <Default>true</Default>
    <Script>installscript.qs</Script>
    <SortingPriority>100</SortingPriority>
    <AutoDependOn></AutoDependOn>
</Package>
EOF

# Update config.xml with current version
cat > "${INSTALLER_DIR}/config/config.xml" << EOF
<?xml version="1.0" encoding="UTF-8"?>
<Installer>
    <Name>ClipAI</Name>
    <Version>${VERSION}</Version>
    <Title>ClipAI ${VERSION} Setup</Title>
    <Publisher>Roman V. Isaev</Publisher>
    <ProductUrl>https://github.com/rm-isaeff/clipai</ProductUrl>

    <!-- Installer Window Configuration -->
    <WizardStyle>Modern</WizardStyle>
    <WizardDefaultWidth>800</WizardDefaultWidth>
    <WizardDefaultHeight>600</WizardDefaultHeight>

    <!-- Target Directory -->
    <TargetDir>@ApplicationsDir@/ClipAI</TargetDir>

    <!-- Start Menu Entry (Windows only) -->
    <StartMenuDir>ClipAI</StartMenuDir>

    <!-- Run Program after installation -->
    <RunProgram>@TargetDir@/ClipAI.exe</RunProgram>
    <RunProgramArguments></RunProgramArguments>
    <RunProgramDescription>Launch ClipAI</RunProgramDescription>

    <!-- Maintenance Tool -->
    <MaintenanceToolName>ClipAIMaintenanceTool</MaintenanceToolName>

    <!-- Allow non-admin installation on Windows -->
    <AllowNonAsciiCharacters>true</AllowNonAsciiCharacters>
    <AllowSpaceInPath>true</AllowSpaceInPath>

    <!-- Control installation -->
    <RemoveTargetDir>true</RemoveTargetDir>
    <CreateLocalRepository>true</CreateLocalRepository>

    <!-- Save default answers -->
    <SaveDefaultAnswers>true</SaveDefaultAnswers>
</Installer>
EOF

# Build installer
INSTALLER_NAME="clipai-${VERSION}-windows-x86_64-setup.exe"
echo ""
echo "Building installer: ${INSTALLER_NAME}"
echo ""

"${BINARYCREATOR}" \
    --offline-only \
    -c "${INSTALLER_DIR}/config/config.xml" \
    -p "${PACKAGES_DIR}" \
    "${OUTPUT_DIR}/${INSTALLER_NAME}"

# Print summary
echo ""
echo "=========================================="
echo -e "${GREEN}Installer created successfully!${NC}"
echo "=========================================="
echo "Installer: ${OUTPUT_DIR}/${INSTALLER_NAME}"
ls -lh "${OUTPUT_DIR}/${INSTALLER_NAME}"
echo ""
echo -e "${YELLOW}To test the installer on Windows, Wine, or a VM:${NC}"
echo "  wine ${OUTPUT_DIR}/${INSTALLER_NAME}"
echo ""
