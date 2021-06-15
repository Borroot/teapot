#include <limits>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "world/mesh.hh"

mesh::mesh(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("could not open file " + filename);

    std::vector<vec3> vertices;
    char word;
    while (file >> word)
    {
        switch (word)
        {
        case 'v':
            double x, y, z;
            file >> x >> y >> z;
            vertices.push_back(*(new vec3(x, y, z)));
            break;
        case 'f':
            int v1, v2, v3;
            file >> v1 >> v2 >> v3;
            this->triangles.push_back(*(new triangle(vertices[v1 - 1], vertices[v2 - 1], vertices[v3 - 1])));
            break;
        default:
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    file.close();
}