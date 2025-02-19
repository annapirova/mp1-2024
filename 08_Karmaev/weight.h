#pragma once
#include <cstdlib>
#include <iostream>


using namespace std;

class weight {
private:
	double kg;
public:
	void setW(double k) { kg = abs(k); }
	double getW() { return kg; }
	void printF() {
		cout << "1).pound - пуды\n2).ounce - унции\n3).carat - караты\n4).slug - слаги\n5)Задать вес заново\n6).allC - Все сразу\n7)Выйти\n";
	}
	double pound() { return (kg / 16.38); }
	double ounce() { return (kg / 0.0311035); }
	double carat() { return (kg / 0.0002); }
	double slug() { return (kg / 14.5939); }
	void allC() {
		cout << kg / 16.38 << "\n" << kg / 0.0311035 << "\n" << kg / 0.0002 << "\n" << kg / 14.5939 << "\n";
	}

};
