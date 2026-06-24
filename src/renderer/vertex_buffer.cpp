#include "vertex_buffer.h"

#include <glad/glad.h>

VertexBuffer::VertexBuffer(const void *data, unsigned int size) {

  // genertae an array buffer object
  glGenBuffers(1, &RendererID);
  glBindBuffer(GL_ARRAY_BUFFER, RendererID);

  // copy data to buffer memory
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

VertexBuffer::~VertexBuffer() { glDeleteBuffers(1, &RendererID); }

void VertexBuffer::Bind() const { glBindBuffer(GL_ARRAY_BUFFER, RendererID); }

void VertexBuffer::unBind() const { glBindBuffer(GL_ARRAY_BUFFER, 0); }