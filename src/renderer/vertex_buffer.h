#pragma once

class VertexBuffer{
    public:
        VertexBuffer(const void* data, unsigned int size);
        ~VertexBuffer();

        void Bind() const;
        void unBind() const;
    
    private:
        unsigned int RendererID;
};