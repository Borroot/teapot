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
    double sum = this->length();
    if (sum != 0)
    {
        this->x /= sum;
        this->y /= sum;
        this->z /= sum;
        this->w /= sum;
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
    vec4 result(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
    return result;
}

vec4 vec4::operator-(const vec4 &v)
{
    vec4 result(this->x - v.x, this->y - v.y, this->z - v.z, this->w - v.w);
    return result;
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
        throw std::bad_cast("w cannot be 0 when casting");
    vec3 result(this->x / this->w, this->y / this->w, this->z / this->w);
    return result;
}

std::ostream &operator<<(std::ostream &os, const vec4 &v)
{
    os << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
    return os;
}