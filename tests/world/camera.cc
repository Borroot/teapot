#include <criterion/criterion.h>
#include "math/vector3.hh"
#include "world/camera.hh"

Test(Camera, constructor)
{
    Camera camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0));
    cr_assert_eq(camera.pos, Vec3(0, 0, 0));
    cr_assert_eq(camera.forward, Vec3(0, 0, 1));
    cr_assert_eq(camera.up, Vec3(0, 1, 0));
}

Test(Camera, constructor_copy)
{
    Camera camera(Vec3(0, 0, 0), Vec3(0, 0, 1), Vec3(0, 1, 0));
    Camera copy1 = Camera(camera);

    cr_assert_eq(copy1.pos, camera.pos);
    cr_assert_eq(copy1.forward, camera.forward);
    cr_assert_eq(copy1.up, camera.up);

    Camera copy2 = camera;

    cr_assert_eq(copy2.pos, camera.pos);
    cr_assert_eq(copy2.forward, camera.forward);
    cr_assert_eq(copy2.up, camera.up);

    Camera copy3;
    copy3 = Camera(camera);

    cr_assert_eq(copy3.pos, camera.pos);
    cr_assert_eq(copy3.forward, camera.forward);
    cr_assert_eq(copy3.up, camera.up);
}