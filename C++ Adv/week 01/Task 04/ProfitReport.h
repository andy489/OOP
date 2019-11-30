#pragma once
#include <sstream>
#include <map>
#include "ProfitCalculator.h"
using namespace std;

string getProfitReport(Company* fromInclusive,
	Company* toInclusive,
	map<int, ProfitCalculator> profitCalculatorsByCompany)
{
	ostringstream ostr;
	for (fromInclusive; fromInclusive != toInclusive + 1; fromInclusive++)
	{
		ostr << fromInclusive->getName() << " = " <<
			profitCalculatorsByCompany[fromInclusive->getId()].calculateProfit(*fromInclusive)
			<< '\n';
	}
	return ostr.str();
}
