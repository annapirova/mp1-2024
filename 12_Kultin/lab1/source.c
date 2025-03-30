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
	clock_t start, end;
	double time;
	int res[1000], res1[1000], n, k, l, r,menu1, menu2, count;
	menu1 = menuIn();
	while (menu1 != -2) {
		if (menu1 == 1)
			n = menuIn1(res1);
		else
			n = menuIn2(res1);

		menu2 = menuSort();
		while (menu2 != -2 && menu2 != -1)
		{
			count = 0;
			for (int i = 0; i < n; i++)
			{
				res[i] = res1[i];
			}
			if (menu2 == 1) {
				sortBuble(res, n);
			}
			else if (menu2 == 2) {
				start = clock();

				sortIns(res, n, &count);

				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				printf("Сортировка вставками выполонена успешно. Количество действий: %d\nВремя, потраченное на сортировку: %f\n", count, time);
			}
			else if (menu2 == 3) {
				
				start = clock();
				sortByAlam(res, 0, n - 1, &count);
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				printf("Сортировка слиянием завершена успешна. Количество действий: %d\n Время, потраченное на сортировку: %Lf\n", count, time);
			}
			else if (menu2 == 4) {
				start = clock();
				l = 0;
				r = n - 1;

				
				sortQuick(res, l, r, &count);

				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;

				printf("Сортировка Хоара выполонена успешно. Количество действий: %d\nВремя, потраченное на сортировку: %f\n", count, time);

			}
			else if (menu2 == 5) {
				start = clock();
				
				sortCount(res, n, &count);
				
				end = clock();
				time = ((double)(end - start)) / CLOCKS_PER_SEC;
				for (int i = 0; i < n; i++)
				{
					printf("%d ", res[i]);
				}
				printf("\n");
				printf("Сортировка подсчетом выполонена успешно. Количество действий: %d\nВремя, потраченное на сортировку: %f\n", count, time);

			}
			if (linCheck(res, n) == 1)
				printf("Сортировка не выполнена");
			else
				printf("Сортировка выполнена");

			printf("\n");
			menu2 = menuSort();
		}

		if (menu2 == -2)
			return 0;
		else if (menu2 == -1) 
			menu1 = menuIn();
		
	}
	
	
	return 0;

}

int linCheck(int arr[], int n) {
	for (int i = 0; i < n - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return 1;

	}
	return 0;
}
int linSearch(int arr[], int val, int n, int **count) {

	int i, k;
	i = 0;
	k = -1;
	while ((i < n) && k == -1)
	{
		(*count)+=1;
		if (arr[i] == val) k = i;
		else i++;
	}
	
	return k;

}

void createNotRepeat(int arr[], int n) {
	int i, j, k, c;
	i = 0;
	j = 0;

	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j]) 
			{
				for (k = i; k <= (n - 1); ++k)
					arr[k] = arr[k + 1];
				n -= 1; 
			}
			else ++j;
		}
		i++;
	}

}

int binSearch(int arr[], int val, int n) {
	int l, r, m, f;
	l = 0;
	r = n - 1;
	f = -1;
	while ((l < r) && f == -1)
	{
		m = round((l + r) / 2);
		if (val > arr[m]) l = m + 1;
		else if (val < arr[m]) r = m - 1;
		else f = 0;

	}
	f = (arr[l] == val || arr[r] == val) ? 0 : -1;
	return f;
}

int checkSort(int arr[], int n) {
	if (arr[0] > arr[n - 1])
		return 1;
	else 
		return 0;

}

