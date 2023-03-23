#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A)) {
    if (s21_create_matrix(A->columns, A->rows, result) == 0) {
      error = OK;
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    } else
      error = FAIL;
  }
  return error;
}