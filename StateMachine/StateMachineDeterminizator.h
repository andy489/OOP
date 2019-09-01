#pragma once
#include "StateMachine.h"
class StateMachine;
class StateMachineDeterminizator
{
private:
	void DeterminationHelperCreateUnionStates(std::vector<StateUnion*>& states, StateMachine* object);
	void DeterminationHelperAddStates(const std::vector<StateUnion*> states, const StateMachine& source, StateMachine* object);
public:
	void Determinate(StateMachine* object);
};
