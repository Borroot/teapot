#include <ostream>
#include "math/common.hh"
#include "render/pixel.hh"
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

void Triangle::rasterize(sf::Uint8 *pixels, int w, sf::Color c)
{
    int xmin = min(3, this->v0.x, this->v1.x, this->v2.x);
    int xmax = max(3, this->v0.x, this->v1.x, this->v2.x) + 1;
    int ymin = min(3, this->v0.y, this->v1.y, this->v2.y);
    int ymax = max(3, this->v0.y, this->v1.y, this->v2.y) + 1;

    for (int x = xmin; x <= xmax; x++)
        for (int y = ymin; y <= ymax; y++)
            if (this->inside(x, y))
                set(pixels, w, x, y, c);
}

void Triangle::draw(sf::Uint8 *pixels, int w, int h, sf::Color c, bool fill, bool lines)
{
    if (lines)
    {
        draw_line(pixels, w, h, this->v0.x, this->v0.y, this->v1.x, this->v1.y, sf::Color::Red, 10);
        draw_line(pixels, w, h, this->v1.x, this->v1.y, this->v2.x, this->v2.y, sf::Color::Red, 10);
        draw_line(pixels, w, h, this->v2.x, this->v2.y, this->v0.x, this->v0.y, sf::Color::Red, 10);
    }
    if (fill)
        this->rasterize(pixels, w, c);
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    os << t.v0 << " " << t.v1 << " " << t.v2;
    return os;
}