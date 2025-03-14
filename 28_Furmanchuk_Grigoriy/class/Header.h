#pragma once
#include <iostream>
using namespace std;

class dist {
private:
	double metr;
public:
	dist(double m = 0.0);
	void setcurr(double ms);
	double getd() { return metr; }
	double getmile() { return metr / 1609.34; }
	double getyard() { return metr * 1.09361; }
	double getfoot() { return metr * 3.28084; }
};


