#pragma once

#include <iosfwd>
#include "math/vector4.hh"
#include "world/triangle.hh"
#include "world/mesh.hh"

class Mat4
{
private:
    double matrix[4][4];

public:
    Mat4() = default;
    Mat4(const double[4][4]);

    double* operator[](int);
    bool operator==(const Mat4 &);
    bool operator!=(const Mat4 &);

    Mat4 operator*(const Mat4 &);
    Mat4 &operator*=(const Mat4 &);

    Vec4 operator*(const Vec4 &);
    void operator*(Triangle &);
    void operator*(Mesh &);

    static Mat4 translate(double, double, double);
    static Mat4 scale(double, double, double);
    static Mat4 viewport(int w, int h);
    static Mat4 projection(int w, int h, double fov, double far, double near);

    static Mat4 rotx(double rad);
    static Mat4 roty(double rad);
    static Mat4 rotz(double rad);

    friend std::ostream &operator<<(std::ostream &, const Mat4 &);
};