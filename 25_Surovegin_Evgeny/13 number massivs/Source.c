#include<stdio.h>
#include<stdlib.h>;
int main()
{
	int** a;
	int n, m;
	printf("stroki\n");
	scanf_s("%d", &n);
	printf("stolbci\n");
	scanf_s("%d", &m);
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * m);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
	printf("First\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", a[i][j]);
		}
	}
	printf("\n");
	int min = a[0][0], index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] < min)
			{
				min = a[i][j];
				index = i;
			}
		}
	}
	//printf("%d\n", min);
	//printf("%d\n", index);
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i >= index)
			{
				a[i][j] = a[i + 1][j];
			}
		}
	}
	printf("Second\n");
	for (int i = 0; i < n-1; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		free(*a[i]);
	}
	free(*a);
}