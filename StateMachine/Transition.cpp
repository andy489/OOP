#include "Transition.h"
#include <iostream>
Transition::Transition(char letter, int index)
{
	this->letter = letter;
	this->indexOfNextState = index;
}

char Transition::GetLetter()const
{
	return this->letter;
}

int Transition::Transist() const
{
	return this->indexOfNextState;
}

bool Transition::operator==(const Transition& other) const
{
	return this->letter == other.letter && this->indexOfNextState == other.indexOfNextState;
}

void Transition::Print() const
{
	std::cout << this->letter << " " << this->Transist() << std::endl;
}

String Transition::ToString() const
{
	String res;
	res += this->letter;
	res += " ";
	char temp[15];
	_itoa_s(this->indexOfNextState, temp, 10);
	res += temp;
	return res;
}
