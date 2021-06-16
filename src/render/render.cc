#include <SFML/Graphics.hpp>
#include "render/render.hh"

void set(sf::Uint8 *pixels, int &w, int x, int y, sf::Color c)
{
    int index = w * y * 4 + x * 4;
    pixels[index + 0] = c.r;
    pixels[index + 1] = c.g;
    pixels[index + 2] = c.b;
    pixels[index + 3] = c.a;
}

void render(const World &world, sf::Uint8 *pixels, int &w, int &h)
{
    for (int y = h / 4; y < 3 * h / 4; y++)
        for (int x = w / 4; x < 3 * w / 4; x++)
            set(pixels, w, x, y, sf::Color::Cyan);
}

void background(sf::Uint8 *pixels, int &w, int &h, sf::Color c)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            set(pixels, w, x, y, c);
}