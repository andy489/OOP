#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Company.h"

#include "CompanyMemoryUtils.h"

int main() {
	typedef unsigned char byte;

	using namespace std;

	ostringstream input;
	string line;
	int numCompanies = 0;
	while (getline(cin, line) && line != "end") {
		input << line << " ";
		numCompanies++;
	}

	vector<byte> inputBytes;
	istringstream inputIn(input.str());
	int byteValue;
	while (inputIn >> byteValue) {
		inputBytes.push_back(byteValue);
	}

	byte* memory = new byte[inputBytes.size()];

	for (int i = 0; i < inputBytes.size(); i++) {
		memory[i] = inputBytes[i];
	}

	vector<Company> companies = readCompaniesFromMemory(memory, numCompanies);

	for (Company c : companies) {
		cout << c << endl;
	}

	delete[] memory;

	return 0;
}
