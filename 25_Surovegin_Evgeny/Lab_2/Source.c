#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include <math.h> 
typedef double(*TFunc)(double x, int y, double z);
typedef void(*TCase)(TFunc func);
TFunc menu1();
double sin(double x, int i, double element)
{
	double tmp = (-1) * (element * x * x );
	double tmp2 = (2 * i * (2 * i + 1));
	tmp = tmp / tmp2;
	return(tmp);
}
double cos(double x, int i, double element)
{
	double tmp = (-1) * element * x * x/(( 2 * i )  *( 2 * i - 1));
	return(tmp);
}
double e(double x, int i, double element)
{
	double tmp = element * x/i;
	return(tmp);
}
double arctg(double x, int i, double element)
{
	i++;
	double tmp = (-1) * element * (x * x * (2 * i - 3)) / (2 * i - 1);
	return(tmp);
}
double first(TFunc function, double x)
{
	double first_el;
	if (function == &sin)
	{
		first_el = x;
		return(first_el);
	}
	else if (function == &cos)
	{
		first_el = 1;
		return(first_el);
	}
	else if (function == &e)
	{
		first_el = 1;
		return(first_el);
	}
	else if (function == &arctg)
	{
		first_el = x;
		return(first_el);
	}
}
double reference_value(double x, TFunc function)
{
	double  next_el, element, reference_sum = 0;
	element = first(function, x);
	reference_sum += element;
	for (int i = 0; i < 100; i++)
	{
		next_el = function(x, i + 1, element);
		element = next_el;
		reference_sum += next_el;
	}
	return(reference_sum);
}
void choice1( TFunc function)
{
	double x, next_el, sum = 0, User_Error, element, reference_sum = 0;
	int n, i = 0, chislo_slagaemix = 0;
	printf("Введите точку\n");
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
	element = first(function,x);
	sum += element;
	next_el = function(x, i + 1, element);
	while ((i < n-1) && (fabs(next_el) - fabs(element) < User_Error))
	{
		next_el = function(x, i + 1, element);
		element = next_el;
		printf("%lf\n",element);
		sum += next_el;
		i++;
		chislo_slagaemix++;
	}
	if (function == &arctg)
	{
		chislo_slagaemix++;
	}
	reference_sum = reference_value(x, function);
	double z = fabs(fabs(reference_sum) - fabs(sum));
	printf("Значение = %lf\n", sum);
	printf("Разница = %lf\n", z);
	printf("Эталонное значение = %lf\n", reference_sum);
	printf("Число слагаемых = %d\n", chislo_slagaemix);
}
void choice2(TFunc function)
{
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
		element = first(function, x);
		sum += element;
		next_el = function(x, i + 1, element);
		while ((i < n - 1) && (fabs(next_el) - fabs(element) < User_Error))
		{
			next_el = function(x, i + 1, element);
			element = next_el;
			sum += next_el;
			i++;
			chislo_slagaemix++;
		}
		if (function == &arctg)
		{
			chislo_slagaemix++;
		}
		reference_sum = reference_value(x, function);
		double z = fabs(fabs(reference_sum) - fabs(sum));
		a[m] = chislo_slagaemix;
		a[m + 1] = sum;
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
			func = sin;
			break;
		}
		case(2):
		{
			func = cos;
			break;
		}
		case(3):
		{
			func = e;
			break;
		}
		case(4):
		{
			func = arctg;
			break;
		}
	}
	return (func);
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