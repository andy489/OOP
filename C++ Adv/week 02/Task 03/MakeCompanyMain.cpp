#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Company.h"
#include "MakeCompany.h"

std::vector<std::string> readStringsLine() {
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

int main() {
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::vector<std::string> properties = readStringsLine();
	while (properties[0] != "end") {
		auto company = makeCompany(properties);

		auto copy = company;

		std::cout << copy->toString() << std::endl;

		properties = readStringsLine();
	}

	return 0;
}
