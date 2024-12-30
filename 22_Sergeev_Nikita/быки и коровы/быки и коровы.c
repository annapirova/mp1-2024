#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "rus");

	srand(time(0));
	int random_number = rand() % 9000 + 1000;
	int ch = 0;

	int r4 = random_number % 10;
	int r3 = ((random_number % 100) - r4) / 10;
	int r2 = ((random_number % 1000) - r3) / 100;
	int r1 = (random_number - r2) / 1000;
	printf("%d\n", random_number);

	while (ch != random_number) {

		printf("введите четырехзначное число\n");
		scanf_s("%d", &ch);
		if (ch < 1000 || ch > 9999) {
			printf("Ошибка! Введите четырехзначное число.\n");
			continue;
		}

		int k = 0;
	
		int m4 = ch % 10;
		int m3 = ((ch % 100) - m4) / 10;
		int m2 = ((ch % 1000) - m3) / 100;
		int m1 = (ch - m2) / 1000;

		if (r1 == m1) k++;
		if (r2 == m2) k++;
		if (r3 == m3) k++;
		if (r4 == m4) k++;
		
		int b = 0;

		int r_digits[4] = {r1, r2, r3, r4};
		int m_digits[4] = {m1, m2, m3, m4};

		int r_used[4] = {0};
		int m_used[4] = {0};

		for (int i = 0; i < 4; i++) {
			if (r_digits[i] == m_digits[i]) {
				r_used[i] = 1;
				m_used[i] = 1;
			}
		}

		
		for (int i = 0; i < 4; i++) {
			if (m_used[i] != 1) { 
				for (int j = 0; j < 4; j++) {
					if (r_used[j] != 1 && m_digits[i] == r_digits[j]) {
						b++;
						r_used[j] = 1;
						m_used[i] = 1;
						break;
					}
				}
			}
		}

		
		if (k == 0) printf("0 коров\n");
		else if (k == 1) printf("1 корова\n");
		else if (k > 1) printf("%d коровы\n", k);

		if (b == 0) printf("0 быков\n");
		else if (b == 1) printf("1 бык\n");
		else if (b > 1) printf("%d быка\n", b);
		
		if (ch == random_number) {
			printf("Вы угадали число: %d\n", random_number);
			break;
		}
	}



	return 0;
}