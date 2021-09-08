#include <ostream>
#include <math.h>
#include "math/vector3.hh"
#include "math/vector4.hh"

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

Vec3 Vec3::operator-()
{
    return Vec3(-this->x, -this->y, -this->z);
}

Vec3 Vec3::operator*(const double scalar)
{
    return Vec3(this->x * scalar, this->y * scalar, this->z * scalar);
}

Vec3 &Vec3::operator*=(const double scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
}

Vec3::operator Vec4()
{
    return Vec4(this->x, this->y, this->z, 1);
}

double Vec3::dist_fast(const Vec3 &v1, const Vec3 &v2)
{
    // perfrom no square root operation, hence fast but inaccurate
    return pow(v1.x - v2.x, 2) + pow(v1.y - v2.y, 2) + pow(v1.z - v2.z, 2);
}

std::ostream &operator<<(std::ostream &os, const Vec3 &v)
{
    os << "(" << v.x << " " << v.y << " " << v.z << ")";
    return os;
}