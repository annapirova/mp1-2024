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


double Taylor(double x, int N, First f, Jump h, Next g) {
	double prev, next, summ;
	int i, jump;

	prev = f(x); summ = 0.0;

	jump = h();

	for (i=1; i<N; i+=jump){
		if (i == 1)
			summ += prev;

		else {
			next = prev*g(x, i);
			summ += next;
			prev = next;
		}
	}

	return summ;
}


void First_Mode() {
	int func, N;
	double x, diff;

	printf("\nSelect function\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. Ch(x)\nEnter: ");
	scanf("%d", &func);

	printf("\nInput x: ");
	scanf("%lf", &x);

	printf("Input N: ");
	scanf("%d", &N);

	printf("\n");

	switch (func){
		case 1:
			printf("Taylor: sin(%lf) ~= %lf\n", x, Taylor(x, N, FirstSin, JumpSin, NextSin));
			printf("math.h: sin(%lf) = %lf\n", x, sin(x));

			diff = (sin(x)-Taylor(x, N, FirstSin, JumpSin, NextSin));
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 2:
			printf("Taylor: cos(%lf) ~= %lf\n", x, Taylor(x, N, FirstCos, JumpCos, NextCos));
			printf("math.h: cos(%lf) = %lf\n", x, cos(x));

			diff = (cos(x)-Taylor(x, N, FirstCos, JumpCos, NextCos));
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 3:
			printf("Taylor: exp(%lf) ~= %lf\n", x, Taylor(x, N, FirstExp, JumpExp, NextExp));
			printf("math.h: exp(%lf) = %lf\n", x, exp(x));

			diff = (exp(x)-Taylor(x, N, FirstExp, JumpExp, NextExp));
			if (diff < 0)
				diff = -diff;
				
			printf("Difference = %lf\n", diff);
			break;

		case 4:
			printf("Taylor: Ch(%lf) ~= %lf\n", x, Taylor(x, N, FirstCh, JumpCh, NextCh));
			printf("math.h: Ch(%lf) = %lf\n", x, cosh(x));

			diff = (cosh(x)-Taylor(x, N, FirstCh, JumpCh, NextCh));
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
	double x, diff;
	int i;

	printf("\nSelect function\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. Ch(x)\nEnter: ");
	scanf("%d", &func);

	printf("\nInput x: ");
	scanf("%lf", &x);

	printf("Input max N (<= 25): ");
	scanf("%d", &N_max);

	printf("\n");

	switch (func){
		case 1:
			printf("sin(x):\n");
			for (i=1; i<N_max+1; i++){
				diff = (sin(x)-Taylor(x, i, FirstSin, JumpSin, NextSin));
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, Taylor(x, i, FirstSin, JumpSin, NextSin), sin(x), diff);
			}
			break;

		case 2:
			printf("cos(x):\n");
			for (i=1; i<N_max+1; i++){
				diff = (cos(x)-Taylor(x, i, FirstCos, JumpCos, NextCos));
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, Taylor(x, i, FirstCos, JumpCos, NextCos), cos(x), diff);
			}
			break;

		case 3:
			printf("exp(x):\n");
			for (i=1; i<N_max+1; i++){
				diff = (exp(x)-Taylor(x, i, FirstExp, JumpExp, NextExp));
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, Taylor(x, i, FirstExp, JumpExp, NextExp), exp(x), diff);
			}
			break;

		case 4:
			printf("Ch(x):\n");
			for (i=1; i<N_max+1; i++){
				diff = (cosh(x)-Taylor(x, i, FirstCh, JumpCh, NextCh));
				if (diff < 0)
					diff = -diff;

				printf("(N = %d) Taylor: %lf, math.h: %lf, diff.: %lf\n", i, Taylor(x, i, FirstCh, JumpCh, NextCh), cosh(x), diff);
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
		scanf("%d", &mode);

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
}