#include <iostream>
#include <string>

#include "TryParse.h"

int main() {
	std::string aString, bString;
	std::cin >> aString >> bString;

	int a = 0, b = 0;
	bool parsedA = tryParse(aString, a);
	bool parsedB = tryParse(bString, b);
	if (parsedA && parsedB) {
		std::cout << a + b << std::endl;
	}
	else {
		if (parsedA) {
			std::cout << a << std::endl;
		}
		else {
			std::cout << "[error] " << aString << std::endl;
		}

		if (parsedB) {
			std::cout << b << std::endl;
		}
		else {
			std::cout << "[error] " << bString << std::endl;
		}
	}

	return 0;
}
