#include "s21_matrix.h"

/*
@brief Создаёт матрицу

@param rows int
@param columns int
@param result matrix_t*

@returns int OK, INCORRECT_MATRIX
*/
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (!result || rows < 1 || columns < 1) return INCORRECT_MATRIX;

  double **matrix = (double **)calloc(rows, sizeof(double *));

  for (size_t i = 0; i < (size_t)rows; i++) {
    matrix[i] = (double *)calloc(columns, sizeof(double));
  }

  s21_set_martix(rows, columns, matrix, result);

  return OK;
}

/*
@brief Освобождает память матрицы и зануляет её поля

@param A matrix_t*

@returns void
*/
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix) {
    for (size_t i = 0; i < (size_t)A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
  A->rows = 0;
  A->columns = 0;
  A->matrix = NULL;
}

/*
@brief Сравнивает две матрицы

@param A matrix_t*
@param B matrix_t*

@returns int SUCCESS, FAILURE
*/
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (!s21_check_matrix(A) || !s21_check_matrix(B) ||
      !s21_compare_size_matrix(A, B)) {
    return FAILURE;
  }

  return s21_compare_matrix_elements(A, B);
}

/*
@brief Складывает две матрицы

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int OK, INCORRECT_MATRIX, CALCULATION_ERROR
*/
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (!s21_check_matrix(A) || !s21_check_matrix(B) || !result) {
    return INCORRECT_MATRIX;
  }

  if (!s21_compare_size_matrix(A, B)) {
    res_code = CALCULATION_ERROR;
  }

  if (!res_code) {
    res_code = s21_sum_elements(A, B, result);
  }

  return res_code;
}

/*
@brief Находит разность lдвух матриц

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int OK, INCORRECT_MATRIX, CALCULATION_ERROR
*/
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (!s21_check_matrix(A) || !s21_check_matrix(B) || !result) {
    return INCORRECT_MATRIX;
  }

  if (!s21_compare_size_matrix(A, B)) {
    res_code = CALCULATION_ERROR;
  }

  if (!res_code) {
    res_code = s21_sub_elements(A, B, result);
  }

  return res_code;
}

/*
@brief Проверяет корректность полей матрицы и указатель на матрицу

@param A matrix_t*

@returns int SUCCESS, FAILURE
*/
int s21_check_matrix(matrix_t *A) {
  int res_code = SUCCESS;

  if (!A || A->rows < 1 || A->columns < 1) {
    res_code = FAILURE;
  }

  return res_code;
}

/*
@brief Сравнивает размеры двух матриц

@param A matrix_t*
@param B matrix_t*

@returns int SUCCESS, FAILURE
*/
int s21_compare_size_matrix(matrix_t *A, matrix_t *B) {
  int res_code = SUCCESS;

  if (A->columns != B->columns || A->rows != B->rows) {
    res_code = FAILURE;
  }

  return res_code;
}

/*
@brief Устанавливает параметры матрицы

@param rows int
@param columns int
@param matrix double**
@param A matrix_t*

@returns void
*/
void s21_set_martix(int rows, int columns, double **matrix, matrix_t *A) {
  A->rows = rows;
  A->columns = columns;
  A->matrix = matrix;
}

/*
@brief Сравнивает элементы двух матриц

@param A matrix_t*
@param B matrix_t*

@returns int SUCCESS, FAILURE
*/
int s21_compare_matrix_elements(matrix_t *A, matrix_t *B) {
  int res_code = SUCCESS;
  const size_t ROWS = A->rows;
  const size_t COLUMNS = A->columns;
  const double EPSILON = 1e-7;

  for (size_t i = 0; res_code && i < ROWS; i++) {
    for (size_t j = 0; res_code && j < COLUMNS; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        res_code = FAILURE;
      }
    }
  }

  return res_code;
}

/*
@brief Складывает элементы двух матриц

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int INCORRECT_MATRIX, OK
*/
int s21_sum_elements(matrix_t *A, matrix_t *B, matrix_t *result) {
  result->rows = A->rows;
  result->columns = A->columns;

  s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS = result->rows;
  const size_t COLUMNS = result->columns;

  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLUMNS; j++) {
      result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
    }
  }

  return OK;
}

