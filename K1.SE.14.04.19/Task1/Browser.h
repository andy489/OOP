#pragma once
#include "WebPage.h"
class Browser
{
	WebPage* pages = nullptr;
	size_t size = 0;

	void incrementSize();
	void decrementSize();

	void copy(const Browser& w);

	void resize();
public:
	Browser();
	Browser(const Browser& b);
	Browser& operator=(const Browser& b);
	~Browser();

	WebPage operator[](int index) const;

	const size_t getSize()const;
	void setSize(size_t n);
	
	void addPage(const WebPage&);
	bool deletePage(size_t index);

	void operator+=(const WebPage&);
	bool operator-=(size_t index);

	void displayPages()const;
};
