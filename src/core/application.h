#pragma once

#include "renderer/shader.h"
#include "renderer/vertex_array.h"
#include "renderer/vertex_buffer.h"


class Application
{
public:
    Application();
    ~Application();

    void Run();

private:
    VertexArray* VAO;
    VertexBuffer* VBO;
    Shader* shader;
};