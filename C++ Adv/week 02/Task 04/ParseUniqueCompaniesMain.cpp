#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>

#include "Company.h"
#include "ParseCompanies.h"

std::string byName(const Company& c) {
	return c.getName();
}

std::string byId(const Company& c) {
	std::ostringstream asStringOut;
	asStringOut << c.getId();
	return asStringOut.str();
}

std::string byNameAndId(const Company& c) {
	return byName(c) + byId(c);
}

int main() {
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);
	
	std::ostringstream input;

	std::string line;
	std::getline(std::cin, line);
	while (line != "end") {
		input << line << std::endl;
		std::getline(std::cin, line);
	}

	int uniquenessCriteria;
	std::cin >> uniquenessCriteria;

	int numCompanies;
	Company* companies;
	
	if (uniquenessCriteria == 1) {
		companies = parseUniqueCompanies(input.str(), numCompanies, byId);
	}
	else if (uniquenessCriteria == 2) {
		companies = parseUniqueCompanies(input.str(), numCompanies, byName);
	}
	else if (uniquenessCriteria == 3) {
		companies = parseUniqueCompanies(input.str(), numCompanies, byNameAndId);
	}
	else {
		companies = nullptr;
	}

	Company* companiesEnd = companies + numCompanies;
	for (Company* c = companies; c < companiesEnd; c++) {
		std::cout << c->toString() << std::endl;
	}
	delete[] companies;

	return 0;
}
