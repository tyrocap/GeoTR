#ifndef VERTICES_H
#define VERTICES_H

#include <vector>
#include <glm/glm.hpp>

class Vertices
{
    public:
        Vertices();
        virtual ~Vertices();

        void AddVertex(std::vector<glm::vec3> vertex);
        std::vector<std::vector<glm::vec3>> GetVertices();

    protected:

    private:
        std::vector<std::vector<glm::vec3>> vertices;

};

#endif // VERTICES_H
