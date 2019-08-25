#pragma once
#include "GameCharacter.h"

class Guardian :public GameCharacter
{
public:
	Guardian();
	void print() const override;
};
