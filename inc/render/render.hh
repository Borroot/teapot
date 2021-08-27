#pragma once

#include <SFML/Graphics.hpp>
#include "math/matrix.hh"
#include "world/world.hh"

class Render
{
private:
    Mat4 projection;
    Mat4 viewport;

public:
    Render() {};
    Render(int w, int h);

    void render(World &, Canvas &);
};