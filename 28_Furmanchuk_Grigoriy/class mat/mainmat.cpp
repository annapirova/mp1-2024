#include <iostream>
#include "mathmatr.h"
using namespace std;

void main() {
	/*int** id = new int* [2];
	int** id2 = new int* [2];
	matrix m(2, 2, id);
	matrix m2(2, 2, id2);
	for (int i = 0; i < 2; i++) {
		id[i] = new int[2];
		id2[i] = new int[2];
		for (int j = 0; j < 2; j++) {
			cin >> id[i][j];
			cin >> id2[i][j];
		}
	}
	matrix a = m.sumx(m2);
	matrix b = m.mply(m2);
	int a1 = a.getel(1, 1);
	int b1 = b.getel(1, 1);
	cout << a1 << " " << b1;*/
	int** id = new int* [2];
	int** id2 = new int* [2];
	matrix m(2, 2, id);
	matrix m2(2, 2, id2);
	m.setel(1, 1, 1);
	m2.setel(1, 1, 2);
	matrix a = m.sumx(m2);
	cout << a.getel(1, 1);

}