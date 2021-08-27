#pragma once

#include <iosfwd>

class Vec3;

class Vec4
{
public:
    double x, y, z, w;

    Vec4() {};
    Vec4(double x, double y, double z, double w);
    Vec4(double x, double y, double z);

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

    operator Vec3();

    friend std::ostream &operator<<(std::ostream &, const Vec4 &);
};