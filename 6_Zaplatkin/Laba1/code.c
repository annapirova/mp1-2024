#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <windows.h>

int is_sort=0;
int ex = 0;
int GlobArray[10000] = { 0 };
int GlobSort[10000] = { 0 };
double Time[5] = { 0.0 };
int SwapArray[5] = {0};

int MaxArray(int A[], int n)
{
	int max=A[0], i;
	for (i = 0; i < n; i++)
	{
		if (A[i] > max)
		{
			max = A[i];
		}
	}
	return (max);
}

int MinArray(int A[], int n)
{
	int min = A[0], i;
	for (i = 0; i < n; i++)
	{
		if (A[i] < min)
		{
			min = A[i];
		}
	}
	return (min);
}

void ArrayOutput(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\t", A[i]);
	}
	printf("\n__________________________________________________________________\n");
}

void SortTimeOutput(double A[5], int n)
{
	int i;
	for (i = 0; i < 5; i++)
	{	
		switch (i) 
		{
		case 0:
			printf("Сортировка 'пузырьком'\t");
			break;
		case 1:
			printf("Сортировка вставками\t");
			break;
		case 2:
			printf("Сортировка выбором\t");
			break;
		case 3:
			printf("Сортировка подсчётом\t");
			break;
		case 4:printf("Быстрая сортировка\t");
			break;
		}
		
		printf("%.7fсек\t", A[i]);
		printf("%d перест\n", SwapArray[i]);
	}
	printf("_________________________________________________________________\n");
	main(n);
}

void ArrayInput(int A[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &A[i]);
	}
}

void RandArrayInput(int A[], int n)
{
	srand(time(NULL));
	int tmp, i, randtemp, low, up;
	printf("Введите нижнюю границу диапазона рандома:\n");
	scanf_s("%d", &low);
	printf("Введите верхнюю границу диапазона рандома:\n");
	scanf_s("%d", &up);
	if (low > up)
	{
		tmp = low;
		low = up;
		up = tmp;
	}
	for (i = 0; i < n; i++)
	{
		if (up == low)
		{
			randtemp = up;
		}
		else 
		{
			randtemp = low + rand() % (up - low);
		}
		A[i] = randtemp;
	}
}

int ArraySortTest(int A[], int n)
{
	int i,is_sort = 1;
	for (i = 0; i < n-1; i++)
	{
		if (A[i] > A[i+1])
		{
			is_sort = 0;
			break;
		}
	}
	return(is_sort);
}

int ArraySettings()
{
	int rightsize=0, arrent, q, stuptest=0, rightarr = 1, rightop=0, stuptest2=0, w, n;
	
	while (!rightop)
	{
		is_sort = 0;
		printf("Выберете действие с массивом:\n");
		printf("1 - Задать/изменить размер массива с последующим его заданием.\n");
		printf("2 - Задать новый массив прежнего размера.\n");
		scanf_s("%d", &q);
		switch (q)
		{
		case 1:
			while (!rightsize)
			{
				rightsize = 1;
				printf("Введите размер массива: \t");
				scanf_s("%d", &n);
				if (n <= 0)
				{
					printf("Размер массива не может быть отрицательным!!\n");
					rightsize = 0;
				}
				else
				{
					for (q = 0; q < 5; q++)
					{
						Time[q] = 0.0;
					}
					for (q = 0; q < 5; q++)
					{
						SwapArray[q] = 0;
					}
					for (q = 0; q < n; q++)
					{
						GlobSort[q] = 0;
					}
					int* GlobArray = malloc(n * sizeof(int));
					int* GlobSort = malloc(n * sizeof(int));
				}
			}
		case 2:
			rightop = 1;
			while (!(rightarr - 1))
			{
				while (!stuptest)
				{
					stuptest = 1;
					printf("Выберете способ задания массива: \n");
					printf("1 - Ручной ввод\n");
					printf("2 - Случайный массив\n");
					scanf_s("%d", &arrent);
					switch (arrent)
					{
					case 1:
						ArrayInput(GlobArray, n);
						break;
					case 2:
						RandArrayInput(GlobArray, n);
						break;
					default:
						stuptest = 0;
						printf("Введёная команда не существует!\n");
						break;
					}
				}
				printf("Ваш исходный массив: \n");
				ArrayOutput(GlobArray, n);
				ArraySortTest(GlobArray, n);
				if (is_sort)
				{
					for (w = 0; w < n; w++)
					{
						GlobSort[w] = GlobArray[w];
					}
				}
				while (!stuptest2)
				{
					stuptest2 = 1;
					printf("Массив верен?\n");
					printf("1 - Да\n");
					printf("2 - Нет\n");
					scanf_s("%d", &rightarr);
					switch (rightarr)
					{
					case 1:
						rightarr = 2;
						break;
					case 2:
						rightarr = 1;
						stuptest = 0;
						break;
					default:
						printf("Введёная команда не существует!\n");
						stuptest2 = 0;
						break;
					}
				}
				stuptest2 = 0;
			}
			break;
		default:
			printf("Введёная команда не существует!\n");
			break;
		}
	}
	main(n);
}

