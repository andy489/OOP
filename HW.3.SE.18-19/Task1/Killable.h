#pragma once
#include "Entity.h"
/* this class is pure virtual and embraces Player and Mob, it's a good OOP practice */

class Killable :public Entity
{
	int damage;
	int health;
public:
	Killable();
	Killable(const char* name, Point2D loc, const int damage, const int health);
	Killable(const char* name, Point3D loc, const int damage, const int health);

	Killable(const Killable& k);

	void setDamage(const int damage);
	const int getDamage() const;

	void setHealth(const int health);
	const int getHealth()const;

	virtual void attack(Killable *ptr) const = 0;

	virtual bool isAlive() const;

	virtual void print() const override;
};
