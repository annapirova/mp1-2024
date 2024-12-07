//
// Created by Семён Евдокимович on 26.11.2024.
//
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    int m;
    int i; int j; int k;

    scanf("%d", &n);
    scanf("%d", &m);
    int **arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
    }
    for ( i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (j=0; j < m; j++) {
        k=0;
        for (i = 0; i < n; i++) {
            if (arr[i][j] < 1) {
                k=1;
                break;
            }
        }
        if (k==1) {
            for (i = 0; i < n; i++) {
                arr[i][j]= 0;
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr[i][j] != 0) {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
}
