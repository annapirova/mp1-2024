#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "locale.h"
#include "math.h"
#include "windows.h"
#include "malloc.h"
#pragma warning(disable: 4996)
//#pragma warning(disable: 6386)




// Main body:



void bubble_sort(int A[], int n) {

	int x = 0, f, amount_comps = 0, amount_perms = 0;
	for (int i = 0; i < n; i++) {
		f = 0;
		for (int j = 0; j < n; j++) {
			if (A[i] < A[j]) {
				x = A[j];
				A[j] = A[i];
				A[i] = x;
				amount_perms++;
				f = 1;
			}
			else {
				f = 1;
			}
			amount_comps++;
		}
		if (f == 0) {
			break;
		}
	}
	printf("\n\nМассив, отсортированный пузырьком:  ");
	for (int i = 0; i < n; i++) {
		printf(" %d ", A[i]);
	}
	printf("\nКоличество сравнений: %d ", amount_comps);
	printf("\nКоличество перестановок: %d ", amount_perms);
}



void bubble_sort_optimized(int A[], int n) {
	int x = 0, f, amount_perms = 0, amount_comps = 0;
	int left = 0, right = n;
	for (int i = 0; i < n; i++) {
		f = 0;
		if (i % 2 == 0) {   //i - четная; идем слева-направо
			for (int j = left; j < right - 1; j++) {
				if (A[j] > A[j + 1]) {
					x = A[j + 1];
					A[j + 1] = A[j];
					A[j] = x;
					amount_perms++;
					f = 1;
				}
				else {
					f = 1;
				}
				amount_comps++;
			}
			right--;
		}
		else {   //i - нечетная; идем справа-налево
			for (int j = right-1; j > left; j--) {
				if (A[j] < A[j - 1]) {
					x = A[j - 1];
					A[j - 1] = A[j];
					A[j] = x;
					amount_perms++;
					f = 1;
				}
				else {
					f = 1;
				}
				amount_comps++;
			}
			left++;
		}
		if (f == 0) {
			break;
		}
	}

	printf("\n\nМассив, отсортированный двунаправленным пузырьком:  ");
	for (int i = 0; i < n; i++) {
		printf(" %d ", A[i]);
	}
	printf("\nКоличество сравнений: %d ", amount_comps);
	printf("\nКоличество перестановок: %d ", amount_perms);
}



void insertion_sort(int A[], int n) {
	int x = 0, pos, val, k, amount_perms = 0, amount_comps = 0;

	for (pos = 1; pos < n; pos++) {
		val = A[pos];
		k = pos - 1;
		while (k >= 0 & A[k] > val) {
			A[k + 1] = A[k];
			k--;
			amount_comps++;
		}
		A[k+1] = val;
		amount_perms++;
	}

	printf("\n\nМассив, отсортированный вставками:  ");
	for (int i = 0; i < n; i++) {
		printf(" %d ", A[i]);
	}
	printf("\nКоличество сравнений: %d ", amount_comps);
	printf("\nКоличество перестановок: %d ", amount_perms);

}



void counting_sort(int A[], int n) {
	int pos, min1 = A[0], max1 = A[0], amount_perms = 0, amount_comps = 0, x = 10000;

	for (int i = 0; i < n; i++) {
		if (A[i] > max1) {
			max1 = A[i];
			amount_comps++;
		}
		if (A[i] < min1) {
			min1 = A[i];
			amount_comps++;
		}
	}

	printf("\n\nМинимальный элемент массива: %d", min1);
	printf("\nМаксимальный элемент массива: %d", max1);
	printf("\n\n");

	int mx = max1;
	int mn = abs(min1);
	int* count = (int*)malloc(sizeof(int) * (mx + mn + x));

	for (int i = 0; i <= (mn + mx); i++) {
		count[i] = 0;
	}

	if (mn >= 0) {
		for (int i = 0; i < n; i++) {
			count[A[i]]++;
		}

		pos = 0;
		for (int i = 0; i <= (mx + mn); i++) {
			if (count[i] > 0) {
				for (int j = 0; j < count[i]; j++) {
					A[pos] = i;
					pos++;
					amount_perms++;
				}
				count[i] = 0;
			}
		}
	}


	else {
		for (int i = 0; i < n; i++) {
			count[A[i] + mn]++;
		}

		pos = 0;
		for (int i = 0; i <= (mx + mn); i++) {
			if (count[i] > 0) {
				for (int j = 0; j < count[i]; j++) {
					A[pos] = i + min1;
					pos++;
					amount_perms++;
				}
				count[i] = 0;
			}
		}
	}

	free(count);


	printf("\n\nМассив, отсортированный подсчетом:  ");
	for (int i = 0; i < n; i++) {
		printf(" %d ", A[i]);
	}
	printf("\nКоличество сравнений: %d ", amount_comps);
	printf("\nКоличество перестановок: %d ", amount_perms);
}