/*
@brief Вычитает элементы двух матриц

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int INCORRECT_MATRIX, OK
*/
int s21_sub_elements(matrix_t *A, matrix_t *B, matrix_t *result) {
  result->rows = A->rows;
  result->columns = A->columns;

  s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS = result->rows;
  const size_t COLUMNS = result->columns;

  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLUMNS; j++) {
      result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
    }
  }

  return OK;
}

/*
@brief Умножает матрицу на число

@param A matrix_t*
@param number double
@param result matrix_t*

@returns int CALCULATION_ERROR, INCORRECT_MATRIX, OK
*/
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (!s21_check_matrix(A) || !result) {
    return INCORRECT_MATRIX;
  }

  int res_code = s21_mult_elements(A, number, result);

  return res_code;
}

/*
@brief Умножает элементы матрицы на число

@param A matrix_t*
@param number double
@param result matrix_t*

@returns int INCORRECT_MATRIX, OK
*/
int s21_mult_elements(matrix_t *A, double number, matrix_t *result) {
  result->rows = A->rows;
  result->columns = A->columns;

  s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS = A->rows;
  const size_t COLUMNS = A->columns;

  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLUMNS; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  }

  return OK;
}

/*
@brief Перемножает две матрицы

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int CALCULATION_ERROR, INCORRECT_MATRIX, OK
*/
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res_code = OK;

  if (!s21_check_matrix(A) || !s21_check_matrix(B) || !result)
    return INCORRECT_MATRIX;

  if (A->columns != B->rows) res_code = CALCULATION_ERROR;

  if (!res_code) {
    result->rows = A->rows;
    result->columns = B->columns;
    res_code = s21_mult_rows(A, B, result);
  }

  return res_code;
}

/*
@brief Записывает значения умножения в результирующую матрицу

@param A matrix_t*
@param B matrix_t*
@param result matrix_t*

@returns int INCORRECT_MATRIX, OK
*/
int s21_mult_rows(matrix_t *A, matrix_t *B, matrix_t *result) {
  s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS_A = A->rows;
  const size_t ROWS_B = B->rows;
  const size_t COLUMNS_B = B->columns;

  for (size_t i = 0; i < ROWS_A; i++) {
    for (size_t j = 0; j < COLUMNS_B; j++) {
      for (size_t k = 0; k < ROWS_B; k++) {
        result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
    }
  }

  return OK;
}

/*
@brief Транспонирует матрицу

@param A matrix_t*
@param result matrix_t*

@returns int INCORRECT_MATRIX, OK
*/
int s21_transpose(matrix_t *A, matrix_t *result) {
  int res_code = OK;

  if (!s21_check_matrix(A) || !result) return INCORRECT_MATRIX;

  result->rows = A->columns;
  result->columns = A->rows;
  res_code = s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS = A->rows;
  const size_t COLUMNS = A->columns;

  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLUMNS; j++) {
      result->matrix[j][i] = A->matrix[i][j];
    }
  }

  return res_code;
}

/*
@brief Проверяет, является ли матрица квадратной;

@param A matrix_t*

// пихать только валидные матрицы
@returns int SUCCESS, FAILURE
*/
int s21_is_square(matrix_t *A) {
  int res_code = SUCCESS;

  if (A->rows != A->columns) res_code = FAILURE;

  return res_code;
}

/*
@brief помещает в result матрицу, у которой удалён один столбец и строка

@param A matrix_t*
@param result matrix_t*
@param int col
@param int row

// пихать только валидные аргументы
// заполняет резалт элементами оригинальной матрицы, исключая столбец и
// колонку элемента, детерминант которого мы ищем
@returns void
*/
void s21_get_minor_matrix(matrix_t *A, matrix_t *result, int col, int row) {
  size_t EXCLUDE_ROW = row;
  size_t EXCLUDE_COL = col;
  size_t ROWS = A->rows;
  size_t COLS = A->columns;

  for (size_t i = 0, i_counter = 0; i < ROWS; i++) {
    if (i != EXCLUDE_ROW) {
      for (size_t j = 0, j_counter = 0; j < COLS; j++) {
        if (j != EXCLUDE_COL) {
          result->matrix[i_counter][j_counter] = A->matrix[i][j];
          j_counter++;
        }
      }
      i_counter++;
    }
  }
}

