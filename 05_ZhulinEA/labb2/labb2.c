#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <locale.h>
#include <windows.h>


typedef double(*First)(double);
typedef double(*Next)(double, int);
typedef int(*Jump)();
#define and &&
#define or ||

double FirstSin(double x) {
    return x;
}

int JumpSin() { 
    return 2;
}

double NextSin(double x, int i) {
    return -x * x / ((i - 1) * i);
}

double FirstCos(double x) {
    return 1;
}

int JumpCos() {
    return 2;
}

double NextCos(double x, int i) {
    i--;
    return -x * x / ((i - 1) * i);
}


double FirstExp(double x) {
    return 1;
}

int JumpExp() {
    return 1;
}

double NextExp(double x, int i) {
    i--; 
    return x / i;
}
double FirstSh(double x) {
    return x;
}
int JumpSh() {
    return 2;
}
double NextSh(double x, int i) {
    return -x * x / ((i - 1) * i);
}


double Taylor(double x, int n, First f, Jump h, Next g) {
    double prev, next;
    int jump; 
    double summ = 0.0;
    prev = f(x);
    jump = h();
    summ = prev;
    for (int i = 1+jump; i < n + 1; i+=jump) {
        
            next = prev * g(x, i);
            summ += next; 
            prev = next;
        
    }
    return summ;
}
void FirstMode() {
    int func, n;
    double x, delta;

    printf("\nSelect function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. sh(x)\n");
    scanf_s("%d", &func);

    printf("\nInput x: ");
    scanf_s("%lf", &x);

    printf("Input N: ");
    scanf_s("%d", &n);

    switch (func) {
    case 1:
        while (x > 2 * 3.141592653589){
        x = x - 2 * 3.141592653589;}
        printf("Teylor: sin(%lf) ~ %lf\n", x, Taylor(x, n, FirstSin,JumpSin,NextSin));
        printf("math.h: sin(%lf) = %lf\n", x, sin(x));
        delta = fabs(sin(x) - Taylor(x, n, FirstSin, JumpSin, NextSin));
        printf("delta: %lf\n", delta);
        break;

    case 2:
        while (x > 2 * 3.141592653589) {
            x = x - 2 * 3.141592653589;
        }
        printf("Teylor: cos(% lf) ~% lf\n", x, Taylor(x, n, FirstCos, JumpCos, NextCos));
        printf("math.h: cos(%lf) = %lf\n", x, cos(x));
        delta = fabs(cos(x) - Taylor(x, n, FirstCos, JumpCos, NextCos ));
        printf("delta: %lf\n", delta);
        break;

    case 3:
        printf("Teylor: exp(%lf) ~ %lf\n", x, Taylor(x, n, FirstExp, JumpExp,NextExp));
        printf("math.h: exp(%lf) = %lf\n", x, exp(x));
        delta = fabs(exp(x) - Taylor(x, n, FirstExp, JumpExp,  NextExp));
        printf("delta: %lf\n", delta);
        break;

    case 4:
        while (x > 2 * 3.141592653589) {
            x = x - 2 * 3.141592653589;
        }
        printf("Teylor: sh(%lf) ~ %lf\n", x, Taylor(x, n, FirstSh, JumpSh, NextSh));
        printf("math.h: sh(%lf) = %lf\n", x, sinh(x));
        delta = fabs(sinh(x) - Taylor(x, n, FirstSh,JumpSh, NextSh));
        printf("delta: %lf\n", delta);
        break;
    }
}

void SecondMode() {
    int func, N_max;
    double x, delta;

    printf("\nSelect function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. sh(x)\n");
    scanf_s("%d", &func);

    printf("\nInput x: ");
    scanf_s("%lf", &x);

    printf("Input N: ");
    scanf_s("%d", &N_max);

    switch (func) {
    case 1:
        while (x > 2 * 3.141592653589) {
            x = x - 2 * 3.141592653589;
        }
        printf("sin(x):\n");
        for (int i = 1; i <= N_max; i++) {
            delta = fabs(sin(x) - Taylor(x, i, FirstSin,JumpSin,NextSin));
            printf("(N = %d) Teylor = %lf, math.h = %lf, delta = %lf\n",
                i, Taylor(x, i, FirstSin, JumpSin, NextSin), sin(x), delta);
        }
        break;

    case 2:
        while (x > 2 * 3.141592653589) {
            x = x - 2 * 3.141592653589;
        }
        printf("cos(x):\n");
        for (int i = 1; i <= N_max; i++) {
            delta = fabs(cos(x) - Taylor(x, i, FirstCos,JumpCos, NextCos));
            printf("(N = %d) Teylor = %lf, math.h = %lf, delta = %lf\n",
                i, Taylor(x, i, FirstCos,  JumpCos, NextCos), cos(x), delta);
        }
        break;

    case 3:
        printf("exp(x):\n");
        for (int i = 1; i <= N_max; i++) {
            delta = fabs(exp(x) - Taylor(x, i, FirstExp, JumpExp, NextExp));
            printf("(N = %d) Teylor = %lf, math.h = %lf, delta = %lf\n",
                i, Taylor(x, i, FirstExp, JumpExp, NextExp), exp(x), delta);
        }
        break;

    case 4:
        while (x > 2 * 3.141592653589) {
            x = x - 2 * 3.141592653589;
        }
        printf("sh(x):\n");
        for (int i = 1; i <= N_max; i++) {
            delta = fabs(sinh(x) - Taylor(x, i, FirstSh,JumpSh, NextSh));
            printf("(N = %d) Teylor = %lf, math.h = %lf, delta = %lf\n",
                i, Taylor(x, i, FirstSh, JumpSh, NextSh), sinh(x), delta);
        }
        break;
    }
}

int main() {
    int choice;

    while (true) {
        printf("\nSelect mode:\n1. First mode\n2. Second mode\n0. Exit\n");
        scanf_s("%d", &choice);

        switch (choice) {
        case 0:
            printf("The program has completed the work\n");
            return 0;

        case 1:
            FirstMode();
            break;

        case 2:
            SecondMode();
            break;
        }
    }

    return 0;
}