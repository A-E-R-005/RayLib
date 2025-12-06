cmake_minimum_required(VERSION 3.31)
project(RayLib)

set(CMAKE_CXX_STANDARD 23)
add_executable(RayLib src/main.cpp
        src/player.h
        src/player.cpp
        src/target.h
        src/target.cpp
        src/sheetanimation.h
        src/sheetanimation.cpp)
find_package(raylib CONFIG REQUIRED)
target_link_libraries(RayLib PRIVATE raylib)