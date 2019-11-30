#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

#include "Company.h"
#include "ProfitCalculator.h"

#include "ProfitReport.h"

int main() {
	using namespace std;

	vector<Company> companies;

	string line;
	while (getline(cin, line) && line != "end") {
		istringstream lineIn(line);

		Company c;
		lineIn >> c;
		companies.push_back(c);
	}

	map<int, ProfitCalculator> profitCalculatorsByCompany;
	line = "";
	while (getline(cin, line) && line != "end") {
		istringstream lineIn(line);

		int companyId;
		lineIn >> companyId;
		ProfitCalculator calculator;
		lineIn >> calculator;

		profitCalculatorsByCompany[companyId] = calculator;
	}

	Company* fromInclusive = &companies[0];
	Company* toInclusive = &companies[companies.size() - 1];

	cout << getProfitReport(fromInclusive, toInclusive, profitCalculatorsByCompany) << endl;

	return 0;
}
