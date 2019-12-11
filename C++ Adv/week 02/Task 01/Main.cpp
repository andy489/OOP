#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "MinBy.h"

std::vector<std::string> readWhitespaceSeparatedValuesLine() {
	std::vector<std::string> values;

	std::string line;
	std::getline(std::cin, line);

	std::istringstream lineIn(line);

	std::string value;
	while (lineIn >> value) {
		values.push_back(value);
	}

	return values;
}

bool lessThanBySize(const std::string& a, const std::string& b) {
	return a.size() < b.size();
}

bool lessThanByLex(const std::string& a, const std::string& b) {
	return a < b;
}

bool moreThanBySize(const std::string& a, const std::string& b) {
	return a.size() > b.size();
}

int main() {
	std::vector<std::string> values = readWhitespaceSeparatedValuesLine();

	int minCharacteristic = readWhitespaceSeparatedValuesLine()[0][0] - '0';

	switch (minCharacteristic)
	{
	case 1:
		std::cout << minBy(values, lessThanByLex) << std::endl;
		break;
	case 2:
		std::cout << minBy(values, lessThanBySize) << std::endl;
		break;
	case 3:
		std::cout << minBy(values, moreThanBySize) << std::endl;
		break;
	default:
		break;
	}

	return 0;
}
