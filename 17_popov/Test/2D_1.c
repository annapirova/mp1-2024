#include "stdlib.h"
#include "time.h"
#include "stdio.h"
#include "locale.h"

void Fill(int** arr, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
}

int Pass(int** arr, int m, int n, int* max_x, int* max_y, int* a, int* b)
{
	int i, j, k, w, buff, x, y, S;
	i = 0;
	j = 0;
	S = 0;
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (arr[i][j] == 0)
			{
				x = 0;
				y = 0;


				while ((j + x < n) && (arr[i][j + x] == 0))
					x++;
				while ((i + y < m) && (arr[i + y][j] == 0))
					y++;

				buff = x * y;

				if (S < buff)
				{
					S = buff;
					*max_x = i;
					*max_y = j;
					*a = i + y;
					*b = j + x;

				}

			}
		}
	}
	return S;
}

void Print(int** arr, int m, int n)
{
	int i, j;
	for (i = 0; i < m; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d\t", arr[i][j]);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int max_x, max_y;
	int a, b;
	
	int n = 8, m = 8;
	int i;
	scanf_s("%d %d", &m, &n);


	int* Arr = (int*)malloc(sizeof(int) * m * n);
	int** Matrix = (int**)malloc(sizeof(int*) * m);
	for (i = 0; i < m; i++)
		Matrix[i] = Arr + i * n;
	if (Arr == NULL) 
	{
		printf("Ошибка выделения памяти для массива Matrix.\n");
		free(Arr);
		return 1;
	}


	
	srand(time(NULL));
	Fill(Matrix, m, n);
	Print(Matrix, m, n);

	printf("\n");
	printf("Площадь = %d\n", Pass(Matrix, m, n, &max_x, &max_y, &a, &b));
	printf("Верхний левый угол: (%d, %d)\n", max_x, max_y);
	printf("Правый нижний угол: (%d, %d)\n", a - 1 , b - 1);

	free(Arr);
	free(Matrix);
	return 0;
}