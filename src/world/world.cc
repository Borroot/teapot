#include <vector>
#include "world/mesh.hh"
#include "world/world.hh"

World::World(std::vector<Mesh> &meshes)
{
    this->meshes = meshes;
}

World::World(const World &world)
{
    for (Mesh mesh : world.meshes)
        this->meshes.push_back(Mesh(mesh));
}