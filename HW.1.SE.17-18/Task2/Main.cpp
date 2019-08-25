#include <iostream>
#include "String.h"
#include "BrowserHistory.h"

int main()
{
	HistoryEntry a{ January, "www.google.com" };
	HistoryEntry b{ May, "www.youtube.com" };
	HistoryEntry c{ May, "www.github.com" };
	HistoryEntry d{ November, "www.stackoverflow.com" };
	
	BrowserHistory BH(4);

	BH.add(a);
	BH.add(b);
	BH.add(c);
	BH.add(d);

	BH.printAll();
	
	Month mostVisits = BH.monthWithMostVisits();
	std::cout << "Most websites visited in " << BH.monthNumToStr(mostVisits) << " with " << BH.numOfWebsVisitedInMonth((Month)(mostVisits)) << " visits\n\n";
	   
	BrowserHistory newBH = BH;

	newBH.printAll();	

	newBH = newBH.concat(BH);
	newBH.printAll();

	newBH.inputFromConsole();
	newBH.printAll();

	std::cout << "~Removing most recent item\n\n";
	newBH.removeMostRecent();
	newBH.printAll();

	newBH.inputFromConsole();
	newBH.printAll();

	return 0;
}
