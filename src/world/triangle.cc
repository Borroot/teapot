#include <ostream>
#include <assert.h>
#include "core/canvas.hh"
#include "math/common.hh"
#include "render/line.hh"
#include "world/triangle.hh"

Triangle::Triangle(const Vec4 v0, const Vec4 v1, const Vec4 v2)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}

Triangle::Triangle(const Triangle &triangle)
{
    this->v0 = triangle.v0;
    this->v1 = triangle.v1;
    this->v2 = triangle.v2;
}

bool Triangle::edgetest(int x, int y, const Vec4 &a, const Vec4 &b)
{
    return 0 <= (x - a.x) * (b.y - a.y) - (y - a.y) * (b.x - a.x);
}

bool Triangle::inside(int x, int y)
{
    return edgetest(x, y, this->v0, this->v1)
        && edgetest(x, y, this->v1, this->v2)
        && edgetest(x, y, this->v2, this->v0);
}

void Triangle::rasterize(Canvas &canvas, sf::Color c)
{
    assert(0 <= this->v0.x && this->v0.x <= canvas.w && 0 <= this->v0.y && this->v0.y <= canvas.h);
    assert(0 <= this->v1.x && this->v1.x <= canvas.w && 0 <= this->v1.y && this->v1.y <= canvas.h);
    assert(0 <= this->v2.x && this->v2.x <= canvas.w && 0 <= this->v2.y && this->v2.y <= canvas.h);

    int xmin = min(3, this->v0.x, this->v1.x, this->v2.x);
    int xmax = max(3, this->v0.x, this->v1.x, this->v2.x);
    int ymin = min(3, this->v0.y, this->v1.y, this->v2.y);
    int ymax = max(3, this->v0.y, this->v1.y, this->v2.y);

    for (int x = xmin; x <= xmax; x++)
        for (int y = ymin; y <= ymax; y++)
            if (this->inside(x, y))
                canvas.set(x, y, c);
}

void Triangle::draw(Canvas &canvas, sf::Color c, bool fill, bool lines)
{
    if (lines)
    {
        draw_line(canvas, this->v0.x, this->v0.y, this->v1.x, this->v1.y, sf::Color::Magenta, 5);
        draw_line(canvas, this->v1.x, this->v1.y, this->v2.x, this->v2.y, sf::Color::Magenta, 5);
        draw_line(canvas, this->v2.x, this->v2.y, this->v0.x, this->v0.y, sf::Color::Magenta, 5);
    }
    if (fill)
        this->rasterize(canvas, c);
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    os << t.v0 << " " << t.v1 << " " << t.v2;
    return os;
}