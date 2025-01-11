#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<locale.h>
#include<math.h>
#include<stdlib.h>


int WordFromOneToTenToNumber(const char* word) {
	if (strcmp(word, "один") == 0) return 1;
	else if (strcmp(word, "одна") == 0) return 1;
	else if (strcmp(word, "два") == 0) return 2;
	else if (strcmp(word, "две") == 0) return 2;
	else if (strcmp(word, "трое") == 0) return 3;
	else if (strcmp(word, "три") == 0) return 3;
	else if (strcmp(word, "четыре") == 0) return 4;
	else if (strcmp(word, "п§ть") == 0) return 5;
	else if (strcmp(word, "шесть") == 0) return 6;
	else if (strcmp(word, "семь") == 0) return 7;
	else if (strcmp(word, "восемь") == 0) return 8;
	else if (strcmp(word, "дев§ть") == 0) return 9;
	else if (strcmp(word, "дес§ть") == 0) return 10;
	else return -1;
}
typedef struct goods {
	int id;
	char name[100];
	double price_k;
	double quantity;
}goods;

char warehouse[][100] = { "томат","киви","§блоко","банан" };
int size_warehouse = sizeof(warehouse) / sizeof(warehouse[0]);
typedef struct product {
	double tmp;
	char name[100];
} product;

product* note;
goods* point;

void create_shop(goods point[], int size) {
	int i, id_art = 1;
	double pri, cou;
	for (i = 0; i < size; i++) {
		pri = fabs(rand() % 500 + 1);
		cou = fabs(rand() % 200 + 1);
		strcpy(point[i].name, warehouse[i]);
		point[i].price_k = pri;
		point[i].quantity = cou;
		point[i].id = id_art;
		id_art++;
	}

}

void prints(goods thing[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d  %s %.2lf  %.2lf\n", thing[i].id, thing[i].name, thing[i].quantity, thing[i].price_k);
	}
}
int get_id_product(char* str) {
	for (int i = 0; i < size_warehouse; i++) {
		if (!strcmp(str, point[i].name)) {
			return point[i].id;
		}
	}
	return -1;
}

int check_product(char* str) {
	for (int i = 0; i < size_warehouse; i++) {
		if (!strcmp(warehouse[i], str)) {
			return 1;
		}
	}
	return 0;
}

int check_tmp(product arr[], int n, char* prod) {
	for (int i = 0; i < n; i++) {
		if (!strcmp(arr[i].name, prod)) {
			return i;
		}
	}
	return -1;

}


void print_check(product all[], int size) {
	double final = 0.0;
	note = (product*)malloc(sizeof(product) * size_warehouse);
	int n = 0;
	for (int i = 0; i < size; i++) {
		if (check_product(all[i].name)) {
			int id = check_tmp(note, n, all[i].name);
			if (id != -1) {
				note[id].tmp += all[i].tmp;
			}
			else {
				strcpy(note[n].name, all[i].name);
				note[n].tmp = all[i].tmp;
				n++;
			}
		}
	}
	for (int i = 0; i < size; i++) {
		if (check_product(note[i].name)) {
			int id = get_id_product(note[i].name);
			if (point[id - 1].quantity >= note[i].tmp) {
				point[id - 1].quantity -= note[i].tmp;
				printf("%s.........%.2lf*%.2lf.........%.2lf\n", point[id - 1].name, note[i].tmp, point[id - 1].price_k, point[id - 1].price_k * note[i].tmp);
				final += point[id - 1].price_k * note[i].tmp;
			}
			else if (point[id - 1].quantity > 0) {
				printf("%s.........%.2lf*%.2lf.........%.2lf\n", point[id - 1].name, point[id - 1].quantity, point[id - 1].price_k, point[id - 1].price_k * point[id - 1].quantity);
				final += point[id - 1].price_k * point[id - 1].quantity;
				point[id - 1].quantity = 0.0;
			}
		}
	}
	printf("»того...........................%.2lf", final);
}

int main() {
	setlocale(LC_ALL, "Rus");
	point = (goods*)malloc(sizeof(goods) * size_warehouse);
	create_shop(point, size_warehouse);
	prints(point, size_warehouse);
	FILE* file = fopen("base1.txt", "r+");
	FILE* check = fopen("check.txt", "r+");
	if (file == NULL) {
		return 0;
	}
	while (!feof(file)) {
		long double total;
		char name[100];
		product* array;
		int i = 0;
		while (!feof(file)) {
			fscanf(file, "%s %lf", &(name), &(total));
			i++;
		}
		array = (product*)malloc(sizeof(product) * i);
		fseek(file, 0, SEEK_SET);
		i = 0;
		while (!feof(file)) {
			fscanf(file, "%s %lf", &(array[i].name), &(array[i].tmp));
			i++;
		}
		print_check(array, i);
		


	}


	fclose(file);
	return 0;
}
