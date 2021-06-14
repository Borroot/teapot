#include <iostream>
#include <math.h>
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

double vec3::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double vec4::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}

vec3 vec3::normalize()
{
    double sum = this->length();
    if (sum != 0)
    {
        this->x /= sum;
        this->y /= sum;
        this->z /= sum;
    }
    return *this;
}

vec4 vec4::normalize()
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

double vec3::dot(const vec3 &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

double vec4::dot(const vec4 &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z + this->w * v.w;
}

bool vec3::operator==(const vec3 &v)
{
    return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool vec3::operator!=(const vec3 &v)
{
    return !(*this == v);
}

bool vec4::operator==(const vec4 &v)
{
    return this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w;
}

bool vec4::operator!=(const vec4 &v)
{
    return !(*this == v);
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