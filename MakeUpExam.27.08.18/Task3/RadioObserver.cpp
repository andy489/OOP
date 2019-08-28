#include "RadioObserver.h"

RadioObserver::RadioObserver() :Observer()
{
	obsType = OBS::Radio;
}

RadioObserver::RadioObserver(const string city, const float temp, const string radioName) : Observer(city, temp)
{
	setRadioName(radioName);
	obsType = OBS::Radio;
}

const string RadioObserver::getRadioName() const
{
	return this->radioName;
}

void RadioObserver::setRadioName(const string radioName)
{
	this->radioName = radioName;
}

void RadioObserver::update(const string name, const float temp)
{
	setCity(name);
	setTemp(temp);
	cout << "Update " << getRadioName() << ": The temperature in " << name << " is " << getTemp() << ".\n";
}

void RadioObserver::printMeteo() const
{
	cout << obsTypeToStr(getType()) << " " << getRadioName() << ": ";
	Observer::printMeteo();
}
Observer * RadioObserver::clone() const
{
	return new RadioObserver(*this);
}
