#include <stdio.h>
#include <stdlib.h>


#define print(a) printf("%d\n", (a))
#define forik(a) for(int i = 0; i < a; i++)




void print_list(int** arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

int get_min_index(int** arr, int n, int m) {
    int max = 0;
    int index = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
                index = j;
            }
        }
    }
    return index;
}


int main() {
    int m, n, i, j;
    int** arr;
    scanf("%d %d", &n, &m);
    arr = (int**)malloc(sizeof(int*) * n);
    for (i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    print_list(arr, n, m);
    int index = get_min_index(arr, n, m);
    print(index);
    for (i = 0; i < n; i++) {
        for (j = index; j < m - 1; j++) {
            arr[i][j] = arr[i][j + 1];
        }
    }
   
    m-=1;
    printf("Массив с удаленной строчкой\n");
    print_list(arr, n, m);
    
    

}