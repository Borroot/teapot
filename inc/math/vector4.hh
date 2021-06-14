#pragma once

#include <iosfwd>

class vec4
{
public:
    double x, y, z, w;

    vec4(double x, double y, double z);
    vec4(double x, double y, double z, double w);

    vec4 &normalize();
    double length();
    double dot(const vec4 &);
    // TODO double cross(const vec4 &);

    bool operator==(const vec4 &);
    bool operator!=(const vec4 &);
    vec4 &operator+=(const vec4 &);
    vec4 &operator-=(const vec4 &);
    friend vec4 operator+(vec4, const vec4 &);
    friend vec4 operator-(vec4, const vec4 &);

    friend std::ostream &operator<<(std::ostream &, const vec4 &);
};