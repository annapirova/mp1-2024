#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void revers(double arr[], int n) {
    int i;
    double tmp;
    for (i = 0; i < n / 2; i++) {
        tmp = arr[i];
        arr[i] = arr[n - i];
        arr[n - i] = tmp;
    }
}

int main() {
    int mi = 10000;
    int n;
    int i, j;
    double** arr;
    double* dp;
    scanf_s("%d", &n);
    arr = (double**)malloc(sizeof(double*) * n);
    srand(time(NULL));
    for (i = 0; i < n; i++) {
        arr[i] = (double*)malloc(sizeof(double) * n);
        for (j = 0; j < n; j++) {
            arr[i][j] = rand();
        }
    }

    for (i = 0; i < n; i++) {
        if (arr[i][i] < mi) {
            mi = arr[i][i];
            dp = arr[i];
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }
    revers(dp, n);
    printf("\n%lf\n", mi);


    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%lf ", arr[i][j]);
        }
        printf("\n");
    }

}