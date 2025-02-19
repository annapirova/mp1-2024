#pragma once

class Chislo
{
private:
	int chislitel;
	int znamenatel;
public:
	Chislo(int chis, int znam);
	~Chislo();
	void SUM(Chislo drob);
	void RAZ(Chislo drob);
	void UMNO(Chislo drob);
	void DEL(Chislo drob);
	void print();
private:
	void sokrashenie();


};