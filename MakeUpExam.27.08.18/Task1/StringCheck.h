#pragma once
#include <iostream>
#include <string>

using namespace std;

class StringCheck
{
public:
	static bool isNumber(string &input);
	static bool isNotTooBig(const string & strNumber);
	static bool isFound(int a);
	static void removeIntervalsInBeginning(string & input);
	static bool isThereMoreInfo(const string & input);
	static void findRemainingContent(string & content, int position);

	static const string getFirstWord(string & input);
	static const int findNumber(string & input);
};
