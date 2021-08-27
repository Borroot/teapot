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
    Mat4 transz = Mat4::translate(0, 0, 5);
    Mat4 transmid = Mat4::translate(0.5, 0.5, 0);

    for (Mesh mesh : world.meshes)
    {
        for (Triangle triangle : mesh.triangles)
        {
            this->viewport * transmid * this->projection * transz * triangle;
            triangle.draw(canvas, sf::Color::White, false, true);
        }
    }
}