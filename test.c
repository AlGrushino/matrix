#include <check.h>
#include <stdio.h>

#include "s21_matrix.h"

// s21_create_matrix
START_TEST(s21_create_matrix_1) {
  matrix_t matrix = {NULL, 0, 0};
  int res = OK;
  int s21_res = s21_create_matrix(1, 1, &matrix);

  ck_assert_int_eq(res, s21_res);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_2) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(1, 1, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_3) {
  matrix_t matrix = {NULL, 0, 0};
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(0, 0, &matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_4) {
  matrix_t matrix = {NULL, 1, 1};
  int res = OK;
  int s21_res = s21_create_matrix(5, 5, &matrix);

  ck_assert_int_eq(res, s21_res);
  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_create_matrix_5) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(0, 0, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_6) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(1, 0, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_7) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(0, 1, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_8) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_create_matrix(1, 1, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_create_matrix_9) {
  int res = OK;
  matrix_t A = {NULL, 5, 5};
  int s21_res = s21_create_matrix(A.rows, A.columns, &A);

  ck_assert_int_eq(res, s21_res);
  s21_remove_matrix(&A);
}
END_TEST

// s21_remove_matrix
START_TEST(s21_remove_matrix_1) {
  matrix_t matrix = {NULL, 5, 5};
  s21_create_matrix(matrix.rows, matrix.columns, &matrix);
  ck_assert_ptr_nonnull(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 5);
  ck_assert_int_eq(matrix.columns, 5);

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

START_TEST(s21_remove_matrix_2) {
  matrix_t matrix = {NULL, 1, 1};
  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 1);
  ck_assert_int_eq(matrix.columns, 1);

  s21_remove_matrix(&matrix);

  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

// s21_set_matrix
START_TEST(s21_set_matrix_1) {
  matrix_t matrix = {NULL, 0, 0};

  s21_set_martix(5, 5, matrix.matrix, &matrix);
  ck_assert_int_eq(matrix.rows, 5);
  ck_assert_int_eq(matrix.columns, 5);

  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(matrix.matrix);
  ck_assert_int_eq(matrix.rows, 0);
  ck_assert_int_eq(matrix.columns, 0);
}
END_TEST

// s21_check_matrix
START_TEST(s21_check_matrix_1) {
  int res = SUCCESS;
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(5, 5, &matrix);
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_check_matrix_2) {
  int res = FAILURE;
  int s21_res = s21_check_matrix(NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_check_matrix_3) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(0, 0, &matrix);
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_check_matrix_4) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(1, 0, &matrix);
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_check_matrix_5) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 0, 0};
  s21_create_matrix(0, 1, &matrix);
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&matrix);
}
END_TEST

START_TEST(s21_check_matrix_6) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 0, 0};
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_check_matrix_7) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 1, 0};
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_check_matrix_8) {
  int res = FAILURE;
  matrix_t matrix = {NULL, 0, 1};
  int s21_res = s21_check_matrix(&matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

// s21_compare_size_matrix
START_TEST(s21_compare_size_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(5, 5, &A);
  s21_create_matrix(5, 5, &B);

  int res = SUCCESS;
  int s21_res = s21_compare_size_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_size_matrix_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 4, &B);

  int res = FAILURE;
  int s21_res = s21_compare_size_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_size_matrix_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 4, &B);

  int res = FAILURE;
  int s21_res = s21_compare_size_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_size_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 2, &B);

  int res = FAILURE;
  int s21_res = s21_compare_size_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// s21_compare_matrix_elements
