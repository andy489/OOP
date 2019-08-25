#include <iostream>

class String 
{
private:
	size_t size;
	char * arr;
	size_t strLen(const char* str); // Return the lenght of a string, 0 if the size is or on error
	void strCopy(const char* src, char* dest); // Copy a char array assuming the destination has enough space
public:
	String(); /* Constructor */
	String(const char* str); /* Copy constructor */	
	String(const String& str); /* Copy constructor */

	String &operator=(const String& str); /* Operator= */
	String &operator=(const char* str); /* Calls Set() */
	String &operator+=(const char); /* Append a character to the end of the current object */
	String &operator+=(const char* str); /* Append a string to  the end of current object */

	friend std::ostream &operator<<(std::ostream& stream, const String& str); /* Overwrite the << operator to work correctly */
	friend std::istream &operator>>(std::istream& stream, String& str); /* Overwrite the >> operator to work correctly */
	
	const char operator[](size_t pos); /* Return the character on the given position */
	const char* get() const; /* Return pointer to the array where the string is */
	void set(const char* str); /* Set the string to equal a char array */

	size_t len() const; /* Return the length of the string */
	String subStr(size_t from, size_t to); /* Return a string containing a substring between the 2 indexes */
	void append(const String& str); /* Append a string to the end of this */
	String concat(const String& str); /* Concatenate this and the new string and return a new string object containing the concatenation */
	void clear(); /* Empties the string */
	
	~String(); /* Destructor */
};
