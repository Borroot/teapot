#include <iostream>
#include "math/vector.hh"

vec3::vec3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec4::vec4(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1.0;
}

vec4::vec4(double x, double y, double z, double w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

std::ostream &operator<<(std::ostream &os, const vec3 &v)
{
    os << v.x << " " << v.y << " " << v.z << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const vec4 &v)
{
    os << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
    return os;
}