#pragma once

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include "core/canvas.hh"
#include "math/vector3.hh"
#include "math/vector4.hh"

class Triangle
{
private:
    bool edgetest(int, int, const Vec4 &, const Vec4 &);
    bool inside(int, int);
    void rasterize(Canvas &, sf::Color);
    void normalize_w();

public:
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;

    Triangle() = default;
    Triangle(const Vec4, const Vec4, const Vec4);

    Vec3 normal();
    void draw(Canvas &, sf::Color, bool fill, bool lines);

    friend std::ostream &operator<<(std::ostream &, const Triangle &);
};