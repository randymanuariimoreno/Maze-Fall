cmake_minimum_required(VERSION 3.23)

project(maze-fall
    VERSION 0.1
    DESCRIPTION "Roguelike Dungeon Crawler made in C++ with SDL3"
    LANGUAGES CXX)

add_executable(maze-fall)

target_sources(maze-fall
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)