void merge(int A[], int left, int mid, int right, int amountp, int amountc) {

	int i, j, pos;
	int amount_perms = 0, amount_comps = 0;
	int la, ra;
	la = mid - left + 1;
	ra = right - mid;
	int *L = (int*)malloc(sizeof(int) * 10000);
	int *R = (int*)malloc(sizeof(int) * 10000);

	for (i = 0; i < la; i++) {
		L[i] = A[left + i];
	}

	for (j = 0; j < ra; j++) {
		R[j] = A[mid + 1 + j];
	}


	i = 0;
	j = 0;
	pos = left;

	while (i < la && j < ra) {
		if (L[i] <= R[j]) {
			A[pos] = L[i];
			i++;
			amount_perms++;
		}
		else {
			A[pos] = R[j];
			j++;
			amount_perms++;
		}
		pos++;
		amount_comps+=2;
	}

	//Заполняем массив оставшимися элементами.
	for (; i < la; i++) {
		A[pos] = L[i];
		pos++;
	}
	for (; j < ra; j++) {
		A[pos] = R[j];
		pos++;
	}
	amountp = amount_perms;
	amountc = amount_comps;
	free(L);
	free(R);
}



void merge_sort(int A[], int left, int right, int n, int amount_perms, int amount_comps) {

	int mid, amountp = 0, amountc = 0;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(A, left, mid, n, amount_perms, amount_comps);
		merge_sort(A, mid + 1, right, n, amount_perms, amount_comps);
		merge(A, left, mid, right, amountp, amountc);
		amount_perms = amountp;
		amount_comps = amountc;
	}
}




void quick_sort(int A[], int left, int right, int* amount_perms, int* amount_comps) {

	int x = 0, i, j, mid;
	mid = (right + left) / 2;
	int val = A[mid];

	i = left;
	j = right;

	while (i <= j) {
		while (A[i] < val) {
			i++;
			(*amount_comps)++;
		}
		while (A[j] > val) {
			j--;
			(*amount_comps)++;
		}

		if (i <= j) {
			x = A[i];
			A[i] = A[j];
			A[j] = x;
			i++;
			j--;
			(*amount_perms) += 2;
		}
	}
	if (i == j) {
		printf("Количество перестановок");
	}

	if  (j > left) {
		quick_sort(A, left, j, amount_perms, amount_comps);
	}
	if (i < right) {
		quick_sort(A, i, right, amount_perms, amount_comps);
	}
}



void linear_search(int A[], int n) {

	int val, k = 0, i = 0, amount_comps = 0;
	printf("Введите искомое значение в массиве: ");
	scanf("%d", &val);

	for (; i < n;i++) {
		if (A[i] == val) {
			printf("\nЗначение %d находится в массиве под индексом: %d \n", val, i);
			k++;
		}
		amount_comps++;
	}

	if (k == 0) {
		printf("\nИскомого значения в массиве не обнаружено!");
	}
	printf("\nКоличество сравнений: %d \n\n", amount_comps);
}



void binary_search(int A[], int n) {

	int val, k = 0, left, mid, right, amount_comps = 0;
	left = 0;
	right = n - 1;
	mid = (left + right) / 2;

	printf("Введите искомое значение в массиве: ");
	scanf("%d", &val); 

	while (right > left) {
		if (val == A[mid]) {
			printf("\nЗначение %d находится в массиве под индексом: %d", val, mid);
			k++;
			break;
		}
		if (val < A[mid]) {
			right = mid;
			amount_comps++;
			mid = (right + left) / 2;
			k++;
		}
		if (val > A[mid]) {
			left = mid;
			amount_comps += 2;
			mid = (right + left) / 2;
			k++;
		}
	}
	if (k == 0) {
		printf("\nИскомого значения в массиве не обнаружено!");
	}

	printf("\nКоличество сравнений: %d \n\n", amount_comps);
}














void start_menu()
{
	printf("1. Input array\n");
	printf("2. Random generated array\n");
}



void main_menu()
{
	printf("Методы сортировки: \n");
	printf("3. Bubble sorting standart\n"); //Done, checked!
	printf("4. Bubble sorting with optimization(bidirectional)\n"); //Done, checked!
	printf("5. Insertion sorting\n"); //Done, checked!
	printf("6. Counting sorting\n"); //Done, checked!
	printf("7. Merge sorting\n"); //Done, checked, working, but with unknown amount of perms & comps.
	printf("8. Hoare sorting / Quick sorting\n"); //Done, checked, work, but one of ten times:)
	printf("9. Linear search\n"); //Done, checked!
	printf("10. Binary search (needed sorted array!)\n"); //Done, checked!
}



void end_menu() 
{
	printf("1. Продолжить сортировку исходного массива другим методом.\n");
	printf("2. Выполнить бинарный поиск в отсортированном массиве.\n");
	printf("3. Задать новый массив.\n");
	printf("4. Закончить работу программы.\n");
}





