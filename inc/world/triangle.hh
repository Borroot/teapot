#pragma once

#include <iosfwd>
#include "math/vector4.hh"

class triangle
{
public:
    vec4 *v0;
    vec4 *v1;
    vec4 *v2;

    triangle() {};
    triangle(vec4 *, vec4 *, vec4 *);

    friend std::ostream &operator<<(std::ostream &, const triangle &);
};