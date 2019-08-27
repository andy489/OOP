#include "OpenQuestion.h"

void OpenQuestion::setMaxPoints(const int points)
{
	this->MaxPoints = points;
}

const int OpenQuestion::getMaxPoints() const
{
	return this->MaxPoints;
}

OpenQuestion::OpenQuestion()
{
	setMaxPoints(10);
}

OpenQuestion::OpenQuestion(string body, const int points) : Question(body)
{
	setMaxPoints(points);
}

const string OpenQuestion::ask() const
{
	cout << "Open question: " << endl;
	print();
	string givenAnswer;
	getline(cin, givenAnswer);
	return givenAnswer;
}

const int OpenQuestion::grade(string givenAnswer) const
{
	print();
	cout << "Given answer: " << endl;
	cout << "write in % the grade of the question!" << endl;

	cout << "grade: ";
	string input;
	getline(cin, input);
	int grade = StringCheck::findNumber(input);
	return (grade * 0.01 * getMaxPoints());
}
