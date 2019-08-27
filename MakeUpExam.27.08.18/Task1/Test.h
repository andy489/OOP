#pragma once
#include "YesNoQuestion.h"
#include "MultipleChoice.h"
#include "OpenQuestion.h"

class Test
{
	vector<Question*> questions;
	vector<string> answers;
	static Test* Instance;

	Test();
	Test(const Test& t);
	Test& operator=(const Test& t);
	~Test();
public:
	static Test* getInstance();
	static void releaseInstance();

	void addQuestion();
	void doTest();
	void gradeTest() const;
};
