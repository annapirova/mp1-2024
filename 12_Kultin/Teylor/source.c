#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

//#define RAND_MIN = pow(10, n - 1)

typedef double(*First)(double x);
typedef double(*Next)(double x, int i);

double FirstExp(double x)
{
	return 1;
}


double NextExp(double x, int n)
{
	return x / n;
}
double Teylor(
	double x,
	int k,
	First first,
	Next next,
	double trueVal,
	double ext
) {
	double summ = first(x), elem = summ,
		a = fabs(summ - trueVal);

	int i = 1;

	while ((i < k) && (a > ext))
	{
		double elemNext = elem * next(x, i);
		summ += elemNext;
		i++;
	}
	return summ;
}

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	double x = 0.2, y, z;

	y = Teylor(x, 10, FirstExp, NextExp, exp(x), 1e-7);
	printf("%d", y);

	return 0;

}

