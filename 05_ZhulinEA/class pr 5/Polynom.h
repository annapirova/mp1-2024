#pragma once
#include <iostream>
#include <cmath> 
using namespace std;


template <typename T> 
class Polynom {
private:
	int n; 
	T* a; 

public:
	Polynom() : n(0), a(nullptr) {};
	Polynom(int g, T* b) {
		n = g;
		if (g > 0) {
			a = new T[g + 1];
			for (int i = 0; i < g + 1; i++) {
				a[i] = b[i];
			}
		}
		else {
			a = nullptr;
		}
	}

	Polynom(const Polynom& b)
	{
		n = b.n;
		a = new T[n + 1];
		for (int i = 0; i <= n; ++i) {
			a[i] = b.a[i];
		}
	}

	~Polynom() {
		if (a) {
			delete[]a;
		}
	}

	int CoutN() {
		return n;
	}
	void ValueKoff(int k) {

		cout << a[k - 1] << '\n';

	}
	int ValuePolynom(int x) {
		int res = 0;
		for (int i = 0; i < n; i++) {
			res += a[i] * (pow(x, (n - i)));
		}
		return res + a[n];
	}
	void ValueDiff() {
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
	Polynom<T> operator+(const Polynom& b) {
		int new_n = max(n, b.n);
		T* new_a = new T[new_n + 1];

		for (int i = 0; i <= new_n; ++i) {
			new_a[i] = 0.0;
		}

		for (int i = 0; i <= n; ++i) {
			new_a[new_n - (n - i)] += a[i];
		}
		for (int i = 0; i <= b.n; ++i) {
			new_a[new_n - (b.n - i)] += b.a[i];
		}

		Polynom<T> res(new_n, new_a);
		delete[] new_a;
		return res;
	}

	Polynom<T>& operator=(const Polynom& b) {
		if (this == &b) {
			return *this;
		}
		delete[] a;

		n = b.n;
		a = new T[n + 1];
		for (int i = 0; i <= n; ++i) {
			a[i] = b.a[i];
		}

		return *this;
	}
	Polynom<T> operator-(const Polynom& b) {
		int new_n = max(n, b.n);
		T* new_a = new T[new_n + 1];

		for (int i = 0; i <= new_n; i++) {

			T coeff_a = 0.0, coeff_b = 0.0;

			if (i <= n) {
				coeff_a = a[i];
			}

			if (i <= b.n) {
				coeff_b = b.a[i];
			}

			new_a[i] = coeff_a - coeff_b;
		}
		Polynom<T> res(new_n, new_a);
		delete[] new_a;	
		return res;
	}
	Polynom<T> operator+(T x) {
		a[n] += x;
		return *this;
	}
	friend Polynom<T> operator+(T x, const Polynom& b) {
		b.a[b.n] += x;
		return b;
	}
	Polynom<T> operator-(T x) {
		a[n] -= x;
		return *this;
	}
	friend Polynom<T> operator-(T x, const Polynom& b) {
		Polynom<T> g = b;
		g.a[g.n] -= x;
		return g;
	}
	friend Polynom<T> operator*(T x, const Polynom& b) {
		T* new_a = new T[b.n + 1];
		for (int i = 0; i <= b.n; i++) {
			new_a[i] = b.a[i] * x;
		}
		Polynom<T> res(b.n, new_a);
		delete[]new_a;
		return res;
	}
	Polynom<T> operator*(T x) {
		T* new_a = new T[n + 1];
		for (int i = 0; i < n; i++) {
			new_a[i] = a[i] * x;
		}
		Polynom<T> res(n, new_a);
		delete[]new_a;
		return res;
	}
	friend ostream& operator<<(ostream& os, Polynom& b) {
		if (b.n <= 0) {
			os << 0;
			return os;
		}
		for (int i = 0; i <= b.n; i++) {
			if (i == b.n) {
				T g = b.a[b.n];
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
	friend istream& operator>>(istream& is, Polynom& b) {
		cout << "Cin N - stepen polynoma: ";
		is >> b.n;
		if (b.n > 0) {
			b.a = new T[b.n + 2];
		}
		cout << "Cin koeffi nachinaia so starshego chlena: " << '\n';
		for (int i = 0; i <= b.n; i++) {
			is >> b.a[i];
		}
		return is;
	}
T& operator[](int index) {
		return a[index];
	}

};