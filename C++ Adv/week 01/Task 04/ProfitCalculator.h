#ifndef PROFIT_CALCULATOR_H
#define PROFIT_CALCULATOR_H

#include <istream>
#include "Company.h"

class ProfitCalculator {
private:
	int taxPercentage;
public:
	int calculateProfit(const Company& company) const {
		int balance = company.getRevenue() - company.getCosts();
		int tax = (balance * taxPercentage) / 100;
		return balance - tax;
	}

	friend std::istream& operator>>(std::istream& stream, ProfitCalculator& p);
};

std::istream& operator>>(std::istream& stream, ProfitCalculator& p) {
	return stream >> p.taxPercentage;
}

#endif
