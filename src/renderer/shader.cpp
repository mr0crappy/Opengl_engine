#include "shader.h"

#include <glad/glad.h>
#include <fstream>
#include <sstream>
#include <iostream>

Shader::Shader(const std::string &vertexPath, const std::string &fragmentPath)
{
    std::string vertexCode = ReadFile(vertexPath);
    std::string fragmentCode = ReadFile(fragmentPath);

    std::cout << vertexCode << std::endl;
std::cout << fragmentCode << std::endl;

    unsigned int vertex = CompileShader(GL_VERTEX_SHADER, vertexCode);
    unsigned int fragment = CompileShader(GL_FRAGMENT_SHADER, fragmentCode);

    RendererID = glCreateProgram();

    glAttachShader(RendererID, vertex);
    glAttachShader(RendererID, fragment);

    glLinkProgram(RendererID);

    CheckCompileErrors(RendererID, "PROGRAM");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Shader::Bind() const
{
    glUseProgram(RendererID);
}

void Shader::unBind() const
{
    glUseProgram(0);
}

void Shader::setFloat(const std::string &name, float value) const
{
    glUniform1i(glGetUniformLocation(RendererID, name.c_str()), value);
}

void Shader::setBool(const std::string &name, bool value) const
{
    glUniform1i(glGetUniformLocation(RendererID, name.c_str()), (int)value);
}

void Shader::setInt(const std::string &name, int value) const
{
    glUniform1i(glGetUniformLocation(RendererID, name.c_str()), value);
}

std::string Shader::ReadFile(const std::string &filepath)
{
    std::ifstream file(filepath);

    if (!file.is_open())
    {
        std::cerr << "Failed to open shader file: " << filepath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();

    file.close();
    return buffer.str();
}

unsigned int Shader::CompileShader(unsigned int type, const std::string &source)
{
    unsigned int shader = glCreateShader(type);
    const char *src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);
    glCompileShader(shader);

    CheckCompileErrors(
        shader,
        type == GL_VERTEX_SHADER? "VERTEX" : "FRAGMENT");

    return shader;
}

void Shader::CheckCompileErrors(unsigned int object, const std::string& type){
    int success;
    char infoLog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(
            object,
            GL_COMPILE_STATUS,
            &success);

        if (!success)
        {
            glGetShaderInfoLog(
                object,
                1024,
                nullptr,
                infoLog);

            std::cerr
                << "ERROR::SHADER::"
                << type
                << "::COMPILATION_FAILED\n"
                << infoLog
                << std::endl;
        }
    }
    else
    {
        glGetProgramiv(
            object,
            GL_LINK_STATUS,
            &success);

        if (!success)
        {
            glGetProgramInfoLog(
                object,
                1024,
                nullptr,
                infoLog);

            std::cerr
                << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                << infoLog
                << std::endl;
        }
    }
}