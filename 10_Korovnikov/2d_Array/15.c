#include "stdio.h"
#include "stdlib.h"

void Pere() { printf("\n"); }

void MatricaVvod(int m, int n, int** A) 
{
	printf("\n Vvedite elementi:\n \n");
	int k = 1;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			printf("Nom.%d: ", k);
			scanf_s("%d", &A[i][j]);
			k++;
		}
		
	}
}

void MatricaVivod(int m,int n, int** A)
{
	printf("\n Matrica: \n");
	for (int i=0; i < m; i++)
	{
		for (int j=0; j < n; j++)
		{
		if (A[i][j]>=0)printf("  %d  ", A[i][j]);
		else printf(" %d  ", A[i][j]);
		}
		printf("\n");
	}
}
int Check(int m, int n, int** A)
{
	int i, j, k, w = 0, q = 0,f=0;
	for (i = 0; i < m; i++)
	{
		if (A[i][n - 1] > 0) q++;
		if (q == m) f = 1;
	}
	for (j = 0; j < n; j++)
	{
		k = 0;
		for (i = 0; i < m; i++)
		{
			if (A[i][j] > 0)k++;
		}
		if (k==m)
		{
			for (i = 0; i < m; i++)
			{
				A[i][j] = 1;
			}
			w++;
		}
		printf("\n");
	}
	return n-w ;
}
void FullPeredel(int** A, int** B, int m,int n)
{
	int j = 0;
	for (int x = 0; x < n; x++)
	{
		int k = 0;
		for (int y = 0; y < m; y++) 
		{
			if (A[y][x] != 1)k++;
		}
		if (k > 0)
		{
			for (int i = 0; i < m; i++)
			{
				B[i][j] = A[i][x];
			}
			j++;
		}
		

	}
		
}

int main()
{
	int** A; int m, n, f, p; int** B;
	printf("Vvedite kol-vo strok:");
	scanf_s("%d", &m);
	printf("Vvedite kol-vo stolbcov:");
	scanf_s("%d", &n);
	if (m > n)  f = m;
	else f = n;
	A = (int**)malloc((f+2) * sizeof(int*));
	for (int i = 0; i < (f+2); i++) { A[i] = (int*)malloc((f+2) * sizeof(int)); }
	B = (int**)malloc((f + 2) * sizeof(int*));
	for (int i = 0; i < (f + 2); i++) { B[i] = (int*)malloc((f + 2) * sizeof(int)); }
	MatricaVvod(m,n, A);
	Pere();
	MatricaVivod(m,n, A);
	p=Check(m, n, A);
	FullPeredel(A,B,m,n);
	printf("Posle preobrazovaniya: ");
	MatricaVivod(m, p, B);

}
