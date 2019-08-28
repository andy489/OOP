#pragma once
#include "Obs.h"

class RadioObserver : public Observer
{
	string radioName;

public:
	RadioObserver();
	RadioObserver(const string city, const float temp, const string radioName);

	const string getRadioName()const;
	void setRadioName(const string newsName);

	virtual void update(const string name, const float temp) override;
	virtual void printMeteo()const override;

	virtual Observer* clone() const override;
};
