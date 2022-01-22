cmake_minimum_required(VERSION 3.12)

project(
    "openGA"
    VERSION 1.1.0
    HOMEPAGE_URL "https://github.com/Arash-codedv/openGA")

add_library(openGA INTERFACE openGA.hpp)
target_include_directories(openGA INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/>)
install(TARGETS openGA
        EXPORT openGA_Targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
