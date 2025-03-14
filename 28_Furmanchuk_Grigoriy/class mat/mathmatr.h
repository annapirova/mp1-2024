#pragma once
#include <iostream>
#include <stdbool.h>
using namespace std;

class matrix {
private:
	int n;
	int m;
	int** arr;
public:

	matrix(int r = 0, int c = 0);
	matrix(const matrix& m2);
	void resize(int r, int c);
	void setel(int r, int c, int x); // need fix
	int& getel(int r, int c) { return arr[r][c]; } // need fix
	matrix sumx(const matrix& m2) const;
	matrix mply(const matrix& m2); 
	~matrix();
	int& operator() (int r, int c);
	const int& operator() (int r, int c) const;
	matrix operator+(const matrix& m2) const;
	matrix& operator=(const matrix& m2);
	matrix operator*(const matrix& m2);
	bool operator==(const matrix& m2) const;
	bool operator>(const matrix& m2) const;
	bool operator<(const matrix& m2) const;
	matrix operator*(int x);
	matrix& operator+=(const matrix& m2);

	friend ostream& operator<<(ostream& f, const matrix& v);
	friend istream& operator>>(istream& f, const matrix& v);
	friend matrix operator*(int i, matrix& v);

};

// += 
