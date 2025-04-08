#include <iostream> 
#include "Polynom.h"
#include <cmath> 

using namespace std; 

Polynom::Polynom() : n(0), a(nullptr) {}

Polynom::Polynom(int g, double *b) {
	n = g;
	if (g > 0) {
		a = new double[g + 1];
		for (int i = 0; i < g + 1; i++) {
			a[i] = b[i];
		}
	} 
	else {
		a = nullptr; 
	}
}
Polynom::Polynom(const Polynom& b)
{
	n = b.n;
	a = new double[n + 1];
	for (int i = 0; i <= n; ++i) {
		a[i] = b.a[i];
	}
}

Polynom::~Polynom() {
	if (a) {
		delete []a; 
	}
}
int Polynom::CoutN() {
	return n; 
}

void Polynom::ValueKoff(int k) {
	
	cout << a[k - 1] << '\n';
	
}
int Polynom::ValuePolynom(int x) {
	int res = 0; 
	for (int i = 0; i < n; i++) {
		res += a[i] * (pow(x, (n - i)));
	}
	return res + a[n]; 
}

void Polynom::ValueDiff() {
	int step = n - 1;
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0 and i != n - 1) {
			cout << a[i] * (n - i) << "x^" << step << " + ";
		}
		else {
			cout << a[i] * (n - i) << "x^" << step;

		}
		step--; 
	}
}

Polynom Polynom::operator+(const Polynom& b){
	int new_n = max(n, b.n);
	double* new_a = new double[new_n + 1];

	for (int i = 0; i <= new_n; ++i) {
		new_a[i] = 0.0;
	}

	for (int i = 0; i <= n; ++i) {
		new_a[new_n - (n - i)] += a[i];
	}
	for (int i = 0; i <= b.n; ++i) {
		new_a[new_n - (b.n-i)] += b.a[i];
	}

	Polynom res(new_n, new_a);
	delete[] new_a; 
	return res;
}
Polynom& Polynom::operator=(const Polynom& b) {
		if (this == &b) { 
			return *this;
		}
		delete[] a;

		n = b.n;
		a = new double[n + 1];
		for (int i = 0; i <= n; ++i) { 
				a[i] = b.a[i];
			}
	
		return *this;
}
Polynom Polynom::operator-(const Polynom& b) {
	int new_n = max(n, b.n);
	double* new_a = new double[new_n + 1];
	
	for (int i = 0; i <= new_n; i++) {
	
		double coeff_a = 0.0, coeff_b = 0.0;
		
		if (i <= n) {
			coeff_a = a[i];
		}
		
		if (i <= b.n) {
			coeff_b = b.a[i];
		}
		
		new_a[i] = coeff_a - coeff_b;
	}
	Polynom res(new_n, new_a);
	delete[] new_a;
	return res;
}

Polynom Polynom::operator+(double x){
	a[n] += x; 
	return *this; 
}
Polynom operator+(double x, const Polynom& b) {
	b.a[b.n] += x; 
	return b; 
}
Polynom Polynom::operator-(double x) {
	a[n] -= x; 
	return *this; 
}
Polynom operator-(double x, const Polynom& b) {
	b.a[b.n] -= x; 
	return b; 
}
Polynom operator*(double x, const Polynom& b) {
	double* new_a = new double [b.n + 1]; 
	for (int i = 0; i <= b.n; i++) {
		new_a[i] = b.a[i] * x; 
	}
	Polynom res(b.n, new_a);
	delete[]new_a; 
	return res; 
}
Polynom Polynom::operator*(double x) {
	double* new_a = new double[n + 1]; 
	for (int i = 0; i < n; i++) {
		new_a[i] = a[i] * x; 
	}
	Polynom res(n, new_a); 
	delete[]new_a;
	return res; 
}
istream& operator>>(istream& is, Polynom& b) {
	cout << "Cin N - stepen polynoma: "; 
	is >> b.n; 
	if (b.n > 0) {
		b.a = new double[b.n + 2];
	}
	cout << "Cin koeffi nachinaia so starshego chlena: " << '\n'; 
	for (int i = 0; i <= b.n; i++) {
		is >> b.a[i]; 
	}
	return is; 
}
ostream& operator<<(ostream& os, Polynom& b) {
	if (b.n <= 0) {
		os << 0;
		return os;
	}
	for (int i = 0; i <= b.n; i++) {
		if (i == b.n) {
			double g = b.a[b.n];
			os << b.a[b.n];
			return os;
		}
		if (b.a[i] > 0) {
			os << b.a[i] << "x^" << (b.n - i) << " + ";
		}
		else if (b.a[i] < 0) {
			os << '-' << b.a[i] << "x^" << (b.n - i) << " ";
		}
	}
}
double &Polynom::operator[](int index) {
	return a[index];
}