#include "TVObserver.h"

TVObserver::TVObserver() :Observer()
{
	obsType = OBS::TV;
}

TVObserver::TVObserver(const string city, const float temp, const string tvName) : Observer(city, temp)
{
	setTvName(tvName);
	obsType = OBS::TV;
}

const string TVObserver::getTvName() const
{
	return this->tvName;
}

void TVObserver::setTvName(const string tvName)
{
	this->tvName = tvName;
}

void TVObserver::update(const string name, const float temp)
{
	setCity(name);
	setTemp(temp);
	cout << "Update " << getTvName() << ": The temperature in " << name << " is " << getTemp() << ".\n";
}

void TVObserver::printMeteo() const
{
	cout << obsTypeToStr(getType()) << " " << getTvName() << ": ";
	Observer::printMeteo();
}
Observer * TVObserver::clone() const
{
	return new TVObserver(*this);
}