void LineSearch(int A[], int n)
{
	int searcher, finder = 0, i, compares=0;
	printf("Введите число для поиска\n");
	scanf_s("%d", &searcher);
	for (i = 0; i < n; i++)
	{
		if (A[i] == searcher)
		{
			printf("Индекс числа равен: %d\n", i);
			finder = 1;
			break;
		}
		compares++;
	}
	if (!finder)
	{
		printf("Числа нет в массиве.\n");
	}
	printf("Было сделано %d сравнений.\n", compares);
}

void BinSearch(int A[], int n)
{
	int left = 0, right = n, searcher, finder=0, mid, compares=0;
	printf("Введите число для поиска\n");
	scanf_s("%d", &searcher);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (A[mid] == searcher)
		{
			printf("Индекс числа равен: %d\n", mid);
			finder = 1;
			compares++;
			break;
		}
		else if (A[mid] < searcher)
		{
			compares+=2;
			left = mid + 1;
		}

		else
		{
			compares+=2;
			right = mid - 1;
		}
	}
	if (!finder)
	{
		printf("Числа нет в массиве.\n");
	}
	printf("Было сделано %d сравнений.\n", compares);
	main(n);
}

void LineSearchMenu(int n)
{
	int i, sorted, stuptest = 0, finder = 0;
	int* A = malloc(n * sizeof(int));
	while (!stuptest)
	{
		stuptest = 1;
		printf("В каком массиве поиск?\n");
		printf("1 - Отсортированный\n");
		printf("2 - Изначальный\n");
		scanf_s("%d", &sorted);
		switch (sorted)
		{
		case 1:
			if (is_sort)
			{
				for (i = 0; i < n; i++)
				{
					A[i] = GlobSort[i];
				}
			}
			else
			{
				stuptest = 0;
				printf("Нет отсортированного массива\n");
			}
			break;
		case 2:
			for (i = 0; i < n; i++)
			{
				A[i] = GlobArray[i];
			}
			break;
		default:
			stuptest = 0;
			printf("Введённая команда не существует\n");
			break;
		}
	}
	LineSearch(A, n);
	main(n);
}

void SearchMenu(int n)
{
	int searchtemp, stuptest=0;
	while (!stuptest)
	{
		stuptest = 1;
		printf("Выберете поиск:\n");
		printf("1 - Линейный поиск.\n");
		printf("2 - Бинарный поиск.    ВНИМАНИЕ! Бинарный поиск только для отсортированных массивов\n");
		scanf_s("%d", &searchtemp);
		switch (searchtemp)
		{
		case 1:
			LineSearchMenu(n);
			break;
		case 2:
			if (is_sort)
			{
				BinSearch(GlobSort, n);
			}
			else
			{
				printf("Нет отсортированного массива!\n");
			}
			break;
		default:
			stuptest = 0;
			printf("Введёная команда не существует!\n");
			break;
		}
	}
	main(n);
}

void Swap(int i, int j, int A[], int q)
{
	int temp;
	temp = A[i];
	A[i] = A[j];
	A[j] = temp;
	SwapArray[q]++;
}

void BubbleSort(int A[], int n)
{
	SwapArray[0] = 0;
	int left = 0, right = n - 1, i, is_sort = 0;
	while ((left <= right)&&(!is_sort))
	{
		for (i = right; i > left; i--)
		{
			if (A[i - 1] > A[i])
			{
				Swap(i, i - 1, A, 0);
			}
		}
		++left;
		for (i = left; i < right; i++)
		{
			if (A[i] > A[i + 1])
			{
				Swap(i, i + 1, A, 0);
			}
		}
		--right;
	}
	is_sort = ArraySortTest(A, n);
}

void InsertSort(int A[], int n)
{
	SwapArray[1] = 0;
	int pos, val, k;
	for (pos = 0; pos < n - 1; pos++)
	{
		val = A[pos + 1];
		k = pos;
		while ((k >= 0) && (A[k] > val))
		{
			A[k + 1] = A[k];
			SwapArray[1]++;
			k--;
		}
		A[k + 1] = val;
		SwapArray[1]++;
	}
}

