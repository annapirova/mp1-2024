#include "stdio.h"
#include "stdlib.h"

// Задание 2 в файле


void input_2d_array(int** A, int m, int n){
	int i, j;

	printf("\nEnter elements of 2D Array (%d): \n", m*n);

	for (i=0; i < m; i++)
		for (j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	printf("Done!\n\n");
}


void print_2d_array(int** A, int m, int n){
	int i, j;

	printf("Your 2D Array: \n");

	for (i=0; i<m; i++){
		for (j=0; j<n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("\n");
}


double find_mid(int** A, int m, int n) {
	int i, j;
	double summ = 0;
	double mid;

	for (i=0; i<m; i++)
		for (j=0; j<n; j++)
			summ += A[i][j];
	
	mid = summ/(m*n);

	return mid;
}


void find_col(int** A, int m, int n, int mid) {
	int i, j;
	
	int counter;
	int max_count = 0;
	int max_col;

	for (j=0; j<n; j++){
		counter = 0;
		for (i=0; i<m; i++)
			if (A[i][j] > mid)
				counter++;

		if (counter > max_count){
			max_count = counter;
			max_col = j;
		}
	}

	printf("Column %d (%d num.)\n", max_col, max_count);
}


void main() {
	int** A; int m; int n;

	printf("Number of rows: ");
	scanf("%d", &m);

	printf("Number of columns: ");
	scanf("%d", &n);

	A = (int**)malloc(m*sizeof(int*));

	int i;

	for (i = 0; i < m; i++)
    		A[i] = (int*)malloc(n*sizeof(int));

	input_2d_array(A, m, n);
	print_2d_array(A, m, n);

	find_col(A, m, n, find_mid(A, m, n));
}