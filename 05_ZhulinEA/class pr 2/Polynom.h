#pragma once 
#include <iostream>
using namespace std; 

class Polynom {
private: 
	int n; // степень полинома 
	double *a; //Коэффиценты полинома 
	
public: 
	Polynom(); 
	Polynom(int g, double* b);
	Polynom(const Polynom& b);
	~Polynom(); 
	int CoutN();
	void ValueKoff(int k);
	int ValuePolynom(int x); 
	void ValueDiff(); 
	Polynom operator+(const Polynom& b); 
	Polynom& operator=(const Polynom& b); 
	Polynom operator-(const Polynom& b);
	Polynom operator+(double x); 
	friend Polynom operator+(double x, const Polynom& b); 
	Polynom operator-(double x);
	friend Polynom operator-(double x, const Polynom& b);
	friend Polynom operator*(double x, const Polynom &b); 
	Polynom operator*(double x); 
	friend ostream& operator<<(ostream& os, Polynom& p); 
	friend istream& operator>>(istream& is, Polynom& p);   
	double& operator[](int index); 

};
