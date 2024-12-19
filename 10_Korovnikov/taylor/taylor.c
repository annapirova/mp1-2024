#define _USE_MATH_DEFINES
#include "stdlib.h"
#include "stdio.h"
#include "math.h"



int menu()
{
	printf("Vibirite rejim: \n1. Odnokratniy raschet\n2. Serijniy experiment\n");
}

int menu2()
{
	printf("\nVibirite function: \n1. SIN()\n2. COS()\n3. EXP\n4. CTG()\n");
}

void VVOD1(double* c, int* d, double* z)
{
	int  b; double a, q;
	printf("\nZadayte X:\n->"); scanf_s("%lf", &a);
	printf("Zadayte chislo elementov:\n->"); scanf_s("%d", &b);
	printf("Zadayte tochnost:\n->"); scanf_s("%lf", &q);
	*c = a; *d = b; *z = q;
}

double FirstSin(double x)
{
	return x;
}

double NextSin(double x, int i)
{
	return (-x * x) / (i * (i + 1));
}
int vozrSin()
{
	return 2;
}

double FirstCos(double x)
{
	return 1;
}

double NextCos(double x, int i)
{
	return (-x * x) / (i * (i - 1));
}
int vozrCos()
{
	return 2;
}
double FirstExp(double x)
{
	return 1;
}

double NextExp(double x, int i)
{
	return x / i ;
}

int vozrExp()
{
	return 1;
}
typedef double(First)(double);
typedef double(Next) (double, int);
typedef int(vozr)();

double Tayleer(double x, int N, First f, Next g, vozr q, double fuun, double eps)
{
	double summ = f(x), prew = f(x), next; int rost = q();
	for (int i = 1; (i < N) && (fabs(fuun - summ) > eps); i += rost) 
	{
		next = prew * g(x,  i);
		summ += next; prew = next; 
	}
	return summ;
}


double Tayler(double x, int N, First f, Next g, vozr q, double fuun, double eps)
{
	double summ = f(x), prew = f(x), next; int rost = q(); int i = 2;
	while ((i < N) && (fabs(fuun - summ) > eps)) 
	{
		next = prew * g(x, i);
		summ += next; prew = next;
		i += rost;
	}
	return summ;
}


void Odnokratni(int a)
{
	int d,len=2,z=-100; double h, c, razn, eps,fuun;
	double* s = &c; int* q = &d; double* li = &eps;
	switch (a)
	{
	case 1: 
	{
		VVOD1(s, q,li);
		printf("~~~~~~~~~~\nx = %lf\nchislo el-v = %d\ntochnost = %lf\n~~~~~~~~~~", c, d,eps); while (c > 2 * M_PI) { c = c - 2 * M_PI; }
		h = Tayler(c, d, FirstSin, NextSin, vozrSin,sin(c),eps);
		printf("\nSin(%lf) ~= %lf", c, h);
		printf("\nreally Sin(%lf) = %lf", c, sin(c));
		razn = h - sin(c); if (razn < 0) razn = razn * (-1);
		printf("\nRaznica = %lf", razn); break;
		
	
	break; }
	case 2: {
		VVOD1(s, q,li);
		printf("~~~~~~~~~~\nx = %lf\nchislo el-v = %d\ntochnost = %lf\n~~~~~~~~~~", c, d,eps); while (c > 2 * M_PI) { c = c - 2 * M_PI; }
		h = Tayler(c, d, FirstCos, NextCos, vozrCos,cos(c),eps);
		printf("\nCos(%lf) ~= %lf", c, h);
		printf("\nreally Cos(%lf) = %lf", c, cos(c));
		razn = h - cos(c); if (razn < 0) razn = razn * (-1);
		printf("\nRaznica = %lf", razn);
		break; }
	case 3: {
		VVOD1(s, q,li);
		printf("~~~~~~~~~~\nx = %lf\nchislo el-v = %d\ntochnost = %lf\n~~~~~~~~~~", c, d,eps);
		h = Tayleer(c, d, FirstExp, NextExp, vozrExp, exp(c), eps);
		printf("\nExp(%lf) ~= %lf", c, h);
		printf("\nreally Exp(%lf) = %lf", c, exp(c));
		razn = h - exp(c); if (razn < 0) razn = razn * (-1);
		printf("\nRaznica = %lf", razn); 
		break; }
	case 4: {
		VVOD1(s, q,li);
		printf("~~~~~~~~~~\nx = %lf\nchislo el-v = %d\ntochnost = %lf\n~~~~~~~~~~", c, d,eps); while (c > M_PI) { c = c - M_PI; }
		h = (Tayler(c, len, FirstCos, NextCos, vozrCos,cos(c),eps) / Tayler(c, len, FirstSin, NextSin, vozrSin,sin(c),eps));
		printf("\nCtg(%lf) ~= %lf", c, h);
		printf("\nreally Ctg(%lf) = %lf", c, exp(c));
		razn = h - 1 / (tan(c)); if (razn < 0) razn = razn * (-1);
		printf("\nRaznica = %lf", razn); break; }
	}
}

