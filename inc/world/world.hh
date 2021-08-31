#pragma once

#include <tuple>
#include <vector>
#include "world/camera.hh"
#include "world/mesh.hh"

class World
{
public:
    std::vector<Mesh> meshes;
    Camera camera;

    World() = default;
    World(std::vector<Mesh> &, Camera &);
    World(const World &);
};