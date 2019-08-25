#include "IntStack.h"
#include <time.h>

int main()
{
	IntStack stack1;
	srand((unsigned)time(0));
	for (size_t i = 0; i < 30; i++) stack1.push(rand() % 40);

	IntStack stack2(stack1);//we copy stack1 to stack2;
	cout << "Our stack is: " << endl;
	stack2.print();

	//we sort stack2 and copy it to stack 3;
	IntStack stack3(sortStack(stack2));

	cout << "Sorted stack is: " << endl;
	stack3.print();//we print stack3;

	cout << "end" << endl;

	return 0;
}
