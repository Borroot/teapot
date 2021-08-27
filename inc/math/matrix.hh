#pragma once

#include <iosfwd>
#include "math/vector4.hh"

class Mat4
{
private:
    double matrix[4][4];

public:
    Mat4() {};
    Mat4(const double[4][4]);

    double* operator[](int);
    bool operator==(const Mat4 &);
    bool operator!=(const Mat4 &);

    Mat4 operator*(const Mat4 &);
    Mat4 &operator*=(const Mat4 &);

    Vec4 operator*(const Vec4 &);

    static Mat4 translate(double, double, double);
    static Mat4 scale(double, double, double);
    static Mat4 viewport(int w, int h);
    static Mat4 projection(int w, int h, double fov, double far, double near);

    friend std::ostream &operator<<(std::ostream &, const Mat4 &);
};