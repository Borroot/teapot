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

Vec4 Mat4::operator*(const Vec4 &v)
{
    Vec4 result = Vec4();

    result.x = v.x * this->matrix[0][0] + v.y * this->matrix[0][1] + v.z * this->matrix[0][2] + v.w * this->matrix[0][3];
    result.y = v.x * this->matrix[1][0] + v.y * this->matrix[1][1] + v.z * this->matrix[1][2] + v.w * this->matrix[1][3];
    result.z = v.x * this->matrix[2][0] + v.y * this->matrix[2][1] + v.z * this->matrix[2][2] + v.w * this->matrix[2][3];
    result.w = v.x * this->matrix[3][0] + v.y * this->matrix[3][1] + v.z * this->matrix[3][2] + v.w * this->matrix[3][3];

    return result;
}

Mat4 Mat4::translate(double x, double y, double z)
{
    return Mat4(new double[4][4]{
        {1, 0, 0, x},
        {0, 1, 0, y},
        {0, 0, 1, z},
        {0, 0, 0, 1}
    });
}

Mat4 Mat4::scale(double x, double y, double z)
{
    return Mat4(new double[4][4]{
        {x, 0, 0, 0},
        {0, y, 0, 0},
        {0, 0, z, 0},
        {0, 0, 0, 1}
    });
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