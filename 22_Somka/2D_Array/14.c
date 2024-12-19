/// 14 задание массивы
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "locale.h"
#include "time.h"

int main() {
	int** mt;
	int** mt1;
	int m, n;
	int min=1000000;
	int num = 0;
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
			mt[i][j] = rand() % 101-50;
			printf("%d ", mt[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = 0; i < n; i++) {
		int cmin = 100000;
		for (int j = 0; j < m; j++) {
			if (mt[j][i] < cmin) {
				cmin = mt[j][i];
			}
		}
		if (cmin < min) {
			min = cmin;
			num = i;
		}
	}
	mt1 = (int**)malloc(m * sizeof(int*));
	for (int i = 0; i < m; i++) {
		mt1[i] = (int*)malloc((n-1) * sizeof(int));
	}
	for (int i = 0; i < m; i++) {
		int k = 0;
		for (int j = 0; j < n; j++) {
			if (j != num) {
				mt1[i][k] = mt[i][j];
				k++;
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < (n-1); j++) {
			printf("%d ",mt1[i][j]);
		}
		printf("\n");
	}


}