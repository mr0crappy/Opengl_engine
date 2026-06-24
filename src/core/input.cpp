#include "input.h"

void Input::ProcessInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    glfwSetWindowShouldClose(window, true);
}

bool Input::IsKeyPressed(GLFWwindow *window, int key) {
  return glfwGetKey(window, key) == GLFW_PRESS;
}