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

	arr21(res, n, n2);
	return 0;

}

int arr21(int** arr, int n1, int n2){
	int coordX1 = -1, coordY1 = -1, coordX2 = -1, coordY2 = -1, s = -1;

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++) {
			printf("%d ", arr[i][j]);
			if (arr[i][j] == 0) {
				int g = 1, h = 1;
				
				while (arr[i][j + h] != 1 && j + h < n2)
				{
					h++;
				}
			
				while (arr[i + g][j] != 1 && i + g < n1)
				{
					g++;
				}
				
				
				if (s < g * h) {
					s = g * h;
					coordY1 = j;
					coordX1 = i;
					coordY2 = j + h - 1;
					coordX2 = i + g - 1;

				}

			}
		}
		printf("\n");
	}

	printf("x1 = %d y1 = %d x2 = %d y2 = %d s = %d ", coordX1, coordY1, coordX2, coordY2, s);

	return 0;

}

