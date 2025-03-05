cmake_minimum_required(VERSION 3.16)

project(learning LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

get_filename_component(SECONDARY_DIR "${PROJECT_SOURCE_DIR}/.." ABSOLUTE)
get_filename_component(SECONDARY_DIR_NAME "${SECONDARY_DIR}" NAME)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/../../bin/)

add_executable(${PROJECT_NAME}
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
install(TARGETS ${PROJECT_NAME}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
