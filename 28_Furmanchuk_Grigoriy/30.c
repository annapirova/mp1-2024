#include "stdio.h"
#include "stdlib.h"

int sumarr(int arr[], int len) {
    int i;
    int sum = 0;
    for (i = 0; i < len; i++) {
        sum += arr[i];
    }
    return sum;
}

void check(int arr1[], int arr2[], int n, int k, int id1, int id2, int* f) {
    int i = 0;;
    if ((n - sumarr(arr1, n)) >= k) {
        for (i = 0; i < n; i++) {
            if (arr1[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr1[i]);
        }
        *f = 1;
        printf("\nNumber of vagon: %d\n", id1+1);
    }
    else if ((n - sumarr(arr2, n)) >= k) {
        for (i = 0; i < n; i++) {
            if (arr2[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr2[i]);
        }
        *f = 1;
        printf("\nNumber of vagon: %d\n", id2+1);
    }
    else if (2 * n - sumarr(arr2, n) - sumarr(arr1, n) >= k) {
        for (i = 0; i < n; i++) {
            if (arr1[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr1[i]);
        }
        printf("\nNumber of vagon: %d\n", id1+1);
        for (i = 0; i < n; i++) {
            if (arr2[i] == 0 && k > 0) {
                printf("X");
                k -= 1;
            }
            else printf("%d", arr2[i]);
        }
        *f = 1;
        printf("\nNumber of vagon: %d\n", id2+1);
    }
}

int main() {
    int b = 0;
    int i, j;
    int n, m;
    int k;
    int** arr;
    int fl = 0;
    //int* arrbug;
    printf("seat empty = 0\n");
    printf("seat taken = 1\n");
    printf("Suggested seat = X\n");
    scanf_s("%d %d", &n, &m);
    scanf_s("%d", &k);
    //arrbug = (int*)malloc(sizeof(int) * m);
    arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for (j = 0; j < m; j++) {
            scanf_s("%d", &arr[i][j]);
            //arrbug[j] = 1;
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; (i < n) && (fl != 1); i++) {
        if (i != n-1) {
            check(arr[i], arr[i + 1], m, k, i, i + 1, &fl);
        }
        //else check(arr[i], arrbug, m, k, i, 10000, &fl);
    }
    if (fl == 0) {
        printf("Imposible");
    }
}