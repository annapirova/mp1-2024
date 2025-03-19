#include "RationalNum.h"


int main() {
	Rational n(3, 5), m(15, 4), a(2, 5), c(4, 7), b(1, 3), v(3, -19);

	(n * m).print();
	cout << endl;
	(n * c).print();
	cout << endl;
	(n + a).print();
	cout << endl;
	(a * b).print();
	cout << endl;
	(n / m).print();
	cout << endl;
	(n / a).print();
	cout << endl;
	(n - a).print();
	cout << endl;
	(m - c).print();
	cout << endl;
	(v + b).print();
	cout << endl;
	
	return 1;
}