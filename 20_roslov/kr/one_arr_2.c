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

int check(int a[], int n, int index){
    for (int i = 0; i < n; i++){
        if (a[i] == index){
            return 0;
        }
    }
    return 1;
}

void bubble_sort(int arr[], int n){
    int left = 0, right = n - 1, i, temp;
    while (left <= right){
        for (i = right; i > left; i--){
            if (arr[i - 1] > arr[i]){
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
        ++left;
        for (i = left; i < right; i++){
            if (arr[i] > arr[i + 1]){
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
            }
        }
        --right;
    }
}


int main(){
    int a, b, index;
    scanf("%d %d", &a, &b);
    int *arr = (int *)malloc(sizeof(int) * a);
    int *arr2 = (int *)malloc(sizeof(int) * b);
    int *final = (int *)malloc(sizeof(int) * (b+a));
    index = a;
    for (int i = 0; i < a; i++){
        scanf("%d", &arr[i]);
    }
    printf("Второй массив");
    for (int i = 0; i < b; i++){
        scanf("%d", &arr2[i]);
    }
    for (int i = 0; i < a; i++){
        final[i] = arr[i];
    }
    for (int i = 0; i < b; i++){
        if (check(arr, a, arr2[i])){
            final[index] = arr2[i];
            index++;
        }
    }
    print(index);
    bubble_sort(final, index);
    list_print(final, index);
}