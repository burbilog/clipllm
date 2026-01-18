cmake_minimum_required(VERSION 3.16)
project(ClipAI VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Qt6 configuration
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Network LinguistTools)

# Optional Qt6 Concurrent for async operations
find_package(Qt6 OPTIONAL_COMPONENTS Concurrent)
if(Qt6Concurrent_FOUND)
    message(STATUS "Qt6::Concurrent found - async operations enabled")
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
    src/core/historymanager.cpp
    src/ui/trayicon.cpp
    src/ui/promptmenu.cpp
    src/ui/settingsdialog.cpp
    src/ui/resultdialog.cpp
    src/ui/hotkeyedit.cpp
    src/ui/historydialog.cpp
    src/models/prompt.cpp
    src/models/llmconfig.cpp
)

# Header files
set(HEADERS
    src/core/app.h
    src/core/clipboardmanager.h
    src/core/llmclient.h
    src/core/promptmanager.h
    src/core/configmanager.h
    src/core/keychainstore.h
    src/core/historymanager.h
    src/ui/trayicon.h
    src/ui/promptmenu.h
    src/ui/settingsdialog.h
    src/ui/resultdialog.h
    src/ui/hotkeyedit.h
    src/ui/historydialog.h
    src/models/prompt.h
    src/models/llmconfig.h
)

# Create executable
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Network
)

if(Qt6Concurrent_FOUND)
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Concurrent)
    target_compile_definitions(${PROJECT_NAME} PRIVATE QT_CONCURRENT_LIB)
endif()

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Resources
qt_add_resources(${PROJECT_NAME} "resources"
    FILES
        resources/resources.qrc
)

# Translations
set(TS_FILES
    translations/clipai_en.ts
    translations/clipai_ru.ts
    translations/clipai_de.ts
    translations/clipai_fr.ts
    translations/clipai_es.ts
)

set_source_files_properties(${TS_FILES} PROPERTIES OUTPUT_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/translations)

# Add translation target
qt_add_lupdate(${PROJECT_NAME} ${TS_FILES})
qt_add_lrelease(${PROJECT_NAME} ${TS_FILES})

# Install translations
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/translations/*.qm
    DESTINATION share/clipai/translations
)

# Desktop file for Linux
if(UNIX AND NOT APPLE)
    configure_file(
        ${CMAKE_CURRENT_SOURCE_DIR}/resources/clipai.desktop.in
        ${CMAKE_CURRENT_BINARY_DIR}/clipai.desktop
        @ONLY
    )
    install(FILES ${CMAKE_CURRENT_BINARY_DIR}/clipai.desktop
        DESTINATION share/applications
    )
    install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/app-icon.svg
        DESTINATION share/icons/hicolor/scalable/apps
        RENAME clipai.svg
    )
endif()

# Installation
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Print configuration summary
message(STATUS "")
message(STATUS "ClipAI Configuration:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  Qt6: ${Qt6_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "")
