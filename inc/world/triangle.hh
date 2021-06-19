#pragma once

#include <SFML/Graphics.hpp>
#include <iosfwd>
#include "math/vector4.hh"

class Triangle
{
private:
    bool edgetest(int, int, const Vec4 &, const Vec4 &);
    bool inside(int, int);

public:
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;

    Triangle(const Vec4, const Vec4, const Vec4);
    Triangle(const Triangle &);

    void rasterize(sf::Uint8 *, int w, sf::Color);
    void draw(sf::Uint8 *, int w, int h, sf::Color, bool fill, bool lines);

    friend std::ostream &operator<<(std::ostream &, const Triangle &);
};