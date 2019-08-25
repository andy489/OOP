#include "BrowserHistory.h"
#include "String.h"
#include <iomanip>

String months[] = { "January", "February", "March", "April", "May", "June",
					"July", "August", "September", "October", "November", "December" };

Month BrowserHistory::strToMonth(const String& s)
{   /* Convert a string to Month enum, assuming the string is validated to be a month */
	if (s == "January") return January;
	else if (s == "February") return February;
	else if (s == "March") return March;
	else if (s == "April") return April;
	else if (s == "May") return May;
	else if (s == "June") return June;
	else if (s == "July") return July;
	else if (s == "August") return August;
	else if (s == "September") return September;
	else if (s == "October") return October;
	else if (s == "November") return November;
	else if (s == "December") return December;
	return January; /* In case something goes wrong return January */
}

bool BrowserHistory::IsStrMonth(const String& str) const
{   /* Check if a string is a month (is contained in Months[]) */
	for (size_t i = 0; i < 12; i++) if (str == months[i]) return true;
	return false;
}

void BrowserHistory::swap(HistoryEntry& a, HistoryEntry& b)
{   /* Swap tow objects in the list (used for sorting) */
	HistoryEntry temp = a;
	a = b;
	b = temp;
}

int BrowserHistory::partition(int low, int high)
{   /* Helper function for sorting */
	int i = (low - 1);
	for (int j = low; j <= high - 1; j++)
	{
		if (list[j].month <= list[high].month)
		{
			i++;
			swap(list[i], list[j]);
		}
	}
	swap(list[i + 1], list[high]);
	return (i + 1);
}

void BrowserHistory::sort(int low, int high)
{   /* Quick sort modified to work properly for the BrowserHistory class */
	if (high == -1) high = currIndx;
	if (low == -1) low = 0;
	if (low < high)
	{
		int pi = partition(low, high);
		sort(low, pi - 1);
		sort(pi + 1, high);
	}
}

BrowserHistory::BrowserHistory(int N) : size(N), currIndx(-1)
{   /* Constructor */
	list = new HistoryEntry[N];
}

BrowserHistory::~BrowserHistory()
{   /* Destructor */
	delete[] list;
}

BrowserHistory::BrowserHistory(const BrowserHistory& history) : size(history.size), currIndx(0)
{   /* Copy constructor */
	list = new HistoryEntry[size];
	for (int i = 0; i < history.currIndx + 1; i++)
	{   /* Iterate over the History object and copy all its elements */
		list[i] = history.list[i];
	}
	currIndx = history.currIndx;
}

BrowserHistory& BrowserHistory::operator=(const BrowserHistory& history)
{   /* operator= */
	if (this != &history)
	{
		this->size = history.size;
		currIndx = -1;
		delete[] list;
		list = new HistoryEntry[size];
		/* Iterate over the History object and copy all its elements */
		for (int i = 0; i < history.currIndx + 1; i++) list[i] = history.list[i];
		currIndx = history.currIndx;
	}
	return *this;
}

void BrowserHistory::add(const HistoryEntry& entry)
{   /* Add a history entry to the list if it has space */
	if (currIndx >= size - 1)
	{
		std::cout << "This history is full. Cannot add more elements to it.\n";
		return;
	}
	currIndx++;
	list[currIndx] = entry;
}

void BrowserHistory::printAll()
{   /* Print all the entries after sorting them */
	if (currIndx == -1)
	{   /* If the list is empty, do nothing */
		std::cout << "There are no entries in the history";
		return;
	}
	sort();
	/* Iterate over the History object and copy all it's elements */
	for (int i = 0; i < currIndx + 1; i++) std::cout << std::setw(12) << std::left
		<< months[list[i].month - 1] << list[i].url << "\n";
	std::cout << "\n";
}

void BrowserHistory::inputFromConsole()
{   /* Prompt the user to input the next entry to a list and then add it via add() */
	String month;
	String url;
	while (!IsStrMonth(month))
	{
		std::cout << "Input the month for the History Entry (e.g December): ";
		std::cin >> month;
	}
	std::cout << "Input the url for the History Entry : ";
	std::cin >> url;
	add(HistoryEntry{ strToMonth(month), url });
}

size_t BrowserHistory::numOfWebsVisitedInMonth(Month monthToCheckFor)
{
	if (currIndx == -1)	return 0;
	size_t visits = 0;
	for (int i = 0; i < currIndx; i++) if (list[i].month == monthToCheckFor) visits++;
	return visits;
}

String BrowserHistory::monthNumToStr(int num)
{
	return months[num];
}

Month BrowserHistory::monthWithMostVisits()
{
	if (currIndx == -1)
	{
		std::cout << "There are no entries in the history";
		return January;
	}
	/* Each index of the array is the visits during a month (0-11) */
	int visits[] = { 0,0,0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < currIndx+1; i++) visits[list[i].month - 1]++;
	/* Find the index from the visits[] with highest count */
	int monthWithMostVisits = 0;
	for (int i = 0; i < 12; i++) if (visits[i] > monthWithMostVisits) monthWithMostVisits = i;
	/* Convert the index (from int to enum) and return it */
	return (Month)(monthWithMostVisits+1);
}

void BrowserHistory::removeMostRecent()
{
	if (currIndx == -1)
	{
		std::cout << "There are no entries in the history";
		return;
	}
	/* Clear the string (aka url) and decrease the currentIndex by 1, leaving the last object unaccessible */
	list[currIndx].url.clear();
	currIndx--;
}

BrowserHistory BrowserHistory::concat(const BrowserHistory& anotherHistory) 
{
	BrowserHistory newHistory(size + anotherHistory.size);
	int i = 0;
	if (currIndx != -1)
	{   /* Copy the elements of the current history into the new one */
		for (i = 0; i < currIndx + 1; i++) newHistory.list[i] = list[i];
	}
	int j = 0;
	/* Copy the elements of anotherHistory into the new one */
	if (anotherHistory.currIndx != -1) for (j = 0; j < anotherHistory.currIndx + 1; j++) newHistory.list[i + j] = anotherHistory.list[j];
	newHistory.currIndx = i + j - 1;
	return newHistory;
}
