cmake_minimum_required(VERSION 3.16)

project(learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(second_namespace
               src/main.cpp
               include/cir.hpp
               src/exercise.cpp
               include/exercise.hpp
               include/animal.hpp
               src/animal.cpp
               src/lion.cpp
               include/lion.hpp
)

include(GNUInstallDirs)
install(TARGETS second_namespace
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
