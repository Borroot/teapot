#pragma once

#include <SFML/Graphics.hpp>
#include "math/matrix.hh"
#include "world/triangle.hh"
#include "world/world.hh"

class Render
{
private:
    double near = 0.1;
    double far = 100;

    Mat4 projection;
    Mat4 screen;

public:
    Render() = default;
    Render(int w, int h);

    void render(const World &, Canvas &);
};