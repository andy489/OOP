#include "Browser.h"

void Browser::incrementSize()
{
	this->size++;
}

void Browser::decrementSize()
{
	this->size--;
}

void Browser::copy(const Browser& b)
{
	size_t n = b.getSize();
	delete[] this->pages;
	for (size_t i = 0; i < n; i++) this->addPage(b[i]);
}

void Browser::resize()
{
	size_t n = getSize();
	WebPage* newPage = new WebPage[n + 1];
	for (size_t i = 0; i < n; i++)	newPage[i] = this->pages[i];
	delete[] this->pages;
	this->pages = newPage;
	incrementSize();
}

Browser::Browser()
{
	pages = nullptr; //already set
}

Browser::Browser(const Browser & b)
{
	copy(b);
}

Browser & Browser::operator=(const Browser& b)
{
	if (this != &b)
	{
		copy(b);
	}
	return *this;
}

Browser::~Browser()
{
	delete[] this->pages;
}

WebPage Browser::operator[](int index) const
{
	size_t n = getSize();
	if (index > (int)(n-1) || index < 0) return WebPage();
	else return this->pages[index];
}

const size_t Browser::getSize() const
{
	return this->size;;
}

void Browser::setSize(size_t n)
{
	this->size = n;
}

void Browser::addPage(const WebPage & w)
{
	resize();
	size_t n = getSize();
	this->pages[n - 1] = w;
}

bool Browser::deletePage(size_t index)
{
	size_t n = getSize();
	if (index < 0 || index >= n) return false;
	for (size_t i = index; i < n-1; i++)	this->pages[i] = this->pages[i + 1];
	decrementSize();
	return true;
}

void Browser::operator+=(const WebPage & w)
{
	addPage(w);
}

bool Browser::operator-=(size_t index)
{
	return deletePage(index);
}

void Browser::displayPages() const
{
	std::cout << "Displaying browser:\n";
	size_t n = getSize();
	for (size_t i = 0; i < n; i++)
	{
		std::cout << "Page " << i + 1 << ": " << "\n";
		std::cout << "Address: ";
		std::cout << pages[i].getAd() << "\n";
		std::cout << "IP: ";
		std::cout << pages[i].getIp() << "\n\n";
	}
}
