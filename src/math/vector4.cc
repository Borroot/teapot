#include <iostream>
#include <math.h>
#include <typeinfo>
#include "math/vector.hh"

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

vec4 &vec4::normalize()
{
    double length = this->length();
    if (length != 0)
    {
        this->x /= length;
        this->y /= length;
        this->z /= length;
        this->w /= length;
    }
    return *this;
}

double vec4::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}

double vec4::operator*(const vec4 &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w;
}

vec4 vec4::operator^(const vec4 &v)
{
    return (vec4)((vec3)*this ^ (vec3)(vec4)v);
}

vec4 &vec4::operator^=(const vec4 &v)
{
    vec4 result = *this ^ v;
    this->x = result.x;
    this->y = result.y;
    this->z = result.z;
    this->w = result.w;
    return *this;
}

bool vec4::operator==(const vec4 &v)
{
    return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
}

bool vec4::operator!=(const vec4 &v)
{
    return !(*this == v);
}

vec4 vec4::operator+(const vec4 &v)
{
    return *(new vec4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w));
}

vec4 vec4::operator-(const vec4 &v)
{
    return *(new vec4(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w));
}

vec4 &vec4::operator+=(const vec4 &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    this->w += v.w;
    return *this;
}

vec4 &vec4::operator-=(const vec4 &v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    this->w -= v.w;
    return *this;
}

vec4::operator vec3()
{
    if (this->w == 0)
        throw std::bad_cast();
    return *(new vec3 (this->x / this->w, this->y / this->w, this->z / this->w));
}

std::ostream &operator<<(std::ostream &os, const vec4 &v)
{
    os << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
    return os;
}