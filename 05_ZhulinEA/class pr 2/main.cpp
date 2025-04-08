#include <iostream>
#include "Polynom.h"

using namespace std; 

int main() {
	Polynom a, b, c, c1, c2, c3;
	cin >> a >> b; 
	c1 = 2.5 * a;
	c2 = c1 + 2.0; 
	c3 = c2 - b; 
	c = c1 + c2 + c3;
	cout << c;
}