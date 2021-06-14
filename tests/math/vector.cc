#include <criterion/criterion.h>
#include <math.h>
#include "math/vector.hh"

Test(vector, vec4_declaration)
{
    vec4 v(2, 3, 4);
    cr_assert_eq(v.w, 1.0);
}

Test(vector, length)
{
    vec3 v1(3, 2, 1);
    cr_assert_float_eq(v1.length(), sqrt(14), 0.1);

    vec4 v2(3, 2, 1, 4);
    cr_assert_float_eq(v2.length(), sqrt(30), 0.1);
}

Test(vector, normalize)
{
    vec3 v1(0, 0, 0);
    cr_assert_eq(v1.normalize(), *(new vec3(0, 0, 0)));

    vec3 v2(1, 0, 0);
    vec3 v3(3, 0, 0);
    cr_assert_eq(v2.normalize(), *(new vec3(1, 0, 0)));
    cr_assert_eq(v3.normalize(), *(new vec3(1, 0, 0)));

    vec4 v4(3, 0, 0, 0);
    cr_assert_eq(v4.normalize(), *(new vec4(1, 0, 0, 0)));
}

Test(vector, dot)
{
    vec3 v1(2, 3, 4);
    vec3 v2(6, 7, 8);
    cr_assert_eq(v1 * v2, 2 * 6 + 3 * 7 + 4 * 8);

    vec4 v3(2, 3, 4, 5);
    vec4 v4(6, 7, 8, 9);
    cr_assert_eq(v3 * v4, 2 * 6 + 3 * 7 + 4 * 8 + 5 * 9);
}

Test(vector, equality)
{
    vec3 v1(1, 2, 3);
    vec3 v2(1, 2, 3);
    cr_assert_eq(v1, v2);

    v1.x = 2;
    cr_assert_neq(v1, v2);

    vec4 v3(2, 3, 4);
    vec4 v4(2, 3, 4, 1);
    cr_assert_eq(v3, v4);

    v3.w = 2;
    cr_assert_neq(v3, v4);
}

Test(vector, addition)
{
    vec3 v1(1, 2, 3);
    vec3 v2(1, 2, 3);
    cr_assert_eq(v1 + v2, *(new vec3(2, 4, 6)));
    cr_assert_eq(v1, *(new vec3(1, 2, 3)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    v1 += v2;
    cr_assert_eq(v1, *(new vec3(2, 4, 6)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    vec4 v3(1, 2, 3, 4);
    vec4 v4(1, 2, 3, 4);
    cr_assert_eq(v3 + v4, *(new vec4(2, 4, 6, 8)));
    cr_assert_eq(v3, *(new vec4(1, 2, 3, 4)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 4)));

    v3 += v4;
    cr_assert_eq(v3, *(new vec4(2, 4, 6, 8)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 4)));
}

Test(vector, substraction)
{
    vec3 v1(1, 2, 3);
    vec3 v2(1, 2, 3);
    cr_assert_eq(v1 - v2, *(new vec3(0, 0, 0)));
    cr_assert_eq(v1, *(new vec3(1, 2, 3)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    v1 -= v2;
    cr_assert_eq(v1, *(new vec3(0, 0, 0)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    vec4 v3(1, 2, 3, 4);
    vec4 v4(1, 2, 3, 4);
    cr_assert_eq(v3 - v4, *(new vec4(0, 0, 0, 0)));
    cr_assert_eq(v3, *(new vec4(1, 2, 3, 4)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 4)));

    v3 -= v4;
    cr_assert_eq(v3, *(new vec4(0, 0, 0, 0)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 4)));
}