# ClipLLM - Cross-platform LLM clipboard utility
# Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.16)
project(ClipLLM VERSION 1.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt6 configuration
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network LinguistTools)
find_package(Qt6 OPTIONAL_COMPONENTS Test)

# Optional Qt6 Concurrent for async operations
find_package(Qt6 OPTIONAL_COMPONENTS Concurrent)
if(Qt6Concurrent_FOUND)
    message(STATUS "Qt6::Concurrent found - async operations enabled")
endif()

# Find ImageMagick for icon generation
find_program(CONVERT_EXECUTABLE convert)
if(CONVERT_EXECUTABLE)
    message(STATUS "ImageMagick convert found at ${CONVERT_EXECUTABLE}")
else()
    message(WARNING "ImageMagick convert not found - icon generation disabled")
endif()

# QHotkey library sources (global hotkey support)
set(QHOTKEY_SOURCES
    3rdparty/qhotkey/qhotkey.cpp
)

# Platform-specific QHotkey sources
if(UNIX AND NOT APPLE)
    # Linux/X11
    find_package(X11 REQUIRED)
    list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_x11.cpp)
elseif(APPLE)
    # macOS
    list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_mac.cpp)
    find_library(CARBON_LIBRARY Carbon)
elseif(WIN32)
    # Windows
    list(APPEND QHOTKEY_SOURCES 3rdparty/qhotkey/qhotkey_win.cpp)
endif()

# Source files
set(SOURCES
    src/main.cpp
    src/core/app.cpp
    src/core/clipboardmanager.cpp
    src/core/llmclient.cpp
    src/core/promptmanager.cpp
    src/core/configmanager.cpp
    src/core/keychainstore.cpp
    src/core/providerkeystore.cpp
    src/core/historymanager.cpp
    src/core/groupsmanager.cpp
    src/core/debuglogger.cpp
    src/core/screenshotmanager.cpp
    src/ui/trayicon.cpp
    src/ui/promptmenu.cpp
    src/ui/settingsdialog.cpp
    src/ui/resultdialog.cpp
    src/ui/hotkeyedit.cpp
    src/ui/historydialog.cpp
    src/ui/prompteditordialog.cpp
    src/ui/promptpreviewdialog.cpp
    src/ui/promptconfirmdialog.cpp
    src/ui/imageviewdialog.cpp
    src/ui/groupsdialog.cpp
    src/ui/screenshotselector.cpp
    src/models/prompt.cpp
    src/models/llmconfig.cpp
    src/models/providerprofile.cpp
    ${QHOTKEY_SOURCES}
)

# Header files
set(HEADERS
    src/core/app.h
    src/core/clipboardmanager.h
    src/core/llmclient.h
    src/core/promptmanager.h
    src/core/configmanager.h
    src/core/keychainstore.h
    src/core/providerkeystore.h
    src/core/historymanager.h
    src/core/groupsmanager.h
    src/core/debuglogger.h
    src/core/screenshotmanager.h
    src/ui/trayicon.h
    src/ui/promptmenu.h
    src/ui/settingsdialog.h
    src/ui/resultdialog.h
    src/ui/hotkeyedit.h
    src/ui/historydialog.h
    src/ui/prompteditordialog.h
    src/ui/promptpreviewdialog.h
    src/ui/promptconfirmdialog.h
    src/ui/imageviewdialog.h
    src/ui/groupsdialog.h
    src/ui/screenshotselector.h
    src/models/prompt.h
    src/models/llmconfig.h
    src/models/providerprofile.h
    3rdparty/qhotkey/qhotkey.h
    3rdparty/qhotkey/qhotkey_p.h
)

# Generate version.h from version.h.in (single source of truth for version)
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/src/core/version.h.in
    ${CMAKE_CURRENT_BINARY_DIR}/src/core/version.h
    @ONLY
)

# Windows-specific: Generate .rc file and manifest
if(WIN32)
    # Copy manifest to build directory
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/clipllm.exe.manifest
        ${CMAKE_CURRENT_BINARY_DIR}/clipllm.exe.manifest
        COPYONLY
    )

    # Generate .rc file from template
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/clipllm.rc.in
        ${CMAKE_CURRENT_BINARY_DIR}/clipllm.rc
        @ONLY
    )
endif()

# Create executable
if(WIN32)
    # Windows: Add .rc file for version info and icon
    add_executable(${PROJECT_NAME} WIN32
        ${SOURCES}
        ${HEADERS}
        ${CMAKE_CURRENT_BINARY_DIR}/clipllm.rc
    )
else()
    add_executable(${PROJECT_NAME}
        ${SOURCES}
        ${HEADERS}
    )
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)

if(Qt6Concurrent_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Concurrent)
    target_compile_definitions(${PROJECT_NAME} PRIVATE QT_CONCURRENT_LIB)
endif()

# Link X11 on Linux for QHotkey
if(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${X11_LIBRARIES})
    target_include_directories(${PROJECT_NAME} PRIVATE ${X11_INCLUDE_DIR})
    # Find xcb for keyboard grabbing in screenshot selector
    find_library(XCB_LIBRARY xcb)
    if(XCB_LIBRARY)
        target_link_libraries(${PROJECT_NAME} PRIVATE ${XCB_LIBRARY})
    endif()
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${CARBON_LIBRARY})
endif()