int menuSort() {
	int cho;
	printf("Выберите метод сортировки:\n");
	printf("1. Сортировка пузырьком(двустороняя)\n");
	printf("2. Сортировка вставками\n");
	printf("3. Сортировка слияние\n");
	printf("4. Сортировка Хоара(быстрая)\n");
	printf("5. Сортировка подсчетом\n");
	printf("-1. Создать новый массив\n");
	printf("-2. Выйти из программы\n");
	
	scanf_s("%d", &cho);
	while (cho > 5 || cho < 1 && cho != -1 && cho != -2) {
		printf("1. Сортировка пузырьком(двустороняя)\n");
		printf("2. Сортировка вставками\n");
		printf("3. Сортировка слияние\n");
		printf("4. Сортировка Хоара(быстрая)\n");
		printf("5. Сортировка подсчетом\n");
		printf("-1. Создать новый массив\n");
		printf("-2. Выйти из программы\n");

		scanf_s("%d", &cho);
	}

	return cho;
}

int menuIn() {
	int cho;

	printf("Выберите способ ввода массива:\n");
	printf("1. Вручную\n");
	printf("2. Случайные числа в определенном диапозоне\n");
	printf("-2. Выйти из программы\n");
	
	scanf_s("%d", &cho);
	while (cho != 1 && cho != 2 && cho != -2)
	{
		printf("Выберите способ ввода массива:\n");
		printf("1. Вручную\n");
		printf("2. Случайные числа в определенном диапозоне\n");
		printf("-2. Выйти из программы\n");

		scanf_s("%d", &cho);
	}


	return cho;
}

int menuIn1(int arr[]) {
	int val; int n;
	n = 0;
	val = 0;
	printf("Введите числа массива, последним числом указав -1 или выйдите из программы, введя -2 или выйдите из заполнения, введя -3:\n");
	for (int i = 0; val != -1 && n < 1001; i++) {
		scanf_s("%d", &val);
		if (val == -3)
			return menuIn();
		else if (val == -2)
			return 0;
		while (val == -1 && n == 0) {
			printf("Нельзя оставлять массив пустым\n");
			scanf_s("%d", &val);
		}
		if (val != -1)
		{
			arr[i] = val;
			n++;
		}
	}
	
	return n;
}

int menuIn2(int arr[]) {
	int n, k, r;

	printf("Введите диапозон возможных чисел, где первое число меньше или равно второго:\n");
	scanf_s("%d %d", &n, &k);
	while (n > k)
	{
		printf("Первое число должно быть меньше второго\n");
		scanf_s("%d %d", &n, &k);
	}
	printf("Введите количество чисел в массиве:\n");
	scanf_s("%d", &r);
	while (r < 1 && r <= 1000) {
		printf("Длинна массива должна варироваться от 1 од 1000\n");
		scanf_s("%d", &r);
	}
	for (int i = 0; i <= r; i++)
	{
		arr[i] = n + rand() % (k - n);
	}
	
	return r;
}

int sortBuble(int arr[], int k) {
	clock_t start, end;
	double time;
	start = clock();
	int f = 1, l, r, p, count;
	
	f = l = count = 0;
	r = k;
	for (int i = 0; (i < k) && (f); i++)
	{
		f = 0;
		if (i % 2 == 1) {
			for (int j = l; j < r - 1; j++)
			{
				count++;
				if (arr[j] > arr[j + 1]) {
					p = arr[j];
					arr[j] = arr[j + 1];					
					arr[j + 1] = p;
					f = 1;
					count += 4;
				}
			}
			count++;
			r--;
		}
		else {
			count += 2;
			f = 0;
			for (int j = r - 1; j > l; j--) {
				count++;
				if (arr[j] < arr[j - 1]) {
					p = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = p;
					f = 1;
					count += 4;
				}
			}
			l++;
			for (int j = 0; j < k; j++)
			{
				printf("%d ", arr[j]);
			}
			printf("\n");

		}
	}
	end = clock();
	time = ((double)(end - start)) / CLOCKS_PER_SEC;
	printf("Сортировка пузырьком выполонена успешно. Количество действий: %d\nВремя, протраченное на сортировку: %f\n", count, time);
	return k;
	
	
}

