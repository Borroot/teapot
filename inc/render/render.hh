#pragma once

#include <SFML/Graphics.hpp>
#include "math/matrix.hh"
#include "world/world.hh"

class Render
{
private:
    Mat4 proj;      // projection matrix
    Mat4 viewport;  // viewport matrix

    static Mat4 projection(int w, int h, double fov, double far, double near);

public:
    Render() {};
    Render(int w, int h);

    void render(World &, Canvas &);
};