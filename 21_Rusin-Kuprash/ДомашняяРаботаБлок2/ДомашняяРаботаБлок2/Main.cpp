#include "Pol.h"


int main() {
	Pol k1(5), k2, k3(4, 5.6f), k4;
	k4 = k3;
	k1.print();
	k2.print();
	k3.print();
	cout << k4.getDeg() << endl;
	cout << k4.getCoef(0) << endl;
	k4.ChangeCoef(1, 3.4f);
	k4.ChangeCoef(2, 2.4f);
	k4.ChangeCoef(3, 1.4f);
	k4.print();
	cout << k4.Value(2);
	

	return 1;
}