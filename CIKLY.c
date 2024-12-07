////Задача на циклы сложная сложность номер 25
#include <stdio.h>

int is_shcatliv(int ticket)
{
	int n1, n2, n3, n4, n5, n6;
	n6 = ticket % 10;
	ticket /= 10;
	n5 = ticket % 10;
	ticket /= 10;
	n4 = ticket % 10;
	ticket /= 10;
	n3 = ticket % 10;
	ticket /= 10;
	n2 = ticket % 10;
	ticket /= 10;
	n1 = ticket % 10;
	return (n1 + n2 + n3) == (n4 + n5 + n6);
}

int main()
{
	int n;
	int ticket;
	int i;
	int counter = 0;
	printf("Enter number of tickets\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		printf("Enter ticket's number: \n");
		scanf_s("%d", &ticket);
		if (is_shcatliv(ticket))
			counter++;
	}
	printf("Count schastliv = %d", counter);
}
