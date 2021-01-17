#ifndef MESH_H
#define MESH_H

#include <vector>

class Mesh
{
    public:

        Mesh(float* vertices, unsigned int sizeOfArray);


        void Draw();

        virtual ~Mesh();

    protected:

    private:
        void Init(float* vertices, unsigned int sizeOfVertices);
        unsigned int vertexArrayObj;
        unsigned int vertexBufferObj;


};



#endif // MESH_H
