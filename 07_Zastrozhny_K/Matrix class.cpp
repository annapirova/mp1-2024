#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>


using namespace std;

#include "matrixcl.h"



//2.4 - Матрица



void main_menu() {
	cout << "\n\nВыберите желаемое действие:\n";
	cout << "1. Узнать заданный размер матрицы\n";
	cout << "2. Задать элемент матрицы по его индексу\n";
	cout << "3. Узнать элемент матрицы по его индексу\n";
	cout << "4. Выполнить сложение двух матриц\n";
	cout << "5. Выполнить вычитание одной матрицы из другой\n";
	cout << "6. Выполнить перемножение двух матриц\n";
	cout << "7. Выполнить умножение матрицы на константу\n";
	cout << "8. Выполнить печать матрицы\n";

}

void end_menu() {
	cout << "\n1. Задать новый размер матрицы и, соответсвенно, саму матрицу\n";
	cout << "2. Вернуться к действиям с матрицами\n";
	cout << "3. Завершить работу программы\n";
}





int main() 
{
	int c = 0, status = 0, mats = 0, a = 0, b = 0;
	double min1 = 0.0, max1 = 0.0, x = 0.0, d = 0.0;
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "Задайте желаемый размер матрицы:  ";
	cin >> mats;
	Matrix matrixA(mats);
	Matrix matrixB(mats);
	Matrix matrixC(mats);



	while (c < 20) {
		if (status == 0) {
			if (mats > 1) {
				cout << "Задайте диапазон для генерации значений в матрицу:  ";
				cin >> min1;
				cin >> max1;
				cout << "Вот сгенерированная матрица:\n";
				matrixA.FulfMat(min1, max1);
				matrixA.Print();
				cout << "\n\n";
				status = 1;
			}
			else {
				cout << "\n\nНекорректный размер матрицы! Пожалуйста, задайте матрицу размерности >= 2\n\n";
				status = 0;
			}
		}


		if (status == 1) {

			main_menu();
			cin >> c;
			
			switch(c) {
			case 1: {
				cout << "\nВот заданный размер матрицы:  ";
				matrixA.GetSize();
				status = 2;
				break;
			}
			case 2: {
				cout << "Введите строку, столбец и, соответсвенно, элемент матрицы: ";
				cin >> a >> b >> x;
				matrixA.Elem(a, b, x);
				cout << "\nОбновленная матрица:  \n\n";
				matrixA.Print();
				status = 2;
				break;
			}
			case 3: {
				cout << "Введите строку и столбец матрицы для выдачи значения:  ";
				cin >> a >> b;
				matrixA.GetElem(a, b);
				matrixA.Print();
				status = 2;
				break;
			}
			case 4: {
				cout << "Выполняем сложение исходной и сгенерированной матрицы: \n";
				matrixB.FulfMat(min1, max1);
				matrixB.Print();
				matrixC = matrixA + matrixB;
				cout << "\n\nВот получившаяся матрица после суммирования:  \n\n";
				matrixC.Print();
				status = 2;
				break;
			}
			case 5: {
				cout << "Выполняем вычитание сгенерированной матрицы из исходной:  \n\n";
				matrixB.FulfMat(min1, max1);
				matrixB.Print();
				matrixC = matrixA - matrixB;
				cout << "\n\nВот матрица-результат разности:  \n\n";
				matrixC.Print();
				status = 2;
				break;
			}
			case 6: {
				cout << "Выполняем перемножение исходной матрицы на сгенерированную:  \n";
				matrixB.FulfMat(min1, max1);
				matrixB.Print();
				matrixC = matrixA * matrixB;
				cout << "\n\nВот получившаяся матрица после умножения:  \n\n";
				matrixC.Print();
				status = 2;
				break;
			}
			case 7: {
				cout << "Введите желаемую константу:  ";
				cin >> d;
				cout << "\nВыполянем умножение всей матрицы на константу:  \n";
				cout << d;
				matrixC = matrixA * d;
				cout << "\n\nВот матрица-результат перемножения:  \n\n";
				matrixC.Print();
				status = 2;
				break;
			}
			case 8: {
				cout << "\nВыполняем успешный вывод вашей матрицы: \n\n";
				cout << matrixA;
				status = 2;
				break;
			}
			}
		}


		if (status == 2) {
			cout << "\n\nОперация завершилась! Выберите дальнейшее действие: \n";
			end_menu();
			cin >> c;

			switch (c) {
			case 1: {
				status = 0;
				break;
			}
			case 2: {
				status = 1;
				break;
			}
			case 3: {
				cout << "Thanks for use! GD!";
				c = 100;
				break;
			}

			}
		}
	}
}
