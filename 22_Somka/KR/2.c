#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "locale.h"
#include "time.h"

int main() {
	int** mt;
	int m, n;
	int sum=0;
	int mid;
	int max=0;
	int num=0;
	int k = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите размеры матрицы \n");
	scanf_s("%d %d", &m, &n);
	mt = (int**)malloc(m*sizeof(int*));
	for (int i = 0; i < m; i++) {
		mt[i] = (int*)malloc(n * sizeof(int));
	}
	srand(time(NULL));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			mt[i][j] = rand() % 100;
			sum = sum + mt[i][j];
			printf("%d ", mt[i][j]);
		}
		printf("\n");
	}
	mid = sum / (m * n);
	for (int i = 0; i < n; i++) {
		k = 0;
		for (int j = 0; j < m; j++) {
			if (mt[j][i] > mid) {
				k++;
			}
		}
		if (k > max) {
			max = k;
			num = i+1;
		}

	}
	printf("%d %d %d", mid, num, max);

}