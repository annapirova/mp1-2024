//
// Created by Семён Евдокимович on 21.11.2024.
//
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void print_me1() {
    printf("1. Sinus\n");
    printf("2. Cosine\n");
    printf("3. Exp\n");
    printf("4. Shinus\n");
    printf("5. Exit \n");
}
double FirstSin(double x) {
    return x;
}
double NextSin(double x, int i) {
    return (-x*x/((i-1)*i));
}
double FirstCos(double x) {
    return 1;
}
double FirstExp(double x) {
    return 1;
}
double NextCos(double x, int i) {
    i--;
    return -x*x/((i-1)*i);
}
double NextExp(double x, int i) {
    i--;
    return x/i;
}
double NextShin(double x, int i) {
    return (x*x/((i-1)*i));
}
typedef double(*First)(double);
typedef double(*Next)(double, int);
double Teylor(double x, int N, First f, Next g, int h, double eps, double res) {
    double prev, next, sum;
    int i=1, shag;
    sum = 0.0;
    prev = f(x);
    next = 0;
    shag = h;
    while(fabs(sum - res) > eps) {
        if (i == 1)
            sum += prev;

        else {
            next = prev*g(x, i);
            sum += next;
            prev = next;
        }
        i+=shag;
    }
    printf("Reference value - %lf \n",res);
    printf("Calculated value - %lf \n",sum);
    printf("Difference of value - %lf \n",fabsl(res - sum));
    printf("The lenght of the row - %d \n ", i);
    return sum;
}
double Teylor2(double x, int N, First f, Next g, int h, double res) {
    double prev, next, sum;
    int i=1, shag;
    sum = 0.0;
    prev = f(x);
    next = 0;
    shag = h;
    while(N >= i) {
        if (i == 1)
            sum += prev;

        else {
            next = prev*g(x, i);
            sum += next;
            prev = next;
        }
        printf("N = %d Difference of value = %lf \n", i, fabsl(res - sum));
        i+=shag;

    }
    return sum;
}


int main() {
    int N;
    double eps;
    double x;
    double y;
    int choice,mode,choice2;

    int k=0,kol=0;
    printf("Input - x \n");
    scanf("%lf",&x);
    printf("Input - N \n");
    scanf("%d",&N);
    printf("Input - eps \n");
    scanf("%lf",&eps);
    printf("The first mode \n");
    print_me1();
    while(k==0) {
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                y = Teylor(x,N, FirstSin, NextSin, 2, eps, sin(x));
            break;
            case 2:

                y = Teylor(x,N, FirstCos, NextCos, 2, eps, cos(x));
            break;
            case 3:
                y = Teylor(x,N, FirstExp, NextExp, 1, eps, exp(x));
            break;
            case 4:
                y = Teylor(x,N, FirstSin, NextShin, 2, eps, sinh(x));
            break;
            case 5:
                k = 1;
            break;
        }
    }
    printf("The second mode \n");
    print_me1();
    while(kol==0) {
        scanf("%d",&choice2);
        switch (choice2) {
            case 1:
                y = Teylor2(x,N, FirstSin, NextSin, 2, sin(x));
            break;
            case 2:

                y = Teylor2(x,N, FirstCos, NextCos, 2, cos(x));
            break;
            case 3:
                y = Teylor2(x,N, FirstExp, NextExp, 1, exp(x));
            break;

            case 4:
                y = Teylor2(x,N, FirstSin, NextShin, 2, sinh(x));
            break;
            case 5:
                kol = 1;
            break;
        }
    }
}
