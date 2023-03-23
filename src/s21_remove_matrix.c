#include "s21_matrix.h"

void s21_remove_matrix(matrix_t *A) {
  if (A && is_okay(A)) {
    free(A->matrix);
    A->matrix = NULL;
    if (A->rows) {
      A->rows = 0;
    }
    if (A->columns) {
      A->columns = 0;
    }
  }
}
