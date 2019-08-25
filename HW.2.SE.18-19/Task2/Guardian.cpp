#include "Guardian.h"

Guardian::Guardian() :GameCharacter("Guardian", 40, 25, 1, 3)
{}

void Guardian::print() const
{
	cout << "Hero: " << getHero() << endl
		<< "Health: " << getHP() << endl
		<< "Mana: " << getMP() << endl
		<< "Attack power: " << getAP() << endl
		<< "Defence: " << getDP() << endl
		<< "------------------------" << endl;
}
