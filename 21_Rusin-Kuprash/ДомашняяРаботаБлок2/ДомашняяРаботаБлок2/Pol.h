#pragma once
//#include <stdio.h>
//#include <stdlib.h>
#include <iostream>
#include <memory>

#include<cmath>

using namespace std;



int min(int a, int b) {
	return a < b? a: b;
}


class Pol {
private:
	int deg;
	float* coef;

public:
	Pol(int deg_ = 1, float stValue = 1.f) {
		if (deg_ > 100) {
			deg_ = 100;
		}
		else if (deg_ < 1) {
			deg_ = 1;
		}
		deg = deg_;
		coef = new float[deg];
		fill(stValue);
	};
	~Pol() {
		delete[] coef;
	}

	Pol& operator=(const Pol& other) {
		if (this == &other) { 

			cout << "surprise!!!";
			fflush(stdout);

			return *this; }

		cout << "surprise!!!";
		fflush(stdout);

		deg = other.deg;
		float* nCoef = (float*)realloc(coef, sizeof(float) * deg);
		if (nCoef != NULL) {
			coef = nCoef;
		}
		memcpy(coef, other.coef, sizeof(float) * deg);

		return *this;
	}


	void fill(float k) {
		for (int i = 0; i < deg; i++) {
			coef[i] = k;
		}
	}


	void ChangeDeg(int nDeg) {
		float* nCoef = new float[nDeg];
		if (nDeg > deg) {
			memset(coef, 1, sizeof(float) * deg);
		}
		memcpy(nCoef, coef, min(nDeg, deg));
	}


	void ChangeCoef(int coefNum, float val) {
		//coefNum += 1;
		if (coefNum < deg) {
			coef[coefNum] = val;
		}
	}


	float getCoef(int coefNum) {
		//coefNum += 1;
		if (coefNum < deg) {
			return coef[coefNum];
		}
	}


	int getDeg() {
		return deg;
	}


	float Value(float x) {
		float val = 0;
		for (int i = 0; i < deg; i++) {
			val += coef[i] * powf(x, i);
		}
		return val;
	}


	void print() {
		int i = 1;
		cout << coef[0];
		for (i; i < deg; i++) {
			cout << " + " << coef[i] << " * x" << i;
		}
		cout << endl;
	}
};