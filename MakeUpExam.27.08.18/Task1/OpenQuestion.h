#pragma once
#include "question.h"

class OpenQuestion : public Question
{
	int MaxPoints;
public:
	void setMaxPoints(const int points);
	const int getMaxPoints() const;

	OpenQuestion();
	OpenQuestion(string body, const int points);

	virtual const string ask() const override;
	virtual const int grade(string givenAnswer) const override;
};
