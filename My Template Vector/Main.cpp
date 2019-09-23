#include "myVector.h"

void test()
{
	myVector<char> v;
	for (size_t i = 0; i < 26; i++) v.pushBack(char(i + 65));
	v.printVec();

	v.insert(10, '$');
	std::cout << "\n~Insertins symbol $ at position 10:\n" << v;

	for (size_t i = 0; i < 3; i++) v.remove(0);
	std::cout << "\n~Erasing first 3 elements:\n" << v;

	std::cout << "\n~Poping back one element: " << v.popBack() << '\n';
	std::cout << "\n~Pushing back element '.' and setting element at position 20 to be '%': \n";
	v.pushBack('.');
	v.setElement(20, '%');
	std::cout << v;

	std::cout << "~Testing begin(): " << v.begin() << '\n';
	std::cout << "~Testing begin(): " << v.end() << '\n';

	for (size_t i = 0; i < 20; i++) v.remove(0);
	std::cout << "\n~Erasing first 20 elements:\n" << v;

	myVector<char> newVec(v);
	newVec.popBack();
	newVec.remove(0);
	std::cout << "\n~Testing copy constructor: " << newVec;

	myVector<char>anotherVec = newVec;
	std::cout << "~Testing operator =: " << anotherVec;

	myVector<int> lastVec(10);
	std::cout << "~Testing constructor with parameter: " << lastVec;
}

int main()
{
	test();
	return 0;
}
