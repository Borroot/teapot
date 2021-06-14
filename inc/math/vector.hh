#pragma once

#include <iosfwd>

class vec3
{
public:
    double x, y, z;

    vec3(double x, double y, double z);
    friend std::ostream &operator<<(std::ostream &, const vec3 &);
};

class vec4
{
public:
    double x, y, z, w;

    vec4(double x, double y, double z);
    vec4(double x, double y, double z, double w);
    friend std::ostream &operator<<(std::ostream &, const vec4 &);
};