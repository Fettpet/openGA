cmake_minimum_required(VERSION 3.12)

project(openGA VERSION 0.1 LANGUAGES CXX)

option(BUILD_OPENGA_EXAMPLES "build the examples" OFF)
option(BUILD_OPENGA_TESTS "build the unit tests" ON)
add_subdirectory(src)

if(${BUILD_OPENGA_EXAMPLES})
    add_subdirectory(examples)
endif()

if(${BUILD_OPENGA_TESTS})
    include(third-party/googletest.cmake)
    include(src/tests.cmake)
endif()
