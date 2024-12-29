#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>


typedef struct {
    char name[20];
    double price_per_kg;
} Product;

// Функция для приведения строки к нижнему регистру
void to_lower_case(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Функция для чтения списка товаров с консоли
void read_purchase_list(char purchases[100][256], int* count) {
    setlocale(LC_ALL, "Rus");
    printf("Введите список покупок (введите 'end' для завершения ввода):\n");
    *count = 0;
    while (*count < 100) {
        fgets(purchases[*count], 256, stdin);
        purchases[*count][strcspn(purchases[*count], "\n")] = 0;
        if (strcmp(purchases[*count], "end") == 0) {
            break;
        }
        (*count)++;
    }
}

// Функция для разбора строки на количество и название товара
void parse_purchase(const char* line, double* quantity, char* name) {
    char* token;
    char line_copy[256];
    strcpy(line_copy, line);

    *quantity = 0.0;
    name[0] = '\0';

    token = strtok(line_copy, " ");
    while (token != NULL) {
        char* endptr;
        double value = strtod(token, &endptr);
        if (endptr != token) {
            *quantity += value;
        }
        else {
            strcat(name, token);
            strcat(name, " ");
        }
        token = strtok(NULL, " ");
    }
    name[strlen(name) - 1] = '\0';
}

// Функция для формирования чека
void generate_check(Product stock[], int stock_count, char purchases[100][256], int purchase_count) {
    FILE* check_file = fopen("check.txt", "w");
    if (check_file == NULL) {
        printf("Ошибка создания файла чека.\n");
        return;
    }

    double total_sum = 0.0;
    fprintf(check_file, "Чек:\n");
    fprintf(check_file, "-----------------------------------\n");
    for (int i = 0; i < purchase_count; i++) {
        double quantity = 0.0;
        char name[256] = "";
        parse_purchase(purchases[i], &quantity, name);
        to_lower_case(name);

        for (int j = 0; j < stock_count; j++) {
            char stock_name[256];
            strcpy(stock_name, stock[j].name);
            to_lower_case(stock_name);

            if (strcmp(stock_name, name) == 0) {
                double cost = quantity * stock[j].price_per_kg;
                fprintf(check_file, "%-15s %2.1f кг * %-10.2f = %.2f\n", stock[j].name, quantity, stock[j].price_per_kg, cost);
                total_sum += cost;
                break;
            }
        }
    }

    fprintf(check_file, "-----------------------------------\n");
    fprintf(check_file, "Общая сумма: %.2f\n", total_sum);
    fclose(check_file);
    printf("Чек успешно сформирован в файл check.txt\n");
}

int main() {
    Product stock[] = {
        {"banana", 105.0},
        {"tomato", 300.0},
        {"kiwi", 400.0},
        {"apple", 150.0},
        {"cucumber", 200.0},
        {"potato", 50.0}
    };
    int stock_count = sizeof(stock) / sizeof(stock[0]);

    char purchases[100][256];
    int purchase_count = 0;

    read_purchase_list(purchases, &purchase_count);
    generate_check(stock, stock_count, purchases, purchase_count);

    return 0;
}

