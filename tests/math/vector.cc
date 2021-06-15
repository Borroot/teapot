#include <criterion/criterion.h>
#include <math.h>
#include <stdexcept>
#include "math/vector.hh"

Test(vector, vec4_declaration)
{
    vec4 v(2, 3, 4);
    cr_assert_eq(v.w, 1);
    cr_assert_throw(new vec4(1, 1, 1, 0), std::domain_error);
}

Test(vector, length)
{
    vec3 v1(3, 2, 1);
    cr_assert_float_eq(v1.length(), sqrt(14), 0.1);

    vec4 v2(3, 2, 1, 1);
    vec4 v3(6, 4, 2, 2);
    cr_assert_float_eq(v2.length(), sqrt(14), 0.1);
    cr_assert_float_eq(v3.length(), sqrt(14), 0.1);
}

Test(vector, normalize)
{
    vec3 v1(0, 0, 0);
    cr_assert_eq(v1.normalize(), *(new vec3(0, 0, 0)));

    vec3 v2(1, 0, 0);
    vec3 v3(3, 0, 0);
    cr_assert_eq(v2.normalize(), *(new vec3(1, 0, 0)));
    cr_assert_eq(v3.normalize(), *(new vec3(1, 0, 0)));

    vec4 v4(3, 0, 0);
    cr_assert_eq(v4.normalize(), *(new vec4(1, 0, 0, 1)));

    vec3 v5(2, -3, 4);
    cr_assert_float_eq(v5.normalize().length(), 1, 0.01);

    vec4 v6(2, -3, 4, 7);
    cr_assert_float_eq(v6.normalize().length(), 1, 0.01);
    cr_assert_float_eq(v6.w, 1, 0.01);
}

Test(vector, dot)
{
    vec3 v1(2, 3, 4);
    vec3 v2(6, 7, 8);
    cr_assert_eq(v1 * v2, 2 * 6 + 3 * 7 + 4 * 8);

    vec4 v3(2, 3, 4, 1);
    vec4 v4(6, 7, 8, 1);
    cr_assert_eq(v3 * v4, 2 * 6 + 3 * 7 + 4 * 8);

    vec4 v5(4, 6, 8, 2);
    vec4 v6(12, 14, 16, 2);
    cr_assert_eq(v5 * v6, 2 * 6 + 3 * 7 + 4 * 8);

    vec4 v7(6, 7, 8, 1);
    v7.w = 0;
    cr_assert_throw(v6 * v7, std::domain_error);
    cr_assert_throw(v7 * v6, std::domain_error);
}

Test(vector, cross)
{
    vec3 v1(1, 0, 0);
    vec3 v2(0, 1, 0);
    cr_assert_eq(v1 ^ v2, *(new vec3(0, 0, 1)));
    cr_assert_eq(v1, *(new vec3(1, 0, 0)));
    cr_assert_eq(v2, *(new vec3(0, 1, 0)));

    v1 ^= v2;
    cr_assert_eq(v1, *(new vec3(0, 0, 1)));
    cr_assert_eq(v2, *(new vec3(0, 1, 0)));

    vec3 v3(2, 4, 7);
    vec3 v4(5, 4, 2);
    cr_assert_eq(v3 ^ v4, *(new vec3(-20, 31, -12)));

    vec4 v5(1, 0, 0);
    vec4 v6(0, 1, 0);
    cr_assert_eq(v5 ^ v6, *(new vec4(0, 0, 1, 1)));
    cr_assert_eq(v5, *(new vec4(1, 0, 0, 1)));
    cr_assert_eq(v6, *(new vec4(0, 1, 0, 1)));

    v5 ^= v6;
    cr_assert_eq(v5, *(new vec4(0, 0, 1, 1)));
    cr_assert_eq(v6, *(new vec4(0, 1, 0, 1)));

    vec4 v7(2, 4, 7);
    vec4 v8(5, 4, 2);
    cr_assert_eq(v7 ^ v8, *(new vec4(-20, 31, -12, 1)));

    vec4 v9(4, 8, 14, 2);
    vec4 v0(10, 8, 4, 2);
    cr_assert_eq(v9 ^ v0, *(new vec4(-20, 31, -12, 1)));

    vec4 v10(1, 2, 3, 1);
    v10.w = 0;
    cr_assert_throw(v10 ^ v0, std::domain_error);
    cr_assert_throw(v0 ^ v10, std::domain_error);
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

    vec4 v5(2, 4, 6, 2);
    vec4 v6(3, 6, 9, 3);
    cr_assert_eq(v5, v6);
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

    vec4 v3(1, 2, 3, 1);
    vec4 v4(1, 2, 3, 1);
    cr_assert_eq(v3 + v4, *(new vec4(2, 4, 6, 1)));
    cr_assert_eq(v3, *(new vec4(1, 2, 3, 1)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 1)));

    v3 += v4;
    cr_assert_eq(v3, *(new vec4(2, 4, 6, 1)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 1)));

    vec4 v5(2, 4, 6, 2);
    vec4 v6(3, 6, 9, 3);
    cr_assert_eq(v5 + v6, *(new vec4(2, 4, 6, 1)));

    vec4 v7(1, 2, 3, 1);
    v7.w = 0;
    cr_assert_throw(v6 + v7, std::domain_error);
    cr_assert_throw(v7 + v6, std::domain_error);
}

Test(vector, subtraction)
{
    vec3 v1(1, 2, 3);
    vec3 v2(1, 2, 3);
    cr_assert_eq(v1 - v2, *(new vec3(0, 0, 0)));
    cr_assert_eq(v1, *(new vec3(1, 2, 3)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    v1 -= v2;
    cr_assert_eq(v1, *(new vec3(0, 0, 0)));
    cr_assert_eq(v2, *(new vec3(1, 2, 3)));

    vec4 v3(1, 2, 3, 1);
    vec4 v4(1, 2, 3, 1);
    cr_assert_eq(v3 - v4, *(new vec4(0, 0, 0, 1)));
    cr_assert_eq(v3, *(new vec4(1, 2, 3, 1)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 1)));

    v3 -= v4;
    cr_assert_eq(v3, *(new vec4(0, 0, 0, 1)));
    cr_assert_eq(v4, *(new vec4(1, 2, 3, 1)));

    vec4 v5(2, 4, 6, 2);
    vec4 v6(3, 6, 9, 3);
    cr_assert_eq(v5 - v6, *(new vec4(0, 0, 0, 1)));

    vec4 v7(1, 2, 3, 1);
    v7.w = 0;
    cr_assert_throw(v6 - v7, std::domain_error);
    cr_assert_throw(v7 - v6, std::domain_error);
}

Test(vector, casting)
{
    vec3 v1(2, 3, 4);
    cr_assert_eq((vec4)v1, *(new vec4(2, 3, 4, 1)));

    vec4 v2(2, 3, 4, 1);
    vec4 v3(9, 3, 6, 3);
    cr_assert_eq((vec3)v2, *(new vec3(2, 3, 4)));
    cr_assert_eq((vec3)v3, *(new vec3(3, 1, 2)));

    vec4 v4(2, 3, 4, 1);
    v4.w = 0;
    cr_assert_throw((vec3)v4, std::domain_error);
}