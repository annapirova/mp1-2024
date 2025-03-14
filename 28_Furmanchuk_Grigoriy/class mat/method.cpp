#include "mathmatr.h"
using namespace std;

matrix::matrix(int r, int c) {
	n = r;
	m = c;
	arr = new int* [r];
	for (int i = 0; i < r; i++) {
		arr[i] =new int[c];
		for (int j = 0; j < c; j++) arr[i][j] = 0;
	}
}

matrix::matrix(const matrix& m2)
{
	n = m2.n;
	m = m2.m;
	arr = new int* [n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		for (int j = 0; j < m; j++) {
			arr[i][j] = m2(i, j);
		}
	}

}

void matrix::setel(int r, int c, int x){
	arr[r][c] = x;
}

void matrix::resize(int r, int c){
	matrix m(r, c);
	for (int i = 0; i < r; i++) {
		m.arr[i] = new int[c];
		for (int j = 0; j < c; j++) {
			m.arr[i][j] = arr[i][j];
		}
	}
	n = r;
	m = c;
	arr = m.arr;
}

matrix matrix::sumx(const matrix& m2) const{
	matrix res(n, m);
	if (n != m2.n || m != m2.m) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			res.arr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				res.arr[i][j] = arr[i][j] + m2.arr[i][j];
			}
		}
		return res;
	}
}


matrix matrix::mply(const matrix& m2) {
	matrix res(n, n);
	if (m != m2.n) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int t = 0;
				for (int k = 0; k < m; k++) {
					t+= (arr[i][k] * m2.arr[k][j]);
				}
				res.arr[i][j] = t;
			}
		}
		
	}
	return res;
}

matrix::~matrix() {
	if (arr!= nullptr) 
		delete []arr;
}

int& matrix::operator()(int r, int c)
{
	return arr[r][c];
}

const int& matrix::operator()(int r, int c) const
{
	return arr[r][c];
}


ostream& operator<<(ostream& f, const matrix& v)
{
	for (int i = 0; i < v.n; i++) {
		for (int j = 0; j < v.m; j++) {
			f << v.arr[i][j] << " ";
		}
		f << endl;
	}
	return f;
}
istream& operator>>(istream& f, const matrix& v)
{
	for (int i = 0; i < v.n; i++) {
		for (int j = 0; j < v.m; j++) {
			f >> v.arr[i][j];
		}
	}
	return f;
}



// good!
matrix& matrix::operator=(const matrix& m2) {
	if (n != m2.n  || m != m2.m) {
		if (arr != nullptr) delete[]arr;
		arr = new int* [m2.n];
		for (int i = 0; i < m2.n; i++) {
			arr[i] = new int[m2.m];
			for (int j = 0; j < m2.m; j++) arr[i][j] = m2.arr[i][j];
		}
	}
	else if(n == m2.n && m == m2.m) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = m2.arr[i][j];
			}
		}
	}
	n = m2.n;
	m = m2.m;
	return *this;
}


//good
matrix matrix::operator+(const matrix& m2) const{
	matrix res(n, m);
	if (n != m2.n || m != m2.m) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			res.arr[i] = new int[m];
			for (int j = 0; j < m; j++) {
				res.arr[i][j] = arr[i][j] + m2.arr[i][j];
			}
		}
		return res;
	}
}

matrix matrix::operator*(const matrix& m2){
	matrix res(n, n);
	if (m != m2.n) {
		res.arr = nullptr;
		return res;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int t = 0;
				for (int k = 0; k < m; k++) {
					t += (arr[i][k] * m2.arr[k][j]);
				}
				res.arr[i][j] = t;
			}
		}

	}
	return res;
}

bool matrix::operator==(const matrix& m2)const {
	if (n == m2.n && m == m2.m) return true;
	return false;
}

bool matrix::operator>(const matrix& m2) const {
	if (n * m > m2.n * m2.m) return true;
	return false;
}

bool matrix::operator<(const matrix& m2) const {
	if (n * m < m2.n * m2.m) return true;
	return false;
}

matrix matrix::operator*(int x){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] *= x;
		}
	}
	return *this; 
}

matrix operator*(int x, matrix& v){
	matrix res(v);
	for (int i = 0; i < v.n; i++) {
		for (int j = 0; j < v.m; j++) res(i, j) = res(i,j) * x;
	}
	return res;
}

matrix& matrix::operator+=(const matrix& m2) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] += m2(i, j);
		}
	}
	return *this;
}




