#!/bin/bash
# Build ClipLLM AppImage in Docker for maximum compatibility
# Uses Ubuntu 22.04 (GLIBC 2.35) - compatible with Debian 12+

set -e

IMAGE_NAME="clipllm-appimage-builder"
CONTAINER_NAME="clipllm-builder-$$"

echo "=================================="
echo "ClipLLM AppImage Builder (Docker)"
echo "=================================="
echo ""

# Check if docker is available
if ! command -v docker &> /dev/null; then
    echo "Error: docker not found. Please install docker first."
    echo "  sudo apt install docker.io"
    exit 1
fi

# Build docker image if not exists
if ! docker image inspect "$IMAGE_NAME" &> /dev/null; then
    echo "Building Docker image with Ubuntu 22.04..."
    cat > Dockerfile.appimage << 'EOF'
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-base-dev-tools \
    libqt6svg6-dev \
    qt6-l10n-tools \
    libx11-dev \
    libxcb1-dev \
    wget \
    file \
    && rm -rf /var/lib/apt/lists/*

# Download linuxdeploy and linuxdeploy-plugin-qt
RUN wget -q https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage -O /usr/local/bin/linuxdeploy && \
    chmod +x /usr/local/bin/linuxdeploy && \
    wget -q https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage -O /usr/local/bin/linuxdeploy-plugin-qt && \
    chmod +x /usr/local/bin/linuxdeploy-plugin-qt

WORKDIR /build
EOF

    docker build -f Dockerfile.appimage -t "$IMAGE_NAME" .
    rm -f Dockerfile.appimage
fi

# Get version
VERSION=$(grep "^project(ClipLLM VERSION" CMakeLists.txt | sed 's/project(ClipLLM VERSION \([0-9.]*\).*/\1/')
echo "Building version: $VERSION"
echo ""

# Run build in container
echo "Building ClipLLM in Docker container..."
docker run --rm -v "$(pwd)":/build -w /build "$IMAGE_NAME" bash -c "
    set -e
    echo 'Installing ImageMagick for icon generation...'
    apt-get update -qq && apt-get install -y -qq imagemagick > /dev/null 2>&1 || true

    echo 'Building ClipLLM...'
    rm -rf build
    mkdir -p build
    cd build
    cmake .. -DCMAKE_BUILD_TYPE=Release
    make -j\$(nproc)
    cd ..

    echo 'Creating AppImage...'
    rm -rf AppDir ClipLLM-x86_64.AppImage
    mkdir -p AppDir/usr/bin
    mkdir -p AppDir/usr/share/applications
    mkdir -p AppDir/usr/share/icons/hicolor/scalable/apps
    mkdir -p AppDir/usr/share/clipllm/translations

    cp build/ClipLLM AppDir/usr/bin/clipllm
    sed 's/Exec=clipllm/Exec=clipllm/' resources/clipllm.desktop.in > AppDir/usr/share/applications/clipllm.desktop
    cp resources/icons/app-icon.svg AppDir/usr/share/icons/hicolor/scalable/apps/clipllm.svg
    cp build/translations/*.qm AppDir/usr/share/clipllm/translations/ 2>/dev/null || true

    # Run linuxdeploy with Qt plugin
    export QMAKE=/usr/lib/qt6/bin/qmake
    mkdir -p dist
    linuxdeploy --appdir AppDir --plugin qt --output appimage

    mv ClipLLM-x86_64.AppImage dist/clipllm-${VERSION}-linux-x86_64.AppImage
    ls -lh dist/clipllm-${VERSION}-linux-x86_64.AppImage
"

echo ""
echo "=================================="
echo "AppImage built successfully!"
echo "GLIBC version: 2.35 (Ubuntu 22.04)"
echo "Compatible with: Debian 12+, Ubuntu 22.04+, and most modern distros"
echo "=================================="
