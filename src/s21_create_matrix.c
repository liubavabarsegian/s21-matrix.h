#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (rows < 1 || columns < 1) {
    error = FAIL;
  } else if (!result) {
    error = FAIL;
  } else {
    result->rows = rows;
    result->columns = columns;

    result->matrix = malloc(sizeof(double) * rows);
    if (!result->matrix) {
      error = 1;
    } else {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = malloc(columns * sizeof(double));
        if (!result->matrix[i]) {
          error = FAIL;
          break;
        }
      }
    }
  }
  return error;
}
