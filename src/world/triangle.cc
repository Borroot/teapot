#include <ostream>
#include "world/triangle.hh"

Triangle::Triangle(const Vec4 v0, const Vec4 v1, const Vec4 v2)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}

Triangle::Triangle(const Triangle &triangle)
{
    this->v0 = triangle.v0;
    this->v1 = triangle.v1;
    this->v2 = triangle.v2;
}

std::ostream &operator<<(std::ostream &os, const Triangle &t)
{
    os << t.v0 << " " << t.v1 << " " << t.v2;
    return os;
}