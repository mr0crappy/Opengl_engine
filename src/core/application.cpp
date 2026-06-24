#include "application.h"
#include "input.h"
#include "utility/paths.h"
#include "window.h"
#include <filesystem>
#include <iostream>


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "ui/imgui_layer.h"
#include <imgui.h>

Application::Application() {}

Application::~Application() {}

void Application::Run() {
  Window window(1920, 1080, "Sentinel");

  camera.Attach(window.GetNativeWindow());

  glEnable(GL_DEPTH_TEST);

  float vertices[] = {
      // Front
      -0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.5f, 0.5f,
      0.5f, 1.0f, 1.0f, -0.5f, 0.5f, 0.5f, 0.0f, 1.0f,

      // Back
      -0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 0.5f,
      0.5f, -0.5f, 0.0f, 1.0f, -0.5f, 0.5f, -0.5f, 1.0f, 1.0f,

      // Left
      -0.5f, -0.5f, -0.5f, 0.0f, 0.0f, -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, -0.5f,
      0.5f, 0.5f, 1.0f, 1.0f, -0.5f, 0.5f, -0.5f, 0.0f, 1.0f,

      // Right
      0.5f, -0.5f, -0.5f, 1.0f, 0.0f, 0.5f, -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, 0.5f,
      0.5f, 0.0f, 1.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,

      // Top
      -0.5f, 0.5f, -0.5f, 0.0f, 1.0f, -0.5f, 0.5f, 0.5f, 0.0f, 0.0f, 0.5f, 0.5f,
      0.5f, 1.0f, 0.0f, 0.5f, 0.5f, -0.5f, 1.0f, 1.0f,

      // Bottom
      -0.5f, -0.5f, -0.5f, 1.0f, 1.0f, -0.5f, -0.5f, 0.5f, 1.0f, 0.0f, 0.5f,
      -0.5f, 0.5f, 0.0f, 0.0f, 0.5f, -0.5f, -0.5f, 0.0f, 1.0f};

  unsigned int indices[] = {// Front
                            0, 1, 2, 2, 3, 0,

                            // Back
                            4, 5, 6, 6, 7, 4,

                            // Left
                            8, 9, 10, 10, 11, 8,

                            // Right
                            12, 13, 14, 14, 15, 12,

                            // Top
                            16, 17, 18, 18, 19, 16,

                            // Bottom
                            20, 21, 22, 22, 23, 20};

  VAO = new VertexArray();
  VAO->Bind();

  VBO = new VertexBuffer(vertices, sizeof(vertices));

  EBO = new IndexBuffer(indices, 36);

  VAO->AddAttribute(0, 3, GL_FLOAT, false, 5 * sizeof(float), (void *)0);

  VAO->AddAttribute(1, 2, GL_FLOAT, false, 5 * sizeof(float),
                    (void *)(3 * sizeof(float)));

  shader = new Shader(std::string(ASSET_PATH) + "shaders/basic.vert",
                      std::string(ASSET_PATH) + "shaders/basic.frag");

  texture = new Texture(std::string(ASSET_PATH) + "textures/container.jpg");

  shader->Bind();
  shader->setInt("texture1", 0);

  ImGuiLayer imgui;
  imgui.Init(window.GetNativeWindow());

  ImGui::GetStyle().ScaleAllSizes(1.5f);

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

  while (!window.ShouldClose()) {
    float currentFrame = (float)glfwGetTime();

    deltaTime = currentFrame - lastFrame;

    lastFrame = currentFrame;

    Input::ProcessInput(window.GetNativeWindow());

    glm::vec3 camPos = camera.GetPosition();

    camera.SetSpeed(cameraSpeed);

    bool tabPressed =
        Input::IsKeyPressed(window.GetNativeWindow(), GLFW_KEY_TAB);

    if (tabPressed && !tabPressedLastFrame) {
      mouseCaptured = !mouseCaptured;

      glfwSetInputMode(window.GetNativeWindow(), GLFW_CURSOR,
                       mouseCaptured ? GLFW_CURSOR_DISABLED
                                     : GLFW_CURSOR_NORMAL);

      camera.SetMouseEnabled(mouseCaptured);

      camera.ResetMouse();
    }

    tabPressedLastFrame = tabPressed;

    if (mouseCaptured) {
      camera.Update(window.GetNativeWindow(), deltaTime);
    }

    imgui.Begin();

    ImGui::Begin("Sentinel");
    ImGui::SetNextWindowSize(ImVec2(450, 700), ImGuiCond_Once);

    ImGui::Checkbox("Wireframe", &wireframe);

    ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

    ImGui::Text("Renderer: OpenGL 4.6");

    ImGui::Separator();

    ImGui::SliderFloat3("Position", &position.x, -10.0f, 10.0f);

    ImGui::SliderFloat3("Rotation Axis", &rotationAxis.x, -1.0f, 1.0f);

    ImGui::SliderFloat("Rotation Speed", &rotationSpeed, 0.0f, 10.0f);

    ImGui::SliderFloat("FOV", &fov, 1.0f, 90.0f);

    ImGui::ColorEdit3("Clear Color", &clearColor.x);

    ImGui::SliderFloat("Camera Speed", &cameraSpeed, 0.1f, 20.0f);

    ImGui::Text("Camera Position");

    ImGui::Text("%.2f %.2f %.2f", camPos.x, camPos.y, camPos.z);

    ImGui::SliderFloat3("Scale", &scale.x, 0.1f, 5.0f);

    ImGui::End();

    glPolygonMode(GL_FRONT_AND_BACK, wireframe ? GL_LINE : GL_FILL);

    glClearColor(clearColor.r, clearColor.g, clearColor.b, 1.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 model(1.0f);

    model = glm::translate(model, position);

    model =
        glm::rotate(model, (float)glfwGetTime() * rotationSpeed, rotationAxis);

    model = glm::scale(model, scale);

    glm::mat4 view = camera.GetViewMatrix();

    glm::mat4 projection =
        glm::perspective(glm::radians(fov), aspectRatio, 0.1f, 100.0f);

    shader->Bind();

    shader->setMat4("model", model);

    shader->setMat4("view", view);

    shader->setMat4("projection", projection);

    texture->Bind();

    VAO->Bind();

    glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, nullptr);

    imgui.End();

    window.Update();
  }
}
