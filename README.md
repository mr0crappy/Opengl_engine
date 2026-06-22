# Sentinel Engine

Sentinel is a custom game engine written in C++ using modern OpenGL. The project is being developed from the ground up as a learning-focused engine architecture with the long-term goal of supporting advanced rendering, physics, asset management, and game development systems.

## Current Features

* OpenGL 4.6 Core Profile
* GLFW window and context management
* GLAD OpenGL loader
* Custom Shader abstraction
* Custom Vertex Buffer (VBO) abstraction
* Custom Vertex Array (VAO) abstraction
* CMake build system
* Basic rendering pipeline



## Building

### Requirements

* CMake 3.20+
* C++17 Compiler
* OpenGL 4.6
* GLFW
* GLAD

### Configure

```bash
cmake -B build
```

### Build

```bash
cmake --build build
```

### Run

```bash
./build/Sentinel
```

## Architecture

The current renderer is built around three core abstractions:

### Shader

Responsible for:

* Loading shader files
* Compiling shaders
* Linking shader programs
* Managing uniforms

### VertexBuffer

Wrapper around OpenGL Vertex Buffer Objects (VBOs).

Responsible for:

* Creating GPU vertex buffers
* Uploading vertex data
* Binding and unbinding buffers

### VertexArray

Wrapper around OpenGL Vertex Array Objects (VAOs).

Responsible for:

* Storing vertex attribute layouts
* Associating VBOs with shader attributes
* Managing vertex input state

## Roadmap

* Add a new camera system
* Load models
* A full Raytracer

### Renderer

* Index Buffers (EBO)
* Texture System
* Camera System
* Transformations
* Model Loading
* Lighting
* Shadow Mapping
* Deferred Rendering
* Physically Based Rendering (PBR)

### Engine

* Asset Manager
* Scene System
* Entity Component System (ECS)
* Input System
* Event System
* Serialization
* Editor

### Physics

* Collision Detection
* Rigid Body Simulation
* Character Controller

## Goals

Sentinel is intended to evolve into a fully featured game engine while serving as a deep exploration of graphics programming, engine architecture, and low-level systems development.

## License

This project is currently under active development.
