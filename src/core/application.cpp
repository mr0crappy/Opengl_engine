#include "application.h"
#include "window.h"
#include "utility/paths.h"
#include <filesystem>
#include <iostream>

Application::Application()
{
}

Application::~Application()
{
}

void Application::Run()
{
    Window window(1024, 768, "Sentinel");

    

    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    } ;

    VAO = new VertexArray();
    VAO->Bind();

    VBO = new VertexBuffer(vertices, sizeof(vertices));
    VAO->AddAttribute(0,3,GL_FLOAT, false, 3*sizeof(float), (void*)0);

    shader = new Shader(std::string(ASSET_PATH) + "shaders/basic.vert",std::string(ASSET_PATH) +"shaders/basic.frag");


    while (!window.ShouldClose())
    {
        
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->Bind();
        VAO->Bind();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        window.Update();
    }
}