int main()
{
	int c = 0, n = 0;   //Выбор опции пользователем из меню; кол-во эелемнтов массива.
	int minA = 0, maxA = 0;   //Max and Min элементы массива, заданные пользователем.
	int status = 0;
	int ap = 0, ac = 0;
	int A[10000];
	int Acopy[10000];
	double Time[9];
	int Perms[9];
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	LARGE_INTEGER freq, start, finish;
	double time;

	QueryPerformanceFrequency(&freq);

	while (c <= 10) {
		if (status == 0) {
			start_menu();
			printf("Введите ваш выбор: ");
			scanf("%d", &c);
			switch (c)
			{
			case 1: {
				printf("Введите желаемую длинну массива: ");
				scanf("%d", &n);

				for (int i = 0; i <= n; i++) {
					A[i] = 0;
				}

				if (n <= 10000) {
					printf("Вводите значения массива через пробел: \n");
					for (int i = 0; i < n; i++) {
						scanf("%d", &A[i]);
					}
					printf("\nВаш массив:  \n");
					for (int i = 0; i < n; i++) {
						printf("%d ", A[i]);
					}
					printf("\n \n");
					for (int i = 0; i < n; i++) {
						Acopy[i] = A[i];
					}
					status = 1;
				}
				else {
					printf("Превышен лимит объектов в массиве; пожалуйста, введите размер массива не более 10000 элементов.\n");
					status = 0;
				}
				break;
			}
			case 2: {
				printf("Введите желаемую длинну массива: ");
				scanf("%d", &n);

				for (int i = 0; i <= n; i++) {
					A[i] = 0;
				}

				printf("Введите минимальный и максимальный элемент диапазона генерации, соответсвенно: ");
				scanf("%d %d", &minA, &maxA);
				if (n <= 10000) {
					for (int i = 0; i < n; i++) {
						A[i] = minA + ((double)rand() / (RAND_MAX) * (maxA - minA));
					}
					printf("\nВаш массив:  \n");
					for (int i = 0; i < n; i++) {
						printf("%d ", A[i]);
					}
					printf("\n \n");
					for (int i = 0; i < n; i++) {
						Acopy[i] = A[i];
					}
					status = 1;
				}
				else {
					printf("Превышен лимит объектов в массиве; пожалуйста, введите размер массива не более 10000 элементов.\n");
					status = 0;
				}
				break;
			}
			default: {
				start_menu;
			}
			}
		}



		if (status == 1) {
			main_menu();
			printf("\nВыберите метод сортировки:  ");
			scanf("%d", &c);
			switch (c) {

			case 3: {
				QueryPerformanceCounter(&start);
				bubble_sort(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 4: {
				QueryPerformanceCounter(&start);
				bubble_sort_optimized(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 5: {
				QueryPerformanceCounter(&start);
				insertion_sort(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 6: {
				QueryPerformanceCounter(&start);
				counting_sort(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 7: {
				QueryPerformanceCounter(&start);
				/*int* ap = (int)malloc(sizeof(int) * 10);
				int* ac = (int)malloc(sizeof(int) * 10);
				ap = 0;
				ac = 0;*/
				merge_sort(Acopy, 0, n-1, n, ap, ac);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\n\nМассив, отсортированный слиянием:  ");
				for (int i = 0; i < n; i++) {
					printf(" %d ", Acopy[i]);
				}
				printf("\nКоличество перестановок: %d ", ap);
				printf("\nКоличество сравнений: %d ", ac);
				/*free(ap);
				free(ac);*/
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 8: {
				QueryPerformanceCounter(&start);
				quick_sort(Acopy, 0, n-1, &ap, &ac);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\n\nМассив, отсортированный быстрой сортировкой:  ");
				for (int i = 0; i < n; i++) {
					printf(" %d ", Acopy[i]);
				} 
				printf("\nМассив отсортирован за %lf !!!", Time[0]);
				break;
			}

			case 9: {
				QueryPerformanceCounter(&start);
				linear_search(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 1;
				Time[0] = time;
				printf("\nПоиск осуществлен за %lf !!!\n", Time[0]);
				printf("\n");
				break;
			}

			case 10: {
				printf("\nДля бинарного поиска необходим отсортированный массив! \nПроизведите сортировку.\n\n");
				break;
			}
			}
		}
		


		if (status == 2) {
			printf("\n\nСортировка массива закончена!!! Хотите выйти или попробовать другую сортировку?\n\n");
			end_menu();
			printf("Введите ваш выбор:  ");
			scanf("%d", &c);
			printf("\n");
			switch (c) {

			case 1: {
				for (int i = 0; i < n; i++) {
					Acopy[i] = A[i];
				}
				status = 1;
				break;
			}

			case 2: {
				QueryPerformanceCounter(&start);
				binary_search(Acopy, n);
				QueryPerformanceCounter(&finish);
				time = (double)(finish.QuadPart -
					start.QuadPart) / (double)freq.QuadPart;
				status = 2;
				Time[0] = time;
				printf("\nПоиск осуществлен за %lf !!! \n", Time[0]);
				break;
			}

			case 3: {
				status = 0;
				break;
			}

			case 4: {
				printf("\n\nThanks for use! GD!\n");
				c = 100;
				break;
			}
			}
		}
	}
	return 0;
}