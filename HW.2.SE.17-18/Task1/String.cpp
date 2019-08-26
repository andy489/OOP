#include "String.h"

size_t strLen(const char* Str)
{
	size_t i = 0;
	for (; Str[i] != 0; ++i);
	return i;
}
void strCpy(char* dest, const char* src)
{
	size_t i = 0;
	for (; src[i] != 0; ++i) dest[i] = src[i];
	dest[i] = 0;
}
short strCmp(const char* Str1, const char* Str2)
{
	size_t i = 0;
	for (; Str1[i] != 0 && Str2[i] != 0; ++i)
	{
		if (Str1[i] < Str2[i]) return -1;
		else if (Str1[i] > Str2[i])	return 1;
	}
	return Str1[i] != Str2[i];
}
bool strEquals(const char* Str1, const char* Str2, size_t lim)
{
	for (size_t i = 0; i < lim; ++i)
	{
		if (Str1[i] != Str2[i])	return 0;
		else if (Str1[i] == 0 || Str2[i] == 0) return Str1[i] == Str2[i];
	}
	return 1;
}
void RReverse(char* Str, size_t len)
{
	if (len < 2) return;
	swap(Str[0], Str[len - 1]);
	RReverse(Str + 1, len - 2);
}

size_t String::calcSize(size_t strLen)
{
	size_t i = 1;
	for (; i <= strLen; i *= 2);
	return i;
}
void String::onlySet(const char* Str)
{
	size = strLen(Str);
	capacity = calcSize(size);
	str = new char[capacity];
	strCpy(str, Str);
}
void String::onlySet(char ch) 
{
	size = 1;
	capacity = 2;
	str = new char[capacity];
	str[0] = ch;
	str[1] = 0;
}
void String::grow() 
{
	if (capacity > size + 1) // Check if a grow is needed i.e the string is full
		return;
	capacity *= 2;
	char* newStr = new char[capacity];
	strCpy(newStr, str);
	delete[] str;
	str = newStr;
}
void String::shrink() 
{
	size_t newLen = calcSize(size);
	if (capacity <= newLen) // Check if a shrink is needed i.e the string is taking too much space
		return;
	capacity = newLen;
	char* newStr = new char[capacity];
	strCpy(newStr, str);
	delete[] str;
	str = newStr;
}

