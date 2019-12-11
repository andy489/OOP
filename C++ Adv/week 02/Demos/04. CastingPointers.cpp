#include <iostream>
#include <string>

int main() {
	using namespace std;

	char letter = 'A';

	void* voidPtr = &letter;
	char* charPtr = &letter;

	char* cStyleCastPtr = (char*)voidPtr;
	int* badCast = (int*)charPtr;

	cout << *cStyleCastPtr << endl; // prints 'A'
	cout << *badCast << endl; // undefined behavior - takes sizeof(int) bytes starting from 'A' and prints resulting number - could cause a memory error if those bytes are outside the program's memory

	char* staticCastPtr = static_cast<char*>(voidPtr); // for void pointer, static_cast is equivalent to C-Style cast
	//int* badStaticCastWontCompile = static_cast<int*>(charPtr); // static_cast here checks type and prevents compilation (uncomment to see compilation error)

	return 0;
}
