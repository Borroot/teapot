#include <SFML/Graphics.hpp>
#include "math/common.hh"
#include "render/line.hh"
#include "render/pixel.hh"
#include "render/render.hh"

void render(World &world, sf::Uint8 *pixels, int w, int h)
{
    draw_line(pixels, w, h, 0, 100, 120, 600, sf::Color::White, 80);
}

void background(sf::Uint8 *pixels, int w, int h, sf::Color c)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            set(pixels, w, x, y, c);
}