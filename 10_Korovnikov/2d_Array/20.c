#include "stdlib.h"
#include "stdio.h"

void Vvod(int** A, int m,int n)

{
	for (int i = 0; i < m; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			switch (i)
			{
			case 0: printf("Sotr.%d (hours) - ", j + 1); scanf_s("%d", &A[i][j]); break;
			case 1: printf("Sotr.%d (zp) - ", j + 1); scanf_s("%d", &A[i][j]); break;
			}
		}
	}
}

void Vivod(int** A, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		switch (i)
		{
		case 0: printf("\nKol-vo otrabotannix chasov \n"); printf("--------------------\n"); break;
		case 1: printf("\n \n Money for person/ hour \n"); printf("--------------------\n"); break;
		}
		for (int j = 0; j < n; j++)
		{
			printf("   %d   ", A[i][j]);
		}
	}
}
 void Zarplata(int **A,int B[],int m,int n)
 {
	 printf("\n\n Zarplata for Month \n ---------------\n");
	 for (int j = 0;j<n;j++)
	 {
		 int k = 1;
		 for (int i = 0; i < m; i++)
		 {
			 k = k * A[i][j];
		 }
		 B[j] = k;
	 }
	 int z = 0;
	 for (int i=0;i<n;i++)
	 {
		 printf("  %d  ", B[i]);
		 z += B[i];
	 }
	 printf("\n\n Vsego nyjno money(fond)  - %d\n\n", z);
 }

int main()
{
	int** A; int n; int B[100] = { 0 };
	printf("Vvedite kol-vo rabochix: ");
	scanf_s("%d", &n);
	A = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) { A[i] = (int*)malloc(n * sizeof(int)); }
	Vvod(A, 2, n);
	Vivod(A, 2, n);
	Zarplata(A, B, 2, n);
}