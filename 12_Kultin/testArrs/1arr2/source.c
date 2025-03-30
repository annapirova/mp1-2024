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

	arr12();
	return 0;

}

int arr12(){
	int n1, n2;
	scanf_s("%d", &n1);
	scanf_s("%d", &n2);

	int* res1 = (int*)malloc(sizeof(int) * n1);
	int* res2 = (int*)malloc(sizeof(int) * n2);
	int* res3 = (int*)malloc(sizeof(int) * (n1 + n2));


	for (int i = 0; i < n1; i++)
	{
		int f;
		scanf_s("%d", &f);
		res1[i] = f;
		res3[i] = res1[i];
	}
	for (int i = n1; i < n1 + n2; i++)
	{
		int f;
		scanf_s("%d", &f);
		res2[i - n1] = f;

		res3[i] = res2[i - n1];
	}


	createNotReap(res3, n1 + n2);

}


int createNotReap(int* arr, int n) {
	int m = 0, j;
	int* b = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		j = 0;
		while ((j < m) && b[j] != arr[i])
			j++;
		if (j == m) {
			b[m] = arr[i];
			m++;
		}
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d ", b[i]);
	}
	return 0;
}
