#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#define _USE_MATH_DEFINES
#include <math.h>
int state = 0;


// M_PI

typedef double (*Start)(double x);
typedef double (*Step)(double x, int n);


double NoClamp(double x) {
	return x;
}


double ClampPI(double x) {
	double v = x / (2 * M_PI);
	return (x - floor(v) * 2. * M_PI);
}


double ChosinStart(double x) {
	return 1;
}


double ChosinStep(double x, int n) {
	return x * x / (2 * (double)n) / (double)(2 * (double)n - 1);
}


double ShinusStart(double x) {
	return x;
}


double ShinusStep(double x, int n) {
	return x * x / (2 * (double)n) / (double)(2 * (double)n + 1);
}


double expStart(double x) {
	return 1;
}


double expStep(double x, int n) {
	return x / n;
}


double sinStart(double x) {
	return x;
}


double sinStep(double x, int n) {
	return -x * x / (2 * (double)n * (2 * (double)n + 1));
}


double cosStart(double x) {
	return 1;
}


double cosStep(double x, int n) {
	return -x * x / (2 * (double)n * (2 * (double)n - 1));
}


// Считать до точности accur (или до n-раз)
double TeylorAccuracy(int n, double accur, double trueVal, Start Clamp, Start first, Step next, double x) {
	int i = 1;
	double res;
	double step;

	x = Clamp(x);
	//printf("%lf\n", x);

	res = first(x);
	step = res * next(x, i);
	res += step;

	while ((i++ < n) && (accur < fabs(res - trueVal))) {
		step = step * next(x, i);
		res += step;
	}
	printf("Рядов рассчитано - %d\n", i - 1);
	return res;
}

/*
// state = 0
void Interface() {
	int ans = 0;
	printf("Выберете режим:\n");
	printf("1) Одиночный вызов.\n");
	//printf("2) Серийный вызов вызов.\n\n");
	printf("2) Выйти.");

	scanf_s("%d", &ans);

	switch (ans) {
	case(1): state = 1; break;
	case(2): state = 255; break;
	case(3): state = 255; break;
	}
}
*/

// запросить n 
int AskNum(char* string) {
	int ans;
	printf(string);
	scanf_s("%d", &ans);
	return ans;
}


double AskDouble(char* string) {
	double ans;
	printf(string);
	scanf_s("%lf", &ans);
	return ans;
}


// state = 1
void NormalMode() {
	double found;
	double find;
	int ans = -1;
	double accurf;
	
	printf("Выберете функцию:\n");
	printf("1) Косинус\n");
	printf("2) Синус\n");
	printf("3) Экспонента\n");
	printf("4) Шинус (\"Гиперболический Синус\")\n");
	printf("5) Чосинус (\"Гиперболический Косинус\")\n\n");
	printf("6) Выйти\n");
	while ((ans < 1) || (ans > 6)) {
		scanf_s("%d", &ans);
	}

	if (ans == 6) {
		state = 255;
		return NULL;
	}
	
	accurf = 1 / pow(10, (double)AskNum("Введите точность ( 10 ^ (-n) )"));
	printf("%lf\n", accurf);
	int n = AskNum("Сколько рядов рассчитать? (0 < n < 121)");
	if (n < 1) {
		n = 0;
	}
	else if (n > 120) {
		n = 120;
	}

	find = AskDouble("Какое значение хотите найти?\n");

	switch (ans) {
	case(1): found = TeylorAccuracy(n, accurf, cos(find), ClampPI, cosStart, cosStep, find);
		printf("Правильное знач - %lf\nПо Тейлору - %lf\nРазница (неточность) - %e", cos(find), found, fabs(cos(find) - found));
		break;
	case(2): found = TeylorAccuracy(n, accurf, sin(find), ClampPI, sinStart, sinStep, find);
		printf("Правильное знач - %lf\nПо Тейлору - %lf\nРазница (неточность) - %e", sin(find), found, fabs(sin(find) - found));
		break;
	case(3): found = TeylorAccuracy(n, accurf, exp(find), NoClamp, expStart, expStep, find);
		printf("Правильное знач - %lf\nПо Тейлору - %lf\nРазница (неточность) - %e", exp(find), found, fabs(exp(find) - found));
		break;
	case(4): found = TeylorAccuracy(n, accurf, sinh(find), NoClamp, ShinusStart, ShinusStep, find);
		printf("Правильное знач - %lf\nПо Тейлору - %lf\nРазница (неточность) - %e", sinh(find), found, fabs(sinh(find) - found));
		break;
	case(5): found = TeylorAccuracy(n, accurf, cosh(find), NoClamp, ChosinStart, ChosinStep, find);
		printf("Правильное знач - %lf\nПо Тейлору - %lf\nРазница (неточность) - %e", cosh(find), found, fabs(cosh(find) - found));
		break;
	}
	state = 0;
}

/*
// state = 2
void SerialMode() {
	AskNum("Добавить текст.");
}
*/

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");

	while (state != 255) {
		printf("\n=================================\n");
		if (state > 1) {
			state = 0;
		}
		switch (state) {
		case(0): NormalMode(); break;
		//case(2): SerialMode(); break;
		}
	}
	printf("Пока");
	return 1;
}