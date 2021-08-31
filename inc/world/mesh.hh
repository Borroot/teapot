#pragma once

#include <vector>
#include <string>
#include "world/triangle.hh"

class Mesh
{
public:
    std::vector<Triangle> triangles;
    // TODO add world space position for rotation around origin

    Mesh() = default;
    Mesh(const std::string &);
    Mesh(const Mesh &);
};