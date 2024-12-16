#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "sys/time.h"


double PortableGetTime() {
    struct timeval t;
    gettimeofday(&t, 0);
    return (t.tv_sec * 1000000ULL + t.tv_usec) * 1.0e-6;
}


int is_sorted(int Sorted[], int len){  // проверка на отсортированность
	int i;

	for (i = 0; i < len-1; i++)
		if (Sorted[i] > Sorted[i+1])
			return 0;
	
	return 1;
}


int is_empty(int Array[]){  // проверка: пуст ли массив
	int i;
	char flag = 0;

	for (i=0; i < 10000; i++)
		if (Array[i] != 0){
			flag = 1;
			break;
		}
	
	if (flag == 1)
		return 0;

	else
		return 1;
			
}


char get_status(int Sorted[], int len) {  // 0 - массив пуст, 1 - неотсортирован, 2 - отсортирован
	if (len == 0)
		return 0;

	else{
		if ((is_empty(Sorted) == 1) || ((is_empty(Sorted) == 0) && (is_sorted(Sorted, len) == 0)))
			return 1;

		else
			return 2;
	}
}


void array_elem_swap(int Array[], int i, int j) {  // замена элементов в массиве
	int tmp;

	tmp = Array[i];

	Array[i] = Array[j];
	Array[j] = tmp;
}


void copy_array(int Array[], int Copied[], int len) {  // скопировать массив
	int i;

	for (i = 0; i < len; i++) {
		Copied[i] = Array[i];
	}
}


void bubble_sort(int Array[], int Sorted[], int len, int swaps[], double times[]){  // сортировка пузырьком
	copy_array(Array, Sorted, len);

	int swaps_counter = 0;

	int f;
	
	int i, j;

	double start_t, finish_t;

	start_t = PortableGetTime();

	for (i=0; i<len; i++)
		for (j=0; j < len-i-1; j++)
			if (Sorted[j] > Sorted[j+1]) {
				f = Sorted[j];
				Sorted[j] = Sorted[j+1];
				Sorted[j+1] = f;

				swaps_counter++;
			}

	finish_t = PortableGetTime();
	
	times[0] = finish_t - start_t;
	swaps[0] = swaps_counter;
}


void modified_bubble_sort(int Array[], int Sorted[], int len, int swaps[], double times[]){  // модифицированная сортировка пузырьком
	copy_array(Array, Sorted, len);

	int swaps_counter = 0;

	int left = 0;
	int right = len - 1;

	int flag = 1;

	double start_t, finish_t;

	start_t = PortableGetTime();

	while ((left <= right) && (flag == 1)) {
		int swap_checker = 0;

		for (int i = right; i > left; --i) 
			if (Sorted[i-1] > Sorted[i])
				array_elem_swap(Sorted, i-1, i);
				swaps_counter++;
				swap_checker = 1;
		++left;
		for (int i = left; i < right; ++i)
			if (Sorted[i] > Sorted[i+1])
				array_elem_swap(Sorted, i, i+1);
				swaps_counter++;
				swap_checker = 1;
		--right;

		if (swap_checker == 0)
			flag = 0;
	}

	finish_t = PortableGetTime();
	
	times[1] = finish_t - start_t;
	swaps[1] = swaps_counter;
}


void insertion_sort(int Array[], int Sorted[], int len, int swaps[], double times[]){  // сортировка вставками
	copy_array(Array, Sorted, len);

	int swaps_counter = 0;
	
	double start_t, finish_t;

	start_t = PortableGetTime();

	for (int i = 1; i < len; ++i){
		int x = Sorted[i];
		int j = i;

		while ((j > 0) && (Sorted[j - 1] > x)){
			Sorted[j] = Sorted[j-1];
			--j;
			swaps_counter++;
		}
		Sorted[j] = x;
	}
	
	finish_t = PortableGetTime();

	times[2] = finish_t - start_t;
	swaps[2] = swaps_counter;
}


void selection_sort(int Array[], int Sorted[], int len, int swaps[], double times[]){  // сортировка выбором
	copy_array(Array, Sorted, len);

	int swaps_counter = 0;

	double start_t, finish_t;

	start_t = PortableGetTime();

	for (int i = 0; i < len - 1; i++) {
		int min_id = i;
		for (int j = i + 1; j < len; j++)
			if (Sorted[j] < Sorted[min_id])
				min_id = j;
				swaps_counter++;

		array_elem_swap(Sorted, min_id, i);
	}

	finish_t = PortableGetTime();
	
	times[3] = finish_t - start_t;
	swaps[3] = swaps_counter;
}


