#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window(int width, int height, const char* title);
    ~Window();

    bool ShouldClose() const;
    void Update();

private:
    GLFWwindow* m_Window;

    static void FramebufferCallback(
        GLFWwindow* window,
        int width,
        int height);
};