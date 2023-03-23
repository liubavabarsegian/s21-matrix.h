#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A)) {
    if (s21_create_matrix(A->rows, A->columns, result) == 0) {
      error = OK;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->rows = A->rows;
          result->columns = A->columns;
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else
      error = FAIL;
  }
  return error;
}
