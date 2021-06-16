#pragma once

#include <iosfwd>
#include "math/vector4.hh"

class Triangle
{
public:
    Vec4 *v0;
    Vec4 *v1;
    Vec4 *v2;

    Triangle(Vec4 *, Vec4 *, Vec4 *);

    friend std::ostream &operator<<(std::ostream &, const Triangle &);
};