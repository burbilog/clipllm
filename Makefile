.PHONY: build translations clean test windows windows-deploy windows-zip windows-installer regen-icons

# Number of CPU cores for parallel build
NPROCS := $(shell nproc)

# MXE build type: shared (default) or static
# Override with: make windows MXE_BUILD_TYPE=static
MXE_BUILD_TYPE ?= shared

build: translations
	@echo "Building ClipLLM..."
	@mkdir -p build
	@cd build && cmake ..
	@cd build && make -j$(NPROCS)
	@echo ""
	@echo "Build complete. Binary info:"
	@ls -lh build/ClipLLM

translations:
	@echo "Updating translations..."
	@./update-translations.sh

clean:
	@echo "Cleaning build directories..."
	@rm -rf build build-windows deploy-windows dist

# Force regeneration of tray icons from art/clipllm_hires.png
# Use this after replacing the source image
regen-icons:
	@echo "Regenerating tray icons from art/clipllm_hires.png..."
	@rm -f resources/icons/tray-icon-*.png resources/icons/tray-icon.ico
	@$(MAKE) build

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
	@echo "Building ClipLLM for Windows (x86_64, $(MXE_BUILD_TYPE))..."
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
	@mkdir -p dist
	@cd deploy-windows && \
		VERSION=$$(grep "^project(ClipLLM VERSION" ../CMakeLists.txt | sed 's/project(ClipLLM VERSION \([0-9.]*\).*/\1/') && \
		zip -r ../dist/clipllm-$${VERSION}-windows-x86_64.zip . && \
		cd .. && ls -lh dist/clipllm-$${VERSION}-windows-x86_64.zip

# Create Windows installer using NSIS (native Windows installer)
windows-installer: windows-deploy
	@echo "Creating Windows installer using NSIS..."
	@which makensis >/dev/null 2>&1 || { echo "NSIS not found. Install with: sudo apt install nsis"; exit 1; }
	@mkdir -p dist
	@VERSION=$$(grep "^project(ClipLLM VERSION" CMakeLists.txt | sed 's/project(ClipLLM VERSION \([0-9.]*\).*/\1/'); \
		echo "Building installer version $$VERSION..."; \
		makensis -DPRODUCT_VERSION=$$VERSION -NOCD installer/clipllm.nsi && \
		ls -lh dist/ClipLLM-$$VERSION-windows-x86_64-setup.exe

# Quick test with Wine
test-windows-wine: windows-deploy
	@echo "Testing Windows build with Wine..."
	@which wine >/dev/null 2>&1 || (echo "Wine not installed. Install with: sudo apt install wine" && exit 1)
	@wine deploy-windows/ClipLLM.exe --version 2>/dev/null || echo "Note: Full Wine test requires a complete Wine setup"