void quick_sort(int Array[], int Sorted[], int first_iter, int left, int right, int swaps[]){
	if (first_iter == 1){
		copy_array(Array, Sorted, right);
		first_iter = 0;
	}

	int i, j = 0;
	int swaps_counter = 0;

	int mid = (right + left) / 2;
	int val = Sorted[mid];

	i = left;
	j = right;
	
	while (i <= j) {
		while (Sorted[i] < val) { 
			i++; 
		}

		while (Sorted[j] > val) { 
			j--;  
		}

		if (i <= j) { 
			array_elem_swap(Sorted, i, j);
			i++; j--; 
			swaps_counter += 1; 
		}
	}

	if (j > left) 
		quick_sort(Array, Sorted, first_iter, left, j, swaps);
	
	if (i < right) 
		quick_sort(Array, Sorted, first_iter, i, right, swaps);

	swaps[4] = swaps_counter;
}


int find_max(int Array[], int len)
{
	int max=Array[0], i;
	for (i = 0; i < len; i++)
	{
		if (Array[i] > max)
		{
			max = Array[i];
		}
	}
	return (max);
}

int find_min(int Array[], int len){
	int min = Array[0], i;

	for (i = 0; i < len; i++)
	{
		if (Array[i] < min)
		{
			min = Array[i];
		}
	}
	return (min);
}


void counting_sort(int Array[], int Sorted[], int len, int swaps[], double times[]){
	copy_array(Array, Sorted, len);

	int k = 0;
	int swaps_counter = 0;

	int S[20000] = {0};
	
	int i, j;

	int max, min, abs;
	
	double start_t, finish_t;
	
	start_t = PortableGetTime();
	
	min = find_min(Array, len);
	max = find_max(Array, len);

	if (max < 0)
		max = max * (-1);
	if (min < 0)
		min = min * (-1);
	if (max > min)
		abs = max; 
	else 
		abs = min;

	for (i = 0; i < len; i++){
		S[Sorted[i]+abs]++; 
		swaps_counter++;
	}

	k = 0; 
	swaps_counter++;

	for (i = 0; i <= len; i++){
		for (j = 0; j <= S[i]; j++){
			Sorted[k] = i - abs;
			k++; 
			swaps_counter += 2;
		}
	}

	finish_t = PortableGetTime();

	times[5] = finish_t - start_t;
	swaps[5] = swaps_counter;
}


void linear_search(int Array[], int len){
	int el;

	printf("Enter element: ");
	scanf("%d", &el);

	int flag = 0;

	for (int i = 0; i < len; i++)
		if (Array[i] == el){
			flag = 1;
			printf("Index: %d\n\n", i);
			break;
		}

	if (flag == 0)
		printf("Element is not found\n\n");
}


void binary_search(int Sorted[], int len){
	int el;

	printf("Enter element: ");
	scanf("%d", &el);

	int low, high, middle;

	low = 0;
	high = len - 1;

	int flag = 0;

	while (low <= high) {
		middle = (low + high) / 2;

		if (el < Sorted[middle])
			high = middle - 1;

		else if (el > Sorted[middle])
			low = middle + 1;

		else{
			flag = 1;
			printf("Index: %d\n\n", middle);
			break;
		}
	}

	
	if (flag == 0)
		printf("Element is not found\n\n");
}


void generate_array(int Array[], int Sorted[], int* len, int swaps[], double times[]){  // сгенерировать массив
	for (int i = 0; i < 5; i++)
		swaps[i] = 0;

	int k;
	for (k=0; k<*len; k++)
		Sorted[k] = 0;


	int min, max;

	do {
		printf("Enter the number of array elements (> 1): ");
		scanf("%d", &(*len));
	}
	while (*len <= 1);

	printf("Enter lower border: ");
	scanf("%d", &min);

	do {
		printf("Enter upper border: ");
		scanf("%d", &max);
	}
	while (max <= min);

	printf("\n");

	int i;

	for (i = 0; i < *len; i++){
		Array[i] = min + rand()%(max - min);
	}

	printf("Done!\n\n");
}


