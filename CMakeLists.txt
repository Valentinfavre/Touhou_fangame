cmake_minimum_required(VERSION 3.15)
project(Touhou_flandre)

set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(Touhou_flandre main.cpp main.hpp menu.cpp menu.hpp)
target_link_libraries(Touhou_flandre ${CONAN_LIBS})