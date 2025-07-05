#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0

/*
@brief Результирующий код
OK = 0
INCORRECT_MATRIX = 1
CALCULATION_ERROR = 2
*/
enum result_code { OK, INCORRECT_MATRIX, CALCULATION_ERROR };

/*
@brief Матрица

@param matrix double
@param rows int
@param columns int
*/
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_check_matrix(matrix_t *matrix);
int s21_compare_size_matrix(matrix_t *A, matrix_t *B);
void s21_set_martix(int rows, int columns, double **matrix, matrix_t *A);
int s21_compare_matrix_elements(matrix_t *A, matrix_t *B);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sum_elements(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_elements(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_elements(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_rows(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
void s21_get_minor_matrix(matrix_t *A, matrix_t *result, int col, int row);
int s21_determinant(matrix_t *A, double *result);
int s21_is_square(matrix_t *A);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif
