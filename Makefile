.PHONY: build translations clean test windows windows-deploy windows-zip windows-installer windows-installer-nsis

# Number of CPU cores for parallel build
NPROCS := $(shell nproc)

# MXE build type: shared (default) or static
# Override with: make windows MXE_BUILD_TYPE=static
MXE_BUILD_TYPE ?= shared

build: translations
	@echo "Building ClipAI..."
	@mkdir -p build
	@cd build && cmake ..
	@cd build && make -j$(NPROCS)
	@echo ""
	@echo "Build complete. Binary info:"
	@ls -lh build/ClipAI

translations:
	@echo "Updating translations..."
	@./update-translations.sh

clean:
	@echo "Cleaning build directories..."
	@rm -rf build build-windows deploy-windows dist

test:
	@echo "Running tests..."
	@cd build && ctest --output-on-failure

# =============================================================================
# Windows cross-compilation targets
# =============================================================================

# Check if MXE is installed (checks for static or shared compiler)
check-mxe:
	@if [ "$(MXE_BUILD_TYPE)" = "shared" ]; then \
		which $${HOME}/mxe/usr/bin/x86_64-w64-mingw32.shared-gcc >/dev/null 2>&1 || \
			(echo "MXE shared toolchain not found." && \
			 echo "Build with: cd ~/mxe && make -j\$$(nproc) MXE_TARGETS='x86_64-w64-mingw32.shared' qt6" && exit 1); \
	else \
		which $${HOME}/mxe/usr/bin/x86_64-w64-mingw32.static-gcc >/dev/null 2>&1 || \
			(echo "MXE static toolchain not found. Please install MXE first:" && \
			 echo "  git clone https://github.com/mxe/mxe.git ~/mxe" && \
			 echo "  cd ~/mxe" && \
			 echo "  make -j\$$(nproc) MXE_TARGETS='x86_64-w64-mingw32.static' qt6" && exit 1); \
	fi

# problem -- Самый простой и правильный путь: вообще не поддерживать свой toolchain, а использовать MXE wrapper в Makefile
## Build for Windows (cross-compilation with MXE)
## Use static by default, override with: make windows MXE_BUILD_TYPE=shared
#windows: check-mxe translations
#	@echo "Building ClipAI for Windows (x86_64, $(MXE_BUILD_TYPE))..."
#	@mkdir -p build-windows
#	@cd build-windows && \
#		cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/windows-x86_64-mingw.cmake \
#		      -DCMAKE_BUILD_TYPE=Release \
#		      -DMXE_BUILD_TYPE=$(MXE_BUILD_TYPE) \
#		      .. && \
#		cmake --build . --parallel $(NPROCS)
#	@echo ""
#	@echo "Windows build complete!"
#	@ls -lh build-windows/ClipAI.exe

windows: check-mxe translations
	@echo "Building ClipAI for Windows (x86_64, $(MXE_BUILD_TYPE))..."
	@mkdir -p build-windows
	@cd build-windows && \
		$(HOME)/mxe/usr/bin/x86_64-w64-mingw32.$(MXE_BUILD_TYPE)-cmake \
		  -DCMAKE_BUILD_TYPE=Release \
		  .. && \
		cmake --build . --parallel $(NPROCS)


# Deploy Windows build (static builds don't need DLLs)
windows-deploy: windows
	@echo "Deploying Windows build ($(MXE_BUILD_TYPE))..."
	@MXE_BUILD_TYPE=$(MXE_BUILD_TYPE) ./scripts/deploy-windows.sh

# Create Windows ZIP archive
windows-zip: windows-deploy
	@echo "Creating Windows ZIP archive..."
	@cd deploy-windows && \
		VERSION=$$(grep "^project(ClipAI VERSION" ../CMakeLists.txt | sed 's/project(ClipAI VERSION \([0-9.]*\).*/\1/') && \
		zip -r ../dist/clipai-$${VERSION}-windows-x86_64.zip . && \
		cd .. && ls -lh dist/clipai-$${VERSION}-windows-x86_64.zip

# Create Windows installer (requires Qt Installer Framework with installerbase)
windows-installer: windows-deploy
	@echo "Creating Windows installer..."
	@if [ -f "$(HOME)/mxe/qtifw-native/build/bin/installerbase" ]; then \
		MXE_BUILD_TYPE=$(MXE_BUILD_TYPE) INSTALLER_BASE=$(HOME)/mxe/qtifw-native/build/bin/installerbase BINARYCREATOR=$(HOME)/mxe/qtifw-native/build/bin/binarycreator ./scripts/build-installer.sh; \
	else \
		echo "Qt Installer Framework installerbase not found."; \
		echo "Please build Qt IFW natively:"; \
		echo "  cd ~/mxe/qtifw-native"; \
		echo "  /usr/lib/qt6/bin/qmake && make -j\$$(nproc)"; \
		echo ""; \
		echo "Or use: make windows-zip"; \
		exit 1; \
	fi

# Quick test with Wine
test-windows-wine: windows-deploy
	@echo "Testing Windows build with Wine..."
	@which wine >/dev/null 2>&1 || (echo "Wine not installed. Install with: sudo apt install wine" && exit 1)
	@wine deploy-windows/ClipAI.exe --version 2>/dev/null || echo "Note: Full Wine test requires a complete Wine setup"

# Create Windows installer using NSIS (native Windows installer)
windows-installer-nsis: windows-deploy
	@echo "Creating Windows installer using NSIS..."
	@which makensis >/dev/null 2>&1 || { echo "NSIS not found. Install with: sudo apt install nsis"; exit 1; }
	@VERSION=$$(grep "^project(ClipAI VERSION" CMakeLists.txt | sed 's/project(ClipAI VERSION \([0-9.]*\).*/\1/'); \
	echo "Building installer version $$VERSION..."; \
	makensis -DPRODUCT_VERSION=$$VERSION -NOCD installer/clipai.nsi && \
	ls -lh dist/ClipAI-$$VERSION-windows-x86_64-setup.exe
