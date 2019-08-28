#include "MeteoStation.h"

MeteoStation::MeteoStation() :cityName(""), temp(10)
{}

MeteoStation::MeteoStation(const string name, const float temp)
{
	setCity(name);
	this->temp=temp;
}

MeteoStation::MeteoStation(const MeteoStation & m) : observers(m.observers.size())
{
	this->cityName = m.getCity();
	this->temp = m.getTemp();
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i] = m.observers[i]->clone();
	}
}

MeteoStation & MeteoStation::operator=(const MeteoStation & m)
{
	if (this != &m)
	{
		for (size_t i = 0; i < observers.size(); i++)
		{
			delete observers[i];
		}

		observers.clear();

		for (size_t i = 0; i < m.observers.size(); i++)
		{
			observers.push_back(m.observers[i]->clone());
		}
	}
	return *this;
}

MeteoStation::~MeteoStation()
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		delete observers[i];
	}
	observers.clear();
}

void MeteoStation::setCity(const string name)
{
	this->cityName = name;
}

void MeteoStation::setTemp(const float temp)
{
	if (getTemp() != temp)
	{
		this->temp = temp;
		notify();
	}
}

const string MeteoStation::getCity() const
{
	return this->cityName;
}

const float MeteoStation::getTemp() const
{
	return this->temp;
}

void MeteoStation::registerObs(Observer * obs)
{
	NewspaperObserver* newspaper = dynamic_cast<NewspaperObserver*>(obs);
	RadioObserver* radio = dynamic_cast<RadioObserver*>(obs);
	TVObserver* tv = dynamic_cast<TVObserver*>(obs);

	Observer* newObs;

	if (newspaper != 0)
	{
		newObs = new NewspaperObserver(*newspaper);
	}
	else if (radio != 0)
	{
		newObs = new RadioObserver(*radio);
	}
	else if (tv != 0)
	{
		newObs = new TVObserver(*tv);
	}
	else
	{
		throw std::invalid_argument("Invalid observer type");
	}

	observers.push_back(newObs);
}

bool MeteoStation::unregister(size_t index)
{
	if (index < observers.size() && index >= 0)
	{
		observers.erase(observers.begin() + index);
		return true;
	}
	return false;
}

void MeteoStation::notify() const
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->update(getCity(), getTemp());
	}	
	cout << "\n";
}

void MeteoStation::printMeteo() const
{
	for (size_t i = 0; i < observers.size(); i++)
	{
		observers[i]->printMeteo();
	}
	cout << "\n";
}