START_TEST(s21_compare_matrix_elements_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);

  int res = SUCCESS;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_matrix_elements_2) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1;
  B.matrix[0][0] = 1;

  int res = SUCCESS;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_matrix_elements_3) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = SUCCESS;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_matrix_elements_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1111112;
  B.matrix[0][0] = 1.1111111;

  int res = FAILURE;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_matrix_elements_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.11111112;
  B.matrix[0][0] = 1.11111111;

  int res = SUCCESS;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_compare_matrix_elements_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = -1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = FAILURE;
  int s21_res = s21_compare_matrix_elements(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// s21_eq_matrix
START_TEST(s21_eq_matrix_1) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = -1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = FAILURE;
  int s21_res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_2) {
  matrix_t A = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);

  A.matrix[0][0] = -1.1111111;

  int res = FAILURE;
  int s21_res = s21_eq_matrix(&A, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_eq_matrix_3) {
  int res = FAILURE;
  int s21_res = s21_eq_matrix(NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_eq_matrix_4) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = SUCCESS;
  int s21_res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_eq_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = FAILURE;
  int s21_res = s21_eq_matrix(&A, &B);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

// s21_sum_elements
START_TEST(s21_sum_elements_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_sum_elements(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 2.2222222);
  ck_assert_double_eq(res_matrix.matrix[1][1], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_sum_matrix
START_TEST(s21_sum_matrix_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_sum_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 2.2222222);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_2) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_sum_matrix(NULL, NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_sum_matrix_3) {
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_matrix);

  B.matrix[0][0] = 1.1111111;

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sum_matrix(NULL, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_4) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1.1111111;

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sum_matrix(&A, NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_5) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);

  A.matrix[0][0] = 1.1111111;

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sum_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sum_matrix_6) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 3, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &res_matrix);

  int res = CALCULATION_ERROR;
  int s21_res = s21_sum_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sum_matrix_7) {
  matrix_t A = {NULL, 0, 0};
  matrix_t B = {NULL, 0, 0};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 2, &res_matrix);

  int res = CALCULATION_ERROR;
  int s21_res = s21_sum_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_sub_elements
