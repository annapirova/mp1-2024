#include <stdio.h>
#include <stdlib.h>

int main() {
	int A[11] = { 1, 6, 6, 3, 7, 9, 5, 10, 11, 111, 1111};
	int B[8] = { 3, 5, 6, 6, 7, 9, 11};
	int a_size = sizeof(A) / sizeof(A[0]);
	int b_size = sizeof(B) / sizeof(B[0]);
	int* C = (int*)malloc(sizeof(B));
	int count = 0;

	for (int i = 0; i < a_size; i++) {
		for (int j = 0; j < b_size; j++) {
			if (A[i] == B[j]) {
				C[count] = A[i];
				count++;
			}
		}

	}

	int uni = 0;
	int* uniq = (int*)malloc(sizeof(C));

	for (int i = 0; i < count; i++) {
		int dubl = 0;
		for (int j = 0; j < uni; j++) {
			if (C[i] == uniq[j]) {
				dubl = 1;
				break;
			}
		}
		if (dubl == 0) {
			uniq[uni] = C[i];
			uni++;
		}
	}

	for (int i = 0; i < uni; i++) {
		printf("%d ", uniq[i]);

	}




	return 0;
}