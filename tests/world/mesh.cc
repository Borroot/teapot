#include <criterion/criterion.h>
#include "world/mesh.hh"

Test(Mesh, file)
{
    cr_assert_throw(Mesh(""), std::runtime_error);

    Mesh cube("tests/world/cube.obj");

    cr_assert_eq(cube.triangles.size(), 12);
}

Test(Triangle, pointers)
{
    Mesh cube("tests/world/cube.obj");

    cr_assert_eq(cube.triangles[0].v1.x, 1);
    cr_assert_eq(cube.triangles[1].v0.x, 1);
    cube.triangles[0].v1.x = 0;
    cr_assert_eq(cube.triangles[0].v1.x, 0);
    cr_assert_eq(cube.triangles[1].v0.x, 1);
}

Test(Mesh, copy)
{
    Mesh cube("tests/world/cube.obj");
    Mesh copy(cube);

    copy.triangles[0].v0.x = 1;
    cr_assert_eq(cube.triangles[0].v0.x, -1);
}