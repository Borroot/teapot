#pragma once

#include <iosfwd>

class mat4
{
private:
    double cells[4][4];

public:
    mat4(const double[4][4]);
    friend std::ostream &operator<<(std::ostream &, const mat4 &);
};