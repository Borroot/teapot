#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <iostream>
#include "math/matrix.hh"

Test(matrix, Mat4_indexing)
{
    Mat4 matrix = Mat4();

    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            matrix[y][x] = y * 4 + x;

    for (short y = 0; y < 4; y++)
        for (short x = 0; x < 4; x++)
            cr_assert_eq(matrix[y][x], y * 4 + x);
}

Test(matrix, Mat4_equality)
{
    Mat4 matrix1 = Mat4();
    Mat4 matrix2 = Mat4();

    for (short y = 0; y < 4; y++)
    {
        for (short x = 0; x < 4; x++)
        {
            matrix1[y][x] = y * 4 + x;
            matrix2[y][x] = y * 4 + x;
        }
    }

    cr_assert_eq(matrix1, matrix2);

    matrix1[3][3] = 0;
    cr_assert_neq(matrix1, matrix2);
}

Test(matrix, Mat4_multiplication)
{
    double m1[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}};

    double m2[4][4] = {
        {7, 8, 9, 0},
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2}};

    Mat4 matrix1(m1);
    Mat4 matrix2(m2);
    Mat4 matrix1_copy(m1);
    Mat4 matrix2_copy(m2);

    Mat4 result(new double[4][4]{
        {60, 30, 40, 40},
        {148, 94, 120, 96},
        {86, 78, 90, 12},
        {104, 62, 80, 68}});

    cr_assert_eq(matrix1 * matrix2, result);
    cr_assert_eq(matrix1, matrix1_copy);
    cr_assert_eq(matrix2, matrix2_copy);

    matrix1 *= matrix2;
    cr_assert_eq(matrix1, result);
    cr_assert_eq(matrix2, matrix2_copy);
}

Test(matrix, Mat4_multiplication_Vec4)
{
    Mat4 matrix(new double[4][4]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 1, 2, 3},
        {4, 5, 6, 7}});

    Vec4 vector = Vec4(4, 6, 8, 2);
    Vec4 result = Vec4(48, 128, 64, 108);

    cr_assert_eq(matrix * vector, result);
}

Test(matrix, Mat4_multiplication_Triangle)
{
    Triangle triangle = Triangle(Vec4(1, 1, 1), Vec4(2, 2, 2), Vec4(3, 3, 3));
    Mat4 trans = Mat4::translate(-1, -1, -1);
    trans * triangle;

    cr_assert_eq(triangle.v0, Vec4(0, 0, 0));
    cr_assert_eq(triangle.v1, Vec4(1, 1, 1));
    cr_assert_eq(triangle.v2, Vec4(2, 2, 2));
}

Test(matrix, Mat4_multiplication_Mesh)
{
    Triangle triangle = Triangle(Vec4(1, 1, 1), Vec4(2, 2, 2), Vec4(3, 3, 3));
    Mat4 trans = Mat4::translate(-1, -1, -1);

    Mesh mesh = Mesh();
    mesh.triangles.push_back(triangle);

    trans * mesh;

    cr_assert_eq(mesh.triangles[0].v0, Vec4(0, 0, 0));
    cr_assert_eq(mesh.triangles[0].v1, Vec4(1, 1, 1));
    cr_assert_eq(mesh.triangles[0].v2, Vec4(2, 2, 2));
}

Test(matrix, Mat4_translate)
{
    Vec4 vector = Vec4(4, 6, 8, 2);
    cr_assert_eq(Mat4::translate(-2, -3, -4) * vector, Vec4(0, 0, 0, 1));
}

Test(matrix, Mat4_scale)
{
    Vec4 vector = Vec4(2, 3, 4, 2);
    cr_assert_eq(Mat4::scale(2, 2, 2) * vector, Vec4(2, 3, 4, 1));
    cr_assert_eq(Mat4::scale(0.5, 0.5, 0.5) * vector, Vec4(2, 3, 4, 4));
}

Test(matrix, Mat4_print, .init = cr_redirect_stdout)
{
    Mat4 matrix(new double[4][4]{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {3, 4, 5, 6}});

    std::cout << matrix;
    cr_assert_stdout_eq_str("1 2 3 4\n5 6 7 8\n9 0 1 2\n3 4 5 6\n");
}