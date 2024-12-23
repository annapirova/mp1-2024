#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <locale.h>
#include "windows.h"

#define C  15000



double Times(double t)
{
	printf("\n\n");
	printf("%f" t);
	printf("\n\n\n");
}


void merge(int mass[], int left, int m, int right) {
	int n1 = m - left + 1;  
	int n2 = right - m;     

	int massleft[C], massright[C];

	for (int i = 0; i < n1; i++) {
		massleft[i] = mass[left + i];
	}
	for (int i = 0; i < n2; i++) {
		massright[i] = mass[m + 1 + i];
	}

	int i = 0, j = 0, k = left;

	for (; i < n1 && j < n2; k++) {
		if (massleft[i] <= massright[j]) {
			mass[k] = massleft[i++];
		}
		else {
			mass[k] = massright[j++];
		}
	}

	for (; i < n1; i++, k++) {
		mass[k] = massleft[i];
	}




	for (; j < n2; j++, k++) {
		mass[k] = massright[j];
	}
}

double ShakerSort(int mass[], int n, int *p)
{
	LARGE_INTEGER freq, start, finish;

	QueryPerformanceFrequency(&freq); // 1 раз на программу
	QueryPerformanceCounter(&start);

	int f = 1;
	int left = 0; int right = n - 1;
	int i, j;
	double tmp;

	for (i = 0; (i < n) && (f); i++)
	{
		f = 0;
		if (i % 2 == 1)
		{
			for (j = left; j < right - 1; j++)
			{
				(*p)++;
				if (mass[j] > mass[j + 1])
				{
					tmp = mass[j];
					mass[j] = mass[j + 1];
					mass[j + 1] = tmp;
					f = 1;


					(*k)++;

				}
				
			}
			right--;
		}
		else
			for (j = right - 1; j > left - 1; j--)
			{
				(*p)++;
				if (mass[j] < mass[j - 1])
				{
					tmp = mass[j];
					mass[j] = mass[j - 1];
					mass[j - 1] = tmp;
					f = 1;


					(*k)++;

				}
				

			}
		left++;

	}
	QueryPerformanceCounter(&finish); // конец замера
	return (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

double InsertionSort(int mass[], int n, int *p)
{
	LARGE_INTEGER freq, start, finish;

	QueryPerformanceFrequency(&freq); // 1 раз на программу
	QueryPerformanceCounter(&start);

	int tmp = 0;

	int k, x;

	for (x = 1; x < n; x++) 
	{
		tmp = mass[x];
		k = x;

		while (k > 0 && mass[k - 1] > tmp) 
		{
			mass[k] = mass[k - 1];
			k--
		}

		mass[k] = tmp;
	}
	QueryPerformanceCounter(&finish); // конец замера
	return (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

double MergeSort(int mass[], int left, int right, int* p) 
{
	LARGE_INTEGER freq, start, finish;

	QueryPerformanceFrequency(&freq); // 1 раз на программу
	QueryPerformanceCounter(&start);

	if (left < right)
	{
		int m = (left + right) / 2;
		MergeSort(mass, left, m, p);
		MergeSort(mass, m + 1, right, p);
		merge(mass, left, m, right);
		(*p)++;
	}

	QueryPerformanceCounter(&finish); // конец замера
	return (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

double QS(int mass[], int left, int right, int* p)
{
	LARGE_INTEGER freq, start, finish;

	QueryPerformanceFrequency(&freq); // 1 раз на программу
	QueryPerformanceCounter(&start);

	int m = (right + left) / 2;
	int val = mass[m];
	int i, j, tmp;

	i = left;
	j = right;

	while (i <= j)
	{
		while (mass[i] < val)
			i++;
		while (mass[j] > val)
			j--;
		if (i <= j)
		{
			tmp = mass[i];
			mass[i] = mass[j];
			mass[j] = tmp;
			i++;
			j--;
		}
		(*p)++;
	}

	if (i > left)
		QS(mass, left, j, p);
	if (j < right)
		QS(mass, i, right, p);
	QueryPerformanceCounter(&finish); // конец замера
	return (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

double SortShell(int mass[], int n, int* p)
{
	LARGE_INTEGER freq, start, finish;

	QueryPerformanceFrequency(&freq); // 1 раз на программу
	QueryPerformanceCounter(&start);

	int step, i, j, tmp;

	for (step = n / 2; step > 0; step = step / 2)
	{
		for (i = step; i < n; i++)
		{
			tmp = mass[i];
			for (j = i; j >= step; j = j - step)
			{
				if (tmp < mass[j - step])
				{
					mass[j] = mass[j - step];
					(*p)++;
				}
				else
					break;
			}
			mass[j] = tmp;
		}
	}

	QueryPerformanceCounter(&finish); // конец замера
	return (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
}

int BinarySearch(int mass[], int n, int val, int *s)
{
	int left = 0;
	int right = n - 1;
	int m;

	while (left <= right)
	{
		(*s)++;
		m = left + (right - left) / 2;

		if (mass[m] == val)
			return m;

		if (mass[m] < val)
			left = m + 1;
		else
			right = m - 1;
		(*s)++;
	}

	return -1;
}

int LinearSearch_2(int mass[], int n, int val, int *s)
{
	int i = 0;
	while (i < n)
	{
		(*s)++;
		if (mass[i] == val)
			return i;
		else
			i++;
		
	}
	return -1;
}

int random(int mass[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		mass[i] = rand() % 1000;
}






int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(NULL));


	int p = 0, s = 0, k = 0;

	double time;
	double time1, time2, time3, time4, time5;
	int a, M;
	int N, n, i;
	int mass[C];


	

	char answer = 'Y';
Start:
	printf("Выберите каким способом Вы хотите задать массив:\n1 - задать случайный массив;\n2 - задать свой массив.\n\n");
	scanf_s("%d", &N);

	printf("\nВведите длинну массива (длинна массива не должна превышать %d):\t", C);
	scanf_s("%d", &n);
	if (n > C)
		goto Start;



	int array = (int*) malloc(sizeof(int) * n))


	switch (N)
	{
	case 1:


			random(array, n);

			break;

		case 2:
			printf("Введите элементы массива:");
			for (i = 0; i < n; i++)

	
				scanf_s("%d", &array[i]);

			break;
		default:
			printf("Выбран не существующий варинат. Попытайтесь снова.\n\n\n");
			goto Start;
			break;
	}
	printf("\n");
	/*for (i = 0; i < n; i++)
		printf("%d\t", mass[i]);*/
	printf("\n\n\n");

Choice:

	printf("\nВыберете способ сортировки массива:\n1 - двунаправленная сортировка пузырьком;\n2 - сортировка вставками;\n3 - сортировка слияния;\n4 - сортировка Хара;\n5 - сортировка Шелла.\n\n");
	scanf_s("%d", &N);
	printf("\n");

	switch (N)
	{
	case 1:


		time1 = ShakerSort(array, n, &p);



			break;
	case 2:


		time2 = InsertionSort(array, n, &p);



			break;
	case 3:



		time3 = MergeSort(array, 0, n - 1, &p);



		break;
	case 4:



		time4 = QS(array, 0, n - 1, &p);



		break;
	case 5:



		time5 = SortShell(array, n, &p);



		break;
	default:
		printf("Выбран не существующий варинат. Попытайтесь снова.\n\n\n");
		goto Choice;

		break;
	}
	for (i = 0; i < n; i++)


		printf("%d\t", array[i]);


	/*printf("\n\n");
	printf("%d\t%f", p, time);
	printf("\n\n\n");*/

	Choice2:
	printf("\nЖелаете выбрать другую сортировку или ввести другой массив?\n1 - выбрать другую сортировку.\n2 - ввести другой массив.\n3 - далее\n\n");
	scanf_s("%d", &N);

	switch (N)
	{
	case 1:
		goto Choice;

	case 2:
		goto Start;
	case 3:
		break;

	default:
		printf("Выбран не существующий варинат. Попытайтесь снова.\n\n\n");
		goto Choice2;

		break;
	}
	Choice3:
	printf("\nВыберете метод поиска:\n1 - линейный поиск;\n2 - бинарный поиск.\n\n");
	scanf_s("%d", &N);

	Choice4:
	printf("\nВведите число, которое хотите найти:\t");
	scanf_s("%d", &a);

	switch (N)
	{
	case 1:

		M = LinearSearch_2(mass, n, a, &s);
		break;
	case 2:
		M = BinarySearch(mass, n, a, &s);

		M = LinearSearch_2(array, n, a, &s);
		break;
	case 2:
		M = BinarySearch(array, n, a, &s);

		break;
	default:
		printf("Выбран не существующий варинат. Попытайтесь снова.\n\n\n");
		goto Choice3;
		break;
	}

	if (M > -1)
		printf("%d", M);
	else
	{
		while (answer == 'Y' || answer == 'N')
		{
			printf("Число не найдено.\nНайти другое число? (Y/N)\t");
			scanf_s(" %c", &answer, 1);
		
			if (answer == 'Y' || answer == 'N')
				break;

			else
				printf("Некорректный ввод. Пожалуйста, введите Y или N.\n");
		}

	}

	if (answer == 'Y')
		goto Choice4;
	
	

	printf("\n\n");
	printf("%d", s);


	return 0;
}