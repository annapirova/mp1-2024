#include "locale.h"
#include "stdio.h"
#include "math.h"
#include <time.h>
#include <stdlib.h>
#include "windows.h"
#include <inttypes.h>

#define cm(a,b) ((a)>(b))
#define _USE_MATH_DEFINES_

int get_min(int a[], int n) {
    int i;
    int minim = 10000000;
    for (i = 0; i < n; i++) {
        if (minim > a[i]) {
            minim = a[i];
        }

    }
    return minim;
}

int get_max(int a[], int n) {
    int i;
    int maxim = -10000000;
    for (i = 0; i < n; i++) {
        if (maxim < a[i]) {
            maxim = a[i];
        }
    }
    return maxim;
}


void qs(int* s_arr, int first, int last,long int p,int p1[])
{
    
    int i = first, j = last, x = s_arr[(first + last) / 2], tmp;

    do {
        p++;
        while (s_arr[i] < x) i++; 
        while (s_arr[j] > x) j--; 

        if (i <= j) {
            if (s_arr[i] > s_arr[j]) {
                tmp=s_arr[i];
                s_arr[i]=s_arr[j];
                s_arr[j] = tmp;
                
            }
            i++; 
            j--; 
        }
    } while (i <= j);

    if (i < last)
        qs(s_arr, i, last,p,p1);
    if (first < j)
        qs(s_arr, first, j,p, p1);
    
    p1[0] += p;
    

}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k,p=0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* leftArr = ((int*)malloc(n1 * sizeof(int)));
    int* rightArr = ((int*)malloc(n2 * sizeof(int)));
    for (i = 0; i < n1; i++)
    {
        leftArr[i] = arr[left + i];
        
    }
    for (j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j]; 
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
            
        }
        else {
            arr[k] = rightArr[j];
            j++;
            
        }
        k++;
    }
    while (i < n1) {
        
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    
}


void mergeSort(int arr[], int left, int right) {
    
    if (left < right) {
        
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);

        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);

    }
    
}
int check(int a[], int n) {
    int i;
    for (i = 0; i < n - 1; i++) {
        if (a[i] > a[i + 1]) {
            return 1;
        }
    }
    return 0;
}


void Insert(int arr[], int k) {
    long p = 0;
    int i;
    for (i = 1; i < k; i++) {
        int x = arr[i];
        int j = i;
        p++;
        while (j > 0 && arr[j - 1] > x) {
            arr[j] = arr[j - 1];
            j--;
            p++;
        }
        arr[j] = x;
    }
    printf("Итераций=%ld\n", p);
}

void linear_search(int arr[], int n, int x) {
    int i, pos = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        printf("Линейный поиск нашел число\n");
        printf("Индекс числа: %d \n", pos);

    }
    else {
        printf("Числа нет в массиве\n");
    }
}

void binary_search(int arr[], int n, int x) {
    int r = n, l = 0;
    int pos = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] < x) {
            l = mid + 1;
        }
        else if (arr[mid] > x) {
            r = mid - 1;
        }
        else if (arr[mid] == x) {
            pos = mid;
            break;
        }
    }
    if (pos != -1) {
        printf("Бинарный поиск нашел число\n");
        printf("Индекс числа: %d \n", pos);

    }
    else {
        printf("Числа нет в массиве\n");
    }
}
void polosa() {
    printf("------------------------\n");
}
// 2 1 3 5 4 6 7 8 
// 1 2 3 4 5 6 7 8 


    void bubble_sort(int arr[], int n) {
    int left = 0, right = n - 1, i, temp, count = 0;
    clock_t start, finish;
    start = clock();
    int flag = 1;
    while (left <= right && flag) {
    int flag = 1;
    for (i = right; i > left; i--) {
        if (arr[i - 1] > arr[i]) {
            temp = arr[i - 1];
            arr[i - 1] = arr[i];
            arr[i] = temp;
            flag = 0;
        }
        count++;
    }
    ++left;
    count++;
    for (i = left; i < right; i++) {
        if (arr[i] > arr[i + 1]) {
            temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
            flag = 0;
        }
        count++;
    }
    --right;
    count++;
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);

    }


// 1 2 -1 -2 -1 2
// ar[0] - хранит, сколько раз было -2
// ar[1] хранит, сколько раз было -1
// ar[2] хранит, сколько раз было  0
// ar[3] хранит, сколько раз было 1
// ar[4] хранит, сколько раз было 2
// ar 1 2 0 1 2 --> это количество
// ar1[.] = i + min

void counting_sort(int arr[], int n) {
    int k, sdvig;
    int flag = 0;
    if (get_min(arr, n) < 0) {
        k = (get_min(arr, n) * -1);
        sdvig = (get_min(arr, n) * -1) + get_max(arr, n) + 1;
        flag = 1;
    }
    else {
        k = get_max(arr, n);
        sdvig = get_max(arr, n) + 1;
    }

    int* a=(int*)malloc((sdvig)*sizeof(int));
    int count = 0;
    int i;
    clock_t start, finish;
    start = clock();
    for (i = 0; i < sdvig; i++) {
        a[i] = 0;
        count++;
    }
    for (i = 0; i < n; i++) {
        if (get_min(arr, n) < 0) {
            a[arr[i] + k] += 1;
        }
        else {
            a[arr[i]] += 1;
        }
        count++;
    }
    int index = 0;
    for (i = 0; i < sdvig; i++) {
        while (a[i] != 0) {
            if (flag) {
                arr[index] = i - (-1 * get_min(arr, n));
            }
            else {
                arr[index] = i;
            }
            a[i]--;
            index++;
            count++;
        }
    }
    for (i = index; i < n; i++) {
        arr[index] = 0;
        count++;
    }
    finish = clock();
    double duration = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("------------------------\n");
    printf("Сортировка выполнена\n");
    printf("Количество операций: %d\n", count);
}

