#include "s21_matrix.h"

int is_okay(matrix_t *A) {
  return (A != NULL && A->rows > 0 && A->columns > 0 && A->matrix != NULL);
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = FAILURE;

  if (is_okay(A) && is_okay(B) && A->columns == B->columns &&
      A->rows == B->rows) {
    error = SUCCESS;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
          error = FAILURE;
        }
      }
    }
  }
  return error;
}
