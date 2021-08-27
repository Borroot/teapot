#include <iostream>
#include "math/matrix.hh"
#include "math/vector4.hh"

Mat4::Mat4(const double other[4][4])
{
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            this->matrix[y][x] = other[y][x];
}

double *Mat4::operator[](int index)
{
    return this->matrix[index];
}

bool Mat4::operator==(const Mat4 &other)
{
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            if (this->matrix[y][x] != other.matrix[y][x])
                return false;
    return true;
}

bool Mat4::operator!=(const Mat4 &other)
{
    return !(*this == other);
}

Mat4 Mat4::operator*(const Mat4 &other)
{
    Mat4 result = Mat4();
    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            double dot = 0;
            for (short n = 0; n < 4; n++)
                dot += this->matrix[y][n] * other.matrix[n][x];
            result[y][x] = dot;
        }
    }
    return result;
}

Mat4 &Mat4::operator*=(const Mat4 &other)
{
    double result[4][4];
    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            double dot = 0;
            for (short n = 0; n < 4; n++)
                dot += this->matrix[y][n] * other.matrix[n][x];
            result[y][x] = dot;
        }
    }
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            this->matrix[y][x] = result[y][x];
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Mat4 &matrix)
{
    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            os << matrix.matrix[y][x];
            if (x < 3)
                os << " ";
        }
        os << std::endl;
    }
    return os;
}