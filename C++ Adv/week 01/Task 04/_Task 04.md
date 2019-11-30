## Task 4 – Profits
You are given program in an **ProfitsMain.cpp**, as well as a **Company.h** and **ProfitCalculator.h** file, that read info about **companies – name, id, revenue** and **costs**, followed by info about profit calculations per company – **company id** followed by a **tax percentage** – and generates a report with the profit for each company in the input.

The report must contain exactly as many lines as there are companies, and each line should contain the name of the company on that line in the input, followed by a space, a '=', another space, and an integer value representing the profits of the company, e.g. a line of the output for a company called **TheCompany** with a profit of **42000** should look like this:

**TheCompany = 42000**

To generate the report, **ProfitsMain.cpp** uses a function named **getProfitReport** from a file named **ProfitReport.h**. The **getProfitReport** function receives 3 parameters:

-	A pointer to the first company in an array of companies
-	A pointer to the last company (inclusive) in an array of companies
-	An **std::map**, which maps company ids to **ProfitCalculators**

The **getProfitReport** should use the appropriate **ProfitCalculator** from the map (i.e. the **ProfitCalculator** in the entry with a key matching the id of the company) to calculate each company’s profit.

The **getProfitReport** returns a string, containing the report for the provided companies, calculated through the provided **ProfitCalculators**, as described above.

Your task is to study the code in **ProfitsMain.cpp**, then create a file called **ProfitReport.h** (which **ProfitsMain.cpp** includes) containing the definition of the **getProfitReport** function, written in such a way that ProfitsMain.cpp compiles successfully and works as described above.

You should submit a single **.zip** file for this task, containing ONLY the **ProfitReport.h** file. The Judge system has a copy of the other files and will compile them along with your **ProfitReport.h** file in the same directory.

To correctly use the **Company** definition, and the **ProfitCalculator** definition, without interfering with their usage by **ProfitsMain.cpp**, use the following structure for the **OrderedInserter.h** file:

**ProfitReport.h**
```cpp
#ifndef PROFIT_REPORT_H
#define PROFIT_REPORT_H

#include "Company.h"
#include "ProfitCalculator.h"

// Place your code here, as well as any other #include directives you might need

#endif // !PROFIT_REPORT_H
```
#### Examples

Input|Output
-|-
acme 424242420 : 43000 1000<br>softuni_foundation 20140414 : 0 0<br>itjoro 878968302 : 100 25<br>end<br>878968302 0<br>424242420 10<br>20140414 30<br>end|acme = 37800<br>softuni_foundation = 0<br>itjoro = 75
