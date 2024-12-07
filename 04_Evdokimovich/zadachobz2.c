//
// Created by Семён Евдокимович on 28.11.2024.
//
// Из файла 2-я
#include <stdio.h>
#include <stdlib.h>
int max(double a, double b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }

}
int main() {
    int n;
    int m;
    double Mid;
    double sum=0.0;
    int i,j,kol,l,l1;
    scanf("%d %d", &n, &m);
    printf("\n");
    double **a = (double**)malloc(n*sizeof(double*));
    for (i = 0; i < n; i++) {
        a[i] = (double*)malloc(m*sizeof(double));
    }
    for ( i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            a[i][j] = rand()%100;
            //scanf("%lf", &a[i][j]);
            sum += a[i][j];
            printf("%.0lf ",a[i][j]);

        }
        printf("\n");
    }
    Mid = sum/(n*m);
    l= 0;
    l1=0;
    printf("%.3lf\n", Mid);
    for ( j = 0; j < m; j++) {
        kol = 0;
        for ( i = 0; i < n; i++) {
            if (a[i][j] > Mid) {
                kol++;
            }
        }
        if (kol > l) {
            l = kol;
            l1 = j;
        }
    }
    printf("%d %d", l1,l);
    for ( j = 0; j < m; j++) {
        free(a[j]);
    }
    free(a);
}
