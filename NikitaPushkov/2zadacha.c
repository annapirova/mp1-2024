#include "stdio.h"
#include "stdlib.h"


int main()
{
	int n, m, ** arr;
	printf("Enter size array:\n");
	printf("Enter stolb m:");
	scanf_s("%d", &m);
	printf("Enter str n:");
	scanf_s("%d", &n);
	arr = (int**)malloc(m * sizeof(int*));
	if (arr) {
		for (int i = 0; i < n; i++) {
			arr[i] = (int*)malloc(m * sizeof(int));
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = 1 + rand() % 100;
			printf("%5d", arr[i][j]);
		}
		printf("\n");
	}
	int raz = n * m;
	double sum=0,mid;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += arr[i][j];
		}
	}
	mid = sum / raz;

	int cnt = 0, maxcnt=0, stolb = 0, ch=0;
	for (int j = 0; j < m; j++) {
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i][j] > mid) {
				cnt++;
				if (maxcnt <= cnt) {
					maxcnt = cnt;
					stolb = j;
					ch = maxcnt;
				}
			}
		}
	}

	printf("Sred znach = %lf\n", mid);
	printf("Stolb = %d\n", stolb);
	printf("chisel = %d", ch);
	return 0;
}