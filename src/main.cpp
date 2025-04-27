#include "glad/glad.h"
#include "shader.h"
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cmath>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

int main() {
  glfwInit(); // initialize glfw
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  // window object
  GLFWwindow *window =
      glfwCreateWindow(800, 600, "Opengl_Engine", NULL,
                       NULL); // declare the size and name of the window
  if (window == NULL) {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window); // Make window context the main context

  // Initialize GLAD
  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glViewport(0, 0, 800, 600); // initialize the size of rendering window

  glfwSetFramebufferSizeCallback(
      window,
      framebuffer_size_callback); // register the callback function for resizing

  Shader ourShader("shaders/shader.vs", "shaders/shader.fs");

  float vertices[] = {-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.5f,
                      -0.5f, 0.0f,  0.0f, 1.0f, 0.0f, 0.0f, 0.5f,
                      0.0f,  0.0f,  0.0f, 1.0f}; // normalized coords of a
                                                 // triangle
  unsigned int VBO, VAO; // vertex buffer object and vertex array object
  glGenVertexArrays(1, &VAO);
  glGenBuffers(1, &VBO);
  glBindVertexArray(VAO);             // bind VAO
  glBindBuffer(GL_ARRAY_BUFFER, VBO); // binding buffers
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
               GL_STATIC_DRAW); // copy the defined vertex data into buffer

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // Set vertex pointers attribute pointers
  glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                        (void *)(3 * sizeof(float)));
  glEnableVertexAttribArray(1);
  // render loop
  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    // render the triangle
    ourShader.use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(window); // swap color buffers
    glfwPollEvents;          // Check if events have triggers
  }

  glfwTerminate(); // Terminate glfw
  return 0;
}

// Processing key inputs
void processInput(GLFWwindow *window) {
  if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS) {
    std::cout << "ESC pressed\n";
    glfwSetWindowShouldClose(window, true);
  }
}

// For when the user resizes the window
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
  glViewport(0, 0, width, height);
}
