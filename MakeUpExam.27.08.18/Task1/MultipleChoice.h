#pragma once
#include "Question.h"
#include "Answer.h"
#include <vector>

class MultipleChoice : public Question, public Answer
{
private:
	vector<Answer> possibleAnswers;

public:
	MultipleChoice();
	MultipleChoice(const std::string body);

	virtual const std::string ask() const override;
	virtual const int grade(std::string givenAnswer) const override;
};
