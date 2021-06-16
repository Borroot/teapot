#include <limits>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include "world/mesh.hh"

Mesh::Mesh(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("could not open file " + filename);

    char word;
    while (file >> word)
    {
        switch (word)
        {
        case 'v':
            double x, y, z;
            file >> x >> y >> z;
            this->vertices.push_back(*(new Vec4(x, y, z)));
            break;
        case 'f':
            int v0, v1, v2;
            file >> v0 >> v1 >> v2;
            this->triangles.push_back(*(new Triangle(&vertices[v0 - 1], &vertices[v1 - 1], &vertices[v2 - 1])));
            break;
        default:
            file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    file.close();
}