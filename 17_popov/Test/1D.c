#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void Fill(int arr[], int N)
{
	int i, j, buff, p;
	j = 0;
	while (j < N)
	{
		p = rand() % 20;
		buff = 0;
		for (i = 0; i < N; i++)
		{
			if (p == arr[i])
			{
				buff++;
				break;
			}

		}

		if (buff == 0)
		{
			arr[j] = p;
			j++;
		}
	}

}

int Union(int A[], int n, int B[], int m, int C[])
{
	int i, j, k, buff;
	//Копирование массива А в массив С
	for (i = 0; i < n; i++)
		C[i] = A[i];

	k = n;

	for(j = 0; j < m; j++)
	{
		buff = 0;
		for (i = 0; i < k; i++)
		{
			if (C[i] == B[j])
			{
				buff++;
				break;
			}
			
		}

		if (buff == 0)
		{
			C[k] = B[j];
			k++;
		}
	}
	return k;
}

int Inter(int A[], int n, int B[], int m, int C[])
{
	int i, j, k, buff;
	

	k = 0;

	for (j = 0; j < m; j++)
	{
		for (i = 0; i < n; i++)
		{
			if (A[i] == B[j])
			{
				C[k] = A[i];
				k++;
				break;
			}

		}

	}
	return k;
}

int Print(int arr[], int N)
{
	int i;
	for (i = 0; i < N; i++)
		printf("%d\t", arr[i]);
}


int main()
{
	//Ввод массивов
	int n = 11, m = 8;
	int l;
	/*scanf_s("%d", n);
	scanf_s("%d", m);*/
	int* A = (int*)malloc(sizeof(int) * n);
	int* B = (int*)malloc(sizeof(int) * m);
	int* C = (int*)malloc(sizeof(int) * (m + n));


	//Заполнение массивов
	srand(time(NULL));
	Fill(A, n);
	Fill(B, m);

	Print(A, n);
	printf("\n\n");
	Print(B, m);
	printf("\n\n");

	l = Union(A, n, B, m, C);
	Print(C, l);
	printf("\n\n");
	l = Inter(A, n, B, m, C);
	Print(C, l);

	free(C);
	free(B);
	free(A);
	return 0;
}