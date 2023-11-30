cmake_minimum_required(VERSION 3.22)

set(VCPKG_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg")
set(VCPKG_TARGET_TRIPLET "x64-linux")
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
    
project(
        JumpingWindows 
        VERSION 0.1.0
        DESCRIPTION "This is a simple game that is a jumping puzzle, but in order to get extra movement you have to move the window.")

find_package(fmt CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)
include(CTest)
include(Catch)
enable_testing()

add_subdirectory(test)
add_subdirectory(src)
