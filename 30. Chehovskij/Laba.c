#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


int minim(int a[], int n) {
	int i;
	int mini = 10000000;
	for (i = 0; i < n; i++) {
		if (mini > a[i]) {
			mini = a[i];
		}

	}
	return mini;
}

int maxim(int a[], int n) {
	int i;
	int maxi = -10000000;
	for (i = 0; i < n; i++) {
		if (maxi < a[i]) {
			maxi = a[i];
		}
	}
	return maxi;
}



void Sort_vstavkami(int a[], int n)
{
	int i, count = 0;
	clock_t start, finish;
	start = clock();
	for (i = 1; i < n; i++) {
		int x = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > x) {
			a[j] = a[j - 1];
			j--;
			count++;
		}
		a[j] = x;
	}
	count++;
	printf("Kol-vo operaciy: %d\n", count);

}


void bubblesort2(int a[], int n) {
	int flag = 0, count = 0;
	int l = 0, r = l - 1, cnt = 0;
	while ((l <= r) && (flag == 0)) {
		flag = 0;
		for (int i = r; i > l; i--) {
			if (a[i - 1] > a[i]) {
				int t = a[i - 1];
				a[i - 1] = a[i];
				a[i] = t;
				flag = 1;
			}
			count++;
		}
		++l;
		cnt++;
		for (int i = l; i < r; i++) {
			if (a[i] > a[i + 1]) {
				int t = a[i + 1];
				a[i + 1] = a[i];
				a[i] = t;
				flag = 1;
			}
			count++;
		}
		--r;
		count++;
	}
	printf("Kol-vo operaciy: %d\n", count);
}

void merge(int a[], int l, int mid, int r) {
	int i, j, k;
	int a1 = mid - l + 1;
	int a2 = r - mid;
	int L[1000], R[1000];
	for (i = 0; i < a1; i++)
		L[i] = a[l + i];
	for (j = 0; j < a2; j++)
		R[j] = a[mid + 1 + j];
	i = 0;
	j = 0;
	k = l;

	while (i < a1 && j < a2) {
		if (L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < a1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while (j < a2) {
		a[k] = R[j];
		j++;
		k++;
	}
}
void slian_sort(int a[], int l, int r) {
	if (l < r) {
		int mid = l + (r - l) / 2;
		slian_sort(a, l, mid);
		slian_sort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
	printf("\n");
}



int bubblsort(int a[], int n) {
	int val, count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				val = a[i];
				a[i] = a[j];
				a[j] = val;
			}
			count++;
		}
		count++;

	}
	count++;
	printf("Kol-vo operaciy: %d\n", count);
	return n;
}




void sort_vuborom(int a[], int n) {
	int i, j, count = 0;
	clock_t start, finish;
	start = clock();
	for (i = 0; i < n; i++) {
		int min = a[i];
		int index = i;
		for (j = i + 1; j < n; j++) {
			if (a[j] < min) {
				index = j;
				min = a[j];
				count++;
			}
		}
		if (index != i) {
			int notes = a[i];
			a[i] = min;
			a[index] = notes;
			count++;
		}
	}
	finish = clock();
	printf("\n");
	count++;
	printf("Kol-vo operaciy: %d\n", count);
	printf("\n");
}


void Quick_Sort(int a[], int l, int p) {
	int i, j, tmp, count = 0;
	int mid = (l + p) / 2;
	int val = a[mid];
	i = l;
	j = p;
	while (i <= j) {
		count++;
		while (a[i] < val) i++;
		while (a[j] > val) j--;
		if (i <= j) { tmp = a[i]; a[i] = a[j]; a[j] = tmp; i++; j--; }
		count++;
	}
	   
	if (j > l) Quick_Sort(a, l, j);
	count++;
	if (i < p) Quick_Sort(a, i, p);
	count++;
	printf("Kol-vo operaciy: %d\n", count);

}





static void vubor_vvoda_massive() {
	printf("1.Vvedu sam\n");
	printf("2.Random massive\n");
}
void random_massive(int a[],int b[], int n) {
	srand(100);
	int i, l;
	for (i = 0; i < n; i++) {
		l = rand() % 100;
		a[i] = l;
		b[i] = l;

	}
}

