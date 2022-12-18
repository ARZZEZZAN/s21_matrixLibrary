#include "s21_matrix.h"
/// @brief Инициализация матрицы,  а именно выделение памяти под нее
/// @param rows
/// @param columns
/// @param result Структура, которая хранит в себе массив, а также rows and
/// columns
/// @return error
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = 0;
  if (rows < 1 || columns < 1) {
    error = 1;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    error = 0;
  }
  if (result->matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
      if (!result->matrix[i]) {
        for (int j = 0; j < i; j++) free(result->matrix[j]);
        free(result->matrix);
      }
    }
    error = 0;
  }
  return error;
}
/// @brief Обнуление матрицы
/// @param A Структура, которая хранит в себе массив, а также rows and
/// columns
void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
  A->matrix = NULL;
  A->rows = 0;
  A->columns = 0;
}