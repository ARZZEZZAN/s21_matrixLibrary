#include "s21_matrix.h"

/// @brief Проверка матрицы на ее существование
/// @param matrix Структура, которая хранит в себе массив, а также rows and
/// columns
/// @return успешность выполнения
int s21_is_Emty(matrix_t *matrix) {
  int res = 0;
  if (matrix == NULL || matrix->matrix == NULL || matrix->rows <= 0 ||
      matrix->columns <= 0) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}
/// @brief Get matrix
/// @param row строки
/// @param col столбцы
/// @param A Структура, которая хранит в себе массив, а также rows and
/// columns
/// @param result Структура для записи результата
void s21_get_matrix(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }
    m_col = 0;
    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }
      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}
