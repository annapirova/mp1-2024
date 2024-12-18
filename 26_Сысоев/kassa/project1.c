#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_LINE_LENGTH 256
#define MAX_PRODUCTS 50

typedef struct {
    char name[100];
    double price;
    double quantity;
} Product;

void printReceipt(const Product* products, int productCount, FILE* output) {
    double total = 0.0;

    if (output == stdout) {
        wprintf(L"\nЧек:\n");
    }

    fwprintf(output, L"%-20ls %-10ls %-10ls %-10ls\n", L"Название", L"Цена", L"Кол-во", L"Сумма");
    fwprintf(output, L"----------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        double sum = products[i].price * products[i].quantity;
        total += sum;
        fwprintf(output, L"%-20hs %-10.2f %-10.2f %-10.2f\n", products[i].name, products[i].price, products[i].quantity, sum);
    }

    fwprintf(output, L"----------------------------------------------------\n");
    fwprintf(output, L"Итого: %.2f\n", total);
}

// Функция помогаюшая с проблемой регистра
int caseInsensitiveCompare(const char* str1, const char* str2) {
#ifdef _WIN32
    return _stricmp(str1, str2);
#else
    return strcasecmp(str1, str2);
#endif
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    Product products[MAX_PRODUCTS] = {
        {"Apple", 45.0, 0.0},
        {"Ananas", 50.0, 0.0},
        {"Kiwi", 30.0, 0.0},
        {"Tomato", 60.0, 0.0},
        {"Cucumber", 55.0, 0.0}
    };
    Product receipt[MAX_PRODUCTS];
    int receiptCount = 0;

    wprintf(L"Введите товары и их количество (пустая строка завершает ввод):\n");

    while (1) {
        char input[MAX_LINE_LENGTH];
        wprintf(L"> ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') {
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        char productName[100] = "";
        double quantity = 0;

        int parsed = sscanf(input, "%99s %lf", productName, &quantity);

        if (parsed < 2 || quantity <= 0) {
            parsed = sscanf(input, "%lf %99s", &quantity, productName);
        }

        if (parsed < 2 || quantity <= 0) {
            wprintf(L"Некорректный ввод.\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (caseInsensitiveCompare(products[i].name, productName) == 0) {
                receipt[receiptCount] = products[i];
                receipt[receiptCount].quantity = quantity;
                receiptCount++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wprintf(L"Товар '%hs' не найден на складе.\n", productName);
        }
    }


    wprintf(L"\nВыберите действие:\n");
    wprintf(L"1. Печатать чек в консоль\n");
    wprintf(L"2. Записать чек в файл\n");

    int choice;
    wscanf(L"%d", &choice);

    FILE* output;
    if (choice == 2) {

        output = fopen("receipt.txt", "w, ccs=UTF-8");
        if (output == NULL) {
            wprintf(L"Ошибка при открытии файла.\n");
            return 1;
        }
    }
    else {
        output = stdout;  
    }

    printReceipt(receipt, receiptCount, output);

    if (output != stdout) {
        fclose(output);
    }

    return 0;
}
