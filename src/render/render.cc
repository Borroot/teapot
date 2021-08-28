#include <SFML/Graphics.hpp>
#include <iostream>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/matrix.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/render.hh"

Render::Render(int w, int h)
{
    this->projection = Mat4::projection(w, h, 90, 1000, 0.1);
    this->viewport = Mat4::viewport(w, h);
}

void Render::render(World &world, Canvas &canvas)
{
    Vec3 light = Vec3(0, 0, -1).normalize();
    Vec3 camera = Vec3(0, 0, 0);
    Mat4 transz = Mat4::translate(0, 0, 5);

    for (Mesh mesh : world.meshes)
    {
        for (Triangle triangle : mesh.triangles)
        {
            transz * triangle;
            Vec3 normal = triangle.normal();
            if ((triangle.v0 - camera) * normal < 0)  // backface culling
            {
                double shade = light * normal;
                sf::Color color = sf::Color(shade * 255, shade * 255, shade * 255, 255);

                this->viewport * this->projection * triangle;
                triangle.draw(canvas, color, true, false);
            }
        }
    }
}