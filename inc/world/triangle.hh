#pragma once

#include <ostream>
#include "math/vector3.hh"

class triangle
{
public:
    vec3 v0;
    vec3 v1;
    vec3 v2;

    triangle(const vec3 &, const vec3 &, const vec3 &);

    friend std::ostream &operator<<(std::ostream &, const triangle &);
};