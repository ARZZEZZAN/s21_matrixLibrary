#include "s21_matrix.h"
/// @brief Сравнение матриц
/// @param A Структура, которая хранит в себе массив, а также rows and
/// @param B Структура, которая хранит в себе массив, а также rows and
/// @return успешность выполнения
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int ret = SUCCESS;
  if (s21_is_Emty(A) == 0 && s21_is_Emty(B) == 0 && A->columns == B->columns &&
      A->rows == B->rows) {
    for (int i = 0; i < A->rows && ret; i++) {
      for (int j = 0; j < A->columns && ret; j++) {
        if (round(A->matrix[i][j] * pow(10, 7)) !=
            round(B->matrix[i][j] * pow(10, 7))) {
          ret = FAILURE;
        }
      }
    }
  } else {
    ret = FAILURE;
  }
  return ret;
}
