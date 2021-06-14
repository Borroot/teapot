#include <criterion/criterion.h>
#include "math/vector.hh"

Test(vector, vec4_declaration)
{
    vec4 v(2, 3, 4);
    cr_assert_eq(v.w, 1.0);
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