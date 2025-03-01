#pragma once
#include <iostream>
using namespace std;

class matrix {
private:
	int n;
	int m;
	int** arr;

public:

	matrix(int r = 0, int c = 0, int** id = nullptr);
	void resize(int r, int c);
	void setel(int r, int c, int x);
	int getel(int r, int c) { return arr[r][c]; }
	matrix sumx(matrix m2);
	matrix mply(matrix m2);
	~matrix();
};
