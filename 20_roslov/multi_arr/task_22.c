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

// 0 - свобоное место,  1 - занятое место
int main(){
    int m,n,i,j;
    int **arr;
    int max_mest = -1;
    int index = -1;
    scanf("%d %d", &n, &m);
    arr = (int **)malloc(sizeof(int *) * n);

    for(i = 0; i < n; i++){
        arr[i] = (int *)malloc(sizeof(int) * m);
    }
    int x;
    for (i = 0; i < n; i++){
        for (j = 0; j < m; j++){
            scanf("%d", &x);
            while (x != 0 && x != 1)
            {
                printf("Можно вводить только 0 или 1\n");
                scanf("%d", &x);
            }
            arr[i][j] = x;
            
        }
    }
    printf("Вагон: \n");
    print_list(arr, n, m);
    int count;
    for (i = 0; i < n; i++){
        count = 0;
        for (j = 0; j < m; j++){
            if (arr[i][j] == 0){
                count++;
            }else{
                if(count > max_mest){
                    max_mest = count;
                    index = i+1;
                }
                count = 0;
            }
        }
        if(count > max_mest){      
            max_mest = count;
            index = i+1;
        }
    }
    
    printf("Максимальное количество мест: %d\n", max_mest);
    printf("В вагоне %d", index);
    
    for(int i = 0; i < n + 1; i++){
        free(arr[i]);
    }
    free(arr);
}
