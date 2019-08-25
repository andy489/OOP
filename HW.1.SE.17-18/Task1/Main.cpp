#include <iostream>
#include <cmath>
#include "String.h"
#include "IntStack.h"

String readNextUntilWhiteSpace(String& str)
{   /* Works like split but on demand, returning one item at a time */
	String newString;
	while (str.len() != 0 && str[0] != ' ')
	{   /* Get all the characters before a white space is encountered */
		newString += str[0];
		str = str.subStr(1, str.len() - 1);
	}
	while (str.len() != 0 && str[0] == ' ')
	{   /* Clear the white spaces at the start */
		str = str.subStr(1, str.len() - 1);
	}
	return newString;
}

int pow(int base, size_t exp)
{
	if (exp == 0)
	{
		return 1;
	}
	return base * pow(base, exp - 1);
}

bool isStringANumber(String str)
{
	if (str.len() == 0)
	{
		return false;
	}
	if (str.len() == 1)
	{
		return str[0] >= '0' && str[0] <= '9';
	}
	else {
		if (str[0] == '-' || (str[0] >= '0' && str[0] <= '9'))
		{
			for (size_t i = 1; i < str.len(); i++)
			{
				if (str[i] < '0' || str[i] > '9')
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
}

int convertToInt(String str)
{   /* Converts a string of numbers into a number, returns -1 on fail */
	if (!isStringANumber(str))
	{
		return 0;
	}

	int result = 0;

	for (size_t i = 1; i <= str.len(); i++)
	{
		if (i == str.len() && str[str.len() - i] == '-')
		{
			result *= -1;
		}
		else
		{
			result += (str[str.len() - i] - '0')*pow(10, i - 1);
		}
	}
	return result;
}

int calculate(char * str)
{
	String workStr = str;
	IntStack stack;
	String nextItem = readNextUntilWhiteSpace(workStr);
	while (nextItem.len() != 0)
	{
		if (isStringANumber(nextItem))
		{   /* If it's a number */
			stack.push(convertToInt(nextItem));
		}
		else if (nextItem.len() == 1)
		{   /* If it's not a number check if it's +, -, *, /, % and perform the calc, else return result = 0 and cout<<ERROR */
			if (nextItem[0] != '+' && nextItem[0] != '-' && nextItem[0] != '/' && nextItem[0] != '*' && nextItem[0] != '%') 
			{
				std::cout << "Error in the input\n";
				return 0;
			}
			/* Get 2 numbers or return error if you can't */
			int num1, num2;
			if (!stack.isEmpty()) 
			{
				num2 = stack.pop();
				if (!stack.isEmpty()) 
				{
					num1 = stack.pop();
				}
				else 
				{
					std::cout << "Error in the input\n";
					return 0;
				}
			}
			else 
			{
				std::cout << "Error in the input\n";
				return 0;
			}
			/* Check if the char is +, -, *, /, % and perform the calculation */
			if (nextItem[0] == '+') stack.push(num1 + num2);			
			else if (nextItem[0] == '-') stack.push(num1 - num2);			
			else if (nextItem[0] == '*') stack.push(num1 * num2);			
			else if (nextItem[0] == '/') stack.push(num1 / num2);			
			else if (nextItem[0] == '%') stack.push(num1 % num2);			
			else 
			{
				std::cout << "Error in the input\n";
				return 0;
			}
		}
		else 
		{   /* if it's not a number and it's not 1 char long - ERROR */
			std::cout << "Error in the input\n";
			return 0;
		}
		nextItem = readNextUntilWhiteSpace(workStr);
	}

	/* If there's only one item in the stack return it as the result */
	if (!stack.isEmpty()) 
	{
		int result = stack.pop();
		if (stack.isEmpty()) 
		{
			return result;
		}
		else 
		{   /* If there's more than 1 item in the stack - ERROR */
			std::cout << "Error in the input\n";
			return 0;
		}
	}
	/* If there's no items in the stack - ERROR */
	std::cout << "Error in the input\n";
	return 0;
}

int main() 
{
	/* If you want the number to be negative you need to have no space separation 
	between the '-' and the number in the reverse polish notation */
	/* Tests */
	char toCalculate1[] = "5 1 2 + 4 * + 3 -";
	int calculated1 = calculate(toCalculate1);
	int actualResult1 = 5 + ((1 + 2) * 4) - 3;
	std::cout << calculated1 << " = " << actualResult1 << " => " << (calculated1 == actualResult1 ? "True" : "False") << "\n";

	char toCalculate2[] = "2 5 + 25 5 / 3 % - -8 *";
	int calculated2 = calculate(toCalculate2);
	int actualResult2 = (2 + 5 - (25 / 5 % 3)) * -8;
	std::cout << calculated2 << " = " << actualResult2 << " => " << (calculated2 == actualResult2 ? "True" : "False") << "\n";

	char toCalculate3[] = "5 2 - 3 / 18 2 * + 36 /";
	int calculated3 = calculate(toCalculate3);
	int actualResult3 = (((5 - 2) / 3) + (18 * 2)) / 36;
	std::cout << calculated3 << " = " << actualResult3 << " => " << (calculated3 == actualResult3 ? "True" : "False") << "\n";

	char toCalculate4[] = "5 2 - 3 / 18 2 * + 36 / -"; /* Wrongly converted, it has one additional '-' at the end */
	int calculated4 = calculate(toCalculate4);
	int actualResult4 = (((5 - 2) / 3) + (18 * 2)) / 36;
	std::cout << calculated4 << " != " << actualResult4 << " => " << (calculated4 != actualResult4 ? "True" : "False") << "\n";

	char toCalculate5[] = "5 2 - 3 / 18 2 * + 36 / 12"; /* Wrongly converted, it has one additional number at the end */
	int calculated5 = calculate(toCalculate5);
	int actualResult5 = (((5 - 2) / 3) + (18 * 2)) / 36;
	std::cout << calculated5 << " != " << actualResult5 << " => " << (calculated5 != actualResult5 ? "True" : "False") << "\n";

	return 0;
}
