#include <stdio.h>
#include <locale.h>

void printMatrix(int matrix[100][100], int a, int b) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void removeColumn(int matrix[100][100], int* a, int* b, int colToRemove) {
    for (int i = 0; i < *a; i++) {
        for (int j = colToRemove; j < *b - 1; j++) {
            matrix[i][j] = matrix[i][j + 1];
        }
    }
    (*b)--;
}

int main() {
    int matrix[100][100];
    int a, b;
    setlocale(LC_ALL, "Rus");
    printf("Введите количество строк и столбцов матрицы: ");
    scanf_s("%d %d", &a, &b);

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            scanf_s("%d", &matrix[i][j]);
        }
    }
    int minElement;
    int minColIndex = -1;

    minElement = matrix[0][0];
    minColIndex = 0;

    for (int j = 0; j < b; j++) {
        for (int i = 0; i < a; i++) {
            if (matrix[i][j] < minElement) {
                minElement = matrix[i][j];
                minColIndex = j;
            }
        }
    }

    if (minColIndex != -1) {
        removeColumn(matrix, &a, &b, minColIndex);
        printf("\nМатрица после удаления столбца с минимальным элементом (%d):\n", minElement);
        printMatrix(matrix, a, b);
    }
    else {
        printf("Не удалось найти минимальный элемент.\n");
    }

    return 0;
}