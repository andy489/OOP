## Task 3 – Order
You are given program in an OrderMain.cpp file that reads info about companies – name and id – and then prints them ordered by their id, in increasing order. To describe a company, it uses the Company.h file, which you are also given.
To order the companies, OrderMain.cpp uses a class named OrderedInserter from a file named OrderedInserter.h – it initializes it with an empty vector of companies, then calls a method named insert for each company in the input, then prints the contents of the vector.
Your task is to study the code in OrderMain.cpp, then create a file called OrderedInserter.h (which OrderMain.cpp includes) containing the definition of the OrderedInserter class, written in such a way that Main.cpp compiles successfully and works as described above.
You should submit a single .zip file for this task, containing ONLY the OrderedInserter.h file. The Judge system has a copy of the other files and will compile them along with your OrderedInserter.h file in the same directory.
To correctly use the Company definition, without interfering with its usage by OrderMain.cpp, use the following structure for the OrderedInserter.h file:
OrderedInserter.h
#ifndef ORDERED_INSERTER_H 
#define ORDERED_INSERTER_H

#include "Company.h"

// Place your code here, as well as any other #include directives you might need

#endif // !ORDERED_INSERTER_H


Examples
Input	Output
acme 424242420
softuni_foundation 20140414
itjoro 878968302
end	softuni_foundation 20140414
acme 424242420
itjoro 878968302
