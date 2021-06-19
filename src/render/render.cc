#include <SFML/Graphics.hpp>
#include "math/common.hh"
#include "math/vector.hh"
#include "render/line.hh"
#include "render/pixel.hh"
#include "render/render.hh"

void render(World &world, sf::Uint8 *pixels, int w, int h)
{
    Triangle triangle(Vec4(100, 100, 0), Vec4(200, 500, 0), Vec4(500, 200, 0));
    triangle.draw(pixels, w, h, sf::Color::White, true, true);
}

void background(sf::Uint8 *pixels, int w, int h, sf::Color c)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            set(pixels, w, x, y, c);
}