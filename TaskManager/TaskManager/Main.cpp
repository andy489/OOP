#include "ComplexTask.h"
#include "LongTask.h"
#include "SimpleTask.h"

#define _CRTDBG_MAP_ALLOC   // required
#include <stdlib.h>         // to enable MSVC++
#include <crtdbg.h>         // memory leak detection

void test()
{
	SimpleTask s1("Find x.");
	s1.Print();
	s1.Work(0.4);
	s1.Print();
	s1.Work(0.5);
	s1.Print();
	s1.Work(0.1);
	s1.Print();

	LongTask l1("Prove that sqrt of 2 is irrational.");
	double workLeft = l1.Work(1.5);
	l1.Print();
	std::cout << "Work time left: " << workLeft << std::endl << std::endl;

	ComplexTask C1;
	C1.addTask(&s1);
	C1.addTask(&l1);
	C1.Print();
	C1.Work(0.5);
	C1.Print();

	SimpleTask S1("Calculate first derivate of f(x).");
	LongTask L1("Find all combinations.");
	LongTask L2("Find all permutations.");
	ComplexTask C2;
	C2.addTask(&S1);
	C2.addTask(&L1);
	C2.addTask(&L2);
	C2.addTask(&C1);
	C2.Print();
	C2.Work(5);
	C2.Print();
}

int main()
{
	test();	
	_CrtDumpMemoryLeaks();
	return 0;
}
