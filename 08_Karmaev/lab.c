#include "locale.h"
#include "stdio.h"
#include "math.h"
#include <time.h>
#include <stdlib.h>
#include "windows.h"
#include <inttypes.h>


#define cm(a,b) ((a)>(b))


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
    while (i < n1) {4
        
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
void Bubble(int arr[], int k, long int c) {
    int left = 0, right = k - 1, i, temp;
    
    while (left <= right) {
        for (i = right; i > left; i--) {
            if (arr[i - 1] > arr[i]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                c++;
            }
        }
        ++left;
        for (i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                temp = arr[i + 1];
                arr[i + 1] = arr[i];
                arr[i] = temp;
                c++;
            }
        }
        --right;

    }
    
    printf("Итераций=%ld\n", c);
    
    
}


void CountSort(int arn[], int a, int n) {
    int* arp;
    int* armi;
    int m = 100100000;
    for (int i = 0; i < n; i++) {
        if (arn[i] < m) {
            m = arn[i];
        }
    }
    int ma = -1000000000;
    for (int i = 0; i < n; i++) {
        if (arn[i] > ma) {
            ma = arn[i];
        }
    }
    m = fabs(m);
    long int raz = ma - m + 1;
    arp = ((int*)malloc((ma + 1) * sizeof(int)));
    for (int i = 0; i < ma+1; i++) {
        arp[i] = 0;
    }
    armi= ((int*)malloc((m) * sizeof(int)));
    for (int i = 0; i < m; i++) {
        armi[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        int p = arn[i];
        if (p < 0) {
            p = fabs(p);
            armi[p]++;
        }
        else {
            arp[p]++;
        }
    }
    for (int i = 0; i < n; i++) {
        arn[i] = 0;
    }
    int ci = 0;
    for (int i = m; i>0; i--) {
        if (armi[i] != 0) {
            while (armi[i] != 0) {
                arn[ci] = -1*i;
                ci++;
                armi[i]--;
            }
        }
        
    }
    for (int i = 0; i <ma; i--) {
        while (arp[i] != 0) {
            arn[ci] = i;
            ci++;
            arp[i]--;
        }

    }
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
                Bubble(arn, l,k1);printf("Массив отсортирован\n");
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
                CountSort(arn, 0, l);
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
    
        
    return 1;
}