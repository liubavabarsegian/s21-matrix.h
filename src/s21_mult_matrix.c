#include "s21_matrix.h"

int s21_can_be_multiplied(matrix_t *A, matrix_t *B) {
  return (A->columns == B->rows);
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A) && is_okay(B)) {
    if (!s21_can_be_multiplied(A, B)) {
      error = CALC_ERROR;
    } else {
      if (s21_create_matrix(A->rows, B->columns, result) == 0) {
        result->rows = A->rows;
        result->columns = B->columns;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            result->matrix[i][j] = 0;
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
        error = OK;
      } else {
        error = FAIL;
      }
    }
  }
  return error;
}
