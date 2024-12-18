#include <stdio.h>
#include <stdlib.h>



int proverka(int a[], int n, int ind) {
    for (int i = 0; i < n; i++) {
        if (a[i] == ind) {
            return 0;
        }
    }
    return 1;
}



int main() {
    int n, m, ind;
    printf("Vvedu razmer 1 u 2 mssiva:\n");
    scanf_s("%d %d", &n, &m);
    int* a;
    int* b;
    int* c;


    a = (int*)malloc(sizeof(int) * n);
    b = (int*)malloc(sizeof(int) * m);
    c = (int*)malloc(sizeof(int) * (n + m));
    ind = n;
    printf("Vvedu 1 massive:\n");
    for (int i = 0; i < n; i++) {
        scanf_s("%d", &a[i]);
    }
    printf("Vvedu 2 massive:\n");
    for (int i = 0; i < m; i++) {
        scanf_s("%d", &b[i]);
    }
    for (int i = 0; i < n; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        if (proverka(a, n, b[i])) {
            c[ind] = b[i];
            ind++;
        }
    }
    printf("%d\n", ind);

    for (int i = 0; i < ind; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}
