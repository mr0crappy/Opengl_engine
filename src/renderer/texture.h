#pragma once

#include <string>

class Texture {
public:
  Texture(const std::string &filepath);
  ~Texture();

  void Bind(unsigned int slot = 0) const;
  void Unbind() const;

private:
  unsigned int RendererID;

  int Width;
  int Height;
  int Channels;
};