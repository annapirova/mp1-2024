#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include <time.h>



bool sortcheck(int arr[], int n) {
	int f = 1, i;
	for (i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			f = 0;
		}
	}
	return f == 1;
}

int linear_seatch(int arr[], int n, int x) {
	int i, ans = -1;
	int f = 0;
	for (i = 0; i < n; i++) {
		if (arr[i] == x) {
			ans = i;
			f = 1;
			break;
		}
	}
	if (f == 1) {
		return ans;

	}
	else {
		return 10001;
	}
}

int binary_search(int arr[], int n, int x) {
	int l = 0, r = n;
	int f = 0;
	int i, ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (arr[mid] == x) {
			ans = mid;
			f = 1;
			break;
		}
		else if (arr[mid] > x) {
			r = mid - 1;
		}
		else if (arr[mid] < x) {
			l = mid + 1;
		}
	}
	if (f == 1) {
		return ans;
	}
	else {
		return 10001;
	}
}

void print(int a[], int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void countsort(int arr[], int n) {
	clock_t start, finish;
	double time;
	int it = 0;
	int tmp[20001] = { 0 };
	int pos = 0;
	start = clock();

	for (int i = 0; i < n; i++) {
		tmp[arr[i] + 10000] += 1;
		/*if (a[i] < 0) tmp[a[i]]++;
		else tmp[a[i] + 10000]++;*/
		it++;
	}
	for (int i = 0; i < 20001; i++) {
		while (tmp[i] > 0) {
			arr[pos] = i - 10000;
			tmp[i] -= 1;
			pos++;
			it++;
		}
	}
	finish = clock();
	print(arr, n);
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.10f\n", time);
	printf("Iterations: %d\n", it);
}
void bubble_sort(int arr[], int n) {
	clock_t start, finish;
	double time;
	int it = 0;
	int left = 0, right = n - 1, i, temp;
	start = clock();
	while (left <= right) {
		for (i = right; i > left; i--) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}
			it++;
		}
		++left;
		for (i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
			it++;
		}
		--right;

	}
	finish = clock();
	print(arr, n);
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.10f\n", time);
	printf("Iterations: %d\n", it);
}

void insertsort(int arr[], int n) {
	clock_t start, finish; 
	double time;
	int it = 0;
	int k, val;
	start = clock();
	for (int i = 1; i < n; i++) {
		val = arr[i];
		k = i - 1;
		while (k >= 0 && arr[k] > val) {
			arr[k + 1] = arr[k];
			k--;
			
		}
		it++;
		arr[k + 1] = val;
	}
	finish = clock();
	print(arr, n);
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.10f\n", time);
	printf("Iterations: %d\n", it);
}

void selectsort(int arr[], int n) {
	clock_t start, finish;
	double time;
	int it = 0;
	int i, j;
	start = clock();
	for (i = 0; i < n; i++) {
		int min = arr[i];
		int id = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				id = j;
				min = arr[j];
			}
			it++;
		}
		if (id != i) {
			int tmp = arr[i];
			arr[i] = min;
			arr[id] = tmp;
		}
	}
	finish = clock();
	print(arr, n);
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.10f\n", time);
	printf("Iterations: %d\n", it);
}

int partition(int arr[], int l, int r, int* count) {
	int x, i, tmp;
	int less;
	x = arr[r];
	less = l;

	for (i = l; i < r; i++) {
		if (arr[i] <= x) {
			tmp = arr[i];
			arr[i] = arr[less];
			arr[less] = tmp;
			less++;
			*count += 1;
		}

	}
	tmp = arr[less];
	arr[less] = arr[r];
	arr[r] = tmp;
	*count += 3;
	return less;
}


void quick_sort(int arr[], int l, int r, int* count) {
	if (l < r) {
		int q = partition(arr, l, r, count);
		quick_sort(arr, l, q - 1, count);
		quick_sort(arr, q + 1, r, count);
	}
	printf(arr, sizeof(arr));
}



