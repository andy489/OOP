#include "Warrior.h"

Warrior::Warrior() :GameCharacter("Warrior", 20, 5, 4, 1)
{}
void Warrior::print() const
{
	cout << "Hero: " << getHero() << endl
		<< "Health: " << getHP() << endl
		<< "Mana: " << getMP() << endl
		<< "Attack power: " << getAP() << endl
		<< "Defence: " << getDP() << endl
		<< "------------------------" << endl;
}
