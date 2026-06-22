#include "vertex_array.h"

#include <glad/glad.h>

VertexArray::VertexArray(){

    glGenVertexArrays(1, &RendererID);       
}

VertexArray::~VertexArray(){
    glDeleteVertexArrays(1, &RendererID);
}

void VertexArray::Bind() const{
    glBindVertexArray(RendererID);
}

void VertexArray::unBind() const{
    glBindVertexArray(0);
}

void VertexArray::AddAttribute(unsigned int index, int count, unsigned int type, bool normalized, int stride, const void* offset){
    glVertexAttribPointer(index, count, type, normalized?GL_TRUE:GL_FALSE, stride, offset);
    glEnableVertexAttribArray(index);
}