#include "String.h"

size_t String::strLen(const char* str) 
{
	if (str != nullptr) 
	{
		size_t i = 0;
		while (str[i]) 
		{
			i++;
		}
		return i;
	}
	return 0;
}

void String::strCopy(const char* src, char* dest) 
{
	if (src == nullptr || dest == nullptr) 
	{
		return;
	}
	size_t i = 0;
	while (src[i] != '\0') 
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

String::String() 
{
	size = 0;
	arr = new char[size + 1];
	arr[0] = '\0';
}

String::String(const char* str) 
{
	if (str == nullptr) 
	{
		size = 0;
		arr = new char[size + 1];
		arr[0] = '\0';
	}
	else 
	{
		size = strLen(str);
		arr = new char[size + 1];
		strCopy(str, arr);
	}
}

String::~String() 
{
	delete[] arr;
}

String::String(const String& str) 
{
	size = str.size;
	arr = new char[size + 1];
	strCopy(str.arr, arr);
}

String &String::operator=(const String& str) 
{
	if (this != &str) 
	{
		delete[] arr;
		size = str.size;
		arr = new char[size + 1];
		strCopy(str.arr, arr);
	}
	return *this;
}

String &String::operator=(const char* str) 
{
	if (str != nullptr) 
	{
		set(str);
	}
	return *this;
}

void String::set(const char* str) 
{
	if (str != nullptr) 
	{
		delete[] arr;
		size = strLen(str);
		arr = new char[size + 1];
		strCopy(str, arr);
	}
}

String &String::operator+=(const char ch) 
{
	char* newStr = new char[size + 2];
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
	return *this;
}

String &String::operator+=(const char* str) 
{
	if (str != nullptr) 
	{
		size_t len = strLen(str);
		char* newStr = new char[size + len +1];
		strCopy(arr, newStr);
		strCopy(str, newStr + size);
		newStr[size + len] = '\0';
		set(newStr);
	}
	return *this;
}

const char *String::get() const 
{
	return arr;
}

size_t String::len() const
{
	return size;
}

std::ostream & operator<<(std::ostream& stream, const String& str) 
{
	stream << str.arr;
	return stream;
}
const char String::operator[](size_t pos) 
{
	if (pos >= size) return 0;
	return arr[pos];
}

String String::subStr(size_t from, size_t to) 
{
	if (from < 0 || to >= size || from > to) 
	{
		return String();
	}

	String n;

	for (size_t i = 0; i < to - from + 1; i++) 
	{
		n += arr[i + from];
	}
	return n;
}

void String::append(const String& str) 
{
	*this += str.get();
}

String String::concat(const String& str) 
{
	String newStr = *this;
	newStr.append(str);
	return newStr;
}

std::istream &operator>>(std::istream& stream, String& str) 
{
	char n = '\n';
	str.clear();
	while (true) 
	{
		stream.get(n);
		if (n == '\n') 
		{
			break;
		}
		str += n;
	}
	return stream;
}

void String::clear() 
{
	delete[] arr;
	size = 0;
	arr = new char[size + 1];
	arr[0] = '\0';
}
