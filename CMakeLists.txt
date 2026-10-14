cmake_minimum_required(VERSION 3.20)

project(Maze-Fall
    VERSION 1.0.0
    DESCRIPTION "A C++ project using SDL3"
    LANGUAGES CXX
)

# Use a modern C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Collect source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp"
)

# Create the executable
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

# Include project headers
target_include_directories(${PROJECT_NAME}
    PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)

# Required SDL3 support
find_package(SDL3 REQUIRED CONFIG)
find_package(SDL3_image REQUIRED CONFIG)

target_link_libraries(${PROJECT_NAME}
    PRIVATE SDL3::SDL3
)

if(SDL3_FOUND)
    message(STATUS "SDL3 found: enabling SDL3 support")

    target_link_libraries(${PROJECT_NAME}
        PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
    )
else()
    message(STATUS "SDL3 not found: building without SDL3")
endif()
