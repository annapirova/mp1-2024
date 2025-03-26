#pragma once
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <cmath>


using namespace std;



class Matrix {
private:
	int size;
	double** A;


public:
	Matrix(int n) {  //Конструктор для задания размера квадратной матрицы и самого создания матрицы.
		size = n;
		if (size > 0) {
			A = new double* [n];
			for (int i = 0; i < n; i++) {
				A[i] = new double[n];
			}

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					A[i][j] = 0;
				}
			}
		}

		else {
			A = nullptr;
			cout << "Некорректный размер матрицы!\n Введите размер снова!";
		}
	}

	Matrix(const Matrix& MatrixCopy) {  //Конструктор копирования для последующих матриц.
		size = MatrixCopy.size;

		A = new double* [size];
		for (int i = 0; i < size; i++) {
			A[i] = new double[size];
		}

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				A[i][j] = MatrixCopy.A[i][j];
			}
		}
	}


	void FulfMat(double min1, double max1) {
		for (int i = 0; i < size; i++) {
			//cout << "\n";
			for (int j = 0; j < size; j++) {
				A[i][j] = min1 + double(rand()) / RAND_MAX * (max1 - min1);
				//cout << A[i][j] << " ";
			}
		}
	}

	int GetSize() {  //Конструктор для возврата размера матрицы.
		cout << size;
		return size;
	}

	double& operator()(int a, int b)
	{
		return A[a][b];
	}

	const double& operator()(int a, int b) const  //Перегруженный оператор для возврата значения из матрицы.
	{
		return A[a][b];
	}

	void Elem(int a, int b, double x) {  //Конструктор для задания значения определенного элемента матрицы.
		if (a < 0 || b < 0)
			cout << "\nВведены отрицательные/нулевые индексы! Пожалуйста повторите корректный ввод.\n";
		if (a < (size + 1) || b < (size + 1))
			A[a - 1][b - 1] = x;
		else
			cout << "\nИндекс вне размера матрицы! Пожалуйста повторите корректный ввод.\n";
	}

	double GetElem(int a, int b) {  //Конструктор для вывода элемента матрицы по индексам.
		if (a < (size + 1) && b < (size + 1)) {
			cout << A[a - 1][b - 1];
			return A[a - 1][b - 1];
		}
		else
			cout << "\nИндекс вне размера матрицы! Пожалуйста введите другое значение.\n";
	}

	void Print() {
		cout.precision(2);
		for (int i = 0; i < size; i++) {
			cout << "\n\n";
			for (int j = 0; j < size; j++) {
				cout << fixed << A[i][j] << "   ";
			}
		}
	}


	Matrix& operator= (const Matrix& C) {

		if (size != C.size)
		{
			for (int i = 0; i < size; i++) {
				delete[] A[i];
			}
			delete[]A;

			A = new double* [size];
			for (int i = 0; i < size; i++) {
				A[i] = new double[size];
			}
		}

		size = C.size;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				A[i][j] = C(i, j);
			}
		}

		return *this;
	}


	Matrix operator+ (const Matrix& B) {
		Matrix C(size); // = C(this->size)

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				C.A[i][j] = A[i][j] + B.A[i][j]; // this->A[i][j] + B.A[i][j];
			}
		return C;
	}


	Matrix operator- (const Matrix& B) {

		Matrix C(size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				C.A[i][j] = A[i][j] - B.A[i][j];
			}
		return C;
	}


	Matrix operator* (const Matrix& B) {

		Matrix C(size);
		double mult = 0.0;

		for (int k = 0; k < size; k++) {
			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					mult = mult + (A[k][j] * B.A[j][i]);
				}
				C.A[k][i] = mult;
				mult = 0;
			}
		}
		return C;
	}


	Matrix operator* (double x) {

		Matrix C(size);

		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++) {
				C.A[i][j] = A[i][j] * x;
			}
		return C;
	}


	//Деструктор для матрицы.
	~Matrix() {
		for (int i = 0; i < size; i++) {
			delete[] A[i];
		}
		delete[]A;
	}


	friend ostream& operator<<(ostream& s, const Matrix& A) {

		for (int i = 0; i < A.size; i++) {
			for (int j = 0; j < A.size; j++) {
				s << A(i, j) << "   ";
			}
			s << "\n\n";
		}

		return s;
	}

};