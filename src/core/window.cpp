#include "window.h"

#include <iostream>

Window::Window(int width, int height, const char *title) {
  glfwInit();

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  m_Window = glfwCreateWindow(width, height, title, nullptr, nullptr);

  glfwMakeContextCurrent(m_Window);

  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  glfwSetFramebufferSizeCallback(m_Window, FramebufferCallback);
}

Window::~Window() { glfwTerminate(); }

bool Window::ShouldClose() const { return glfwWindowShouldClose(m_Window); }

void Window::Update() {

  glfwSwapBuffers(m_Window);
  glfwPollEvents();
}

void Window::FramebufferCallback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}

GLFWwindow *Window::GetNativeWindow() const { return m_Window; }