void input_array(int Array[], int Sorted[], int* len, int swaps[], double times[]){  // ввод массива
	for (int i = 0; i < 5; i++)
		swaps[i] = 0;

	int k;
	for (k=0; k<*len; k++)
		Sorted[k] = 0;

	do {
		printf("Enter the number of array elements (> 1): ");
		scanf("%d", &(*len));
	}
	while (*len <= 1);
	
	printf("\n");

	int i;

	for (i = 0; i < *len; i++) {
		printf("Element (%d/%d): ", i+1, *len);
		scanf("%d", &Array[i]);
	}
	printf("Done!\n\n");
}


void print_array(int Array[], int len) {  // вывод массива
	printf("{");
	
	int i;

	for (i=0; i < len; i++){
		printf("%d", Array[i]);
		if (i < len - 1)
			printf(", ");
	}

	printf("}");
}


void print_menu(int Array[], int Sorted[], int len, int swaps[], double times[]){  // напечатать меню
	printf("====================\n");

	char status = get_status(Sorted, len);

	switch (status) {
		case 1:
			if (len <= 20) {
				printf("Array: ");
				print_array(Array, len);
				printf("\n\n");
			}
			printf("----------\nStats:\n\n");

			if (swaps[0] != 0)
				printf("Bubble sort: %d iter. | %f sec.\n", swaps[0], times[0]);

			else
				printf("Bubble sort: --\n");

			if (swaps[1] != 0)
				printf("Bubble sort (mod.): %d iter. | %f sec.\n", swaps[1], times[1]);
			else
				printf("Bubble sort (mod.): --\n");

			if (swaps[2] != 0)
				printf("Insertion sort: %d iter. | %f sec.\n", swaps[2], times[2]);
			else
				printf("Insertion sort: --\n");
			
			if (swaps[3] != 0)
				printf("Selection sort: %d iter. | %f sec.\n", swaps[3], times[3]);
			else
				printf("Selection sort: --\n");
			
			if (swaps[4] != 0)
				printf("Quick sort: %d iter. | %f sec.\n", swaps[4], times[4]);
			else
				printf("Quick sort: --\n");

			if (swaps[5] != 0)
				printf("Counting sort: %d iter. | %f sec.\n", swaps[5], times[5]);
			else
				printf("Counting sort: --\n");


			printf("----------\n\n");
			break;

		case 2:
			if (len <= 20) {
				printf("Array: ");
				print_array(Array, len);
				printf("\nSorted array: ");
				print_array(Sorted, len);
				printf("\n\n");
			}

			printf("----------\nStats:\n\n");

			if (swaps[0] != 0)
				printf("Bubble sort: %d iter. | %f sec.\n", swaps[0], times[0]);
			else
				printf("Bubble sort: --\n");

			if (swaps[1] != 0)
				printf("Bubble sort (mod.): %d iter. | %f sec.\n", swaps[1], times[1]);
			else
				printf("Bubble sort (mod.): --\n");

			if (swaps[2] != 0)
				printf("Insertion sort: %d iter. | %f sec.\n", swaps[2], times[2]);
			else
				printf("Insertion sort: --\n");
			
			if (swaps[3] != 0)
				printf("Selection sort: %d iter. | %f sec.\n", swaps[3], times[3]);
			else
				printf("Selection sort: --\n");

			if (swaps[4] != 0)
				printf("Quick sort: %d iter. | %f sec.\n", swaps[4], times[4]);
			else
				printf("Quick sort: --\n");

			if (swaps[5] != 0)
				printf("Counting sort: %d iter. | %f sec.\n", swaps[5], times[5]);
			else
				printf("Counting sort: --\n");


			printf("----------\n\n");
			break;
	}

	printf("Actions: \n");
	
	printf("1. Enter array\n");
	printf("2. Generate array\n");

	switch (status) {
		case 1:
			printf("3. Bubble sort\n");
			printf("4. Modified bubble sort\n");
			printf("5. Insertion sort\n");
			printf("6. Selection sort\n");
			printf("7. Quick sort\n");
			printf("8. Counting sort\n");
			printf("9. Linear search\n");
			break;

		case 2:
			printf("3. Bubble sort\n");
			printf("4. Modified bubble sort\n");
			printf("5. Insertion sort\n");
			printf("6. Selection sort\n");
			printf("7. Quick sort\n");
			printf("8. Counting sort\n");
			printf("9. Linear search\n");
			printf("10. Binary search\n");
			break;

	}

	printf("0. Exit\n");

	printf("====================\n");
}


