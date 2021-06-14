#pragma once

#include <iosfwd>

typedef struct
{
    double x, y, z;
} vec3;

typedef struct
{
    double x, y, z, w = 1;
} vec4;

std::ostream &operator<<(std::ostream &, const vec3 &);
std::ostream &operator<<(std::ostream &, const vec4 &);