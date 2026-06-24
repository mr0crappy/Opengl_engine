# Sentinel Engine

Sentinel is a custom game engine written in C++ using Modern OpenGL. The project is being developed from the ground up as a learning-focused engine architecture with the long-term goal of supporting advanced rendering, physics, asset management, scene management, and editor tooling.

## Current Features

### Core

* C++17
* OpenGL 4.6 Core Profile
* GLFW window and context management
* GLAD OpenGL loader
* CMake build system

### Rendering

* Custom Shader abstraction
* Vertex Buffer Object (VBO) abstraction
* Vertex Array Object (VAO) abstraction
* Index Buffer Object (EBO) abstraction
* Texture loading and binding
* Model / View / Projection matrices
* Depth testing
* Wireframe rendering mode
* Textured cube rendering

### Camera

* FPS-style camera
* WASD movement
* Mouse look
* Scroll wheel zoom
* Delta-time based movement

### Editor

* Dear ImGui integration
* Real-time transform controls
* Position editing
* Rotation controls
* Scale controls
* FOV controls
* Camera speed controls
* Renderer settings panel
* Wireframe toggle
* Runtime statistics display
* Editor/Game mode switching

## Screenshots

Currently renders a textured 3D cube with:

* Free-look camera
* Real-time transform manipulation
* ImGui editor controls
* Perspective projection

## Building

### Requirements

* CMake 3.20+
* C++17 Compiler
* OpenGL 4.6
* GLFW
* GLAD
* Dear ImGui
* GLM

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


## Implemented Systems

### Shader

Responsible for:

* Reading shader files
* Compiling shaders
* Linking programs
* Uniform management

### VertexBuffer

Responsible for:

* GPU buffer allocation
* Vertex uploads
* Buffer binding

### VertexArray

Responsible for:

* Vertex layouts
* Attribute configuration
* Input state management

### IndexBuffer

Responsible for:

* Indexed rendering
* Element storage
* Draw call optimization

### Texture

Responsible for:

* Texture loading
* GPU texture creation
* Texture binding

### Camera

Responsible for:

* View matrix generation
* Mouse look
* Keyboard movement
* Zoom control

## Roadmap

### Renderer

* Multiple texture support
* Material system
* Mesh abstraction
* Asset browser
* Cube maps
* Skyboxes
* Lighting system
* Directional lights
* Point lights
* Spot lights
* Shadow mapping
* HDR rendering
* Deferred rendering
* Physically Based Rendering (PBR)

### Engine

* Scene system
* Entity Component System (ECS)
* Event system
* Asset manager
* Serialization
* Prefabs
* Resource hot-reloading

### Editor

* Scene hierarchy
* Inspector panel
* Asset browser
* Transform gizmos
* Docking layout
* Content browser
* Play mode
* Project settings

### Physics

* Collision detection
* Rigid body simulation
* Character controller
* Physics debug rendering

## Goals

Sentinel aims to evolve into a complete game engine while serving as a deep exploration of:

* Graphics Programming
* Engine Architecture
* Rendering Pipelines
* Physics Systems
* Tool Development
* Real-Time Rendering

## License

This project is currently under active development.