void menu() {
    printf("------------------------\n1.Ввести массив вручную\n2.Рандомный массив\n3.Сортировка пузырьком\n4.Сортировка вставками\n5.Сортировка подсчетом\n");
    printf("6.Сортировка Хоара\n7.Сортировка слиянием\n8.Вывести массив\n9.Линейный поиск\n10.Бинарный поиск\n11.Очистить массив\n12.Вывод меню\n0.Выход\n------------------------\n");
}
void st() {
    printf("Массив уже отсортирован");
}


int main() {
    setlocale(LC_ALL, "Rus");
    printf("Задайте размер массива: "); int l; scanf_s("%d", &l);
    int* arn = ((int*)malloc(l * sizeof(int)));
    printf("------------------------\n1.Ввести массив вручную\n2.Рандомный массив\n3.Сортировка пузырьком\n4.Сортировка вставками\n5.Сортировка подсчетом\n");
    printf("6.Сортировка Хоара\n7.Сортировка слиянием\n8.Вывести массив\n9.Линейный поиск\n10.Бинарный поиск\n11.Очистить массив\n12.Вывод меню\n0.Выход\n------------------------\n");
    int x = 10;int v;
    LARGE_INTEGER freq, start, finish;
    double time;
    QueryPerformanceFrequency(&freq);
    while (x != 0) {     
        long double k1 = 0,k2;
        long int y = 0;
        clock_t start1, end1;
        int p1[2] = { 0,0 };
        printf("Введите: ");
        scanf_s("%d", &x);
        switch (x) {
        case(1):
            polosa();
            printf("Вводите: ");
            for (int i = 0; i < l; i++) {
                scanf_s("%d", &arn[i]);
            }
            printf("\nУспешно!\n"); polosa(); 
            menu();
            break;
        case(2):
            polosa();
            for (int i = 0; i < l; i++) {
                arn[i] = rand();
            }
            printf("Успешно!\n"); polosa(); 
            menu();
            break;
        case(3):
            polosa(); //vivodit vremya i it
            if (check(arn,l)){
                QueryPerformanceCounter(&start);
                bubble_sort(arn, l);printf("Массив отсортирован\n");
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart -
                    start.QuadPart) / (double)freq.QuadPart;
                printf("Время работы программы = %.5f\n", time);
            }
            else {
                st(); printf("\n");
            }
            polosa();
            menu();
            break;
        case(4):
            polosa();
            if (check(arn, l)) {
                QueryPerformanceCounter(&start);
            
                Insert(arn, l);printf("Массив отсортирован\n");//vivodit
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart -
                    start.QuadPart) / (double)freq.QuadPart;
                printf("Время работы программы=%.5f(cек)\n", time);
            }
            else {
                st(); printf("\n");
            }
            polosa();
            menu();
            break;
        case(5):
            polosa();
            if (check(arn, l)) {
                QueryPerformanceCounter(&start);
                counting_sort(arn, l);
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart -
                    start.QuadPart) / (double)freq.QuadPart;
                printf("Время выполнения работы=%.5f\nМассив отсортирован\n");}
            else {
                st(); printf("\n");
            }
            polosa();
            menu();
            break;
        case(6):
            polosa();
            if (check(arn, l)) {
                QueryPerformanceCounter(&start);
                qs(arn, 0, l-1,y,p1);printf("Массив отсортирован\n");//vivodit
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart -
                    start.QuadPart) / (double)freq.QuadPart;
                printf("Время работы программы=%.5f(cек)\nИтераций=%ld\n", time, p1[0]);
            }
            else {
                st(); printf("\n");                
            }
            polosa();
            menu();
            break;
        case(7):
            polosa();
            if (check(arn, l)){
                QueryPerformanceCounter(&start);
                mergeSort(arn, 0, l - 1);printf("Массив отсортирован\n");
                QueryPerformanceCounter(&finish);
                time = (double)(finish.QuadPart -
                    start.QuadPart) / (double)freq.QuadPart;
                printf("Время выполнения программы=%.5f(cек)\n", time);            
            }
            else {
                st(); printf("\n");
            }
            polosa();
            menu();//Только время выполнения 
            break;
        case(8):
            polosa();
            for (int i = 0; i < l; i++) {
                printf("%d ", arn[i]);
            }
            polosa();
            menu();
            break;
        case(9):
            polosa();
            printf("Число для поиска: ");
            scanf_s("%d", &v);
            polosa();
            QueryPerformanceCounter(&start);
            linear_search(arn, l, v);
            QueryPerformanceCounter(&finish);
            time = (double)(finish.QuadPart -
                start.QuadPart) / (double)freq.QuadPart;
            printf("Время выполнения программы=%.5f(cек)\n------------------------\n", time);
            menu();
            break;
        case(10):
            polosa();
            if(check(arn,l)==0){
            printf("Число для поиска: ");
            scanf_s("%d", &v);
            polosa();
            QueryPerformanceCounter(&start);
            binary_search(arn, l, v);
            QueryPerformanceCounter(&finish);
            time = (double)(finish.QuadPart -
                start.QuadPart) / (double)freq.QuadPart;
            printf("Время выполнения программы=%lf(cек)\n------------------------\n",time);
            }
            else {
                printf("Отсортируйте массив\n------------------------\n");                
            }
            menu();
            break;
        case(11):
            for (int i = 0; i < l; i++) {
                arn[i] = 0;
            }
            polosa();
            printf("Массив очищен!\n");
            polosa();
            menu();
            break;
        case(12):
            menu();
            break;
        default:
            break;
        menu();
        scanf_s("%d", &x);
        }
    }
    
        
    
}