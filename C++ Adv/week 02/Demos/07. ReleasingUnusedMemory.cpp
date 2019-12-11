#include <iostream>
#include <vector>
#include <cmath>

double* getPrecomputedSquareRoots(int toNumber) {
	double* roots = new double[toNumber + 1];
	for (size_t i = 0; i <= toNumber; i++) {
		roots[i] = sqrt(i);
	}

	return roots;
}

int main() {
	double* roots = getPrecomputedSquareRoots(10000);

	int numbers;
	std::cin >> numbers;
	for (int i = 0; i < numbers; i++) {
		int number;
		std::cin >> number;

		std::cout << "sqrt(" << number << ") = " << roots[number] << std::endl;
		//std::cout << "sqrt(" << number << ") = " << getPrecomputedSquareRoots(10000)[number] << std::endl; // memory leak on each iteration
	}

	delete[] roots;

	return 0;
}
