cmake_minimum_required(VERSION 3.14)

project(MyBloomFilter)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

# Set source files for the project
set(SOURCE_FILES
    src/bloomFilter.cpp
)

# Set test files
set(TEST_FILES
    tests/test_main.cpp
    tests/test_bloomFilter.cpp
)

# Create an executable for the tests
add_executable(bloomFilterTests ${TEST_FILES})

# Link the GoogleTest library to the test executable
target_link_libraries(bloomFilterTests PRIVATE gtest gtest_main)

# Link the source files to the test executable
target_sources(bloomFilterTests PRIVATE ${SOURCE_FILES})

# Include directories
target_include_directories(bloomFilterTests PRIVATE src)

# Enable testing and add test
enable_testing()
include(GoogleTest)
add_test(NAME bloomFilterTests COMMAND bloomFilterTests)