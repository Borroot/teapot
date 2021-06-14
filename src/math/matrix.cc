#include <iostream>
#include "math/matrix.hh"

mat4::mat4(const double other[4][4])
{
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            this->matrix[y][x] = other[y][x];
}

double *mat4::operator[](const int &index)
{
    return this->matrix[index];
}

bool mat4::operator==(const mat4 &other)
{
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            if (this->matrix[y][x] != other.matrix[y][x])
                return false;
    return true;
}

bool mat4::operator!=(const mat4 &other)
{
    return !(*this == other);
}

mat4 mat4::operator*(const mat4 &other)
{
    mat4 result = mat4();
    for (short y = 0; y < 4; y++) {
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

std::ostream &operator<<(std::ostream &os, const mat4 &matrix)
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