#pragma once
#include <iostream>

class String 
{
	size_t size; // The length of the string 
	size_t capacity; /* The actual length of str, where the string is stored, powers of 2 */
	char* str; // The array where the string is stored
	void onlySet(const char* Str); // Only set string without deleting (used in copying, operator=, etc.)
	void onlySet(char Char); // Only set string without deleting (used in copying, operator=, etc.)
	void grow(); // Increase the size of the array <str>
	void shrink(); // Decrease the size of the array <str>
	size_t calcSize(size_t StrLen); // Calculates how big str needs to be, Returns the smallest power of 2 which is bigger than StrLen
public:
	// Constructors
	String(); // Default constructor, only initializes the '\0'
	String(char Char); // Constructs a string from a given single character
	String(const char* Str); // Constructs a string from a given char array
	// Copy constructor
	String(const String& Str); // Constructs a string from another string
	// Destructor
	~String(); // Frees the memory taken by <str>
	// Assignment
	String& Set(char ch);// Sets the contents of a string, like what the operator= would do usually
	String& Set(const char* Str);
	String& Set(const String& Str);
	String& SetAt(char Char, size_t pos); // Sets the character at some position if that position is valid
	String& operator=(char ch); // Operator= acting as the copy constructor but deleting the current str first
	String& operator=(const char* Str);
	String& operator=(const String& Str);
	// Append
	String& append(char ch); // Append to the end of the string
	String& append(const char* Str);
	String& append(const String& Str);
	String& operator+=(const String& Str); // Calls Append
	String& insertAt(const String& Str, size_t pos); // Inserts the string at the given position
													 // Operators << and >>
	friend std::ostream& operator<<(std::ostream& stream, const String& Str);
	friend std::istream& operator>>(std::istream& stream, String& Str);
	// Accessing
	char operator[](const size_t pos) const; // Return a copy of the character at the position
	const char* Get() const; // Return the whole string
	// Comparison
	bool operator<(const String& Str) const;
	bool operator>(const String& Str) const;
	bool operator<=(const String& Str) const;
	bool operator>=(const String& Str) const;
	bool operator==(const String& Str) const;
	bool operator!=(const String& Str) const;
	// Properties
	size_t Size() const; // The length of the str
	size_t realSize() const; // The actual space that the object takes in the memory
	// Concatenation
	String concat(const String& Str) const; // Return a new string which is the concatenation of this and Str
	String operator+(const String& Str) const; // Calls Concat
	// Other functionalities
	String substr(size_t from, size_t to) const; // Return a new string which is a substring of this
	String clone() const; // Return a copy of the current object
	String& clear(); // Set the contentst to be ""
	String& toLower(); // Convert the English letters in the string to lowercase
	String& toUpper(); // Convert the English letters in the string to uppercase
	String& trimStart(); // Remove all spaces at the beginning of the string
	String& trimEnd(); // Remove all spaces at the end of the string
	String& trim(); // TrimStart and TrimEnd
	String& removeAt(size_t indx); // Remove the character at the Index position from the string
	String& removeRange(size_t from, size_t to); // Remove a substring
	String& replace(const String& what, const String& with); // Replace What with With ONCE
	String& replaceAll(const String& what, const String& with); // Replace What with With until there's no more What in the string. WARNING: Be careful what you replace, could enter infinite loop
	String& remove(const String& what); // Removes substring from the string
	String& removeAll(const String& what); // Removes all substrings from the string
	String& reverse(); // Reverse the string
					   // Lookup
	bool contains(const String& Str) const; // Returns if the string contains Str as a substring
	bool startsWith(const String& Str) const; // Returns if the string starts with Str
	bool endsWith(const String& Str) const; // Returns if the string ends with Str
	size_t indx(const String& Str) const; // Returns the first position where Str is encountered
	size_t lastIndex(const String& Str) const; // Returns the last position where Str is encountered
};

template <typename T>
void swap(T& item1, T& item2) 
{ // Swaps the 2 items in the memory
	T tempItem = item1;
	item1 = item2;
	item2 = tempItem;
}
size_t strLen(const char* Str); // Returns the length of a null-terminated string
void strCpy(char* dest, const char* src); // Copies the contents of string Source into string Dest
short strCmp(const char* Str1, const char* Str2); // Compares 2 strings like the usual strcpy does
bool strEquals(const char* Str1, const char* Str2, size_t Limit); // Determines if 2 strings are equal, takes the length to which to compare
void RReverse(char* Str, size_t Len); // Recursively reverses a string


