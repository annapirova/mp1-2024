#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double FirstSin(double x) {
	return x;
}

int JumpSin(){  // шаг в цикле
	return 2;
}

double NextSin(double x, int i) {
	return -x*x/((i-1)*i);
}


double FirstCos(double x) {
	return 1;
}

int JumpCos(){
	return 2;
}

double NextCos(double x, int i) {
	i--;
	return -x*x/((i-1)*i);
}


double FirstExp(double x) {
	return 1;
}

int JumpExp(){
	return 1;
}

double NextExp(double x, int i) {
	i--;
	return x/i;
}


double FirstCh(double x) {
	return 1;
}

int JumpCh(){
	return 2;
}

double NextCh(double x, int i) {
	i--;
	return x*x/((i-1)*i);
}


typedef double (First)(double);
typedef int (Jump)();
typedef double (Next)(double, int);


double Taylor(double x, int N, double acc, double etalon, First f, Jump h, Next g) {
	double prev, next, summ;
	int i, jump;

	prev = f(x); summ = 0.0;

	jump = h();

	summ += prev;
	i = 1 + jump;

//	for (i = 1; (i < N) && (fabs(summ - etalon) > acc); i++)

	while ((i < N) && (fabs(summ - etalon) > acc)) {
		next = prev * g(x, i);
		summ += next;
		prev = next;

		i+=jump;
	}
	printf("Amount of terms: %d\n\n", i);

	return summ;
}


void First_Mode() {
	int func, N;
	double tayl, x, diff, acc;

	printf("\nSelect function\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. Ch(x)\nEnter: ");
	scanf_s("%d", &func);

	printf("\nInput x: ");
	scanf_s("%lf", &x);
	
	if (func == 1 || func == 2) {
		if (fabs(x) == x)
			while (fabs(x)>2*M_PI)
				x = x-2*M_PI;
		else
			while (fabs(x)>2*M_PI)
				x = x+2*M_PI;
	}

	printf("Input N: ");
	scanf_s("%d", &N);

	printf("Input accuracy: ");
	scanf_s("%lf", &acc);

	printf("\n");

	switch (func){
		case 1:
			tayl = Taylor(x, N, acc, sin(x), FirstSin, JumpSin, NextSin);
			printf("Taylor: sin(%lf) ~= %lf\n", x, tayl);
			printf("math.h: sin(%lf) = %lf\n", x, sin(x));

			diff = (sin(x)-tayl);
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 2:
			tayl = Taylor(x, N, acc, cos(x), FirstCos, JumpCos, NextCos);
			printf("Taylor: cos(%lf) ~= %lf\n", x, tayl);
			printf("math.h: cos(%lf) = %lf\n", x, cos(x));

			diff = (cos(x)-tayl);
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 3:
			tayl = Taylor(x, N, acc, exp(x), FirstExp, JumpExp, NextExp);
			printf("Taylor: exp(%lf) ~= %lf\n", x, tayl);
			printf("math.h: exp(%lf) = %lf\n", x, exp(x));

			diff = (exp(x)-tayl);
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 4:
			tayl = Taylor(x, N, acc, cosh(x), FirstCh, JumpCh, NextCh);
			printf("Taylor: Ch(%lf) ~= %lf\n", x, tayl);
			printf("math.h: Ch(%lf) = %lf\n", x, cosh(x));

			diff = (cosh(x)-tayl);
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		default:
			printf("Function is not defined\n");
			break;
	}
	printf("\n");
}


void Second_Mode() {
	int func, N_max;
	double x, diff, tayl, acc;
	int i;

	printf("\nSelect function\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. Ch(x)\nEnter: ");
	scanf_s("%d", &func);

	printf("\nInput x: ");
	scanf_s("%lf", &x);

	if (func == 1 || func == 2) {
		if (fabs(x) == x)
			while (fabs(x) > 2 * M_PI)
				x = x - 2 * M_PI;
		else
			while (fabs(x) > 2 * M_PI)
				x = x + 2 * M_PI;
	}

	printf("Input max N (<= 25): ");
	scanf_s("%d", &N_max);

	printf("Input accuracy: ");
	scanf_s("%lf", &acc);

	printf("\n");

	switch (func){
		case 1:
			printf("sin(x):\n");
			for (i=1; i<N_max+1; i++){
				tayl = Taylor(x, i, acc, sin(x), FirstSin, JumpSin, NextSin);
				diff = (sin(x)-tayl);
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, tayl, sin(x), diff);
			}
			break;

		case 2:
			printf("cos(x):\n");
			for (i=1; i<N_max+1; i++){
				tayl = Taylor(x, i, acc, cos(x), FirstCos, JumpCos, NextCos);
				diff = (cos(x)-tayl);
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, tayl, cos(x), diff);
			}
			break;

		case 3:
			printf("exp(x):\n");
			for (i=1; i<N_max+1; i++){
				tayl = Taylor(x, i, acc, exp(x), FirstExp, JumpExp, NextExp);
				diff = (exp(x)-tayl);
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, tayl, exp(x), diff);
			}
			break;

		case 4:
			printf("Ch(x):\n");
			for (i=1; i<N_max+1; i++){
				tayl = Taylor(x, i, acc, cosh(x), FirstCh, JumpCh, NextCh);
				diff = (cosh(x)-tayl);
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, tayl, cosh(x), diff);
			}
			break;

		default:
			printf("Function is not defined\n");
			break;
	}
	printf("\n");
}


void main(){
	int mode=3;
	
	while (mode != 0){
		printf("===============\nSelect mode\n1. First mode\n2. Second mode\n0. Exit\nEnter: ");
		scanf_s("%d", &mode);

		switch (mode) {
			case 1:
				First_Mode();
				break;

			case 2:
				Second_Mode();
				break;

			case 0:
				printf("Bye!\n");
				mode = 0;
				break;
	
			default:
				printf("Command is not defined\n");
				break;
		}
	}
}//goida