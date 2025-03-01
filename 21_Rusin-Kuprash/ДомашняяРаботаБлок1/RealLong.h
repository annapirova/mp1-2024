#pragma once

#include <iostream>
using namespace std;


class LongestInt {
private:
	unsigned int pos;
	bool isneg;
public:
	LongestInt(unsigned int a = 0, bool neg = false) {
		pos = a;
		isneg = neg;
	}
	LongestInt operator +(LongestInt other) {
		LongestInt v;
		if (isneg == other.isneg) {
			v.pos = pos + other.pos;
		}
		else {
			if (other.pos > pos) {
				v.pos = other.pos - pos;
				v.isneg = other.isneg;
			}
			else {
				v.pos = pos - other.pos;
				v.isneg = isneg;
			}
		}
		return v;
	}
};