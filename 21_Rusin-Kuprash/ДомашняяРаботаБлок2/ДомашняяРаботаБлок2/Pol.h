#pragma once
#include <exception>
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
	Pol(int deg_ = 0, float stValue = 1.f) {
		if (deg_ > 100) {
			throw std::invalid_argument("No more than 100 degree. - Polynom class");
		}
		else if (deg_ < 0) {
			throw std::invalid_argument("No less than 0 degree. - Polynom class");
		}
		deg = deg_;
		coef = new float[deg + 1];
		fill(stValue);
	};
	Pol(const Pol& other) {
		deg = other.deg;
		coef = (float*)malloc(sizeof(float) * (deg + 1));
		if (coef != NULL) {
			memcpy(coef, other.coef, sizeof(float) * (deg + 1));
		}
		else {
			throw std::runtime_error("We are too poor on memory;((");
		}
	}
	~Pol() {
		delete[] coef;
	}

	Pol& operator=(const Pol& other) {
		if (this == &other) { 

			cout << "Same function!?";

			return *this; }

		deg = other.deg;
		float* nCoef = (float*)realloc(coef, sizeof(float) * (deg + 1));
		if (nCoef != NULL) {
			coef = nCoef;
			memcpy(coef, other.coef, sizeof(float) * (deg + 1));
		}
		else {
			throw std::runtime_error("We are too poor on memory;((");
		}
		return *this;
	}


	void fill(float k) { // 
		for (int i = 0; i < deg + 1; i++) {
			coef[i] = k;
		}
	}


	void ChangeDeg(int nDeg) { // 1) задать степень полинома.
		float* nCoef = NULL;
		float v = 3;
		float& vv = v;
		nCoef = (float*)malloc(sizeof(float) * (nDeg + 1));
		if (nCoef != NULL) {
			if (nDeg > deg) {
				for (int i = 0; i < nDeg + 1; i++) {
					nCoef[i] = 1.0f;
				}
			}
			memcpy(nCoef, coef, sizeof(float) * (min(nDeg, deg) + 1));
			delete[] coef;
			coef = nCoef;
			deg = nDeg;
		}
		else {
			throw std::runtime_error("We are too poor on memory((");
		}
	}


	void ChangeCoef(int coefNum, float val) { // 2) задание коэф. мономома.
		//coefNum += 1;
		if (coefNum < deg + 1) {
			coef[coefNum] = val;
		}
		else {
			throw std::invalid_argument("Polynom's degree is smaller than the coefNum");
		}
	}


	float operator[](int coefNum) { // 4) узнать значение коэффициента	
		//coefNum += 1;
		if (coefNum < deg + 1) {
			return coef[coefNum];
		}
		throw std::invalid_argument("Polynom's degree is smaller than the coefNum");
	}


	int getDeg() { // 3) узнать степень полинома
		return deg;
	}


	float operator()(float x) { // 5) значение полинома в точке x
		float val = coef[0];
		for (int i = 1; i < deg + 1; i++) {
			val += coef[i] * powf(x, (float)i);
		}
		return val;
	}


	float DerValue(float x) { // 6) значение производной полинома в точке x
		if (deg == 0) {
			return 0;
		}
		float val = coef[1];
		for (int i = 2; i < deg + 1; i++) {
			val += coef[i] * i * powf(x, (float)(i - 1));
		}
		return val;
	}


	void print() {
		int i = 1;
		cout << coef[0];
		for (i; i < deg + 1; i++) {
			cout << " + " << coef[i] << " * x" << i;
		}
		cout << endl;
	}


	Pol operator+(const Pol& other) {
		Pol k;
		if (other.deg > deg) {
			k = other;
			for (int i = 0; i < deg + 1; i++) {
				k.coef[i] += coef[i];
			}
		}
		else {
			k = *this;
			for (int i = 0; i < other.deg + 1; i++) {
				k.coef[i] += other.coef[i];
			}
		}
		return k;
	}


	Pol operator-() {
		Pol k = *this;
		for (int i = 0; i < deg + 1; i++) {
			k.coef[i] *= -1;
		}
		return k;
	}


	Pol operator-(const Pol& other) {
		Pol k;
		if (other.deg > deg) {
			k = other;
			for (int i = 0; i < other.deg + 1; i++) {
				k.coef[i] *= -1;
			}
			for (int i = 0; i < deg + 1; i++) {
				k.coef[i] += coef[i];
			}
			
		}
		else {
			k = *this;
			for (int i = 0; i < other.deg + 1; i++) {
				//cout << i << " ";
				k.coef[i] -= other.coef[i];
			}
			cout << endl;
		}
		return k;
	}

	Pol operator*(const Pol& other) {
		int nDeg = deg * other.deg;
		Pol k = Pol(nDeg, 0);
		for (int i = 0; i < deg + 1; i++) {
			for (int j = 0; j < other.deg + 1; j++) {
				k.coef[i + j] += coef[i] * other.coef[j];
			}
		}
		return k;
	}
	
	Pol operator/(const float a) {
		if (a == 0) {
			throw std::invalid_argument("division by 0;");
		}
		Pol k = *this;
		for (int i = 0; i < deg + 1; i++) {
			k.coef[i] /= a;
		}
		return k;
	}
	
};