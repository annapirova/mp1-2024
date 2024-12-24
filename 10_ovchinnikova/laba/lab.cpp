#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include <time.h>
void print_menu1()
{
	setlocale(LC_ALL, "Russian");
	printf("0. Input_array\n");
	printf("1. RandomArray\n");
}
void print_menu2()
{
	setlocale(LC_ALL, "Russian");
	printf("2. Bubble sort\n");
	printf("3. Insert sort\n");
	printf("4. Counting sort\n");
	printf("5. Selection Sort\n");
	printf("6. Quick Sort\n");
}
void print_menu3()
{
	printf("7. Linear_search\n");
	printf("8. Binary_search\n");
}

void Bubble_sort(int A[], int n)
{
	int swapped;
	int start = 0;
	int end = n - 1;

	do {
		swapped = 0;

		for (int i = start; i < end; i++) {
			if (A[i] > A[i + 1]) {
				int temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
				swapped = 1;
			}
		}
		end--;

	
		for (int i = end; i > start; i--) {
			if (A[i] < A[i - 1]) {
				int temp = A[i];
				A[i] = A[i - 1];
				A[i - 1] = temp;
				swapped = 1;
			}
		}
		start++; 

	} while (swapped);
}

void Insert_sort(int A[], int n)
{
	int sr = 0;
	printf("Сортировка вставками\n");
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = A[i];
		j = i - 1;

		// Перемещаем элементы A[0..i-1], которые больше key,
		// на одно положение вперед от их текущей позиции
		while (j >= 0 && A[j] > key)
		{
			A[j + 1] = A[j];
			sr = sr + 2;
			j = j - 1;
		}
		A[j + 1] = key;
		sr++;
	}
	printf("\nчисло сравнений и перестановок равно %d\n", sr);
}

void count(int mn, int mx, int n, int A[], int B[])
{
	int m;
	int sr = 0;
	for (int i = 0;i < n;i++) {
		m = A[i];
		B[m]++;
		sr++;
	}
	int i = 0;
	for (int j = mn;j < (mx + 1);j++) {
		sr++;
		while (B[j] > 0) {
			A[i] = j;
			i++;
			B[j]--;
			sr = sr + 2;
		}
	}
	printf("совершено %d перестановок и сравнений\n", sr);

}

// Функция сортировки выбором
void selectionSort(int A[], int n) {
	int i, j, min_idx;
	int sr = 0;

	for (i = 0; i < n - 1; i++) {
		sr++;
		// Находим индекс минимального элемента в неотсортированной части массива
		min_idx = i;
		for (j = i + 1; j < n; j++) {
			sr++;
			if (A[j] < A[min_idx]) {
				min_idx = j;
				sr = sr + 2;
			}
		}
		// Обмен найденного минимального элемента с первым элементом
		int temp = A[min_idx];
		A[min_idx] = A[i];
		A[i] = temp;
		sr = sr + 3;
	}
	printf("\nчисло сравнений и перестановок равно %d\n", sr);
}

void QS(int* A, int per, int pos, long int p, int p1[])
{

	int i = per, j = pos, x = A[(per + pos) / 2], tmp;

	do {
		p++;
		while (A[i] < x)
			i++;
		while (A[j] > x)
			j--;

		if (i <= j) {
			if (A[i] > A[j]) {
				tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;

			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < pos)
		QS(A, i, pos, p, p1);
	if (per < j)
		QS(A, per, j, p, p1);

	p1[0] += p;


}

int Linear_search(int A[], int n, int val)
{
	int i, k, sr;
	i = 0;
	k = 0;
	sr = 0;
	while ((i < n) && (A[i] != val)) {
		i++;
		sr++;
	}
	if (i < n) {
		k = i;
		sr++;
	}
	return k;
}
int Binary_search(int A[], int n, int val)
{
	int m, l, r, f, sr;
	m = 0;
	l = 0;
	r = n - 1;
	f = 0;
	sr = 0;
	while ((l <= r) && !f)
	{
		sr++;
		m = (l + r) / 2;
		if (val > A[m]) {
			l = m + 1;
			sr++;
		}
		else if (val < A[m]) {
			r = m - 1;
			sr++;
		}

		else f = 1;

	}
	return m;
}

void Copy_array(int A[], int B[], int n)
{
	int i;
	for (i = 0;i < n;i++)
		B[i] = A[i];
}

void Input_array(int A[], int n)
{
	printf("Элементы:");
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}

}

void RandomArray(int A[], int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		A[i] = min + rand() % (max - min + 1);  // Генерация случайного числа в диапазоне [min, max]
	}
}

