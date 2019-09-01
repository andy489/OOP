#include "State.h"
#include <iostream>
State::State()
{
	this->isFinal = false;
}

State::State(bool isEnd)
{
	this->isFinal = isEnd;
}

State::State(const State* state)
{
	this->isFinal = state->isFinal;
	this->transitions = state->transitions;
}

void State::AddFunctionality(const State& other, bool copyIsFinal)
{
	std::vector<Transition> temp = other.GetAllTransitions();
	for (unsigned i = 0; i < temp.size(); i++)
	{
		this->AddTransition(temp[i]);
	}
	if (copyIsFinal)
	{
		this->isFinal = other.IsFinal();
	}
}

void State::AddMappedFunctionality(const State& other, std::unordered_map<int, int>& oldStatesToNew, bool copyIsFinal)
{
	auto temp = other.GetAllTransitions();
	for (unsigned j = 0; j < temp.size(); j++)
	{
		Transition t = temp[j];
		Transition newT(t.GetLetter(), oldStatesToNew[t.Transist()]);
		this->AddTransition(newT);
	}
	if (copyIsFinal)
	{
		this->isFinal = other.IsFinal();
	}
}

void State::AddTransition(const Transition tr)
{
	if (this->HasTransition(tr))
	{
		return;
	}
	this->transitions[tr.GetLetter()].push_back(tr);
}

bool State::IsFinal() const
{
	return this->isFinal;
}

std::vector<Transition> State::Transist(String word) const
{
	if (this->transitions.count(word[0]))
	{
		return this->transitions.at(word[0]);
	}
	std::vector<Transition> a;
	return a;
}

std::vector<Transition> State::GetAllTransitions() const
{
	std::vector<Transition> temp;
	for (const auto &myPair : this->transitions) {
		for (unsigned i = 0; i < myPair.second.size(); i++)
		{
			temp.push_back(myPair.second[i]);
		}
	}
	return temp;
}

std::vector<std::vector<Transition>> State::GetAllTransitionsGrouped() const
{
	std::vector<std::vector<Transition>> result;
	std::vector<Transition> temp;

	for (const auto &myPair : this->transitions)
	{
		for (unsigned i = 0; i < myPair.second.size(); i++)
		{
			temp.push_back(myPair.second[i]);
		}
		result.push_back(temp);
		temp.clear();
	}
	return result;
}

void State::Print() const
{
	std::cout << "Finality: " << this->isFinal << std::endl;
	std::vector<Transition> t = this->GetAllTransitions();
	for (unsigned i = 0; i < t.size(); i++)
	{
		t[i].Print();
	}
}

bool State::HasTransition(const Transition& tr)
{
	std::vector<Transition> t = this->transitions[tr.GetLetter()];
	for (unsigned i = 0; i < t.size(); i++)
	{
		if (t[i] == tr)
		{
			return true;
		}
	}
	return false;
}
