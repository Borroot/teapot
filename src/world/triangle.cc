#include <ostream>
#include <assert.h>
#include "core/canvas.hh"
#include "math/common.hh"
#include "math/vector4.hh"
#include "render/line.hh"
#include "world/triangle.hh"

Triangle::Triangle(const Vec4 v0, const Vec4 v1, const Vec4 v2)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}

void Triangle::normalize_w()
{
    this->v0.normalize_w();
    this->v1.normalize_w();
    this->v2.normalize_w();
}

Vec3 Triangle::normal()
{
    return ((this->v1 - this->v0).normalize() ^ (this->v2 - this->v0).normalize()).normalize();
}

void Triangle::rasterize(Canvas &canvas)
{
    assert(this->v0.w == 1 && this->v1.w == 1 && this->v2.w == 1);

    assert(0 <= this->v0.x && this->v0.x < canvas.w && 0 <= this->v0.y && this->v0.y < canvas.h);
    assert(0 <= this->v1.x && this->v1.x < canvas.w && 0 <= this->v1.y && this->v1.y < canvas.h);
    assert(0 <= this->v2.x && this->v2.x < canvas.w && 0 <= this->v2.y && this->v2.y < canvas.h);

    int xmin = min(3, this->v0.x, this->v1.x, this->v2.x);
    int xmax = max(3, this->v0.x, this->v1.x, this->v2.x);
    int ymin = min(3, this->v0.y, this->v1.y, this->v2.y);
    int ymax = max(3, this->v0.y, this->v1.y, this->v2.y);

    auto area = [&](double x1, double y1, double x2, double y2, double x3, double y3) {
        // return the area of the triangle times two (bounding parallelogram)
        return (x3 - x1) * (y2 - y1) - (x2 - x1) * (y3 - y1);
    };

    double area_triangle = area(v0.x, v0.y, v1.x, v1.y, v2.x, v2.y);
    for (int x = xmin; x <= xmax; x++)
    {
        for (int y = ymin; y <= ymax; y++)
        {
            double w0 = area(x, y, v0.x, v0.y, v1.x, v1.y);
            double w1 = area(x, y, v1.x, v1.y, v2.x, v2.y);
            double w2 = area(x, y, v2.x, v2.y, v0.x, v0.y);

            if (w0 >= 0 && w1 >= 0 && w2 >= 0)  // then inside triangle
            {
                // compute the barycentric coordinate scalar components
                w0 /= area_triangle;
                w1 /= area_triangle;
                w2 /= area_triangle;

                sf::Color color(w0 * 255, w1 * 255, w2 * 255, 255);
                canvas.set(x, y, color);
            }
        }
    }
}

void Triangle::draw(Canvas &canvas, bool fill, bool lines)
{
    this->normalize_w();
    if (fill)
        this->rasterize(canvas);
    if (lines)
    {
        draw_line(canvas, this->v0.x, this->v0.y, this->v1.x, this->v1.y, sf::Color::Red, 1);
        draw_line(canvas, this->v1.x, this->v1.y, this->v2.x, this->v2.y, sf::Color::Red, 1);
        draw_line(canvas, this->v2.x, this->v2.y, this->v0.x, this->v0.y, sf::Color::Red, 1);
    }
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    os << t.v0 << " " << t.v1 << " " << t.v2;
    return os;
}