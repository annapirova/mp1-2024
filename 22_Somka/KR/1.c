#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "locale.h"

int main() {
	int s1, s2;
	int* m1;
	int* m2;
	int* c;
	int k = 0;
	int n = 0;
	setlocale(LC_ALL, "Russian");
	printf("Введите колличество элементов массива ");
	scanf_s("%d", &s1);
	m1 = (int*)malloc(s1 * sizeof(int));
	for (int i = 0; i < s1; i++) {
		scanf_s("%d", &m1[i]);
	}
	printf("Введите колличество элементов массива ");
	scanf_s("%d", &s2);
	m2 = (int*)malloc(s2 * sizeof(int));
	for (int i = 0; i < s2; i++) {
		scanf_s("%d", &m2[i]);
	}
	for (int i = 0; i < s1; i++) {
		for (int j=0; j < s2; j++) {
			if (m1[i] == m2[j]) {
				k += 1;
			}
		}
	}
	c = (int*)malloc(k * sizeof(int));
	for (int i = 0; i < s1; i++) {
		for (int j=0; j < s2; j++) {
			if (m1[i] == m2[j]) {
				c[n] = m1[i];
				n++;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		printf("%d ", c[i]);
	}

}