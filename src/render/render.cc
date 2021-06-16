#include <SFML/Graphics.hpp>
#include "math/common.hh"
#include "render/line.hh"
#include "render/pixel.hh"
#include "render/render.hh"

void render(const World &world, sf::Uint8 *pixels, int w, int h)
{
    draw_line(pixels, w, h, 100, 100, 1000, 600, sf::Color::White, 5);
}

void background(sf::Uint8 *pixels, int w, int h, sf::Color c)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            set(pixels, w, x, y, c);
}