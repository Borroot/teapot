#include <SFML/Graphics.hpp>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/render.hh"

void render(World &world, Canvas &canvas)
{
    Triangle triangle(Vec4(100, 50, 0), Vec4(200, 250, 0), Vec4(300, 150, 0));
    triangle.draw(canvas, sf::Color::White, true, true);
}