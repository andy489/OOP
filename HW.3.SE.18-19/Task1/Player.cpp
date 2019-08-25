#include "Player.h"

Player::Player() : Killable()
{
	setType(ENTITY_PLAYER);
}

Player::Player(const char * name, Point2D loc, const int damage, const int health) :
	Killable(name, loc, damage, health)
{
	setType(ENTITY_PLAYER);
}

Player::Player(const char * name, Point3D loc, const int damage, const int health) :
	Killable(name, loc, damage, health)
{
	setType(ENTITY_PLAYER);
}

Player::Player(const Player & p) : Killable(p)
{
}

bool Player::isAlive() const
{
	return Killable::isAlive();
}

void Player::attack(Killable *ptr) const
{
	double distance;
	distance = getDistanceTo(*ptr);
	if (distance < 5)
	{
		ptr->setHealth(ptr->getHealth() - getDamage());
	}
	/*if (ptr->getHealth()<0)
	{
		ptr->setHealth(0);
	}*/
	/*But I don't think our game needs this, because the player can attack 
	the corpse of the Mob or another Player (int health) in order to gain 
	potions ot smth like that. It depends on the game.*/
}

void Player::print() const
{
	std::cout << "Player:" << std::endl;
	Killable::print();
}
