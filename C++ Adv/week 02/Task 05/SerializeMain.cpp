SerializeMain#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "Company.h"

#include "Serialize.h"

int main() {
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::ostringstream input;

	std::string line;
	std::getline(std::cin, line);
	while (line != "end") {
		input << line << std::endl;
		std::getline(std::cin, line);
	}

	size_t bytesWritten;
	byte* memory = serializeToMemory(input.str(), bytesWritten);
	for (byte* b = memory; b < memory + bytesWritten; b++) {
		std::cout << (int)(*b) << " ";
	}
	delete[] memory;

	return 0;
}
