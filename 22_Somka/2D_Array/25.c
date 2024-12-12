/// 25 задание
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "locale.h"
#include "time.h"

int main() {
	int** mt;
	int m, n;
	int sum = 0;
	int magic = 1;
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
	for (int i = 0; i < m; i++) {
		sum = sum + mt[i][0];
	}
	for (int i = 0; i < m; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			c = c + mt[i][j];
		}
		if (sum != c) {
			magic = 0;
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		int c = 0;
		for (int j = 0; j < n; j++) {
			c = c + mt[j][i];
		}
		if (sum != c) {
			magic = 0;
			break;
		}
	}
	if (magic == 1) {
		printf("Квадрат магический");
	}
	if (magic == 0) {
		printf("Квадрат не является магическим");
	}
}