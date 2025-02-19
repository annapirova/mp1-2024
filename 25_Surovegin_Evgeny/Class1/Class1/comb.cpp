#include "compl.h"
#include<cstdlib>
#include<iostream>
using namespace std;
Chislo::Chislo(int chis, int znam)
{
	chislitel = chis;
	znamenatel = znam;
	sokrashenie();
}
Chislo::~Chislo()
{

}
void Chislo::SUM(Chislo drob)
{
	chislitel = chislitel * drob.znamenatel + znamenatel * drob.chislitel;
	znamenatel = drob.znamenatel * znamenatel;
	sokrashenie();
}
void Chislo::RAZ(Chislo drob)
{
	chislitel = chislitel * drob.znamenatel - znamenatel * drob.chislitel;
	znamenatel = drob.znamenatel * znamenatel;
	sokrashenie();
}
void Chislo::UMNO(Chislo drob)
{
	chislitel = chislitel * drob.chislitel;
	znamenatel = drob.znamenatel * znamenatel;
	sokrashenie();
}
void Chislo::DEL(Chislo drob)
{
	znamenatel = znamenatel * drob.chislitel;
	chislitel = drob.znamenatel * chislitel;
	sokrashenie();
}
void Chislo::print()
{
	cout << chislitel << " / " << znamenatel << endl;
}
void Chislo::sokrashenie()
{
	int ost = 1;
	int NOD = 0, del = znamenatel, max = chislitel;
	while (ost != 0)
	{
		ost = max % del;
		if (ost != 0)
		{
			max = del;
			del = ost;
		}
		else
		{
			NOD = del;
		}
	}
	chislitel /= NOD;
	znamenatel /= NOD;
}