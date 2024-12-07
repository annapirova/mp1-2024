#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "time.h"
#include "memory.h"
#include "locale.h"
#pragma warning(disable: 4996)



//Задание №22

void amountplaces(int **A, int m, int n) {

	int indmax = 0, maxl = 0, maxg = 0, countf = 0, l = m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] == 0) {
				countf++;
				if (countf > maxl) {
					maxl = countf;
				}
			}
			else {
				countf = 0;
			}
		}
		countf = 0;
		if (maxl > maxg) {
			maxg = maxl;
			indmax = i;
		}
		maxl = 0;
	}

	printf("Вагон с максимальным количеством идущих подряд свободных мест: %d", indmax+1);
	printf("\nСумма мест: %d", maxg);

}



int main() {

	int m = 0, n = 0;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	printf("Введите количество вагонов и мест в них, соответсвенно:  ");
	scanf("%d %d", &n, &m);

	int** A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * m);
	}

	printf("Рандомная ситуация по посадке вагонов, где 0 - свободное место, 1 - занятое место: \n\n");
	for (int i = 0; i < n; i++) {
		printf("%d вагон:  ", i+1);
		for (int j = 0; j < m; j++) {
			A[i][j] = (double)rand() / RAND_MAX * 2;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	printf("\n\nИтог: \n\n");
	amountplaces(A, m, n);


	for (int i = 0; i < m; i++) {
		free(A[i]);
	}
	free(A);

	return 0;
}








//Задание №23

int main2() 
{
	int m = 0, n = 0, x = 0, minA = 0, min1 = 0, max1 = 0, ind = 0;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	printf("Задайте размерность квадратной матрицы, в которой: n строк х n столбцов: ");
	scanf("%d", &n);
	printf("Обозначьте диапазон генерируемых значений: ");
	scanf("%d %d", &min1, &max1);
	m = n;
	minA = max1 + 1;
	printf("\n\n");

	int** A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * m);
	}

	printf("Получившаяся матрица: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			A[i][j] = min1 + (double)rand() / RAND_MAX * (max1 - min1);
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	//Нахождение мин. элемента по главной диагонали
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if ((i == j) && (A[i][j] < minA)) {
				minA = A[i][j];
				ind = i;
				printf("%d %d ", minA, ind);
			}
		}
	}

	//Зеркальное отображение строки с мин. элементом
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (m / 2); j++) {
			if (i == ind) {
				x = A[i][(m-1) - j];
				A[i][(m-1) - j] = A[i][j];
				A[i][j] = x;
			}
		}
		printf("\n");
	}


	printf("\n\nПолучившаяся зеркальная матрица!\n\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);

	return 0;
}
