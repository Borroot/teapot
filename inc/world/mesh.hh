#pragma once

#include <vector>
#include <string>
#include "world/triangle.hh"

class Mesh
{
public:
    std::vector<Triangle> triangles;

    Mesh() = default;
    Mesh(const std::string &);
    Mesh(const Mesh &);
};