void linpoisk(int a[], int n) {
	int i, x, flag = 0, count = 0;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
	for (i = 0; i < n; i++) {
		if (a[i] == x) {
			flag = i;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d", flag);
		printf("\n");
	}
	else {
		printf("chisla net v massive");
		printf("\n");
	}
}

int proverka(int a[], int n) {
	int i, c;
	for (i = 0; i < n - 1; i++) {
		if (a[i] > a[i + 1]) {
			return 0;
		}
	}
	printf("massiv_otsortirivan");

}
void b_poisk(int a[], int n) {
	int x, flag = 0, count = 0;
	int l = 0, r = n - 1, c;
	printf("Vvedite x\n");
	scanf_s("%d", &x);
	flag = 0;
	while (l <= r) {
		c = (l + r) / 2;
		if (a[c] > x) {
			r = c - 1;
		}
		else if (a[c] < x) {
			l = c + 1;
		}
		else {
			flag = c;
			break;
		}
	}
	if (flag != 0) {
		printf("chislo naydeno, index - %d\n", flag);
	}
	else {
		printf("chisla net v massive\n");
	}

}




void podschet_sort(int a[], int n) {
	int k, sdvig;
	int flag = 0;
	if (minim(a, n) < 0) {
		k = (minim(a, n) * -1);
		sdvig = (minim(a, n) * -1) + maxim(a, n) + 1;
		flag = 1;
	}
	else {
		k = maxim(a, n);
		sdvig = maxim(a, n) + 1;
	}

	int arr[100];
	int count = 0;
	int i;
	for (i = 0; i < sdvig; i++) {
		arr[i] = 0;
		count++;
	}
	for (i = 0; i < n; i++) {
		if (minim(a, n) < 0) {
			arr[a[i] + k] += 1;
		}
		else {
			arr[a[i]] += 1;
		}
		count++;
	}
	int index = 0;
	for (i = 0; i < sdvig; i++) {
		while (arr[i] != 0) {
			if (flag) {
				a[index] = i - (-1 * minim(a, n));
			}
			else {
				a[index] = i;
			}
			arr[i]--;
			index++;
			count++;
		}
	}
	for (i = index; i < n; i++) {
		a[index] = 0;
		count++;
	}
	printf("Kol-vo operaciy: %d\n", count);

}





void menu()
{
	printf("1. b_poisk \n");
	printf("2. linpoisk\n");
	printf("3. sort_vuborom\n");
	printf("4. Quick_Sort\n");
	printf("5. Sort_vstavkami\n");
	printf("6. bublsort\n");
	printf("7. bubblesort2\n");
	printf("8. slian_sort\n");
	printf("9. podschet_sort\n");
	printf("10. Exit\n");
}




void genmassiva_sam(int a[], int b[], int n)
{
	int i, l;
	
	for (i = 0; i < n; i++) {
		scanf_s("%d", &l);

		a[i] = l;
		b[i] = l;
	}

}

void vivodmassive(int a[], int n) {

	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}


int copy(int a[], int b[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		a[i] = b[i];
	}
}




int main() {
	int c, n, g = 1, i;
	int a[100];
	int b[100];
	clock_t start, finish;
	int count = 0;
	vubor_vvoda_massive();

	scanf_s("%d", &c);
	if ((c == 1) || (c == 2)) {
		if (c == 1) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			genmassiva_sam(a, b, n);
			vivodmassive(a, n);
			
			
			


		}
		if (c == 2) {
			printf("Vvedite dliny massiva\n");
			scanf_s("%d", &n);
			random_massive(a, b,n);
			vivodmassive(a, n);
			



		}
		printf("\n");
		




		while (g != 10) {
			copy_list(a, b, n);
			printf("Vubrite sortirovky ili poisk\n");
			menu();
			scanf_s("%d", &g);
			switch (g)
			{
			case 1: {

				
				b_poisk(a, n);
				break;
			}
			case 2: {


				linpoisk(a, n);
				break;
			}
			case 3: {
			
				start = clock();

				sort_vuborom(a, n);

				printf("\n");
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n");
				break;

			}
			case 4: {
				start = clock();
				Quick_Sort(a, 0, n - 1);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n");
				break;
			}
			case 5: {
				start = clock();
				Sort_vstavkami(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n");
				break;

			}
			case 6: {
				start = clock();
				bubblsort(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n");
				break;
			}
			case 7: {
				start = clock();
				bubblesort2(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n"); ;
				break;

			}
			case 8: {
				start = clock();
				slian_sort(a, 0, n - 1);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n"); ;
				break;
			}
			case 9: {
				start = clock();
				podschet_sort(a, n);
				finish = clock();
				double duration = (double)(finish - start) / CLOCKS_PER_SEC;
				printf("Vremya: %f sec\n ", duration);
				vivodmassive(a, n);
				printf("\n");
				proverka(a, n);
				printf("\n"); ;
				break;


			}
			case 10: {
				printf("Vuhod");
				printf("\n");

			}

			}

			printf("Programma zavershena");
			printf("\n");
		}

	}
}
