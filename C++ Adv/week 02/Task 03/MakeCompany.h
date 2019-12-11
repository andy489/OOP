#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

#include <memory>
#include <vector>
#include <string>
#include <utility>
#include <cstddef>

int toInt(const std::string& s) {
	int i;
	std::istringstream(s) >> i;
	return i;
}

std::shared_ptr<Company> makeCompany(std::vector<std::string> properties) {
	int id = toInt(properties[0]);
	std::string name = properties[1];

	std::vector<std::pair<char, char> > employeeInitials;
	for (size_t i = 2; i < properties.size(); i++) {
		std::string initialsPair = properties[i];
		employeeInitials.push_back(std::pair<char, char>{ initialsPair[0], initialsPair[1] });
	}

	return std::shared_ptr<Company>(new Company(id, name, employeeInitials));
}

#endif // !MAKE_COMPANY_H
