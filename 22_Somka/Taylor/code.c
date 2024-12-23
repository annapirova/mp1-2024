#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>


double FirstSin(double x) {
	return x;
}

double NextSin(double x, int i) {
	return -(x * x) / ((2 * i + 1) * 2 * i);
}


double FirstCos(double x) {
	return 1;
}

double NextCos(double x, int i) {
	return -(x * x) / ((2 * i - 1) * 2 * i);
}


double FirstExp(double x) {
	return 1;
}

double NextExp(double x, int i) {
	return x / i;
}


double FirstLn(double x) {
	return (x - 1);
}

double NextLn(double x, int i) {
	return(-(i * (x - 1)) / (i + 1));
}


typedef double (First)(double);
typedef double (Next)(double, int);


double Taylor(double x, int N, double acc, double etalon, First f, Next g) {
	double sum, prev, next, diff;
	diff = acc;

	prev = f(x);
	sum = prev;

	int i;
	for (i = 1; i < N; i++) {
		if (diff >= acc) {
			next = prev * g(x, i);
			sum += next;
			prev = next;

			diff = fabs(sum - etalon);
		}
	}

	return sum;
}


void First_Mode() {
	int func, N;
	double value, x, acc, etalon, diff;

	printf("1. sin(x)\n2. cos(x)\n3. exp(x)\n4. ln(x)\n");
	do {
		printf("Выберите функцию: ");
		scanf_s("%d", &func);
	} while (!(1 <= func <= 4));

	if (func == 4) {
		printf("\n0 < x < 2 (!)\n");

		do {
			printf("Введите значение x: ");
			scanf_s("%lf", &x);
		} while ((x < 0) || (x > 2));
	}

	else {
		printf("\nВведите значение x: ");
		scanf_s("%lf", &x);
	}

	printf("Введите точность вычисления: ");
	scanf_s("%lf", &acc);

	printf("Введите кол-во слагаемых N: ");
	scanf_s("%d", &N);


	if ((func == 1) || (func == 2))
		while (fabs(x) > 2 * M_PI) {
			if (fabs(x) != x)
				x = x + 2 * M_PI;

			else
				x = x - 2 * M_PI;
		}


	switch (func) {
	case 1:
		etalon = sin(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		value = Taylor(x, N, acc, etalon, FirstSin, NextSin);
		printf("Ф-ла Тейлора: %lf\n", value);

		diff = fabs(etalon - value);

		printf("Разница: %lf\n\n\n", diff);

		break;

	case 2:
		etalon = cos(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		value = Taylor(x, N, acc, etalon, FirstCos, NextCos);
		printf("Ф-ла Тейлора: %lf\n", value);

		diff = fabs(etalon - value);

		printf("Разница: %lf\n\n\n", diff);

		break;

	case 3:
		etalon = exp(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		value = Taylor(x, N, acc, etalon, FirstExp, NextExp);
		printf("Ф-ла Тейлора: %lf\n", value);

		diff = fabs(etalon - value);

		printf("Разница: %lf\n\n\n", diff);

		break;

	case 4:
		etalon = log(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		value = Taylor(x, N, acc, etalon, FirstLn, NextLn);
		printf("Ф-ла Тейлора: %lf\n", value);

		diff = fabs(etalon - value);

		printf("Разница: %lf\n\n\n", diff);

		break;

	default:
		printf("Такой команды нет...\n\n\n");
		break;
	}
}


void Second_Mode() {
	int func, N_max; int i;
	double value, x, etalon, diff;

	printf("1. sin(x)\n2. cos(x)\n3. exp(x)\n4. ln(x)\n");
	do {
		printf("Выберите функцию для серийного эксперимента: ");
		scanf_s("%d", &func);
	} while (!(1 <= func <= 4));

	if (func == 4) {
		printf("\n0 < x < 2 (!)\n");

		do {
			printf("Введите значение x: ");
			scanf_s("%lf", &x);
		} while ((x < 0) || (x > 2));
	}

	else {
		printf("\nВведите значение x: ");
		scanf_s("%lf", &x);
	}

	printf("Введите верхнюю границу кол-ва слагаемых N max (<= 25): ");
	scanf_s("%d", &N_max);


	if ((func == 1) || (func == 2))
		while (fabs(x) > 2 * M_PI) {
			if (fabs(x) != x)
				x = x + 2 * M_PI;

			else
				x = x - 2 * M_PI;
		}


	switch (func) {
	case 1:
		etalon = sin(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		for (i = 1; i <= N_max; i++) {
			value = Taylor(x, i, 0.0, etalon, FirstSin, NextSin);
			diff = fabs(etalon - value);

			printf("(N = %d) ", i);
			printf("Ф-ла Т.: %lf; ", value);
			printf("разница: %lf\n", diff);
		}
		printf("\n\n");

		break;

	case 2:
		etalon = cos(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		for (i = 1; i <= N_max; i++) {
			value = Taylor(x, i, 0.0, etalon, FirstCos, NextCos);
			diff = fabs(etalon - value);

			printf("(N = %d) ", i);
			printf("Ф-ла Т.: %lf; ", value);
			printf("разница: %lf\n", diff);
		}
		printf("\n\n");

		break;

	case 3:
		etalon = exp(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		for (i = 1; i <= N_max; i++) {
			value = Taylor(x, i, 0.0, etalon, FirstExp, NextExp);
			diff = fabs(etalon - value);

			printf("(N = %d) ", i);
			printf("Ф-ла Т.: %lf; ", value);
			printf("разница: %lf\n", diff);
		}
		printf("\n\n");

		break;

	case 4:
		etalon = log(x);

		printf("\nЭталонное значение (math.h): %lf\n", etalon);

		for (i = 1; i <= N_max; i++) {
			value = Taylor(x, i, 0.0, etalon, FirstLn, NextLn);
			diff = fabs(etalon - value);

			printf("(N = %d) ", i);
			printf("Ф-ла Т.: %lf; ", value);
			printf("разница: %lf\n", diff);
		}
		printf("\n\n");

		break;

	default:
		printf("Такой команды нет...\n\n\n");
		break;
	}
}


void main() {
	setlocale(LC_ALL, "Russian");

	int mode = -1;

	while (mode != 0) {
		printf("Выберите режим:\n");
		printf(" 1. Первый\n 2. Второй\n 0. Выход\n>>> ");
		scanf_s("%d", &mode);
		printf("\n");

		switch (mode) {
		case 0:
			printf("Пока!\n");
			break;

		case 1:
			First_Mode();
			break;

		case 2:
			Second_Mode();
			break;

		default:
			printf("Такой команды нет...\n");
			break;
		}
	}
}
