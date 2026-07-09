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
# along with this program.  If not, see <https://www.gnu.org/licenses/>.

# HistoryManager tests
qt_add_executable(TestHistoryManager
    tst_historymanager.cpp
    ../src/core/historymanager.cpp
    ../src/core/debuglogger.cpp
)

target_link_libraries(TestHistoryManager
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Test
)

target_include_directories(TestHistoryManager
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

add_test(NAME TestHistoryManager COMMAND TestHistoryManager)

# ConfigManager tests
qt_add_executable(TestConfigManager
    tst_configmanager.cpp
    ../src/core/configmanager.cpp
    ../src/core/debuglogger.cpp
    ../src/models/providerprofile.cpp
)

target_link_libraries(TestConfigManager
    PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Test
)

target_include_directories(TestConfigManager
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

add_test(NAME TestConfigManager COMMAND TestConfigManager)

# RubySanitizer tests
qt_add_executable(TestRubySanitizer
    tst_rubysanitizer.cpp
    ../src/ui/rubysanitizer.cpp
)

target_link_libraries(TestRubySanitizer
    PRIVATE
    Qt6::Core
    Qt6::Test
)

target_include_directories(TestRubySanitizer
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

add_test(NAME TestRubySanitizer COMMAND TestRubySanitizer)

# Proxy tests (unit): verify a configured proxy URL is applied to the
# QNetworkAccessManager after setProxy()/setConfig(). No network needed.
qt_add_executable(TestProxy
    tst_proxy.cpp
    ../src/core/llmclient.cpp
    ../src/core/debuglogger.cpp
    ../src/models/llmconfig.cpp
)

target_link_libraries(TestProxy
    PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Widgets
    Qt6::Test
)

target_include_directories(TestProxy
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

add_test(NAME TestProxy COMMAND TestProxy)

# Proxy tests (integration): drive a real request through docker-hosted HTTP
# and SOCKS5 proxies against a mock LLM. Orchestrated by run.sh, which skips
# (exit 77) when docker is unavailable so CI without docker is not broken.
qt_add_executable(TestProxyIntegration
    tst_proxyintegration.cpp
    ../src/core/llmclient.cpp
    ../src/core/debuglogger.cpp
    ../src/models/llmconfig.cpp
)

target_link_libraries(TestProxyIntegration
    PRIVATE
    Qt6::Core
    Qt6::Network
    Qt6::Widgets
    Qt6::Test
)

target_include_directories(TestProxyIntegration
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

add_test(NAME TestProxyIntegration
    COMMAND bash ${CMAKE_SOURCE_DIR}/tests/proxy/run.sh $<TARGET_FILE:TestProxyIntegration>)
set_tests_properties(TestProxyIntegration PROPERTIES SKIP_RETURN_CODE 77)
