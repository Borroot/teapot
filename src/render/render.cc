#include <SFML/Graphics.hpp>
#include <algorithm>
#include <iostream>
#include <vector>
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
    Vec3 camera(0, 0, 0);
    Mat4 transz = Mat4::translate(0, 0, 3);

    std::vector<Triangle> triangles;
    for (Mesh mesh : world.meshes)
        for (Triangle triangle : mesh.triangles)
            triangles.push_back(triangle);

    std::sort(triangles.begin(), triangles.end(), [](Triangle t1, Triangle t2) {
        double average1 = (t1.v0.z + t1.v1.z + t1.v2.z) / 3;
        double average2 = (t2.v0.z + t2.v1.z + t2.v2.z) / 3;
        return average1 > average2;
    });  // painter's algorithm

    for (Triangle triangle : triangles)
    {
        transz * triangle;  // move the triangle back a bit
        Vec3 normal = triangle.normal();

        if ((triangle.v0 - camera) * normal < 0)  // backface culling
        {
            double shade = light * normal;  // shading
            sf::Color color = sf::Color(shade * 255, shade * 255, shade * 255, 255);

            this->viewport * this->projection * triangle;  // projection
            triangle.draw(canvas, color, true, false);
        }
    }
}