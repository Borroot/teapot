#pragma once

#include <iosfwd>

class Vec4;

class Vec3
{
public:
    double x, y, z;

    Vec3() = default;
    Vec3(double x, double y, double z);

    Vec3 &normalize();
    double length();
    double dot(const Vec3 &);

    double operator*(const Vec3 &);  // dot product

    Vec3 operator^(const Vec3 &);  // cross product
    Vec3 &operator^=(const Vec3 &);

    bool operator==(const Vec3 &);
    bool operator!=(const Vec3 &);

    Vec3 operator+(const Vec3 &);
    Vec3 operator-(const Vec3 &);
    Vec3 &operator+=(const Vec3 &);
    Vec3 &operator-=(const Vec3 &);

    Vec3 operator-();

    Vec3 operator*(const double);
    Vec3 &operator*=(const double);

    operator Vec4();

    friend std::ostream &operator<<(std::ostream &, const Vec3 &);
};