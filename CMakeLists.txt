cmake_minimum_required(VERSION 3.14)

project("MyBloomFilter")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.11.0.zip
)
enable_testing()

# Ensure Google Test is fetched
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()


# Set source files for the project
set(SOURCE_FILES
    src/bloomFilter.cpp
    src/HashFunction.cpp
    src/logicToBloomFilter.cpp
    src/global.cpp
    src/server.cpp
)

# Include directories for source files
include_directories(src)


# Set test files
set(TEST_FILES
    tests/test_main.cpp
    tests/test_bloomFilter.cpp
)

# Include directories for test files
include_directories(src ${googletest_SOURCE_DIR}/googletest/include)

# Create a test executable
add_executable(Tests ${TEST_FILES} ${SOURCE_FILES})
target_link_libraries(Tests PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(Tests)

# Main application executable
add_executable(MainApp src/main.cpp ${SOURCE_FILES})
target_link_libraries(MainApp PRIVATE gtest_main)
