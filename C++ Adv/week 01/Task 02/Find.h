#pragma once
#include "Company.h"
#include <vector>
using namespace std;

Company* find(const vector<Company*>& companies, int searchId)
{	
	for (const auto c:companies)
	{
		if (c->getId()==searchId)
		{
			return c;
		}
	}
	return nullptr;
}
