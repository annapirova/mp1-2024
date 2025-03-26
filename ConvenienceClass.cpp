#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>

#include "weighter.h"


using namespace std;



//1.5 Конвертер весов




void start_menu() {
	cout << "1. Килограммы в американские фунты\n";
	cout << "2. Килограммы в американские унции\n";
	cout << "3. Килограммы в аптечную драхму\n";
}

void end_menu() {
	cout << "1. Повторить конвертацию в другую единицу измерения.\n";
	cout << "2. Изменить массу.\n";
	cout << "3. Завершить работу программы.\n";
}


int main() 
{
	int status = 0, c = 0;
	double we = 0.0;
	setlocale(LC_ALL, "Russian");

	Weighter weightmain;

	while (c <= 10) {
		if (status == 0) {
			cout << "Задайте изначальный вес в килограммах: ";
			cin >> weightmain.weight;
			if (weightmain.weight > 0.0) {
				cout << "\nОтлично! Конвертируемая масса: " << weightmain.weight << " кг\n\n";
				status = 1;
			}
			else {
				while (weightmain.weight <= 0.0) {
					cout << "Получена некорректная масса! Пожалуйста, повторите ввод!";
					cin >> weightmain.weight;
				}
			}

		}

		if (status == 1) {
			start_menu();
			cout << "\n\nВыберите конвертацию в требуемую единицу массы: \n";
			cin >> c;

			switch (c) {
			case 1: {
				weightmain.pound();
				status = 2;
				break;
			}

			case 2: {
				weightmain.ounce();
				status = 2;
				break;
			}

			case 3: {
				weightmain.drachma();
				status = 2;
				break;
			}
			}
		}

		if (status == 2) {
			cout << "\n\nКонвертация завершена! Выберите дальнейшее действие: \n\n";
			end_menu();
			cin >> c;

			switch (c) {
			case 1: {
				status = 1;
				break;
			}
			case 2: {
				status = 0;
				break;
			}
			case 3: {
				cout << "Thanks for using! GD!\n";
				c = 11;
				break;
			}
			}
		}
	}


	return 0;
}