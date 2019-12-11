#include <string>
#include <vector>
#include <iostream>

class Person {
	std::string name;
	int age;
public:
	Person(std::string name, int age) : name(name), age(age) {}

	std::string getName() {
		return this->name;
	}
};

std::vector<Person*>* getPeople() {
	std::vector<Person*>* people = new std::vector<Person*>();

	people->push_back(new Person("Ben Dover", 42));
	people->push_back(new Person("Ary O'usure", 25));

	return people;
}

int main() {
	auto people = getPeople();

	std::cout << people->at(0)->getName() << std::endl;

	delete people; // memory leak - we delete the vector, but each Person* inside it needs to be deleted before that, i.e. for (auto p : people) { delete p; } and only then delete people;

	return 0;
}
