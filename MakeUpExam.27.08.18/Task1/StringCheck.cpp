#include "StringCheck.h"

const int NOT_FOUND = -1;

bool StringCheck::isNumber(string& input)
{
	return (NOT_FOUND == input.find_first_not_of("0123456789"));
}

bool StringCheck::isNotTooBig(const string & strNumber)
{
	// we should not accept numbers with more than 9 digits
	if ("" == strNumber)
	{
		return false;
	}
	return (strNumber.size() <= 9);
}

bool StringCheck::isFound(int a)
{
	return (NOT_FOUND != a);
}

void StringCheck::removeIntervalsInBeginning(string & input)
{
	while ("" != input && ' ' == input[0])
	{
		input.erase(input.begin());
	}
}

bool StringCheck::isThereMoreInfo(const string & input)
{
	return (NOT_FOUND != input.find_first_not_of(" "));
}

void StringCheck::findRemainingContent(string & content, int position)
{
	string newContent(content, position);
	content = newContent;
}

// returns the first word from input and removes it from input;
const string StringCheck::getFirstWord(string & input)
{
	removeIntervalsInBeginning(input);
	// now we are sure that our string does not start with intervals	
	int position = input.find(" ");
	string foundWord(input, 0, position); // copies the characters before the first ' ';	
	if (isFound(position))
	{
		findRemainingContent(input, position);
	}
	else
	{
		input = "";
	}
	return foundWord;
}

// if possible returns the number from the string returned by findText;
const int StringCheck::findNumber(string & input)
{
	string strNumber = getFirstWord(input);
	int result = NOT_FOUND;
	bool isNEgative = false;
	if (isNumber(strNumber) && isNotTooBig(strNumber))
	{
		result = stoi(strNumber);
		// always return positive number because we have removed the sign;		
	}
	return result;
}
