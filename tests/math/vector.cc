#include <criterion/criterion.h>
#include "math/vector.hh"

Test(vector, vec4_declaration)
{
    vec4 v = {1, 2, 3};
    cr_assert_eq(v.w, 1);
}