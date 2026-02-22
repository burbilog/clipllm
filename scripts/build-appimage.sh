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

# Always rebuild image to ensure latest dependencies
echo "Building/rebuilding Docker image with Ubuntu 22.04..."
if docker image inspect "$IMAGE_NAME" &> /dev/null; then
    echo "Removing old image to rebuild with updated dependencies..."
    docker rmi "$IMAGE_NAME" || true
fi

cat > Dockerfile.appimage << 'EOF'
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    qt6-base-dev \
    qt6-tools-dev \
    qt6-tools-dev-tools \
    qt6-base-dev-tools \
    libqt6svg6-dev \
    qt6-l10n-tools \
    libgl1-mesa-dev \
    libx11-dev \
    libxcb1-dev \
    wget \
    file \
    && rm -rf /var/lib/apt/lists/*

# Download and extract linuxdeploy and linuxdeploy-plugin-qt
# Extract AppImages to work without FUSE in Docker
RUN cd /tmp && \
    wget -q https://github.com/linuxdeploy/linuxdeploy/releases/download/continuous/linuxdeploy-x86_64.AppImage && \
    chmod +x linuxdeploy-x86_64.AppImage && \
    ./linuxdeploy-x86_64.AppImage --appimage-extract && \
    mv squashfs-root /opt/linuxdeploy && \
    ln -s /opt/linuxdeploy/AppRun /usr/local/bin/linuxdeploy && \
    wget -q https://github.com/linuxdeploy/linuxdeploy-plugin-qt/releases/download/continuous/linuxdeploy-plugin-qt-x86_64.AppImage && \
    chmod +x linuxdeploy-plugin-qt-x86_64.AppImage && \
    ./linuxdeploy-plugin-qt-x86_64.AppImage --appimage-extract && \
    mv squashfs-root /opt/linuxdeploy-plugin-qt && \
    ln -s /opt/linuxdeploy-plugin-qt/AppRun /usr/local/bin/linuxdeploy-plugin-qt && \
    rm -f linuxdeploy-x86_64.AppImage linuxdeploy-plugin-qt-x86_64.AppImage && \
    rm -rf /tmp/squashfs-root*

WORKDIR /build
EOF

docker build -f Dockerfile.appimage -t "$IMAGE_NAME" .
rm -f Dockerfile.appimage

# Get version
VERSION=$(grep "^project(ClipLLM VERSION" CMakeLists.txt | sed 's/project(ClipLLM VERSION \([0-9.]*\).*/\1/')
echo "Building version: $VERSION"
echo ""

# Run build in container
echo "Building ClipLLM in Docker container..."
docker run --rm -v "$(pwd)":/build -w /build "$IMAGE_NAME" bash -c "
    # Get host user info for correct file ownership
    HOST_UID=\$(stat -c '%u' /build/.)
    HOST_GID=\$(stat -c '%g' /build/.)
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
    export LINUXDEPLOY_PLUGIN_QT=/usr/local/bin/linuxdeploy-plugin-qt
    mkdir -p dist
    linuxdeploy --appdir AppDir --plugin qt --output appimage

    mv ClipLLM-x86_64.AppImage dist/clipllm-${VERSION}-linux-x86_64.AppImage
    ls -lh dist/clipllm-${VERSION}-linux-x86_64.AppImage

    # Fix ownership - change from root to host user
    chown -R \${HOST_UID}:\${HOST_GID} dist/ build/ AppDir/ 2>/dev/null || true
"

echo ""
echo "=================================="
echo "AppImage built successfully!"
echo "GLIBC version: 2.35 (Ubuntu 22.04)"
echo "Compatible with: Debian 12+, Ubuntu 22.04+, and most modern distros"
echo "=================================="
