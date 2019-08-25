#include "Warrior.h"
#include "Wizzard.h"
#include "Guardian.h"

int main()
{
	Wizzard wiz1;
	Guardian guard1;
	Warrior war1;

	wiz1.print();

	for (size_t i = 0; i < 14; i++)	wiz1.getAttacked(war1);

	wiz1.print();

	/* the defence of the Wizzard is greater	than the attack damaga of the Guardian */
	for (size_t i = 0; i < 100; i++)wiz1.getAttacked(guard1);
	   
	/* killing the Wizard */
	wiz1.getAttacked(war1);

	// testing:

	cout << "\n~Testing the Code:\n\n";
	Wizzard wiz2;
	Guardian guard2;

	GameCharacter *ptr1 = nullptr;
	ptr1 = &wiz2;
	GameCharacter *ptr2 = nullptr;
	ptr2 = &guard2;

	ptr1->print();
	ptr2->print();
	return 0;
}
