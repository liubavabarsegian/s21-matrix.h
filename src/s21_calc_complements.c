#include <math.h>

#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A)) {
    error = OK;
    if (A->rows != A->columns) {
      error = CALC_ERROR;
    } else {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        if (A->rows == 1 && A->columns == 1) {
          result->matrix[0][0] = A->matrix[0][0];
        } else {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
              matrix_t minor;
              int create = s21_minor(A, i, j, &minor);
              if (create == 0) {
                double det;
                int sign = pow(-1, (i + j));
                s21_determinant(&minor, &det);
                result->matrix[i][j] = det * sign;
                s21_remove_matrix(&minor);
              }
            }
          }
        }
      }
    }
  }
  return error;
}