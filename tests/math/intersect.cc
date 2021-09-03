#include <criterion/criterion.h>
#include "math/intersect.hh"

Test(intersect, intersect_plane)
{
    Vec3 plane_point1(0, 0, 0);
    Vec3 plane_normal1(0, 0, 1);
    Vec3 line_start1(0, 0, -1);
    Vec3 line_end1(0, 0, 1);

    Vec3 intersect1 = intersect_plane(plane_point1, plane_normal1, line_start1, line_end1);
    cr_assert_eq(intersect1, Vec3(0, 0, 0));

    Vec3 plane_point2(2, 2, 2);
    Vec3 plane_normal2(2, 2, 0);
    Vec3 line_start2(-1, -1, 0);
    Vec3 line_end2(5, 5, 0);

    Vec3 intersect2 = intersect_plane(plane_point2, plane_normal2, line_start2, line_end2);
    cr_assert_eq(intersect2, Vec3(2, 2, 0));
}