#include "stdio.h"
#include"stdlib.h"
#include"locale.h"
int unic(int* a, int s, int x) {
	for (int i = 0; i < s; i++) {
		if (a[i] == x) {
			return 0;
		}
	}
	return 1;
}int main() {
	setlocale(LC_ALL, "Rus");
	int* a1, * a2, * ob;
	int s1, s2, obs = 0;
	printf("Введите размер первого массива:");
	scanf_s("%d", &s1);
	a1 = (int*)malloc(s1 * sizeof(int));
	printf("Введите элементы первого массива:\n");
	for (int i = 0; i < s1; i++) {
		scanf_s("%d", &a1[i]);
	}
	printf("Введите размер второго массива:");
	scanf_s("%d", &s2);
	a2 = (int*)malloc(s2 * sizeof(int));
	printf("Введите элементы второго массива:\n");
	for (int i = 0; i < s2; i++)
	{
		scanf_s("%d", &a2[i]);
	}
	ob = (int*)malloc((s1 + 2) * sizeof(int));
	for (int i = 0; i < s1; i++) {
		if (unic(ob, obs, a1[i]))
		{
			ob[obs++] = a1[i];
		}
	}
	for (int i = 0; i < s2; i++) {
		if (unic(ob, obs, a2[i]))
		{
			ob[obs++] = a2[i];
		}
	}
	printf("Массив объединения:\n");
	for (int i = 0; i < obs; i++)
	{
		printf("%d", ob[i]);
	}
	printf("\n");
	free(a1);
	free(a2);
	free(ob);
	return 0;
}