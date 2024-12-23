//
// Created by Семён Евдокимович on 28.11.2024.
//
// Задача 2.
#include <stdio.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int n, m,l;
    scanf("%d", &n);
    scanf("%d", &m);
    int *arr = (int*)malloc(n * sizeof(int));
    int *arr1 = (int*)malloc(m * sizeof(int));
    int *arr_res = (int*)malloc((m+n) * sizeof(int));
    int *arr_res1 = (int*)malloc((m+n) * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        arr_res[i] = arr[i];
    }
    for (int i = 0; i < m; i++) {
        scanf("%d", &arr1[i]);
        arr_res[n+i] = arr1[i];
    }
    qsort(arr_res,n+m, sizeof(int), comp);
    arr_res1[0] = arr_res[0];
    l=1;
    printf("%d ", arr_res1[0]);
    for (int i = 1; i < n+m; i++) {
        if (arr_res[i]!=arr_res[i-1]) {
            arr_res1[l] = arr_res[i];
            l++;
            printf("%d ",arr_res[i]);
        }
    }
    free(arr);
    free(arr1);
    free(arr_res);
    free(arr_res1);
    return 0;
}