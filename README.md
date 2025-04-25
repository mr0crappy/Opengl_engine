# OpenGL Engine (WIP)

Welcome to **OpenGL Engine**, a lightweight custom rendering engine built using **GLFW**, **GLAD**, and **modern OpenGL (3.3+)**. This project is built from scratch on **Linux (Arch)**, aiming to explore graphics programming, low-level rendering pipelines, and future AI/ML integration.

## Features (In Progress)

- ✅ OpenGL context setup (GLFW + GLAD)
- ✅ Shader loading and compilation
- ✅ Basic triangle rendering

## Build Instructions

### Dependencies
- CMake (>= 3.20)
- GCC or Clang
- GLFW
- GLAD
- OpenGL-compatible GPU & drivers

>  Make sure `glfw` and `glad` are properly included in your `include/` and `src/` folders.

### Build (Using CMake Presets)

```bash
# For Debug Build
cmake --preset debug
cmake --build --preset app-debug

# For Release Build (Not yet implemented)
cmake --preset release
cmake --build --preset release
```

### ▶️ Run the Project

```bash
# Example (Debug mode)
./build/debug/opengl_project
```

##  Screenshots

> (Coming soon: screenshots of triangle rendering and future demos)



