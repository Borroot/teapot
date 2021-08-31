#include <vector>
#include <iostream>
#include "world/mesh.hh"
#include "world/world.hh"

World::World(std::vector<Mesh> &meshes, Camera &camera)
{
    this->meshes = meshes;
    this->camera = camera;
}

World::World(const World &world)
{
    this->camera = Camera(world.camera);
    for (Mesh mesh : world.meshes)
        this->meshes.push_back(Mesh(mesh));
}