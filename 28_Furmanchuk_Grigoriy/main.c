#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "locale.h"
#include "stdbool.h"
#include <time.h>
//#define _CRT_SECURE_NO_WARNINGS


struct prod {
	char nameof[50];
	int numof;
};

struct tovar {
	int code;
	char name[50];
	double price;
	double wt;
};


void get_list(struct prod arr[], int n) {
	int i;
	printf("Введите сначала название товара, а затем его количество количество в шт. \n ");
	for (i = 0; i < n; i++) {
		char s[50];
		//fgets(s, 50, stdin);
		scanf_s("%s", arr[i].nameof, 50);
		scanf_s("%d", &arr[i].numof);
	}
}

//bool mass_chekc(int m, struct tovar skl[], int id) {
//	return skl[id].wt - m;
//}

int sklad_check(char s[], struct tovar* skl) {
	int i;
	for (i = 0; i < 5;i++) {
		if (strcmp(s, skl[i].name) == 0) return i;
	}
	return -1;
}



void get_bill(struct prod arr[], int n, struct tovar skl[], struct tovar bll[]) {
	int i = 0, id;
	double mass; // skl[id] = arr[i].numof * rand.
	double kg;
	double a = 5.0;
	srand(time(NULL));
	while (i < n) {
		/*bll[i].price = 0.0;
		bll[i].wt = 0.0;
		bll[i].code = -1;*/
		id = sklad_check(arr[i].nameof, skl);
		if (id != -1) {
			strcpy(&bll[id].name, &skl[id].name);
			kg = (double)rand() / (double)(RAND_MAX)*a;
			mass = kg * arr[i].numof;
			if (mass > skl[id].wt) {
				printf("На складе находиться меньшее количество чем вам нужно. Забирайте весь склад\n");
				mass = skl[id].wt;
			}
			bll[id].price += mass * skl[id].price;
			bll[id].wt += mass;
			//bll[id].code = skl[id].code;
			/*if (id != -1) {
				printf("%s....%lf * %lf....%lf\n", skl[id].name, mass, skl[id].price, res);
			}*/
		}
		if (id == -1) printf("товара %s нет на складе\n", arr[i].nameof);
		i += 1;
	}
}


int main(void) {
	int i, j;
	int n;
	double sum = 0.0;
	struct prod* list;
	struct tovar bill[5] = { {0, "-", 0.0, 0.0}, {1, "-", 0.0, 0.0}, {2, "-", 0.0, 0.0}, {3, "-", 0.0, 0.0}, {4, "-", 0.0, 0.0} };
	struct tovar sklad[5] = { {0, "b", 100.0, 28.0}, {1, "a", 101.0, 32.3}, {2, "t", 105.0, 4.0}, {3, "o", 102.0, 19.0}, {4, "p", 104.0, 14.0} };
	setlocale(LC_ALL, "rus");
	printf("Количество товаров: ");
	scanf_s("%d", &n);
	list = (struct prod*)malloc(sizeof(struct prod) * n);
	printf("Список товаров: \n");
	get_list(list, n);
	get_bill(list, n, sklad, bill);
	for (i = 0; i < 5; i++) {
		if (bill[i].price != 0.0) {
			
			printf("%s....%lf * %lf....%lf\n",bill[i].name, bill[i].wt, bill[i].price / bill[i].wt, bill[i].price);
			sum += bill[i].price;
		}
	}
	printf("Сумма................%lf", sum);

}