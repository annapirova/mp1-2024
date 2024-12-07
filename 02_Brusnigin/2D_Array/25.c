#include "stdio.h"
#include "stdlib.h"

// проверка на магический квадрат


void input_2d_array(int** A, int n){
	int i, j;

	printf("\nEnter elements of 2D Array (%d): \n", n*n);

	for (i=0; i < n; i++)
		for (j=0; j<n; j++){
			scanf("%d", &A[i][j]);
		}
	printf("Done!\n\n");
}


void print_2d_array(int** A, int n){
	int i, j;

	printf("Your 2D Array: \n");

	for (i=0; i<n; i++){
		for (j=0; j<n; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}
	printf("\n");
}


void is_magic(int** A, int n){
	int counter;
	int magic = 1;
	int i, j;

	int N = 0;

	for (j=0; j<n; j++) // сумма
		N += A[0][j];

	for (i=0; i<n; i++){ // проверка строк
		counter = 0;

		for (j=0; j<n; j++)
			counter += A[i][j];

		if (counter != N){
			magic = 0;
			break;
		}
	}
	
	if (magic == 1){
		for (j=0; j<n; j++){ // проверка столбцов
			counter = 0;

			for (i=0; i<n; i++)
				counter += A[i][j];

			if (counter != N){
				magic = 0;
				break;
			}
		}
	}

	if (magic == 1)
		printf("Array is magic square\n");
	else
		printf("Array is not magic square\n");
}


void main() {
	int** A; int n;

	printf("Number of rows/columns: ");
	scanf("%d", &n);

	A = (int**)malloc(n*sizeof(int*));

	int i;
	for(i = 0; i < n; i++)
    		A[i] = (int*)malloc(n*sizeof(int));


	input_2d_array(A, n);

	print_2d_array(A, n);

	is_magic(A, n);
}