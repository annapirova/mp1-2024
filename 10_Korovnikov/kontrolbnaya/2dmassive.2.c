#include "stdio.h"
#include "time.h"
#include "stdlib.h"

void RandMatrica(int** A, int m, int n)
{
	int a, b;
	srand(time(NULL));
	printf("Vvedite granici matrici ot naimens k naibols:\n");
	scanf_s("%d %d", &a, &b);
	for (int i = 0; i < m; i++) 
	{ 
		for (int j = 0; j < n; j++)
		{
			A[i][j] = a + rand() % (b - a);
		}
	}
	printf("\nMATRICA: \n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
}
 double MID(int**A,int m,int n)
 {
	 double k = 0;
	 for (int i = 0; i < m; i++)
	 {
		 for (int j = 0; j < n; j++)
		 {
			 k += A[i][j];
		 }
	 }
	 return k / (m * n);
 }

 int poisk(int** A, int m, int n,double mid)
 {
	 int k = 0, l = 0, maxk = 0; double q;
	 for (int j = 0; j < n; j++)
	 {
		 k = 0;
		 for (int i = 0; i < m; i++)
		 {
			 q = A[i][j];
			 if (q > mid)k++;
		 }
		 if (k > maxk) { maxk = k; l = j; }
	 }
	 printf("Stolbec %d (kol-vo %d)", l, maxk);
 }
int main()
{
	int** A; int m, n, f = 0;double mid;
	printf("Vvedite kol-vo strok:");
	scanf_s("%d", &m);
	printf("Vvedite kol-vo stolbcov:");
	scanf_s("%d", &n);
	if (m > n)  f = m;
	else f = n;
	A = (int**)malloc((f + 2) * sizeof(int*));
	for (int i = 0; i < (f + 2); i++) { A[i] = (int*)malloc((f + 2) * sizeof(int)); }
	RandMatrica(A, m, n);
	mid = MID(A, m, n);
	printf("\nSrednee %.3f \n", mid);
	poisk(A, m, n, mid);





}