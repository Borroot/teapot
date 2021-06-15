#pragma once

#include <iosfwd>

class mat4
{
private:
    double matrix[4][4];

public:
    mat4() {};
    mat4(const double[4][4]);

    double* operator[](const int &);
    bool operator==(const mat4 &);
    bool operator!=(const mat4 &);

    mat4 operator*(const mat4 &);
    mat4 &operator*=(const mat4 &);

    friend std::ostream &operator<<(std::ostream &, const mat4 &);
};