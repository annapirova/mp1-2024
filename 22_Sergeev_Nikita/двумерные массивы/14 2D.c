#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    int rows = rand() % 5 + 1;
    int cols = rand() % 5 + 1;

    printf("Размеры массива: %d x %d\n", rows, cols);

    
    int** A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
    }

    
    printf("\nИсходный массив A:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 100 + 1; 
            printf("%4d ", A[i][j]);
        }
        printf("\n");
    }

    
    int k = 101; 
    int stolbec = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (A[i][j] < k) {
                k = A[i][j];
                stolbec = j;
            }
        }
    }

    printf("\nМинимальный элемент: %d в столбце %d\n", k, stolbec);

  
    int** B = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        B[i] = (int*)malloc((cols - 1) * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        int b_col = 0;
        for (int j = 0; j < cols; j++) {
            if (j == stolbec) continue;
            B[i][b_col] = A[i][j];
            b_col++;
        }
    }

    printf("\nМассив B\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1; j++) {
            printf("%4d ", B[i][j]);
        }
        printf("\n");
    }

    return 0;
}