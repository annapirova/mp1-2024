#include <stdio.h>
#include <locale.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>

void print_menu()
{
    printf("0. Синус \n");
    printf("1. Косинус \n");
    printf("2. Экспонента \n");
    printf("3. Секанс \n");
    printf("4. Выход \n");
}

// Первый синус
double FirstSin(double x)
{
    return x;
}
// Следующий синус
double NextSin(double x, int i)
{
    return (-x * x / (i - 1) / i);
}
// Первый косинус
double FirstCos(double x)
{
    return 1;
}
// Следующий косинус
double NextCos(double x, int i)
{
    i--;
    return (-x * x / (i - 1) / i);
}
// Первая экспонента
double FirstExp(double x)
{
    return 1;
}
// Следующая экспонента
double NextExp(double x, int i)
{
    i--;
    return x / i;
}
// Первый секанс
double FirstSec(double x)
{
    return 1;
}
// Следующий секанс
double NextSec(double x, int i)
{
    if (i % 2 == 0) {
        return (x * x / (i - 1) / i);
    }
    else {
        return 0; // Только чётные члены
    }
}

typedef double(*First)(double);
typedef double(*Next)(double, int);

// Тейлор режим 1
double Teylor(double x, int N, First f, Next g, int h, double eps, double rez, int max_iter)
{
    double prev;
    double next;
    double sums;
    int i = 1, shag;
    prev = f(x);
    sums = 0.0;
    next = 0;
    shag = h;
    int iter = 0;

    while (fabs(sums - rez) > eps && iter < max_iter) // Остановка по точности и количеству итераций
    {
        if (i == 1)
            sums += prev;
        else
        {
            next = prev * g(x, i);
            sums += next;
            prev = next;
        }
        i += shag;
        iter++; // Увеличиваем счетчик итераций
    }

    printf("Исходное значение - %lf \n", rez);
    printf("Посчитанное значение - %lf \n", sums);
    printf("Разница в значениях - %lf \n", fabsl(rez - sums));
    printf("Количество слагаемых, которое было вычислено равно %d \n", i);

    // Проверка, по какому условию завершена работа
    if (iter >= max_iter) {
        printf("Достигнут максимальный лимит итераций (%d).\n", max_iter);
    }
    else {
        printf("Достигнута требуемая точность.\n");
    }

    return sums;
}

int main()
{
    int N;
    double eps;
    double x, y;
    int c1 = 0;
    int max_iter;

    setlocale(LC_ALL, "Russian");

    printf("Выбери функцию из перечня \n");
    print_menu();
    scanf_s("%d", &c1);

    printf("Введи точку x, в которой хочешь найти значение функции \n");
    scanf_s("%lf", &x);
    printf("Введи число элементов ряда для выполнения расчёта (N) \n");
    scanf_s("%d", &N);
    printf("Введи точность вычисления (eps) \n");
    scanf_s("%lf", &eps);
    printf("Введи максимальное количество итераций (max_iter) \n");
    scanf_s("%d", &max_iter);

    while (x > M_PI_2)
    {
        x = x - M_PI_2;
    }

    switch (c1)
    {
    case 0:
        y = Teylor(x, N, FirstSin, NextSin, 2, eps, sin(x), max_iter);
        break;
    case 1:
        y = Teylor(x, N, FirstCos, NextCos, 2, eps, cos(x), max_iter);
        break;
    case 2:
        y = Teylor(x, N, FirstExp, NextExp, 1, eps, exp(x), max_iter);
        break;
    case 3:
        y = Teylor(x, N, FirstSec, NextSec, 2, eps, 1 / cos(x), max_iter);
        break;
    case 4:
        printf("Выход из программы\n");
        return 0;
    default:
        printf("Некорректный ввод. Попробуйте снова.\n");
        return 1;
    }

    return 0;
}
