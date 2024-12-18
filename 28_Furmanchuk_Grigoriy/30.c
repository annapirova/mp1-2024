#include "stdio.h"
#include "stdlib.h"

int sumarr(int arr[], int len) {
    int i;
    int sum;
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

void check(int arr1[], int arr2[], int n, int k, int flag) {
    int i = 0;;
    if ((n - sum(arr1, n)) >= k) {
        for (i = 0; i < n; i++) {
            if (arr1[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr1[i]);
        }
        flag = 1;
    }
    else if ((n - sum(arr2, n)) >= k) {
        for (i = 0; i < n; i++) {
            if (arr2[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr2[i]);
        }
        flag = 1;
    }
    else if (2 * n - sum(arr2, n) - sum(arr1, n) >= k) {
        for (i = 0; i < n; i++) {
            if (arr1[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr1[i]);
        }
        for (i = 0; i < n; i++) {
            if (arr2[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr2[i]);
        }
        flag = 1;
    }
}

int main() {
    int i, j;
    int n, m;
    int k;
    int** arr;
    int fl = 0;
    printf("seat empty = 0\n");
    printf("seat taken = 1\n");
    scanf_s("%d %d", n, m);
    scanf_s("%d", k);
    arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for (j = 0; j < m; j++) {
            scanf_s("%d", arr[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n - 1 && !fl; i++) {
        check(arr[i], arr[i + 1], m, k, fl);
    }
}