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
    // Triangle triangle(Vec4(100, 50, 0), Vec4(200, 250, 0), Vec4(300, 150, 0));
    // triangle.draw(canvas, sf::Color::White, true, true);

    Mat4 trans = Mat4::translate(1, 1, 6);
    Mat4 scale = Mat4::scale(0.5, 0.5, 0.5);

    for (Mesh mesh : world.meshes)
    {
        for (Triangle triangle : mesh.triangles)
        {
            triangle.v0 = this->viewport * this->projection * scale * trans * triangle.v0;
            triangle.v1 = this->viewport * this->projection * scale * trans * triangle.v1;
            triangle.v2 = this->viewport * this->projection * scale * trans * triangle.v2;

            triangle.draw(canvas, sf::Color::White, false, true);
        }
    }
}