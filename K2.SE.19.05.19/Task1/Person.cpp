#include "Person.h"

void Person::copy(const Person & p)
{
	setName(p.getName());
	setEgn(p.getEgn());
	setAge(p.getAge());
	setBirthYear(p.getBirthYear());
}

Person::Person() :age(0), birthYear(0)
{
	setName("");
	setEgn("");
}

Person::Person(const char * name,
	const char * egn,
	size_t age,
	size_t birthYear)
{
	setName(name);
	setEgn(egn);
	setAge(age);
	setBirthYear(birthYear);
}

Person::Person(const Person& p)
{
	copy(p);
}

Person & Person::operator=(const Person & p)
{
	if (this != &p)
	{
		copy(p);
	}
	return *this;
}

Person::~Person()
{
	delete[] this->name;
	delete[] this->egn;
}

void Person::setName(const char* name)
{
	delete[]this->name;
	size_t len = strlen(name) + 1;
	this->name = new char[len];
	strcpy_s(this->name, len, name);
}

const char* Person::getName() const
{
	return this->name;
}

void Person::setEgn(const char* egn)
{
	delete[]this->egn;
	size_t len = strlen(egn) + 1;
	this->egn = new char[len];
	strcpy_s(this->egn, len, egn);
}

const char* Person::getEgn() const
{
	return this->egn;
}

void Person::setAge(size_t age)
{
	this->age = age;
}

size_t Person::getAge() const
{
	return this->age;
}

void Person::setBirthYear(size_t birthYear)
{
	this->birthYear = birthYear;
}

size_t Person::getBirthYear() const
{
	return this->birthYear;
}

void Person::print() const
{
	std::cout << "Name: " << getName() << "\n"
		<< "EGN: " << getEgn() << "\n"
		<< "Age: " << getAge() << "\n"
		<< "Birth: " << getBirthYear() << "\n\n";
}
