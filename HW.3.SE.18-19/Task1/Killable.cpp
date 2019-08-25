#include "Killable.h"

Killable::Killable() :Entity(), damage(0), health(0)
{}

Killable::Killable(const char * name, Point2D loc, const int damage, const int health) :
	Entity(name, loc)
{
	setDamage(damage);
	setHealth(health);
}
Killable::Killable(const char * name, Point3D loc, const int damage, const int health) :
	Entity(name, loc)
{
	setDamage(damage);
	setHealth(health);
}
Killable::Killable(const Killable & k) : Entity(k)
{
	setDamage(k.getDamage());
	setHealth(k.getHealth());
}

void Killable::setDamage(const int damage)
{
	this->damage = damage;
}

const int Killable::getDamage() const
{
	return this->damage;
}

void Killable::setHealth(const int health)
{
	this->health = health;
}

const int Killable::getHealth() const
{
	return this->health;
}

bool Killable::isAlive() const
{
	if (getHealth() > 0) return true;	
	else return false;
}

void Killable::print() const
{
	Entity::print();
	std::cout << "Damage: " << getDamage() << std::endl;
	std::cout << "Health: " << getHealth() << std::endl;
}

