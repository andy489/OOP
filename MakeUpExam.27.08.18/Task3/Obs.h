#pragma once
#include <iostream>
#include <string>
#include "Enums.h"
using namespace std;

class Observer
{
protected:
	string city;
	float temp;
	OBS obsType;

	const string obsTypeToStr(OBS obs) const;

public:
	Observer();
	Observer(const string city, const float temp);

	const string getCity()const;
	void setCity(const string city);

	const float getTemp()const;
	void setTemp(const float temp);

	const OBS getType()const;

	virtual void update(const string name, const float temp) = 0;
	virtual void printMeteo()const;

	virtual Observer* clone() const = 0;
};
