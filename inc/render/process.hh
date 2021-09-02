#pragma once

#include <list>
#include "core/canvas.hh"
#include "math/vector3.hh"
#include "world/triangle.hh"
#include "world/world.hh"

void populate(const World &world, std::list<Triangle> &);
void backface_culling(std::list<Triangle> &, Vec3 ref);
void shade(std::list<Triangle> &);
void painters_algorithm(std::list<Triangle> &, const Vec3 &ref);
void clip_farnear(std::list<Triangle> &, double far, double near);
void clip_properly(std::list<Triangle> &);
void apply_matrix(std::list<Triangle> &, Mat4);
void draw(std::list<Triangle> &, Canvas &);