#include <cstdlib>
#include <iostream>
#include "weight.h"


using namespace std;



int main() {
	setlocale(LC_ALL, "Russian");
	weight t1;
	double z;
	cout << "Введите вес в кг: ";
	cin >> z;

	t1.setW(z);
	t1.printF();
	int type = 0;
	double res;
	while (type != 7) {
		cin >> type;
		switch (type) {
		case 1:
			res = t1.pound();
			cout << "Результат конвертации в пуды = " << res;
			break;
		case 2:
			res = t1.ounce();
			cout << "Результат конвертации в унции = " << res;
			break;
		case 3:
			res = t1.carat();
			cout << "Результат конвертации в караты = " << res;
			break;
		case 4:
			res = t1.slug();
			cout << "Результат конвертации в слаги = " << res;
			break;
		case 5:
			cin >> z;
			t1.setW(z);
			break;
		case 6:
			t1.allC();
			break;
		case 7:
			
			break;
		}
	}
	return 1;
}