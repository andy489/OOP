#include "MultipleChoice.h"

MultipleChoice::MultipleChoice()
{
	Answer a1;
	possibleAnswers.push_back(a1);
}

MultipleChoice::MultipleChoice(const string body) : Question(body)
{
	std::string input;
	for (int i = 0; i < 9; i++) // max 9 different answers;
	{
		cout << "Do you want to add answer? press y" << endl;
		getline(cin, input);
		if (StringCheck::getFirstWord(input) == "y")
		{
			std::cout << "enter body of answer, <press enter>, is it correct(1 or 0), points to get in this order!" << endl;
			std::string body;
			std::getline(std::cin, body);
			bool isItCorrect;
			int points;
			getline(cin, input);
			isItCorrect = StringCheck::findNumber(input);
			points = StringCheck::findNumber(input);
			Answer a1(body, isItCorrect, points);
			possibleAnswers.push_back(a1);
		}
		else
		{
			break;
		}

	}

	if (possibleAnswers.size() == 0)
	{
		Answer a1;
		possibleAnswers.push_back(a1);
	}
}

const std::string MultipleChoice::ask() const
{
	std::cout << "Multiple question: " << std::endl;
	print();
	unsigned int size = possibleAnswers.size();
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << i + 1 << ". ";
		std::cout << possibleAnswers[i].getAnswerBody() << std::endl;
	}
	std::string givenAnswer;
	std::cout << "write only the number in front of the correct answers!" << std::endl;
	std::getline(std::cin, givenAnswer);
	return givenAnswer;
}

const int MultipleChoice::grade(string givenAnswer) const
{
	int receivedPoints = 0;
	while (StringCheck::isThereMoreInfo(givenAnswer))
	{
		int numAns = StringCheck::findNumber(givenAnswer);
		int realindex = numAns - 1;
		if (size_t(realindex) < possibleAnswers.size())
		{
			if (possibleAnswers[realindex].getIsCorrect())
			{
				receivedPoints += possibleAnswers[realindex].getPoitns();
			}
			else
			{
				receivedPoints -= possibleAnswers[realindex].getPoitns();
			}
		}
	}
	if (receivedPoints > 0)
	{
		return receivedPoints;
	}

	return 0;
}
