cmake_minimum_required(VERSION 3.10)

# Project Name
project(rayTracing)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add Include Directories
include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR}/__test__)

# Collect all source files
file(GLOB_RECURSE MATH_SOURCES "math/*.cpp")
file(GLOB_RECURSE TEST_SOURCES "__test__/*.cpp")
file(GLOB_RECURSE SRC_SOURCES "src/*.cpp")
file(GLOB_RECURSE INCLUDE_SOURCES "include/*.h")

# Add Executable (Ensure tests are included)
add_executable(rayTracing 
    ${MATH_SOURCES} 
    ${TEST_SOURCES}
    ${INCLUDE_SOURCES}
    ${SRC_SOURCES}
)
