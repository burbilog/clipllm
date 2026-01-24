# ClipLLM - Cross-platform LLM clipboard utility
# Copyright (C) 2026 Roman V. Isaev <rm@isaeff.net>
#
# CMake toolchain file for cross-compiling ClipLLM for Windows x86_64
# using MXE (M Cross Environment) from Linux
#
# Usage:
#   mkdir build-windows && cd build-windows
#   cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/windows-x86_64-mingw.cmake ..
#
# For static MXE build (default):
#   MXE_TARGETS='x86_64-w64-mingw32.static' make qt6
#
# For shared MXE build:
#   MXE_TARGETS='x86_64-w64-mingw32.shared' make qt6
#   cmake -DCMAKE_TOOLCHAIN_FILE=../cmake/windows-x86_64-mingw.cmake -DMXE_BUILD_TYPE=shared ..

# Target operating system
set(CMAKE_SYSTEM_NAME Windows)
set(CMAKE_SYSTEM_VERSION 1.0)
set(CMAKE_SYSTEM_PROCESSOR x86_64)

# MXE toolchain (adjust path if MXE is installed elsewhere)
set(MXE_PATH "$ENV{HOME}/mxe")

# Determine build type (static or shared)
# Default to static if not specified
if(NOT DEFINED MXE_BUILD_TYPE)
    set(MXE_BUILD_TYPE "static")
endif()

# Set MXE target suffix based on build type
if(MXE_BUILD_TYPE STREQUAL "shared")
    set(MXE_SUFFIX "x86_64-w64-mingw32.shared")
    set(MXE_BUILD_TYPE_DESC "Shared (dynamic linking)")
else()
    set(MXE_SUFFIX "x86_64-w64-mingw32.static")
    set(MXE_BUILD_TYPE_DESC "Static (static linking)")
endif()

message(STATUS "MXE Build Type: ${MXE_BUILD_TYPE_DESC}")
message(STATUS "MXE Target: ${MXE_SUFFIX}")

# Cross-compilation compilers
set(CMAKE_C_COMPILER ${MXE_PATH}/usr/bin/${MXE_SUFFIX}-gcc)
set(CMAKE_CXX_COMPILER ${MXE_PATH}/usr/bin/${MXE_SUFFIX}-g++)
set(CMAKE_RC_COMPILER ${MXE_PATH}/usr/bin/${MXE_SUFFIX}-windres)

# MXE paths
set(MXE_TARGET_PATH ${MXE_PATH}/usr/${MXE_SUFFIX})
set(CMAKE_FIND_ROOT_PATH ${MXE_TARGET_PATH})
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

# Qt6 path
set(CMAKE_PREFIX_PATH ${MXE_TARGET_PATH}/qt6)
set(Qt6_DIR ${MXE_TARGET_PATH}/qt6/lib/cmake/Qt6)

# Windows definitions
add_definitions(-DUNICODE -D_UNICODE)

# For static builds, add QT_STATIC_DEFINE
if(MXE_BUILD_TYPE STREQUAL "static")
    add_definitions(-DQT_STATIC_BUILD)
    # For static Qt, we may need to link additional libraries
    set(QT_STATIC_PLUGINS "qwindows" CACHE STRING "Static Qt plugins to link" FORCE)
endif()

# Set PKG_CONFIG_PATH for MXE
set(ENV{PKG_CONFIG_PATH} ${MXE_TARGET_PATH}/lib/pkgconfig)
set(ENV{PKG_CONFIG_LIBDIR} ${MXE_TARGET_PATH}/lib/pkgconfig)

# Ensure we use the correct pkg-config
set(PKG_CONFIG_EXECUTABLE ${MXE_PATH}/usr/bin/${MXE_SUFFIX}-pkg-config)

# For static builds, disable auto-linking of Qt main (we have our own main)
if(MXE_BUILD_TYPE STREQUAL "static")
    # Qt static builds may need this
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")
endif()
