#pragma once

#include <vector>
#include <string>
#include "world/triangle.hh"

class mesh
{
public:
    std::vector<triangle> triangles;

    mesh(const std::string &);
};