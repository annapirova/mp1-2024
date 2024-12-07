//
// Created by Семён Евдокимович on 11.11.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
void print(int A[],int n) {
    int i;
    for(i=0;i<n;i++) {
        printf("%d ",A[i]);
    }
}
double PortableGetTime()
{
    struct timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec * 1000000ULL + t.tv_usec) * 1.0e-6;
}
void print_menu(){
    printf("1. Input Array \n"
           "2. Generate Array \n"
           "3. Bubble sort \n"
           "4. Vstavka sort \n"
           "5. Count sort \n"
           "6. Sorting by choice \n"
           "7. Quick sort \n"
           "8. Print array\n"
           "9. Using a binary search, find out what the item\n"
           "   will be if they are placed in ascending order\n"
           "10. Using a linear search, find out what the item\n"
           "    will be if they are placed in ascending order\n"
           "11. Print results sort\n"
           "12. Result count swap"
           "13. Print results search\n"
           "14. Result swap search"
           "15. Exit\n");
}
void input_array(int A[],int n) {
    for(int i=0;i<n;i++) {
        scanf("%d",&A[i]);
    }

}
int vstavk (int a[],int n){
    int A[n];
    int sw=0;
    int val, pos,i;
    int k;
    for (i=0; i<n; i++) {
        A[i] = a[i];
    }
    for (pos=1;pos<n;pos++) {
        val = A[pos];
        k = pos-1;
        while (k>=0 && A[k]>val) {
            A[k+1] = A[k];
            k--;
            sw++;
        }
        A[k+1] = val;
        sw++;
    }
    print(A,n);
    return sw;
}
void generate_array(int A[],int n) {
    int i;
    for(i=0;i<n;i++) {
        A[i] = rand()%10000;
    }
}
int bubble_sort(int a[],int n) {
    int A[n];
    int i,j,f=1,left, right, k,sw=0;
    left=0; right=n - 2;
    for (i=0; i<n; i++) {
        A[i] = a[i];
    }
    while(left<right) {
        k = -1;
        for(i=left; i<= right; i++ ) {
            if(A[i]>A[i+1]) {
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;
                k = i;
                sw++;
            }
        }
        right = k;
        k = n;
        for (j=right - 1; j>=left; j--) {
            if(A[j]>A[j+1]) {
                int temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                k =  j-1;
                sw++;
            }
        }
        left = k;
    }
    print(A,n);
    return sw;
}

