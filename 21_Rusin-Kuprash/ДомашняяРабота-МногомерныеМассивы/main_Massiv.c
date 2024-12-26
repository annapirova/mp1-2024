﻿#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


void printLine(float* line, int n) {
	for (int j = 0; j < n; j++) {
		printf("%.2f ", line[j]);
	}
	printf("\n");
}


void printOrig(float* array, int n, int m) {
	printf("����\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%.2f ", array[m * i + j]);
		}
		printf("\n");
	}
}


void printArray(float** array, int n, int m) {	
	//printf("\n������\n");
	for (int i = 0; i < n; i++) {
		printf("%d - ", i);
		printLine(array[i], m);
		//printf("\n");
	}
}


int checkLine(int lineId, int maxLineId[5], int minLineId[5]) {
	int mins = 0;
	int maxs = 0;
	for (int i = 0; i < 5; i++) {
		if (lineId == minLineId[i]) {
			mins++;
		}
		if (lineId == maxLineId[i]) {
			maxs++;
		}
	}

	if (maxs > 2){
		return 1;
	}
	if (mins > 2) {
		return 2;
	}
	return 0;
}



int prog1() {
	int n;
	unsigned int seed;
	float** insects;
	float* insectsMem;

	float maxLine[5] = {-1, -1, -1, -1, -1};
	int maxLineId[5];
	float minLine[5] = { 256, 256, 256, 256, 256 };
	int minLineId[5];
	float averLine[5] = {0, 0, 0, 0, 0};

	float val;

	float addfl1 = 0;
	float addfl2 = 0;
	int addNum1 = 0;
	int addNum2 = 0;
	int addNum3 = 0;

	printf("Задача по многомерным массивам 21:\n");
	printf("��������� ���������:\n");
	scanf_s("%u", &seed);
	srand(seed);
	printf("������� ���������:\n");
	scanf_s("%d", &n);
	
	insectsMem = (float*)malloc(sizeof(float) * 5 * n);
	insects = (float**)malloc(sizeof(float*) * n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			val = (float)(rand()) / (float)RAND_MAX * 255;
			insectsMem[i * 5 + j] = val;
			averLine[j] += val;
			if (maxLine[j] < val) {
				maxLine[j] = val;
				maxLineId[j] = i;
			}
			if (minLine[j] > val) {
				minLine[j] = val;
				minLineId[j] = i;
			}
		}
		insects[i] = &insectsMem[i * 5];
	}

	for (int j = 0; j < 5; j++) {
		averLine[j] /= n;
	}

	printArray(insects, n, 5);

	
	printf("\n ���������� ���-� � �� ���������:\n");
	for (int i = 0; i < 5; i++) {
		printf("%f %d |", maxLine[i], maxLineId[i]);
	}
	printf("\n ���������� ���-� � �� ���������:\n");
	for (int i = 0; i < 5; i++) {
		printf("%f %d |", minLine[i], minLineId[i]);
	}
	printf("\n");
	
	printf("���������� ������:\n");
	for (int i = 0; i < n; i++) {
		addNum3 = checkLine(i, maxLineId, minLineId);
		if (addNum3 == 1) {
			printf("����� ������!! (������� ����� ���� ������������� � ������������� ����������) - \n");
			addNum1 = 1;
			printf("%d - ", i);
			printLine(insects[i], 5);
		}
		if (addNum3 == 2) {
			printf("����� ������!! (������� ����� ���� ������������� � ������������ ����������) - \n");
			addNum2 = 1;
			printf("%d - ", i);
			printLine(insects[i], 5);
		}
	}
	if (!addNum1) {
		printf("���� ������!!\n");
	}
	if (!addNum2) {
		printf("���� ������!!\n");
	}
	printf("\n������� ��-�� �������������: ");
	printLine(averLine, 5);
	printf("�������������� ������:\n");
	
	addNum3 = 0;

	for (int j = 0; j < 5; j++) addfl1 += fabs(insects[0][j] - averLine[j]);

	for (int i = 1; i < n; i++) {
		addfl2 = 0;
		for (int j = 0; j < 5; j++) addfl2 += fabs(insects[0][j] - averLine[j]);
		if (addfl2 < addfl1) {
			addfl1 = addfl2;
			addNum3 = i;
		};
	}
	printf("%d - %f - ", addNum3, addfl1);
	printLine(insects[addNum3], 5);
	
	return 1;
}


