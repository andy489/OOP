#pragma once
#include "Question.h"

class YesNoQuestion : public Question
{
	string answer;
	int points;
public:
	void setAnswer(const string answer);
	const string getAnswer() const;
	void setPoints(const int points);
	const int getPoints() const;

	YesNoQuestion();
	YesNoQuestion(const string body, const int points, const string answer);

	virtual const string ask() const override;
	virtual const int grade(string givenAnswer) const override;
};

