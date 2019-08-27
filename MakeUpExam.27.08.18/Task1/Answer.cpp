#include "Answer.h"

void Answer::setAnswerBody(const string answer)
{
	this->answerBody = answer;
}

const std::string Answer::getAnswerBody() const
{
	return this->answerBody;
}

void Answer::setIsCorrect(const bool isCorrect)
{
	this->isCorrect = isCorrect;
}

const bool Answer::getIsCorrect() const
{
	return this->isCorrect;
}

void Answer::setPoints(const int points)
{
	this->points = points;
}

const int Answer::getPoitns() const
{
	return this->points;
}

Answer::Answer()
{
	setAnswerBody("def answer");
	setIsCorrect(true);
	setPoints(5);
}

Answer::Answer(const string answer, const bool isCorrect, const int points)
{
	setAnswerBody(answer);
	setIsCorrect(isCorrect);
	setPoints(points);
}