START_TEST(s21_sub_elements_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_sub_elements(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 0);
  ck_assert_double_eq(res_matrix.matrix[1][1], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_sub_matrix
START_TEST(s21_sub_matrix_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1.1111111;
  B.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_sub_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 0);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_2) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_sub_matrix(NULL, NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_sub_matrix_3) {
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(B.rows, B.columns, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sub_matrix(NULL, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&B);
  // s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_4) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  // s21_create_matrix(2, 2, &res_matrix);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sub_matrix(&A, NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  // s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_5) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_sub_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(s21_sub_matrix_6) {
  matrix_t A = {NULL, 2, 3};
  matrix_t B = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  int res = CALCULATION_ERROR;
  int s21_res = s21_sub_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_sub_matrix_7) {
  matrix_t A = {NULL, 2, 2};
  matrix_t B = {NULL, 2, 3};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);
  // s21_create_matrix(2, 2, &res_matrix);

  int res = CALCULATION_ERROR;
  int s21_res = s21_sub_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  // s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_mult_elements
START_TEST(s21_mult_elements_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};
  double num = 2;

  s21_create_matrix(A.rows, A.columns, &A);
  // s21_create_matrix(2, 2, &res_matrix);

  A.matrix[0][0] = 1;
  s21_mult_elements(&A, num, &res_matrix);

  ck_assert_double_eq(res_matrix.matrix[0][0], num);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_mult_number
START_TEST(s21_mult_number_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 2, 2};
  double num = 2;

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_mult_number(&A, num, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 2.2222222);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_mult_number_2) {
  matrix_t A = {NULL, 0, 0};
  double num = 2;

  s21_create_matrix(2, 2, &A);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_number(&A, num, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_mult_number_3) {
  matrix_t res_matrix = {NULL, 2, 2};
  double num = 2;

  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_number(NULL, num, &res_matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_mult_number_4) {
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 2, 2};
  double num = 2;

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1.1111111;

  int res = OK;
  int s21_res = s21_mult_number(&A, num, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_transpose
START_TEST(s21_transpose_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  int res = OK;
  int s21_res = s21_transpose(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 0);
  ck_assert_double_eq(res_matrix.matrix[0][1], 1);
  ck_assert_double_eq(res_matrix.matrix[1][0], 0);
  ck_assert_double_eq(res_matrix.matrix[1][1], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

START_TEST(s21_transpose_2) {
  matrix_t res_matrix = {NULL, 0, 0};

  int res = INCORRECT_MATRIX;
  int s21_res = s21_transpose(NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);
}
END_TEST

START_TEST(s21_transpose_3) {
  matrix_t A = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;

  int res = INCORRECT_MATRIX;
  int s21_res = s21_transpose(&A, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(s21_transpose_4) {
  matrix_t A = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 4;
  A.matrix[1][0] = 2;
  A.matrix[1][1] = 5;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;

  int res = OK;
  int s21_res = s21_transpose(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 1);
  ck_assert_double_eq(res_matrix.matrix[0][1], 2);
  ck_assert_double_eq(res_matrix.matrix[0][2], 3);
  ck_assert_double_eq(res_matrix.matrix[1][0], 4);
  ck_assert_double_eq(res_matrix.matrix[1][1], 5);
  ck_assert_double_eq(res_matrix.matrix[1][2], 6);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}
END_TEST

// s21_mult_rows
START_TEST(s21_mult_rows_1) {
  matrix_t A = {NULL, 2, 3};
  matrix_t B = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;

  B.matrix[0][0] = 4;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 1;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 5;

  int res = OK;
  int s21_res = s21_mult_rows(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 12);
  ck_assert_double_eq(res_matrix.matrix[0][1], 14);
  ck_assert_double_eq(res_matrix.matrix[1][0], 16);
  ck_assert_double_eq(res_matrix.matrix[1][1], 12);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}

// s21_mult_matrix
START_TEST(s21_mult_matrix_1) {
  matrix_t A = {NULL, 2, 3};
  matrix_t B = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;

  B.matrix[0][0] = 4;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 1;
  B.matrix[2][0] = 1;
  B.matrix[2][1] = 5;

  int res = OK;
  int s21_res = s21_mult_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 12);
  ck_assert_double_eq(res_matrix.matrix[0][1], 14);
  ck_assert_double_eq(res_matrix.matrix[1][0], 16);
  ck_assert_double_eq(res_matrix.matrix[1][1], 12);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_mult_matrix_2) {
  matrix_t B = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(B.rows, B.columns, &B);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_matrix(NULL, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&B);
}

START_TEST(s21_mult_matrix_3) {
  matrix_t A = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_matrix(&A, NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_mult_matrix_4) {
  matrix_t A = {NULL, 2, 3};
  matrix_t B = {NULL, 3, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_matrix(&A, &B, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

START_TEST(s21_mult_matrix_5) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_mult_matrix(NULL, NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_mult_matrix_6) {
  matrix_t A = {NULL, 10, 10};
  matrix_t B = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(B.rows, B.columns, &B);

  int res = CALCULATION_ERROR;
  int s21_res = s21_mult_matrix(&A, &B, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}

// s21_get_minor
START_TEST(s21_get_minor_matrix_1) {
  matrix_t A = {NULL, 2, 2};
  matrix_t res_matrix = {NULL, 1, 1};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(res_matrix.rows, res_matrix.columns, &res_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;

  s21_get_minor_matrix(&A, &res_matrix, 0, 0);

  ck_assert_double_eq(res_matrix.matrix[0][0], 4);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_get_minor_matrix_2) {
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(res_matrix.rows, res_matrix.columns, &res_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  s21_get_minor_matrix(&A, &res_matrix, 0, 0);

  ck_assert_double_eq(res_matrix.matrix[0][0], 4);
  ck_assert_double_eq(res_matrix.matrix[0][1], 2);
  ck_assert_double_eq(res_matrix.matrix[1][0], 2);
  ck_assert_double_eq(res_matrix.matrix[1][1], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_get_minor_matrix_3) {
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 2, 2};

  s21_create_matrix(A.rows, A.columns, &A);
  s21_create_matrix(res_matrix.rows, res_matrix.columns, &res_matrix);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  s21_get_minor_matrix(&A, &res_matrix, 1, 1);

  ck_assert_double_eq(res_matrix.matrix[0][0], 1);
  ck_assert_double_eq(res_matrix.matrix[0][1], 3);
  ck_assert_double_eq(res_matrix.matrix[1][0], 5);
  ck_assert_double_eq(res_matrix.matrix[1][1], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

// s21_is_square
START_TEST(s21_is_square_1) {
  matrix_t A = {NULL, 3, 3};

  s21_create_matrix(A.rows, A.columns, &A);

  int res = SUCCESS;
  int s21_res = s21_is_square(&A);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_is_square_2) {
  matrix_t A = {NULL, 3, 2};

  s21_create_matrix(A.rows, A.columns, &A);

  int res = FAILURE;
  int s21_res = s21_is_square(&A);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

// s21_determinant
START_TEST(s21_determinant_1) {
  int res = OK;
  double num = 0;
  double s21_num = 0;
  matrix_t A = {NULL, 3, 3};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  int s21_res = s21_determinant(&A, &s21_num);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(num, s21_num);

  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_2) {
  int res = INCORRECT_MATRIX;
  double s21_num = 0;

  int s21_res = s21_determinant(NULL, &s21_num);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_determinant_3) {
  int res = CALCULATION_ERROR;
  double s21_num = 0;
  matrix_t A = {NULL, 4, 3};

  s21_create_matrix(A.rows, A.columns, &A);
  int s21_res = s21_determinant(&A, &s21_num);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_4) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 3, 3};

  s21_create_matrix(A.rows, A.columns, &A);
  int s21_res = s21_determinant(&A, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_5) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 4, 3};

  s21_create_matrix(A.rows, A.columns, &A);
  int s21_res = s21_determinant(&A, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_6) {
  int res = OK;
  double num = -3;
  double s21_num = 0;
  matrix_t A = {NULL, 3, 3};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1.0;
  A.matrix[0][1] = 2.0;
  A.matrix[0][2] = 3.0;

  A.matrix[1][0] = 4.0;
  A.matrix[1][1] = 5.0;
  A.matrix[1][2] = 6.0;

  A.matrix[2][0] = 7.0;
  A.matrix[2][1] = 8.0;
  A.matrix[2][2] = 10.0;

  int s21_res = s21_determinant(&A, &s21_num);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(num, s21_num);

  s21_remove_matrix(&A);
}

START_TEST(s21_determinant_7) {
  int res = OK;
  double num = 1;
  double s21_num = 0;
  matrix_t A = {NULL, 1, 1};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;

  int s21_res = s21_determinant(&A, &s21_num);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(num, s21_num);

  s21_remove_matrix(&A);
}

// s21_calc_complements
START_TEST(s21_calc_complements_1) {
  int res = OK;
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  int s21_res = s21_calc_complements(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 0);
  ck_assert_double_eq(res_matrix.matrix[0][1], 10);
  ck_assert_double_eq(res_matrix.matrix[0][2], -20);

  ck_assert_double_eq(res_matrix.matrix[1][0], 4);
  ck_assert_double_eq(res_matrix.matrix[1][1], -14);
  ck_assert_double_eq(res_matrix.matrix[1][2], 8);

  ck_assert_double_eq(res_matrix.matrix[2][0], -8);
  ck_assert_double_eq(res_matrix.matrix[2][1], -2);
  ck_assert_double_eq(res_matrix.matrix[2][2], 4);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_calc_complements_2) {
  int res = INCORRECT_MATRIX;
  matrix_t res_matrix = {NULL, 0, 0};

  int s21_res = s21_calc_complements(NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_calc_complements_3) {
  int res = INCORRECT_MATRIX;
  matrix_t A = {NULL, 3, 3};

  int s21_res = s21_calc_complements(&A, NULL);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_calc_complements_4) {
  int res = INCORRECT_MATRIX;
  int s21_res = s21_calc_complements(NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_calc_complements_5) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 3, 2};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  int s21_res = s21_calc_complements(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_calc_complements_6) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 1, 1};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 100;

  int s21_res = s21_calc_complements(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_calc_complements_7) {
  int res = OK;
  matrix_t A = {NULL, 4, 4};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;

  A.matrix[1][0] = -1;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 6;
  A.matrix[1][3] = 7;

  A.matrix[2][0] = 1;
  A.matrix[2][1] = 4;
  A.matrix[2][2] = -13;
  A.matrix[2][3] = 7;

  A.matrix[3][0] = 6;
  A.matrix[3][1] = 3;
  A.matrix[3][2] = 4;
  A.matrix[3][3] = -77;

  int s21_res = s21_calc_complements(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 4305);
  ck_assert_double_eq(res_matrix.matrix[0][1], -315);
  ck_assert_double_eq(res_matrix.matrix[0][2], 420);
  ck_assert_double_eq(res_matrix.matrix[0][3], 345);

  ck_assert_double_eq(res_matrix.matrix[1][0], -3153);
  ck_assert_double_eq(res_matrix.matrix[1][1], 1658);
  ck_assert_double_eq(res_matrix.matrix[1][2], 175);
  ck_assert_double_eq(res_matrix.matrix[1][3], -172);

  ck_assert_double_eq(res_matrix.matrix[2][0], -495);
  ck_assert_double_eq(res_matrix.matrix[2][1], 755);
  ck_assert_double_eq(res_matrix.matrix[2][2], -305);
  ck_assert_double_eq(res_matrix.matrix[2][3], -25);

  ck_assert_double_eq(res_matrix.matrix[3][0], -108);
  ck_assert_double_eq(res_matrix.matrix[3][1], 203);
  ck_assert_double_eq(res_matrix.matrix[3][2], 10);
  ck_assert_double_eq(res_matrix.matrix[3][3], -82);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

// s21_inverse_matrix
START_TEST(s21_inverse_matrix_1) {
  int res = OK;
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;

  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 1);
  ck_assert_double_eq(res_matrix.matrix[0][1], -1);
  ck_assert_double_eq(res_matrix.matrix[0][2], 1);

  ck_assert_double_eq(res_matrix.matrix[1][0], -38);
  ck_assert_double_eq(res_matrix.matrix[1][1], 41);
  ck_assert_double_eq(res_matrix.matrix[1][2], -34);

  ck_assert_double_eq(res_matrix.matrix[2][0], 27);
  ck_assert_double_eq(res_matrix.matrix[2][1], -29);
  ck_assert_double_eq(res_matrix.matrix[2][2], 24);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_inverse_matrix_2) {
  int res = INCORRECT_MATRIX;
  matrix_t res_matrix = {NULL, 0, 0};

  int s21_res = s21_inverse_matrix(NULL, &res_matrix);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_inverse_matrix_3) {
  int res = INCORRECT_MATRIX;
  matrix_t A = {NULL, 3, 3};

  s21_create_matrix(A.rows, A.columns, &A);

  int s21_res = s21_inverse_matrix(&A, NULL);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_inverse_matrix_4) {
  int res = INCORRECT_MATRIX;

  int s21_res = s21_inverse_matrix(NULL, NULL);

  ck_assert_int_eq(res, s21_res);
}

START_TEST(s21_inverse_matrix_5) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 3, 4};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_inverse_matrix_6) {
  int res = CALCULATION_ERROR;
  matrix_t A = {NULL, 3, 3};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 2;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 6;

  A.matrix[2][0] = 3;
  A.matrix[2][1] = 6;
  A.matrix[2][2] = 9;

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  s21_remove_matrix(&A);
}

START_TEST(s21_inverse_matrix_7) {
  int res = OK;
  matrix_t A = {NULL, 1, 1};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_inverse_matrix_8) {
  int res = OK;
  matrix_t A = {NULL, 1, 1};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 100;

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);
  ck_assert_double_eq(res_matrix.matrix[0][0], 0.01);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

START_TEST(s21_inverse_matrix_9) {
  int res = OK;
  matrix_t A = {NULL, 4, 4};
  matrix_t res_matrix = {NULL, 0, 0};

  s21_create_matrix(A.rows, A.columns, &A);

  A.matrix[0][0] = 1;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[0][3] = 0;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 0;
  A.matrix[1][3] = 0;

  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  A.matrix[2][3] = 0;

  A.matrix[3][0] = 0;
  A.matrix[3][1] = 0;
  A.matrix[3][2] = 0;
  A.matrix[3][3] = 1;

  int s21_res = s21_inverse_matrix(&A, &res_matrix);

  ck_assert_int_eq(res, s21_res);

  ck_assert_double_eq(res_matrix.matrix[0][0], 1);
  ck_assert_double_eq(res_matrix.matrix[0][1], 0);
  ck_assert_double_eq(res_matrix.matrix[0][2], 0);
  ck_assert_double_eq(res_matrix.matrix[0][3], 0);

  ck_assert_double_eq(res_matrix.matrix[1][0], 0);
  ck_assert_double_eq(res_matrix.matrix[1][1], 1);
  ck_assert_double_eq(res_matrix.matrix[1][2], 0);
  ck_assert_double_eq(res_matrix.matrix[1][3], 0);

  ck_assert_double_eq(res_matrix.matrix[2][0], 0);
  ck_assert_double_eq(res_matrix.matrix[2][1], 0);
  ck_assert_double_eq(res_matrix.matrix[2][2], 1);
  ck_assert_double_eq(res_matrix.matrix[2][3], 0);

  ck_assert_double_eq(res_matrix.matrix[3][0], 0);
  ck_assert_double_eq(res_matrix.matrix[3][1], 0);
  ck_assert_double_eq(res_matrix.matrix[3][2], 0);
  ck_assert_double_eq(res_matrix.matrix[3][3], 1);

  s21_remove_matrix(&A);
  s21_remove_matrix(&res_matrix);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  suite_add_tcase(s1, tc1_1);

  //   s21_create_matrix
  tcase_add_test(tc1_1, s21_create_matrix_1);
  tcase_add_test(tc1_1, s21_create_matrix_2);
  tcase_add_test(tc1_1, s21_create_matrix_3);
  tcase_add_test(tc1_1, s21_create_matrix_4);
  tcase_add_test(tc1_1, s21_create_matrix_5);
  tcase_add_test(tc1_1, s21_create_matrix_6);
  tcase_add_test(tc1_1, s21_create_matrix_7);
  tcase_add_test(tc1_1, s21_create_matrix_8);
  tcase_add_test(tc1_1, s21_create_matrix_9);

  // s21_remove_matrix
  tcase_add_test(tc1_1, s21_remove_matrix_1);
  tcase_add_test(tc1_1, s21_remove_matrix_2);

  // s21_set_matrix
  tcase_add_test(tc1_1, s21_set_matrix_1);

  // s21_check_matrix
  tcase_add_test(tc1_1, s21_check_matrix_1);
  tcase_add_test(tc1_1, s21_check_matrix_2);
  tcase_add_test(tc1_1, s21_check_matrix_3);
  tcase_add_test(tc1_1, s21_check_matrix_4);
  tcase_add_test(tc1_1, s21_check_matrix_5);
  tcase_add_test(tc1_1, s21_check_matrix_6);
  tcase_add_test(tc1_1, s21_check_matrix_7);
  tcase_add_test(tc1_1, s21_check_matrix_8);

  // s21_compare_size_matrix
  tcase_add_test(tc1_1, s21_compare_size_matrix_1);
  tcase_add_test(tc1_1, s21_compare_size_matrix_2);
  tcase_add_test(tc1_1, s21_compare_size_matrix_3);
  tcase_add_test(tc1_1, s21_compare_size_matrix_4);

  // s21_compare_matrix_elements
  tcase_add_test(tc1_1, s21_compare_matrix_elements_1);
  tcase_add_test(tc1_1, s21_compare_matrix_elements_2);
  tcase_add_test(tc1_1, s21_compare_matrix_elements_3);
  tcase_add_test(tc1_1, s21_compare_matrix_elements_4);
  tcase_add_test(tc1_1, s21_compare_matrix_elements_5);
  tcase_add_test(tc1_1, s21_compare_matrix_elements_6);

  // s21_eq_matrix
  tcase_add_test(tc1_1, s21_eq_matrix_1);
  tcase_add_test(tc1_1, s21_eq_matrix_2);
  tcase_add_test(tc1_1, s21_eq_matrix_3);
  tcase_add_test(tc1_1, s21_eq_matrix_4);
  tcase_add_test(tc1_1, s21_eq_matrix_5);

  // s21_sum_elements
  tcase_add_test(tc1_1, s21_sum_elements_1);

  // s21_sum_matrix
  tcase_add_test(tc1_1, s21_sum_matrix_1);
  tcase_add_test(tc1_1, s21_sum_matrix_2);
  tcase_add_test(tc1_1, s21_sum_matrix_3);
  tcase_add_test(tc1_1, s21_sum_matrix_4);
  tcase_add_test(tc1_1, s21_sum_matrix_5);
  tcase_add_test(tc1_1, s21_sum_matrix_6);
  tcase_add_test(tc1_1, s21_sum_matrix_7);

  // s21_sub_elements
  tcase_add_test(tc1_1, s21_sub_elements_1);

  // s21_sub_matrix
  tcase_add_test(tc1_1, s21_sub_matrix_1);
  tcase_add_test(tc1_1, s21_sub_matrix_2);
  tcase_add_test(tc1_1, s21_sub_matrix_3);
  tcase_add_test(tc1_1, s21_sub_matrix_4);
  tcase_add_test(tc1_1, s21_sub_matrix_5);
  tcase_add_test(tc1_1, s21_sub_matrix_6);
  tcase_add_test(tc1_1, s21_sub_matrix_7);

  // s21_mult_elements
  tcase_add_test(tc1_1, s21_mult_elements_1);

  // s21_mult_number
  tcase_add_test(tc1_1, s21_mult_number_1);
  tcase_add_test(tc1_1, s21_mult_number_2);
  tcase_add_test(tc1_1, s21_mult_number_3);
  tcase_add_test(tc1_1, s21_mult_number_4);

  // s21_transpose
  tcase_add_test(tc1_1, s21_transpose_1);
  tcase_add_test(tc1_1, s21_transpose_2);
  tcase_add_test(tc1_1, s21_transpose_3);
  tcase_add_test(tc1_1, s21_transpose_4);

  // s21_mult_rows
  tcase_add_test(tc1_1, s21_mult_rows_1);

  // s21_mult_matrix
  tcase_add_test(tc1_1, s21_mult_matrix_1);
  tcase_add_test(tc1_1, s21_mult_matrix_2);
  tcase_add_test(tc1_1, s21_mult_matrix_3);
  tcase_add_test(tc1_1, s21_mult_matrix_4);
  tcase_add_test(tc1_1, s21_mult_matrix_5);
  tcase_add_test(tc1_1, s21_mult_matrix_6);

  // s21_get_minor_matrix
  tcase_add_test(tc1_1, s21_get_minor_matrix_1);
  tcase_add_test(tc1_1, s21_get_minor_matrix_2);
  tcase_add_test(tc1_1, s21_get_minor_matrix_3);

  // s21_is_square
  tcase_add_test(tc1_1, s21_is_square_1);
  tcase_add_test(tc1_1, s21_is_square_2);

  // s21_determinant
  tcase_add_test(tc1_1, s21_determinant_1);
  tcase_add_test(tc1_1, s21_determinant_2);
  tcase_add_test(tc1_1, s21_determinant_3);
  tcase_add_test(tc1_1, s21_determinant_4);
  tcase_add_test(tc1_1, s21_determinant_5);
  tcase_add_test(tc1_1, s21_determinant_6);
  tcase_add_test(tc1_1, s21_determinant_7);

  // s21_calc_complements
  tcase_add_test(tc1_1, s21_calc_complements_1);
  tcase_add_test(tc1_1, s21_calc_complements_2);
  tcase_add_test(tc1_1, s21_calc_complements_3);
  tcase_add_test(tc1_1, s21_calc_complements_4);
  tcase_add_test(tc1_1, s21_calc_complements_5);
  tcase_add_test(tc1_1, s21_calc_complements_6);
  tcase_add_test(tc1_1, s21_calc_complements_7);

  // s21_inverse_matrix
  tcase_add_test(tc1_1, s21_inverse_matrix_1);
  tcase_add_test(tc1_1, s21_inverse_matrix_2);
  tcase_add_test(tc1_1, s21_inverse_matrix_3);
  tcase_add_test(tc1_1, s21_inverse_matrix_4);
  tcase_add_test(tc1_1, s21_inverse_matrix_5);
  tcase_add_test(tc1_1, s21_inverse_matrix_6);
  tcase_add_test(tc1_1, s21_inverse_matrix_7);
  tcase_add_test(tc1_1, s21_inverse_matrix_8);
  tcase_add_test(tc1_1, s21_inverse_matrix_9);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  srunner_ntests_failed(sr);

  srunner_free(sr);

  return 0;
}
