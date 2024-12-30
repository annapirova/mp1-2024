#include <stdio.h>
#include <locale.h>
#include <math.h>

double sin_taylor(double x, int n) {
    double result = 0.0;
    double term = x;

    for (int i = 0; i < n; i++) {
        result += term;
        term *= -x * x / ((2 * i + 2) * (2 * i + 3));
    }

    return result;
}

double cos_taylor(double x, int n) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 0; i < n; i++) {
        term *= -x * x / ((2 * i + 1) * (2 * i + 2));
        result += term;
    }

    return result;
}

double exp_taylor(double x, int n) {
    double result = 1.0;
    double term = 1.0;

    for (int i = 1; i <= n; i++) {
        term *= x / i;
        result += term;
    }

    return result;
}

double ctg(double x, int n) {
    double sin_val = sin_taylor(x, n);
    double cos_val = cos_taylor(x, n);

    return cos_val / sin_val;
}

double tg(double x, int n) {
    double sin_val = sin_taylor(x, n);
    double cos_val = cos_taylor(x, n);

    return sin_val / cos_val;
}

void single(double (*func)(double, int), double x, double gg, int mx) {
    double true_value = 1 / tan(x);
    double approx = 0;
    int t = 0;

    for (int i = 1; i <= mx; i++) {
        approx = func(x, i);
        t = i;
        if (fabs(approx - true_value) <= gg) {
            break;
        }
    }

    if (isinf(true_value)) {
        printf("Эталонное значение: inf\n");
    }
    else {
        printf("Эталонное значение: %.10f\n", true_value);
    }

    printf("Приближённое значение: %.10f\n", approx);
    printf("Разница: %.10f\n", fabs(approx - true_value));
    printf("Использовано слагаемых: %d\n", t);
}

void serial(double (*func)(double, int), double x, int mx) {
    double tv = 1 / tan(x);

    printf("\nЭталонное значение: %.10f\n", tv);
    printf("| N |   Приближённое значение   |   Разница    |\n");

    for (int i = 1; i <= mx; i++) {
        double v = func(x, i);
        double difr = fabs(v - tv);
        printf("|%-3d| %-25.10f | %-10.10f |\n", i, v, difr);
    }
}



int main() {
    setlocale(LC_ALL, "ru_RU");
    int mode0;
    int mode;

    printf("Выберите функцию:\n");
    printf("1) ctg\n");
    printf("2) tg\n");
    scanf_s("%d", &mode0);
    double (*function)(double, int) = tg;

    if (mode0 == 1) {
        double (*function)(double, int) = ctg;
    }

    printf("Выберите режим:\n");
    printf("1) Однократный расчёт\n");
    printf("2) Серийный эксперимент\n");
    scanf_s("%d", &mode);

    if (mode == 1) {
        double x, epsilon;
        int mx;

        printf("Введите точку x: ");
        scanf_s("%lf", &x); // из-за setlocale(LC_ALL, "ru_RU"), если хотим записать дробное число пишем запятую, а не точку
        printf("Введите точность: ");
        scanf_s("%lf", &epsilon); // из-за setlocale(LC_ALL, "ru_RU"), если хотим записать дробное число пишем запятую, а не точку
        printf("Введите максимальное число слагаемых: ");
        scanf_s("%d", &mx);

        single(function, x, epsilon, mx);
    }
    else if (mode == 2) {
        double xx;
        int mx;

        printf("Введите точку x: ");
        scanf_s("%lf", &xx); // из-за setlocale(LC_ALL, "ru_RU"), если хотим записать дробное число пишем запятую "," , а не точку "."
        printf("Введите число экспериментов: ");
        scanf_s("%d", &mx);
        serial(function, xx, mx);
    }
    else {
        printf("Ошибка\n");
    }

    return 0;
}