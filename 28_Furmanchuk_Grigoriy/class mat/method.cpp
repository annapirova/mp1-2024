#include "mathmatr.h"
using namespace std;

matrix::matrix(int r, int c, int** id) {
	n = r;
	m = c;
	arr = id;
	//id = new int* [r];
	//id = new int* [r];
	for (int i = 0; i < r; i++) {
		id[i] =new int[c];
	}
}

void matrix::setel(int r, int c, int x) {
	arr[r][c] = x;
}

void matrix::resize(int r, int c) {
	int** id = new int* [r];
	matrix m(r, c, id);
	for (int i = 0; i < r; i++) {
		id[i] = new int[c];
		for (int j = 0; j < c; j++) {
			id[i][j] = arr[i][j];
		}
	}
	n = r;
	m = c;
	arr = id;
}

matrix matrix::sumx(matrix m2) {
	int** id = new int*[n];
	matrix res(n, m, id);
	if (n != m2.n || m != m2.m) {
		id = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			id[i] = new int[m];
			for (int j = 0; j < m; j++) {
				id[i][j] = arr[i][j] + m2.arr[i][j];
			}
		}
		return res;
	}
}

matrix matrix::mply(matrix m2) {
	int** id = new int* [n];
	matrix res(n, n, id);
	if (m != m2.n) {
		id = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			id[i] = new int[m];
			for (int j = 0; j < n; j++) {
				id[i][j] = 0;
				for (int k = 0; k < m; k++) {
					id[i][j] += (arr[n][k] * m2.arr[k][j]);
				}
			}
		}
		return res;
	}
}

matrix::~matrix() {
	if (arr) delete []arr;
}