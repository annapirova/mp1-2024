
#include <math.h>
//
//#define and &&
//#define or ||
//
//struct food {
//	double price;
//	char name[100];
//	double n;
//}; 
//
//
//typedef struct food food; 
//
//food sklad[100] = { 
//	{105, "banana", 3},
//	{300, "tomato", 3},
//	{60, "tomato", 3},
//	{110, "apple", 3},
//	{75, "pear", 3},
//	{110, "kiwi", 3}, 
//	{75, "cucumber", 3}};
//
//char primes[100][100] = { '1', '0', '2', '3', '4', '5', '6', '7', '8', '9' };
//
//char products[14][10] = { "banana", "tomato" , "potato", "apple", "pear", "kiwi", "cucumber" };
//
//int def(char s[]) {
//	if (s == '1') return 1; 
//	else if (s == '2') return 2;
//	else if (s == '3') return 3;
//	else if (s == '4') return 4;
//	else if (s == '5') return 5;
//	else if (s == '6') return 6;
//	else if (s == '7') return 7;
//	else if (s == '8') return 8;
//	else if (s == '9') return 9;
//	else return 0; 
//}
//
//int dlina(double price) {
//	char str[100];
//	sprintf(str, "%lf", price);
//	return strlen(str);
//}
//
//void cout_checka(char s[], double g, double price) {
//	printf("Name         Price             Kolichestvo\n"); 
//	printf("%s", s); 
//	for (int i = 0; i < 9 - strlen(s); i++) {
//		printf('.');
//	}
//	printf("\n", price);
//	for (int i = 0; i < 13 - dlina(price); i++) {
//		printf("."); 
//	}
//	printf("%lf", g);
//	
//}
//
//
//void gets(char s[]) {
//	char ads[100]; // tekushaya stroka 
//	int k = 0; //iterator dlya ads 
//	char endS[100]; // naimenovanie producta 
//	int g; // kol-vo nashego producta
//	int a, b; 
//	char itog_product[100];
//	double itog_chislo;
//	double itog_price;
//	int f_i = 0, f_s = 0; // flag chisla, flag stroki
//	for (int i = 0; i < sizeof(s) and f_s + f_s != 2; i++) {
//		if (s[i] == ' ') {
//
//			// proverka na product 
//			for (int j = 0; j < sizeof(products); j++) {
//				if (ads == products[j]) {
//					strcpy(itog_product, ads);
//					f_s = 1;
//					a = j;
//
//				}
//			}
//			// proverka na chislo
//			if (f_s != 1) {
//				for (int j = 0; j < sizeof(primes); j++) {
//					if (ads == primes[j]) {
//						f_i = 1;
//						itog_chislo = def(ads);
//						if (itog_chislo - sklad[a].n > 0) {
//							itog_chislo = sklad[a].n;
//						}
//						itog_price = g * sklad[a].price; 
//					}
//				}
//			}
//			//~~~~~~~~~~~~~~~~~~~~~
//		ads[0] = '\0';
//		k = 0; 
//		}
//		else if (s[i] != ' ' and i == sizeof(s) - 1){
//			ads[k] = s[i];
//			k++;
//		}
//	}
//
//	if (f_i + f_s == 2) {
//			cout_checka(itog_product, itog_chislo, itog_price); 
//}
//}
//
//
//int main() {
//	int n; 
//	printf("Zadaite chislo productov na sclade: ");
//	scanf_s("%d", &n);
//	printf("\n"); 
//	int end[100]; 
//	int ends[100];
//	char now_str[100];
//	int k = 0; 
//	for (int p = 0; p < n; p++) {
//		scanf_s("%s", &now_str);
//		gets(now_str);
//	}
//	return 0; 
//}
//
