#pragma once

#include <vector>
#include <string>
#include "world/triangle.hh"

class Mesh
{
public:
    std::vector<Vec4> vertices;
    std::vector<Triangle> triangles;

    Mesh() {};
    Mesh(const std::string &);
};