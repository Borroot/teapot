#pragma once

#include <iosfwd>

class vec3
{
public:
    double x, y, z;

    vec3(double x, double y, double z);

    double dot(const vec3 &);

    bool operator==(const vec3 &);
    bool operator!=(const vec3 &);

    friend std::ostream &operator<<(std::ostream &, const vec3 &);
};

class vec4
{
public:
    double x, y, z, w;

    vec4(double x, double y, double z);
    vec4(double x, double y, double z, double w);

    double dot(const vec4 &);

    bool operator==(const vec4 &);
    bool operator!=(const vec4 &);

    friend std::ostream &operator<<(std::ostream &, const vec4 &);
};