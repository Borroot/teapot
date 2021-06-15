#include <ostream>
#include "math/vector3.hh"
#include "world/triangle.hh"

triangle::triangle(const vec3 &v0, const vec3 &v1, const vec3 &v2)
{
    this->v0 = v0;
    this->v1 = v1;
    this->v2 = v2;
}

std::ostream &operator<<(std::ostream &os, const triangle &t)
{
    os << t.v0 << " " << t.v1 << " " << t.v2;
    return os;
}