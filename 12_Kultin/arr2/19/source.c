#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//#define RAND_MIN = pow(10, n - 1)
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");

	int n, n2;
	scanf_s("%d", &n);
	scanf_s("%d", &n2);

	int** res = (int**)malloc(sizeof(int*) * n); 
	
	for (int i = 0; i < n; i++)
		res[i] = (int*)malloc(sizeof(int) * n2);


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n2; j++)
		{
			int f;
			scanf_s("%d", &f);

			res[i][j] = f;
		}
	}

	hw22(res, n, n2);
	return 0;

}



int hw22(int **arr, int k1, int k2){
	int maxD, count;
	maxD = count = 0;

	for (int i = 0; i < k1; i++)
	{
		count = 0;
		for (int j = 0; j < k2; j++) {
			if (arr[i][j] == 0) {
				count++;
			}
		}
		maxD = max(maxD, count);
		
	}
	printf("%d ", maxD);
	return 0;
}






