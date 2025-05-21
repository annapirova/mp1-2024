#include <iostream> 
#include "Game.h"
#include <vector> 
#include <algorithm>
#include <string>
#include <sstream>

using namespace std; 
Player::Player() {
	
	my = {};  
	n = 0;    
}
void User::GetCards() {
	for (int i = 0; i < my.size(); i++) {
		cout << i << ')' << my[i].rank << my[i].mast << " ";
	}
	cout << '\n';
}
vector <card> User::Answer(vector <card> onTable, char kozyr) {
	vector <card> end;
	vector <int> cards;

	int f = 0; 
	cout << '\n'; 
	cout << "Сейчас на столе: " << '\n';
	for (int i = 0; i < onTable.size(); i++) {
	cout <<i << ')' << onTable[i].rank << onTable[i].mast << ' ';
	}
	cout << '\n'; 
	// проверка!!!
	while (f != 1) {
		
		f = 1;
		cout << "Ваши карты: ";
		GetCards();
		cout << "Выберите карты которыми хотите отбиться(если у вас нехватает карт чтобы отбиться то ничего не вводите!!): ";
		string ans;
		getline(cin, ans);
		if (ans.empty()) {
			return end; 
		}
		cards.clear();
		string bufer;
		for (int i = 0; i < ans.size(); i++) {
			if (ans[i] == ' ') {
				cards.push_back(stoi(bufer)); 
				bufer = "";
			}
			else {
				bufer += ans[i]; 
			}
		}
		if (!bufer.empty()) {
			cards.push_back(stoi(bufer));
		}
		if (cards.size() > onTable.size()) {
			cout << "Выбранно слишком много карт"; 
			continue; 
		}

		for (int i = 0; i < onTable.size(); i++) {
			for (int j = 0; j < cards.size(); j++) {
				card card_t = onTable[i];
				card card_u = my[cards[j]];  
				if ((card_t.mast == card_u.mast || card_u.mast == kozyr)) {
					if ((card_t.mast == kozyr && card_u.rank >= card_t.rank) || (card_t.rank <= card_u.rank)) {
						continue;
					}
					else {
						f = 0;
					}
				}
				else {
					f = 0;
				}
			}
		}
	}
	int k = 0; 
	// !	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	// 	// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

		// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	// после проверки добавляем в end
	sort(cards.begin(), cards.end(), greater<int>());

	for (int i = 0; i < cards.size(); i++) {
		end.push_back(my[cards[i]]);
		my.erase(my.begin() + cards[i]);
	}
	return end; 
}


vector<card> User::GiveCards(vector<card> onTable, char kozyr) {
	cout << "Ваши карты: ";
	GetCards();
	cout << "Козырь: " << kozyr << '\n';
	cout << "Выберите карты которыми хотите сыграть (они должны быть одного ранга): ";

	string ans;
	getline(cin, ans);

	vector<int> cards;
	istringstream iss(ans);
	int num;

	// Парсинг ввода
	while (iss >> num) {
		if (num >= 0 && num < my.size()) {
			cards.push_back(num);
		}
		else {
			cout << "Неверный индекс карты: " << num << endl;
		}
	}

	// Проверка что выбраны карты
	if (cards.empty()) {
		return {};
	}

	// Проверка одного ранга
	char first_rank = my[cards[0]].rank;
	for (int i = 1; i < cards.size(); i++) {
		if (my[cards[i]].rank != first_rank) {
			cout << "Все карты должны быть одного ранга!" << endl;
			return {};
		}
	}

	// Удаление карт с проверкой
	vector<card> end;
	sort(cards.begin(), cards.end(), greater<int>());

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i] < my.size()) {
			end.push_back(my[cards[i]]);
			my.erase(my.begin() + cards[i]);
		}
	}

	return end;
}



vector<card> Comp::Answer(vector<card> onTable, char kozyr) {
	vector<card> cardsToBeat;
	vector<card> remainingCards = my; 

	for (const auto& tableCard : onTable) {
		bool found = false;
		card bestCard{ '9', 'z' }; 
		int bestIndex = -1;

		for (int i = 0; i < remainingCards.size(); i++) {
			const auto& myCard = remainingCards[i];

			if ((myCard.mast == tableCard.mast and myCard.rank > tableCard.rank) or
				(myCard.mast == kozyr and tableCard.mast != kozyr) or
				(myCard.mast == kozyr and tableCard.mast == kozyr and myCard.rank > tableCard.rank)) {

				if (myCard.rank < bestCard.rank ||
					(myCard.rank == bestCard.rank && myCard.mast != kozyr)) {
					bestCard = myCard;
					bestIndex = i;
					found = true;
				}
			}
		}

		if (found) {
			cardsToBeat.push_back(bestCard);
			remainingCards.erase(remainingCards.begin() + bestIndex);
		}
		else {
			return {};
		}
	}

	my = remainingCards;
	return cardsToBeat;
}

vector<card> Comp::GiveCards(vector<card> onTable, char kozyr) {
	vector<card> cardsToPlay;

	//  сначала ищем минимальные не козырные карты
	char min_rank = '9'; 
	vector<int> min_indices;

	for (int i = 0; i < my.size(); i++) {
		if (my[i].mast != kozyr) {
			if (my[i].rank < min_rank) {
				min_rank = my[i].rank;
				min_indices.clear();
				min_indices.push_back(i);
			}
			else if (my[i].rank == min_rank) {
				min_indices.push_back(i);
			}
		}
	}

	// если не нашли не козырных ищем минимальные козыри
	if (min_indices.empty()) {
		min_rank = '9';
		for (int i = 0; i < my.size(); i++) {
			if (my[i].rank < min_rank) {
				min_rank = my[i].rank;
				min_indices.clear();
				min_indices.push_back(i);
			}
			else if (my[i].rank == min_rank) {
				min_indices.push_back(i);
			}
		}
	}

	sort(min_indices.begin(), min_indices.end(), greater<int>());

	for (int idx : min_indices) {
		cardsToPlay.push_back(my[idx]);
		my.erase(my.begin() + idx);
	}

	return cardsToPlay;
}




