#include <SFML/Graphics.hpp>
#include "math/common.hh"
#include "render/line.hh"
#include "render/pixel.hh"
#include "render/render.hh"

void draw_line(sf::Uint8 *pixels, int w, int x1, int y1, int x2, int y2, sf::Color c)
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

void draw_line(sf::Uint8 *pixels, int w, int h, int x1, int y1, int x2, int y2, sf::Color c, int thickness)
{
    // TODO change this to rasterizing a rotated rectangle
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    double xinc = (double)dx / steps;
    double yinc = (double)dy / steps;

    double x = x1;
    double y = y1;
    for (int n = 0; n < steps; n++)
    {
        set(pixels, w, x, y, c);

        for (int i = 2; i < thickness + 1; i++)
        {
            if (i % 2)
                set(pixels, w, x + (yinc * (i / 2)), y - (xinc * (i / 2)), c);
            else
                set(pixels, w, x - (yinc * (i / 2)), y + (xinc * (i / 2)), c);
        }
        x += xinc;
        y += yinc;
    }
}