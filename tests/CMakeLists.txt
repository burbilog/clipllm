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
)

target_link_libraries(TestHistoryManager
    PRIVATE
    Qt6::Core
    Qt6::Test
)

target_include_directories(TestHistoryManager
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

add_test(NAME TestHistoryManager COMMAND TestHistoryManager)

# ConfigManager tests
qt_add_executable(TestConfigManager
    tst_configmanager.cpp
    ../src/core/configmanager.cpp
    ../src/models/providerprofile.cpp
)

target_link_libraries(TestConfigManager
    PRIVATE
    Qt6::Core
    Qt6::Test
)

target_include_directories(TestConfigManager
    PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

add_test(NAME TestConfigManager COMMAND TestConfigManager)
