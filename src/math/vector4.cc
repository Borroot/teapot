#include <iostream>
#include <math.h>
#include <stdexcept>
#include "math/matrix.hh"
#include "math/vector.hh"

Vec4::Vec4(double x, double y, double z, double w)
{
    if (w == 0)
        throw std::domain_error("divide by zero since w=0");
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

Vec4::Vec4(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
}

Vec4 &Vec4::normalize()
{
    Vec3 v = (Vec3)*this;  // make w = 1
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

double Vec4::length()
{
    if (this->w == 0)
        throw std::domain_error("divide by zero since w=0");
    return sqrt(
        pow(this->x / this->w, 2) +
        pow(this->y / this->w, 2) +
        pow(this->z / this->w, 2));
}

double Vec4::operator*(const Vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return (
        (this->x / this->w) * (v.x / v.w) +
        (this->y / this->w) * (v.y / v.w) +
        (this->z / this->w) * (v.z / v.w));
}

Vec4 Vec4::operator^(const Vec4 &v)
{
    Vec3 v1 = (Vec3)*this;  // make w = 1
    Vec3 v2 = (Vec3)(Vec4)v;

    return Vec4(
        v1.y * v2.z - v1.z * v2.y,
        v1.z * v2.x - v1.x * v2.z,
        v1.x * v2.y - v1.y * v2.x);
}

Vec4 &Vec4::operator^=(const Vec4 &v)
{
    Vec3 v1 = (Vec3)*this;  // make w = 1
    Vec3 v2 = (Vec3)(Vec4)v;

    double x = v1.y * v2.z - v1.z * v2.y;
    double y = v1.z * v2.x - v1.x * v2.z;
    double z = v1.x * v2.y - v1.y * v2.x;

    this->x = x;
    this->y = y;
    this->z = z;
    this->w = 1;
    return *this;
}

bool Vec4::operator==(const Vec4 &v)
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

bool Vec4::operator!=(const Vec4 &v)
{
    return !(*this == v);
}

Vec4 Vec4::operator+(const Vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return Vec4(
        this->x / this->w + v.x / v.w,
        this->y / this->w + v.y / v.w,
        this->z / this->w + v.z / v.w);
}

Vec4 Vec4::operator-(const Vec4 &v)
{
    if (this->w == 0 || v.w == 0)
        throw std::domain_error("divide by zero since w=0");
    return Vec4(
        this->x / this->w - v.x / v.w,
        this->y / this->w - v.y / v.w,
        this->z / this->w - v.z / v.w);
}

Vec4 &Vec4::operator+=(const Vec4 &v)
{
    this->x = this->x / this->w + v.x / v.w;
    this->y = this->y / this->w + v.y / v.w;
    this->z = this->z / this->w + v.z / v.w;
    this->w = 1;
    return *this;
}

Vec4 &Vec4::operator-=(const Vec4 &v)
{
    this->x = this->x / this->w - v.x / v.w;
    this->y = this->y / this->w - v.y / v.w;
    this->z = this->z / this->w - v.z / v.w;
    this->w = 1;
    return *this;
}

Vec4 Vec4::operator*(const Mat4 &matrix)
{
    Vec4 result = Vec4();
    Mat4 m = (Mat4)matrix;

    result.x = this->x * m[0][0] + this->y * m[1][0] + this->z * m[2][0] + this->w * m[3][0];
    result.y = this->x * m[0][1] + this->y * m[1][1] + this->z * m[2][1] + this->w * m[3][1];
    result.z = this->x * m[0][2] + this->y * m[1][2] + this->z * m[2][2] + this->w * m[3][2];
    result.w = this->x * m[0][3] + this->y * m[1][3] + this->z * m[2][3] + this->w * m[3][3];

    return result;
}

Vec4 &Vec4::operator*=(const Mat4 &m)
{
    Vec4 result = Vec4(this->x, this->y, this->z, this->w) * m;

    this->x = result.x;
    this->y = result.y;
    this->z = result.z;
    this->w = result.w;

    return *this;
}

Vec4::operator Vec3()
{
    if (this->w == 0)
        throw std::domain_error("divide by zero since w=0");
    if (this->w == 1)
        return Vec3 (this->x, this->y, this->z);
    return Vec3 (this->x / this->w, this->y / this->w, this->z / this->w);
}

std::ostream &operator<<(std::ostream &os, const Vec4 &v)
{
    os << v.x << " " << v.y << " " << v.z << " " << v.w << std::endl;
    return os;
}