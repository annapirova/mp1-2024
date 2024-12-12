#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    setlocale(LC_ALL, "rus");
    srand(time(NULL));

    
    int rows = rand() % 4 + 2;
    int cols = rand() % 4 + 2;

    printf("Размер массива: %d x %d\n", rows, cols);

    
    int** A = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        A[i] = (int*)malloc(cols * sizeof(int));
    }

 
    printf("Случайный массив:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            A[i][j] = rand() % 100 + 1;
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }

   
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += A[i][j];
        }
    }

   
    float mid = (float)sum / (rows * cols);
    printf("\nСреднее значение: %.3f\n", mid);

    
    int* count = (int*)calloc(cols, sizeof(int));

    for (int j = 0; j < cols; j++) {
        int k = 0;
        for (int i = 0; i < rows; i++) {
            if (A[i][j] > mid) k++;
        }
        count[j] = k;
    }

    
    int max_count = 0;
    int stolbec = 0;

    for (int j = 0; j < cols; j++) {
        if (count[j] > max_count) {
            max_count = count[j];
            stolbec = j;
        }
    }

    printf("\nСтолбец %d (%d число(а))\n", stolbec, max_count);

    
    for (int i = 0; i < rows; i++) {
        free(A[i]);
    }
    free(A);
    free(count);

    return 0;
}