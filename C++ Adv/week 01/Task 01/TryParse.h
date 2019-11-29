#pragma once

#include <string>
using namespace std;

bool tryParse(string& str, int& a)
{	
	int length = str.length();
	if (length == 0) {
		return false;
	}
	int i = 0;
	if (str[0] == '-') {
		if (length == 1) {
			return false;
		}
		i = 1;
	}
	for (; i < length; ++i) {
		char c = str[i];
		if (c < '0' || c > '9') {
			return false;
		}
	}
	a = stoi(str);
	return true;
}
