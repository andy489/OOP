#include "WebPage.h"

WebPage::WebPage()
{
	setAd("");
	setIp("");
}

WebPage::WebPage(const char* address, const char* ip)
{
	setAd(address);
	setIp(ip);
}

WebPage::WebPage(const WebPage& w)
{
	setAd(w.getAd());
	setIp(w.getIp());
}

WebPage & WebPage::operator=(const WebPage& w)
{
	if (this!=&w)
	{
		setAd(w.getAd());
		setIp(w.getIp());
	}
	return *this;
}

WebPage::~WebPage()
{
	delete[] this->address;
	delete[] this->ip;
}

void WebPage::setAd(const char* a)
{
	delete[] this->address;
	size_t len = strlen(a) + 1;
	this->address = new char[len];
	strcpy_s(this->address, len, a);
}

void WebPage::setIp(const char * i)
{
	delete[] this->ip;
	size_t len = strlen(i) + 1;
	this->ip = new char[len];
	strcpy_s(this->ip, len, i);
}

const char* WebPage::getAd() const
{
	return this->address;
}

const char* WebPage::getIp() const
{
	return this->ip;
}

std::ostream & operator<<(std::ostream & os, const WebPage & w)
{

	os << "Web Address is: " << w.getAd() << std::endl
		<< "IP address is: " << w.getIp() << std::endl
		<< ".... .... .... ...." << std::endl;

	return os;
}

std::istream & operator>>(std::istream & is, WebPage & w)
{
	char strInput[612];
	int intInput;

	std::cout << "Enter webpage & ip address separated by space:\n";
	is >> strInput;
	w.setAd(strInput);

	is >> strInput;
	w.setIp(strInput);

	return is;
}
