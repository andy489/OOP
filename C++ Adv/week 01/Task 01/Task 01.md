## Task 1 – TryParse
You are given program in a **Main.cpp** file that reads two strings, each of which **is either a valid integer, or contains only letters**, then attempts to parse them into integer numbers – using a function called tryParse – and calculate their sum.
If both numbers can be parsed, their sum is printed.
Otherwise, two lines are printed, one of them for the first number, the other for the second number. Each of those lines contains either the input string for that number, but if the number was not successfully parsed, the line starts with "[error] " followed by the input string for the number.
Your task is to study the code in Main.cpp, then create a file called TryParse.h (which Main.cpp includes) containing the definition of the tryParse function, written in such a way that Main.cpp compiles successfully and works as described above.
You should submit a single .zip file for this task, containing ONLY the TryParse.h file. The Judge system has a copy of the Main.cpp file and will compile it and your TryParse.h file in the same directory.
Examples
Input	Output
13 42	55
asd 112	[error] asd
112
