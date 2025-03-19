#pragma once
#include <iostream>
#include <math.h>
using namespace std;


class Rational {
private:
	int val;
	int del;
public:
	Rational(int v = 0, int d = 0) {
		val = v;
		del = d;
		Lead();
	}
	Rational(const Rational & v2) {
		val = v2.val;
		del = v2.del;
		Lead();
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
		if (del < 0) {
			val *= -1;
			del *= -1;
		}
		int m = abs(val), n = abs(del), r;
		if (n > m) {
			m = abs(val);
			n = abs(del);
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