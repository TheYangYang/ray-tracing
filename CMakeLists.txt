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

# Add the PCH file and source
add_library(pch STATIC src/pch.cpp)

# Add Main Executable
add_executable(rayTracing ${SRC_SOURCES})

# Add Test Executable 
add_executable(rayTracingTests ${TEST_SOURCES})

if (MSVC)
    set_target_properties(rayTracing PROPERTIES LINK_FLAGS "/SUBSYSTEM:WINDOWS")
endif()

# Link libraries
target_link_libraries(rayTracing pch)
target_link_libraries(rayTracingTests pch)
