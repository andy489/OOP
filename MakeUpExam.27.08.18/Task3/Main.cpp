#include "MeteoStation.h"

int main()
{
	MeteoStation station1("Sofia", 22);

	NewspaperObserver obs1("Plovediv", 15, "Vstnik Trud");
	RadioObserver obs2("Pleven", 19, "Radio Vitosha");
	TVObserver obs3("Varna", 24, "Movie Star Tv");

	station1.registerObs(&obs1);
	station1.registerObs(&obs2);
	station1.registerObs(&obs3);

	station1.printMeteo();
	
	station1.setTemp(28);
	station1.unregister(0);
	station1.setTemp(26);
	
	cout << "Check copy constructor:\n";
	MeteoStation station2(station1);
	station2.printMeteo();

	cout << "Check operator=:\n";
	MeteoStation station3;
	station3 = station2;
	station3.printMeteo();
	
	return 0;
}
