#pragma once

#include <vector>
#include "world/mesh.hh"

class World
{
public:
    std::vector<Mesh> meshes;

    World(std::vector<Mesh> &);
    World(const World &);
};