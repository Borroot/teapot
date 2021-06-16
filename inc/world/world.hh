#pragma once

#include <vector>
#include "world/mesh.hh"

class World
{
private:
    std::vector<Mesh> meshes;

public:
    World(std::vector<Mesh> &);
};