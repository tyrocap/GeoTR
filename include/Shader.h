#ifndef SHADER_H
#define SHADER_H

#include <string>

class Shader
{
    public:
        Shader(const std::string& filePath);

        void Bind();

        virtual ~Shader();

    protected:


    private:
        static const unsigned int NUM_SHADERS = 2; // vertex & fragment
        unsigned int programId;
        unsigned int listOfShaderIds[NUM_SHADERS];
};

#endif // SHADER_H
