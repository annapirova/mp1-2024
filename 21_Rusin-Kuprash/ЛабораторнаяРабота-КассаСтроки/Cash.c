#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>



typedef struct Tovar Tovar;


struct Tovar {
	int id;
	char name[100];
	double price;
	double count;
};


void fileOpen(FILE** cashF, char obj[100], char dest[100]) {
	char d[200];
	char ansS[100] = "\0";

	printf("Выберите %s: \n", obj);
	scanf_s("%s", ansS, (unsigned)_countof(ansS));
	memcpy(d, dest, sizeof(char) * 100);
	strcat(d, ansS);
	strcat(d, ".txt");
	*cashF = fopen(d, "r");
	while (*cashF == NULL) {
		printf(d);
		printf("\n");
		printf("Такой %s не существует.\n", obj);
		scanf_s("%s", ansS, (unsigned)_countof(ansS));
		memcpy(d, dest, sizeof(char) * 100);
		strcat(d, ansS);
		strcat(d, ".txt");
		*cashF = fopen(d, "r");
	}
}


void SaveCheck(Tovar** skl, int* sklN, Tovar* receipt, int n) {
	FILE* file;
	char dir[200] = "data/Чеки/";
	char name[100];

	Tovar receiptT;
	Tovar* scladT;

	//char* foundR[2000] = "";
	char* ErrR[2000] = {"\0"};
	char* bufT[400] = {"\0"};

	double sm = 0;
	double tsm = 0;

	strcpy(ErrR, "");

	printf("Как назвать чек?\n");
	scanf_s("%s", &name, 100);
	strcat(dir, name);
	strcat(dir, ".txt");
	file = fopen(dir, "r");
	while (file != NULL) {
		fclose(file);
		strcpy(dir, "data/Чеки/");
		printf("Файл с таким именем уже существует, выберите другой.\n");
		scanf_s("%s", &name, 100);
		strcat(dir, name);
		strcat(dir, ".txt");
		file = fopen(dir, "r");
	}
	file = fopen(dir, "w");
	for (int i = 0; i < n; i++) {
		receiptT = receipt[i];
		if (receiptT.id == 0) {
			//strcpy(bufT, "Нет на складе - %s\n");
			sprintf(bufT, "Нет на складе - %s\n", receiptT.name);

			strcat(ErrR, bufT);
		}
		else {
			for (int j = 0; j < *sklN; j++) {
				if ((*skl)[j].id == receiptT.id) {
					scladT = &((*skl)[j]);
					break;
				}
			}
			if ((*scladT).count < receiptT.count) {
				receiptT.count = (*scladT).count;
				sprintf(bufT, "На складе закончился - %s\n", receiptT.name);
				
				//strcat(ErrR, "На складе закончился - ");
				strcat(ErrR, bufT);
			}
			if (receiptT.count != 0) {
				(*scladT).count -= receiptT.count;
				tsm = receiptT.price * receiptT.count;
				sm += tsm;
				sprintf(bufT, "%s -- кол-во: %lf -- цена за ед: %lf -- всего: %lf\n", receiptT.name, receiptT.count, receiptT.price, tsm);
				fwrite(bufT, 1, strlen(bufT), file);
			}
			
		
		}
	}

	fwrite("----------\n", 1, 11, file);
	sprintf(bufT, "Итого -- %lf\n----------\nЗамечания к чеку:\n", sm);
	fwrite(bufT, 1, strlen(bufT), file);
	fwrite(ErrR, 1, strlen(ErrR), file);

	printf("Чек сохранён в %s\n", dir);
	fclose(file);
}


