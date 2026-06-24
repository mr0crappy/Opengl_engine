#pragma once

#include "renderer/shader.h"
#include "renderer/vertex_array.h"
#include "renderer/vertex_buffer.h"
#include "renderer/index_buffer.h"
#include "renderer/texture.h"
#include "scene/camera.h"

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
    IndexBuffer* EBO;
    Texture* texture;
    bool wireframe = false;
    Camera camera;
};