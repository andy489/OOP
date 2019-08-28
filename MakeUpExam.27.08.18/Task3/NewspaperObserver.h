#pragma once
#include "Obs.h"

class NewspaperObserver : public Observer
{
	string newsName;

public:
	NewspaperObserver();
	NewspaperObserver(const string city, const float temp, const string newsName);

	const string getNewsName()const;
	void setNewsName(const string newsName);

	virtual void update(const string name, const float temp) override;
	virtual void printMeteo()const override;
	
	virtual Observer* clone() const override;
};
