## Task 2 – Find
You are given program in a **Main.cpp** file that reads info about **companies** – **name** and **id** – and then reads a **search id**, finds a company with that **id**, and prints the info about that company. If no such company has been entered, the program prints **"[not found]"**. To do the search, the program uses a function named find. To describe a company, it uses the **Company.h** file, which you are also given.

Your task is to study the code in **Main.cpp**, then create a file called **Find.h** (which **Main.cpp** includes) containing the definition of the **find** function, written in such a way that **Main.cpp** compiles successfully and works as described above.

You should submit a single **.zip** file for this task, containing ONLY the **Find.h** file. The Judge system has a copy of the **Main.cpp** file and will compile it along with your **Find.h** file in the same directory.

To correctly use the **Company** definition, without interfering with its usage by **Main.cpp**, use the following structure for the **Find.h** file:
```cpp
Find.h
#ifndef FIND_H
#define FIND_H

#include "Company.h"

// Place your code here, as well as any other #include directives you might need

#endif // !FIND_H
```

#### Examples

Input|Output
-|-
acme 424242420<br>itjoro 878968302<br>softuni_foundation 20140414<br>end<br>878968302|itjoro 878968302
