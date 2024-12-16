#include <stdio.h>
#include <stdlib.h>


#define print(a) printf("%d\n", (a))
#define forik(a) for(int i = 0; i < a; i++)




void print_list(int **arr, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}

int get_min_index(int **arr, int n, int m){
    int minim = 10000000;
    int index = -1;
    for (int i = 0; i < n; i++){
        for(int j = 0; j< m; j++){
            if(arr[i][j] < minim){
                minim = arr[i][j];
                index = i;
            }
        }
    }
    return index;
}


int main(){
    int m = 3,n,i,j;
    int **arr;
    int base[3][5];
    int not_yav = 0, not_sdan, norm = 0, good = 0, great = 0;
    scanf("%d", &n);
    arr = (int **)malloc(sizeof(int *) * n);

    for(i = 0; i < n; i++){
        arr[i] = (int *)malloc(sizeof(int) * m);
    }
    for (i = 0; i < 3; i++){
        for (j = 0; j < 5; j++){
            base[i][j] = 0;
        }
    }
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Таблица с оценками");
    print_list(arr, n, m);
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            base[j][arr[i][j] - 1]++;
            // switch (j)
            // {
            // case 1:
            //     base[j][arr[i][j] - 1]++;
            //     break;
            
            // case 2:
            //     base[j][arr[i][j] - 1]++;
            //     break;
            // case 3:
            //     base[j][arr[i][j] - 1]++;
            //     break;
            // case 4:
            //     base[j][arr[i][j] - 1]++;
            //     break;
            // case 5:
            //     base[j][arr[i][j] - 1]++;
            //     break;
            }
        }
    for (i = 0; i < m; i++){
        printf("------------------------\n");
        printf("Количество неявок на %d экзамене: %d\n", i+1, base[i][0]);
        printf("Количество неудовлетворительных оценок на %d экзамене: %d\n", i+1, base[i][1]);
        printf("Количество удовлетворительных оценок на %d экзамене: %d\n", i+1, base[i][2]);
        printf("Количество хороших оценок на %d экзамене: %d\n", i+1, base[i][3]);
        printf("Количество отличных оценок на %d экзамене: %d\n", i+1, base[i][4]);
    }
    for(int i = 0; i < n + 1; i++){
        free(arr[i]);
    }
    free(arr);
}
