#include "GameCharacter.h"

void GameCharacter::copy(const GameCharacter & g)
{
	setHero(g.getHero());
	setHP(g.getHP());
	setMP(g.getMP());
	setAP(g.getAP());
	setDP(g.getDP());
}

GameCharacter::GameCharacter() {}

GameCharacter::GameCharacter(const char* hero,
	size_t HP,
	size_t MP,
	int AP,
	int DP)
{
	setHero(hero);
	setHP(HP);
	setMP(MP);
	setAP(AP);
	setDP(DP);
}

const char * GameCharacter::getHero() const
{
	return this->hero;
}

const size_t GameCharacter::getHP() const
{
	return this->HP;
}

const size_t GameCharacter::getMP() const
{
	return this->MP;
}

const int GameCharacter::getAP() const
{
	return this->AP;
}

const int GameCharacter::getDP() const
{
	return this->DP;
}

void GameCharacter::setHero(const char* hero)
{
	delete[] this->hero;
	this->hero = new char[strlen(hero) + 1];
	strcpy_s(this->hero, strlen(hero) + 1, hero);
}

void GameCharacter::setHP(size_t HP)
{
	this->HP = HP;
}

void GameCharacter::setMP(size_t MP)
{
	this->MP = MP;
}

void GameCharacter::setAP(int AP)
{
	this->AP = AP;
}

void GameCharacter::setDP(int DP)
{
	this->DP = DP;
}

GameCharacter & GameCharacter::operator=(const GameCharacter & g)
{
	copy(g);
	return *this;
}

GameCharacter::GameCharacter(const GameCharacter & g)
{
	*this = g;
}

GameCharacter::~GameCharacter()
{
	delete[] this->hero;
}

void GameCharacter::getAttacked(GameCharacter& g)
{
	int damage = g.getAP() - this->getDP();
	if (damage > 0)
	{
		int health = this->HP - damage;
		if (health > 0)
		{
			setHP(health);
			cout << this->getHero() << " was attacked by " << g.getHero()<<'\n';
		}
		else
		{
			cout << "Your " << this->getHero() << " hero was slain by " << g.getHero() << "!\n";
			setHP(0);
			setMP(0);
			setAP(0);
			setDP(0);
		}
	}
}
