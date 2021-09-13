#pragma once

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include "core/canvas.hh"
#include "math/vector3.hh"
#include "math/vector4.hh"

class Triangle
{
private:
    void rasterize(Canvas &);

public:
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;
    sf::Color color;

    Triangle() = default;
    Triangle(const Vec4, const Vec4, const Vec4);

    void normalize_w();
    Vec3 normal();
    void draw(Canvas &, bool fill, bool lines);

    friend std::ostream &operator<<(std::ostream &, const Triangle &);
};