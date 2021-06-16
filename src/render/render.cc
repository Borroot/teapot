#include <SFML/Graphics.hpp>
#include "math/common.hh"
#include "render/render.hh"

void set(sf::Uint8 *pixels, int &w, int x, int y, sf::Color c)
{
    int index = w * y * 4 + x * 4;
    pixels[index + 0] = c.r;
    pixels[index + 1] = c.g;
    pixels[index + 2] = c.b;
    pixels[index + 3] = c.a;
}

void draw_line(sf::Uint8 *pixels, int &w, int x1, int y1, int x2, int y2, sf::Color c)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    double xinc = (double)dx / steps;
    double yinc = (double)dy / steps;

    double x = x1;
    double y = y1;
    for (int n = 0; n < steps; n++)
    {
        set(pixels, w, (int)x, (int)y, c);
        x += xinc;
        y += yinc;
    }
}

void render(const World &world, sf::Uint8 *pixels, int &w, int &h)
{
    draw_line(pixels, w, 0, 0, w - 1, h - 1, sf::Color::Green);
}

void background(sf::Uint8 *pixels, int &w, int &h, sf::Color c)
{
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++)
            set(pixels, w, x, y, c);
}