void Serijniy(int a) 
{
	int d, l, len = 2, z = -100, sss; double h, c, razn;
	printf("\n");
	switch (a)
	{
	case 1:
	{
		printf("Zadayte x:\n->"); scanf_s("%lf", &c); while (c > 2 * M_PI) { c = c - 2 * M_PI; }
		printf("Do skolki slagaemix?(ne bol.25)\n->"); scanf_s("%d", &l);
		printf("really sin(%lf) = %lf\n", c, sin(c));
		for (int i = 1; i < l; i += 2)
		{
			h = Tayler(c, i, FirstSin, NextSin, vozrSin,sin(c),0); printf("Znachenie - %lf", h);
			razn = Tayler(c, i, FirstSin, NextSin, vozrSin,sin(c),0) - sin(c); if (razn < 0) razn = razn * (-1);
			printf("  Raznica = %lf", razn); printf("\n");
		}

		break;
	}

	case 2:
	{
		printf("Zadayte x:\n->"); scanf_s("%lf", &c); while (c > 2 * M_PI) { c = c - 2 * M_PI; }
		printf("Do skolki slagaemix?(ne bol.25)\n->"); scanf_s("%d", &l);
		printf("really cos(%lf) = %lf\n", c, cos(c));
		for (int i = 1; i < l; i += 2)
		{
			h = Tayler(c, i, FirstCos, NextCos, vozrCos,cos(c),0); printf("Znachenie - %lf", h);
			razn = Tayler(c, i, FirstCos, NextCos, vozrCos,cos(c),0) - cos(c); if (razn < 0) razn = razn * (-1);
			printf("  Raznica = %lf", razn); printf("\n");
		}

		break;

	}
	case 3:
	{
		printf("Zadayte x:\n->"); scanf_s("%lf", &c);
		printf("Do skolki slagaemix?(ne bol.25)\n->"); scanf_s("%d", &l);
		printf("really Exp(%lf) = %lf\n", c, exp(c));
		for (int i = 1; i < l; i += 2)
		{
			h = Tayleer(c, i, FirstExp, NextExp, vozrExp,exp(c),0); printf("Znachenie - %lf", h);
			razn = Tayleer(c, i, FirstExp, NextExp, vozrExp,exp(c),0) - exp(c); if (razn < 0) razn = razn * (-1);
			printf("  Raznica = %lf", razn); printf("\n");
		}

		break;
	}
	case 4:
	{
		printf("Zadayte x:\n->"); scanf_s("%lf", &c);
		printf("Do skolki slagaemix?(ne bol.25)\n->"); scanf_s("%d", &l);
		printf("really Ctg(%lf) = %lf\n", c, 1/(tan(c)));
		for (int i = 1; i < l; i += 2)
		{
			h = (Tayler(c, i, FirstCos, NextCos, vozrCos,cos(c),0) / Tayler(c, i, FirstSin, NextSin, vozrSin,sin(c),0)); printf(" Znachenie - %lf", h);
			razn = (Tayler(c, i, FirstCos, NextCos, vozrCos,cos(c),0) / Tayler(c, i, FirstSin, NextSin, vozrSin,sin(c),0)) - 1 / (tan(c)); if (razn < 0) razn = razn * (-1);
			printf(" Raznica = %lf", razn);
		}

		break;
	}
	}
}

int main()
{
	int a = -100, b = -100;
	printf("Hello!\n");
	menu();
	while (a != 1 && a != 2) 
	{
		printf("->");
		scanf_s("%d", &a);
		switch (a)
		{
		case 1: { printf("-----Odnokratniy raschet-----"); menu2(); break; }
		case 2: { printf("-----Serijniy experiment-----"); menu2(); break; }
		default:
			printf("Net takogo rejima, vvedite zanogo:\n");
			break;
		}
	}
	while (b != 1 && b != 2 && b != 3 && b != 4)
	{
		printf("->");
		scanf_s("%d", &b);
		switch (b)
		{
		case 1: { printf("----------SIN()----------");  break; }
		case 2: { printf("----------COS()----------");  break; }
		case 3: { printf("----------EXP----------");  break; }
		case 4: { printf("----------CTG()----------");  break; }
		default:
			printf("Net takoy function, vvedite zanogo:\n");
			break;
		}
	}
	if (a == 1) Odnokratni(b);
	else Serijniy(b);
}