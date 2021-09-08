#include <algorithm>
#include <iostream>
#include <list>
#include <math.h>
#include "math/vector3.hh"
#include "render/clipping.hh"
#include "render/line.hh"
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
    return Mat4::scale(w / 2 - 0.5, h / 2 - 0.5, 1) * Mat4::translate(1, 1, 0);
}

Render::Render(int w, int h)
{
    this->projection = projection_matrix(w, h, 90, this->far, this->near);
    this->screen = screen_matrix(w, h);
}

void Render::render(const World &world, Canvas &canvas)
{
    Vec3 light = Vec3(0.3, 0.5, -1).normalize();
    Camera camera = world.camera;
    std::list<Triangle> ts;

    for (Mesh m : world.meshes) for (Triangle t : m.triangles) ts.push_back(t);  // populate
    ts.remove_if([&](Triangle &t) { return (t.v0 - camera.pos) * t.normal() >= 0; });  // backface culling

    for (Triangle &t : ts) {
        double shade = light * t.normal() * 0xFF;
        t.color = sf::Color(shade, shade, shade, 0xFF);
    }  // apply shading

    ts.sort([&](Triangle &t1, Triangle &t2) {
        double av1 = (Vec3::dist_fast(t1.v0, camera.pos) + Vec3::dist_fast(t1.v1, camera.pos) + Vec3::dist_fast(t1.v2, camera.pos)) / 3;
        double av2 = (Vec3::dist_fast(t2.v0, camera.pos) + Vec3::dist_fast(t2.v1, camera.pos) + Vec3::dist_fast(t2.v2, camera.pos)) / 3;
        return av1 > av2; });  // painter's algorithm

    for (Triangle &t : ts) camera.view_matrix() * t;  // view space
    clip_farnear(ts, this->far, this->near);  // clip behind camera and far away

    for (Triangle &t : ts) this->projection * t;  // projection space
    clip_frustum(ts, canvas.w, canvas.h);  // clip on viewing frustum edges

    for (Triangle &t : ts) this->screen * t;  // screen space
    for (Triangle &t : ts) t.draw(canvas, true, false);
}