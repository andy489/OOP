#pragma once
#include <iostream>
#include <string>
using namespace std;

class GameCharacter
{
private:
	char* hero = nullptr;
	size_t HP;
	size_t MP;
	int AP;
	int DP;

	void copy(const GameCharacter& g);

	void setHero(const char* hero);
	void setHP(size_t HP);
	void setMP(size_t MP);
	void setAP(int AP);
	void setDP(int DP);
protected:
	GameCharacter(); // protected default constructor (unabling creating instances)
	GameCharacter(const char* hero,
		size_t HP, size_t MP,
		int AP, int DP);

	const char* getHero()const;
	const size_t getHP()const;
	const size_t getMP()const;
	const int getAP()const;
	const int getDP()const;
public:
	GameCharacter& operator=(const GameCharacter& g);
	GameCharacter(const GameCharacter& g);
	~GameCharacter();

	/*the function "getAttacked" makes sense only if
	it accepts an argument - object of a similar class*/

	void getAttacked(GameCharacter& g);
	virtual void print() const = 0; // not necessary = 0
};

