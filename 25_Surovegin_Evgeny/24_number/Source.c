#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n, m;
	printf("vvedite n\n");
	scanf_s("%d", &n);
	printf("vvedite m\n");
	scanf_s("%d", &m);
	while (m == 1)
	{
		printf("vvedite m\n");
		scanf_s("%d", &m);
	}
	int** a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * m);
	}
	int* b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		b[i] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		printf("vvedite stroky\n");
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		int t = 1;
		int k = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] == a[i][m - t] && j<=m-t)
			{
				k++;
			}
			else
			{
				break;
			}
			t++;
		}
		if (m % 2 == 0)
		{
			if (k == m / 2)
			{
				b[i] = i;
			}
		}
		else
		{
			if (k == m / 2 + 1)
			{
				b[i] = i;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (b[i] != -1)
		{
			printf("%d\n", b[i]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	free(b);
}
