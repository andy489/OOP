#include "Mob.h"

Mob::Mob() : Killable()
{
	setType(ENTITY_MOB);
}

Mob::Mob(const char * name, Point2D  loc, const int damage, const int health) :
	Killable(name, loc, damage, health)
{

	setType(ENTITY_MOB);
}

Mob::Mob(const char * name, Point3D  loc, const int damage, const int health) :
	Killable(name, loc, damage, health)
{

	setType(ENTITY_MOB);
}

Mob::Mob(const Mob & m) :Killable(m)
{
}

bool Mob::isAlive() const
{
	return Killable::isAlive();
}

void Mob::attack(Killable * ptr) const
{
	if (ptr->getType() == ENTITY_PLAYER)
	{
		double distance;
		distance = getDistanceTo(*ptr);
		if (distance < 5)
		{
			ptr->setHealth(ptr->getHealth() - getDamage());
		}
	}
}

void Mob::print() const
{
	std::cout << "Mob:" << std::endl;
	Killable::print();
}
