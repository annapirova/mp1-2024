#include<cstdlib>
#include<iostream>
#include "compl.h"
using namespace std;
void Menu(Chislo drob1, Chislo drob2)
{
	int ans = 5;
	while (ans < 1 || ans>4)
	{
		cout << "Chto hotite sdelat\n";
		cout << "1.SUM\n";
		cout << "2.RAZ\n";
		cout << "3.UMNO\n";
		cout << "4.DEL\n";
		cin >> ans;
	}
	switch (ans)
	{
		case 1:
		{
			drob1.SUM(drob2);
			break;
		}
		case 2:
		{
			drob1.RAZ(drob2);
			break;
		}
		case 3:
		{
			drob1.UMNO(drob2);
			break;
		}
		case 4:
		{
			drob1.DEL(drob2);
			break;
		}
	};
	drob1.print();

}
	int main()
	{
		int chis, znam, ans;
		cout << "Vvedite chislitel 1\n";
		cin >> chis;
		cout << "Vvedite znamenatel 1\n";
		cin >> znam;
		while (znam == 0)
		{
			cout << "Vvedite znamenatel\n";
			cin >> znam;
		}
		Chislo drob1(chis, znam);
		cout << "Vvedite chislitel 2\n";
		cin >> chis;
		cout << "Vvedite znamenatel 2\n";
		cin >> znam;
		while (znam == 0)
		{
			cout << "Vvedite znamenatel\n";
			cin >> znam;
		}
		Chislo drob2(chis, znam);
		Menu(drob1, drob2);
	}