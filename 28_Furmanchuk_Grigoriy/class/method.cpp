#include "Header.h"
#include <iostream>

using namespace std;

dist::dist(double m = 0.0) {
	if (m < 0.0) metr = -100000;
	else metr = m;
}

void dist::setcurr(double ms) {
	if (ms < 0.0) metr = -100000;
	else metr = ms;
}

