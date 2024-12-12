#include <stdio.h>
#include <stdlib.h>

#define print(a) printf("%d\n", (a))

void list_print(int a[], int n){
    int i;
    for (i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main(){
    int m,n,i,j;
    int **arr;
    int index = -1;
    int count = 0;

    double summa = 0;
    scanf("%d %d", &n, &m);
    arr = (int **)malloc(sizeof(int *) * n);
    for(i = 0; i < n; i++){
        arr[i] = (int *)malloc(sizeof(int) * m);
    }
    srand(100);
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            int x;
            //scanf("%d", &x);
            x = rand() % 200 - 100;
            arr[i][j] = x;
            summa += x;
        }
    }
    double mid = summa / (double)(m * n);
    for (i = 0; i < n; i++){
        int local_count = 0;
        for (j = 0; j < m; j++){
            if ((double)arr[j][i] > mid){
                local_count++;
            }
        }
        if (local_count > count){
            count = local_count;
            index = i;
        }
    }
    printf("%.3lf\n", mid);
    printf("Столбец %d (%d числа)", index, count);
    
}



/*
4 4
5  
6
7
8
1
2
3
4
3
2
9
5
1
5
6
7
*/