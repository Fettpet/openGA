cmake_minimum_required(VERSION 3.21)


add_executable(UnitTests
    src/Matrix.test.cpp
)

target_link_libraries(UnitTests
    gtest_main
    openGA
)

add_test(UnitTests UnitTests)
