#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "stdbool.h"
#define _USE_MATH_DEFINES



typedef double(*First)(double);
typedef double(*Next)(double, int);
typedef bool(*check)(double);
#define input(x) scanf_s("%lf", &x)




void setvar(double x){
    printf("Input x: ");
    input(x);
}
void accuracy(double epi, check f){
    while(f(epi)) {
        printf("Invalid accuracy.\nSet accuracy: ");
        input(epi);
    }
}

bool check_accur(double ep){
    if(ep < 0.0  || ep > 0.000001) return false;
    else return true;
}
bool check_arc(double x){
    if(fabs(x) <= 1) return true;
    else return false;
}

void f(int y, int epi, int cd, int x){
    double a;
    double res;
    if(cd == 2){
        a = fabs(y - sin(x)) ;
        printf("Reference value: ", sin(x));

    }
    if(cd == 3){
        a = fabs(y - cos(x));
        printf("Reference value: \n", cos(x));
    }
    if(cd == 4){
        a = fabs(y - exp(x)) < epi;
        printf("Reference value: ", exp(x));
    }
    if(cd == 5){
        a = fabs(y - M_PI/2 + atan(x)) < epi;
        printf("Reference value: ", M_PI - atan(x));
    }
    printf("inaccuracy: %lf\n", a);
}


        double FirstSin(double x){
    return x;
}

double FirstCos(double x){
    return 1;
}
double FirstExp(double x){
    return 1;
}
double FirstArcCtg(double x){
    return x;
}



double NextSin(double x, int i){
    return -x * x/2*i/2*i + 1;
}
double NextCos(double x, int i){
    return -x * x /2*i - 1/2*i;
}
double NextExp(double x, int i){
    return x/i;
}
double NextArcCtg(double x, int i){
    return x * x * (2 * i - 1)/2 * i + 1;
}

double Teylor(double x, int n, First first, Next next, int com){
    double summ = 0, prev = first(x), cur;
    int i;
    for(i = 1; i < n; i ++){
        cur = prev * next(x,i);
        summ+=cur;
        prev = cur;
    }
    if(com != 5) {
        return summ;
    }
    else return M_PI - summ;
}




void menu(){
    printf("Choose function\n");
    printf("0. Input x\n1. Set accuracy\n2. Sin(x)\n3. Cos(x)\n4. Exp(x)\n5. ArcCtg(x)\n6. Change number of steps\n7.exit\n");
}

int main(void) {
    int com;
    double x, eps = 0.0;
    int step;
    double res, reverence;
    printf("To start you need to enter variable, accuracy and number of steps\n");
    setvar(x);
    printf("Set accuracy: ");
    input(eps);
    printf("Steps: ");
    input(step);
    while(com != 7){
        menu();
        printf("Option: ");
        scanf_s("%d", &com);
        switch(com){
            case 0:{
                setvar(x);
                break;
            }
            case 1:{
                accuracy(eps,check_accur);
                break;
            }
            case 2:{ //sin
                res = Teylor(x, step, FirstSin, NextSin, com);
                break;
            }
            case 3:{ // cos
                res = Teylor(x, step, FirstCos, NextCos, com);
                break;
            }
            case 4:{ //exp
                res = Teylor(x, step, FirstExp, NextExp, com);
                break;
            }
            case 5:{ // arcctg
                while(!(check_arc(x))){
                    printf("Invalid value: x must in range[-1;1]");
                    setvar(x);
                }
                res = Teylor(x, step, FirstArcCtg, NextArcCtg, com);
                break;
            }
            case 6:{
                printf("Input number of steps: ");
                input(step);
                break;
            }
        }
        f(res, eps, com, x);
        printf("Experimental value: %lf\n", res);
        printf("Number of steps: %d\n", step);
    }
}
