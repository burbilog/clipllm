#!/bin/bash
# Update and compile translations for ClipLLM

set -e

# Use Qt6 tools directly - bypass broken qtchooser
LUPDATE="/usr/lib/qt6/bin/lupdate"
LRELEASE="/usr/lib/qt6/bin/lrelease"

if [ ! -f "$LUPDATE" ]; then
    echo "Error: Qt6 lupdate not found at $LUPDATE"
    echo "Please install qt6-base-dev-tools package"
    exit 1
fi

echo "=========================================="
echo "ClipLLM Translation Updater"
echo "=========================================="
echo ""

# Get script directory (where ClipLLM is located)
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

echo "Updating translation source files from source code..."
echo "Source directory: $SCRIPT_DIR/src"
echo "Translations: $SCRIPT_DIR/translations/*.ts"
echo ""

# Run lupdate to extract new strings from source code
$LUPDATE "$SCRIPT_DIR/src/" -ts "$SCRIPT_DIR/translations/"*.ts

echo ""
echo "Compiling translations..."
$LRELEASE "$SCRIPT_DIR/translations/"*.ts

echo ""
echo "=========================================="
echo "✅ Translation files updated and compiled!"
echo "=========================================="
echo ""
echo "Next steps:"
echo "  1. Open linguist to edit translations:"
echo "     linguist $SCRIPT_DIR/translations/clipllm_ru.ts"
echo ""
echo "  2. Translate all strings marked with '?' (untranslated)"
echo ""
echo "  3. Compile translations:"
echo "     cd $SCRIPT_DIR/build && cmake --build . --target translations"
echo ""
echo "  4. Rebuild ClipLLM:"
echo "     cd $SCRIPT_DIR/build && cmake --build ."
echo ""
echo "Quick commands:"
echo "  ./update-translations.sh    # Update source files"
echo "  linguist translations/clipllm_ru.ts  # Translate"
echo "  cd build && cmake --build . --target translations  # Compile"
echo ""
