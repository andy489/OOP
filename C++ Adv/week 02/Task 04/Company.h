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

public:
	Company() {}

	Company(int id, std::string name)
		: id(id)
		, name(name) {}

	int getId() const {
		return this->id;
	}

	std::string getName() const {
		return this->name;
	}

	std::string toString() const {
		std::ostringstream stream;
		stream << id << " " << name << " ";
		return stream.str();
	}
};

#endif // !COMPANY_H
