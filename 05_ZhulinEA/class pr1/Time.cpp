#include "Time.h" 
#include "iostream"
using namespace std; 




void Time::coutTime() {
	cout << h << " hours " << m << " minutes " << s << " seconds "; 
}

void Time::deltaTime(Time t2) {
	cout << "Delta 2 times:" << '\n'; 
	cout << h - t2.h << " hours " << m - t2.m << " minutes " << s - t2.s << " seconds ";
}
void Time::sdvigTime(int h1, int m1, int s1) {
	int res_h, res_m, res_s; 
	cout << "Sdvig v min:" << '\n'; 
	if (h - h1 < 0) {
		res_h = 24 - (h - h1);
	} 
	else {
		res_h = h - h1; 
	}
	if (m - m1 < 0) {
		res_m = 60 - (m - m1); 
	}
	else{ 
		res_m = m - m1; 
	}
	if (s - s1 < 0) {
		res_s = 60 - (s - s1);
	}
	else {
		res_s = s - s1;
	}
	cout << res_h << " hours " << res_m << " miniutes " << res_s << " seconds " << '\n';
	int endh, endm, ends; 
	cout << "Sdviig v max:" << '\n';
	if (h + h1 > 24) {
		endh = h1 - (24 - h);
	}
	else {
		endh = h + h1;
	}
	if (m + m1 > 60) {
		endm = m1 - (60 - m);
	}
	else {
		endm = m + m1;
	}
	if (s - s1 > 60) {
		ends = s1 - (60 - s);
	}
	else {
		ends = s + s1;
	}
	cout << ends << " hours " << endm << " miniutes " << ends << " seconds " << '\n';
}