#include <iostream>
#include "Polynom.h"
using namespace std; 

int main() {
	Polynom <int> a;
	Polynom <double> b; 
	Polynom <char> c; 
	cout << "vvedite a(int)" << '\n'; 
	cin >> a;
	cout << a;
	cout << '\n'; 

	cout << "vvedite b(double)" << '\n';
	cin >> b;
	cout << b;
	cout << '\n';

	cout << "vvedite c(char)" << '\n';
	cin >> c;
	cout << c;
	cout << '\n';


	return 0; 
}