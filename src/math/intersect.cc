#include "math/intersect.hh"

Vec3 intersect_plane(Vec3 &plane_point, Vec3 &plane_normal, Vec3 &line_start, Vec3 &line_end)
{
    Vec3 line = line_end - line_start;
    double scalar = ((plane_point - line_start) * plane_normal) / (line * plane_normal);
    return line_start + line * scalar;
}