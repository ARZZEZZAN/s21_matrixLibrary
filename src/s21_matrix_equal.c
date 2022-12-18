#include "s21_matrix.h"
/// @brief Сравнение матриц
/// @param A Структура, которая хранит в себе массив, а также rows and
/// @param B Структура, которая хранит в себе массив, а также rows and
/// @return успешность выполнения
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = 0;
  if (s21_is_Emty(A) || s21_is_Emty(B)) {
    result = 1;
  } else if (A->columns != B->columns || A->rows != B->rows) {
    result = 1;
  } else {
    for (int i = 0; i < A->rows && result; i++) {
      for (int j = 0; j < A->columns && result; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7)))
          result = 1;
      }
    }
  }
  return result;
}
