#ifndef MIN_BY_H
#define MIN_BY_H

#include <cstddef> //size_t
#include <string>
#include <vector>

std::string minBy(const std::vector<std::string>& strings, bool(*lessThan)(const std::string&, const std::string&)) {
	std::string minString = strings[0];

	for (size_t i = 1; i < strings.size(); i++) {
		std::string s = strings[i];
		if (lessThan(s, minString)) {
			minString = s;
		}
	}

	return minString;
}

#endif // !MIN_BY_H
