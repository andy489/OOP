#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <sstream>
#include <vector>
#include <utility>

class Company {
private:
	int id;
	std::string name;
	std::vector<std::pair<char, char> > employees;

public:
	Company(int id, std::string name, std::vector<std::pair<char, char> > employees)
		: id(id)
		, name(name)
		, employees(employees) {}

	std::string toString() {
		std::ostringstream stream;
		stream << id << " " << name << " ";

		for (int i = 0; i < employees.size(); i++) {
			auto initials = employees[i];
			stream << initials.first << initials.second;
			if (i < employees.size() - 1) {
				stream << " ";
			}
		}

		return stream.str();
	}
};

#endif // !COMPANY_H