void ReadCheckList(Tovar** skl, int* sklN) {
	FILE* cashF;
	Tovar ch;
	char buf[100];
	char lowerName[100];

	Tovar* receipt = (Tovar*)malloc(sizeof(Tovar) * 20);
	int n = 0;
	int bl = 0;
	int in;

	fileOpen(&cashF, "список", "data/Заказы/");

	ch.id = 0;
	ch.price = 0;
	
	fgets(buf, 100, cashF);
	if (isdigit(buf[0])) {
		sscanf_s(buf, "%lf %s", &(ch.count), &(ch.name), (unsigned)_countof(ch.name));
	}
	else {
		sscanf_s(buf, "%s %lf", &(ch.name), (unsigned)_countof(ch.name), &(ch.count));
	}

	for (int i = 0; ch.name[i]; i++) ch.name[i] = tolower(ch.name[i]);

	receipt[n] = ch;
	n++;
	while (!feof(cashF)) {

		//fgets(buf, 256, f);

		/*
		ch.id = 9;
		strcpy_s(ch.name, 100 * sizeof(char), "data/Склад/");
		ch.price = 15.5;
		ch.count = 5.6;
		*/

		// Чтение строки
		fgets(buf, 100, cashF);
		if (isdigit(buf[0])) {
			sscanf_s(buf, "%lf %s", &(ch.count), &(ch.name), (unsigned)_countof(ch.name));
		}
		else {
			sscanf_s(buf, "%s %lf", &(ch.name), (unsigned)_countof(ch.name), &(ch.count));
		}
		
		// Приведение букв в строчные
		for (int i = 0; ch.name[i]; i++) ch.name[i] = tolower(ch.name[i]);

		// Запись в чек
		bl = 0;
		for (int j = 0; j < n; j++) {
			if (strcmp(ch.name, receipt[j].name) == 0) {
				receipt[j].count += ch.count;
				bl = 1;
				break;
			}
		}
		if (!bl) {
			n++;
			receipt[n - 1] = ch;
		}
		

		//printf(" % d % s % lf % lf\n", (ch.id), (ch.name), (ch.price), (ch.count));
		}


	// поиск id и цены по имени
	for (int j = 0; j < *sklN; j++){
		
		for (in = 0; (*skl)[j].name[in]; in++) lowerName[in] = tolower((*skl)[j].name[in]);
		lowerName[in] = tolower((*skl)[j].name[in]);
		for (int i = 0; i < n; i++) {
			if (strcmp(receipt[i].name, lowerName) == 0) {
				receipt[i].id = (*skl)[j].id;
				receipt[i].price = (*skl)[j].price;
				strcpy(receipt[i].name, (*skl)[j].name);
				break;
		}
		
		}
	}

	// Вывод
	for (int i = 0; i < n; i++) {
		printf(" %lf %s\n", (receipt[i].count), (receipt[i].name));
	}
	
	SaveCheck(skl, sklN, receipt, n);

	fclose(cashF);
}


void ReadSklad(Tovar** skl, int* sklN, FILE* f) {
	char* buf = (char*)malloc(256 * sizeof(char));
	char* p;
	int i = 0;
	Tovar ch;

	*sklN = 0;
	while (!feof(f)) {
		fgets(buf, 256, f);
		(*sklN)++;


		p = strtok(buf, " ");
	}
	rewind(f);

	*skl = (Tovar*)malloc(sizeof(Tovar) * (*sklN));
	while (!feof(f)) {
		//fgets(buf, 256, f);

		/*
		ch.id = 9;
		strcpy_s(ch.name, 100 * sizeof(char), "data/Склад/");
		ch.price = 15.5;
		ch.count = 5.6;
		*/
		
		fscanf_s(f, "%d %s %lf %lf", &(ch.id), &(ch.name), (unsigned)_countof(ch.name), &(ch.price), &(ch.count));
		(*skl)[i].id = ch.id;
		strcpy((*skl)[i].name, ch.name);
		(*skl)[i].price = ch.price;
		(*skl)[i].count = ch.count;
		//fgets(buf, 256, f);
		//printf(" % d % s % lf % lf\n", (ch.id), (ch.name), (ch.price), (ch.count));
		i++;
	}

	free(buf);
}


void CheckSklad(Tovar** skl, int* sklN) {
	FILE* cashF;

	fileOpen(&cashF, "склад", "data/Склад/");
	if (*skl != NULL) {
		free(*skl);
	}
	ReadSklad(skl, sklN, cashF);
	fclose(cashF);
}



int main() {
	
	//d[0] = "\n";


	Tovar* skl = NULL;
	int sklN;

	int ans = 0;

	setlocale(LC_ALL, "Russian");
	CheckSklad(&skl, &sklN);

	//ans = 0;
	while (ans != 4) {

		switch (ans) {
		case(1): CheckSklad(&skl, &sklN); break;
		case(2): ReadCheckList(&skl, &sklN); break;
		case(3): 
			for (int i = 0; i < sklN; i++)
				printf(" %d %s %.2lf %.2lf\n", (skl[i].id), (skl[i].name), (skl[i].price), (skl[i].count));
			break;
		}

		printf("1) Выбрать склад\n");
		printf("2) Выполнить заказ\n");
		printf("3) Проверить склад\n");
		printf("\n4) Выйти\n");

		scanf_s("%d", &ans);
	}
	


	//fclose(cashF);
	return 1;
}
