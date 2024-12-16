#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include "locale.h"
#include "memory.h"
#pragma warning(disable: 4996)



//Задание на одномерные массивы (№2)

void array_merge(int A[], int B[], int n1, int n2) {

	int l = 0, c = 0, f, N = n1 + n2;
	int* arrm = (int*)malloc(sizeof(int) * 2000);


	for (int i = 0; i < N; i++) {
		arrm[i] = 0;
	}
	for (int i = 0; i < n1; i++) {
		arrm[i] = A[i];
	}
	for (int j = n1; j < N; j++) {
		arrm[j] = B[c];
		c++;
	}


	for (int i = 0; i < N; i++) {
		f = 0;
		for (int j = 0; j < N; j++) {
			if (arrm[i] < arrm[j]) {
				c = arrm[i];
				arrm[i] = arrm[j];
				arrm[j] = c;
				f = 1;
			}
			else {
				f = 1;
			}
		}
		if (f == 0) {
			break;
		}
	}

	for (int i = 0; i < N;) {
		if (arrm[i] == arrm[i + 1]) {
			i++;
		}
		else {
			printf("%d ", arrm[i]);
			i++;
			l++;
		}
	}
	printf("\nИтоговая длина массива без повторений: %d", l);

	free(arrm);
}



int main1() 
{
	int A[1000];
	int B[1000];
	int n1 = 0, n2 = 0, minA = 0, maxA = 0, minB = 0, maxB = 0;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	printf("Введите желаемую длину первого и второго массива соответсвенно: ");
	scanf("%d %d", &n1, &n2);
	printf("Введите диапазон для первого массива: ");
	scanf("%d %d", &minA, &maxA);
	printf("Введите диапазон для второго массива: ");
	scanf("%d %d", &minB, &maxB);


	printf("Массив A:  ");
	for (int i = 0; i < n1; i++) {
		A[i] = minA + (double)rand() / RAND_MAX * (maxA - minA);
		printf("%d ", A[i]);
	}

	printf("\n\nМассив B:  ");
	for (int i = 0; i < n2; i++) {
		B[i] = minB + (double)rand() / RAND_MAX * (maxB - minB);
		printf("%d ", B[i]);
	}


	printf("\n\nGreatful! Ваш готовый массив без повторений: ");
	array_merge(A, B, n1, n2);

	return 0;
}





//Задание на двумерные массивы (№2)

int main2() {

	int m = 0, n = 0, x = 0, c = 0, count = 0;
	int minA = 0, maxA = 0, maxS = 0;
	double mid = 0;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	printf("Задайте размерность массива, где m строк x n столбцов: ");
	scanf("%d %d", &m, &n);
	printf("Введите минимальную и максимальную границу диапазона для заполнения массива: ");
	scanf("%d %d", &minA, &maxA);

	int** A = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		A[i] = (int*)malloc(sizeof(int) * m);
	}

	printf("Сгенерированный массив: \n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			x = minA + (double)rand() / RAND_MAX * (maxA - minA);
			A[i][j] = x;
			c += x;
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}

	mid = c / (m * n);
	printf("\n\nСреднее значение элементов матрицы: %lf \n\n", mid);

	//Транспонирование матрицы
	int** B = (int**)malloc(sizeof(int*) * m); //Вспомогательная matrix
	for (int i = 0; i < m; i++) {
		B[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			B[j][i] = A[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", B[i][j]);
		}
		printf("\n");
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (B[i][j] > mid) {
				count++;
				printf("%d ", count);
			}
		}
		if (count > maxS) {
			maxS = i+1;
		}
		count = 0;
		printf("\n");
	}

	for (int i = 0; i < n; i++) {
		free(B[i]);
	}
	free(B);

	for (int i = 0; i < n; i++) {
		free(A[i]);
	}
	free(A);
	
	printf("\n\nСтрока с превосходящим количеством элементов, больших mid значений матрицы: %d ", maxS);

	return 0;
}