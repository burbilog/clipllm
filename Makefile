.PHONY: build translations clean

# Number of CPU cores for parallel build
NPROCS := $(shell nproc)

build:
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
	@echo "Cleaning build directory..."
	@rm -rf build
