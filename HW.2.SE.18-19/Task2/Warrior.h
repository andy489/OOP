#pragma once
#include "GameCharacter.h"

class Warrior : public GameCharacter
{
public:
	Warrior();
	void print() const override;
};
