#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include "math/vector3.hh"
#include "render/line.hh"
#include "render/process.hh"
#include "render/render.hh"

static Mat4 projection_matrix(int w, int h, double fov, double far, double near)
{
    double fovrad = 1 / tan(fov * 0.5 / 180.0 * M_PI);
    double aspect_ratio = (double)h / (double)w;

    double projection[4][4] = {
        {aspect_ratio * fovrad, 0, 0, 0},
        {0, fovrad, 0, 0},
        {0, 0, far / (far - near), (-far * near) / (far - near)},
        {0, 0, 1, 0}};

    return Mat4(projection);
}

static Mat4 screen_matrix(int w, int h)
{
    return Mat4::scale(w / 2, h / 2, 1) * Mat4::translate(1, 1, 0);
}

Render::Render(int w, int h)
{
    this->projection = projection_matrix(w, h, 90, this->far, this->near);
    this->screen = screen_matrix(w, h);
}

void Render::render(const World &world, Canvas &canvas)
{
    Camera camera = world.camera;
    std::list<Triangle> triangles;

    populate(world, triangles);
    backface_culling(triangles, camera.pos);
    shade(triangles);
    painters_algorithm(triangles, camera.pos);
    apply_matrix(triangles, camera.view_matrix());
    clip_farnear(triangles, this->far, this->near);
    apply_matrix(triangles, this->projection);
    clip_properly(triangles);
    apply_matrix(triangles, this->screen);
    draw(triangles, canvas);

    // std::cout << triangles.size() << std::endl;
}