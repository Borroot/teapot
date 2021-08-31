#include <iostream>
#include <math.h>
#include <stdexcept>
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

void Vec4::remove_w()
{
    if (w == 0)
        throw std::domain_error("divide by zero since w=0");
    this->x = x / this->w;
    this->y = y / this->w;
    this->z = z / this->w;
    this->w = 1;
}

Vec4 &Vec4::normalize()
{
    this->remove_w();
    double length = this->length();
    if (length != 0)
    {
        this->x = this->x / length;
        this->y = this->y / length;
        this->z = this->z / length;
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

Vec4 Vec4::operator^(const Vec4 &vector)
{
    Vec4 v = Vec4(vector);
    v.remove_w();
    this->remove_w();

    return Vec4(
        this->y * v.z - this->z * v.y,
        this->z * v.x - this->x * v.z,
        this->x * v.y - this->y * v.x);
}

Vec4 &Vec4::operator^=(const Vec4 &vector)
{
    Vec4 v = Vec4(vector);
    v.remove_w();
    this->remove_w();

    double x = this->y * v.z - this->z * v.y;
    double y = this->z * v.x - this->x * v.z;
    double z = this->x * v.y - this->y * v.x;

    this->x = x;
    this->y = y;
    this->z = z;
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

Vec4 Vec4::operator-()
{
    return Vec4(-this->x, -this->y, -this->z, this->w);
}

Vec4 Vec4::operator*(const double scalar)
{
    return Vec4(this->x * scalar, this->y * scalar, this->z * scalar, this->w);
}

Vec4 &Vec4::operator*=(const double scalar)
{
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
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