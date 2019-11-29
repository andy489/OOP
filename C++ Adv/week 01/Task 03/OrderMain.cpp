#include <iostream>
#include <string>
#include <sstream>
#include <vector>

#include "Company.h"
#include "OrderedInserter.h"

int main() {
	using namespace std;

	vector<const Company*> companies;

	OrderedInserter inserter{ companies };

	string line;
	while (getline(cin, line) && line != "end") {
		istringstream lineIn(line);

		Company* c = new Company();
		lineIn >> *c;
		inserter.insert((const Company*)c);
	}

	for (auto companyPtr : companies) {
		cout << *companyPtr << endl;
		delete companyPtr;
	}

	return 0;
}
