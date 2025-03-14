﻿#include <iostream>
#include "Header.h"
using namespace std;


void main() {
	int n;
	cin >> n;
	dist t(n);
	int cm = 0;
	while (cm != 6) {
		int res;
		cin >> cm;
		switch (cm) {
		case 1: 
			cout << "Set new distance: ";
			int m;
			cin >> m;
			t.setcurr(m);
			break;
		case 2:
			res = t.getd();
			cout << "Current distance in metres:" << res <<"\n";
			break;
		case 3:
			res = t.getmile();
			cout << "Miles: " << res << "\n";
			break;
		case 4:
			res = t.getfoot();
			cout << "Foots: " << res << "\n";
			break;
		case 5:
			res = t.getyard();
			cout << "Yards: " << res << "\n";
			break;
		}
		cout << "no cmd!";
	}
}