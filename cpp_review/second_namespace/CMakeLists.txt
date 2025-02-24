cmake_minimum_required(VERSION 3.16)

project(second_namespace LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(second_namespace main.cpp
               cir.hpp
)

include(GNUInstallDirs)
install(TARGETS second_namespace
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
