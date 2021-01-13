#include <iostream>
#include <GL/glew.h>
#include <Display.h>
#include <Shader.h>
#include <Mesh.h>

#define WIDTH 800
#define HEIGHT 600

using namespace std;

int main()
{
    Display display(900, 800, "Hello World");
    Shader shader("./res/basic.shader");

    float vertices[] = {
         0.0f, -1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         0.0f,  1.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         1.0f,  0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         -1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
         -0.3f, -0.3f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.3f,  -0.3f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.0f,  0.3f, 0.0f, 1.0f, 0.0f, 0.0f,
         -0.3f, -0.3f, 0.0f, 1.0f, 0.0f, 0.0f,
         0.0f, 0.5f, 0.0f, 0.5f, 1.0f, 0.0f,
         -0.1f,-0.1f, 0.0f, 0.5f, 1.0f, 0.0f,
         0.5f, 0.0f, 0.0f, 0.5f, 1.0f, 0.0f,
    };
    Mesh mesh(vertices, sizeof(vertices));

    while (!display.isClosed())
    {
        display.Clear(1.0f, 1.0f, 1.0f, 1.0f); // white background
        shader.Bind();

        glLineWidth(2);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);



        mesh.Draw();
        display.Update();
    }

    return 0;
}
