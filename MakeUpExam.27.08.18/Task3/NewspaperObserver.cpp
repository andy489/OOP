#include "NewspaperObserver.h"

NewspaperObserver::NewspaperObserver() :Observer()
{
	obsType = OBS::Newspaper;
}

NewspaperObserver::NewspaperObserver(const string city, const float temp, const string newsName) : Observer(city, temp)
{
	setNewsName(newsName);
	obsType = OBS::Newspaper;
}

const string NewspaperObserver::getNewsName() const
{
	return this->newsName;
}

void NewspaperObserver::setNewsName(const string newsName)
{
	this->newsName = newsName;
}

void NewspaperObserver::update(const string name, const float temp)
{
	setCity(name);
	setTemp(temp);
	cout << "Update " << getNewsName() << ": The temperature in " << name << " is " << getTemp() << ".\n";
}

void NewspaperObserver::printMeteo() const
{
	cout << obsTypeToStr(getType()) << " " << getNewsName() << ": ";
	Observer::printMeteo();
}

Observer * NewspaperObserver::clone() const
{
	return new NewspaperObserver(*this);
}
