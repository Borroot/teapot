#include <iostream>
#include <math.h>
#include "math/vector.hh"

Vec3::Vec3(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Vec3 &Vec3::normalize()
{
    double length = this->length();
    if (length != 0)
    {
        this->x /= length;
        this->y /= length;
        this->z /= length;
    }
    return *this;
}

double Vec3::length()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

double Vec3::operator*(const Vec3 &v)
{
    return this->x * v.x + this->y * v.y + this->z * v.z;
}

Vec3 Vec3::operator^(const Vec3 &v)
{
    return Vec3(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x);
}

Vec3 &Vec3::operator^=(const Vec3 &v)
{
    double x = this->y * v.z - this->z * v.y;
    double y = this->z * v.x - this->x * v.z;
    double z = this->x * v.y - this->y * v.x;

    this->x = x;
    this->y = y;
    this->z = z;
    return *this;
}

bool Vec3::operator==(const Vec3 &v)
{
    return this->x == v.x && this->y == v.y && this->z == v.z;
}

bool Vec3::operator!=(const Vec3 &v)
{
    return !(*this == v);
}

Vec3 Vec3::operator+(const Vec3 &v)
{
    return Vec3(this->x + v.x, this->y + v.y, this->z + v.z);
}

Vec3 Vec3::operator-(const Vec3 &v)
{
    return Vec3(this->x - v.x, this->y - v.y, this->z - v.z);
}

Vec3 &Vec3::operator+=(const Vec3 &v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    return *this;
}

Vec3 &Vec3::operator-=(const Vec3 &v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    return *this;
}

Vec3::operator Vec4()
{
    return Vec4(this->x, this->y, this->z, 1);
}

std::ostream &operator<<(std::ostream &os, const Vec3 &v)
{
    os << v.x << " " << v.y << " " << v.z << std::endl;
    return os;
}