#include "s21_matrix.h"

int s21_minor(matrix_t *A, int row, int column, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A) && A->rows == A->columns) {
    if (s21_create_matrix(A->rows - 1, A->columns - 1, result) == 0 &&
        row < A->rows && column < A->columns) {
      error = OK;
      int n = -1;
      for (int i = 0; i < A->rows; i++) {
        if (i != row) {
          n++;
          int m = -1;
          for (int j = 0; j < A->columns; j++) {
            if (j != column) {
              m++;
              result->matrix[n][m] = A->matrix[i][j];
            }
          }
        }
      }
    } else {
      error = CALC_ERROR;
    }
  }
  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = FAIL;
  if (is_okay(A)) {
    error = OK;
    if (A->rows != A->columns) {
      error = CALC_ERROR;
    } else {
      if (A->rows == 1 && A->columns == 1) {
        *result = A->matrix[0][0];
      } else {
        int sign = 1;
        *result = 0;
        for (int j = 0; j < A->columns; j++) {
          matrix_t temp_matrix;
          int create = s21_minor(A, 0, j, &temp_matrix);
          if (create == 0) {
            double temp_res = 0;
            int status = s21_determinant(&temp_matrix, &temp_res);
            if (status == 0) {
              *result += A->matrix[0][j] * temp_res * sign;
              sign *= -1;
            }
            s21_remove_matrix(&temp_matrix);
          }
        }
      }
    }
  }
  return error;
}
