#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "math/matrix.hh"

Test(matrix, mat4_indexing)
{
    mat4 matrix = mat4();

    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            matrix[y][x] = y * 4 + x;

    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            cr_assert_eq(matrix[y][x], y * 4 + x);
}

Test(matrix, mat4_equality)
{
    mat4 matrix1 = mat4();
    mat4 matrix2 = mat4();

    for (short y = 0; y < 4; y++) {
        for (short x = 0; x < 4; x++) {
            matrix1[y][x] = y * 4 + x;
            matrix2[y][x] = y * 4 + x;
        }
    }

    cr_assert_eq(matrix1, matrix2);

    matrix1[3][3] = 0;
    cr_assert_neq(matrix1, matrix2);
}

Test(matrix, mat4_multiplication)
{
    mat4 matrix1(new double[4][4] {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}});

    mat4 matrix2(new double[4][4] {
        {7, 8, 9, 0},
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2}});

    mat4 result(new double[4][4] {
        { 60, 30,  40, 40},
        {148, 94, 120, 96},
        { 86, 78,  90, 12},
        {104, 62,  80, 68}});

    cr_assert_eq(matrix1 * matrix2, result);
}

Test(matrix, mat4_print, .init = cr_redirect_stdout)
{
    mat4 matrix(new double[4][4] {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}});

    std::cout << matrix;
    cr_assert_stdout_eq_str("1 2 3 4\n5 6 7 8\n9 0 1 2\n3 4 5 6\n");
}