void ChoiseSort(int A[], int n)
{
	SwapArray[2] = 0;
	int i, pos, j;
	for (i = 0; i < n; i++)
	{
		pos = i;
		for (j = i + 1; j < n; j++)
		{
			if (A[pos] > A[j])
			{
				pos = j;
			}
		}
		Swap(pos, i, A, 2);
	}
}
void CountSort(int A[], int n)
{
	SwapArray[3] = 0;
	int min, max, i, q, j, pos=0;
	for (q = 0; q < n; q++)
	{
		A[q] = GlobArray[q];
	}
	min = MinArray(GlobArray, n);
	max = MaxArray(GlobArray, n);
	int* B = malloc((max-min+1) * sizeof(int));
	for (q = 0; q < (max-min+1); q++)
	{
		B[q] = 0;
	}
	for (i = 0; i < n; i++)
	{
		B[A[i]-min]+=1;
	}
	for (i = 0; i <= max-min; i++)
	{
		if (B[i] > 0)
		{
			for (j = 0; j < B[i]; j++)
			{
				A[pos] = i+min;
				SwapArray[3]++;
				pos++;
			}
		}
	}
}

void QSort(int* A, int end)
{
	int i = 0, j = end-1, mid;
	mid = A[end/2];
	do
	{
		while (A[i] < mid)
		{
			i++;
		}
		while (A[j] > mid)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(i, j, A, 4);
			i++;
			j--;
		}
	} while (i <= j);
	if (j > 0)
	{
		QSort(A, j + 1);
	}
	if (i < end)
	{
		QSort(&A[i], end - i);
	}
}

void SortMenu(int n)
{
	LARGE_INTEGER freq, start, finish;
	double time;
	int i, stuptest = 0, sorttemp, w, is_sort=0;
	int* A = malloc(n * sizeof(int));
	QueryPerformanceFrequency(&freq);
	for (i = 0; i < n; i++)
	{
		A[i] = GlobArray[i];
	}
	while (!stuptest)
	{
		stuptest = 1;
		printf("Выберите сортировку:\n");
		printf("1 - Сортировка 'пузырьком'\n");
		printf("2 - Сортировка вставками\n");
		printf("3 - Сортировка выбором\n");
		printf("4 - Сортировка подсчётом\n");
		printf("5 - Быстрая сортировка\n");
		scanf_s("%d", &sorttemp);
		switch(sorttemp)
		{
		case 1:
			is_sort = 0;
			QueryPerformanceCounter(&start);
			BubbleSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[0] = time;
			if (ArraySortTest(A, n))
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(A, n);
			break;
		case 2:
			is_sort = 0;
			QueryPerformanceCounter(&start);
			InsertSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[1] = time;
			is_sort=ArraySortTest(A, n);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort, n);
			break;
		case 3:
			is_sort = 0;
			QueryPerformanceCounter(&start);
			ChoiseSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[2] = time;
			is_sort = ArraySortTest(A, n);
			if (is_sort)
			{
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(GlobSort, n);
			break;
		case 4:
			SwapArray[4] = 0;
			QueryPerformanceCounter(&start);
			CountSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[3] = time;
			if (ArraySortTest(A, n))
			{

				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			ArrayOutput(A, n);
			break;
		case 5:
			is_sort = 0;
			QueryPerformanceCounter(&start);
			QSort(A, n);
			QueryPerformanceCounter(&finish);
			time = (double)(finish.QuadPart - start.QuadPart) / (double)freq.QuadPart;
			Time[4] = time;
			is_sort = ArraySortTest(A, n);
			if (is_sort)
			{
				ArrayOutput(A, n);
				for (w = 0; w < n; w++)
				{
					GlobSort[w] = A[w];
				}
			}
			break;
		default:
			printf("Введёная команда не существует!\n");
			stuptest = 0;
			break;
		}
	}
	main(n);
}

int main(int n)
{
	int mainmenu, stuptest=0;
	setlocale(LC_ALL, "Rus");
	while ((!stuptest) && (!ex))
	{
		stuptest = 1;
		printf("Главное меню:\n");
		printf("0 - Выход\n");
		printf("1 - Настройка массива.\n");
		printf("2 - Меню поиска.\n");
		printf("3 - Меню сортировок.\n");
		printf("4 - Таблица времени сортировок.\n");

		scanf_s("%d", &mainmenu);
		switch (mainmenu)
		{
		case 0:
			ex = 1;
			printf("Удачного дня!!!\n");
			break;
		case 1:
			n = ArraySettings();
			break;
		case 2:
			SearchMenu(n);
			break;
		case 3:
			SortMenu(n);
			break;
		case 4:
			SortTimeOutput(Time, n);
			break;
		default:
			printf("Введёная команда не существует!\n");
			stuptest = 0;
			break;
		}
	}
	return 0;
}