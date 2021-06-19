#include <criterion/criterion.h>
#include "math/common.hh"

Test(min, simple)
{
    cr_assert_eq(min(3, 3.14, -1.5, 16.7), -1.5);
    cr_assert_eq(min(3, -1.5, 3.14, 16.7), -1.5);
    cr_assert_eq(min(3, -1.5, 16.7, 3.14), -1.5);
    cr_assert_eq(min(3, 16.7, 3.14, -1.5), -1.5);
}

Test(max, simple)
{
    cr_assert_eq(max(3, 3.14, -1.5, 16.7), 16.7);
    cr_assert_eq(max(3, -1.5, 3.14, 16.7), 16.7);
    cr_assert_eq(max(3, -1.5, 16.7, 3.14), 16.7);
    cr_assert_eq(max(3, 16.7, 3.14, -1.5), 16.7);
}