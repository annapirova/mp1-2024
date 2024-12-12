#include "stdio.h"
#include "math.h"
#include "locale.h"

typedef double(*First)(double);
typedef double(*Next)(double, int);
typedef double(*Check)(double, double, int,double);

int fq(int a) {
	int k=1,q=1;
	if (a == 0) {
		return 1;
	}
	else{
		while (q <= a) {
			k *= q;
			a--;
		}
		return k;
	}
}
double FirstSin(double x) {
	return x;
}

double FirstCos(double x) {
	return 1;
}
double FirstExp(double x) {
	return 1;
}
double FirstLog(double x) {
	return x ;
}
double NextSin(double x, int i) {
	return -x * x / (2 * i) / (2 * i + 1);
}
double NextCos(double x, int i) {
	return (-(x * x) / ((2 * i) * (2 * i-1)));
}
double NextExp(double x, int i) {
	return (x / i);
}
double NextLog(double x, int i) {
	return ( - x / i);
}

double true(double x,int type) {
	if (type == 1 || type == 2) {
		while (x > 6.28 || x < -6.28) {
			x -= 6.28;
		}
	}
	return x;
}

void ch(int i) {
	printf("\nВведите N:");
	scanf_s("%d", &i);
}
void inpX(double x) {
	printf("Введите значение x=");
	scanf_s("%lf", &x);
}
double Check_e(int type, double x, double t,double eps) {
	if (type == 1) {
		return (fabs(t - sin(x)));
	}
	else if (type == 2) {
		return (fabs(t - cos(x)));
	}
	else if (type == 3) {
		return (fabs(t - exp(x)));
	}
	else if (type == 4) {
		return (fabs(t - log(x+1)));
	}
	
}
double Tey(double x, int n, First f, Next g, double eps, int type_func, Check z,int *count, double val) {
	double x1 = true(x,type_func);
	double t = f(x1);
	double elem;
	double prew = f(x1);
	int i = 1;
	while (i < n && (fabs(t - val) > eps)) {
		elem = prew * g(x1, i);
		t += elem;
		prew = elem;		
		*count +=1;
		i++;
	}
	return t;
}


int main() {
	setlocale(LC_ALL, "Rus");
	double x, eps,t;
	int type,n,count=1;
	printf("Выберите функцию\n1)Sin(x)\n2)Cos(x)\n3)Exp(x)\n4)ln(x+1)\nВведите:");
	scanf_s("%d", &type);
	while (type>4 && type<1) {
		printf("\nНеверный ввод\n");
		printf("Выберите функцию\n1)Sin(x)\n2)Cos(x)\n3)Exp(x)\n4)ln(x)\nВведите:");
		scanf_s("%d", &type);
	}
	printf("Введите точность вычисления =");
	scanf_s("%lf", &eps);
	//while(eps>0.1 || eps<0.0001){
	//	printf("\nНеверный ввод\n");
	//	printf("Введите точность вычисления (0,1 до 0,0001)=");
	//	scanf_s("%lf", &eps);;
	//}
	printf("Введите N:");
	scanf_s("%d", &n);
	while (n <= 0) {
		printf("\nНеверный ввод\n");
		printf("Введите N:");
		scanf_s("%d", &n);
	}
	
	if (type == 4) {

		printf("\n-1<x<=1\nВведите x=");
		scanf_s("%lf", &x);
		if (x > 1 || x < -1) {
			return 1;
		}
	}
	else {
		printf("Введите x=");
		scanf_s("%lf", &x);
	}
	switch (type) {
	case 1:
		
		double f=Tey(x, n, FirstSin, NextSin, eps, type, Check_e,&count, sin(x));
		printf("Эталонное значениe=%lf\nВычисленное значение=%lf\nРазличие между значениями=%lf\nКоличество слагаемых=%d\n", sin(x), f, fabs(f - sin(x)), count);
		break;
	case 2:
		double f1 = Tey(x, n, FirstCos, NextCos, eps, type, Check_e, &count, cos(x));
		printf("Эталонное значениe=%lf\nВычисленное значение=%lf\nРазличие между значениями=%lf\nКоличество слагаемых=%d\n", cos(x), f1, fabs(f1 - cos(x)), count);
		break;
	case 3:
		double f2 = Tey(x, n, FirstExp, NextExp, eps, type, Check_e, &count, exp(x));
		printf("Эталонное значениe=%lf\nВычисленное значение=%lf\nРазличие между значениями=%lf\nКоличество слагаемых=%d\n", exp(x), f2, fabs(f2 - exp(x)), count);
		break;
	case 4:
		double f3 = Tey(x, n, FirstLog, NextLog, eps, type, Check_e, &count, log(x+1));
		printf("Эталонное значениe=%lf\nВычисленное значение=%lf\nРазличие между значениями=%lf\nКоличество слагаемых=%d\n", log(x+1), f3, fabs(f3 - log(x+1)), count);
		break;
	}

	

	return 0;
}


