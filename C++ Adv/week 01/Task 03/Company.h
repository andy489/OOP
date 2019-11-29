#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <istream>

class Company {
	std::string name;
	int id;
public:
	std::string getName() const {
		return this->name;
	}

	int getId() const {
		return this->id;
	}

	friend std::istream& operator>>(std::istream& stream, Company& company);
};

std::istream& operator>>(std::istream& stream, Company& company) {
	return stream >> company.name >> company.id;
}

std::ostream& operator<<(std::ostream& stream, const Company& company) {
	return stream << company.getName() << " " << company.getId();
}

#endif // !COMPANY_H

