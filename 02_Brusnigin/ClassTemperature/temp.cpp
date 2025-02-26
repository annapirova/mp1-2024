#include <iostream>
#include "class.h"

using namespace std;


int main() {
	Temperature thermometer(36.6);

	int action = -1;

	while (action != 0) {
		cout << "Actions: \n1. Set temperature\n2. Get temp in celsius\n3. Get temp in fahrenheit\n4. Get temp in kelvin\n5. Get temp in rankin\n0. Exit\n>>> ";
		cin >> action;

		switch (action) {
		case 1:
			thermometer.set_celsius();
			break;
		
		case 2:
			thermometer.get_celsius();
			break;

		case 3:
			thermometer.get_fahrenheit();
			break;

		case 4:
			thermometer.get_kelvin();
			break;

		case 5:
			thermometer.get_rankin();
			break;
		}
	}

	return 0;
}