/*int main1() {
	setlocale(LC_ALL, "Rus");
	printf("1.Однократный расчет функции в заданной точке.\n2.Серийный эксперимент.");
	printf("\nВведите вариант=");
	int c;
	scanf_s("%d", &c);
	if (c==1)
	{
		printf("\nЗадайте точку вычисления x=");
		double x;
		scanf_s("%lf", &x);
		printf("\nЗадайте точность вычисления (знаков после запятой)=");
		int t;
		scanf_s("%d", &t);
		printf("\nЧисло элементов ряда для вычисления (от 1 до 1000) =");
		double l;
		scanf_s("%lf", &l);
		printf("\nВыберите функцию: \n1.Cos(x) \n2.Sin(x) \n3.Exp(x)\n4.ln(x)\nВведите=");
		int c1;
		scanf_s("%d", &c1);
		switch (c1) {
		case (1):
			double p = cosinus(x, l);
			double p1 = cos(x);
			double dp = fabs(p - p1);
			printf("\nВычисленное значение = %*.*lf\nЭталонное значение = %*.*lf\nРазница = %f\n", t + 1, t, p, t + 1, t, p1, dp);
			break;
		case (2):
			double p2 = sinus(x, l);
			double p3 = sin(x);
			double dp1 = fabs(p2 - p3);
			printf("\nВычисленное значение = %*.*lf\nЭталонное значение = %*.*lf\nРазница = %f", t + 1, t, p2, t + 1, t, p3, dp1);
			break;
		case (3):
			double p4 = expa(x, l);
			double p5 = exp(x);
			double dp2 = fabs(p4 - p5);
			printf("\nВычисленное значение = %*.*lf\nЭталонное значение = %*.*lf\nРазница = %f", t + 1, t, p4, t + 1, t, p5, dp2);
			break;
		case (4):
			double p6 = logi(x, l);
			double p7 = log(x);
			double dp3 = fabs(p6 - p7);
			printf("\nВычисленное значение = %*.*lf\nЭталонное значение = %*.*lf\nРазница = %f", t + 1, t, p6, t + 1, t, p7, dp3);
			break;
		}
	}
	else if(c == 2) {
		printf("\nЗадайте точку вычисления x=");
		double x;
		scanf_s("%lf", &x);
		printf("\nКоличество экспериментов (от 1 до 25)=");
		double l;
		scanf_s("%lf", &l);
		printf("\nВыберите функцию: \n1.Cos(x) \n2.Sin(x) \n3.Exp(x)\n4.ln(x)\nВведите=");
		int c1;
		scanf_s("%d", &c1);
		switch (c1) {
		case (1):
			printf("\nРяд ТейлОра\n");
			for (int i = 1; i < l; i++) {
				double pdidi = cosinus(x, i);
				printf(" %lf ", pdidi);
			}
			printf("\nЭталонное значение\n");
			double pdidi = cos(x);
			printf(" %lf ", pdidi);
			printf("\nРазница с эталонным значением\n");
			for (int i = 1; i < l; i++) {
				double pdidi = cos(x), pdidi1 = cosinus(x, i);
				double pdelta = fabs(pdidi - pdidi1);
				printf(" %lf ", pdelta);
			}
			printf("\n");
			break;
		case (2):
			printf("\nРяд ТейлОра\n");
			for (int i = 1; i < l; i++) {
				double pdidi = sinus(x, i);
				printf(" %lf ", pdidi);
			}
			printf("\nЭталонное значение\n");
			double etal = sin(x);
			printf(" %lf ", etal);
			printf("\nРазница с эталонным значением\n");
			for (int i = 1; i < l; i++) {
				double et = sin(x), pdidi1 = sinus(x, i);
				double pdelta = fabs(et - pdidi1);
				printf(" %lf ", pdelta);
			}
			printf("\n");
			break;
		case(3):
			printf("\nРяд ТейлОра\n");
			for (int i = 1; i < l; i++) {
				double pdidi = expa(x, i);
				printf(" %lf ", pdidi);
			}
			printf("\nЭталонное значение\n");
			double eta = exp(x);
			printf(" %lf ", eta);
			printf("\nРазница с эталонным значением\n");
			for (int i = 1; i < l; i++) {
				double ski = exp(x), pdidi1 = expa(x, i);
				double pdelta = fabs(ski - pdidi1);
				printf(" %lf ", pdelta);
			}
			printf("\n");
			break;
		case(4):
			printf("\nРяд ТейлОра\n");
			for (int i = 1; i < l; i++) {
				double pdidi = logi(x, i);
				printf(" %lf ", pdidi);
			}
			printf("\nЭталонное значение\n");
			double elo = log(x);
			printf(" %lf ", elo);
			printf("\nРазница с эталонным значением\n");
			for (int i = 1; i < l; i++) {
				double rt = log(x), pdidi1 = logi(x, i);
				double pdelta = fabs(rt - pdidi1);
				printf(" %lf ", pdelta);
			}
			printf("\n");
			break;
		}
	}
}*/