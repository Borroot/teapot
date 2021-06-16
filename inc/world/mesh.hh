#pragma once

#include <vector>
#include <string>
#include "world/triangle.hh"

class mesh
{
public:
    std::vector<vec4> vertices;
    std::vector<triangle> triangles;

    mesh() {};
    mesh(const std::string &);
};