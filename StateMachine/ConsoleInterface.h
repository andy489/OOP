#pragma once
#include <vector>
#include <iostream>
#include "StateMachine.h"
class ConsoleInterface
{
private:
	std::vector<StateMachine> elements;
	std::istream& is;
	std::ostream& os;
	int elementsCount;
	String destination;
	void Recognize(int index, String word);
	void List() const;
	void Print(int index) const;
	void Save(int index, String fileName) const;
	void IsEmpty(int index) const;
	void IsDeterministic(int index) const;
	void AddElement(const StateMachine&);
	void Union(int firstIndex, int secondIndex);
	void Open(String path);
	void Concat(int firstIndex, int secondIndex);
	void Un(int firstIndex);
	void Reg(String regex);
	void Minimize(int index);
	void Determinate(int index);
	void Reverse(int index);
	void PrintLanguage(int index) const;
	void IsLanguageFinite(int index) const;
	void Help() const;
	bool ValidateInput(int stringIndexToInt, int parametersNeeded, std::vector<String> str) const;
	bool ValidateInput(int* stringToInt, int stringsToParse, int parametersNeeded, std::vector<String> str) const;

public:
	void Read(std::istream& is = std::cin);
	ConsoleInterface(std::istream& is = std::cin, std::ostream& os = std::cout);
};
