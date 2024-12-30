#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#pragma warning(disable : 4996)

// Структура для хранения информации о товаре
struct Item {
    char name[100];       // Название товара
    double price;         // Цена за кг
    double quantity;      // Количество на складе или в чеке
};

// Массив товаров на складе
struct Item inventory[] = {
    {"tomato", 820.0, 43.0},
    {"milk", 530.0, 101.0},
    {"cheese", 2250.0, 31.0},
    {"raxat-lukum", 31000.0, 29.0},
    {"bread", 220.0, 52.0},
    {"egg", 1030.0, 2.0}
};

// Массив для хранения товаров, выбранных покупателем
struct Item basket[100];

// Функция для перевода строки в нижний регистр
void toLowerCase(char* str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

// Функция для поиска товара в массиве на складе
int findItemByName(const char* itemName) {
    for (int i = 0; i < sizeof(inventory) / sizeof(inventory[0]); i++) {
        int j = 0;
        // Сравниваем строки без учета регистра
        while (inventory[i].name[j] != '\0' && itemName[j] != '\0') {
            if (tolower((unsigned char)inventory[i].name[j]) != tolower((unsigned char)itemName[j])) {
                break;
            }
            j++;
        }
        // Если строки совпали
        if (inventory[i].name[j] == '\0' && itemName[j] == '\0') {
            return i;  // Товар найден
        }
    }
    return -1;  // Товар не найден
}

int main() {
    int numberOfItems = 0;  // Количество введенных товаров
    char userInput[100];    // Строка для ввода пользователя
    char* token;
    char delimiter[] = " ";  // Разделитель для строк
    char inputLines[100][100];  // Массив для хранения строк с товарами
    char tokens[100][100];  // Массив для хранения токенов (слов)

    setlocale(LC_ALL, "Russian");

    // Ввод списка товаров
    printf("Введите список товаров, чтобы завершить, введите пустую строку:\n");
    while (1) {
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\n")] = '\0';  // Удаляем символ новой строки
        if (strlen(userInput) == 0) break;  // Завершаем ввод при пустой строке
        strcpy(inputLines[numberOfItems], userInput);
        numberOfItems++;
    }

    // Разбиваем строки на отдельные токены (слова)
    int tokenCount = 0;
    for (int i = 0; i < numberOfItems; i++) {
        token = strtok(inputLines[i], delimiter);
        while (token != NULL) {
            strcpy(tokens[tokenCount], token);
            token = strtok(NULL, delimiter);
            tokenCount++;
        }
    }

    // Формируем список товаров в корзине (basket) на основе введенных данных
    int basketIndex = 0;
    for (int t = 0; t < tokenCount; t++) {
        double quantity = 1.0;  // Стандартное количество — 1
        if (sscanf(tokens[t], "%lf", &quantity)) {  // Если токен — это число
            basket[basketIndex].quantity = quantity;
            strcpy(basket[basketIndex].name, tokens[t + 1]);
            t++;  // Переходим к следующему товару
        }
        else {
            basket[basketIndex].quantity = atof(tokens[t + 1]);
            strcpy(basket[basketIndex].name, tokens[t]);
            t++;  // Переходим к следующему товару
        }
        basketIndex++;
    }

    // Вывод чека с точками между товаром и его стоимостью
    printf("Чек:\n");
    double totalSum = 0.0;
    for (int i = 0; i < basketIndex; i++) {
        char lowerName[100];
        strcpy(lowerName, basket[i].name);
        toLowerCase(lowerName);

        int inventoryIndex = findItemByName(lowerName);
        if (inventoryIndex != -1) {
            double totalPrice = basket[i].quantity * inventory[inventoryIndex].price;
            totalSum += totalPrice;
            
            printf("%-20s.... %.1lf * %.2lf.... %.2lf\n", basket[i].name, basket[i].quantity, inventory[inventoryIndex].price, totalPrice);
        }
        else {
            printf("%-20s.... Не найден\n", basket[i].name);
        }
    }

    // Вывод общей суммы
    printf("Сумма.................... %.2lf\n", totalSum);

    return 0;
}
