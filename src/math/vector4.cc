#include <iostream>
#include <math.h>
#include <stdexcept>
#include "math/vector.hh"

vec4::vec4(double x, double y, double z, double w)
{
    if (w == 0)
        throw std::domain_error("divide by zero since w=0");
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vec4::vec4(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
}

vec4 &vec4::normalize()
{
    vec3 v = (vec3)*this;  // make w = 1
    double length = v.length();
    if (length != 0)
    {
        this->x = v.x / length;
        this->y = v.y / length;
        this->z = v.z / length;
        this->w = 1;
    }
    return *this;
}

double vec4::length()
{
    if (this->w == 0)
        throw std::domain_error("divide by zero since w=0");
    return sqrt(
        pow(this->x / this->w, 2) +
        pow(this->y / this->w, 2) +
        pow(this->z / this->w, 2));
}

double vec4::operator*(const vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return (
        (this->x / this->w) * (v.x / v.w) +
        (this->y / this->w) * (v.y / v.w) +
        (this->z / this->w) * (v.z / v.w));
}

vec4 vec4::operator^(const vec4 &v)
{
    vec3 v1 = (vec3)*this;  // make w = 1
    vec3 v2 = (vec3)(vec4)v;

    return *(new vec4(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x));
}

vec4 &vec4::operator^=(const vec4 &v)
{
    vec3 v1 = (vec3)*this;  // make w = 1
    vec3 v2 = (vec3)(vec4)v;

    double x = v1.y * v2.z - v1.z * v2.y;
    double y = v1.z * v2.x - v1.x * v2.z;
    double z = v1.x * v2.y - v1.y * v2.x;

    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
    return *this;
}

bool vec4::operator==(const vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    if (this->w == v.w)
        return this->x == v.x && this->y == v.y && this->z == v.z;
    return (
        this->x / this->w == v.x / v.w &&
        this->y / this->w == v.y / v.w &&
        this->z / this->w == v.z / v.w);
}

bool vec4::operator!=(const vec4 &v)
{
    return !(*this == v);
}

vec4 vec4::operator+(const vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return *(new vec4(
        this->x / this->w + v.x / v.w,
        this->y / this->w + v.y / v.w,
        this->z / this->w + v.z / v.w));
}

vec4 vec4::operator-(const vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return *(new vec4(
        this->x / this->w - v.x / v.w,
        this->y / this->w - v.y / v.w,
        this->z / this->w - v.z / v.w));
}

vec4 &vec4::operator+=(const vec4 &v)
{
    this->x = this->x / this->w + v.x / v.w;
    this->y = this->y / this->w + v.y / v.w;
    this->z = this->z / this->w + v.z / v.w;
    this->w = 1;
    return *this;
}

vec4 &vec4::operator-=(const vec4 &v)
{
    this->x = this->x / this->w - v.x / v.w;
    this->y = this->y / this->w - v.y / v.w;
    this->z = this->z / this->w - v.z / v.w;
    this->w = 1;
    return *this;
}

vec4::operator vec3()
{
    if (this->w == 0)
        throw std::domain_error("divide by zero since w=0");
    if (this->w == 1)
        return *(new vec3 (this->x, this->y, this->z));
    return *(new vec3 (this->x / this->w, this->y / this->w, this->z / this->w));
}

std::ostream &operator<<(std::ostream &os, const vec4 &v)
{
    os << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
    return os;
}