/*
@brief находит детерминант матрицы

@param A matrix_t*
@param result double*

@returns int OK, INCORRECT_MATRIX, CALCULATION_ERROR
*/
int s21_determinant(matrix_t *A, double *result) {
  int res_code = OK;

  if (!s21_check_matrix(A)) {
    return INCORRECT_MATRIX;
  }
  if (!s21_is_square(A) || !result) {
    return CALCULATION_ERROR;
  }

  double temp = 0.0, current_determinant = 0.0;
  switch (A->columns) {
    case 1:
      *result = A->matrix[0][0];
      break;
    case 2:
      *result =
          A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
      break;
    default:
      for (size_t j = 0; j < (size_t)A->columns; j++) {
        matrix_t minor = {NULL, A->rows - 1, A->columns - 1};
        res_code = s21_create_matrix(minor.rows, minor.columns, &minor);
        s21_get_minor_matrix(A, &minor, j, 0);
        res_code = s21_determinant(&minor, &current_determinant);
        temp += pow(-1, j) * A->matrix[0][j] * current_determinant;
        s21_remove_matrix(&minor);
      }
      *result = temp;
      break;
  }
  return res_code;
}

/*
@brief создаёт матрицу из детерминантов

@param A matrix_t*
@param result matrix_t*

@returns int OK, INCORRECT_MATRIX, CALCULATION_ERROR
*/
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A) || !result) {
    return INCORRECT_MATRIX;
  }
  if (!s21_is_square(A) || A->rows == 1) {
    return CALCULATION_ERROR;
  }

  result->rows = A->rows;
  result->columns = A->columns;

  int res_code = s21_create_matrix(result->rows, result->columns, result);

  const size_t ROWS = A->rows;
  const size_t COLS = A->columns;

  for (size_t i = 0; i < ROWS; i++) {
    for (size_t j = 0; j < COLS; j++) {
      matrix_t minor = {NULL, A->rows - 1, A->columns - 1};
      res_code = s21_create_matrix(minor.rows, minor.columns, &minor);
      s21_get_minor_matrix(A, &minor, j, i);

      double temp_res = 0.0;
      res_code = s21_determinant(&minor, &temp_res);
      result->matrix[i][j] = pow(-1, i + j) * temp_res;

      s21_remove_matrix(&minor);
    }
  }
  return res_code;
}

/*
@brief создаёт обратную матрицу

@param A matrix_t*
@param result matrix_t*

@returns int OK, INCORRECT_MATRIX, CALCULATION_ERROR
*/
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  if (!s21_check_matrix(A) || !result) {
    return INCORRECT_MATRIX;
  }
  if (!s21_is_square(A)) {
    return CALCULATION_ERROR;
  }

  double determinant = 0.0;
  int res_code = s21_determinant(A, &determinant);

  if (determinant != 0) {
    if (A->rows == 1) {
      result->rows = 1;
      result->columns = 1;

      res_code = s21_create_matrix(result->rows, result->columns, result);

      result->matrix[0][0] = 1 / A->matrix[0][0];
    } else {
      matrix_t complements_matrix = {NULL, 0, 0};
      matrix_t transposed_matrix = {NULL, 0, 0};

      res_code = s21_calc_complements(A, &complements_matrix);
      res_code = s21_transpose(&complements_matrix, &transposed_matrix);
      res_code = s21_mult_number(&transposed_matrix, 1.0 / determinant, result);

      s21_remove_matrix(&complements_matrix);
      s21_remove_matrix(&transposed_matrix);
    }
  } else {
    res_code = CALCULATION_ERROR;
  }
  return res_code;
}