String::String() {
	onlySet("");
}
String::String(char ch) 
{
	onlySet(ch);
}
String::String(const char* Str) 
{
	onlySet(Str);
}
String::String(const String& Str) 
{
	onlySet(Str.str);
}
String::~String() 
{
	delete[] str;
}
String& String::Set(char ch) 
{
	delete[] str;
	onlySet(ch);
	return *this;
}
String& String::Set(const char* Str) 
{
	delete[] str;
	onlySet(Str);
	return *this;
}
String& String::Set(const String& Str) 
{
	if (&Str != this) {
		Set(Str.str);
	}
	return *this;
}
String& String::SetAt(char ch, size_t pos) 
{
	if (pos < size)	str[pos] = ch;
	return *this;
}
String& String::operator=(char ch) 
{
	Set(ch);
	return *this;
}
String& String::operator=(const char* Str)
{
	Set(Str);
	return *this;
}
String& String::operator=(const String& Str) 
{
	Set(Str);
	return *this;
}
String& String::append(char ch)
{
	grow();
	str[size] = ch;
	size++;
	str[size] = 0;
	return *this;
}
String& String::append(const char* Str)
{
	size_t length = strLen(Str);
	for (size_t i = 0; i < length; i++)	append(Str[i]);	
	return *this;
}
String& String::append(const String& Str)
{
	const String& ref = (&Str == this) ? clone() : Str;
	for (size_t i = 0; i < ref.size; i++) append(Str.str[i]);	
	return *this;
}
String& String::operator+=(const String& Str)
{
	return append(Str);
}
String& String::insertAt(const String& Str, size_t pos)
{
	if (pos > size) return *this;// If it's bigger return
	size_t newLen = size + Str.size;
	size_t newSize = calcSize(newLen);
	char* newStr = new char[newSize];
	size_t currPos = 0;
	for (; currPos < pos; ++currPos) newStr[currPos] = str[currPos];// Copy the beginning
	for (size_t i = 0; i < Str.size; ++i, ++currPos) newStr[currPos] = Str[i];// Copy the addition		
	for (size_t i = pos; str[i] != 0; ++i, ++currPos) newStr[currPos] = str[i];// Copy the remainder after the replaces sub string
	newStr[currPos] = 0;
	size = newLen;
	capacity = newSize;
	delete[] str;
	str = newStr;
	return *this;
}
std::ostream& operator<<(std::ostream& stream, const String& Str) 
{
	stream << Str.str;
	return stream;
}
std::istream& operator>>(std::istream& stream, String& Str) 
{
	Str.clear();
	char ch = '\n';
	while (stream.get(ch) && ch != '\n') Str.append(ch);
	return stream;
}
char String::operator[](const size_t pos) const 
{
	if (pos < size) return str[pos];
	return 0;
}
const char* String::Get() const 
{
	return str;
}
bool String::operator<(const String& Str) const 
{
	return strCmp(str, Str.str) < 0;
}
bool String::operator>(const String& Str) const 
{
	return strCmp(str, Str.str) > 0;
}
bool String::operator<=(const String& Str) const 
{
	return strCmp(str, Str.str) <= 0;
}
bool String::operator>=(const String& Str) const 
{
	return strCmp(str, Str.str) >= 0;
}
bool String::operator==(const String& Str) const 
{
	return strCmp(str, Str.str) == 0;
}
bool String::operator!=(const String& Str) const 
{
	return strCmp(str, Str.str) != 0;
}
size_t String::Size() const 
{
	return size;
}
size_t String::realSize() const 
{
	return capacity;
}
String String::concat(const String& Str) const 
{
	String newStr = *this;
	newStr.append(Str);
	return newStr;
}
String String::operator+(const String& Str) const 
{
	return concat(Str);
}
String String::substr(size_t from, size_t to) const 
{
	if (to < from) swap(to, from);
	if (to >= size) to = size;
	String newStr;
	for (; from < to && from < size; from++) newStr.append(str[from]);
	return newStr;
}
String String::clone() const 
{
	return String(*this);
}
String& String::clear() 
{
	delete[] str;
	onlySet("");
	return *this;
}
String& String::toLower() 
{
	for (size_t i = 0; i < size; ++i) if (str[i] >= 'A' && str[i] <= 'Z') str[i] += 'a' - 'A';
	return *this;
}
String& String::toUpper() 
{
	for (size_t i = 0; i < size; i++) if (str[i] >= 'a' && str[i] <= 'z') str[i] -= 'a' - 'A';
	return *this;
}
String& String::trimStart() 
{
	size_t removeTill = 0;
	for (size_t i = 0; i < size; i++) 
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') removeTill++;
		else break;
	}
	removeRange(0, removeTill);
	return *this;
}
String& String::trimEnd() 
{
	size_t removeFrom = size;
	for (size_t i = size - 1; i >= 0; --i) 
	{
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n') removeFrom--;
		else break;
	}
	removeRange(removeFrom, size);
	return *this;
}
String& String::trim() 
{
	trimStart();
	trimEnd();
	return *this;
}
String& String::removeAt(size_t indx) 
{
	if (indx < size) 
	{
		size_t newLen = size - 1;
		size_t newSize = calcSize(newLen);
		char* newStr = new char[newSize];
		for (size_t i = 0; i < indx; ++i) newStr[i] = str[i];
		strCpy(newStr + indx, str + indx + 1);
		delete[] str;
		str = newStr;
		size = newLen;
		capacity = newSize;
		shrink();
	}
	return *this;
}
String& String::removeRange(size_t from, size_t to) 
{ 
	if (to < from) swap(to, from);
	if (from >= size) return *this;
	if (to >= size) to = size;
	size_t newLen = size - (to - from);
	size_t newSize = calcSize(newLen + 1);
	char* newStr = new char[newSize];
	size_t currPos = 0;
	for (; currPos < from; ++currPos) newStr[currPos] = str[currPos];// Copy the beginning
	for (; to < size; ++to, ++currPos) newStr[currPos] = str[to];// Copy the ending
	newStr[currPos] = 0;
	delete[] str;
	str = newStr;
	size = newLen;
	capacity = newSize;
	return *this;
}
String& String::replace(const String& what, const String& with) 
{
	size_t index = indx(what);
	if (index != (size_t)-1) {
		size_t newLen = size - what.size + with.size;
		size_t newSize = calcSize(newLen + 1);
		char* newStr = new char[newSize];
		size_t currPos = 0;
		for (; currPos < index; currPos++) newStr[currPos] = str[currPos];// Copy the beginning			
		for (size_t i = 0; i < with.size; i++, currPos++) newStr[currPos] = with[i];// Copy the replacement
		for (size_t i = index + what.size; str[i] != 0; ++i, currPos++) // Copy the remainder after the replaces sub string
		newStr[currPos] = str[i];
		newStr[currPos] = 0;
		delete[] str;
		str = newStr;
		size = newLen;
		capacity = newSize;
	}
	return *this;
}
String& String::replaceAll(const String& what, const String& with) 
{
	size_t index = indx(what);
	while (index != (size_t)-1) 
	{
		replace(what, with);
		index = indx(what);
	}
	return *this;
}
String& String::remove(const String& what) 
{
	return replace(what, "");
}
String& String::removeAll(const String& what) 
{
	return replaceAll(what, "");
}
String& String::reverse() 
{
	RReverse(str, size);
	return *this;
}
bool String::contains(const String& Str) const 
{
	return indx(Str) != (size_t)-1;
}
bool String::startsWith(const String& Str) const 
{
	return strEquals(str, Str.str, Str.size);
}
bool String::endsWith(const String& Str) const 
{
	if (Str.size > size) return 0;
	size_t start = size - Str.size;
	return strEquals(str + start, Str.str, Str.size);
}
size_t String::indx(const String& Str) const 
{
	size_t Cap = size - Str.size + 1;
	for (size_t i = 0; i < Cap; ++i) if (strEquals(str + i, Str.str, Str.size)) return i;	
	return -1;
}
size_t String::lastIndex(const String& Str) const 
{
	size_t Cap = size - Str.size;
	for (size_t i = Cap; i >= 0; --i) if (strEquals(str + i, Str.str, Str.size)) return i;	
	return -1;
}
