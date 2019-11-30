#ifndef COMPANY_H
#define COMPANY_H

#include <string>
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

	friend std::ostream& operator<<(std::ostream& stream, const Company& c);
};

std::ostream& operator<<(std::ostream& stream, const Company& c) {
	stream << c.id << " " << c.name << " (";

	for (int i = 0; i < c.employees.size(); i++) {
		auto initials = c.employees[i];
		stream << initials.first << "." << initials.second << ".";
		if (i < c.employees.size() - 1) {
			stream << ",";
		}
	}

	stream << ")";

	return stream;
}

#endif // !COMPANY_H