if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    find_library(BZ2_LIBRARY bz2 REQUIRED)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${BZ2_LIBRARY})
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/qhotkey
    ${CMAKE_CURRENT_BINARY_DIR}/src  # For generated version.h
)

# Generate tray icons from high-resolution source
if(CONVERT_EXECUTABLE AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png")
    message(STATUS "Enabling icon generation from art/clipllm_hires.png")
    
    # Create output directory
    file(MAKE_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons)
    
    # Generate PNG icons for Linux/macOS
    add_custom_command(
        OUTPUT
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-16.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-22.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-24.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-32.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-48.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-64.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-128.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon.ico
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 16x16 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-16.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 22x22 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-22.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 24x24 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-24.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 32x32 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-32.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 48x48 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-48.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 64x64 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-64.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            -resize 128x128 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-128.png
        COMMAND ${CONVERT_EXECUTABLE}
            ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
            \( -clone 0 -resize 16x16 \)
            \( -clone 0 -resize 32x32 \)
            \( -clone 0 -resize 48x48 \)
            \( -clone 0 -resize 64x64 \)
            \( -clone 0 -resize 128x128 \)
            \( -clone 0 -resize 256x256 \)
            -delete 0 ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon.ico
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/art/clipllm_hires.png
        COMMENT "Generating tray icons from art/clipllm_hires.png"
        VERBATIM
    )
    
    add_custom_target(generate_tray_icons
        DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-16.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-22.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-24.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-32.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-48.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-64.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-128.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon.ico
        COMMENT "Icon generation target"
    )
    
    # Make resources depend on icon generation
    # Also add JSON config to ensure it's included in resources
    set_property(SOURCE resources/resources.qrc
        PROPERTY OBJECT_DEPENDS
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-16.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-22.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-24.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-32.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-48.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-64.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon-128.png
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/tray-icon.ico
            ${CMAKE_CURRENT_SOURCE_DIR}/resources/config/prompts-default.json
    )
    
    # Ensure icon generation runs when needed by making it a dependency
    # of the main target - this is more reliable than OBJECT_DEPENDS alone
    add_dependencies(${PROJECT_NAME} generate_tray_icons)
else()
    message(STATUS "Icon generation skipped (ImageMagick or source file not found)")
endif()

# Resources - use target_sources with CMAKE_AUTORCC=ON
# qt_add_resources() syntax was embedding the .qrc XML file instead of actual resources
# This ensures proper resource embedding for all platforms
if(CMAKE_AUTORCC)
    message(STATUS "Using CMAKE_AUTORCC for resource compilation")
    target_sources(${PROJECT_NAME} PRIVATE resources/resources.qrc)
else()
    # Fallback for older CMake versions
    message(STATUS "Using qt_add_resources for resource compilation")
    qt_add_resources(${PROJECT_NAME}
        resources/resources.qrc
    )
endif()

# Translations
set(TS_FILES
    translations/clipllm_en.ts
    translations/clipllm_ru.ts
    translations/clipllm_de.ts
    translations/clipllm_fr.ts
    translations/clipllm_es.ts
)

set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/translations)

# Custom target to generate .qm files (built by default with ALL)
add_custom_target(translations ALL
    COMMENT "Building translations..."
)

# Generate .qm files for each language
foreach(ts_file ${TS_FILES})
    get_filename_component(lang_name ${ts_file} NAME_WE)
    add_custom_command(
        TARGET translations
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_CURRENT_BINARY_DIR}/translations
        COMMAND Qt6::lrelease ${CMAKE_CURRENT_SOURCE_DIR}/${ts_file} -qm ${CMAKE_CURRENT_BINARY_DIR}/translations/${lang_name}.qm
        COMMENT "Generating ${lang_name}.qm..."
        VERBATIM
    )
endforeach()

# Development helper: copy .qm files to source directory (for running from build dir)
add_custom_target(translations-copy
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_BINARY_DIR}/translations ${CMAKE_CURRENT_SOURCE_DIR}/translations
    COMMENT "Copying .qm files to source directory for development..."
    DEPENDS translations
)

# Install translations
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/translations/*.qm
    DESTINATION share/clipllm/translations
)

# Unit tests
option(BUILD_TESTING "Build unit tests" ON)
if(Qt6Test_FOUND AND BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
    message(STATUS "Unit tests enabled")
else()
    if(NOT Qt6Test_FOUND)
        message(STATUS "Unit tests disabled: Qt6::Test not found")
    endif()
    if(NOT BUILD_TESTING)
        message(STATUS "Unit tests disabled: BUILD_TESTING=OFF")
    endif()
endif()

# Desktop file for Linux
if(UNIX AND NOT APPLE)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/clipllm.desktop.in
        ${CMAKE_CURRENT_BINARY_DIR}/clipllm.desktop
        @ONLY
    )
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/clipllm.desktop
        DESTINATION share/applications
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/app-icon.svg
        DESTINATION share/icons/hicolor/scalable/apps
        RENAME clipllm.svg
    )
endif()

# Windows-specific installation
if(WIN32)
    # Install translations to bin directory (same as executable)
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/translations/*.qm
        DESTINATION bin/translations
    )
endif()

# Installation
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Print configuration summary
message(STATUS "")
message(STATUS "ClipLLM Configuration:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Qt6: ${Qt6_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "")
