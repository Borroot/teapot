#pragma once

#include <iosfwd>

class Vec3;

class Vec4
{
public:
    double x, y, z, w;

    Vec4() = default;
    Vec4(double x, double y, double z, double w);
    Vec4(double x, double y, double z);

    void normalize_w();  // make w = 1
    Vec4 &normalize();
    double length();
    double dot(const Vec4 &);

    double operator*(const Vec4 &);  // dot product

    Vec4 operator^(const Vec4 &);  // cross product
    Vec4 &operator^=(const Vec4 &);

    bool operator==(const Vec4 &);
    bool operator!=(const Vec4 &);

    Vec4 operator+(const Vec4 &);
    Vec4 operator-(const Vec4 &);
    Vec4 &operator+=(const Vec4 &);
    Vec4 &operator-=(const Vec4 &);

    Vec4 operator-();

    Vec4 operator*(const double);
    Vec4 &operator*=(const double);

    operator Vec3();

    friend std::ostream &operator<<(std::ostream &, const Vec4 &);
};