#include "camera.h"

static Camera *s_Instance = nullptr;

Camera::Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(2.5f),
      MouseSensitivity(0.1f), Zoom(45.0f) {
  Position = position;
  WorldUp = up;
  Yaw = yaw;
  Pitch = pitch;

  UpdateCameraVectors();
}

glm::mat4 Camera::GetViewMatrix() const {
  return glm::lookAt(Position, Position + Front, Up);
}

void Camera::ProcessKeyboard(int direction, float deltaTime) {
  float velocity = MovementSpeed * deltaTime;

  if (direction == FORWARD)
    Position += Front * velocity;

  if (direction == BACKWARD)
    Position -= Front * velocity;

  if (direction == LEFT)
    Position -= Right * velocity;

  if (direction == RIGHT_MOVE)
    Position += Right * velocity;
}

void Camera::ProcessMouseMovement(float xOffset, float yOffset,
                                  bool constrainPitch) {
  xOffset *= MouseSensitivity;
  yOffset *= MouseSensitivity;

  Yaw += xOffset;
  Pitch += yOffset;

  if (constrainPitch) {
    if (Pitch > 89.0f)
      Pitch = 89.0f;

    if (Pitch < -89.0f)
      Pitch = -89.0f;
  }

  UpdateCameraVectors();
}

void Camera::ProcessMouseScroll(float yOffset) {
  Zoom -= yOffset;

  if (Zoom < 1.0f)
    Zoom = 1.0f;

  if (Zoom > 45.0f)
    Zoom = 45.0f;
}

float Camera::GetZoom() const { return Zoom; }

void Camera::UpdateCameraVectors() {
  glm::vec3 front;

  front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));

  front.y = sin(glm::radians(Pitch));

  front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));

  Front = glm::normalize(front);

  Right = glm::normalize(glm::cross(Front, WorldUp));

  Up = glm::normalize(glm::cross(Right, Front));
}

void Camera::MouseCallback(GLFWwindow *window, double xpos, double ypos) {
  if (!s_Instance)
    return;
  if (!s_Instance->MouseEnabled)
    return;
  if (s_Instance->FirstMouse) {
    s_Instance->LastX = (float)xpos;
    s_Instance->LastY = (float)ypos;
    s_Instance->FirstMouse = false;
  }

  float xOffset = (float)xpos - s_Instance->LastX;

  float yOffset = s_Instance->LastY - (float)ypos;

  s_Instance->LastX = (float)xpos;
  s_Instance->LastY = (float)ypos;

  s_Instance->ProcessMouseMovement(xOffset, yOffset);
}

void Camera::ScrollCallback(GLFWwindow *window, double xoffset,
                            double yoffset) {
  if (s_Instance) {
    s_Instance->ProcessMouseScroll((float)yoffset);
  }
}

void Camera::Attach(GLFWwindow *window) {
  s_Instance = this;

  glfwSetCursorPosCallback(window, Camera::MouseCallback);

  glfwSetScrollCallback(window, Camera::ScrollCallback);

  glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Camera::Update(GLFWwindow *window, float deltaTime) {
  if (glfwGetKey(window, GLFW_KEY_W))
    ProcessKeyboard(FORWARD, deltaTime);

  if (glfwGetKey(window, GLFW_KEY_S))
    ProcessKeyboard(BACKWARD, deltaTime);

  if (glfwGetKey(window, GLFW_KEY_A))
    ProcessKeyboard(LEFT, deltaTime);

  if (glfwGetKey(window, GLFW_KEY_D))
    ProcessKeyboard(RIGHT_MOVE, deltaTime);
}

void Camera::SetSpeed(float speed) { MovementSpeed = speed; }

glm::vec3 Camera::GetPosition() const { return Position; }

void Camera::ResetMouse() { FirstMouse = true; }

void Camera::SetMouseEnabled(bool enabled) { MouseEnabled = enabled; }