#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


struct Product {
	char code[5];
	char name[50];
	double kg_price;
	double amount;
};

typedef struct Product Product;

struct Product Warehouse[] = {
	{"99919", "Banana", 199.0, 25.0},
	{"34583", "Apple", 149.99, 135.0},
	{"12345", "Cucumber", 299.0, 50.5},
	{"54322", "Tomato", 269.0, 30.0},
	{"69696", "Potato", 149.99, 50.0},
	{"12365", "Cheese", 395.0, 10.0},
	{"99999", "Pepsi", 199.99, 50.3},
	{"87425", "Carrot", 89.50, 20.1},
	{"23411", "Bread", 57.10, 25.0},
	{"93411", "Chicken", 435.50, 14.2}
};

struct Product Check[100];


int get_list(char List[][100]) {
	char string[100];
	
	int i = 0;
	do {
		fgets(string, 100, stdin);
		strcpy(List[i], string);
		i++;
	}
	while (strlen(string) != 1);

	return i;
}


int add_in_check(char code[5], char name[50], double kg_price, double amount, int i) {
	int flag = -1;
	
	for (int j=0; j < sizeof(Check)/sizeof(Check[0]); j++)
		if (strcmp(code, Check[j].code) == 0)
			flag = j;
	
	if (flag != -1){
		Check[flag].kg_price += kg_price*amount;
		Check[flag].amount += amount;
		return 0;
	}
		
	else {
		strcpy(Check[i].code, code);
		strcpy(Check[i].name,name);
		Check[i].kg_price = kg_price*amount;
		Check[i].amount = amount;
		return 1;
	}
}

void print_check(int n) {
	int i; double sum = 0.0;

	FILE *file = fopen("check.txt", "w");
	
	printf("==========CHECK==========\n");
	fputs("==========CHECK==========\n", file);

	for (i = 0; i < n; i++){
		printf(Check[i].name);
		fputs(Check[i].name, file);

		printf("   ");
		fputs("   ", file);

		printf("%.2f\n", Check[i].kg_price);
		fprintf(file, "%.2f\n", Check[i].kg_price);

		sum += Check[i].kg_price;
	}
	printf("\nSum = %.2f\n", sum);
	fprintf(file, "\nSum = %.2f\n", sum);

	printf("=========================\n");
	fputs("=========================", file);
	
	printf("\nFile with check - check.txt\n");

	fclose(file);
}


int main() {
	int amount_in_list;  // количество записей в списке покупок
	int tokens_amount;  
	int i, j;
	int buyed = 0;
	int items = sizeof(Warehouse)/sizeof(Warehouse[0]);

	char* token;
	char* name = "";
	char* amount = "";

	int name_flag, amount_flag;

	char List[25][100];  // список покупок
	char* Assortment[10];  // ассортимент (названия)
	
	for (i=0; i < items; i++){
		Assortment[i] = Warehouse[i].name;
		//Assortment[i][0] = tolower(Assortment[i][0]);
	}


	printf("Shopping list:\n");
	amount_in_list = get_list(List);

	
	for (i=0; i < amount_in_list-1; i++){
		token = strtok(List[i], " ");
		
		tokens_amount = 0;

		name_flag = 0; amount_flag = 0;

		while (token != NULL) {
			tokens_amount++;

			for (j=0; j<strlen(token); j++)
				if (strcmp(&token[j], "\n") == 0)
					token[j] = 0;


			if (isdigit(token[0])){
				amount = token;
				amount_flag = 1;
			}

			else{
				name = token;
				name_flag = 1;
			}

			token = strtok(NULL, " ");
		}

		if (tokens_amount == 2 && name_flag && amount_flag){
			for (j=1; j < strlen(name); j++)
				name[j] = tolower(name[j]);
			
			name[0] = toupper(name[0]);

			for (j=0; j < items; j++){
				if (strlen(name) >= 4 && (strstr(name, Assortment[j]) || strstr(Assortment[j], name))) {
					if (Warehouse[j].amount >= strtod(amount, NULL)){
						printf(Warehouse[j].name);
						printf(": ");
						printf(amount);
						printf("*");
						printf("%.2f", Warehouse[j].kg_price);
						printf("\n");
					
						buyed += add_in_check(Warehouse[j].code, Warehouse[j].name, Warehouse[j].kg_price, strtod(amount, NULL), buyed);	
					}
					
					else {
						printf(Warehouse[j].name);
						printf(": ");
						printf("Not enough goods in warehouse\n");
					}

					break;
				}
			}
		}
	}
	
	printf("\n");
	print_check(buyed);
}