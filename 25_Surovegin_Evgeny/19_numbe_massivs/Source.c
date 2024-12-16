#include<stdio.h>
#include<stdlib.h>
struct ocenki_ex
{
	int k1;
	int k2;
	int k3;
	int k4;
	int k5;
};
int main()
{
	int predmet = 3;
	int n;
	struct ocenki_ex* p;
	p = malloc(sizeof(struct ocenki_ex) * predmet);
	for (int i = 0; i < predmet; i++)
	{
		p[i].k1 = 0;
		p[i].k2 = 0;
		p[i].k3 = 0;
		p[i].k4 = 0;
		p[i].k5 = 0;
	}
	printf("Kol-vo students\n");
	scanf_s("%d", &n);
	int** a;
	a = (int**)malloc(sizeof(int*) * n);
	for (int i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * predmet);
	}
	printf("Ocenki\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < predmet; j++)
		{
			scanf_s("%d", &a[i][j]);
			while (a[i][j] > 5 || a[i][j] < 1)
			{
				scanf_s("%d", &a[i][j]);
			}
		}
		//printf("\n");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < predmet; j++)
		{
			switch (a[i][j])
			{
				case(1):
				{
					p[j].k1++;
					break;
				}
				case(2):
				{
					p[j].k2++;
					break;
				}
				case(3):
				{
					p[j].k3++;
					break;
				}
				case(4):
				{
					p[j].k4++;
					break;
				}
				case(5):
				{
					p[j].k5++;
					break;
				}
			}
		}
	}
	for (int i = 0; i < predmet; i++)
	{
		printf("predmet #%d\n", i+1);
		printf("'1'=%d '2'=%d '3'=%d '4'=%d '5'= %d \n", p[i].k1, p[i].k2, p[i].k3, p[i].k4, p[i].k5);

	}
	for (int i = 0; i < n; i++)
	{
		free(a[i]);
	}
	free(a);
	free(p);
}