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
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  

    VAO = new VertexArray();
    VAO->Bind();

    VBO = new VertexBuffer(vertices, sizeof(vertices));
    
    EBO = new IndexBuffer(indices, 6);
    VAO->AddAttribute(0,3,GL_FLOAT,false,3 * sizeof(float),(void*)0);
    shader = new Shader(std::string(ASSET_PATH) + "shaders/basic.vert",std::string(ASSET_PATH) +"shaders/basic.frag");


    while (!window.ShouldClose())
    {
        
         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader->Bind();
        VAO->Bind();
        glDrawElements(GL_TRIANGLES, EBO->GetCount(), GL_UNSIGNED_INT, nullptr);
        window.Update();
    }
}