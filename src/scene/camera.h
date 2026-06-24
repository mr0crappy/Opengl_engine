#pragma once

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


class Camera {
public:
  Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 3.0f),
         glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = -90.0f,
         float pitch = 0.0f);
  glm::mat4 GetViewMatrix() const;

  void ProcessKeyboard(int direction, float deltaTime);

  void ProcessMouseMovement(float xOffset, float yOffset,
                            bool constrainPitch = true);

  void ProcessMouseScroll(float yOffset);

  float GetZoom() const;

  void Attach(GLFWwindow *window);
  void Update(GLFWwindow *window, float deltaTime);

  void SetSpeed(float speed);

  glm::vec3 GetPosition() const;

  void ResetMouse();
  void SetMouseEnabled(bool enabled);

private:
  static void MouseCallback(GLFWwindow *window, double xpos, double ypos);

  static void ScrollCallback(GLFWwindow *window, double xoffset,
                             double yoffset);
  void UpdateCameraVectors();
  glm::vec3 Position;
  glm::vec3 Front;
  glm::vec3 Up;
  glm::vec3 Right;
  glm::vec3 WorldUp;

  float Yaw;
  float Pitch;

  float MovementSpeed;
  float MouseSensitivity;
  float Zoom;

  float LastX = 512.0f;
  float LastY = 384.0f;
  bool FirstMouse = true;
  bool mouseCaptured = true;
  bool MouseEnabled = true;
};

enum CameraMovement { FORWARD, BACKWARD, LEFT, RIGHT_MOVE };