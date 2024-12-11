#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


void fillMatrix(double** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = (double)(rand() % 100) / 10;
        }
    }
}

void printMatrix(double** matrix, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

double calculateAverage(double** matrix, int m, int n) {
    double sum = 0.0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            sum += matrix[i][j];
        }
    }
    return sum / (m * n);
}

int findColumnWithMostAboveAverage(double** matrix, int m, int n, double average, int* columnIndex) {
    int maxCount = 0;
    *columnIndex = -1;

    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (matrix[i][j] > average) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            *columnIndex = j;
        }
    }

    return maxCount;
}

int main() {
    int m, n;
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    printf("Введите количество строк: ");
    scanf_s("%d", &m);
    printf("Введите количество столбцов: ");
    scanf_s("%d", &n);
    double** matrix = (double**)malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    fillMatrix(matrix, m, n);
    printf("Матрица:\n");
    printMatrix(matrix, m, n);
    double average = calculateAverage(matrix, m, n);
    printf("Среднее значение в матрице: %.2f\n", average);
    int columnIndex;
    int countAboveAverage = findColumnWithMostAboveAverage(matrix, m, n, average, &columnIndex);

    if (columnIndex != -1) {
        printf("Столбец с наибольшим количеством значений больше среднего: %d\n", columnIndex + 1);
        printf("Количество значений в этом столбце больше среднего: %d\n", countAboveAverage);
    }
    else {
        printf("Нет значений больше среднего.\n");
    }

    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
