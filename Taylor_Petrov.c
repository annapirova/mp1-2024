#include <stdio.h>
#include <math.h>

typedef double (First)(double);
typedef double (Next)(double, int);

//First
double First_exp(double x)
{
	return 1;
}
double First_sin(double x)
{
	return x;
}

double First_cos(double x)
{
	return 1;
}

double First_cosh(double x)
{
	return 1;
}
//Next
double Next_exp(double x, int n)
{
	return x/n;
}
double Next_sin(double x, int n)
{
	return (-(x * x))/((2*n)*(2*n+1));
}

double Next_cos(double x, int n)
{
	return (-(x * x)) / ((2 * n) * (2 * n - 1));
}

double Next_cosh(double x, int n)
{
	return x / (2 * n);
}

void function_list()
{
	printf("1.Exp\n");
	printf("2.Sin\n");
	printf("3.Cos\n");
	printf("4.Cosh\n");
}

double Taylor(double x, int N, double etalon, double tochhonst, First first, Next next)
{
	double elem, elem_next, result;
	double check = 1.0;
	int i;
	elem = first(x);
	result = elem;
	for (i = 1; (i < N) && !(check < tochhonst); i++)
	{
		elem_next = elem * next(x, i);
		result += elem_next;
		elem = elem_next;
		check = fabs(result - etalon);
	}
	printf("----------\n");
	printf("Result: %lf\n", result);
	printf("Etalon is %lf\n", etalon);
	printf("Raznica is %lf\n", fabs(etalon - result));
	printf("Slgaaemo is %d\n", i);
	printf("----------\n");
	return result;
}

int main()
{
	int mode = 0;
	int function = 0;
	double x = 0;
	int N = 0;
	double tochhonst;
	int Nmax = 0;
	int i;
	while(1==1)
	{
		printf("Choose mode (1 - default mode 1; 2 - seria mode)(-1 to Exit.)\n");
		scanf_s("%d", &mode);
		if (mode == -1)
			break;
		printf("Choose function\n");
		function_list();
		scanf_s("%d", &function);
		printf("Enter x\n");
		scanf_s("%lf", &x);
		printf("Enter tochhonst:\n");
		scanf_s("%lf", &tochhonst);
		if (mode == 1)
		{
			printf("Enter N\n");
			scanf_s("%d", &N);
			switch (function)
			{
			case 1:
				Taylor(x, N, exp(x), tochhonst, First_exp, Next_exp);
				break;
			case 2:
				Taylor(x, N, sin(x), tochhonst, First_sin, Next_sin);
				break;
			case 3:
				Taylor(x, N, cos(x), tochhonst, First_cos, Next_cos);
				break;
			case 4:
				Taylor(x, N, cosh(x), tochhonst, First_cosh, Next_cosh);
				break;
			}
		}
		else
		{
			printf("Enter Nmax\n");
			scanf_s("%d", &Nmax);
			for (i = 1; i <= Nmax; i++)
			{
				switch (function)
				{
				case 1:
					Taylor(x, i, exp(x), tochhonst, First_exp, Next_exp);
					break;
				case 2:
					Taylor(x, i, sin(x), tochhonst, First_sin, Next_sin);
					break;
				case 3:
					Taylor(x, i, cos(x), tochhonst, First_cos, Next_cos);
					break;
				case 4:
					Taylor(x, i, cosh(x), tochhonst, First_cosh, Next_cosh);
					break;
				}
			}
		}
	}
	return 0;
}
