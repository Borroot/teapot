#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "math/matrix.hh"

void setup_stdout()
{
    cr_redirect_stdout();
}

Test(matrix, mat4_print, .init = setup_stdout)
{
    mat4 matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}};

    std::cout << matrix;
    cr_assert_stdout_eq_str("1 2 3 4\n5 6 7 8\n9 0 1 2\n3 4 5 6\n");
}