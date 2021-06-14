#include <iostream>
#include "math/matrix.hh"

mat4::mat4(const double m[4][4])
{
    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            this->cells[y][x] = m[y][x];
}

std::ostream &operator<<(std::ostream &os, const mat4 &m)
{
    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            os << m.cells[y][x];
            if (x < 3)
                os << " ";
        }
        os << std::endl;
    }
    return os;
}