#include "stdio.h"
#include "stdlib.h"

// проверка на латинский квадрат


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


void is_latin(int** A, int n){
	int latin = 1;
	int i, j, k;
	int flag;
	int checker;

	for (i=0; i<n; i++){ // проверка строк
		checker = 1;
		for (k=0; k<n; k++)
			for (j=0; j<n; j++)
				if (A[i][j] == checker)
					checker++;

		if (checker != n+1){
			latin = 0;
			break;
		}
	}
	
	if (latin == 1){
		for (j=0; j<n; j++){ // проверка столбцов
			checker = 1;
			for (k=0; k<n; k++)
				for (i=0; i<n; i++)
					if (A[i][j] == checker)
						checker++;
	
			if (checker != n+1){
				latin = 0;
				break;
			}
		}
	}

	if (latin == 1)
		printf("Array is latin square\n");
	else
		printf("Array is not latin square\n");
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

	is_latin(A, n);
}