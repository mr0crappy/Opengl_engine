cmake_minimum_required(VERSION 3.22.0)

project(opengl_engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES src/*.cpp src/*.c)

find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

add_executable(opengl_project ${SOURCES})
target_link_libraries(opengl_project PRIVATE glfw OpenGL::GL)

set_target_properties(opengl_project PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/debug
    RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release
)
