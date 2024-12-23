//
// Created by Семён Евдокимович on 26.11.2024.
//
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int main() {
    int n;
    int m;
    int mx, mx2, ans;
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
    mx = 0;
    for (i = 0; i < n; i++) {
        k=0;
        for (j = 0; j < m; j++) {
            if (arr[i][j] ==0) {
                k++;
                mx = max(mx, k);
            } else {

                k=0;
            }
        }
    }
    mx2 = 0;
    for (j = 0; j < m; j++) {
        k=0;
        for (i = 0; i < n; i++) {
            if (arr[i][j] ==0) {
                k++;
                mx2 = max(k,mx2);
            } else {

                k=0;
            }
        }
    }
    ans = max(mx2,mx);
    printf("%d ", ans);
}