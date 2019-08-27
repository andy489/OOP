#include "Test.h"

int main()
{
	Test::getInstance()->addQuestion();
	Test::getInstance()->addQuestion();
	//Test::getInstance()->addQuestion();
	//Test::getInstance()->addQuestion();
	//...

	Test::getInstance()->doTest();
	Test::getInstance()->gradeTest();

	return 0;
}
