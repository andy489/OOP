## Task 3 – Make Company

You are given program in an **MakeCompanyMain.cpp**, as well as a **Company.h** file, that read information about **companies** and writes it to the console.
Each company has:
-	An id (a 4-byte integer)
-	A name (a string containing a sequence of lowercase English letters a-z)
-	Employees by their initials (a vector of pairs of characters, containing at most 255 employee initials)
The MakeCompanyMain.cpp file reads the information from the console as a single line for each company, containing:
-	company id string 
-	space
-	company name
-	2 characters representing the initials of the first employee
-	Space
-	Again 2 characters, representing the second employee
-	… and so on
NOTE: there could be companies without employees, in which case the line ends with the company name.
For example, if we have the companies:
-	id = 42, name = "uni", employees = { {'I', 'K'}, {'S', 'N'} } and 
id = 13, name = "joro", employees = { {'G', 'G' } }
Their representation as strings read by MemoryMain.cpp will be:
42 uni IK SN
13 joro GG
The program reads each line from the console, then calls a function named makeCompany to dynamically allocate memory for a Company object and set its values, then prints its representation as a back to the console (i.e. the program should print the exact line it read), until a line containing the single string "end" is reached.
Your task is to create a file called MakeCompany.h containing the function makeCompany such that the program compiles successfully and performs the described task. 
Your file should resemble the following:
MakeCompany.h
#ifndef MAKE_COMPANY_H
#define MAKE_COMPANY_H

#include "Company.h"

// Place your code here

#endif // !MAKE_COMPANY_H

You should submit a single .zip file for this task, containing ONLY the MakeCompany.h file. The Judge system has a copy of the other files and will compile them, along with your file, in the same directory.
Additional Requirements
Make sure you correctly create the Company objects and ensure that there are no memory leaks.
Examples
Input	Output
42 uni IK SN
13 joro GG
end	42 uni IK SN
13 joro GG
188 noemployees
58 oneemployee SA
end	188 noemployees
58 oneemployee SA
