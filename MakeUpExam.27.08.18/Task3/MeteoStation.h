#pragma once
#include "Obs.h"
#include "NewspaperObserver.h"
#include "RadioObserver.h"
#include "TVObserver.h"
#include <vector>

class MeteoStation
{
	string cityName;
	float temp;

	vector <Observer*> observers;
		
public:
	MeteoStation();
	MeteoStation(const string name, const float temp);
	MeteoStation(const MeteoStation& m);
	MeteoStation& operator=(const MeteoStation& m);
	~MeteoStation();

	void setCity(const string name);
	void setTemp(const float temp);

	const string getCity()const;
	const float getTemp()const;

	void registerObs(Observer* obs);
	bool unregister(size_t index);

	void notify() const;
	void printMeteo()const;
};
