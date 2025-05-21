#pragma once
#include <iostream> 
#include <vector>
#include <utility>
#include <algorithm>
#include <random>

//трайну дурака

using namespace std; 

struct card {
	char rank; // {6,7,8,9,10,v,d,k,t} 
	char mast; // {a, b, c, d} 

	bool operator==(card c2) { return (rank == c2.rank) && (mast == c2.mast); }
};

class Player {
protected: 
	vector <card> my;
	size_t n; //kol-vo kart 
public: 
	virtual vector <card> Answer(vector <card> OnTable, char kozyr) = 0;
	virtual vector <card> GiveCards(vector <card> onTable, char kozyr) = 0;
	



	Player(); 

	friend class Game;
};

class Comp : public Player {
public:
	vector <card>  Answer(vector <card> OnTable, char kozyr); // логику компьютер
	vector <card> GiveCards(vector <card> onTable, char kozyr);// логику компьютер
	
}; 

class User : public Player {
public:
 	vector <card> Answer(vector <card> OnTable, char kozyr);
	vector <card> GiveCards(vector <card> onTable, char kozyr); //запрос через консоль 
	
	void GetCards(); // показать текущие карты 
	
};


class Game {
	vector <card> allCards;
	vector <card> onTable;
	char kozyr;

	Player* p[2];


public: 
	int n = 0; // номер хода
	Game() {
		p[0] = new User;
		p[1] = new Comp;
	}
	void SetOnTable(vector<card> a) {
		if (a.empty()) return;  // защита от пустого вектора

		for (int c = 0; c < a.size(); c++) {
			this->onTable.push_back(a[c]);
		}
	}
	void SetallCards() {
		const char ranks[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };// 10 заменил на 5
		const char suits[] = { 'a', 'b', 'c', 'd' };
		for (char suit : suits) {
			for (char rank : ranks) {
				allCards.push_back({ rank, suit });
			}
		}
	}
	void start() {

		SetallCards(); 
		shuffle(allCards.begin(), allCards.end(), mt19937(random_device{}())); // карты Общей колоды берём из конца массива, а не из начала, в начале козырь будет 
		// Раздаём карты 
		size_t das = allCards.size(); 
		if (das >= 6) {
			for (int j = das - 1; j > das - 6 - 1; j--) {
				p[0]->my.push_back(allCards[j]);
				allCards.pop_back();
			}
		}
		else {
			cout << "oshibka v starte"; 
		}
		das = allCards.size();
		if (das >= 6){
			for (int j = das - 1; j > das - 6 - 1; j--) {
				p[1]->my.push_back(allCards[j]);
				allCards.pop_back();
			}
		}
		else {
			cout << "oshibka v starte";
		}
		// Закончили раздачу

		kozyr = allCards[0].mast; //козырь 

		while (allCards.size() != 0 and p[0]->my.size() != 0 and p[1]->my.size() != 0) {
			int l = n % 2;
			cout << '\n';
			vector <card> a1 = p[l]->GiveCards(onTable, kozyr);
			SetOnTable(a1);
			cout << '\n';

			vector <card> a2 = p[1 - l]->Answer(onTable, kozyr);
			cout << "Скинутые карты:" << '\n'; 
			if (a2.size() < a1.size()) {
				for (int i = 0; i < onTable.size(); i++) {
					p[1 - l]->my.push_back(onTable[i]);
				}
			}
			if (a2.size() > 0) {
				for (int he = 0; he < a2.size(); he++) {
					cout << he << ')' << a2[he].rank << a2[he].mast << ' ';
				}
			}
			else {
				cout << "Ничего!" << '\n';
			}
			onTable.clear();
			// берём карты из allCards 

			while (p[l]->my.size() < 6 && !allCards.empty()) {
				p[l]->my.push_back(allCards.back());
				allCards.pop_back();
			}
			while (p[1 - l]->my.size() < 6 && !allCards.empty()) {
				p[1 - l]->my.push_back(allCards.back());
				allCards.pop_back();
			}
			n++;





		}

			if (p[0]->n == 0) {
				cout << "Computer win. Nice try";

			}
			else {
				cout << "Good job. You win";
			}
		}
	

};


 