int vybor(int a[],int n) {
    int i,j,pos,ind,mni; int mn,temp;
    int A[n];
    int sw=0;
    for (i=0; i<n; i++) {
        A[i] = a[i];
    }
    for (pos=0; pos<n; pos++) {
        mn = A[pos];
        mni = pos;
        for (ind=pos; ind<n; ind++) {
            if (mn > A[ind]) {
                mn = A[ind];
                mni = ind;
            }
        }
        temp  = A[pos];
        A[pos] = mn;
        A[mni] = temp;
        sw++;
    }
    print(A,n);
    return sw;

}
int quicksort(int arr[], int low, int high,int sw) {
    int s=sw;
    if (low < high) {
        int pivot = arr[(low + high) / 2];
        int i = low;
        int j = high;
        int temp;
        while (i <= j) {
            while (arr[i] < pivot) i++;
            while (arr[j] > pivot) j--;
            if (i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
                s++;
            }
        }

        if (low < j) quicksort(arr, low, j,s);
        if (i < high) quicksort(arr, i, high,s);
    }
    return s;
}
void countsort(int arr[], int n) {
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    int* countArray = (int*)calloc(mx + 1, sizeof(int));
    for (int i = 0; i < n; i++)
        countArray[arr[i]]++;
    for (int i = 1; i <= mx; i++)
        countArray[i] += countArray[i - 1];
    int* outputArray = (int*)malloc(n * sizeof(int));
    for (int i = n - 1; i >= 0; i--) {
        outputArray[countArray[arr[i]] - 1] = arr[i];
        countArray[arr[i]]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = outputArray[i];
    free(countArray);
    free(outputArray);
}
int binsearch(int A[],int n,int x) {
    int low,high,mid,i;
    int otv=0;
    int sw=0;
    low=0;
    high=n-1;
    while(low<=high && A[n-1]>= x && A[0]<=x) {
        mid=(low+high)/2;
        if(A[mid]==x) {
            otv=1;
            printf("The nunmber of elements - %d\n",mid+1);
            break;
        } if(A[mid]<x) {
            low=mid+1;
            sw++;
        } if (A[mid]>x) {
            high=mid-1;
            sw++;
        }
    }
    if (otv==0) {
        printf("Not Found\n");
    }
    return sw;
}
int linear_search(int a[],int n,int x) {
    int i,sw=-1;
    for (i=0; i<n; i++) {
        if (a[i]==x) {
            printf("The nunmber of elements - %d\n",i+1);
            sw=i+1;
            break;
        }
    }
    if (sw==-1) {
        printf("Not Found\n");
        sw=n;
    }
    return sw;
}
int main() {
    int n,n2,kol = 0;
    int masiv[100000];int masiv2[100000];
    double start,finish,time;
    int choice;
    double vrem[5];
    int sw[5];
    int swp[2];
    double poisk[2];
    int num;
    n2 = n-1;
    print_menu();
    printf("Input size array \n");
    scanf("%d",&n);
    printf("Choose comand\n");

    while(kol==0) {
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                input_array(masiv,n); // работат
            for(int i=0;i<n;i++) {
                masiv2[i] = masiv[i];
            }
            break;
            case 2: generate_array(masiv,n); // работает
            for(int i=0;i<n;i++) {
                masiv2[i] = masiv[i];
            }
            break;
            case 3:start = PortableGetTime();
                sw[0] = bubble_sort (masiv,n);// работает
            finish = PortableGetTime();
            time = finish - start;
            vrem[0]=time;
            break;
            case 4:start = PortableGetTime();
                sw[1] = vstavk(masiv,n); //работает
            finish = PortableGetTime();
            time = finish - start;
            vrem[1]=time;
            break;
            case 5:for(int i=0;i<n;i++) {
                masiv2[i] = masiv[i];
            }
                start = PortableGetTime();
            countsort(masiv2,n);
            finish = PortableGetTime();
            time = finish - start;
            print(masiv2,n);
            vrem[2]=time;
            break;
            case 6:start = PortableGetTime();
                sw[3] = vybor(masiv,n); // работает
            finish = PortableGetTime();
            time = finish - start;
            vrem[3]=time;
            break;
            case 7:for(int i=0;i<n;i++) {
                masiv2[i] = masiv[i];
            }
                start = PortableGetTime();
            sw[4] = quicksort(masiv2,0,n-1,0);
            finish = PortableGetTime();
            time = finish - start;
            print(masiv2,n);
            vrem[4]=time;
            break;
            case 8:
                print(masiv,n); //работает
            break;
            case 9:
            printf("Enter a number\n");
            scanf("%d",&num);
            quicksort(masiv2,0,n-1,0);
            start = PortableGetTime();
            swp[0] = binsearch(masiv2,n,num);
            finish = PortableGetTime();
            time = finish - start;
            poisk[0]=time;
            break;
            case 10:
                printf("Enter a number\n");
            scanf("%d",&num);
            quicksort(masiv2,0,n-1,0);
            start = PortableGetTime();
            swp[1] = linear_search(masiv2,n,num);
            finish = PortableGetTime();
            time = finish - start;
            poisk[1]=time;
            break;
            case 11:
                printf("Result time of sort\n");
                for (int i = 0; i <5; i++){
                  printf("%lf ",vrem[i]);
                }
            break;
            case 12:
                printf("Result count swap\n");
            for (int i = 0; i <5; i++){
                printf("%d ",sw[i]);
            }
            break;
            case 13:
                printf("Result time of search\n");
            for (int i = 0; i < 2; i++) {
                printf("%lf ",poisk[i]);
            }
            break;
            case 14:
                printf("Result swap search\n");
            for (int i = 0; i < 2; i++) {
                printf("%d ",swp[i]);
            }
            case 15:
                kol = 1;
            break;
        }
    }
}