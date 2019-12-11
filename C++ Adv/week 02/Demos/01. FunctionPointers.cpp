#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> split(std::string s, char separator) {
	std::vector<std::string> strings;

	std::ostringstream current;
	for (char c : s) {
		if (c == separator) {
			strings.push_back(current.str());
			
			// clear the stringstream containing the current word to start reading the next
			current.str("");
			current.clear();
		}
		else {
			current << c;
		}
	}

	return strings;
}

int main() {
	std::vector<std::string> (*p)(std::string, char) = split;

	// p = split also works, the & is optional in this case

	std::vector<std::string> words = p("the quick brown fox jumps over the lazy dog", ' ');

	for (std::string w : words) {
		std::cout << w << std::endl;
	}

	return 0;
}
