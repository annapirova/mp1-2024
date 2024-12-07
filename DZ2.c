//Задача на двумерные массивы 13
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int minimum = 100000, minimum_stroko = 0;

void create_and_find(int** arr, int n, int m)
{
	int elementos;
	int i, j;
	//Ввод массива и одновременно поиск минимума
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf_s("%d", &elementos);
			arr[i][j] = elementos;
			if (elementos < minimum)
			{
				minimum = elementos;
				minimum_stroko = i;
			}
		}
	}
}

void print_and_cut(int** arr, int n, int m)
{
	int i, j;
	//Вывод матрицы с удаленной строкой
	for (i = 0; i < n; i++)
	{
		if (i == minimum_stroko)
			continue;
		for (j = 0; j < m; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int n, m, i, j, elementos;
	double mid = 0;
	printf("Enter strok, than enter stolb:\n");
	scanf_s("%d", &n);
	scanf_s("%d", &m);

	//Динамическое создание массива
	int** arr = (int**)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(m * sizeof(int));
	}
	printf("--------------\n");

	create_and_find(arr, n, m);

	printf("--------------\n");

	print_and_cut(arr, n, m);

	printf("--------------\n");

	return 0;
}
