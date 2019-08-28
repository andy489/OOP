#pragma once
#include <iostream>
#include <cstring>

class Person
{
	char* name = nullptr;
	char* egn = nullptr;
	size_t age;
	size_t birthYear;

	void copy(const Person& p);

public:

	Person();
	Person(const char* name,
		const char* egn,
		size_t age,
		size_t birthYear);
	Person(const Person& p);
	Person& operator=(const Person& p);
	~Person();

	void setName(const char* name);
	const char* getName() const;

	void setEgn(const char* egn);
	const char* getEgn() const;

	void setAge(size_t age);
	size_t getAge() const;

	void setBirthYear(size_t birthYear);
	size_t getBirthYear() const;

	void print() const;
};
