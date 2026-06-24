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
    external/stb
    external/imgui
    external/imgui/backends
)

target_link_libraries(Sentinel PRIVATE
    glfw
)

set(IMGUI_SOURCES
    external/imgui/imgui.cpp
    external/imgui/imgui_draw.cpp
    external/imgui/imgui_tables.cpp
    external/imgui/imgui_widgets.cpp
    external/imgui/backends/imgui_impl_glfw.cpp
    external/imgui/backends/imgui_impl_opengl3.cpp
)

target_sources(Sentinel PRIVATE
    ${IMGUI_SOURCES}
)