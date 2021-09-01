#include <algorithm>
#include <math.h>
#include "math/vector3.hh"
#include "render/line.hh"
#include "render/render.hh"

Render::Render(int w, int h)
{
    this->projection = projection_matrix(w, h, 90, 1000, 0.1);
    this->screen = screen_matrix(w, h);
}

Mat4 Render::projection_matrix(int w, int h, double fov, double far, double near)
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

Mat4 Render::screen_matrix(int w, int h)
{
    return Mat4::scale(w / 2, h / 2, 1) * Mat4::translate(1, 1, 0);
}

void Render::list(const World &world, std::vector<Triangle> &triangles)
{
    for (Mesh mesh : world.meshes)
        for (Triangle triangle : mesh.triangles)
            triangles.push_back(triangle);
}

void Render::sort(std::vector<Triangle> &triangles, const Vec3 &ref)
{
    std::sort(triangles.begin(), triangles.end(), [&](Triangle t1, Triangle t2) {
        double average1 = (Vec3::dist_fast(t1.v0, ref) + Vec3::dist_fast(t1.v1, ref) + Vec3::dist_fast(t1.v2, ref)) / 3;
        double average2 = (Vec3::dist_fast(t2.v0, ref) + Vec3::dist_fast(t2.v1, ref) + Vec3::dist_fast(t2.v2, ref)) / 3;
        return average1 > average2;
    });  // painter's algorithm
}

void Render::render(const World &world, Canvas &canvas)
{
    Vec3 light = Vec3(-1, 1, -1).normalize();
    Camera camera = world.camera;
    Mat4 viewport = camera.viewport();

    std::vector<Triangle> triangles;
    list(world, triangles);
    sort(triangles, camera.pos);

    for (Triangle triangle : triangles)
    {
        if ((triangle.v0 - camera.pos) * triangle.normal() < 0)  // backface culling
        {
            double shade = light * triangle.normal();
            sf::Color color = sf::Color(shade * 255, shade * 255, shade * 255, 255);

            this->screen * this->projection * viewport * triangle;
            triangle.draw(canvas, color, true, false);
        }
    }
}