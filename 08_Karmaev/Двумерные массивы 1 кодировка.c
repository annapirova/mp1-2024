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
	arr = (int **)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(m * sizeof(int));
	}
	int k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf_s("%d", &k);
			arr[i][j] = k;
		}
		printf("\n");
	}
	int total = 0, stroka = 0, stolbec = 0;
	int type = 0, it = 0;
	int i = 0, j = 0, l = 100;
	int* arn= ((int*)malloc(l * sizeof(int)));
	int* x = ((int*)malloc(l * sizeof(int)));
	int* y = ((int*)malloc(l * sizeof(int)));
	int maximus = -1110;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if (arr[i][j] == 0) {
				int k2 = j;
				int k1 = i;
				stroka++;
				if (k2 + 1 < m) {
					k2++;
				}
				while (arr[i][k2] == 0 && k2<m) {
					stroka++;
					if (k2 + 1 < m) {
						k2++;
					}
					else {
						break;
					}
				}
				if (k1 + 1 < n) {
					k1++;
				}
				stolbec++;
				while (arr[k1][j] == 0 && k1<n) {
					stolbec++;
					if (k1 + 1 < n) {
						k1++;
					}
					else {
						break;
					}
				}
				int sizek = stroka * stolbec;
				arn[it] = sizek;
				x[it] = j+stroka;
				y[it] = i+stolbec;
				stroka = 0; stolbec = 0;
				it++;
			}	
		}
	}
	int maxi = -100, max_x = -1, max_y=-1;

	for (int i = 0; i < 100; i++) {
		if (arn[i] > maxi) {
			maxi = arn[i];
			max_x = x[i];
			max_y = y[i];
		}
	}
	printf("Правый нижний угол (%d,%d)  S=%d",max_x,max_y,maxi);



}


