//1 Задача на массивы средняя сложность номер 19
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

void count_marks(int a[][3], int n)
{
	int i, j, ocenka;
	int ekz1[6] = { 0, 0, 0, 0, 0, 0 };
	int ekz2[6] = { 0, 0, 0, 0, 0, 0 };
	int ekz3[6] = { 0, 0, 0, 0, 0, 0 };
	int neyvka = 0, neyd = 0, ydovl = 0, hor = 0, otl = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			ocenka = a[i][j];
			switch (ocenka)
			{
			case 1:
				neyvka++;
				break;
			case 2:
				neyd++;
				break;
			case 3:
				ydovl++;
				break;
			case 4:
				hor++;
				break;
			case 5:
				otl++;
				break;
			default:
				printf("Incorrect ocenka\n");
				printf("Will be replaces as 1\n");
				ocenka = 1;
				break;
			}
			if ((ocenka > 5) || (ocenka <= 0))
			{
				printf("Incorrect ocenka\n");
				printf("Will be replaces as 1\n");
				ocenka = 1;
			}
			if (j == 0)
				ekz1[ocenka]++;
			if (j == 1)
				ekz2[ocenka]++;
			if (j == 1)
				ekz3[ocenka]++;
		}
	}
	printf("neyvka = %d\n", neyvka);
	printf("neyd = %d\n", neyd);
	printf("ydovl = %d\n", ydovl);
	printf("hor = %d\n", hor);
	printf("otl = %d\n", otl);
	printf("----------------\n");
	printf("Ekzamen 1 total: \n");
	for (i = 0; i < 5; i++)
	{
		printf("Ocenok %d za 1 ekz:%d ",i, ekz1[i]);
	}
	printf("\n----------------\n");
	printf("Ekzamen 2 total: \n");
	for (i = 0; i < 5; i++)
	{
		printf("Ocenok %d za 2 ekz:%d ",i, ekz1[i]);
	}
	printf("\n----------------\n");
	printf("Ekzamen 3 total: \n");
	for (i = 0; i < 5; i++)
	{
		printf("Ocenok %d za 3 ekz:%d ",i, ekz1[i]);
	}
}

void check_matrix(int a[][3], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("student %d: ", i + 1);
		for (j = 0; j < 3; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void ocenka_input(int marks[][3], int n)
{
	int ocenka;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("Enter students ocenka: \n");
			scanf_s("%d", &ocenka);
			marks[i][j] = ocenka;
		}
		printf("------------------\n");
	}
}

int main()
{
	int n;
	int ocenka;
	int i, j;
	printf("Max students count is 1000\n");
	printf("Enter students count: \n");
		scanf_s("%d", &n);
	int** marks = (int**)malloc(n*sizeof(int));
	for (i = 0; i < n; i++)
	{
		marks[i] = (int*)malloc(3 * sizeof(int));
	}
	ocenka_input(marks, n);
	check_matrix(marks, n);
	printf("------------------\n");
	count_marks(marks, n);
	return 0;
}
