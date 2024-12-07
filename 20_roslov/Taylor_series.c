#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef double(*First)(double);
typedef double(*Next)(int, double);
typedef double(*Check)(double, double , int , double );


#define print(a) printf("%d\n", (a))
#define forik(a) for(int i = 0; i < a; i++)

void menu_print(int *action){
    printf("Выбирите действие:\n");
    printf("1) Однократный расчет функции в заданной точке\n");
    printf("2) Серийный эксперимент.\n");
    scanf("%d", action);
    
}

void change_func(int *type_func){
    printf("Выбирите функцию:\n");
    printf("1) Косинус\n");
    printf("2) Синус\n");
    printf("3) Экспонент\n");
    printf("4) Гиперболический синус\n");
    scanf("%d", type_func);
}

void change_x(int *x){
    printf("Введите значение x:\n");
    scanf("%lf", x);
}

void accuracy(int *eps){
    printf("Введите точность вычислений:\n");
    scanf("%lf", eps);
}

void input_n(int *n){
    printf("Введите значение N:\n");
    scanf("%d", n);
}

double FirstSin(double x){
    return x;
}

double FirstHSin(double x){
    return x;
}

double FirstCos(double x){
    return 1;
}

double FirstExp(double x){
    return 1;
}

double NextSin(int i, double x){
    return -x * x / (2 * i) / (2 * i + 1);
}

double NextHSin(int i, double x){
    return x * x / (2 * i) / (2 * i + 1);
}

double NextExp(int i, double x){
    return x / (i);
}

double NextCos(int i, double x){
    return  -x * x / (2 * i) / (2 * i - 1);
}

double check_eps(double x, double total, int type, double eps){
    if (type == 1){
        return (total - cos(x));
    } else if (type == 2){
        return (total - sin(x));
    } else if (type == 3){
        return (total - exp(x));
    } else if (type == 4){
        return (total - sinh(x));
    }
}


double Teylor(double x, int n, First f, Next g, double eps, int type_func, Check z, int *count){
    double summ = f(x);
    double elem = x;
    double prew = f(x);

    for (int i = 1; i < n && z(x, summ, type_func, eps); i++){
        elem = prew * g(i, x);
        summ += elem;
        prew = elem;
        *count += 1;
    }
    return summ;
}

int main(){
    int action, n, type_func;
    int count = 1;
    double x, eps;
    change_func(&type_func);
    while (type_func != 1 && type_func != 2 && type_func != 3 && type_func != 4)
        {
            printf("Неправильный ввод\n");
            printf("Повторите ввод\n");
            change_func(&type_func);
        }
        accuracy(&eps);
        while (eps > 0.0 && eps < 0.000001)
        {
            printf("Неправильный ввод\n");
            printf("Повторите ввод\n");
            accuracy(&eps);
        }
    if (type_func == 3){    
        input_n(&n);
        change_x(&x);
        double y = Teylor(x, n, FirstExp, NextExp, eps, type_func, check_eps, &count);
        printf("Эталонное значние Экспонента: %lf\n", exp(x));
        printf("Вычисленная оценка значения: %lf\n", y);
        printf("Разница между оценкой и эталонным значением: %lf\n", y -  exp(x));
        printf("Количество слагаемых, которое было вычислено: %d\n", count);
    }else if (type_func == 1){
        input_n(&n);
        change_x(&x);
        double y = Teylor(x, n, FirstCos, NextCos, eps, type_func, check_eps, &count);
        printf("Эталонное значние Косинуса: %lf\n", cos(x));
        printf("Вычисленная оценка значения: %lf\n", y);
        printf("Разница между оценкой и эталонным значением: %lf\n", y -  cos(x));
        printf("Количество слагаемых, которое было вычислено: %d\n", count);
    }else if (type_func == 2){
        input_n(&n);
        change_x(&x);
        double y = Teylor(x, n, FirstSin, NextSin, eps, type_func, check_eps, &count);
        printf("Эталонное значние Синуса: %lf\n", sin(x));
        printf("Вычисленная оценка значения: %lf\n", y);
        printf("Разница между оценкой и эталонным значением: %lf\n", y -  sin(x));
        printf("Количество слагаемых, которое было вычислено: %d\n", count);
    }else if ( type_func == 4){
        input_n(&n);
        change_x(&x);
        double y = Teylor(x, n, FirstHSin, NextHSin, eps, type_func, check_eps, &count);
        printf("Эталонное значние Гиб.син: %lf\n", sinh(x));
        printf("Вычисленная оценка значения: %lf\n", y);
        printf("Разница между оценкой и эталонным значением: %lf\n", y -  sinh(x));
        printf("Количество слагаемых, которое было вычислено: %d\n", count);
    }
}