int sortIns(int arr[], int n, int *count) {
	int val, k;
	
	for (int i = 0; i < n - 1; i++)
	{
		val = arr[i + 1];
		k = i;
		
		while (k >= 0 && arr[k] > val)
		{
			arr[k + 1] = arr[k];
			k--;
			++(*count);
		}
		arr[k + 1] = val;
		(*count)+=3;
	}
}

int alam(int arr[], int l, int m, int r, int *count) {
	int i, j, k, n1, n2;
	int larr[1000], rarr[1000];

	n1 = m - l + 1;
	n2 = r - m;
	(*count) += 2;

	for (int i = 0; i < n1; i++) {
		larr[i] = arr[l + i];
		++(*count);
	}
	for (int i = 0; i < n2; i++) {
		rarr[i] = arr[m + i + 1];
		++(*count);
	}
	
	i = j = 0;
	k = l;
	(*count) += 2;
	while (i < n1 && j < n2)
	{
		if (larr[i] <= rarr[j]) {
			arr[k] = larr[i];
			i++;
			
		}
		else {
			arr[k] = rarr[j];
			j++;
		}
		k++;
		(*count) += 4;
	}
	while (i < n1) {
		arr[k] = larr[i];
		i++;
		k++;
		(*count) += 3;
	}

	while (j < n2){
		arr[k] = rarr[j];
		j++;
		k++;
		(*count) += 3;
	}
	

	return 0;
}

int sortByAlam(int arr[], int l, int r, int *count) {
	if (l < r) {
		int m;
		m = l + (r - l) / 2;
		//(*count) += 2;

		sortByAlam(arr, l, m, count);
		sortByAlam(arr, m + 1, r, count);
		alam(arr, l, m, r, count);
	}
	return 0;
}

int sortQuick(int arr[], int l, int r, int *count) {
	int m, v, ch, i, j;
	i = l;
	j = r;
	m = (l + r) / 2;
	
	v = arr[m];
	++(*count);

	
	while (i <= j) {
		++(*count);
		while (arr[i] < v) { 
			i++; 
			++(*count);
		};
		while (arr[j] > v) {
			j--;
			++(*count);
		}
		if (i <= j) {
			if (arr[i] > arr[j]){
				ch = arr[i];
				arr[i] = arr[j];
				arr[j] = ch;
				(*count) += 3;
			}
			i++;
			j--;
			(*count) += 4;
		}
	}
	if (i < r)
		sortQuick(arr, i, r, count);
	if (l < j) 
		sortQuick(arr, l, j, count);
	
	
}

int sortCount(int arr[], int n, int* count) {
	int nCp, nCm, c, nP, nM;
	nCp = nCm = c = 0;

	for (int i = 0; i < n; i++) {
		nCp = (arr[i] > nCp && arr[i] >= 0) ? arr[i] : nCp;
		nCm = (arr[i] < nCm && arr[i] < 0) ? arr[i] : nCm;
	}
	nCm = abs(nCm);

	int *arrCp = (int*)malloc(sizeof(int) * nCp);
	int *arrCm = (int*)malloc(sizeof(int) * nCm);

	int *arr2p = (int*)malloc(sizeof(int) * nCp);
	int *arr2m = (int*)malloc(sizeof(int) * nCm);

	for (int i = 0; i <= nCp; i++)
		arrCp[i] = 0;
	for (int i = 0; i <= nCm; i++)
		arrCm[i] = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= 0)
			arrCp[arr[i]] += 1;
		else
			arrCm[abs(arr[i])] += 1;
	}
	

	(*count) += 2 * n + nCp + nCm;

	
	for (int i = nCm; i >= 0; i--)
	{
		for (int j = 0; j < arrCm[i]; j++)
		{
			arr[c] = -i;
			c++;
		}
	}

	for (int i = 0; i <= nCp; i++)
	{
		for (int j = 0; j < arrCp[i]; j++)
		{
			arr[c] = i;
			c++;
		}
	}

	
	printf("\n");
	return 0;


	

}














