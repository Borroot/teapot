#include "world/world.hh"

World::World(std::vector<Mesh> &meshes, Camera &camera)
{
    this->meshes = meshes;
    this->camera = camera;
}