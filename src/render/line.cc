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
    draw_line(pixels, w, x1, y1, x2, y2, c);  // draw center line

    if (abs(x2 - x1) > abs(y2 - y1)) {  // horizontal line
        for (int i = 2; i < thickness + 1; i++)
        {
            if (i % 2 == 0)  // add to top
                draw_line(pixels, w, x1, y1 - i / 2, x2, y2 - i / 2, c);
            else  // add to bottom
                draw_line(pixels, w, x1, y1 + i / 2, x2, y2 + i / 2, c);
        }
    } else {  // vertical line
        for (int i = 2; i < thickness + 1; i++)
        {
            if (i % 2 == 0)  // add to left
                draw_line(pixels, w, x1 - i / 2, y1, x2 - i / 2, y2, c);
            else  // add to right
                draw_line(pixels, w, x1 + i / 2, y1, x2 + i / 2, y2, c);
        }
    }
}