int main()
{

	setlocale(LC_ALL, "Russian");

	int c, max, min;
	int A[10000];
	int B[10000];
	int H[10000];
	int n;
	int status = 0;
	printf("Выберите способ введения массива\n");
	print_menu1();
	scanf_s("%d", &c);
	if (c == 0) {
		printf("введите кол-во элементов массива\n");
		scanf_s("%d", &n);
		if (n > 10000) {
			printf("Превышение числа элементов в массиве.Введите кол-во элементов еще раз");
			scanf_s("%d", &n);
		}
		Input_array(A, n);
		printf("Массив A:");
		for (int i = 0; i < n; i++) {
			printf("%d ", A[i]);
		}
		status = 1;
	}
	if (c == 1) {
		printf("введите кол-во элементов массива\n");
		scanf_s("%d", &n);
		if (n > 10000) {
			printf("Превышение числа элементов в массиве.Введите кол-во элементов еще раз ");
			scanf_s("%d", &n);
		}
		printf("введите минимальную  границу, в которой будут находиться числа\n");
		scanf_s("%d", &min);
		printf("введите максимаьную  границу, в которой будут находиться числа\n");
		scanf_s("%d", &max);
		RandomArray(A, n, min, max);
		printf("Массив A:");
		for (int j = 0; j < n; j++) {
			printf("%d ", A[j]);
		}
		status = 1;
	}
	printf("\nВыберите метод сортировки\n");
	print_menu2();
	scanf_s("%d", &c);
	long int y = 0;
	int p1[2] = { 0,0 };
	if (c == 2) {
		Copy_array(A, H, n);
		int k = 0;
		Bubble_sort(H, n);
		for (int j = 0; j < n; j++) {
			printf("%d ", H[j]);
		}
		status = 2;
	}
	if (c == 3) {
		Copy_array(A, H, n);
		Insert_sort(H, n);
		for (int j = 0; j < n; j++) {
			printf("%d ", H[j]);
		}
		status = 2;
	}
	if (c == 4) {
		Copy_array(A, H, n);
		//сортировка методом подсчета
		int mn, mx;
		mx = H[0];
		mn = H[0];

		for (int i = 0; i < n;i++) {
			if (H[i] < mn)
				mn = H[i];
			if (H[i] > mx)
				mx = H[i];
		}
		for (int i = mn;i < (mx + 1);i++) {
			B[i] = 0;
		}
		count(mn, mx, n, H, B);
		for (int i = 0;i < n;i++) {
			printf("%d ", H[i]);
		}
		status = 2;
	}
	if (c == 5) {
		Copy_array(A, H, n);
		selectionSort(H, n);
		for (int j = 0; j < n; j++) {
			printf("%d ", H[j]);
		}
		status = 2;
	}
	if (c == 6) {
		Copy_array(A, H, n);
		QS(A, 0, n - 1, y, p1);
		for (int j = 0; j < n; j++) {
			printf("%d ", H[j]);
		}
		status = 2;
	}
	printf("\nвыбери метод поиска элемента в масиве\n");
	print_menu3();
	scanf_s("%d", &c);
	if (c == 7) {
		int val, k;
		printf("введи значение, которое необходимо найти ");
		scanf_s("%d", &val);
		k=Linear_search(H, n, val);
		printf("%d", k + 1);
	}
	if (c == 8) {
		int val, m;
		printf("\nвведи значение, которое необходимо найти ");
		scanf_s("%d", &val);
		m=Binary_search(H, n, val);
		printf("%d", m + 1);
	}

}
