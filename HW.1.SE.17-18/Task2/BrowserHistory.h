#pragma once
#include "String.h"
#include <iostream>

enum Month
{
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};

struct HistoryEntry
{
	Month month;
	String url;
};

/* currIndx = -1 => Meaning the list is empty
   currIndx = n => Meaning the n-th element of the list */
class BrowserHistory 
{
	HistoryEntry* list; /* array to store the entries */
	int size; // Maximum capacity
	int currIndx; // The current position in the array
	void swap(HistoryEntry& h1, HistoryEntry& h2); /* Helper function for sorting */
	int partition(int low, int high); /* Helper function for sorting */
	void sort(int low = -1, int high = -1); /* Sorting function used before printing */
	bool IsStrMonth(const String& str) const; /* Helper function for validating */
	Month strToMonth(const String& str); /* Helper function to convert String to enum Month */
public:
	BrowserHistory(int n = 0); /* Constructor, n is the number of the History entries that can be inserted */
	BrowserHistory(const BrowserHistory& history); /* Copy constructor */
	
	BrowserHistory& operator=(const BrowserHistory& history); /* Operator= */
	void add(const HistoryEntry& h); /* Add a History Entry to the list if it's not full */
	void printAll(); /* Print all the entries after sorting them by month */
	void inputFromConsole(); /* Get input from the console and use Add() */
	size_t numOfWebsVisitedInMonth(Month month); /* Return the number of websites visited a certain month */
	Month monthWithMostVisits(); /* Return the month with the mosts sites visited */
	void removeMostRecent(); /* Remove the most recent website (e.g to clear space to add more) */
	
	/* Concatenate this-> and anotherHistory into one new object which size is the combined and its entries are concatinated */
	BrowserHistory concat(const BrowserHistory& anotherHistory);
	String monthNumToStr(int num); // Convert a month (int) to a string representation for printing
	~BrowserHistory(); /* Destructor */
};
