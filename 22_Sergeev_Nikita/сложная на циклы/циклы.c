#include <stdio.h>

int main() {
	
	for (int i = 1; i < 28; i++) {
		for (int j = 100; j < 1000; j++) {
			int m3 = j % 10;
			int m2 = ((j % 100) - m3) / 10;
			int m1 = (j - m2) / 100;
			if (i == m1 + m2 + m3) {
				printf("%d\n", j);
			}
		}
	}

	return 0;
}