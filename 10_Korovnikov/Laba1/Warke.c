#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "time.h"


void StandMassive(int A[], int n)
{
	for (int i = 0; i < n; i++) { printf("El.%d: ", i + 1); scanf_s("%d", &A[i]); }
	printf("Massive: ");
	for (int i = 0; i < n; i++) { printf("%d ", A[i]); }

}
void RandMassive(int A[], int n)
{
	int a, b;
	srand(time(NULL));
	printf("Vvedite granici massiva ot naimens k naibols:\n");
	scanf_s("%d %d", &a, &b);
	for (int i = 0; i < n; i++) { A[i] = a + rand() % (b - a); }
	printf("Massive: \n");
	for (int i = 0; i < n; i++) { printf("%d ", A[i]); }

}
int LinSearch(int A[], int a)
{
	int i = 0, k = 0, val;
	printf("\n");
	printf("Vvedite iskovoe chislo: ");
	scanf_s("%d", &val);
	while ((i < a) && (A[i] != val))
	{
		i++;
		if (i < a)
			k = i;
		else printf("Takogo elementa net!");
	}
	if (a != i)
		printf("Nashel, ego index = %d", k);
	return k;
}
int BinSearch(int A[], int a)
{
	int l, r, m, f, val;
	l = 0;
	r = a - 1;
	f = 0;
	printf("\n");
	printf("Vvedite iskovoe chislo: ");
	scanf_s("%d", &val);
	while ((l != r) && (!f))
	{
		m = (l + r) / 2;
		if (val > A[m]) l = m + 1;
		else
			if (val < A[m])  r = m - 1;
			else f = 1;
	}
	if (A[m] != val) printf("Takogo elementa net!");
	else printf("Nashel, ego index = %d", m);
	return m;
}
void BubbleSort(int A[], int a, double Stat1[], int Stat2[])
{
	clock_t start = clock();
	int f, k = 0;
	for (int i = 0; i < a; i++)
		for (int j = 0; j < a - i - 1; j++)
			if (A[j] > A[j + 1]) { f = A[j]; A[j] = A[j + 1]; A[j + 1] = f; k += 3; }
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent);
	printf("Kol-vo iterac. - %d", k);
	Stat2[1] = k; Stat1[1] = time_spent;

}
void QS(int A[], int left, int right, double Stat1[], int Stat2[])
{
	int i, j, tmp, k, a, p = 0;
	int mid = (right + left) / 2;
	int val = A[mid];
	i = left;
	j = right;
	a = right + 1;
	clock_t start = clock();
	while (i <= j)
	{
		k = 0; p += 1;
		while (A[i] < val) { i++; p += 1; }
		while (A[j] > val) { j--; p += 1; }
		if (i <= j) { k = -1; tmp = A[i]; A[i] = A[j]; A[j] = tmp; i++; j--; p += 6; }
	}

	if (j > left) QS(A, left, j, Stat1, Stat2);
	if (i < right) QS(A, i, right, Stat1, Stat2);
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	//printf("\n");
	//printf("Sort time = %.8f \n", time_spent);
	//printf("Kol-vo iterac. - %d", p);
	Stat2[5] = p;

}
void merge(int A[], int l, int mid, int r,int Stat2[]) {
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int L[10000], R[10000];
	for (i = 0; i < n1; i++)
		L[i] = A[l + i]; Stat2[7]++;
	for (j = 0; j < n2; j++)
		R[j] = A[mid + 1 + j]; Stat2[7]++;
	i = 0;
	j = 0;
	k = l; Stat2[7]+=3;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			i++; Stat2[7]+=2;
		}
		else {
			A[k] = R[j];
			j++; Stat2[7]+=2;
		}
		k++; Stat2[7]++;
	}
	while (i < n1) {
		A[k] = L[i];
		i++;
		k++; Stat2[7]+=3;
	}
	while (j < n2) {
		A[k] = R[j];
		j++;
		k++; Stat2[7]+=3;
	}
}
void MergeSort(int A[], int l, int r, double Stat1[], int Stat2[]) {
	clock_t start = clock();
	if (l < r) {
		int mid = l + (r - l) / 2; Stat2[7]++;
		MergeSort(A, l, mid, Stat1, Stat2); Stat2[7]++;
		MergeSort(A, mid + 1, r,Stat1,Stat2); Stat2[7]++;
		merge(A, l, mid, r,Stat2); Stat2[7]++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Sort time = %.8f \n", time_spent); Stat1[7]=time_spent;
}

void VivodOts(int A[], int a)
{
	printf("\n");
	printf("Otsort massive:");
	for (int i = 0; i < a; i++)
		printf("%d ", A[i]);
}
void Vivod(int A[], int a)
{
	printf("\n");
	printf("Massive:");
	for (int i = 0; i < a; i++)
		printf("%d ", A[i]);
}


void TwoBubble(int A[], int a, double Stat1[], int Stat2[])
{
	int f = 1, left = 0, right = a - 1, k = 0, tmp;
	clock_t start = clock();
	while (left <= right && f==1)
	{
		f = 0;
		for (int i = right; i > left; --i)
		{
			if (A[i - 1] > A[i]) { tmp = A[i]; A[i] = A[i - 1]; A[i - 1] = tmp; f = 1; k += 3; }
		}
		++left; k++;
		for (int i = left; i < right; ++i)
		{
			if (A[i + 1] < A[i]) { tmp = A[i]; A[i] = A[i + 1]; A[i + 1] = tmp; f = 1; k += 3; }
		}
		--right; k++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", k); Stat1[2] = time_spent; Stat2[2] = k;

}

void VstavkaSort(int A[], int a, double Stat1[], int Stat2[])
{
	int j, k = 0;
	clock_t start = clock();
	for (int i = 1; i < a; ++i)
	{
		int tmp = A[i];
		for (j = i - 1; j >= 0 && A[j] > tmp; --j)
		{
			A[j + 1] = A[j]; k++;
		}
		A[j + 1] = tmp; k++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", k); Stat1[3] = time_spent; Stat2[3] = k;
}
void ViboromSort(int A[], int a, double Stat1[], int Stat2[])
{
	int z = 0;
	clock_t start = clock();
	for (int i = 1; i < a; i++)
	{
		int k = A[i]; int s = i - 1;
		while (s>=0 && A[s]>k)
		{
			A[s + 1] = A[s];
			s--;
			z+=2;
		}
		A[s + 1] = k; z++;
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.8f \n", time_spent); printf("Kol-vo iterac. - %d", z); Stat1[4] = time_spent; Stat2[4] = z;
}

void PodschetSort(int A[], int a, double Stat1[], int Stat2[])
{
	int  k, z = 0, max = -10000000000, min = 1000000000, absol;
	int S[20000] = { 0 };
	clock_t start = clock();
	for (int i=0;i<a;i++)
	{
		if (A[i] > max)max = A[i];
		if (A[i] < min)min = A[i];
	}
	if (max < 0)max = max * (-1);
	if (min < 0)min = min * (-1);
	if (max > min)absol = max; else absol = min;
	for (int i = 0; i < a; i++)
	{
		S[A[i] +absol]++; z++;
	}
	k = 0; z++;
	for (int i = 0; i <= 20000; i++)
	{
		for (int j = 0; j < S[i]; j++)
		{
			A[k] = i - absol;
			k++; z += 2;
		}
	}
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\n");
	printf("Sort time = %.f \n", time_spent); printf("Kol-vo iterac. - %d", z); Stat1[6] = time_spent; Stat2[6] = z;
}
void Pere() { printf("\n"); }
void menu()
{
	printf("1.Bubble Sort\n");
	printf("2.Two Bubble Sort\n");
	printf("3.Sort Vstavkami\n");
	printf("4.Sort Viborom\n");
	printf("5.Quick Sort\n");
	printf("6.Podschet Sort\n");
	printf("7.Merge Sort\n");
	printf("8.LinSearch\n");
	printf("9.BinSearch\n");
	printf("10. Drygoi massiv\n");
	printf("11.Exit\n");
}
void CopyMass(int A[], int Cop[], int n)
{
	for (int i = 0; i < n; i++) { Cop[i] = A[i]; }
}
void STAT(double Stat1[], int Stat2[])
{
	printf("-------------------------\n");
	for (int i = 1; i < 8; i++)
	{
		switch (i)
		{
		case 1: printf("Bubble: "); break;
		case 2: printf("TwoBubble: "); break;
		case 3: printf("Vstavka: "); break;
		case 4: printf("Vibor: "); break;
		case 5: printf("QS: "); break;
		case 6: printf("Podschet: "); break;
		case 7: printf("Merge: "); break;
		}
		printf("time - %f  ", Stat1[i]); printf("iter. - %d  ", Stat2[i]);
		printf("\n");
	}
	printf("-------------------------\n");
}
void Proverka(int A[], int n)
{
	int k = 0;
	for (int i = 0; i < n - 1; i++)  if (A[i] > A[i + 1]) k++;
	if (k > 1) printf("Ne otsort!");
	else printf("Otsort!");
}
void emae()
{
	int A[10000] = { 0 };
	int Acopy[10000] = { 0 };
	double Stat1[8] = { 0 };
	int Stat2[8] = { 0 };
	int c = 100;
	int a; int s = 100; int f = 0; double t = 0; int k = 0, mid;
	printf("Vvedite kol-vo elementov massiva: ");
	scanf_s("%d", &a);
	mid = (a / 2);
	printf("Vibirite tip zadaniya massiva:"); Pere();
	printf("1. Vvod svoego"); Pere();
	printf("2. Random massive"); Pere();
	while ((c != 1) && (c != 2))
	{
		scanf_s("%d", &c);
		switch (c)
		{
		case 1: StandMassive(A, a); break;
		case 2: RandMassive(A, a); break;
		default:
			printf("Takogo varianta net, viberi drygoi!\n");
			Pere();
			break;
		}
	}
	Pere();
	while (s != 11)
	{
		Pere(); Vivod(A, a); Pere(); Pere(); menu(); Pere(); printf("Deistvie? :");
		while (s != 11)
		{
			scanf_s("%d", &s);
			switch (s)
			{
			case 1: CopyMass(A, Acopy, a); BubbleSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); f = 1; Pere(); break;
			case 2: CopyMass(A, Acopy, a); TwoBubble(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 3: CopyMass(A, Acopy, a); VstavkaSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 4: CopyMass(A, Acopy, a); ViboromSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 5: CopyMass(A, Acopy, a); clock_t start = clock(); QS(Acopy, 0, a, Stat1, Stat2);clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC; Stat1[5] = time_spent; VivodOts(Acopy, a); Pere(); f = 1; break;
			case 7:CopyMass(A, Acopy, a); MergeSort(Acopy,0,a-1,Stat1,Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 6:CopyMass(A, Acopy, a); PodschetSort(Acopy, a, Stat1, Stat2); VivodOts(Acopy, a); Pere(); f = 1; break;
			case 8: LinSearch(A, a); Pere(); break;
			case 9:
				if (f == 1) { BinSearch(Acopy, a); Pere(); }
				else
				{
					printf("Massiv ne otsort!"); s = 100; Pere(); printf("Zanogo"); Pere();
				}
				break;
			case 10: emae(); break;
			case 11:printf("$Exit$"); break;
			default:
				printf("Takogo varianta net, viberi drygoi!\n");
				break;

			}
			if (s == 11)break;
			STAT(Stat1, Stat2);  Pere(); menu(); Pere(); printf("Deistvie? :");

		}
	}


}
int main()
{
	printf("Hello!");
	Pere();
	emae();
}