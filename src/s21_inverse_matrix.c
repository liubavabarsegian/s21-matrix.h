#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = FAIL;
  if (is_okay(A)) {
    error = OK;
    double det = 0;
    s21_determinant(A, &det);
    if (A->rows != A->columns || det == 0) {
      error = CALC_ERROR;
    } else {
      matrix_t complements;
      matrix_t transponse;
      int compl = s21_calc_complements(A, &complements);
      int create = s21_transpose(&complements, &transponse);
      if (create == 0 && compl == 0) {
        error = s21_mult_number(&transponse, 1 / det, result);
        s21_remove_matrix(&complements);
        s21_remove_matrix(&transponse);
      }
    }
  }
  return error;
}
