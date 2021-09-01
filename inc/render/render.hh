#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "math/matrix.hh"
#include "world/triangle.hh"
#include "world/world.hh"

class Render
{
private:
    Mat4 projection;
    Mat4 screen;

    static Mat4 projection_matrix(int w, int h, double fov, double far, double near);
    static Mat4 screen_matrix(int w, int h);

    static void list(const World &, std::vector<Triangle> &);
    static void sort(std::vector<Triangle> &, const Vec3 &ref);

public:
    Render() = default;
    Render(int w, int h);

    void render(const World &, Canvas &);
};