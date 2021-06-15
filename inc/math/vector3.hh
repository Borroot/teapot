#pragma once

#include <iosfwd>
#include "math/vector4.hh"

class vec3
{
public:
    double x, y, z;

    vec3(double x, double y, double z);

    vec3 &normalize();
    double length();
    double dot(const vec3 &);

    double operator*(const vec3 &);  // dot product

    vec3 operator^(const vec3 &);  // cross product
    vec3 &operator^=(const vec3 &);

    bool operator==(const vec3 &);
    bool operator!=(const vec3 &);

    vec3 operator+(const vec3 &);
    vec3 operator-(const vec3 &);
    vec3 &operator+=(const vec3 &);
    vec3 &operator-=(const vec3 &);

    operator vec4();

    friend std::ostream &operator<<(std::ostream &, const vec3 &);
};