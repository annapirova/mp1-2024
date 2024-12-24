#include "stdio.h"
#include "locale.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"
//задача на двумерные массивы
int main() {
	setlocale(LC_ALL, "Russian");
	int strk, stlb, i, j;
	printf("введи кол-во строк и столбцов в двумерном массиве ");
	scanf_s("%d %d", &strk, &stlb);
	int** arr = (int**)malloc(strk * sizeof(int*));
	for (i = 0; i < strk; i++) {
		arr[i] = (int*)malloc(stlb * sizeof(int*));
	}
	srand(time(NULL));
	int s = 0;
	for (i = 0; i < strk; i++) {
		for (j = 0; j < stlb; j++) {
			arr[i][j] = rand() % 100;
			s += arr[i][j];
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	double mid;
	mid = (double)s / (strk * stlb);
	printf("средне значение равно %.2f\n", mid);
	int mx, mx1, k;
	mx = 0;
	mx1 = -1;
	for (j = 0; j < stlb; j++) {
		k = 0;
		for (i = 0; i < strk; i++) {
			if (arr[i][j] > mid) {
				k++;
			}
		}
		if (k > mx) {
			mx = k;
			mx1 = j;
		}
	}
	if (mx1 != -1) {
		printf("%d столбец имеет большее кол-во значений больших среднего", mx1);
	}
	else {
		printf("нет таких зн-ий");
	}

}