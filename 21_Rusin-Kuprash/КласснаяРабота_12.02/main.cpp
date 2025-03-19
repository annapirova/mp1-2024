#include <iostream>
#include <stdlib.h>

using namespace std;


void genMap(int* mapOrig, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == 0 && i == size && j == 0 && j == size) {
				mapOrig[i * size + j] = 1;
			}
			else {
				mapOrig[i * size + j] = 0;
			}
			
		}
	}
}


void outMap(int* mapOrig, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			switch (mapOrig[i * size + j]) {
			case (0): cout << "*"; break;
			case (1): cout << "#"; break;
			}
		}
		cout << "\n";
	}
	fflush(stdout);
}


int main() {
	const int size = 32;
	int i;
	int** map;
	int* mapOrig;
	char a;

	mapOrig = new int[size * size];
	map = new int* [size];
	for (i = 0; i < size; i++) {
		map[i] = &mapOrig[size * i];
	}
	for (i = 0; i < size * size; i++) {
		mapOrig[i] = 0;
	}
	cout << "Hello world!!";
	cin >> a;
	genMap(mapOrig, size);
	system("cls");
	while (a != char("0")) {
		outMap(mapOrig, size);
		cin >> a;
		system("cls");
	}
	return 1;
}