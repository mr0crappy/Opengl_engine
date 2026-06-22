cmake_minimum_required(VERSION 3.20)

project(Sentinel)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glfw)

file(GLOB_RECURSE ENGINE_SOURCES
    src/*.cpp
)

add_executable(Sentinel
    ${ENGINE_SOURCES}
    external/glad/src/glad.c
)

target_include_directories(Sentinel PRIVATE
    src
    external/glad/include
    external/glm
)

target_link_libraries(Sentinel PRIVATE
    glfw
)