void do_action(int Array[], int Sorted[], int* len, char* exit_checker, int swaps[], double times[]) {  // выполнение действия
	double quick_time1, quick_time2;

	int action;
	
	printf("\nYour action: ");
	
	while (scanf("%d", &action) != 1) {
		scanf("%*[^\r^\n]");
		fflush(stdout);
	} /* Цикл для очистки буфера на линукс */

	printf("\n");

	char status = get_status(Sorted, *len);

	switch (status) {
		case 0:
			switch (action) {
				case 1:
					printf("\033[0d\033[2J");
					input_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 2:
					printf("\033[0d\033[2J");
					generate_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 0:
					*exit_checker = 1;
					break;

				default:
					printf("\033[0d\033[2J");
					printf("Undefined action!\n\n");
			}
			break;

		case 1:
			switch (action) {
				case 1:
					printf("\033[0d\033[2J");
					input_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 2:
					printf("\033[0d\033[2J");
					generate_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 3:
					printf("\033[0d\033[2J");
					bubble_sort(Array, Sorted, *len, swaps, times);
					break;

				case 4:
					printf("\033[0d\033[2J");
					modified_bubble_sort(Array, Sorted, *len, swaps, times);
					break;

				case 5:
					printf("\033[0d\033[2J");
					insertion_sort(Array, Sorted, *len, swaps, times);
					break;

				case 6:
					printf("\033[0d\033[2J");
					selection_sort(Array, Sorted, *len, swaps, times);
					break;

				case 7:
					printf("\033[0d\033[2J");
					quick_time1 = PortableGetTime();
					quick_sort(Array, Sorted, 1, 0, *len, swaps);
					quick_time2 = PortableGetTime();
					times[4] = quick_time2 - quick_time1;
					break;

				case 8:
					printf("\033[0d\033[2J");
					counting_sort(Array, Sorted, *len, swaps, times);
					break;

				case 9:
					printf("\033[0d\033[2J");
					linear_search(Array, *len);
					break;

				case 0:
					*exit_checker = 1;
					break;

				default:
					printf("\033[0d\033[2J");
					printf("Undefined action!\n\n");
			}
			break;

		case 2:
			switch (action) {
				case 1:
					printf("\033[0d\033[2J");
					input_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 2:
					printf("\033[0d\033[2J");
					generate_array(Array, Sorted, len, swaps, times);
					printf("\033[0d\033[2J");
					break;

				case 3:
					printf("\033[0d\033[2J");
					bubble_sort(Array, Sorted, *len, swaps, times);
					break;

				case 4:
					printf("\033[0d\033[2J");
					modified_bubble_sort(Array, Sorted, *len, swaps, times);
					break;

				case 5:
					printf("\033[0d\033[2J");
					insertion_sort(Array, Sorted, *len, swaps, times);
					break;

				case 6:
					printf("\033[0d\033[2J");
					selection_sort(Array, Sorted, *len, swaps, times);
					break;

				case 7:
					printf("\033[0d\033[2J");
					quick_time1 = PortableGetTime();
					quick_sort(Array, Sorted, 1, 0, *len, swaps);
					quick_time2 = PortableGetTime();
					times[4] = quick_time2 - quick_time1;
					break;

				case 8:
					printf("\033[0d\033[2J");
					counting_sort(Array, Sorted, *len, swaps, times);
					break;


				case 9:
					printf("\033[0d\033[2J");
					linear_search(Array, *len);
					break;

				case 10:
					printf("\033[0d\033[2J");
					binary_search(Sorted, *len);
					break;

				case 0:
					*exit_checker = 1;
					break;

				default:
					printf("\033[0d\033[2J");
					printf("Undefined action!\n\n");
			}
			break;

	}
}


int main() {
	int A[10000] = {0};  // массив
	int B[10000] = {0};  // отсортированный массив
	int n = 0;  // кол-во элементов
	
	char is_exit = 0;

	int swaps[6] = {0};  // количество обменов в сортировках
	double times[6] = {0};   // время сортировок


	srand(time(NULL));

	printf("Make the console bigger to see everything :) \n\n");

	while (is_exit != 1) {
		print_menu(A, B, n, swaps, times);
		do_action(A, B, &n, &is_exit, swaps, times);
	}

	printf("Bye!\n");

	return 0;
}