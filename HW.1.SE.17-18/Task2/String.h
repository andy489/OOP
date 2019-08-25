#pragma once
#include <iostream>

class String {
private:
	size_t size;
	char * arr;
	const size_t strLen(const char* str) const; /* Return the lenght of a string */
	void strCpy(const char* src, char* dest); /* Copy a char array assuming the destination has enough space */
	void setWithoutDelete(const char* str);
	void setWithoutDelete(const String& str);
public:
	String(); /* Constructor */
	String(const char* str); /* Copy constructor */
	String(const String& str); /* Copy constructor */
	~String(); /* Destructor */

	String& operator=(const String& str); /* operator= */
	String& operator=(const char* str); /* operator= */
	String& operator+=(const char ch); /* Append a character to the end of the current object */
	String& operator+=(const char* str); /* Append a string to the end of current object */
	String& operator+=(const String& str); /* Append a string to the end of current object */
	
	friend std::ostream &operator<<(std::ostream &stream, const String& str); /* Overwrite the << operator to work correctly */
	friend std::istream &operator>>(std::istream &stream, String& str); /* Overwrite the >> operator to work correctly */
	
	const char operator[](const size_t pos) const; /* Return the character on the given position */
	bool operator==(const char*) const; /* Compare two strings */
	bool operator==(const String& str) const; /* Compare two strings */
	bool operator!=(const char*) const; /* Compare two strings */
	bool operator!=(const String& str) const; /* Compare two strings */
	
	const char* get() const; /* Return pointer to the array where the string is */
	void set(const char* str); /* Set the string to equal a char array */
	void set(const String& str); /* Set the string to equal another string */
	size_t length() const; /* Return the length of the string */
	String subStr(size_t from, size_t to) const; /* Return a string containing a substring between the two indexes */
	void append(const String& str); /* Append a string to the end of this */
	void append(const char* str); /* Append a string to the end of this */
	void append(const char ch); /* Append a string to the end of this */
	String concat(const String& str) const; /* Concatenate this and the new string and return a new string object containing the concatination */
	void clear(); /* Empties the string */
	void toLower();
	void toUpper();
};
