#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = CALC_ERROR;

  if (!is_okay(A) || !is_okay(B)) {
    error = FAIL;
  } else {
    if (is_okay(A) && is_okay(B) && are_sizes_equal(*A, *B)) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        error = OK;
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      error = CALC_ERROR;
      // result = NULL;
    }
  }
  return error;
}
