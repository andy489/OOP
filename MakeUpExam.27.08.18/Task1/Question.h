#pragma once
#include "StringCheck.h"

class Question
{
private:
	std::string body;
public:
	void setBody(const string body);
	const string getBody() const;

	Question();
	Question(const string body);

	virtual const string ask() const = 0;
	virtual const int grade(string givenAnswer) const = 0;
	void print() const;
};
