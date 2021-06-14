#pragma once

#include <iosfwd>

typedef double mat4[4][4];

std::ostream &operator<<(std::ostream &, const mat4 &);