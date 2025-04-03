cmake_minimum_required(VERSION 3.10)

# Project Name
project(rayTracing)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Include Directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all source files
file(GLOB_RECURSE SRC_SOURCES "src/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "__test__/*.cpp")

# Add Main Executable
add_executable(rayTracing ${SRC_SOURCES})

# Add Test Executable (Only includes test files)
add_executable(rayTracingTests ${TEST_SOURCES})

