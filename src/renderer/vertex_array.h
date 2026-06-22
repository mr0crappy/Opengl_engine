#pragma once

class VertexArray{
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void unBind() const;

        void AddAttribute(unsigned int index, int count, unsigned int type, bool normalized, int stride, const void* offset);
    
    private:
        unsigned int RendererID;
};