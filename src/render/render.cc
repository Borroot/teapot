#include <SFML/Graphics.hpp>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/render.hh"

void render(World &world, Canvas &canvas)
{
    Triangle triangle(Vec4(100, 100, 0), Vec4(200, 500, 0), Vec4(500, 200, 0));
    triangle.draw(canvas, sf::Color::White, true, true);
}

void background(Canvas &canvas, sf::Color c)
{
    for (int y = 0; y < canvas.h; y++)
        for (int x = 0; x < canvas.w; x++)
            canvas.set(x, y, c);
}