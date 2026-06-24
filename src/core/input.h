#pragma once

#include <glfw/glfw3.h>

class Input {
public:
  static void ProcessInput(GLFWwindow *window);

  static bool IsKeyPressed(GLFWwindow *window, int key);
};