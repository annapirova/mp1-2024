#include<stdio.h>
#include <locale.h>

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
	int ok = 1;
	int i = 0;
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
		for (int j = 0; j < n; j++)
		{
			if (strcmp(p[i], product[j].name) == 0)
			{
				return(3);
			}
		}
	}
	return(2);
}
int MASSIV(char* name, struct BUY* buy, struct TOVAR* product, int n)
{
	char* p, end;
	int i = 0;
	//struct BUY A[100];
	FILE* f = fopen(name, "r");
	char tmp[MAX_LINE_LENGTH];

	if (f != NULL)
	{
		while (!feof(f))
		{
			fgets(tmp, MAX_LINE_LENGTH, f);
			p = strtok(tmp, " ");
			//printf("%s\n", buf);
			while (p != NULL)
			{
				// создать массив структур дл€ товара который хот€т купить, сравнивать название товара до 2 буквы с конца, если все норм -> в чек, в check смотрим пор€док ввода и добавл€ем в массив структур;
				int ok = CHECK(p, product, n);
				if (ok == 1)
				{
					buy[i].kg = strtod(*p, &end);
				}
				else if (ok == 3)
				{
					strcpy(buy[i].name, p);
				}
				p = strtok(NULL, " ");
			}
			i++;
		}
		fclose(f);
	}
	return i;
}
void Tovar(struct TOVAR* product, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("¬ведите штрихкод");
		scanf_s("%d", &(product[i].code));
		printf("¬ведите название");
		scanf_s("%s", &(product[i].name),sizeof(char)*100);
		printf("¬ведите цену за кг");
		scanf_s("%lf", &product[i].price);
		printf("¬ведите количество товара");
		scanf_s("%lf", &product[i].kg);
	}
}
void PRINT(char* name, struct BUY* buy, int count, struct TOVAR* product, int n)
{
	FILE* f = fopen(name, "w");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < count; j++)
		{
			if (strcmp(buy[i].name, product[j].name))
			{
				if (buy[i].kg <= product[j].kg)
				{
					fprintf(f, "%s" "%lf", buy[i].name, buy[i].kg*product[j].price);
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
	printf("¬ведите число товаров");
	scanf_s("%d", &n);
	while (n < 0)
	{
		printf("¬ведите число товаров");
		scanf_s("%d", &n);
	}
	struct TOVAR* product;
	product = (struct TOVAR*)malloc(sizeof(struct TOVAR) * n);
	Tovar(product, n);
	//char check[100];
	struct BUY buy[100];
	char* name = "D:\my.txt";
	char* out  = "D:\my1.txt";
	int buyCount = MASSIV( name, buy, product,n);


	PRINT(out, buy, buyCount, product,n);
	free(product);
}