#include "stdlib.h"
#include "stdio.h"
#include "locale.h"



int main() {
	setlocale(LC_ALL, "Rus");

	int** arr;
	int n, m, h;
	double middle;
	printf("Введите кол-во столбцов m=");
	scanf_s("%d", &m);
	printf("\nВведите кол-во строк n=");
	scanf_s("%d", &n);
	arr = (int **)malloc(sizeof(int*)*n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int *)malloc(m * sizeof(int));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = rand();
		}
	}
	middle = 0.0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			middle += arr[i][j];
		}
	}
	middle = middle / (n * m);
	int max_count = 0;
	int dynamic_count = 0;
	int coord = 0;
	printf("\nСреднее значение middle=%.2lf\n", middle);
	for (int i = 0; i < m; i++) {
		dynamic_count = 0;
		for (int j = 0; j < n;j++) {
			if (arr[j][i] > middle) {
				dynamic_count++;
			}
		}
		if (dynamic_count > max_count) {
			max_count = dynamic_count;
			coord = i+1;
		}
	}
	printf("\nСтолбец %d, чисел %d\n", coord, max_count);
	printf("\nМатрица:\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf(" %9.d ", arr[i][j]);
		}
		printf("\n");
	}
	return 1;
}