#include <iostream>
#include "math/matrix.hh"

std::ostream &operator<<(std::ostream &os, const mat4 &matrix)
{
    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            os << matrix[y][x];
            if (x < 3)
                os << " ";
            else
                os << std::endl;
        }
    }
    return os;
}
