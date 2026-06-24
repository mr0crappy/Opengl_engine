#include "texture.h"

#include <glad/glad.h>
#include <iostream>
#include <stb_image.h>


Texture::Texture(const std::string &filepath) {
  glGenTextures(1, &RendererID);
  glBindTexture(GL_TEXTURE_2D, RendererID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
                  GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  unsigned char *data =
      stbi_load(filepath.c_str(), &Width, &Height, &Channels, 0);

  if (data) {
    GLenum format = Channels == 4 ? GL_RGBA : GL_RGB;
    glTexImage2D(GL_TEXTURE_2D, 0, format, Width, Height, 0, GL_RGB,
                 GL_UNSIGNED_BYTE, data);

    glGenerateMipmap(GL_TEXTURE_2D);
  } else {
    std::cout << "Failed to load textures";
  }
  stbi_image_free(data);
}

Texture::~Texture() { glDeleteTextures(1, &RendererID); }

void Texture::Bind(unsigned int slot) const {
  glActiveTexture(GL_TEXTURE0 + slot);
  glBindTexture(GL_TEXTURE_2D, RendererID);
}

void Texture::Unbind() const { glBindTexture(GL_TEXTURE_2D, 0); }