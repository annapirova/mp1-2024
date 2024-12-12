#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#define _USE_MATH_DEFINES
#include <math.h> 
typedef double(*TFunc)(double x, int y, double z);
typedef void(*TCase)(TFunc func);
TFunc menu1();

// M_PI 
// if (x > 2*M_PI) --> x < 2*M_PI
struct SUMMA
{
	int k1;
	double k2;
};
struct SUMMA MATH(double User_Error, double x, int n, TFunc function);
double sin1(double x, int i, double element)
{
	double tmp = (-1) * (element * x * x );
	double tmp2 = (2 * i * (2 * i + 1));
	tmp = tmp / tmp2;
	return(tmp);
}
double cos1(double x, int i, double element)
{
	double tmp = (-1) * element * x * x/(( 2 * i )  *( 2 * i - 1));
	return(tmp);
}
double e1(double x, int i, double element)
{
	double tmp = element * x/i;
	return(tmp);
}
double arctg1(double x, int i, double element)
{
	i++;
	double tmp = (-1) * element * (x * x * (2 * i - 3)) / (2 * i - 1);
	return(tmp);
}
double first(TFunc function, double x)
{
	double first_el;
	if (function == &sin1)
	{
		first_el = x;
		return(first_el);
	}
	else if (function == &cos1)
	{
		first_el = 1;
		return(first_el);
	}
	else if (function == &e1)
	{
		first_el = 1;
		return(first_el);
	}
	else if (function == &arctg1)
	{
		first_el = x;
		return(first_el);
	}
}
double reference_value(double x,TFunc function)
{
	double reference_sum = 0;
	if (function == &sin1)
	{
		reference_sum = sin(x);
	}
	else if(function == &cos1)
	{
		reference_sum = cos(x);
	}
	else if (function == &e1)
	{
		reference_sum = e(x);
	}
	else if (function == &arctg1)
	{
		reference_sum = arctg(x);
	}
	return(reference_sum);
}

void choice1( TFunc function)
{
	double x, next_el, sum = 0, User_Error, element, reference_sum = 0;
	int n, i = 0, chislo_slagaemix = 0;
	struct SUMMA ANS;
	printf("Введите точку\n");
	if (function == &sin1 || function == &cos1)
	{
		while (x > 2 * M_PI)
		{
			x -= 2 * M_1_PI;
		}
	}
	scanf_s("%lf", &x);
	printf("Введите число элементов ряда\n");
	scanf_s("%d", &n);
	while (n < 1 || n>1000)
	{
		printf("Введите число элементов ряда повторно\n");
		scanf_s("%d", &n);
	}
	printf("Введите погрешность\n");
	scanf_s("%lf", &User_Error);
	while (User_Error < 0.000001)
	{
		printf("Введите погрешность  повторно\n");
		scanf_s("%lf", &User_Error);
	}
	//
	ANS = MATH(User_Error, x, n, function);
	//
	reference_sum = reference_value(x, function);
	double z = fabs(reference_sum - sum);
	printf("Значение = %lf\n", ANS.k2);
	printf("Разница = %lf\n", z);
	printf("Эталонное значение = %lf\n", reference_sum);//
	printf("Число слагаемых = %d\n", ANS.k1);
}
void choice2(TFunc function)
{
	struct SUMMA ANS;
	double x, next_el, sum = 0, User_Error, element, reference_sum = 0;
	int n, i = 0, chislo_slagaemix = 0, Nmax = 0, m =0;
	printf("Введите число экспериментов\n");
	scanf_s("%d", &Nmax);
	while (Nmax < 1 || Nmax>25)
	{
		printf("Введите число экспериментов повторно\n");
		scanf_s("%d", &Nmax);
	}
	double* a = (double*)malloc(sizeof(double) * Nmax * 4);
	for (int j = 0; j < Nmax; j++)
	{
		printf("Введите точку\n");
		scanf_s("%lf", &x);
		if (function == &sin1 || function == &cos1)
		{
			while (x > 2 * M_PI)
			{
				x -= 2 * M_1_PI;
			}
		}
		printf("Введите погрешность\n");
		scanf_s("%lf", &User_Error);
		printf("Введите число элементов ряда\n");
		scanf_s("%d", &n);
		while (n < 1 || n>1000)
		{
			printf("Введите число элементов ряда повторно\n");
			scanf_s("%d", &n);
		}
		while (User_Error < 0.000001)
		{
			printf("Введите погрешность  повторно\n");
			scanf_s("%lf", &User_Error);
		}
		if (j != 0)
		{
			function = menu1();
		}
		//
		ANS = MATH(User_Error, x, n, function);
		//
		reference_sum = reference_value(x, function);
		double z = fabs(fabs(reference_sum) - fabs(sum));
		a[m] = ANS.k1;
		a[m + 1] = ANS.k2;
		a[m + 2] = z;
		a[m + 3] = x;
		m += 4;
		chislo_slagaemix = 0;
		sum = 0;
		z = 0;
		i = 0;
	}
	printf("|   Число слагаемых       |     Значение функции    |     Разница значений    |          X             |\n");
	for (int i = 1; i <= (Nmax * 4); i++)
	{
		if (i % 4 == 0)
		{
			printf("|        %lf        |\n", a[i-1]);

		}
		else
		{
			printf("|        %lf         ", a[i-1]);
		}
	}
	free(a);
}
TFunc menu1()
{
	int ans1;
	TFunc func =0;
	printf("Выберете функцию\n");
	printf("1.sin\n");
	printf("2.cos\n");
	printf("3.e\n");
	printf("4.arctg\n");
	scanf_s("%d", &ans1);
	while (ans1 < 1 || ans1>4)
	{
		printf("Выберете функцию повторно\n\n");
		scanf_s("%d", &ans1);
	}
	switch (ans1)
	{
		case(1):
		{
			func = sin1;
			break;
		}
		case(2):
		{
			func = cos1;
			break;
		}
		case(3):
		{
			func = e1;
			break;
		}
		case(4):
		{
			func = arctg1;
			break;
		}
	}
	return (func);
}
struct SUMMA MATH(double User_Error, double x, int n, TFunc function)
{
	struct SUMMA ANS;
	ANS.k1 = 0;
	ANS.k2 = 0;
	double element = 0, sum = 0, next_el = 0;
	int chislo_slagaemix = 0, i = 0;
	element = first(function, x);
	sum += element;
	next_el = function(x, i + 1, element);
	while ((i < n - 1) && (fabs(next_el) - fabs(element) < User_Error))
	{
		next_el = function(x, i + 1, element);
		element = next_el;
		//printf("%lf\n",element);
		sum += next_el;
		i++;
		chislo_slagaemix++;
	}
	if (function == &arctg1)
	{
		chislo_slagaemix++;
	}
	ANS.k1 = chislo_slagaemix;
	ANS.k2 = sum;
	return(ANS);
}
TCase menu()
{
	int ans;
	TCase res = 0;
	printf("1 режим\n");
	printf("2 режим\n");
	scanf_s("%d", &ans);
	while (ans < 1 || ans>2)
	{
		scanf_s("%d", &ans);
	}
	switch (ans)
	{
		case(1):
		{
			res = choice1;
			break;
		}
		case(2):
		{
			res = choice2;
			break;
		}
	}
	return (res);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	TFunc function;
	TCase ans;
	function = menu1();
	ans = menu();
	ans(function);
}