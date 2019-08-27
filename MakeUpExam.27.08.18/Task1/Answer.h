#pragma once
#include <iostream>
#include <string>
using namespace std;

class Answer
{
	string answerBody;
	bool isCorrect;
	int points;
public:
	void setAnswerBody(const string answer);
	const string getAnswerBody() const;
	void setIsCorrect(const bool isCorrect);
	const bool getIsCorrect() const;
	void setPoints(const int points);
	const int getPoitns() const;

	Answer();
	Answer(const string answer, const bool isCorrect, const int points);
};
