#ifndef SERIALIZE_H
#define SERIALIZE_H

#include "Company.h"

#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

std::vector<byte> serializeToBytes(const Company& company) {
	std::vector<byte> companyBytes;

	companyBytes.push_back(company.getId());

	for (char c : company.getName()) {
		companyBytes.push_back((byte)c);
	}
	companyBytes.push_back('\0');

	auto employees = company.getEmployees();
	companyBytes.push_back(employees.size());

	for (auto e : employees) {
		companyBytes.push_back((byte)e.first);
		companyBytes.push_back((byte)e.second);
	}

	return companyBytes;
}

byte* serializeToMemory(std::string companiesString, size_t& bytesWritten) {
	std::istringstream companiesIn(companiesString);

	std::vector<Company> companies;

	Company company;
	while (companiesIn >> company) {
		companies.push_back(company);
	}

	std::vector<byte> bytes;

	bytes.push_back(companies.size());

	for (Company c : companies) {
		auto companyBytes = serializeToBytes(c);
		bytes.insert(bytes.end(), companyBytes.begin(), companyBytes.end());
	}

	bytesWritten = bytes.size();
	byte* memory = new byte[bytes.size()];
	for (int i = 0; i < bytes.size(); i++) {
		memory[i] = bytes[i];
	}

	return memory;
}

#endif // !SERIALIZE_H

