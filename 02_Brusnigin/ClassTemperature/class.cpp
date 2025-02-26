#include <iostream>
#include "class.h"

using namespace std;


Temperature::Temperature(double cels) {
	if (cels >= -273.15)
		celsius = cels;
			
	else
		celsius = 0;
}


void Temperature::set_celsius() {
	double cels;

			
	do {
		cout << "Enter temperature in celsius: ";
		cin >> cels;
		cout << endl;
	}

	while (cels < -273.15);
			
	if (cels > 0)
		cout << "Okay! Your temperature is +" << cels << " C\n" << endl;

	else
		cout << "Okay! Your temperature is " << cels << " C\n" << endl;

	celsius = cels;
}


void Temperature::get_celsius() {
	if (celsius > 0)
		cout << "Temperature in celsius: +" << celsius << endl << endl;

	else
		cout << "Temperature in celsius: " << celsius << endl << endl;
}


void Temperature::get_kelvin() {
	double k;

	k = celsius + 273.15;

	cout << "Temperature in kelvin: " << k << endl << endl;
}


void Temperature::get_fahrenheit() {
	double f;

	f = (celsius * 1.8) + 32;
			
	if (f > 0)
		cout << "Temperature in fahrenheit: +" << f << endl << endl;

	else
		cout << "Temperatute in fahrenheit: " << f << endl << endl;
}


void Temperature::get_rankin() {
	double r;

	r = (celsius + 273.15)*1.8;

	cout << "Temperature in rankin: " << r << endl << endl;
}

