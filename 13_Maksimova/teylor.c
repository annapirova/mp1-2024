#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void changefunction() {
    printf("\nВыберите функцию:\n");
    printf("1. Sin\n");
    printf("2. Cos\n");
    printf("3. Exp\n");
    printf("4. Tanh\n");
    printf(">>> ");
}


double FirstSin(double x) {
    return x;
}

double NextSin(double x, int i) {
    return (-x * x / ((i - 1) * i));
}


double FirstCos(double x) {
    return 1;
}

double NextCos(double x, int i) {
    i--;
    return -x * x / ((i - 1) * i);
}


double FirstExp(double x) {
    return 1;
}

double NextExp(double x, int i) {
    i--;
    return x / i;
}


double FirstTanh(double x) {
    return x;
}

int factorial(int n) {
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

double bernulli(int n) {  // bernulli number B(n)
    int k;
    double result = 0.0;
    int C;

    if (n == 0)
        return 1;

    else {
        for (k = 1; k <= n; k++) {
            C = factorial(n + 1) / (factorial(n - k) * factorial(k + 1));
            result += C * bernulli(n - k);
        }
        result = result * (-1.0 / (n + 1));
    }
    return result;
}

double NextTanh(double x, int i) {
    double th1, th2;

    if (i == 2) {
        th1 = ((pow(2, 2 * i) * bernulli(2 * i) * (pow(2, 2 * i) - 1)) / factorial(2 * i)) * (pow(x, 2 * i - 1));
        return (th1 / x);
    }

    th1 = ((pow(2, 2 * i) * bernulli(2 * i) * (pow(2, 2 * i) - 1)) / factorial(2 * i)) * (pow(x, 2 * i - 1));
    th2 = ((pow(2, 2 * (i - 2)) * bernulli(2 * (i - 2)) * (pow(2, 2 * (i - 2)) - 1)) / factorial(2 * (i - 2))) * (pow(x, 2 * (i - 2) - 1));

    return (th1 / th2);
}


typedef double(*First)(double);
typedef double(*Next)(double, int);

double Teylor(double x, int N, First f, Next g, int h, double eps, double res) {
    double prev, next, sum;
    int i = 1, shag;
    sum = 0.0;
    prev = f(x);
    next = 0;
    shag = h;

    while ((fabs(sum - res) > eps) && (i < N)) {
        if (i == 1)
            sum += prev;
        else {
            next = prev * g(x, i);
            sum += next;
            prev = next;
        }
        i += shag;
    }

    printf("Эталонное значение: %lf \n", res);
    printf("Вычисленная оценка значения: %lf \n", sum);
    printf("Разница между оценкой и эталонным значением: %lf \n", fabs(res - sum));
    printf("Количество слагаемых,которое было вычислено: %d \n\n", i - 1);
    return sum;
}


double Teylor2(double x, int N, First f, Next g, int h, double res) {
    double prev, next, sum;
    int i = 1, shag;
    sum = 0.0;
    prev = f(x);
    next = 0;
    shag = h;

    printf("\nЭталонное значение: %lf \n\n", res);

    while (N >= i) {
        if (i == 1)
            sum += prev;
        else {
            next = prev * g(x, i);
            sum += next;
            prev = next;
        }
        printf("(N = %d) Вычисленная оценка значения: %lf \n", i, sum);
        printf("(N = %d) Разница между оценкой и эталонным значением: %lf \n\n", i, fabs(res - sum));
        i += shag;
    }
    return sum;
}


void main() {
    setlocale(LC_ALL, "Rus");
    int N;
    double eps;
    double x;
    double y;
    int choice;
    int mode = -1;

    while (mode != 3) {
        printf("CВыберите режим:\n");
        printf("1. Однократный расчет\n");
        printf("2. Серийный расчет\n");
        printf("3. Выход\n");
        scanf_s("%d", &mode);

        if (mode == 3) {
            printf("Пока!\n");
            break;
        }

        do {
            changefunction();
            scanf_s("%d", &choice);
            printf("\n");
        } while ((choice < 1) || (choice > 4));


        if (choice == 4) {
            printf("\n(!) tanh(x): -0.5 <= x <= 0.5\n");
            do {
                printf("Введите x: \n");
                scanf_s("%lf", &x);
            } while ((x < -0.5) || (x > 0.5));
        }

        else {
            printf("Введите x: \n");
            scanf_s("%lf", &x);
        }


        if (choice == 4) {
            printf("\n(!) tanh(x): N <= 10\n");
            do {
                printf("Введите N: \n");
                scanf_s("%d", &N);
            } while (N > 10);
        }

        else {
            printf("Введите N(<= 50):\n");
            scanf_s("%d", &N);
        }


        if (mode == 1) {
            printf("Введите точность вычислений: \n");
            scanf_s("%lf", &eps);
        }


        if ((choice == 1) || (choice == 2)) {
            if (fabs(x) == x)
                while (fabs(x) > 2 * M_PI)
                    x = x - 2 * M_PI;
            else
                while (fabs(x) > 2 * M_PI)
                    x = x + 2 * M_PI;
        }

        printf("\n");

        if (mode == 1) {
            switch (choice) {
            case 1:
                y = Teylor(x, N, FirstSin, NextSin, 2, eps, sin(x));
                break;
            case 2:
                y = Teylor(x, N, FirstCos, NextCos, 2, eps, cos(x));
                break;
            case 3:
                y = Teylor(x, N, FirstExp, NextExp, 1, eps, exp(x));
                break;
            case 4:
                y = Teylor(x, N, FirstTanh, NextTanh, 1, eps, tanh(x));
                break;
            default:
                printf("Неверный выбор\n");
                continue;
            }
        }


        if (mode == 2) {
            switch (choice) {
            case 1:
                y = Teylor2(x, N, FirstSin, NextSin, 2, sin(x));
                break;
            case 2:
                y = Teylor2(x, N, FirstCos, NextCos, 2, cos(x));
                break;
            case 3:
                y = Teylor2(x, N, FirstExp, NextExp, 1, exp(x));
                break;
            case 4:
                y = Teylor2(x, N, FirstTanh, NextTanh, 1, tanh(x));
                break;
            default:
                printf("Неверный выбор\n");
                continue;
            }
        }
    }
}
