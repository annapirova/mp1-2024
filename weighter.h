#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>


using namespace std;



class Weighter {

private:
	void KilToPound(double weight) {
		double p = weight / 453.59;
		cout << "\nИсходный вес в килограммах: " << weight << "\nПолученный вес в фунтах: " << p;
	};
	void KilToOunce(double weight) {
		double o = weight / 28.35;
		cout << "\nИсходный вес в килограммах: " << weight << "\nПолученный вес в унциях: " << o;
	};
	void KilToDrachma(double weight) {
		double d = weight / 3.89;
		cout << "\nИсходный вес в килограммах: " << weight << "\nПолученный вес в драхмах: " << d;
	};

public:
	double weight;

	void pound() {
		return KilToPound(weight);
	};

	void ounce() {
		return KilToOunce(weight);
	};

	void drachma() {
		return KilToDrachma(weight);
	};

};