#pragma once

#include "window.h"
#include "renderer/shader.h"
#include "renderer/vertex_array.h"
#include "renderer/vertex_buffer.h"
#include "renderer/index_buffer.h"
#include "renderer/texture.h"
#include "scene/camera.h"
#include "input.h"
#include "utility/paths.h"

#include <filesystem>
#include <iostream>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ui/imgui_layer.h"
#include <imgui.h>

class Application
{
public:
    Application();
    ~Application();
    

    void Run();

private:
    VertexArray* VAO;
    VertexBuffer* VBO;
    Shader* shader;
    IndexBuffer* EBO;
    Texture* texture;
    bool wireframe = false;
    Camera camera;
    Window window;
    ImGuiLayer imgui;

    void Init();
    void InitRenderer();
    void InitScene();
    void InitUi();

    void Update();
    void Render();

    void Shutdown();

    void CalculateDeltaTime();
    void ProcessInput();
    void UpdateCamera();
    void DrawInspector();


    float deltaTime = 0.0f;
  float lastFrame = 0.0f;

  float aspectRatio = 1920.0f / 1080.0f;

  float rotationSpeed = 1.0f;

  glm::vec3 position = {0.5f, -0.5f, 0.0f};

  glm::vec3 rotationAxis = {0.0f, 0.0f, 1.0f};

  float fov = 45.0f;

  glm::vec3 clearColor = {0.2f, 0.3f, 0.3f};

  float cameraSpeed = 2.5f;

  bool mouseCaptured = true;
  bool tabPressedLastFrame = false;

  glm::vec3 scale = {1.0f, 1.0f, 1.0f};
  glm::vec3 camPos;
};