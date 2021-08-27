#include <SFML/Graphics.hpp>
#include <math.h>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/render.hh"

Render::Render(int w, int h)
{
    this->proj = projection(w, h, 90, 1000, 0.1);
}

Mat4 Render::projection(int w, int h, double fov, double far, double near)
{
    double fovrad = 1 / tan(fov * 0.5 / 180.0 * M_PI);
    double aspect_ratio = (double)w / (double)h;

    double projection[4][4] = {
        {aspect_ratio * fovrad, 0, 0, 0},
        {0, fovrad, 0, 0},
        {0, 0, far / (far - near), (-far * near) / (far - near)},
        {0, 0, 1, 0}};

    return Mat4(projection);
}

void Render::render(World &world, Canvas &canvas)
{
    // Triangle triangle(Vec4(100, 50, 0), Vec4(200, 250, 0), Vec4(300, 150, 0));
    // triangle.draw(canvas, sf::Color::White, true, true);

    for (Mesh mesh : world.meshes) {
        for (Triangle triangle : mesh.triangles) {
            Vec3 v0 = (Vec3)(triangle.v0 * this->proj);
            Vec3 v1 = (Vec3)(triangle.v1 * this->proj);
            Vec3 v2 = (Vec3)(triangle.v2 * this->proj);

            canvas.set(v0.x + 50, v0.y + 50, sf::Color::White);
            canvas.set(v1.x + 50, v1.y + 50, sf::Color::White);
            canvas.set(v2.x + 50, v2.y + 50, sf::Color::White);
        }
    }
}