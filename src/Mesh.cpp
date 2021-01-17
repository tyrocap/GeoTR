#include "Mesh.h"

#include <iostream>
#include <GL/glew.h>


Mesh::Mesh(float* vertices, unsigned int sizeOfArray)
{
    Init(vertices, sizeOfArray);
}


Mesh::~Mesh()
{
    glDeleteVertexArrays(1, &vertexArrayObj);
    glDeleteBuffers(1, &vertexBufferObj);
}

void Mesh::Init(float* vertices, unsigned int sizeOfVertices)
{

    // allocate memory on GPU & copy the data into it (VBO)
    // unsigned int vbo, vao;
    // set up vertex array obj (vao)
    glGenVertexArrays(1, &vertexArrayObj);
    glBindVertexArray(vertexArrayObj);

    // set up vertex buffer obj (vbo) (will be 'inside' vao)
    glGenBuffers(1, &vertexBufferObj);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObj);

    glBufferData(GL_ARRAY_BUFFER, sizeOfVertices, vertices, GL_STATIC_DRAW);
    // as of now, vertex data is in GPU memory handled by vbo object

    //TODO: add error checking

    // configure how OpenGL should interpret the memory
    // pos attrib
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0); // otherwise, vertex attribs are disabled by default

    // color attrib
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);
}



void Mesh::Draw()
{
    glBindVertexArray(vertexArrayObj);

    glDrawArrays(GL_LINES, 0, 2);
    glDrawArrays(GL_LINES, 2, 2); // vertical line

    // triangles
    glDrawArrays(GL_TRIANGLES, 4, 3);
    glDrawArrays(GL_TRIANGLES, 8, 3);

    // VAOs & VBOs can be unbound at this point if necessary
//    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}



