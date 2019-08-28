#pragma once
#include <iostream>
#include <cstring>

class WebPage
{
	char* address = nullptr;
	char* ip = nullptr;
public:
	WebPage();
	WebPage(const char* address, const char* ip);
	WebPage(const WebPage& w);
	WebPage& operator=(const WebPage& w);
	~WebPage();

	const char *getAd() const;
	const char *getIp() const;

	void setAd(const char* a);
	void setIp(const char* i);

	friend std::ostream& operator<<(std::ostream&, const WebPage&);
	friend std::istream& operator>>(std::istream&, WebPage&);
};
