#pragma once


class Time {
private:
	int h; 
	int m; 
	int s; 

public: 
	Time(int a = 0, int b = 0, int c = 0) {
		h = a;
		m = b;
		s = c;
	}
	void coutTime(); 
	void deltaTime(Time t2);
	void sdvigTime(int h1, int m1, int s1); 
}; 