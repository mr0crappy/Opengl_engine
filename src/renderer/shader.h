#pragma once

#include <string>

class Shader{
    public:
        Shader(const std::string& vertexPath, const std::string& fragmentPath);
        ~Shader();

        void Bind() const;
        void unBind() const;

        void setBool(const std::string &name, bool value) const;
        void setInt(const std::string &name, int value) const;
        void setFloat(const std::string &name, float value) const;

    private:
        unsigned int RendererID;

        std::string ReadFile(const std::string& filePath);
        unsigned int CompileShader(unsigned int type, const std::string& source);
        void CheckCompileErrors(unsigned int object, const std::string& type);

};