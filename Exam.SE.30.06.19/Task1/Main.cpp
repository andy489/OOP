#include "Matrix.h"
#define _CRTDBG_MAP_ALLOC   // required
#include <stdlib.h>         // to enable MSVC++
#include <crtdbg.h>         // memory leak detection

void test()
{
	std::cout << "Checking default constructor:\n\n";
	Matrix<float> defMatrix;
	defMatrix.print();

	std::cout << "Checking constructor with parameters:\n\n";
	Matrix<double> parMatrix(4, 6);
	parMatrix.print();

	std::cout << "Checking copy constructor:\n\n";
	Matrix<double> cpyMatrix(parMatrix);
	cpyMatrix.print();

	std::cout << "Checking operator= :\n\n";
	Matrix<double> equalMatrix=parMatrix;
	equalMatrix.print();

	std::cout << "Testing setAt() function:\n\n";
	Matrix<int> intMatrix(3, 4);
	for (size_t i = 1; i <= 3; i++)
		for (size_t j = 1; j <= 4; j++)	intMatrix.setAt(i, j, j);
	intMatrix.print();

	std::cout << "Testing getAt() function:\n\n";
	std::cout << "Element at row 1, col 1: " << intMatrix.getAt(1, 1) << "\n";
	std::cout << "Element at row 3, col 4: " << intMatrix.getAt(3, 4) << "\n\n";

	std::cout << "Testing transpose() function:\n\n";
	intMatrix.transpose();
	intMatrix.print();
}

int main()
{
	test();
	_CrtDumpMemoryLeaks();	
	return 0;
}
