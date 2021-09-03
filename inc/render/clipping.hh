
#pragma once

#include <list>
#include "world/triangle.hh"

void clip_properly(std::list<Triangle> &, int w, int h);  // in projection space
void clip_farnear(std::list<Triangle> &, double far, double near);  // in view space