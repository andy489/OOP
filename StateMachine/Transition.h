#pragma once
#include "State.h"
class String;
class Transition
{
private:
	char letter;
	int indexOfNextState;
public:
	Transition(char letter, int index);
	Transition();
	char GetLetter() const;
	int Transist() const;
	bool operator==(const Transition&) const;
	void Print() const;
	String ToString() const;
};

