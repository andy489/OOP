#include "String.h"

const size_t String::strLen(const char* str) const
{
	if (str != nullptr)
	{
		size_t i = 0;
		while (str[i]) i++;
		return i;
	}
	return 0;
}

void String::strCpy(const char* src, char* dest)
{
	if (src == nullptr || dest == nullptr) return;
	size_t i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void String::setWithoutDelete(const char* str)
{
	size = strLen(str);
	arr = new char[size + 1];
	strCpy(str, arr);
}

void String::setWithoutDelete(const String& str)
{
	size = str.size;
	arr = new char[size + 1];
	strCpy(str.arr, arr);
}

String::String()
{
	setWithoutDelete("");
}

String::String(const char* str)
{
	if (str == nullptr) setWithoutDelete("");
	else setWithoutDelete(str);
}

String::~String()
{
	delete[] arr;
}

String::String(const String& str)
{
	setWithoutDelete(str);
}

String &String::operator=(const String& str)
{
	if (this != &str) set(str);
	return *this;
}

String &String::operator=(const char* str)
{
	if (str != nullptr) set(str);
	return *this;
}

void String::set(const char* str)
{
	if (str != nullptr)
	{
		delete[] arr;
		setWithoutDelete(str);
	}
}

void String::set(const String& str)
{
	delete[] arr;
	setWithoutDelete(str);
}

String &String::operator+=(const char ch)
{
	append(ch);
	return *this;
}

String &String::operator+=(const char* str)
{
	append(str);
	return *this;
}

String &String::operator+=(const String& str)
{
	append(str);
	return *this;
}

const char* String::get() const
{
	return arr;
}

size_t String::length() const 
{
	return size;
}

std::ostream& operator<<(std::ostream &stream, const String& str) 
{
	stream << str.arr;
	return stream;
}
const char String::operator[](const size_t pos) const 
{
	if (pos >= size) return 0;
	return arr[pos];
}

String String::subStr(size_t from, size_t to) const 
{
	if (from < 0 || to >= size || from > to) return String();	
	char* newStr = new char[to - from + 2];
	for (size_t i = 0; i < to - from + 1; i++) newStr[i] = arr[i + from];
	newStr[to - from + 1] = '\0';
	String newString = newStr;
	return newString;
}

void String::append(const String& str) 
{
	*this += str.get();
}

void String::append(const char* str) 
{
	if (str != nullptr) 
	{
		size_t len = strLen(str);
		char *newStr = new char[size + len + 1];
		strCpy(arr, newStr);
		strCpy(str, newStr + size);
		newStr[size + len] = '\0';
		set(newStr);
	}
}

void String::append(const char ch) 
{
	char *newStr = new char[size + 2];
	size_t i = 0;
	while (arr[i] != '\0') 
	{
		newStr[i] = arr[i];
		i++;
	}
	newStr[size] = ch;
	newStr[size + 1] = '\0';
	delete[] arr;
	arr = newStr;
	size++;
	return;
}

String String::concat(const String& str) const 
{
	String newStr = *this;
	newStr.append(str);
	return newStr;
}

std::istream &operator>>(std::istream &stream, String& str) 
{
	char c = '\0';
	str.clear();
	stream.get(c);
	while (c != '\n') 
	{
		str += c;
		stream.get(c);
	}
	return stream;
}

void String::clear()
{
	delete[] arr;
	setWithoutDelete("");
}

bool String::operator==(const String& str) const 
{
	size_t len = length();
	if (len != str.length()) return false;	
	for (size_t i = 0; i < len; i++) if (arr[i] != str[i]) return false;
	return true;
}

bool String::operator==(const char* str) const 
{
	String newStr = str;
	return *this == newStr;
}

bool String::operator!=(const String& str) const 
{
	size_t len = length();
	if (len != str.length()) return true;	
	for (size_t i = 0; i < len; i++) if (arr[i] != str[i]) return true;
	return false;
}

bool String::operator!=(const char* str) const 
{
	String newStr = str;
	return *this != newStr;
}

void String::toUpper() 
{
	for (size_t i = 0; i < size; ++i) if (arr[i] >= 'a' && arr[i] <= 'z') arr[i] = arr[i] & ~32;		
	
}

void String::toLower() 
{
	for (size_t i = 0; i < size; ++i) if (arr[i] >= 'A' && arr[i] <= 'Z') arr[i] = arr[i] | 32;
}
