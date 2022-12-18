#include "s21_matrix.h"
/// @brief Нахождение суммы матриц
/// @param A Структура, которая хранит в себе массив, а также rows and columns
/// @param B Структура, которая хранит в себе массив, а также rows and columns
/// @param result Матрица для записи результата
/// @return успешность выполнения
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  if ((s21_is_Emty(A) && s21_is_Emty(B))) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}
/// @brief Нахождение разницы матриц
/// @param A Структура, которая хранит в себе массив, а также rows and columns
/// @param B Структура, которая хранит в себе массив, а также rows and columns
/// @param result Матрица для записи результата
/// @return успешность выполнения
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  if ((s21_is_Emty(A) && s21_is_Emty(B))) {
    if ((A->rows == B->rows) && (A->columns == B->columns)) {
      flag = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}
/// @brief Умножение матрицы на число
/// @param A Структура, которая хранит в себе массив, а также rows and columns
/// @param B Структура, которая хранит в себе массив, а также rows and columns
/// @param result Матрица для записи результата
/// @return успешность выполнения
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int flag = 0;
  if (s21_is_Emty(A)) {
    flag = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  } else {
    flag = 1;
  }
  return flag;
}
/// @brief Умножение матриц
/// @param A Структура, которая хранит в себе массив, а также rows and columns
/// @param B Структура, которая хранит в себе массив, а также rows and columns
/// @param result Матрица для записи результата
/// @return успешность выполнения
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int flag = 0;
  if (s21_is_Emty(A) && s21_is_Emty(B)) {
    if ((A->columns == B->rows)) {
      flag = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    } else {
      flag = 2;
    }
  } else {
    flag = 1;
  }
  return flag;
}