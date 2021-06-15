#include <iostream>
#include <math.h>
#include "math/vector.hh"

vec3::vec3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3 &vec3::normalize()
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

double vec3::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double vec3::operator*(const vec3 &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

vec3 vec3::operator^(const vec3 &v)
{
    vec3 result(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x);
    return result;
}

vec3 &vec3::operator^=(const vec3 &v)
{
    double x = this->y * v.z - this->z * v.y;
    double y = this->z * v.x - this->x * v.z;
    double z = this->x * v.y - this->y * v.x;
    this->x = x, this->y = y, this->z = z;
    return *this;
}

bool vec3::operator==(const vec3 &v)
{
    return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool vec3::operator!=(const vec3 &v)
{
    return !(*this == v);
}

vec3 vec3::operator+(const vec3 &v)
{
    vec3 result(this->x + v.x, this->y + v.y, this->z + v.z);
    return result;
}

vec3 vec3::operator-(const vec3 &v)
{
    vec3 result(this->x - v.x, this->y - v.y, this->z - v.z);
    return result;
}

vec3 &vec3::operator+=(const vec3 &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

vec3 &vec3::operator-=(const vec3 &v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

vec3::operator vec4()
{
    vec4 result(this->x, this->y, this->z, 1);
    return result;
}

std::ostream &operator<<(std::ostream &os, const vec3 &v)
{
    os << v.x << " " << v.y << " " << v.z << std::endl;
    return os;
}