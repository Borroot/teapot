#pragma once

#include <iosfwd>
#include "math/vector4.hh"

class Triangle
{
public:
    Vec4 v0;
    Vec4 v1;
    Vec4 v2;

    Triangle(const Vec4, const Vec4, const Vec4);
    Triangle(const Triangle &);

    friend std::ostream &operator<<(std::ostream &, const Triangle &);
};