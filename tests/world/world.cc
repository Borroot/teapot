#include <criterion/criterion.h>
#include <iostream>
#include "world/camera.hh"
#include "world/world.hh"

Test(World, constructor)
{
    Camera camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0));
    std::vector<Mesh> meshes = {};

    World world(meshes, camera);

    cr_assert_eq(world.camera.pos, camera.pos);
    cr_assert_eq(world.camera.forward, camera.forward);
    cr_assert_eq(world.camera.up, camera.up);
}