float* arrMemAllocRow(float*** arr, int m, int n, int k) {
	float* newArrMem;
	float** newArr;
	int i = 0;
	newArrMem = (float*)malloc(sizeof(float) * m * (n + 1));
	if (newArrMem != NULL) {
		while (i < k + 1) {
			for (int j = 0; j < m; j++) newArrMem[i * m + j] = (*arr)[i][j];
			i++;
		}
		for (int j = 0; j < m; j++) newArrMem[i * m + j] = 0;
		while (i < n) {
			for (int j = 0; j < m; j++) newArrMem[(i + 1) * m + j] = arr[0][i][j];
			i++;
		}
		newArr = (float**)realloc(*arr, sizeof(float*) * (n + 1));
		for (int i = 0; i < (n + 1); i++) newArr[i] = &newArrMem[i * m];
		*arr = newArr;
	}
	return newArrMem;
}


float* arrMemAllocCol(float*** arr, int m, int n, int k) {
	float* newArrMem;
	float** newArr;
	int j;
	m++;
	newArrMem = (float*)malloc(sizeof(float) * m * n);

	if (newArrMem != NULL) {
		for (int i = 0; i < n; i++) {
			j = 0;
			while (j < k + 1) {
				newArrMem[i * m + j] = (*arr)[i][j];
				j++;
			}
			newArrMem[i * m + j] = 0;
			while (j < m) {
				newArrMem[i * m + j + 1] = (*arr)[i][j];
				j++;
			}
		}
		for (int i = 0; i < n; i++) (*arr)[i] = &newArrMem[i * m];
	}
	return newArrMem;
}



int prog2() {
	unsigned int seed;
	int m, n;
	int k;
	float* memCh;
	float* arrMem;
	float** arr;

	printf("Задача по многомерным массивам 16:\n");
	printf("Случайный генератор:\n");
	scanf_s("%u", &seed);
	srand(seed);
	printf("Размер матрицы: (m n)\n");
	scanf_s("%d %d", &m, &n);

	arrMem = (float*)malloc(sizeof(float) * m * n);
	arr = (float**)malloc(sizeof(float*) * n);
	if (arrMem && arr) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arrMem[i * m + j] = floorf((float)(rand()) / (float)RAND_MAX * 255);
			}
			arr[i] = &arrMem[i * m];
		}
		printf("ваш массив:\n");
		printArray(arr, n, m);
		//printOrig(arrMem, n, m);

		//printf("%f\n", arr[0][2]);
		//printf("%f\n", arr[1][3]);


		printf("Введите куда вставить новую строку: (-1 <= k <= %d)\n", n - 1);
		scanf_s("%d", &k);
		if (k < -1)	k = -1;
		else if (k > n - 1) k = n - 1;

		
		memCh = arrMemAllocRow(&arr, m, n, k);
		free(arrMem);
		arrMem = memCh;
		n++;

		//printOrig(arrMem, n, m);
		printArray(arr, n, m);

		printf("Введите куда вставить новый столбец: (-1 <= k <= %d)\n", m - 1);
		scanf_s("%d", &k);
		if (k < -1)	k = -1;
		else if (k > m - 1) k = m - 1;
		memCh = arrMemAllocCol(&arr, m, n, k);

		free(arrMem);
		arrMem = memCh;
		m++;
		printArray(arr, n, m);
	}
	
	return 1;
}


int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	int ans;
	printf("�������� ������ (1/2): ");
	scanf_s("%d", &ans);
	printf("\n");
	if (ans < 2) return prog1();
	return prog2();
}