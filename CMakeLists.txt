cmake_minimum_required(VERSION 3.16)
SET(MYCOMPILE_FLAGS "-O3")
set(CMAKE_CXX_STANDARD 17)
project("Matrix")

file(GLOB SRC "src/*")
add_executable(RELEASE ${SRC})
target_include_directories(RELEASE PRIVATE "include")
