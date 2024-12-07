#include "stdio.h"

// Задание 2 в файле


void input_array(int Array[], int len) {
	int i;

	for (i = 0; i < len; i++) {
		printf("Element (%d/%d): ", i+1, len);
		scanf_s("%d", &Array[i]);
	}
}


void print_array(int Array[], int len) {
	int i;

	for (i = 0; i < len; i++) {
		printf("%d ", Array[i]);
	}

	printf("\n");
}


int elem_in_array(int Array[], int len1, int el) {
	int i;

	for (i = 0; i < len1; i++) {
		if (Array[i] == el)
			return 1;
	}

	return 0;
}


int intersection(int Array1[], int len1, int Array2[], int len2, int Intersection[]) {
	int i, j;
	int k = 0;
	int len3;

	for (i = 0; i < len1; i++) {
		if (!elem_in_array(Intersection, k, Array1[i]))
			for (j = 0; j < len2; j++) {
				if (Array1[i] == Array2[j]) {
					Intersection[k] = Array1[i];
					k++;
					break;
				}
			}
	}
	len3 = k;
	return len3;
}


void main() {
	int A[200]; int B[200]; int C[200];
	int n1, n2, n3;

	printf("Enter length of first array: ");
	scanf_s("%d", &n1);
	printf("Enter first array:\n");
	input_array(A, n1);
	printf("\n");

	printf("Enter length of second array: ");
	scanf_s("%d", &n2);
	printf("Enter second array:\n");
	input_array(B, n2);
	printf("\n");

	n3 = intersection(A, n1, B, n2, C);

	printf("Intersection:\n");
	print_array(C, n3);
}
