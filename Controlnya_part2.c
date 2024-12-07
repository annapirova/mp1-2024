#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>

int main()
{
	int n1, n2;
	int element;
	int i, j;
	int nt;
	int flag = 0;
	int index = 0;
	printf("Enter 1-st array's len: \n");
	scanf_s("%d", &n1);
	printf("Enter 2-nd array's len: \n");
	scanf_s("%d", &n2);

	int* array1 = (int*)malloc(n1 * sizeof(int));
	int* array2 = (int*)malloc(n2 * sizeof(int));
	
	if (n2 > n1)
		nt = n2;
	else
		nt = n1;

	int* arrayresult = (int*)malloc(nt * sizeof(int));

	printf("Enter 1-st array's elements: \n");
	for (i = 0; i < n1; i++)
	{
		scanf_s("%d", &element);
		array1[i] = element;
	}

	printf("Enter 2-st array's elements: \n");
	for (i = 0; i < n2; i++)
	{
		scanf_s("%d", &element);
		array2[i] = element;
	}

	for (i = 0; i < nt; i++)
	{
		element = array1[i];
		for (j = 0; j < n2; j++)
		{
			if (array2[j] == array1[i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			flag = 0;
			arrayresult[index] = element;
			index++;
		}
	}
	for (i = 0; i < index; i++)
	{
		printf("%d ", arrayresult[i]);
	}
	return 0;
}
