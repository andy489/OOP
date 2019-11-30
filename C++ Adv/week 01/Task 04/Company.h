#pragma once
#ifndef COMPANY_H
#define COMPANY_H

#include <string>
#include <istream>

class Company {
	std::string name;
	int id;
	int revenue;
	int costs;
public:
	std::string getName() const {
		return this->name;
	}

	int getId() const {
		return this->id;
	}

	int getRevenue() const {
		return this->revenue;
	}

	int getCosts() const {
		return this->costs;
	}

	friend std::istream& operator>>(std::istream& stream, Company& company);
};

std::istream& operator>>(std::istream& stream, Company& company) {
	char separator;
	return stream >> company.name >> company.id >> separator >> company.revenue >> company.costs;
}

std::ostream& operator<<(std::ostream& stream, const Company& company) {
	return stream << company.getName() << " " << company.getId() << " : " << company.getRevenue() << " " << company.getCosts();
}

#endif // !COMPANY_H

