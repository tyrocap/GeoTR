#ifndef MESH_H
#define MESH_H


class Mesh
{
    public:
        Mesh(float* vertices, unsigned int sizeOfVertices);

        void Draw();


        virtual ~Mesh();

    protected:

    private:
        void Init(float* vertices, unsigned int sizeOfVertices);
        unsigned int vertexArrayObj;
        unsigned int vertexBufferObj;

};

#endif // MESH_H
