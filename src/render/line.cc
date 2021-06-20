#include <SFML/Graphics.hpp>
#include <assert.h>
#include "math/common.hh"
#include "render/line.hh"
#include "render/render.hh"

void draw_line(Canvas &canvas, int x1, int y1, int x2, int y2, sf::Color c)
{
    assert(0 <= x1 && x1 <= canvas.w && 0 <= y1 && y1 <= canvas.h);
    assert(0 <= x2 && x2 <= canvas.w && 0 <= y2 && y2 <= canvas.h);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    double xinc = (double)dx / steps;
    double yinc = (double)dy / steps;

    double x = x1;
    double y = y1;
    for (int n = 0; n < steps; n++)
    {
        canvas.set(x, y, c);
        x += xinc;
        y += yinc;
    }
}

void draw_line(Canvas &canvas, int x1, int y1, int x2, int y2, sf::Color c, int thickness)
{
    assert(0 <= x1 && x1 <= canvas.w && 0 <= y1 && y1 <= canvas.h);
    assert(0 <= x2 && x2 <= canvas.w && 0 <= y2 && y2 <= canvas.h);

    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps = abs(dx) > abs(dy) ? abs(dx) * 2 : abs(dy) * 2;

    double xinc = (double)dx / steps;
    double yinc = (double)dy / steps;

    double x = x1;
    double y = y1;
    for (int n = 0; n < steps; n++)
    {
        canvas.set(x, y, c);

        for (int i = 2; i < thickness + 1; i++)
        {
            if (i % 2) {
                int xx = x + (yinc * (i / 2));
                int yy = y - (xinc * (i / 2));
                if (0 <= xx && xx < canvas.w && 0 <= y && y < canvas.h)
                    canvas.set(xx, yy, c);
            } else {
                int xx = x - (yinc * (i / 2));
                int yy = y + (xinc * (i / 2));
                if (0 <= xx && xx < canvas.w && 0 <= y && y < canvas.h)
                    canvas.set(xx, yy, c);
            }
        }
        x += xinc;
        y += yinc;
    }
}