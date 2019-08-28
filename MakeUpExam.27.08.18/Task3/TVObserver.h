#pragma once
#include "Obs.h"

class TVObserver : public Observer
{
	string tvName;

public:
	TVObserver();
	TVObserver(const string city, const float temp, const string tvName);

	const string getTvName()const;
	void setTvName(const string tvName);

	virtual void update(const string name, const float temp) override;
	virtual void printMeteo()const override;

	virtual Observer* clone() const override;
};
