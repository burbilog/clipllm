# Translations CMakeLists.txt

# Translation files
set(TS_FILES
    clipai_en.ts
    clipai_ru.ts
    clipai_de.ts
    clipai_fr.ts
    clipai_es.ts
)

# Custom target to update translation files from source
add_custom_target(translations_update
    COMMAND ${Qt6_LUPDATE_EXECUTABLE}
        ${CMAKE_SOURCE_DIR}/src
        -ts ${TS_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Updating translation files"
    VERBATIM
)

# Custom target to release translation files (create .qm files)
add_custom_target(translations_release
    COMMAND ${Qt6_LRELEASE_EXECUTABLE}
        ${TS_FILES}
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Releasing translation files"
    VERBATIM
)

# Install translation files
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/*.qm
    DESTINATION share/clipai/translations
    OPTIONAL
)
