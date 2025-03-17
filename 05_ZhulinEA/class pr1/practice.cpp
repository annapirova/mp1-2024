#include <vector> 
#include <string>
#include <algorithm>
#include <cmath> 
#include <iostream>
#include <set> 
#include <map> 
#include <queue>
#include "Time.h"

using namespace std;
using ll = long long;

/*
cout.precision(4);
double x = 1.3784384;
cout << fixed << x;
*/

int main() {
	int h, m, s; 
	cout << "Cout your time:"; 
	cin >> h >> m >> s; 
	Time a1(h, m ,s);
	int h1, m1, s1; 
	cout << "Cout sdvig"; 
	cin >> h1 >> m1 >> s1; 
	Time a2(h1, m1, s1); 
	a1.coutTime(); 
	a1.deltaTime(a2);
	a1.sdvigTime
	return 0; 
}