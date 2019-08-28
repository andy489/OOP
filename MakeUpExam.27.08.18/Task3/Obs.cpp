#include "Obs.h"

const string Observer::obsTypeToStr(OBS obs) const
{
	if (obs == Newspaper) {
		return "Newspaper observer";
	}
	else if (obs == Radio) {
		return "Radio observer";
	}
	else if (obs == TV) {
		return "TV observer";
	}
	else {
		return "Unspecified observer";
	}
}

Observer::Observer() :city(""), temp(10)
{}

Observer::Observer(const string city, const float temp)
{
	setCity(city);
	setTemp(temp);
}

const string Observer::getCity() const
{
	return this->city;
}

void Observer::setCity(const string city)
{
	this->city = city;
}

const float Observer::getTemp() const
{
	return this->temp;
}

void Observer::setTemp(const float temp)
{
	this->temp = temp;
}

const OBS Observer::getType() const
{
	return this->obsType;
}

void Observer::printMeteo() const
{
	cout << "The temperature in " << getCity() << " is " << getTemp() << ".\n";
};

