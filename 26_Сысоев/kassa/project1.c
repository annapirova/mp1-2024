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

    fprintf(output, "\nReceipt:\n");
    fprintf(output, "%-20s %-10s %-10s %-10s\n", "Product", "Price", "Qty", "Total");
    fprintf(output, "----------------------------------------------------\n");

    for (int i = 0; i < productCount; i++) {
        double sum = products[i].price * products[i].quantity;
        total += sum;
        fprintf(output, "%-20s %-10.2f %-10.2f %-10.2f\n", products[i].name, products[i].price, products[i].quantity, sum);
    }

    fprintf(output, "----------------------------------------------------\n");
    fprintf(output, "Total: %.2f\n", total);
}

int caseInsensitiveCompare(const char* str1, const char* str2) {
#ifdef _WIN32
    return _stricmp(str1, str2);
#else
    return strcasecmp(str1, str2);
#endif
}

int main() {
    setlocale(LC_ALL, "C");

    Product products[MAX_PRODUCTS] = {
        {"Apple", 45.0, 0.0},
        {"Ananas", 50.0, 0.0},
        {"Kiwi", 30.0, 0.0},
        {"Tomato", 60.0, 0.0},
        {"Cucumber", 55.0, 0.0}
    };
    Product receipt[MAX_PRODUCTS];
    int receiptCount = 0;

    printf("Enter products and their quantity (empty input ends):\n");

    int flag = 1;
    while (flag) {
        char input[MAX_LINE_LENGTH];
        printf("> ");
        fgets(input, sizeof(input), stdin);

        if (input[0] == '\n') {
            flag = 0;
            continue;
        }

        input[strcspn(input, "\n")] = '\0';

        char productName[100] = "";
        double quantity = 0;

        int parsed = sscanf(input, "%99s %lf", productName, &quantity);

        if (parsed < 2 || quantity <= 0) {
            parsed = sscanf(input, "%lf %99s", &quantity, productName);
        }

        if (parsed < 2 || quantity <= 0) {
            printf("Invalid input.\n");
            continue;
        }

        int found = 0;
        for (int i = 0; i < 5; i++) {
            if (caseInsensitiveCompare(products[i].name, productName) == 0) {
                found = 1;

                int alreadyInReceipt = 0;
                for (int j = 0; j < receiptCount; j++) {
                    if (caseInsensitiveCompare(receipt[j].name, productName) == 0) {
                        receipt[j].quantity += quantity;
                        alreadyInReceipt = 1;
                        break;
                    }
                }

                if (!alreadyInReceipt) {
                    receipt[receiptCount] = products[i];
                    receipt[receiptCount].quantity = quantity;
                    receiptCount++;
                }

                break;
            }
        }
        if (!found) {
            printf("Product '%s' not found in stock.\n", productName);
        }
    }

    printf("\nChoose an action:\n");
    printf("1. Print receipt to console\n");
    printf("2. Save receipt to file\n");

    int choice;
    scanf("%d", &choice);

    FILE* output;
    if (choice == 2) {
        output = fopen("receipt.txt", "w");
        if (output == NULL) {
            printf("Error opening file.\n");
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
