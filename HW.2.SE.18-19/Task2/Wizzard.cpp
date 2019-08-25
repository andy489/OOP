#include "Wizzard.h"

Wizzard::Wizzard() :GameCharacter("Wizzard", 30, 30, 2, 2)
{}

void Wizzard::print() const
{
	cout << "Hero: " << getHero() << endl
		<< "Health: " << getHP() << endl
		<< "Mana: " << getMP() << endl
		<< "Attack power: " << getAP() << endl
		<< "Defence: " << getDP() << endl
		<< "------------------------" << endl;
}
