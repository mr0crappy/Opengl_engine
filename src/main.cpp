#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

// Vertex Shader code
const char *vertexShaderSource =
    "#version 330 core\n"
    "layout (location=0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

// Fragment Shader code
const char *fragmentShaderSource =
    "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

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

  float vertices[] = {
      -0.5f, -0.5f, 0.0f, 0.5f, -0.5f,
      0.0f,  0.0f,  0.5f, 0.0f}; // normalized coords of a triangle

  unsigned int VBO; // vertex buffer object
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO); // binding buffers
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,
               GL_STATIC_DRAW); // copy the defined vertex data into buffer

  // Vertex Shader Creation
  unsigned int vertexShader;                       // shader object
  vertexShader = glCreateShader(GL_VERTEX_SHADER); // Create a vertex shader
  glShaderSource(vertexShader, 1, &vertexShaderSource,
                 NULL);          // Attach shader source code to shader object
  glCompileShader(vertexShader); // Compile the shader
  // Check compilation success
  int success;
  char infoLog[512]; // Store error messages
  glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
    std::cout << "Error::shader::vertex::compilation_failed\n"
              << infoLog << std::endl;
  }

  // Fragment Shader Creation
  unsigned int fragmentShader;
  fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
  glCompileShader(fragmentShader);
  glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
  if (!success) {
    glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
    std::cout << "Error::shader::fragment::compilation_failed\n"
              << infoLog << std::endl;
  }

  // LinkingShader
  unsigned int shaderProgram;
  shaderProgram = glCreateProgram();
  glAttachShader(shaderProgram, vertexShader);
  glAttachShader(shaderProgram, fragmentShader);
  glLinkProgram(shaderProgram);
  glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
  if (!success) {
    glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
    std::cout << "Eroor::shader::program::linking_failed\n"
              << infoLog << std::endl;
  }

  // Activate the program
  glUseProgram(shaderProgram);
  // delete the shaders after linking
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  // Linking vertex attributes
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);

  unsigned int VAO;
  glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
  // Enable the vertex attribute
  glBindBuffer(GL_ARRAY_BUFFER, VBO); // copy vertices in an array
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
  // Set vertex pointers attribute pointers
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
  glEnableVertexAttribArray(0);
  // render loop
  while (!glfwWindowShouldClose(window)) {
    processInput(window);

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
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
