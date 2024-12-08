#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>


bool validcheck(int arr[], int n) {
	int f = 1, i;
	for (i = 1; i < n; i++) {
		if (arr[i - 1] > arr[i]) {
			f = 0;
		}
	}
	return f == 1;
}

void linear_seatch(int arr[], int n, int x) {
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
		printf("Id of x: %d \n", ans);

	}
	else {
		printf("No X in array\n");
	}
}

void binary_search(int arr[], int n, int x) {
	int l = 0, r = n;
	int f = 0;
	int mid = (l + r) / 2;
	int i, ans = -1;
	while (l <= r) {
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
		printf("Id of X: %d\n", ans);
	}
	else {
		printf("No X in array\n");
	}

}

void print(int a[],int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}

void countsort(int a[], int n) {
	int tmp[20001] = { 0 };
	int pos = 0;
	for (int i = 0; i < n; i++) {
		tmp[a[i] + 10000] += 1;
		/*if (a[i] < 0) tmp[a[i]]++;
		else tmp[a[i] + 10000]++;*/
	}
	for (int i = 0; i < 20001; i++) {
		while (tmp[i] > 0) {
			a[pos] = i - 10000;
			tmp[i] -= 1;
			pos++;
		}
	}
	// del
	//print(tmp, 10020);
}
void bubble_sort(int arr[], int n) {
	int left = 0, right = n - 1, i, temp;
	while (left <= right) {
		for (i = right; i > left; i--) {
			if (arr[i - 1] > arr[i]) {
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
			}
		}
		++left;
		for (i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
			}
		}
		--right;

	}
}

void insertsort(int a[], int n) {
	int k, val;
	for (int i = 1; i < n; i++) {
		val = a[i];
		k = i-1;
		while (k >= 0 && a[k] > val) {
			a[k + 1] = a[k];
			k--;
		}
		a[k+1] = val;
	}
}

void selectsort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		int min = arr[i];
		int id = i;
		for (j = i + 1; j < n; j++) {
			if (arr[j] < min) {
				id = j;
				min = arr[j];
			}
		}
		if (id != i) {
			int tmp = arr[i];
			arr[i] = min;
			arr[id] = tmp;
		}
	}
}



void true_merget_sort(int arr[], int buf[], int l, int r) {
	if (l < r) {
		int mid = (l + r) / 2;
		true_merget_sort(arr, buf, l, mid);
		true_merget_sort(arr, buf, mid + 1, r);
		int i, j;
		int k = l;
		for (i = l, j = mid + 1; i <= mid && j <= r; ) {
			if (j > r || (i <= mid && arr[i] < arr[j])) {
				buf[k] = arr[i];
				++i;
			}
			else {
				buf[k] = arr[j];
				++j;
			}
			++k;
		}
		for (i = l; i <= r; ++i) {
			arr[i] = buf[i];
		}
	}

}

void merger_sort(int arr[], int n) {
	int buf[10000];
	true_merget_sort(arr, buf, 0, n - 1);
}

void arrayInp(int arr[], int n) {
	int ran;
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
		printf("Randomize range: ");
		scanf_s("%d", &ran);
		srand(ran);
		for (int i = 0; i < n; i++) {
			arr[i] = rand();
		}
	}
}

void menu()
{
	printf("1. Input array\n");
	printf("2. Print array\n");
	printf("3. Bubble sort\n");
	printf("4. Count sort\n");
	printf("5. Insert sort\n");
	printf("6. Selection sort\n");
	printf("7. Merge sort\n");
	printf("8. Linear search\n");
	printf("9. Binary search\n");
	printf("0. Exit\n");
}


int main() {
	int x;
	int cs = 3;
	int len;
	int arr[10000];
	int c = 10000000;
	printf("Input size of array: ");
	scanf_s("%d", &len);
	while (len < 0) {
		printf("Invalid lenght..Size of the array must be greater than 0!!!\nInput size of array: ");
		scanf_s("%d", &len);
	}
	while (c != 0) {
		menu();
		printf("Option: ");
		scanf_s("%d", &c);
		switch(c)
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
			arrayInp(arr, len);
			break;
		}
		case 2: {
			print(arr, len);
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
			merger_sort(arr, len);
			break;
		}
		case 8: {
			printf("Input X: ");
			scanf_s("%d", &x);
			printf("\n");
			linear_seatch(arr, len, x);
			break;

		}
		case 9: {
			if (!validcheck) {
				printf("Array must be sorted to Binary seatch!!!\n");
				break;
			}
			printf("Input X: ");
			scanf_s("%d", &x);
			printf("\n");
			binary_search(arr, len, x);
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