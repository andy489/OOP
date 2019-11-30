#ifndef COMPANY_MEMORY_UTILS_H
#define COMPANY_MEMORY_UTILS_H

#include "Company.h"

using namespace std;
typedef unsigned char byte;

vector <Company> readCompaniesFromMemory(byte* memory, int numCompanies)
{
	vector <Company> allCompanies;
	int i;
	for (i = 0; i < numCompanies; ++i)
	{
		unsigned char id_ = (*memory);
		int id = (int)id_;

		vector <char> namee;

		while (memory++)
		{
			if ((*memory) != '\0' || (*memory) != 0)
			{
				namee.push_back((*memory));
			}
			else break;			
		}
		string name;

		for (i = 0; i < namee.size(); ++i)
		{
			name += namee[i];
		}

		memory++; //pointing to the number of employees
		int numOfEmployees = (int)(*memory);

		vector <pair <char, char>> employeeNames;

		char first,second;
		for (i = 0; i < numOfEmployees; ++i)
		{
			memory++;
			first = toupper((*memory));
			memory++;
			second = toupper((*memory));
			employeeNames.push_back({first, second});
		}
		Company comp(id, name, employeeNames);
		allCompanies.push_back(comp);
		memory++;
	}
	return allCompanies;
}


#endif // !COMPANY_MEMORY_UTILS_H
