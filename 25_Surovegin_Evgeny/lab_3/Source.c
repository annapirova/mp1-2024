#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINES  100
#define MAX_LINE_LENGTH  100

struct TOVAR
{
	int code;
	char name[100];
	double price;
	double kg;
};
struct BUY
{
	char name[100];
	double kg;
};
int CHECK(char* p, struct TOVAR* product, int n)
{
	int i = 0;
	while (p[i] != '\0')
	{
		if (p[i] == '\n')
		{
			p[i] = '\0';
		}
		i++;
	}

	int ok = 1;
	i = 0;
	while (p[i] != '\0')
	{
		if (!isdigit(p[i]))
		{
			ok = 0;
			break;
		}
		i++;
	}
	if (ok == 1)
	{
		return(1);
	}
	for (int i = 0; i < n; i++)
	{
		if (strcmp(p, product[i].name) == 0)
		{
			return(3);
		}
	}
	return(2);
}
int COUNT(char* name)
{
	int i = 0;
	char tmp[MAX_LINE_LENGTH];
	FILE* f = fopen(name, "r");
	if (f != NULL)
	{
		while (fgets(tmp, MAX_LINE_LENGTH, f) != NULL)
		{
			i++;
		}
		fclose(f);
	}
	return i;
}
int MASSIV(char* name, struct BUY* buy, struct TOVAR* product, int n)
{
	char* p, end;
	int i = 0;
	char tmp[MAX_LINE_LENGTH];
	FILE* f = fopen(name, "r");
	if (f != NULL)
	{
		while (fgets(tmp, MAX_LINE_LENGTH, f) != NULL)
		{
			struct BUY b;
			b.kg = -1;
			b.name[0] = '0';

			p = strtok(tmp, " ");
			while (p != NULL)
			{
				// создать массив структур дл€ товара который хот€т купить, сравнивать название товара до 2 буквы с конца, если все норм -> в чек, в check смотрим пор€док ввода и добавл€ем в массив структур;
				int ok = CHECK(p, product, n);
				if (ok == 1)
				{
					b.kg = atof(p);
				}
				else if (ok == 3)
				{
					strcpy(b.name, p);
				}
				p = strtok(NULL, " ");
			}

			if (b.kg != -1 && b.name[0] != '0')
			{
				buy[i].kg = b.kg;
				strcpy(buy[i].name, b.name);

				i++;
			}
		}
		fclose(f);
	}

	return i;
}

void Tovar(struct TOVAR* product, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("¬ведите штрихкод\n");
		scanf_s("%d", &(product[i]).code);
		printf("¬ведите название\n");
		scanf_s("%s", &(product[i]).name, 100);
		printf("¬ведите цену за кг\n");
		scanf_s("%lf", &(product[i]).price);
		printf("¬ведите количество товара\n");
		scanf_s("%lf", &(product[i]).kg);
	}
}
void PRINT(char* name, struct BUY* buy, int buyCount, struct TOVAR* product, int n)
{
	FILE* f = fopen(name, "w");
	for (int i = 0; i < buyCount; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (strcmp(buy[i].name, product[j].name)==0)
			{
				if (buy[i].kg <= product[j].kg)
				{
					fprintf(f, "%s %lf", buy[i].name, buy[i].kg*product[j].price);
					fprintf(f, "\n");
				}
				else
				{
					fprintf(f, "%s %lf", buy[i].name, product[j].kg * product[j].price);
					fprintf(f, "\n");
				}
			}
		}
	}
	fclose(f);
}
int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	printf("¬ведите число товаров на складе\n");
	scanf_s("%d", &n);
	while (n < 0)
	{
		printf("¬ведите число товаров на складе\n");
		scanf_s("%d", &n);
	}
	struct TOVAR* product;
	product = (struct TOVAR*)malloc(sizeof(struct TOVAR) * n);
	Tovar(product, n);
	//char check[100];
	struct BUY* buy = NULL;
	char* name = "D:\\my.txt";
	char* out  = "D:\\my1.txt";
	int buyCount = COUNT(name);
	buy = (struct BUY*)malloc(sizeof(struct BUY) * buyCount);
	int found = MASSIV( name, buy, product,n);
	PRINT(out, buy, found, product, n);
	free(product);
	free(buy);
}
