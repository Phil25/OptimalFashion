cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

message("Building with CMake version " ${CMAKE_VERSION})

project(DS3OptimalFashion)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

if (DEFINED APP_VERSION)
    add_definitions(-DAPP_VERSION="${APP_VERSION}")
endif ()

add_subdirectory(DS3OptimalFashion)
add_subdirectory(DS3OptimalFashionCore)
add_subdirectory(DS3OptimalFashionManual)