cmake_minimum_required(VERSION 3.12)

project(openGA VERSION 0.1 LANGUAGES CXX)

option(build_examples "build the examples" ON)
add_subdirectory(src)

if(${build_examples})

    add_subdirectory(examples)
endif()
