#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/matrix.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/render.hh"

Render::Render(int w, int h)
{
    this->proj = projection(w, h, 90, 1000, 0.1);
    this->viewport = Mat4::scale(w / 2, h / 2, 1);
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

    Mat4 trans = Mat4::translate(2, 2, 2);
    Mat4 scale = Mat4::scale(0.5, 0.5, 0.5);

    for (Mesh mesh : world.meshes)
    {
        for (Triangle triangle : mesh.triangles)
        {
            std::cout << triangle.v0 << trans * triangle.v0 << scale * trans * triangle.v0 << std::endl;

            // Vec3 v0 = (Vec3)(this->viewport * this->proj * scale * (trans * triangle.v0));
            // Vec3 v1 = (Vec3)(this->viewport * this->proj * scale * (trans * triangle.v2));
            // Vec3 v2 = (Vec3)(this->viewport * this->proj * scale * (trans * triangle.v1));
            Vec3 v0 = (Vec3)(this->viewport * scale * trans * triangle.v0);
            Vec3 v1 = (Vec3)(this->viewport * scale * trans * triangle.v2);
            Vec3 v2 = (Vec3)(this->viewport * scale * trans * triangle.v1);

            canvas.set(v0.x, v0.y, sf::Color::White);
            canvas.set(v1.x, v1.y, sf::Color::White);
            canvas.set(v2.x, v2.y, sf::Color::White);

            std::cout << std::endl;
        }
    }
}