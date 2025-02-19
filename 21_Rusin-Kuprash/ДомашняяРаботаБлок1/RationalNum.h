#pragma once
#include <iostream>
using namespace std;


class Rational {
private:
	int val;
	int del;
public:
	Rational(int v = 0, int d = 0) {
		val = v;
		del = d;
	}
	Rational operator +(Rational other) {
		Rational v(val * other.del + other.val * del, del * other.del);
		v.Lead();
		return v;
	}
	Rational operator -(Rational other) {
		Rational v(val * other.del - other.val * del, del * other.del);
		v.Lead();
		return v;
	}
	Rational operator *(Rational other) {
		Rational v(val * other.val, del * other.del);
		v.Lead();
		return v;
	}
	Rational operator / (Rational other) {
		Rational v(val * other.del, del * other.val);
		v.Lead();
		return v;
	}

	void Lead() {
		int m, n, r;
		if (val > del) {
			m = val;
			n = del;
		}
		else {
			m = del;
			n = val;
		}
		r = m % n;
		while (r != 0) {
			m = n;
			n = r;
			r = m % n;
		}
		val /= n;
		del /= n;
	}
	void print() {
		cout << val << "/" << del;
	}
};