void true_merge_sort(int arr[], int buffer[], int l, int r, int* it) {
	if (l < r) {
		int middle = (l + r) / 2;
		true_merge_sort(arr, buffer, l, middle, it);
		true_merge_sort(arr, buffer, middle + 1, r, it);
		int i, j;
		int k = l;
		for (i = l, j = middle + 1; i <= middle || j <= r; ) {
			if (j > r || (i <= middle && arr[i] < arr[j])) {
				buffer[k] = arr[i];
				++i;

			}
			else {
				buffer[k] = arr[j];
				++j;
			}
			++k;
			*it++;
		}
		for (i = l; i <= r; ++i) {
			arr[i] = buffer[i];
			*it++;
		}
	}


}

void merge_sort(int arr[], int n) {
	int buffer[10000];
	clock_t start, finish;
	double time;
	int it = 0;
	start = clock();
	true_merge_sort(arr, buffer, 0, n - 1, &it);
	finish = clock();
	print(arr, n);
	printf("\n");
	time = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("Time: %.10f\n", time);
	printf("Iterations: %d\n", it);

}

void arrayInp(int arr[], int n, int arrcopy[]) {
	int ran;
	int x;
	int c;
	int ai;
	for (int i = 0; i < n; i++) {
		arr[i] = 0;
	}
	printf("1.Manual input\n2.Random input\nOpsion: ");
	scanf_s("%d", &c);
	if (c == 1) {
		for (int i = 0; i < n; i++) {
			scanf_s("%d", &ai);
			arr[i] = ai;
		}
	}
	else {
		printf("Pick any number: ");
		scanf_s("%d", &x);
		srand(x);
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
	}
	for (int i = 0; i < n; i++) {
		arrcopy[i] = arr[i];
	}
}

void menu()
{
	printf("1. Input array\n");
	printf("2. Print the original array\n");
	printf("3. Bubble sort\n");
	printf("4. Count sort\n");
	printf("5. Insert sort\n");
	printf("6. Selection sort\n");
	printf("7. Merge sort\n");
	printf("8. Quick sort\n");
	printf("9. Linear search\n");
	printf("10. Binary search\n");
	printf("0. Exit\n");
}


int main() {
	int search;
	int x;
	int cs = 3;
	int len;
	int arr[10000];
	int c = 10000000;
	int count = 0;
	int* orarr;
	printf("Input size of array: ");
	scanf_s("%d", &len);
	orarr = (int*)malloc(sizeof(int) * len);
	while (len < 0) {
		printf("Invalid lenght..Size of the array must be greater than 0!!!\nInput size of array: ");
		scanf_s("%d", &len);
	}
	while (c != 0) {
		menu();
		printf("Option: ");
		scanf_s("%d", &c);
		switch (c)
		{
		case 1: {
			cs = 3;
			while (cs != 1) {
				printf("Confirm the length of %d\n1.Yes\n2.No\nOption: ", len);
				scanf_s("%d", &cs);
				if (cs == 2) {
					printf("Size: ");
					scanf_s("%d", &len);
				}
				if (len < 0) {
					printf("Invalid length.Size of the array must be greater than 0!!!\n");
					cs = 2;
					printf("Size: ");
					scanf_s("%d", &len);
				}
				if (cs > 2 || cs < 1) printf("Unknown command.Type again\n");
			}
			arrayInp(orarr, len, arr);
			break;
		}
		case 2: {
			print(orarr, len);
			break;
		}
		case 3: {
			bubble_sort(arr, len);
			break;
		}
		case 4: {
			countsort(arr, len);
			break;
		}
		case 5: {
			insertsort(arr, len);
			break;
		}
		case 6: {
			selectsort(arr, len);
			break;
		}
		case 7: {
			merge_sort(arr, len);
			break;
		}
		case 8: {
			quick_sort(arr, 0, len - 1, &count);
			break;
		}
		case 9: {
			printf("Input X: ");
			scanf_s("%d", &x);
			printf("\n");
			search = linear_seatch(arr, len, x);
			if (search != 10001) printf("Id of x : %d\n", search);
			else printf("No x in array\n");
			break;

		}
		case 10: {
			if (!sortcheck(arr, len)) {
				printf("Array must be sorted to Binary seatch!!!\n");
				break;
			}
			printf("Input X: ");
			scanf_s("%d", &x);
			printf("\n");
			search = binary_search(arr, len, x);
			if (search != 10001) printf("Id of x : %d\n", search);
			else printf("No x in array\n");
			break;

		}
		case 0: {
			printf("Programm is over!");
			break;
		}
		default:
			printf("Unknown command\n");
			break;
		}
	}

}