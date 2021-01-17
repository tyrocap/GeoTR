#include "Shader.h"

#include <GL/glew.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


struct ShaderProgramSource
{
    std::string VertexShaderSource;
    std::string FragmentShaderSource;
};

static ShaderProgramSource ParseShader(const std::string& filePath);
static unsigned int CreateShader(const std::string& text, unsigned int shaderType);
static void CheckShaderError(unsigned int shader, unsigned int flag, bool isProgram, const std::string& errorMessage);

Shader::Shader(const std::string& filePath)
{
    programId = glCreateProgram();

    enum ShaderType
    {
        VERTEX = 0, FRAGMENT = 1
    };

    ShaderProgramSource source = ParseShader(filePath);

    listOfShaderIds[(int)ShaderType::VERTEX] = CreateShader(source.VertexShaderSource, GL_VERTEX_SHADER);
    listOfShaderIds[(int)ShaderType::FRAGMENT] = CreateShader(source.FragmentShaderSource, GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; ++i)
    {
        glAttachShader(programId, listOfShaderIds[i]);
    }

    // glBindAttribLocation(programId, ...);

    glLinkProgram(programId);
    CheckShaderError(programId, GL_LINK_STATUS, true, "Error: Program linking failed: ");

    glValidateProgram(programId);
    CheckShaderError(programId, GL_VALIDATE_STATUS, true, "Error: Program is invalid: ");

}

Shader::~Shader()
{
    for (unsigned int i = 0; i < NUM_SHADERS; ++i)
    {
        glDetachShader(programId, listOfShaderIds[i]);
        glDeleteShader(listOfShaderIds[i]);
    }
    glDeleteProgram(programId);
}

void Shader::Bind()
{
    glUseProgram(programId);
    unsigned int attLoc = glGetAttribLocation(programId, "glFragColor");
}

static unsigned int CreateShader(const std::string& source, unsigned int shaderType)
{
    unsigned int shaderId = glCreateShader(shaderType);
    const char* src = source.c_str();
    glShaderSource(shaderId, 1, &src, nullptr);
    glCompileShader(shaderId);

    return shaderId;
}


static ShaderProgramSource ParseShader(const std::string& filePath)
{
    std::ifstream stream(filePath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;


    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
            {
                type = ShaderType::VERTEX;
            }
            else if (line.find("fragment") != std::string::npos)
            {
                type = ShaderType::FRAGMENT;
            }
        }
        else
        {
            ss[(int)type] << line << "\n";
        }
    }

    return { ss[0].str(), ss[1].str() };
}


void CheckShaderError(unsigned int shader, unsigned int flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if(isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if(success == GL_FALSE)
    {
        if(isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        std::cerr << errorMessage << ": '" << error << "'" << std::endl;
    }
}