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

    double operator*(const vec4 &);  // dot product
    double operator^(const vec4 &);  // cross product TODO

    bool operator==(const vec4 &);
    bool operator!=(const vec4 &);

    vec4 operator+(const vec4 &);
    vec4 operator-(const vec4 &);
    vec4 &operator+=(const vec4 &);
    vec4 &operator-=(const vec4 &);

    friend std::ostream &operator<<(std::ostream &, const vec4 &);
};