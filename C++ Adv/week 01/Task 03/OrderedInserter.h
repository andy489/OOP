#pragma once
#include <vector>
#include "Company.h"
using namespace std;

struct OrderedInserter
{
	vector<const Company*>& companies;
public:
	OrderedInserter(vector<const Company*>& companies) :companies(companies) {}

	void insert(const Company* c) {

		companies.push_back(c);
		size_t i = companies.size() - 1;
		while (i >= 1 && companies[i]->getId() < companies[i - 1]->getId()) {
			swap(companies[i], companies[i - 1]);
			i--;
		}
	}
