#pragma once

#include <iosfwd>

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

    friend std::ostream &operator<<(std::ostream &, const Mat4 &);
};