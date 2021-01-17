#include "Vertices.h"

#include <vector>

Vertices::Vertices()
{
    //ctor
}

Vertices::~Vertices()
{
    //dtor
}

void Vertices::AddVertex(std::vector<glm::vec3> vertex)
{
    vertices.push_back(vertex);
}


std::vector<std::vector<glm::vec3>> Vertices::GetVertices()
{
    return vertices;
}
