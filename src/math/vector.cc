#include <iostream>
#include "math/vector.hh"

std::ostream &operator<<(std::ostream &os, const vec3 &vector)
{
    os << vector.x << " " << vector.y << " " << vector.z << std::endl;
    return os;
}

std::ostream &operator<<(std::ostream &os, const vec4 &vector)
{
    os << vector.x << " " << vector.y << " " << vector.z << " " << vector.w << std::endl;
    return os;
}