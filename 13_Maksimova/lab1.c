#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "time.h"

int z = 0;
void main()
{
	setlocale(LC_ALL, "Rus");
	int a, b, i, mass[10], temp[10], min = 0, max = 9, left = 0, right = 9, mid;

	printf("Выберите способ ввода массива:");
	scanf_s("%d", &a);

	if (a == 1) {
		printf("Задайте массив  длиной в 10 значений:");
		for (int i = 0; i < 10; i++)
		{
			scanf_s("%d", &mass[i]);
		}
	}
	if (a == 2) {
		srand(time(NULL));
		for (int i = 0; i < 10; i++) {
			mass[i] = rand() % 100;
			printf("%d\n", mass[i]);
		}
	}
	printf("Выберите метод сортировки:");
	scanf_s("%d", &b);
	switch (b)
	{
	case 1:
		bubbleSort(mass);
		for (int i = 0; i < 10; i++)
		{
			printf("%d\t", mass[i]);
		}
		break;
	case 2:
		mergeSort(mass, left, right, z);
		for (int i = 0; i < 10; i++)
		{
			printf("%d\t", mass[i]);
		}
		break;
	case 3:
		QuikSort(mass, left, right);
		for (int e = 0; e < 10; e++)
		{
			printf("%d\t", mass[e]);
		}
		break;
	case 4:
		InsertionSort(mass);
		for (int i = 0; i < 10; i++)
		{
			printf("%d\t", mass[i]);
		}
		break;
	case 5:
		selectionSort(mass);
		for (int i = 0; i < 10; i++)
		{
			printf("%d\t", mass[i]);
		}
		break;
	default:
		printf("Ошибка");
		break;
	}

	printf("Выберите способ поиска:");
	int target;
	int h;
	scanf_s("%d", &h);
	switch (h)
	{
	case 1:
		printf("Введите элемент для поиска:");
		scanf_s("%d", &target);
		int indexB = BinSearch(mass, min, max, target);
		printf("Элементу принадлежит индекс  %d", indexB);
		break;
	case 2:
		printf("Введите элемент для поиска:");
		scanf_s("%d", &target);
		LinSearch(mass, min, max, target);
		int indexL = LinSearch(mass, min, max, target);
		printf("Элементу принадлежит индекс  %d", indexL);
		break;
	default:
		printf("Ошибка");
		break;
	}
}
int bubbleSort(int mass[])// Двунаправленный пузерек
{
	int left = 0, right = 10 - 1;
	int flag = 1;
	clock_t start = clock();
	z++;
	printf("z = % d\n", z);
	while ((left < right) && flag > 0) {
		flag = 0;
		for (int i = left; i < right; i++) {
			if (mass[i] > mass[i + 1]) {
				int t = mass[i];
				mass[i] = mass[i + 1];
				mass[i + 1] = t;
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--) {
			if (mass[i - 1] > mass[i]) {
				int t = mass[i];
				mass[i] = mass[i - 1];
				mass[i - 1] = t;
				flag = 1;

			}
		}
		left++;
		z++;
		printf("z = % d\n", z);
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");

}
int merge(int mass[], int left, int a, int right) //Метод слияния
{
	clock_t start = clock();
	int i, j, k;
	int n1 = a - left + 1;
	int n2 = right - a;
	int leftArr[10], rightArr[10];

	for (i = 0; i < n1; i++)
		leftArr[i] = mass[left + i];
	for (j = 0; j < n2; j++)
		rightArr[j] = mass[a + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		z++;
		printf("z = % d\n", z);

		if (leftArr[i] <= rightArr[j]) {
			mass[k] = leftArr[i];
			i++;
		}
		else {
			mass[k] = rightArr[j];
			j++;
		}
		k++;

	}

	while (i < n1) {

		mass[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < n2) {

		mass[k] = rightArr[j];
		j++;
		k++;
	}

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");

}

int mergeSort(int mass[], int left, int right)
{

	if (left < right)
	{
		int a = left + (right - left) / 2;
		mergeSort(mass, left, a);
		mergeSort(mass, a + 1, right);
		merge(mass, left, a, right);
	}
}
int QuikSort(int mass[], int left, int right) // Быстрая сортировка
{
	z++;
	printf("z = % d\n", z);
	if (left > right)
		return;
	clock_t start = clock();
	int i = left;
	int j = right;
	int pivot = mass[(right + left) / 2];
	while (i <= j)
	{
		while (mass[i] < pivot)
		{
			i++;

		}
		while (mass[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			int temp = mass[i];
			mass[i] = mass[j];
			mass[j] = temp;
			i++;
			j--;
		}
	}
	QuikSort(mass, left, j);
	QuikSort(mass, i, right);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");
}
int InsertionSort(int mass[]) // Сортировка вставками
{
	clock_t start = clock();
	z++;
	printf("z = %d\n", z);
	int el, loc;
	for (int i = 1; i < 10; i++)
	{
		el = mass[i];
		loc = i - 1;
		while (loc >= 0 && mass[loc] > el)
		{
			mass[loc + 1] = mass[loc];
			loc = loc - 1;
			z++;
			printf("z = %d\n", z);
		}

		mass[loc + 1] = el;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");
}
int selectionSort(int mass[]) // Сортировка выбором
{
	clock_t start = clock();
	z++;
	printf("z = %d\n", z);
	for (int i = 0; i < 10; i++)
	{
		int min_idx = i;
		for (int j = i + 1; j < 10; j++)
		{
			if (mass[j] < mass[min_idx])
			{
				min_idx = j;
				z++;
				printf("z = %d\n", z);
			}
		}
		int temp = mass[min_idx];
		mass[min_idx] = mass[i];
		mass[i] = temp;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Время работы вашей программы: %f \n", time_spent);
	printf("\n");
}

int BinSearch(int mass[], int min, int max, int target)  // Бинарный поиск
{
	while (min <= max)
	{
		int mid = (min + max) / 2;
		if (target < mass[mid])
		{
			max = mid - 1;
		}
		else if (target > mass[mid])
		{
			min = mid + 1;
		}
		else
		{
			return mid;
		}
	}
	return -1;
}

int LinSearch(int mass[], int min, int max, int target) // Линейный поиск
{
	for (int i = 0; i < 10; i++)
	{
		if (mass[i] == target)
		{
			return i;
		}
	}
	return -1;
}
