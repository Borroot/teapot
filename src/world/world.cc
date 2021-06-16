#include <vector>
#include "world/mesh.hh"
#include "world/world.hh"

World::World(std::vector<Mesh> &meshes)
{
    this->meshes = meshes;
}