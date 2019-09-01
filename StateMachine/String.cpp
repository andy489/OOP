#include "String.h"
#include <cstring>
#include <iostream>
#include <cassert>
String::String()
{
	this->content = nullptr;
	this->length = 0;
}
String::String(const String& str)
{
	this->length = str.Length();
	this->content = new char[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->content[i] = str[i];
	}
}
String::String(const char* str)
{
	this->length = strlen(str);
	this->content = new char[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->content[i] = str[i];
	}
}
String::String(char ch)
{
	this->length = 1;
	this->content = new char[1];
	this->content[0] = ch;
}
String::~String()
{
	delete[] this->content;
}
String String::operator+(const String& str) const
{
	return this->Concatenate(str);
}
String String::operator+(const char* str) const
{
	return *this + String(str);
}
String& String::operator=(const String& str)
{
	if (this == &str)
	{
		return *this;
	}
	delete[] this->content;
	this->length = str.Length();
	this->content = new char[this->length];
	for (int i = 0; i < this->length; i++)
	{
		this->content[i] = str[i];
	}
	return *this;
}
String& String::operator+=(const String& str)
{
	this->Append(str);
	return *this;
}
String& String::operator+=(const char* str)
{
	this->Append(String(str));
	return *this;
}
char String::operator[](int index)const
{
	if (index >= this->length || index < 0)
	{
		return '\0';
	}
	return this->content[index];
}
bool String::operator==(const String& other) const
{
	if (this->length != other.length)
	{
		return false;
	}
	for (int i = 0; i < this->length; i++)
	{
		if (this->content[i] != other.content[i])
		{
			return false;
		}
	}
	return true;
}
bool String::operator!=(const String& other) const
{
	return !((*this) == other);
}
std::istream& operator>>(std::istream& is, String& s)
{
	s = "";
	while (is.peek() > 0)
	{
		char input = is.get();
		if (input != '\n')
		{
			s.Append(input);
		}
		else
		{
			break;
		}
	}
	return is;
}
std::ostream& operator<<(std::ostream& os, String& s)
{
	for (int i = 0; i < s.length; i++)
	{
		os << s[i];
	}
	return os;
}
String::operator int() const
{
	return this->ToInt();
}
String::operator double() const
{
	return this->ToDouble();
}
int String::Length() const
{
	return this->length;
}
String String::Concatenate(const String& str) const
{
	String temp = *this;
	temp.Append(str);
	return temp;
}
void String::Append(const String& str)
{
	char* temp = this->content;
	this->length += str.Length();
	this->content = new char[this->length];
	for (int i = 0; i < this->length - str.Length(); i++)
	{
		this->content[i] = temp[i];
	}
	for (int i = this->length - str.Length(), j = 0; i < this->length; i++, j++)
	{
		this->content[i] = str[j];
	}
	delete temp;
}
void String::AppendLine(const String& str)
{
	this->Append(str + "\n");
}
void String::Print() const
{
	for (int i = 0; i < this->length; i++)
	{
		std::cout << (*this)[i];
	}
}
int String::IndexOf(char ch) const
{
	return this->IndexOf(ch, 0);
}
int String::IndexOf(char ch, int startIndex) const
{
	for (int i = startIndex; i < this->length; i++)
	{
		if (this->content[i] == ch)
		{
			return i;
		}
	}
	return -1;
}
int String::IndexOf(const String& str)const
{
	return this->IndexOf(str, 0);
}
int String::IndexOf(const String& str, int startIndex) const
{
	String substr;
	int currIndex = this->IndexOf(str[0], startIndex);
	while (currIndex != -1)
	{
		if (this->Substring(currIndex, str.Length()) == str)
		{
			break;
		}
		currIndex = this->IndexOf(str[0], currIndex + 1);
	}
	return currIndex;
}
int String::LastIndexOf(char ch) const
{
	for (int i = this->length - 1; i >= 0; i--)
	{
		if (this->content[i] == ch)
		{
			return i;
		}
	}
	return -1;
}
int String::FirstIndexOfAny(char* chars, int count) const
{
	int minIndex = this->length;
	int charIndex = -1;
	for (int i = 0; i < count; i++)
	{
		charIndex = this->IndexOf(chars[i]);
		if (charIndex > -1 && minIndex > charIndex)
		{
			minIndex = charIndex;
		}
	}
	if (minIndex == this->length)
	{
		return -1;
	}
	return minIndex;
}
int String::Count(const String& str) const
{
	int counter = 0;
	int index = this->IndexOf(str);
	while (index != -1)
	{
		counter++;
		index = this->IndexOf(str, index + 1);
	}
	return counter;
}
bool String::ContainsAny(const char* chars, int count)const
{
	for (int i = 0; i < count; i++)
	{
		if (this->Count(chars[i]) != 0)
		{
			return true;
		}
	}
	return false;
}
bool String::Contains(const String& str) const
{
	if (this->IndexOf(str) != -1)
	{
		return true;
	}
	return false;
}
String String::Substring(int start, int len) const
{
	if (start < 0)
	{
		return String();
	}
	String t;
	if (start + len > this->length)
	{
		len = this->length - start;
	}
	for (int i = 0; i < len; i++)
	{
		if (i >= this->length)
		{
			return t;
		}
		t += this->content[i + start];
	}
	return t;
}
String String::Substring(int start) const
{
	return this->Substring(start, this->length);
}
std::vector<String> String::Split(char delimiter) const
{
	std::vector<String> result;
	int count = this->Count(delimiter);
	int currIndex = 0;
	int indexOfDelimiter = this->IndexOf(delimiter);
	for (int i = 0; i < count; i++)
	{
		result.push_back(String(this->Substring(currIndex, indexOfDelimiter - currIndex)));
		currIndex = indexOfDelimiter + 1;
		indexOfDelimiter = this->IndexOf(delimiter, currIndex);
	}
	result.push_back(String(this->Substring(currIndex)));

	//Remove empty entries
	for (int i = result.size() - 1; i >= 0; i--)
	{
		if (result[i] == String())
		{
			result.erase(result.begin() + i);
		}
	}

	return result;
}
void String::InsertAt(int index, const String& str)
{
	String tmp = this->Substring(0, index);
	tmp.Append(str);
	tmp.Append(this->Substring(index));
	*this = tmp;
}
void String::Remove(const String& other)
{
	this->Replace(other, "");
}
void String::Replace(const String& oldStr, const String& newStr)
{
	if (oldStr == newStr)
	{
		return;
	}
	String result;
	int startIndex = 0;
	int index = this->IndexOf(oldStr);
	if (index == -1)
	{
		return;
	}
	while (index != -1)
	{
		if (index != startIndex)
		{
			result.Append(this->Substring(startIndex, index - startIndex));
		}
		result.Append(newStr);
		startIndex = index + oldStr.length;
		index = this->IndexOf(oldStr, startIndex);
	}

	if (startIndex < this->length)
	{
		result.Append(this->Substring(startIndex));
	}

	*this = result;
}
int String::ToInt() const
{
	assert(TryParseToInt() && "Invalid input to parse!");
	char* t = this->ToCharArray();
	int result = atoi(t);
	delete[] t;
	return result;
}
double String::ToDouble() const
{
	bool isFloating = false;
	double result = 0;
	char temp = ' ';
	assert(TryParseToDouble() && "Invalid input to parse!");
	char* a = this->ToCharArray();
	result = atof(a);
	delete[] a;
	return result;
}
bool String::TryParseToDouble() const
{
	bool isFloating = false;
	double result = 0;
	char temp;
	for (int i = 0; i < this->length; i++)
	{
		if (i == 0 && this->content[i] == '-')
		{
			continue;
		}

		if (this->content[i] == '.')
		{
			if (isFloating)
			{
				return false;
			}
			isFloating = true;
			continue;
		}
		temp = this->content[i] - '0';
		if (temp < 0 || temp>9)
		{
			return false;
		}
	}
	return true;
}
bool String::TryParseToInt() const
{
	char temp;
	for (int i = 0; i < this->length; i++)
	{
		if (i == 0 && this->content[i] == '-')
		{
			continue;
		}
		temp = this->content[i] - '0';
		if (temp < 0 || temp>9)
		{
			return false;
		}
	}
	return true;
}
char* String::ToCharArray() const
{
	char* res = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		res[i] = this->content[i];
	}
	res[this->length] = 0;
	return res;
}
String operator+(const char* ch, const String& str)
{
	String result(ch);
	result.Append(str);
	return result;
}
