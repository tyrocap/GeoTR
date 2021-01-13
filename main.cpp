#include <iostream>
#include <GL/glew.h>
#include <Display.h>
#include <Shader.h>

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

    //TODO: add error checking

    // vertex buffer (storage for vertex data)
    // vbo(vertex buffer obj - obj that can store vertices in GPU's memory)
    unsigned int vbo, vao;
    glGenBuffers(1, &vbo); // generate id
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // copy vertices data to buffer memory
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    //TODO: add error checking

    // pos attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // color attrib
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);


    glBindBuffer(GL_ARRAY_BUFFER, 0);

    while (!display.isClosed())
    {
        display.Clear(1.0f, 1.0f, 1.0f, 1.0f); // white background
        shader.Bind();

        glBindVertexArray(vao);

        glLineWidth(2);
        glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

        glDrawArrays(GL_LINES, 0, 2);
        glDrawArrays(GL_LINES, 2, 2); // vertical line

        // triangles
        glDrawArrays(GL_TRIANGLES, 4, 3);
        glDrawArrays(GL_TRIANGLES, 8, 3);

        display.Update();
    }

    return 0;
}
